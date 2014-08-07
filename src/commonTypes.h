/** 
 * @file commonTypes.h
 * @brief Type definitions for the Allegion Gateway project
 * 				This file contains common naming conventions used for data types and
 * 				macros.These should be used by octopus source code.
 * @author Harlan Shoop
 * @version 0.1
 * @date 2014-08-07
 */

#ifndef COMMONTYPES_H_
#define COMMONTYPES_H_

/*------- HEADER INCLUDE FILES -----------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*------- MACRO DEFINITIONS --------------------------------------------------*/

// General numeric constants
#define ZERO    (0)							/**< ZERO     */
#define ONE     (1)							/**< ONE      */

// General return status values
#define STATUS_SUCCESS    (0)				/**< STATUS_SUCCESS */
#define STATUS_FAILURE    (-1)				/**< STATUS_FAILURE */

/*------- TYPEDEFS -----------------------------------------------------------*/
typedef char sInt8_t;						/**< 8-bit signed int	*/
typedef unsigned char uInt8_t;				/**< 8-bit unsigned int	*/
typedef int16_t sInt16_t;					/**< 16-bit signed int	*/
typedef uint16_t uInt16_t;					/**< 16-bit unsigned int*/
typedef int32_t sInt32_t;					/**< 32-bit signed int	*/
typedef uint32_t uInt32_t;					/**< 32-bit unsigned int*/
typedef int64_t sInt64_t;					/**< 64-bit signed int	*/
typedef uint64_t uInt64_t;					/**< 64-bit unsigned int*/

/*------- FUNCTION PROTOTYPES ------------------------------------------------*/
// Common functions used by octopus should be declared here

#endif /* COMMONTYPES_H_ */

