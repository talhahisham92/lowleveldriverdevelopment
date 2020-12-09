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
* File Name     : vect.h
* Version       : 1.00
* Device        : R5F563T6
* Tool-Chain    : RX Family C Compiler 1.2.1.0
* H/W Platform  : RSKRX63T
* Description   : Contains interrupt vector defintion and function prototypes
*******************************************************************************/
/*******************************************************************************
* History       : 05.02.2013  Ver. 1.00 First Release
*******************************************************************************/


// Exception(Supervisor Instruction)
#pragma interrupt (Excep_SuperVisorInst)
void Excep_SuperVisorInst(void);

// Exception(Undefined Instruction)
#pragma interrupt (Excep_UndefinedInst)
void Excep_UndefinedInst(void);

// Exception(Floating Point)
#pragma interrupt (Excep_FloatingPoint)
void Excep_FloatingPoint(void);

// NMI
#pragma interrupt (NonMaskableInterrupt)
void NonMaskableInterrupt(void);

// Dummy
#pragma interrupt (Dummy)
void Dummy(void);

// BRK
#pragma interrupt (Excep_BRK(vect=0))
void Excep_BRK(void);

// vector  1 reserved
// vector  2 reserved
// vector  3 reserved
// vector  4 reserved
// vector  5 reserved
// vector  6 reserved
// vector  7 reserved
// vector  8 reserved
// vector  9 reserved
// vector 10 reserved
// vector 11 reserved
// vector 12 reserved
// vector 13 reserved
// vector 14 reserved
// vector 15 reserved

// BSC BUSERR
#pragma interrupt (Excep_BSC_BUSERR(vect=16))
void Excep_BSC_BUSERR(void);

// vector 17 reserved
// vector 18 reserved
// vector 19 reserved
// vector 20 reserved

// FCU FIFERR
#pragma interrupt (Excep_FCU_FIFERR(vect=21))
void Excep_FCU_FIFERR(void);

// vector 22 reserved

// FCU_FRDYI
#pragma interrupt (Excep_FCU_FRDYI(vect=23))
void Excep_FCU_FRDYI(void);

// vector 24 reserved
// vector 25 reserved
// vector 26 reserved

// ICU_SWINT
#pragma interrupt (Excep_ICU_SWINT(vect=27))
void Excep_ICU_SWINT(void);

// CMT0 CMI0
#pragma interrupt (Excep_CMT0_CMI0(vect=28))
void Excep_CMT0_CMI0(void);

// CMT1 CMI1
#pragma interrupt (Excep_CMT1_CMI1(vect=29))
void Excep_CMT1_CMI1(void);

// CMT2 CMI2
#pragma interrupt (Excep_CMT2_CMI2(vect=30))
void Excep_CMT2_CMI2(void);

// CMT3 CMI3
#pragma interrupt (Excep_CMT3_CMI3(vect=31))
void Excep_CMT3_CMI3(void);

// vector 32 reserved
// vector 33 reserved
// vector 34 reserved
// vector 35 reserved


// CAC FERRF
#pragma interrupt (Excep_CAC_FERRF(vect=36))
void Excep_CAC_FERRF(void);

// CAC MENDF
#pragma interrupt (Excep_CAC_MENDF(vect=37))
void Excep_CAC_MENDF(void);

// CAC OVFF
#pragma interrupt (Excep_CAC_OVFF(vect=38))
void Excep_CAC_OVFF(void);

// RSPI0 SPRI0
#pragma interrupt (Excep_RSPI0_SPRI0(vect=39))
void Excep_RSPI0_SPRI0(void);

// RSPI0 SPTI0
#pragma interrupt (Excep_RSPI0_SPTI0(vect=40))
void Excep_RSPI0_SPTI0(void);

// RSPI0 SPII0
#pragma interrupt (Excep_RSPI0_SPII0(vect=41))
void Excep_RSPI0_SPII0(void);

// vector 42 reserved
// vector 43 reserved
// vector 44 reserved
// vector 45 reserved
// vector 46 reserved
// vector 47 reserved
// vector 48 reserved
// vector 49 reserved
// vector 50 reserved
// vector 51 reserved
// vector 52 reserved
// vector 53 reserved
// vector 54 reserved
// vector 55 reserved
// vector 56 reserved

// DOC_DOPCF
#pragma interrupt (Excep_DOC_DOPCF(vect=57))
void Excep_DOC_DOPCF(void);

