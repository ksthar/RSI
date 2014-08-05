/**
 * @name rsiSocket.h
 * @date July 29, 2014
 * @author Harlan
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include "commonTypes.h"

#define	UNIX_PATH_MAX	108
#define	READ	0
#define	WRITE 1
#define SOCKET_ADDR 	"./demo_socket"
#define SOCKET_BUFFER_SIZE	256

uInt16_t openSocket( struct sockaddr_un *address );
uInt16_t createSocketConnection( uInt16_t socket_fd, struct sockaddr_un *address );
uInt16_t readFromSocket( uInt16_t connection_fd, char *buf );
uInt16_t writeToSocket( uInt16_t connection_fd, char *msg );
void closeConnection( uInt16_t connection_fd );
void closeSocket( uInt16_t socket_fd );
