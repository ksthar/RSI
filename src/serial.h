/*
 * serial.h
 *
 *  Created on: May 21, 2014
 *      Author: kbroerman
 */

#ifndef SERIAL_H_
#define SERIAL_H_

#define	SERIAL_DEVICE	"/dev/ttyS0"

uInt16_t rs485_open(void);
uInt16_t rs485_close(uInt16_t fd);

uInt16_t rs485_rcvEnable(void);
uInt16_t rs485_rcvDisable(void);
uInt16_t rs485_xmitEnable(void);
uInt16_t rs485_xmitDisable(void);

uInt16_t rs485_read( uInt16_t fd, char *buffer, uInt16_t requested );
uInt16_t rs485_write( uInt16_t fd, char *buffer, uInt16_t requested );

void rs485TimedRead( uInt16_t fd, uInt16_t enabled );
void rs485UartVminVtime( uInt16_t fd, uInt16_t vmin, uInt16_t vtime );

#endif /* SERIAL_H_ */