// vector 58 reserved
// vector 59 reserved
// vector 60 reserved
// vector 61 reserved
// vector 62 reserved
// vector 63 reserved

// ICU IRQ0
#pragma interrupt (Excep_ICU_IRQ0(vect=64))
void Excep_ICU_IRQ0(void);

// ICU IRQ1
#pragma interrupt (Excep_ICU_IRQ1(vect=65))
void Excep_ICU_IRQ1(void);

// ICU IRQ2
#pragma interrupt (Excep_ICU_IRQ2(vect=66))
void Excep_ICU_IRQ2(void);

// ICU IRQ3
#pragma interrupt (Excep_ICU_IRQ3(vect=67))
void Excep_ICU_IRQ3(void);

// ICU IRQ4
#pragma interrupt (Excep_ICU_IRQ4(vect=68))
void Excep_ICU_IRQ4(void);

// ICU IRQ5
#pragma interrupt (Excep_ICU_IRQ5(vect=69))
void Excep_ICU_IRQ5(void);

// vector 70 reserved
// vector 71 reserved
// vector 72 reserved
// vector 73 reserved
// vector 74 reserved
// vector 75 reserved
// vector 76 reserved
// vector 77 reserved
// vector 78 reserved
// vector 79 reserved
// vector 80 reserved
// vector 81 reserved
// vector 82 reserved
// vector 83 reserved
// vector 84 reserved
// vector 85 reserved
// vector 86 reserved
// vector 87 reserved
// vector 88 reserved
// vector 89 reserved
// vector 90 reserved
// vector 91 reserved
// vector 92 reserved
// vector 93 reserved
// vector 94 reserved
// vector 95 reserved
// vector 96 reserved
// vector 97 reserved
// vector 98 reserved
// vector 99 reserved
// vector 100 reserved
// vector 101 reserved

// S12AD S12ADI
#pragma interrupt (Excep_S12AD_S12ADI(vect=102))
void Excep_S12AD_S12ADI(void);

// S12AD S12GBADI
#pragma interrupt (Excep_S12AD_S12GBADI(vect=103))
void Excep_S12AD_S12GBADI(void);

// vector 104 reserved
// vector 105 reserved
// vector 106 reserved
// vector 107 reserved
// vector 108 reserved
// vector 109 reserved
// vector 110 reserved
// vector 111 reserved
// vector 112 reserved
// vector 113 reserved

// ICU GROUP12
#pragma interrupt (Excep_ICU_GROUP12(vect=114))
void Excep_ICU_GROUP12(void);

// vector 115 reserved
// vector 116 reserved
// vector 117 reserved
// vector 118 reserved
// vector 119 reserved
// vector 120 reserved
// vector 121 reserved

// SCI12 SCIX0
#pragma interrupt (Excep_SCI12_SCIX0(vect=122))
void Excep_SCI12_SCIX0(void);

// SCI12 SCIX1
#pragma interrupt (Excep_SCI12_SCIX1(vect=123))
void Excep_SCI12_SCIX1(void);

// SCI12 SCIX2
#pragma interrupt (Excep_SCI12_SCIX2(vect=124))
void Excep_SCI12_SCIX2(void);

// SCI12 SCIX3
#pragma interrupt (Excep_SCI12_SCIX3(vect=125))
void Excep_SCI12_SCIX3(void);

// MTU0 TGIA0
#pragma interrupt (Excep_MTU0_TGIA0(vect=126))
void Excep_MTU0_TGIA0(void);

// MTU0 TGIB0
#pragma interrupt (Excep_MTU0_TGIB0(vect=127))
void Excep_MTU0_TGIB0(void);

// MTU0 TGIC0
#pragma interrupt (Excep_MTU0_TGIC0(vect=128))
void Excep_MTU0_TGIC0(void);

// MTU0 TGID0
#pragma interrupt (Excep_MTU0_TGID0(vect=129))
void Excep_MTU0_TGID0(void);

// MTU0 TCIV0
#pragma interrupt (Excep_MTU0_TCIV0(vect=130))
void Excep_MTU0_TCIV0(void);

// MTU0 TGIE0
#pragma interrupt (Excep_MTU0_TGIE0(vect=131))
void Excep_MTU0_TGIE0(void);

