/** 
 * @file gpio.c
 * @brief Initialize GPIO pins
 * @author Keith Broerman
 * @version 0.1
 * @date 2014-05-22
 */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "gpio.h"

/* ****************************************************************** */
/** 
 * @brief Define GPIO pins to export
 * 
 * @param gpio	Pin number to export
 * 
 * @return file descriptor
 */
/* ****************************************************************** */
int gpio_init(int gpio)
{
	//export gpio so userspace can tweek it:
	int fd = open("/sys/class/gpio/export", O_WRONLY);
	if (fd >= 0) {
		char buf[10];
		sprintf(buf, "%d", gpio);
		//printf("gpio_init : buf = %s\n", buf);
		write(fd, buf, strlen(buf));
		close(fd);
	}
	return fd;
}

/* ****************************************************************** */
/** 
 * @brief Define GPIO pins to unexport
 * 
 * @param gpio Pin number to unexport
 * 
 * @return file descriptor 
 */
/* ****************************************************************** */
int gpio_deinit(int gpio)
{
	//unexport gpio:
	int fd = open("/sys/class/gpio/unexport", O_WRONLY);
	if (fd >= 0) {
		char buf[10];
		sprintf(buf, "%d", gpio);
		//printf("gpio_init : buf = %s\n", buf);
		write(fd, buf, strlen(buf));
		close(fd);
	}
	return fd;
}

/* ****************************************************************** */
/** 
 * @brief Set value (high/low) of pin
 * 
 * @param gpio 	Pin number
 * @param value Value to set true=high, false=low
 * 
 * @return 
 */
/* ****************************************************************** */
int gpio_setValue(int gpio, int value)
{
	char buf[60];
	int len = sprintf(buf, "/sys/class/gpio/gpio%d", gpio);
	strcat( &buf[len], "/direction" );
	int fd = open(buf, O_WRONLY);
	if (fd >= 0) {
		if (value)
			write(fd, "high", 4);
		else
			write(fd, "low",  3);
		close(fd);
	}
	return 0;
}

