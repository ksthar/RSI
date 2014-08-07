/** 
 * @file gpio.h
 * @brief Header file for gpio.c
 * @author Keith Broerman
 * @version 0.1
 * @date 2014-05-22
 */

#ifndef GPIO_H_
#define GPIO_H_

#define GPIO_41			(41)			/**< GPIO pin 41		*/
#define GPIO_42			(42)			/**< GPIO pin 42		*/
#define RS485_RE		(GPIO_41)		/**< RS485 Rx Enable	*/
#define RS485_DE		(GPIO_42)		/**< RS485 DE			*/

#define GPIO_44			(44)			/**< GPIO pin 44		*/
#define GPIO_45			(45)			/**< GPIO pin 45		*/
#define RS485_LED_GREEN	(GPIO_44)		/**< RS485 TX LED		*/
#define RS485_LED_RED	(GPIO_45)		/**< RS485 RX LED		*/

int gpio_init(int gpio);
int gpio_deinit(int gpio);
int gpio_setValue(int gpio, int value);


#endif /* GPIO_H_ */
