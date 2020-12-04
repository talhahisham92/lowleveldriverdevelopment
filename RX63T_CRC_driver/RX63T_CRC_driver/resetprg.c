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
/*******************************************************************************
* Copyright (C) 2012 Renesas Electronics Corporation. All rights reserved.    */
/*******************************************************************************
* File Name     : resetprg.c
* Version       : 1.00
* Device        : R5F563T6
* Tool-Chain    : RX Family C Compiler 1.2.1.0
* H/W Platform  : RSKRX63T
* Description   : Defines post-reset routines that are used to configure the
*                 MCU prior to the main program starting. This is where the 
*                 program counter starts on power-up or reset. 
*******************************************************************************/
/*******************************************************************************
* History       : 05.02.2013  Ver. 1.00 First Release
*******************************************************************************/

/*******************************************************************************
* User Includes (Project Level Includes)
*******************************************************************************/
/* Defines system level functions used in this file */
#include <machine.h>

/* Defines MCU configuration functions used in this file */
#include <_h_c_lib.h>

/* Defines the size of the stack which configured in this file */
#include "stacksct.h"

/* Contains hardware setup function prototypes. */
#include "hwsetup.h"

/* Contains main module function prototypes. */
#include "main.h"

/* Contains module function prototype exports */
#include "resetprg.h"

/*******************************************************************************
* Compiler Directives
*******************************************************************************/
/* Declare the contents of the function 'change_psw_pm_to_user_mode' as
   assembly to the compiler */
#pragma inline_asm change_psw_pm_to_user_mode

/*******************************************************************************
* Macro Definitions
*******************************************************************************/
#define PSW_INIT  0x00010000
#define FPSW_INIT 0x00000100

/*******************************************************************************
* Pre-processor Directives
*******************************************************************************/
/* Set this as the location of the 'ResetPRG' section */
#pragma section ResetPRG

/* Set this as the entry point from a power-on reset */
#pragma entry PowerON_Reset_PC

/*******************************************************************************
* Local Function Prototypes
*******************************************************************************/
/* MCU usermode switcher function declaration */
static void change_psw_pm_to_user_mode(void);

/*******************************************************************************
* Function Name : PowerON_Reset_PC
* Description   : This program is the MCU's entry point from a power-on reset.
*                 The function configures the MCU stack, then calls the
*                 HardwareSetup function and main function sequentially.
* Argument      : none
* Return value  : none
*******************************************************************************/
void PowerON_Reset_PC (void)
{
    /* Initialise the MCU processor word */
    set_intb((__sectop("C$VECT")));
    set_fpsw(FPSW_INIT);

    /* Initialise the MCU stack area */
    _INITSCT();

    /* Configure the MCU and RSK hardware */
    HardwareSetup();
    
    /* Execute a NOP instruction */
    nop();
    
    /* Set Ubit and Ibit for PSW */
    set_psw(PSW_INIT);

    /* Change the MCU's usermode from supervisor to user */             
    change_psw_pm_to_user_mode();

    /* Call the main program function */
    main();

    /* Invoke a break interrupt */
    brk();
}
/*******************************************************************************
* End of function PowerON_Reset_PC
*******************************************************************************/

/*******************************************************************************
* Function Name : change_psw_pm_to_user_mode
* Description   : Assembler function, used to change the MCU's user mode from
*                 supervisor to user.
* Argument      : none
* Return value  : none
*******************************************************************************/
static void change_psw_pm_to_user_mode (void)
{
    MVFC   PSW,R1
    OR     #00100000h,R1
    PUSH.L R1
    MVFC   PC,R1
    ADD    #10,R1
    PUSH.L R1
    RTE
    NOP
    NOP
}
/*******************************************************************************
* End of function change_psw_pm_to_user_mode
*******************************************************************************/


