/** 
 * @file mod_socket.h
 * @brief Domain socket (streaming) library
 * @author Harlan Shoop
 * @version 0.1
 * @date 2014-08-07
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include "commonTypes.h"

#define	UNIX_PATH_MAX	108					/**< Max path length 		*/
#define SOCKET_ADDR 	"./rsi_socket"		/**< Socket name			*/
#define SOCKET_BUFFER_SIZE	256				/**< Size of socket buffer	*/

uInt16_t sock_open( struct sockaddr_un *address );
uInt16_t sock_createConnection( uInt16_t socket_fd, struct sockaddr_un *address );
uInt16_t sock_read( uInt16_t connection_fd, char *buf );
uInt16_t sock_write( uInt16_t connection_fd, char *msg );
void sock_closeConnection( uInt16_t connection_fd );
void sock_close( uInt16_t socket_fd );
