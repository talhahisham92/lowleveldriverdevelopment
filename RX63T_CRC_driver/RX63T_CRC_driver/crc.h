/*******************************************************************************
* File Name     : crc.h
* Version       : 1.00
* Device        : R5F563T6
* Tool-Chain    : RX Family C Compiler 1.2.1.0
* H/W Platform  : RSKRX63T
* Description   : LCD Module utility functions.
*                 Written for KS0066u compatible LCD Module.
*                 (8 characters by 2 lines)
*******************************************************************************/

#ifndef CRC_H
#define CRC_H

#include <stdint.h>
	
typedef enum {NO_CALCULATION , X8X2X1, X16X15X21, X16X12X51} crc_polynomial_t; // read HW manual to see options
typedef enum {LSB_FIRST, MSB_FIRST} crc_switching_t; // read HW manual to see options

typedef struct _crc_config{  // struct for config
	crc_polynomial_t crc_polynomial;
	crc_switching_t crc_switching;
} crc_config_t;

void clearCRC();
void CRC_Init(crc_config_t* config);
uint16_t CalculateCRC(const uint8_t* data, uint32_t length);

#endif


