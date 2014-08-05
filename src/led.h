/*
 * led.h
 *
 *  Created on: May 23, 2014
 *      Author: kbroerman
 */
#include "commonTypes.h"

#ifndef LED_H_
#define LED_H_

#define RED		("red:led")
#define GREEN	("green:led")
#define BLUE	("blue:led")

uInt16_t led_setValue(char *led, uInt16_t value);

#endif /* LED_H_ */
