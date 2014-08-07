/** 
 * @file led.h
 * @brief Header for led.c
 * @author Keith Broerman
 * @version 0.1
 * @date 2014-05-23
 */
#include "commonTypes.h"

#ifndef LED_H_
#define LED_H_

#define RED		("red:led")			/**< Red LED	*/
#define GREEN	("green:led")		/**< Green LED	*/
#define BLUE	("blue:led")		/**< Blue LED	*/

uInt16_t led_setValue(char *led, uInt16_t value);

#endif /* LED_H_ */
