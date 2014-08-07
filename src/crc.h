/** 
 * @file crc.h
 * @brief Header file for crc.c
 * @author Keith Broerman
 * @version 0.1
 * @date 2014-05-22
 */

#ifndef CRC_H_
#define CRC_H_

#include "commonTypes.h"

#define CRC_SIZE		(2)			/**< Number of bytes in CRC */
#define CRC_LSB_INDEX	(0)			/**< Index for LSB 			*/
#define CRC_MSB_INDEX	(1)			/**< Index for MSB			*/
#define CRC_TBL_SIZE    (256)		/**< CRC table size			*/
#define LSB_MASK        (0x00FF)	/**< LSB mask				*/
#define MSB_MASK        (0xFF00)	/**< MSB mask				*/
#define BYTE_SIZE       (8)			/**< Bits per byte			*/

uInt16_t gTable[CRC_TBL_SIZE]; 		/**< Global CRC Table		*/

void printTable(void);
void buildXmodem(void);
uInt16_t xmodemCrc(uInt8_t byteVal, uInt16_t tempCrc);
uInt16_t calculateCrcBuf(uInt8_t * crcBuf, sInt32_t bufLength,
        uInt16_t tempCrc);
sInt32_t calculateCrc(uInt8_t * rsiFrame, sInt32_t frameLength, uInt8_t *crcVal);
void crcInit(void);
uInt8_t calculateChecksum(uInt8_t * rsiFrame, sInt32_t frameLength);

#endif /* CRC_H_ */
