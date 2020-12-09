/*******************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only
* intended for use with Renesas products. No other uses are authorized. This
* software is owned by Renesas Electronics Corporation and is protected under
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software
* and to discontinue the availability of this software. By using this software,
* you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
*******************************************************************************/
/* Copyright (C) 2013 Renesas Electronics Corporation. All rights reserved.   */
/*******************************************************************************
* File Name     : hwsetup.c
* Version       : 1.00
* Device        : R5F563T6
* Tool-Chain    : RX Family C Compiler 1.2.1.0
* H/W Platform  : RSKRX63T
* Description   : Defines the hardware initialisation routines used each time 
*                 the MCU is restarted. 
*******************************************************************************/
/*******************************************************************************
* History       : 05.02.2013  Ver. 1.00 First Release
*******************************************************************************/

/*******************************************************************************
System Includes
*******************************************************************************/
/* Includes assembly level definitions */
#include <machine.h>

/* Following header file provides C99 type definitions. */
#include <stdint.h>

/*******************************************************************************
User Includes (Project Level Includes)
*******************************************************************************/
/* Defines R5F563T6 port registers */
#include "iodefine.h"

/* Defines macros relating to the R5F563T6 user LEDs and switches */
#include "rskrx63tdef.h"

/* LCD controlling function prototypes & macro definitions */
#include "lcd.h"

/* Switch handler function definitions */
#include "switch.h"

/* Contains declarations for the functions defined in this file */
#include "hwsetup.h"

/*******************************************************************************
* Function Name : HardwareSetup
* Description   : Contains all the setup functions called at device restart
* Argument      : none
* Return value  : none
*******************************************************************************/
void HardwareSetup (void)
{
    ConfigureOperatingFrequency();
    ConfigureOutputPorts();
    ConfigureInterrupts();
    EnablePeripheralModules();
}
/*******************************************************************************
* End of function HardwareSetup
*******************************************************************************/

/*******************************************************************************
* Function Name : ConfigureOperatingFrequency
* Description   : Configures the clock settings for each of the device clocks
* Argument      : none
* Return value  : none
*******************************************************************************/
void ConfigureOperatingFrequency (void)
{       
    /* Declare and initialise a loop count variable */
    uint16_t i = 0;
        
    /* Protection off */
    SYSTEM.PRCR.WORD = 0xA503;          
    
#ifdef INSTALL__SUB_CLOCK
    /* Stop sub-clock */
    SYSTEM.SOSCCR.BYTE = 0x01;          
#endif /* SOSCCR */
                    
    /* Specify a clock stabilisation time, greater than 10ms at 16MHz 
       (16.384 msec) */
    /* XTAL = 16MHz, Period = 62.5 ns, 
       ( {MOSCWTCR = 0x0E} 262144 * 62.5ns ) = 16.384 ms */
    SYSTEM.MOSCWTCR.BYTE = 0x0E;        
        
    /* 4194304 state (default)*/
    /* wait over 12ms  @PLL=192MHz(16MHz*12) */                             
    SYSTEM.PLLWTCR.BYTE = 0x0F;         
    
    /* x12 @PLL */
    SYSTEM.PLLCR.WORD = 0x0B00; 
      
    /* Turn on EXTAL */
    SYSTEM.MOSCCR.BYTE = 0x00;  
            
    /* Turn on the PLL and enable writing to the PLL control register */
    SYSTEM.PLLCR2.BYTE = 0x00;  
    
    /* Wait over 12ms */
    for (i = 0; i < 2075; i++)
    {
        nop();
    }
        
    /* Configure the clocks as follows -
    Clock Description              Frequency
    ----------------------------------------
    PLL Clock frequency............... NOT 192MHz but 150MHz as XTAL is 12.5
    System Clock Frequency.............96MHz
    Peripheral Module Clock B..........48MHz    
    FlashIF Clock......................48MHz
    External Bus Clock.................48MHz
	PCKA...............................75MHz as XTAL is 12.5 and not 16 in my case */             
    SYSTEM.SCKCR.LONG = 0x21821211;     
   
    /* Set the clock source to PLL */
    SYSTEM.SCKCR3.WORD = 0x0400;
    
    /* Protection on */
    SYSTEM.PRCR.WORD = 0xA500;  
}
/*******************************************************************************
* End of function ConfigureOperatingFrequency
*******************************************************************************/

/*******************************************************************************
* Function Name : ConfigureOutputPorts
* Description   : Configures the port and pin direction settings, and sets the
*                 pin outputs to a safe level.
* Argument      : none
* Return value  : none
*******************************************************************************/
void ConfigureOutputPorts (void)
{   
    /* Configure the LED pins (LED0-LED3) as outputs */
    LED0_PORT_DIR = 0x1;
    LED1_PORT_DIR = 0x1;
    LED2_PORT_DIR = 0x1;
    LED3_PORT_DIR = 0x1;

    /* Set LED pin outputs as high (all LEDs off) */
    LED0 = LED_OFF;
    LED1 = LED_OFF;
    LED2 = LED_OFF;
    LED3 = LED_OFF;
    
    /* Configure the debug LCD data pins (DLCD7-DLCD4 {P94 - P91}) as outputs */
    LCD_DATA_DIR_PORT = 0x1E;
            
    /* Set debug LCD data pin (DLCD7-DLCD4) outputs as low */
    LCD_DATA_PORT = 0x00;
    
    /* Configure the debug LCD control pin (DLCDRS) and enable pin (DLCDE)
       as output */
    RS_PIN_DIR = 0x1;
    E_PIN_DIR  = 0x1;
            
    /* Set the debug LCD control pin (DLCDRS) and enable pin (DLCDE) as output
       low */
    RS_PIN = 0x0;
    E_PIN  = 0x0;   
}
/*******************************************************************************
* End of function ConfigureOutputPorts
*******************************************************************************/

/*******************************************************************************
* Function Name : ConfigureInterrupts
* Description   : Configures the interrupts used
* Argument      : none
* Return value  : none
*******************************************************************************/
void ConfigureInterrupts (void)
{
    /* Configure switch interrupts */
    InitialiseSwitchInterrupts();
}
/*******************************************************************************
* End of function ConfigureInterrupts
*******************************************************************************/

/*******************************************************************************
* Function Name : EnablePeripheralModules
* Description   : Enables and configures peripheral devices on the MCU
* Argument      : none
* Return value  : none
*******************************************************************************/
void EnablePeripheralModules (void)
{
    /* Peripherals initialised in specific initialisation functions */
}
/*******************************************************************************
* End of function EnablePeripheralModules
*******************************************************************************/

