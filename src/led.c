/** 
 * @file led.c
 * @brief Set tricolor LED color
 * @author Keith Broerman
 * @version 0.1
 * @date 2014-05-23
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#include "led.h"

char *ledName[] = { RED, GREEN, BLUE };		/**< LED names	*/

/* ****************************************************************** */
/** 
 * @brief 			Set value of LED
 * 
 * @param led		String specifying LED color
 * @param value		0-255 value for LED brightness
 * 
 * @return 
 */
/* ****************************************************************** */
uInt16_t led_setValue(char *led, uInt16_t value)
{
	char buf[60];
	uInt16_t rtn;
	uInt16_t len = sprintf(buf, "/sys/class/leds/%s", led);
	strcat( &buf[len], "/brightness" );
	uInt16_t fd = open(buf, O_WRONLY);
	if (fd >= 0) {
		if (value < 0)   value = 0;
		if (value > 255) value = 255;

		len = sprintf(buf, "%d", value);
		rtn = write(fd, buf, len);
		close(fd);
	}
	return 0;
}
