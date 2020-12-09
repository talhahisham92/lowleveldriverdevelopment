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
* File Name     : main.c
* Version       : 1.00
* Device        : R5F563T6
* Tool-Chain    : RX Family C Compiler 1.2.1.0
* H/W Platform  : RSKRX63T
* Description   : Empty main program.
*******************************************************************************/
/*******************************************************************************
* History       : 05.02.2013  Ver. 1.00 First Release
*******************************************************************************/

/*******************************************************************************
User Includes (Project Level Includes)
*******************************************************************************/
/* main definitions */
#include "main.h"
#include "gpt.h"

/******************************************************************************
* Function Name : main
* Description   : The main program function.
* Argument      : none
* Return value  : none
******************************************************************************/
void main (void)
{

    /* Enter user code */
	 Init_GPT0();
	 gpt_config_t config;
	 
	 config.gpt_mode = TRIWAVE_PWM1; // Check hardware manual to see the mode specifics
	 config.gpt_prescalar = PCLKA; //PCLKA = 75MHz
	 config.gpt_compare_match_output_A = TOGGLE;
	 config.gpt_cycle_end_output_A = RETAIN;
	 config.gpt_compare_match_output_B = TOGGLE;
	 config.gpt_cycle_end_output_B = RETAIN;
	 config.initial_output_A = 0;
	 config.initial_output_B = 1;
	 
	 config.Overflow_value = 0xFFFF; // 65536 * 13.3 ns = 873ms
	 config.Compare_value_A = 0x8000; // 435ms
	 config.deadtime_included = 1;
	 config.Deadtime_Up_value = 0x1999;	 //87.3ms
	 config.Deadtime_Down_value = 0x1999; //87.3ms
	 
	 GPT0_config(&config);
	 Start_GPT0();

    /* Infinite while loop */
    while (1)
    {
        /* Do nothing */
    }
}
/******************************************************************************
* End of function main
******************************************************************************/

