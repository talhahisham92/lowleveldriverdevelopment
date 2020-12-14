/*******************************************************************************
* File Name     : uart.c
* Version       : 1.00
* Device        : R5F563T6
* Tool-Chain    : RX Family C Compiler 1.2.1.0
* H/W Platform  : RSKRX63T
* Description   : Defines UART initialization and config methods     
*******************************************************************************/
#include "uart.h"
#include "iodefine.h"
#include "vect.h"	
					   					//2400 4800 9600 19200
const uint8_t values_for_baudrates[4] = {121,  60,  29,  14};
volatile uint8_t SCI_RX; // Declare a receive buffer variable

void Init_UART()
{
	SYSTEM.PRCR.WORD = 0xA50B;
	SYSTEM.MSTPCRB.BIT.MSTPB31 = 0; // Wake up SCI0
	
	MPC.PWPR.BIT.B0WI = 0;
	MPC.PWPR.BIT.PFSWE = 1;		    
    MPC.P24PFS.BYTE = 0x0A; /* Set Port2's pin 4 function to RXD0 */
    MPC.P30PFS.BYTE = 0x0A; /* Set Port3's pin 0 function to TXD0 */
	MPC.PWPR.BIT.PFSWE = 0;			
	MPC.PWPR.BIT.B0WI = 1;			
	
	PORT2.PMR.BYTE = 0x10;
    PORT3.PMR.BYTE = 0x01;
	
	SCI0.SCR.BYTE = 0; // Clear all control bits
	SCI0.SIMR1.BIT.IICM = 0 ;
	SCI0.SPMR.BIT.CKPH = 0; 
	SCI0.SPMR.BIT.CKPOL = 0;
	
	SCI0.SMR.BIT.CKS = 1; // Clock will be set to PCLK/4 37.5MHz , leave SEMR as default
	ICU.IPR[214].BYTE = 0x04; // Set recieve interrupt priority at interrupt controller
	ICU.IER[26].BIT.IEN6 = 1; //Enable recieve interrupt at interrupt controller
}

void SCI0_config(uart_config_t* config)
{
	SCI0.BRR = values_for_baudrates[config->uart_baudrate]; // set baudrate
	SCI0.SMR.BIT.CHR = config->uart_characterlength;
	SCI0.SMR.BIT.PE = config->uart_parity_enable;
	SCI0.SMR.BIT.PM = config->uart_parity_mode;
}

void SCI0_write(volatile const uint8_t* data, uint16_t length)
{
	uint16_t i;
	
	for(i = 0; i < length; i++)
	{
		SCI0.TDR = data[i];
		
		while(SCI0.SSR.BIT.TEND == 0);	// wait for last transmit to finish
	}
}


void SCI0_start()
{
	SCI0.SCR.BIT.TE = 1; // Enable transmit
	SCI0.SCR.BIT.RE = 1; // Enable recieve
	SCI0.SCR.BIT.RIE = 1; // Enable recieve interrupt
}

void Excep_SCI0_RXI0()
{
	SCI_RX = SCI0.RDR;
	SCI0_write(&SCI_RX, 1);	
}