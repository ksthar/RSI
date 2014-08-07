/** 
 * @file serial.h
 * @brief Header file for serial.c
 * @author Keith Broerman
 * @version 0.1
 * @date 2014-05-21
 */
#ifndef SERIAL_H_
#define SERIAL_H_

#define	SERIAL_DEVICE	"/dev/ttyS0"		/**< UART for RS-485 communications */

uInt16_t rs485_open(void);
uInt16_t rs485_close(uInt16_t fd);

uInt16_t rs485_rcvEnable(void);
uInt16_t rs485_rcvDisable(void);
uInt16_t rs485_xmitEnable(void);
uInt16_t rs485_xmitDisable(void);

uInt16_t rs485_read( uInt16_t fd, uInt8_t *buffer, uInt16_t requested );
uInt16_t rs485_write( uInt16_t fd, uInt8_t *buffer, uInt16_t requested );

//void rs485TimedRead( uInt16_t fd, uInt16_t enabled );
void rs485UartVminVtime( uInt16_t fd, uInt16_t vmin, uInt16_t vtime );

#endif /* SERIAL_H_ */