// MTU0 TGIF0
#pragma interrupt (Excep_MTU0_TGIF0(vect=132))
void Excep_MTU0_TGIF0(void);

// MTU1 TGIA1
#pragma interrupt (Excep_MTU1_TGIA1(vect=133))
void Excep_MTU1_TGIA1(void);

// MTU1 TGIB1
#pragma interrupt (Excep_MTU1_TGIB1(vect=134))
void Excep_MTU1_TGIB1(void);

// MTU1 TCIV1
#pragma interrupt (Excep_MTU1_TCIV1(vect=135))
void Excep_MTU1_TCIV1(void);

// MTU1 TCIU1
#pragma interrupt (Excep_MTU1_TCIU1(vect=136))
void Excep_MTU1_TCIU1(void);

// MTU2 TGIA2
#pragma interrupt (Excep_MTU2_TGIA2(vect=137))
void Excep_MTU2_TGIA2(void);

// MTU2 TGIB2
#pragma interrupt (Excep_MTU2_TGIB2(vect=138))
void Excep_MTU2_TGIB2(void);

// MTU2 TCIV2
#pragma interrupt (Excep_MTU2_TCIV2(vect=139))
void Excep_MTU2_TCIV2(void);

// MTU2 TCIU2
#pragma interrupt (Excep_MTU2_TCIU2(vect=140))
void Excep_MTU2_TCIU2(void);

// MTU3 TGIA3
#pragma interrupt (Excep_MTU3_TGIA3(vect=141))
void Excep_MTU3_TGIA3(void);

// MTU3 TGIB3
#pragma interrupt (Excep_MTU3_TGIB3(vect=142))
void Excep_MTU3_TGIB3(void);

// MTU3 TGIC3
#pragma interrupt (Excep_MTU3_TGIC3(vect=143))
void Excep_MTU3_TGIC3(void);

// MTU3 TGID3
#pragma interrupt (Excep_MTU3_TGID3(vect=144))
void Excep_MTU3_TGID3(void);

// MTU3 TCIV3
#pragma interrupt (Excep_MTU3_TCIV3(vect=145))
void Excep_MTU3_TCIV3(void);

// MTU4 TGIA4
#pragma interrupt (Excep_MTU4_TGIA4(vect=146))
void Excep_MTU4_TGIA4(void);

// MTU4 TGIB4
#pragma interrupt (Excep_MTU4_TGIB4(vect=147))
void Excep_MTU4_TGIB4(void);

// MTU4 TGIC4
#pragma interrupt (Excep_MTU4_TGIC4(vect=148))
void Excep_MTU4_TGIC4(void);

// MTU4 TGID4
#pragma interrupt (Excep_MTU4_TGID4(vect=149))
void Excep_MTU4_TGID4(void);

// MTU4 TCIV4
#pragma interrupt (Excep_MTU4_TCIV4(vect=150))
void Excep_MTU4_TCIV4(void);

// MTU5 TGIU5
#pragma interrupt (Excep_MTU5_TGIU5(vect=151))
void Excep_MTU5_TGIU5(void);

// MTU5 TGIV5
#pragma interrupt (Excep_MTU5_TGIV5(vect=152))
void Excep_MTU5_TGIV5(void);

// MTU5 TGIW5
#pragma interrupt (Excep_MTU5_TGIW5(vect=153))
void Excep_MTU5_TGIW5(void);

// MTU6 TGIA6
#pragma interrupt (Excep_MTU6_TGIA6(vect=154))
void Excep_MTU6_TGIA6(void);

// MTU6 TGIB6
#pragma interrupt (Excep_MTU6_TGIB6(vect=155))
void Excep_MTU6_TGIB6(void);

// MTU6 TGIC6
#pragma interrupt (Excep_MTU6_TGIC6(vect=156))
void Excep_MTU6_TGIC6(void);

// MTU6 TGID6
#pragma interrupt (Excep_MTU6_TGID6(vect=157))
void Excep_MTU6_TGID6(void);

// MTU6 TCIV6
#pragma interrupt (Excep_MTU6_TCIV6(vect=158))
void Excep_MTU6_TCIV6(void);

// vector 159 reserved
// vector 160 reserved

// MTU7 TGIA7
#pragma interrupt (Excep_MTU7_TGIA7(vect=161))
void Excep_MTU7_TGIA7(void);

