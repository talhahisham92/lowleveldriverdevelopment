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
* File Name     : vect.c
* Version       : 1.00
* Device        : R5F563T6
* Tool-Chain    : RX Family C Compiler 1.2.1.0
* H/W Platform  : RSKRX63T
* Description   : Initialise of Vector Table and MDE register.
*******************************************************************************/
/*******************************************************************************
* History       : 05.02.2013 Ver. 1.00 First Release
*******************************************************************************/

/*******************************************************************************
* User Includes (Project Level Includes)
*******************************************************************************/
/* Includes interrupt vector definitions */
#include "vect.h"

/* Set this as the location of the 'FIXEDVECT' section */
#pragma section C FIXEDVECT

/*******************************************************************************
* Outline       : Fixed_Vectors
* Description   : Vector table initialisation
* Argument      : none
* Return value  : none
*******************************************************************************/
void (*const Fixed_Vectors[])(void) = {

/*;0xffffffd0  Exception(Supervisor Instruction) */
    Excep_SuperVisorInst,

/*;0xffffffd4  Reserved */
    Dummy,

/*;0xffffffd8  Reserved */
    Dummy,

/*;0xffffffdc  Exception(Undefined Instruction) */
    Excep_UndefinedInst,

/*;0xffffffe0  Reserved */
    Dummy,

/*;0xffffffe4  Exception(Floating Point) */
    Excep_FloatingPoint,

/*;0xffffffe8  Reserved */
    Dummy,

/*;0xffffffec  Reserved */
    Dummy,

/*;0xfffffff0  Reserved */
    Dummy,

/*;0xfffffff4  Reserved */
    Dummy,

/*;0xfffffff8  NMI */
    NonMaskableInterrupt,

/*;0xfffffffc  RESET */
/*;<<VECTOR DATA START (POWER ON RESET)>> */

/*;Power On Reset PC */
PowerON_Reset_PC

/*;<<VECTOR DATA END (POWER ON RESET)>> */
};

/* MDE register (Single Chip Mode) */
#pragma address MDEreg=0xffffff80 
#ifdef __BIG
    const unsigned long MDEreg = 0xfffffff8; 
#else
    const unsigned long MDEreg = 0xffffffff;
#endif
/*******************************************************************************
* End of Fixed_Vectors
*******************************************************************************/

