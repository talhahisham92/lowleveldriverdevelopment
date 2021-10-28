/*******************************************************************************
* File Name     : crc.c
* Version       : 1.00
* Device        : R5F563T6
* Tool-Chain    : RX Family C Compiler 1.2.1.0
* H/W Platform  : RSKRX63T
* Description   : LCD Module utility functions.
*                 Written for KS0066u compatible LCD Module.
*                 (8 characters by 2 lines)
*******************************************************************************/
#include "crc.h"
#include <machine.h>
#include "iodefine.h"
//nooooyyyyeeee
void clearCRC()
{
	CRC.CRCCR.BIT.DORCLR = 1; // clear CRCDOR register
}

void CRC_Init(crc_config_t* config)
{
   SYSTEM.PRCR.WORD = 0xA50B; 	// enable register writting		
   SYSTEM.MSTPCRB.BIT.MSTPB23 = 0x00;    // Initialize CRC module
  
  CRC.CRCCR.BIT.GPS = config->crc_polynomial; // set polynomial option
   CRC.CRCCR.BIT.LMS = config->crc_switching;	// set MSB or LSB first option
}

uint16_t CalculateCRC(const uint8_t* data, uint32_t length)
{
	while(length > 0)
	{
		CRC.CRCDIR = *data; // input register
		data++;
		length--;
	}		
	return CRC.CRCDOR; // read output register
}