// MTU7 TGIB7
#pragma interrupt (Excep_MTU7_TGIB7(vect=162))
void Excep_MTU7_TGIB7(void);

// MTU7 TGIC7
#pragma interrupt (Excep_MTU7_TGIC7(vect=163))
void Excep_MTU7_TGIC7(void);

// MTU7 TGID7
#pragma interrupt (Excep_MTU7_TGID7(vect=164))
void Excep_MTU7_TGID7(void);

// MTU7 TCIV7
#pragma interrupt (Excep_MTU7_TCIV7(vect=165))
void Excep_MTU7_TCIV7(void);

// POE OEI1
#pragma interrupt (Excep_POE_OEI1(vect=166))
void Excep_POE_OEI1(void);

// vector 167 reserved

// POE OEI3
#pragma interrupt (Excep_POE_OEI3(vect=168))
void Excep_POE_OEI3(void);

// POE OEI4
#pragma interrupt (Excep_POE_OEI4(vect=169))
void Excep_POE_OEI4(void);

// vector 170 reserved

// CMP CMP0
#pragma interrupt (Excep_CMP_CMP0(vect=171))
void Excep_CMP_CMP0(void);

// CMP CMP1
#pragma interrupt (Excep_CMP_CMP1(vect=172))
void Excep_CMP_CMP1(void);

// CMP CMP2
#pragma interrupt (Excep_CMP_CMP2(vect=173))
void Excep_CMP_CMP2(void);

// vector 174 reserved
// vector 175 reserved
// vector 176 reserved
// vector 177 reserved
// vector 178 reserved
// vector 179 reserved
// vector 180 reserved
// vector 181 reserved
// vector 182 reserved
// vector 183 reserved
// vector 184 reserved
// vector 185 reserved
// vector 186 reserved
// vector 187 reserved
// vector 188 reserved
// vector 189 reserved
// vector 190 reserved
// vector 191 reserved
// vector 192 reserved
// vector 193 reserved

// RIIC0_EEI0
#pragma interrupt (Excep_RIIC0_EEI0(vect=194))
void Excep_RIIC0_EEI0(void);

// RIIC0 RXI0
#pragma interrupt (Excep_RIIC0_RXI0(vect=195))
void Excep_RIIC0_RXI0(void);

// RIIC0 TXI0
#pragma interrupt (Excep_RIIC0_TXI0(vect=196))
void Excep_RIIC0_TXI0(void);

// RIIC0 TEI0
#pragma interrupt (Excep_RIIC0_TEI0(vect=197))
void Excep_RIIC0_TEI0(void);

// DMAC DMAC0I
#pragma interrupt (Excep_DMAC_DMAC0I(vect=198))
void Excep_DMAC_DMAC0I(void);

// DMAC DMAC1I
#pragma interrupt (Excep_DMAC_DMAC1I(vect=199))
void Excep_DMAC_DMAC1I(void);

// DMAC DMAC2I
#pragma interrupt (Excep_DMAC_DMAC2I(vect=200))
void Excep_DMAC_DMAC2I(void);

// DMAC DMAC3I
#pragma interrupt (Excep_DMAC_DMAC3I(vect=201))
void Excep_DMAC_DMAC3I(void);

// vector 202 reserved
// vector 203 reserved
// vector 204 reserved
// vector 205 reserved
// vector 206 reserved
// vector 207 reserved
// vector 208 reserved
// vector 209 reserved
// vector 210 reserved
// vector 211 reserved
// vector 212 reserved
// vector 213 reserved

// SCI0 RXI0
#pragma interrupt (Excep_SCI0_RXI0(vect=214))
void Excep_SCI0_RXI0(void);

// SCI0 TXI0
#pragma interrupt (Excep_SCI0_TXI0(vect=215))
void Excep_SCI0_TXI0(void);

// SCI0 TEI0
#pragma interrupt (Excep_SCI0_TEI0(vect=216))
void Excep_SCI0_TEI0(void);

// SCI1 RXI1
#pragma interrupt (Excep_SCI1_RXI1(vect=217))
void Excep_SCI1_RXI1(void);

// SCI1 TXI1
#pragma interrupt (Excep_SCI1_TXI1(vect=218))
void Excep_SCI1_TXI1(void);

// SCI1 TEI1
#pragma interrupt (Excep_SCI1_TEI1(vect=219))
void Excep_SCI1_TEI1(void);

