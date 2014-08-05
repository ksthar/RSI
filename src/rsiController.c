/** 
 * @file rsiController.c
 * @brief This is an adaptation of the code written by Keith.
 * @author Harlan Shoop
 * @version 0.1
 * @date 2014-08-04
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the PG_ORGANIZATION nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY	THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS-IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE 
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
 * POSSIBILITY OF SUCH DAMAGE.
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <termios.h>

#include "commonTypes.h"
#include "rsi.h"
#include "led.h"
#include "rsiSocket.h"

#define MAKE_SOCKET

/** 
 * @brief Reads SOCKET_BUFFER_SIZE chars from socket
 * 
 * @param conn The connection file descriptor
 * 
 * @return bytes read
 */
uInt16_t readSocketBuffer( uInt16_t conn ){
	char buffer[SOCKET_BUFFER_SIZE];
	return readFromSocket( conn, buffer );
}

/** 
 * @brief Writes message to socket
 * 
 * @param conn The connection fd
 * 
 * @return  Bytes written
 */
uInt16_t writeSocketBuffer( uInt16_t conn ){
	uInt16_t nbytes;
	char buffer[SOCKET_BUFFER_SIZE];
	nbytes = snprintf( buffer, SOCKET_BUFFER_SIZE, "Response from RSI process" );
	return writeToSocket( conn, buffer );
}

uInt16_t main(void) {	//this code emulates the RSI process...

	puts("RSI-BLE POC for Digi i.MX28...");
	//led_setValue(GREEN, 0);
	//led_setValue(RED, 0);
	//led_setValue(BLUE, 80);

	uInt16_t rsi_fd = rsiOpen();
	uInt16_t espLength, count;
	sInt32_t reqLength, status;
	uInt16_t running = 1;
	uInt16_t sock_fd, conn_fd;

	// create pointer to address so we can "pass by reference"
	struct sockaddr_un client_addr;
	struct sockaddr_un *ptr_client_addr = &client_addr;

	char rsiRequestFrame[RSI_MAX_FRAME_SIZE];
	char rsiResponseFrame[RSI_MAX_FRAME_SIZE];

#ifdef MAKE_SOCKET
	// setup socket for communicating with on-board BLE process
	sock_fd = openSocket( ptr_client_addr );
#endif

	while (running) {	//emulate RSI process

		//---- listen for RS485 command from ACP (master)
		memset(rsiRequestFrame,  0, sizeof(rsiRequestFrame));
		memset(rsiResponseFrame, 0, sizeof(rsiResponseFrame));
		reqLength = rsiRead(rsi_fd, rsiRequestFrame);

		//process the command, generate immediate response
		status = rsiHandler(rsiRequestFrame, rsiResponseFrame, &reqLength);

		//send immediate response back to ACP
		if (status == STATUS_SUCCESS) {
			//printf("need to send %d bytes back...\n", reqLength);
			rsiWrite(rsi_fd, rsiResponseFrame, reqLength);

#ifdef MAKE_SOCKET
			// HN: make blocking call to socket connection
			conn_fd = createSocketConnection( sock_fd, ptr_client_addr );
			// The following lines will read a message from the socket and then write
			// a response.  At this point, there is no intelligence in the read
			// routine.  In the future, the read should contain decision branching
			// eventually directing rsiWrite.
			readSocketBuffer( conn_fd );
			writeSocketBuffer( conn_fd );
#endif

		} // if status == STATUS_SUCCESS

		//are we done? set the flag...
		running = 0;

	}	//while running
	printf("done...\n");

	//----- close the UART, release the GPIOs, etc -----
	rsiClose(rsi_fd);
	return 0;
}

