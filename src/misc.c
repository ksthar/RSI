/*
 * misc.c
 *
 *  Created on: May 22, 2014
 *      Author: kbroerman
 */

#include <time.h>
#include "commonTypes.h"
#include <fcntl.h>


void delayuS(uInt32_t uSec)
{
	struct timespec ts;
	ts.tv_sec = 0;
	ts.tv_nsec = uSec * 1000;
	nanosleep(&ts, NULL);
}

uInt16_t uptimeInSec( char *timeString)
{
	uInt16_t num = 0, fd = open("/proc/uptime", O_RDONLY );
	if (fd > 0) {
		num = read( fd, timeString, 30 );
		close(fd);
	}
	return num;
}
