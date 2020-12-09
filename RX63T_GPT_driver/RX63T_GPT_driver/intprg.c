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
* File Name     : intprg.c
* Version       : 1.00
* Device        : R5F563T6
* Tool-Chain    : RX Family C Compiler 1.2.1.0
* H/W Platform  : RSKRX63T
* Description   : Contains empty interrupt handler functions
*******************************************************************************/
/*******************************************************************************
* History       : 05.02.2013 Ver. 1.00 First Release
*******************************************************************************/

/*******************************************************************************
* System Includes
*******************************************************************************/
/* Includes assembly level function definitions */
#include <machine.h>

/*******************************************************************************
User Includes (Project Level Includes)
*******************************************************************************/
/* Includes interrupt vector definitions */
#include "vect.h"

/* Set this as the location of the 'IntPRG' section */
#pragma section IntPRG

// Exception(Supervisor Instruction)
void Excep_SuperVisorInst(void){/* brk(); */}

// Exception(Undefined Instruction)
void Excep_UndefinedInst(void){/* brk(); */}

// Exception(Floating Point)
void Excep_FloatingPoint(void){/* brk(); */}

// NMI
void NonMaskableInterrupt(void){/* brk(); */}

// Dummy
void Dummy(void){/* brk(); */}

// BRK
void Excep_BRK(void){ wait(); }

// BSC BUSERR
void Excep_BSC_BUSERR(void){ }

// FCU FIFERR
void Excep_FCU_FIFERR(void){ }

// FCU FRDYI
void Excep_FCU_FRDYI(void){ }

// ICU SWINT
void Excep_ICU_SWINT(void){ }

// CMT0 CMI0
//void Excep_CMT0_CMI0(void){ }

// CMT1 CMI1
void Excep_CMT1_CMI1(void){ }

// CMT2 CMI2
void Excep_CMT2_CMI2(void){ }

// CMT3 CMI3
void Excep_CMT3_CMI3(void){ }

// CAC FERRF
void Excep_CAC_FERRF(void){ }

// CAC MENDF
void Excep_CAC_MENDF(void){ }

// CAC OVFF
void Excep_CAC_OVFF(void){ }

// RSPI0 SPRI0
void Excep_RSPI0_SPRI0(void){ }

// RSPI0 SPTI0
void Excep_RSPI0_SPTI0(void){ }

// RSPI0 SPII0
void Excep_RSPI0_SPII0(void){ }

// DOC DOPCF
void Excep_DOC_DOPCF(void){ }

// ICU IRQ0
//void Excep_ICU_IRQ0(void){ }

// ICU IRQ1
//void Excep_ICU_IRQ1(void){ }

// ICU IRQ2
//void Excep_ICU_IRQ2(void){ }

// ICU IRQ3
void Excep_ICU_IRQ3(void){ }

// ICU IRQ4
void Excep_ICU_IRQ4(void){ }

// ICU IRQ5
void Excep_ICU_IRQ5(void){ }

// S12AD S12ADI
void Excep_S12AD_S12ADI(void){ }

// S12AD S12GBADI
void Excep_S12AD_S12GBADI(void){ }

// ICU GROUP12
void Excep_ICU_GROUP12(void){ }

// SCI12 SCIX0
void Excep_SCI12_SCIX0(void){ }

// SCI12 SCIX1
void Excep_SCI12_SCIX1(void){ }

// SCI12 SCIX2
void Excep_SCI12_SCIX2(void){ }

// SCI12 SCIX3
void Excep_SCI12_SCIX3(void){ }

// MTU0 TGIA0
void Excep_MTU0_TGIA0(void){ }

// MTU0 TGIB0
void Excep_MTU0_TGIB0(void){ }

// MTU0 TGIC0
void Excep_MTU0_TGIC0(void){ }

// MTU0 TGID0
void Excep_MTU0_TGID0(void){ }

// MTU0 TCIV0
void Excep_MTU0_TCIV0(void){ }

// MTU0 TGIE0
void Excep_MTU0_TGIE0(void){ }

// MTU0 TGIF0
void Excep_MTU0_TGIF0(void){ }

// MTU1 TGIA1
void Excep_MTU1_TGIA1(void){ }

// MTU1 TGIB1
void Excep_MTU1_TGIB1(void){ }

// MTU1 TCIV1
void Excep_MTU1_TCIV1(void){ }

// MTU1 TCIU1
void Excep_MTU1_TCIU1(void){ }

// MTU2 TGIA2
void Excep_MTU2_TGIA2(void){ }

// MTU2 TGIB2
void Excep_MTU2_TGIB2(void){ }

// MTU2 TCIV2
void Excep_MTU2_TCIV2(void){ }

// MTU2 TCIU2
void Excep_MTU2_TCIU2(void){ }

// MTU3 TGIA3
void Excep_MTU3_TGIA3(void){ }

// MTU3 TGIB3
void Excep_MTU3_TGIB3(void){ }

// MTU3 TGIC3
void Excep_MTU3_TGIC3(void){ }

// MTU3 TGID3
void Excep_MTU3_TGID3(void){ }

// MTU3 TCIV3
void Excep_MTU3_TCIV3(void){ }

