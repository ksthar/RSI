/** 
 * @file misc.c
 * @brief Helper functions for gateway
 * @author Keith Broerman
 * @version 0.1
 * @date 2014-05-22
 */
#include <time.h>
#include "commonTypes.h"
#include <fcntl.h>


/* ****************************************************************** */
/** 
 * @brief 			Microsecond delay timer
 * 
 * @param uSec		Delay in microseconds
 */
/* ****************************************************************** */
void delayuS(uInt32_t uSec)
{
	struct timespec ts;
	ts.tv_sec = 0;
	ts.tv_nsec = uSec * 1000;
	nanosleep(&ts, NULL);
}

/* ****************************************************************** */
/** 
 * @brief 				Return uptime
 * 
 * @param timeString	Buffer to load uptime into
 * 
 * @return 				Number of characters read (success)
 */
/* ****************************************************************** */
uInt16_t uptimeInSec( char *timeString)
{
	uInt16_t num = 0, fd = open("/proc/uptime", O_RDONLY );
	if (fd > 0) {
		num = read( fd, timeString, 30 );
		close(fd);
	}
	return num;
}
