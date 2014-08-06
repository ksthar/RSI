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

uInt16_t sock_open( struct sockaddr_un *address );
uInt16_t sock_createConnection( uInt16_t socket_fd, struct sockaddr_un *address );
uInt16_t sock_read( uInt16_t connection_fd, char *buf );
uInt16_t sock_write( uInt16_t connection_fd, char *msg );
void sock_closeConnection( uInt16_t connection_fd );
void sock_close( uInt16_t socket_fd );