// vector 220 reserved
// vector 221 reserved
// vector 222 reserved
// vector 223 reserved
// vector 224 reserved
// vector 225 reserved

// GPT0 GTCIA0
#pragma interrupt (Excep_GPT0_GTCIA0(vect=226))
void Excep_GPT0_GTCIA0(void);

// GPT0 GTCIB0
#pragma interrupt (Excep_GPT0_GTCIB0(vect=227))
void Excep_GPT0_GTCIB0(void);

// GPT0 GTCIC0
#pragma interrupt (Excep_GPT0_GTCIC0(vect=228))
void Excep_GPT0_GTCIC0(void);

// GPT0 GTCIE0
#pragma interrupt (Excep_GPT0_GTCIE0(vect=229))
void Excep_GPT0_GTCIE0(void);

// GPT0 GTCIV0
#pragma interrupt (Excep_GPT0_GTCIV0(vect=230))
void Excep_GPT0_GTCIV0(void);

// GPT0 LOCOI
#pragma interrupt (Excep_GPT0_LOCOI(vect=231))
void Excep_GPT0_LOCOI(void);

// GPT1 GTCIA1
#pragma interrupt (Excep_GPT1_GTCIA1(vect=232))
void Excep_GPT1_GTCIA1(void);

// GPT1 GTCIB1
#pragma interrupt (Excep_GPT1_GTCIB1(vect=233))
void Excep_GPT1_GTCIB1(void);

// GPT1 GTCIC1
#pragma interrupt (Excep_GPT1_GTCIC1(vect=234))
void Excep_GPT1_GTCIC1(void);

// GPT1 GTCIE1
#pragma interrupt (Excep_GPT1_GTCIE1(vect=235))
void Excep_GPT1_GTCIE1(void);

// GPT1 GTCIV1
#pragma interrupt (Excep_GPT1_GTCIV1(vect=236))
void Excep_GPT1_GTCIV1(void);

// vector 237 reserved

// GPT2 GTCIA2
#pragma interrupt (Excep_GPT2_GTCIA2(vect=238))
void Excep_GPT2_GTCIA2(void);

// GPT2 GTCIB2
#pragma interrupt (Excep_GPT2_GTCIB2(vect=239))
void Excep_GPT2_GTCIB2(void);

// GPT2 GTCIC2
#pragma interrupt (Excep_GPT2_GTCIC2(vect=240))
void Excep_GPT2_GTCIC2(void);

// GPT2 GTCIE2
#pragma interrupt (Excep_GPT2_GTCIE2(vect=241))
void Excep_GPT2_GTCIE2(void);

// GPT2 GTCIV2
#pragma interrupt (Excep_GPT2_GTCIV2(vect=242))
void Excep_GPT2_GTCIV2(void);

// vector 243 reserved

// GPT3 GTCIA3
#pragma interrupt (Excep_GPT3_GTCIA3(vect=244))
void Excep_GPT3_GTCIA3(void);

// GPT3 GTCIB3
#pragma interrupt (Excep_GPT3_GTCIB3(vect=245))
void Excep_GPT3_GTCIB3(void);

// GPT3 GTCIC3
#pragma interrupt (Excep_GPT3_GTCIC3(vect=246))
void Excep_GPT3_GTCIC3(void);

// GPT3 GTCIE3
#pragma interrupt (Excep_GPT3_GTCIE3(vect=247))
void Excep_GPT3_GTCIE3(void);

// GPT3 GTCIV3
#pragma interrupt (Excep_GPT3_GTCIV3(vect=248))
void Excep_GPT3_GTCIV3(void);

// vector 249 reserved

// SCI12 RXI12
#pragma interrupt (Excep_SCI12_RXI12(vect=250))
void Excep_SCI12_RXI12(void);

// SCI12 TXI12
#pragma interrupt (Excep_SCI12_TXI12(vect=251))
void Excep_SCI12_TXI12(void);

// SCI12 TEI12
#pragma interrupt (Excep_SCI12_TEI12(vect=252))
void Excep_SCI12_TEI12(void);

// vector 253 reserved
// vector 254 reserved
// vector 255 reserved

//;<<VECTOR DATA START (POWER ON RESET)>>
//;Power On Reset PC
extern void PowerON_Reset_PC(void);                                                                                                                
//;<<VECTOR DATA END (POWER ON RESET)>>