// MTU4 TGIA4
void Excep_MTU4_TGIA4(void){ }

// MTU4 TGIB4
void Excep_MTU4_TGIB4(void){ }

// MTU4 TGIC4
void Excep_MTU4_TGIC4(void){ }

// MTU4 TGID4
void Excep_MTU4_TGID4(void){ }

// MTU4 TCIV4
void Excep_MTU4_TCIV4(void){ }

// MTU5 TGIU5
void Excep_MTU5_TGIU5(void){ }

// MTU5 TGIV5
void Excep_MTU5_TGIV5(void){ }

// MTU5 TGIW5
void Excep_MTU5_TGIW5(void){ }

// MTU6 TGIA6
void Excep_MTU6_TGIA6(void){ }

// MTU6 TGIB6
void Excep_MTU6_TGIB6(void){ }

// MTU6 TGIC6
void Excep_MTU6_TGIC6(void){ }

// MTU6 TGID6
void Excep_MTU6_TGID6(void){ }

// MTU6 TCIV6
void Excep_MTU6_TCIV6(void){ }

// MTU7 TGIA7
void Excep_MTU7_TGIA7(void){ }

// MTU7 TGIB7
void Excep_MTU7_TGIB7(void){ }

// MTU7 TGIC7
void Excep_MTU7_TGIC7(void){ }

// MTU7 TGID7
void Excep_MTU7_TGID7(void){ }

// MTU7 TCIV7
void Excep_MTU7_TCIV7(void){ }

// POE OEI1
void Excep_POE_OEI1(void){ }

// POE OEI3
void Excep_POE_OEI3(void){ }

// POE OEI4
void Excep_POE_OEI4(void){ }

// CMP CMP0
void Excep_CMP_CMP0(void){ }

// CMP CMP1
void Excep_CMP_CMP1(void){ }

// CMP CMP2
void Excep_CMP_CMP2(void){ }

// RIIC0 EEI0
void Excep_RIIC0_EEI0(void){ }

// RIIC0 RXI0
void Excep_RIIC0_RXI0(void){ }

// RIIC0 TXI0
void Excep_RIIC0_TXI0(void){ }

// RIIC0 TEI0
void Excep_RIIC0_TEI0(void){ }

// DMAC DMAC0I
void Excep_DMAC_DMAC0I(void){ }

// DMAC DMAC1I
void Excep_DMAC_DMAC1I(void){ }

// DMAC DMAC2I
void Excep_DMAC_DMAC2I(void){ }

// DMAC DMAC3I
void Excep_DMAC_DMAC3I(void){ }

// SCI0 RXI0
void Excep_SCI0_RXI0(void){ }

// SCI0 TXI0
void Excep_SCI0_TXI0(void){ }

// SCI0 TEI0
void Excep_SCI0_TEI0(void){ }

// SCI1 RXI1
void Excep_SCI1_RXI1(void){ }

// SCI1 TXI1
void Excep_SCI1_TXI1(void){ }

// SCI1 TEI1
void Excep_SCI1_TEI1(void){ }

// GPT0 GTCIA0
void Excep_GPT0_GTCIA0(void){ }

// GPT0 GTCIB0
void Excep_GPT0_GTCIB0(void){ }

// GPT0 GTCIC0
void Excep_GPT0_GTCIC0(void){ }

// GPT0 GTCIE0
void Excep_GPT0_GTCIE0(void){ }

// GPT0 GTCIV0
void Excep_GPT0_GTCIV0(void){ }

// GPT0 LOCOI
void Excep_GPT0_LOCOI(void){ }

// GPT1 GTCIA1
void Excep_GPT1_GTCIA1(void){ }

// GPT1 GTCIB1
void Excep_GPT1_GTCIB1(void){ }

// GPT1 GTCIC1
void Excep_GPT1_GTCIC1(void){ }

// GPT1 GTCIE1
void Excep_GPT1_GTCIE1(void){ }

// GPT1 GTCIV1
void Excep_GPT1_GTCIV1(void){ }

// GPT2 GTCIA2
void Excep_GPT2_GTCIA2(void){ }

// GPT2 GTCIB2
void Excep_GPT2_GTCIB2(void){ }

// GPT2 GTCIC2
void Excep_GPT2_GTCIC2(void){ }

// GPT2 GTCIE2
void Excep_GPT2_GTCIE2(void){ }

// GPT2 GTCIV2
void Excep_GPT2_GTCIV2(void){ }

// GPT3 GTCIA3
void Excep_GPT3_GTCIA3(void){ }

// GPT3 GTCIB3
void Excep_GPT3_GTCIB3(void){ }

// GPT3 GTCIC3
void Excep_GPT3_GTCIC3(void){ }

// GPT3 GTCIE3
void Excep_GPT3_GTCIE3(void){ }

// GPT3 GTCIV3
void Excep_GPT3_GTCIV3(void){ }

// SCI12 RXI12
void Excep_SCI12_RXI12(void){ }

// SCI12 TXI12
void Excep_SCI12_TXI12(void){ }

// SCI12 TEI12
void Excep_SCI12_TEI12(void){ }

