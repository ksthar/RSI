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

#define	UNIX_PATH_MAX	108
#define	READ	0
#define	WRITE 1
#define SOCKET_ADDR 	"./demo_socket"
#define SOCKET_BUFFER_SIZE	256

int openSocket( struct sockaddr_un *address );
int createSocketConnection( int socket_fd, struct sockaddr_un *address );
int readFromSocket( int connection_fd, char *buf );
int writeToSocket( int connection_fd, char *msg );
void closeConnection( int connection_fd );
void closeSocket( int socket_fd );
