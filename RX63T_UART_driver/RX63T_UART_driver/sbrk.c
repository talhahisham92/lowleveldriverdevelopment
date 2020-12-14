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
* File Name     : sbrk.c
* Version       : 1.00
* Device        : R5F563T6
* Tool-Chain    : RX Family C Compiler 1.2.1.0
* H/W Platform  : RSKRX63T
* Description   : Configures the MCU heap memory.
*******************************************************************************/
/*******************************************************************************
* History       : 05.02.2013  Ver. 1.00 First Release
*******************************************************************************/

/*******************************************************************************
User Includes (Project Level Includes)
*******************************************************************************/
/* Provides standard io definitions used in this file */
#include <stdio.h>

/* Provides standard variable type defines used in this file */
#include "typedefine.h"

/* Declares functions defined in this file */
#include "sbrk.h"

/*******************************************************************************
* Type Defines
*******************************************************************************/
typedef union 
{
    /* Dummy for 4-byte boundary */
    _SDWORD  dummy;        

    /* Declaration of the area managed by sbrk*/
    _SBYTE heap[HEAPSIZE];  
} heap_type_t;

/*******************************************************************************
* Local Variables
*******************************************************************************/


/*******************************************************************************
* Function Name: sbrk
* Description  : This function configures MCU memory area allocation.
* Arguments    : size - assigned area size
* Return Value : Start address of allocated area (pass)
*                -1 (failure)
*******************************************************************************/
_SBYTE  *sbrk (const size_t size)                      
{
    /* Declare memory heap area */
    static heap_type_t heap_area;
    
    /* End address allocated by sbrk    */
    static _SBYTE    * brk = (_SBYTE * ) &heap_area;
    
    /* Declare a pointer to use for the memory to be allocated */
    _SBYTE           * p;

    if ((brk + size) > (heap_area.heap + HEAPSIZE))
    {
        /* Empty area size  */
        p = (_SBYTE * ) -1;
    }
    else 
    {
        /* Area assignment */
        p = brk;  
          
        /* End address update */                           
        brk += size;                           
    }
    
    /* Return result */
    return p;
}
/*******************************************************************************
* End of function sbrk
*******************************************************************************/

