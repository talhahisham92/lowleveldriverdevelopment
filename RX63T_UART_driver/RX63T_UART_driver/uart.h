/*******************************************************************************
* File Name     : uart.h
* Version       : 1.00
* Device        : R5F563T6
* Tool-Chain    : RX Family C Compiler 1.2.1.0
* H/W Platform  : RSKRX63T
* Description   : Declares UART initialization and config methods     
*******************************************************************************/
#ifndef UART_H
#define UART_H

#include<stdint.h>
#include<machine.h>			
										
extern const uint8_t values_for_baudrates[4];

typedef enum {EVEN, ODD} uart_paritymode_t;
typedef enum {DISABLED, ENABLED} uart_parityenable_t;
typedef enum {BIT8, BIT7} uart_characterlength_t;
typedef enum {BAUDRATE2400,BAUDRATE4800,BAUDRATE9600,BAUDRATE19200} uart_baudrate_t;

typedef struct _uart_config{
	uart_baudrate_t uart_baudrate;
	uart_characterlength_t uart_characterlength;
	uart_paritymode_t uart_parity_mode;
	uart_parityenable_t uart_parity_enable;
}uart_config_t;

void Init_UART();
void SCI0_config(uart_config_t* config);
void SCI0_start();
void SCI0_write(volatile const uint8_t* data, uint16_t length);

#endif