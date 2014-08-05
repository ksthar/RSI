/**
 * @name rsiSocket.c
 * @date July 29, 2014
 * @author Harlan
 *
 *	Creates and provides control to a domain socket (stream) used to
 *	communicate with the BLE process (client).
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

#include "rsiSocket.h"

#define		DEBUG

// ======================= SET UP SOCKET ==========================
/** 
 * @brief Opens, binds, and listens the socket.
 * 
 * @param address A pointer to the address struct.
 * 
 * @return The socked file descriptor is returned if the socket is successfully
 * opened.  Otherwise, a 1 is returned.
 */
uInt16_t openSocket( struct sockaddr_un *address )
{
	// socket vars
	uInt16_t socket_fd, connection_fd;

	// ignore the SIGCHLD signal to prevent zombie processes
	signal( SIGCHLD, SIG_IGN );

	socket_fd = socket(PF_UNIX, SOCK_STREAM, 0);
	if(socket_fd < 0)
	{
	  printf( "Error: socket() failed\n" );
	  return 1;
	}

	unlink( SOCKET_ADDR );

	/* start with a clean address structure */
	memset(address, 0, sizeof(struct sockaddr_un));

	(*address).sun_family = AF_UNIX;
	snprintf((*address).sun_path, UNIX_PATH_MAX, SOCKET_ADDR );

	if( bind(socket_fd, (struct sockaddr *) address, sizeof(struct sockaddr_un)) != 0 )
	{
		printf( "Error: bind() failed\n" );
		return 1;
	}

	if( listen(socket_fd, 5) != 0 )
	{
		printf( "Error: listen() failed\n" );
		return 1;
	}

	printf( "Socket opened.\n" );
	return socket_fd;
}


// =================== CREATE CONNECTION ========================
/** 
 * @brief Waits for a connection from client.
 * 
 * @param socket_fd Socket descriptor
 * @param address Pointer to the address struct
 * 
 * @return Connection file descriptor
 */
uInt16_t createSocketConnection( uInt16_t socket_fd, struct sockaddr_un *address )
{
	uInt16_t connection_fd;
	socklen_t address_length;
	address_length = 0;

	// NOTE: accept() is blocking in this usage
	// accept() returns a nonnegative integer that is a descriptor for the
	// accepted socket when a connection is made with a client.
	printf( "Waiting for connection from client...\n" );
	connection_fd = accept( socket_fd, (struct sockaddr *) address, &address_length );

	if( connection_fd != -1)
	{
		printf( "Connected!\n" );
		return connection_fd;

	} else {
		printf( "Error accepting connection.\n" );
		perror( "accept" );
		return 1;
	} // if connection_fd

}


// =================== READ AND WRITE ========================
/** 
 * @brief Reads message from socket and loads into buffer.
 * 
 * @param connection_fd Connection file descriptor
 * @param buf	Pointer to the read buffer
 * 
 * @return Number of bytes read
 */
uInt16_t readFromSocket( uInt16_t connection_fd, char *buf )
{
	uInt16_t nbytes = 0;
	// TO-DO: force buf to 256 here
	nbytes = read(connection_fd, buf, 256);
	buf[nbytes] = 0;
	printf("\033[032m<-  MESSAGE FROM CLIENT:\033[034m %s\033[037m\n", buf);
	return nbytes;
}

/** 
 * @brief Write string to the socket
 * 
 * @param connection_fd Connection file descriptor
 * @param msg Pointer to message to write (string)
 * 
 * @return Number of bytes written
 */
uInt16_t writeToSocket( uInt16_t connection_fd, char *msg )
{
	uInt16_t nbytes = 0;
	char buffer[256];
	nbytes = snprintf(buffer, 256, "%s", msg);
	printf( "\033[035m->  SENDING TO CLIENT:\033[037m   %s\n", msg);
	return write(connection_fd, buffer, nbytes);
}


// =================== CLOSE CONN & SOCKET ========================
/** 
 * @brief Close socket connection
 * 
 * @param connection_fd Connection file descriptor
 */
//
void closeConnection( uInt16_t connection_fd )
{
	close( connection_fd );
	printf( "Closing connection...\n" );
}

/** 
 * @brief Close socket
 * 
 * @param socket_fd Socket file descriptor
 */
void closeSocket( uInt16_t socket_fd )
{
	close( socket_fd );
	unlink( SOCKET_ADDR );
	printf( "Closing socket...\n" );
}

// eof
