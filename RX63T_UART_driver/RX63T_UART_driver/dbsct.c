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
* File Name     : dbsct.c
* Version       : 1.00
* Device        : R5F563T6
* Tool Chain    : RX Family C Compiler 1.2.1.0
* H/W Platform  : RSKRX63T
* Description   : Defines the structure of ROM and RAM areas.
*******************************************************************************/
/*******************************************************************************
* History       : 05.02.2013  Ver. 1.00 First Release
*******************************************************************************/

/*******************************************************************************
User Includes (Project Level Includes)
*******************************************************************************/
/* Defines type structures used in this file */
#include "typedefine.h"

/* Preprocessor directive to specify the boundary alignment value for the 
   members of structures & unions */
#pragma unpack

/* Specify a start of the section C$DSEC */
#pragma section C C$DSEC

/* MCU ROM and RAM structure definition */
extern const struct {
    _UBYTE * rom_s;   /* Start address of the initialized data section in ROM */
    _UBYTE * rom_e;   /* End address of the initialized data section in ROM   */
    _UBYTE * ram_s;   /* Start address of the initialized data section in RAM */
}   _DTBL[] = {
    { __sectop("D"), __secend("D"), __sectop("R") },
    { __sectop("D_2"), __secend("D_2"), __sectop("R_2") },
    { __sectop("D_1"), __secend("D_1"), __sectop("R_1") },
    { __sectop("L"), __secend("L"), __sectop("L") }
};

/* Specify a start of the section C$BSEC */
#pragma section C C$BSEC

/* MCU ROM and RAM structure definition */
extern const struct {
    _UBYTE * b_s;         /* Start address of non-initialized data section */
    _UBYTE * b_e;         /* End address of non-initialized data section   */
}   _BTBL[] = {
    { __sectop("B"), __secend("B") },
    { __sectop("B_2"), __secend("B_2") },
    { __sectop("B_1"), __secend("B_1") }
};

/* End of section C$BSEC */
#pragma section

/* CTBL prevents excessive output of L1100 messages when linking.
   Even if CTBL is deleted, the operation of the program does not change. */
_UBYTE * const _CTBL[] = {
    __sectop("C_1"), __sectop("C_2"), __sectop("C"),
    __sectop("W_1"), __sectop("W_2"), __sectop("W")
};

/* Preprocessor directive to specify the boundary alignment value for the 
   members of structures & unions */
#pragma packoption


