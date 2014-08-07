/** 
 * @file mod_rsi.h
 * @brief Header file for mod_rsi.c
 * @author Harlan Shoop
 * @version 0.1
 * @date 2014-08-07
 */
#ifndef RSI_H_
#define RSI_H_

#include "commonTypes.h"

#define RSI_MAX_FRAME_SIZE			(64)			/**< Max size of RSI frame  		*/
#define RSI_HEADER_LENGTH			(4)				/**< Size of RSI header in bytes 	*/
#define RSI_SOF						(0x0A)			/**< Start of Frame byte 			*/
#define	ACP_ADDR					(0xFF)			/**< Address of ACP					*/

//ACP request codes:
#define POLL_APM_CRC                (0x44)			/**< Poll APM CRC command 			*/
#define POLL_APM_CHECKSUM           (0x3B)			/**< Poll APM Checksum command 		*/
#define POLL_RSD_CRC                (0x3A)			/**< Poll RSD CRC command 			*/
#define POLL_RSD_CHECKSUM           (0x74)			/**< Poll RSD Checksum command 		*/
#define APM_TIMED_UNLOCK           	(0x56)			/**< APM Timed Unlock command		*/

//Gateway response codes:
#define APM_STATUS		          	(0x30)			/**< APM Status response			*/
#define RSD_STATUS		          	(0x31)			/**< RSD Status response			*/
#define RSD_STATUS_EXTENDED			(0x34)			/**< RSD Status Extended response	*/

//#define GET_OEM_CODE                (0x6F)
//#define GET_RSD_INFORMATION         (0x3C)
//#define GET_FIRMWARE_VERSION        (0x2C)
//#define SET_RSD_CONFIGURATION       (0x77)

/**< RSD status enumerator			*/
typedef enum rsdStatus {							
	RSD_STATUS_IDLE,
	RSD_STATUS_CHANGE,
	RSD_STATUS_CARDDATA,
} rsdStatus_t;										/**< RSD status type				*/

uInt16_t rsi_open(void);
uInt16_t rsi_close(uInt16_t fd);
uInt16_t rsi_read( uInt16_t fd, uInt8_t *buffer );
uInt16_t rsi_write( uInt16_t fd, uInt8_t *buffer, uInt16_t numBytes );
sInt32_t rsi_validateFrame( uInt8_t *buffer, uInt16_t msgLength );
sInt32_t rsi_handler(uInt8_t *rsiRequest, uInt8_t *rsiResponseFrame,
        sInt32_t * frameLength);


#endif /* RSI_H_ */
