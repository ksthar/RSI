/** 
 * @file rsi_commands.h
 * @brief Header for rsi_commands.c
 * @author Keith Broerman
 * @version 0.1
 * @date 2014-05-22
 */
#ifndef RSI_COMMANDS_H_
#define RSI_COMMANDS_H_

#include "commonTypes.h"

sInt32_t processPollRsd(uInt8_t * rsiResponseFrame);
sInt32_t processPollApm(uInt8_t * rsiResponseFrame);
sInt32_t processApmTimedUnlock(uInt8_t * rsiRequestFrame, uInt8_t * rsiResponseFrame);

#endif /* RSI_COMMANDS_H_ */
