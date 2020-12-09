/*******************************************************************************
* File Name     : gpt.c
* Version       : 1.00
* Device        : R5F563T6
* Tool-Chain    : RX Family C Compiler 1.2.1.0
* H/W Platform  : RSKRX63T
* Description   : GPT timer driver 
*******************************************************************************/

#include "gpt.h" 
#include "iodefine.h"

void Init_GPT0()
{
   SYSTEM.PRCR.WORD = 0xA50B; 	// enable register writting		
   SYSTEM.MSTPCRA.BIT.MSTPA7 = 0x00;    // Initialize GPT module
   GPT.GTSTR.BIT.CST0 = 0; // Stop count
   GPT0.GTCNT = 0; // Set count to zero
   
   MPC.PWPR.BIT.B0WI = 0; // Enables writes to PFSWE bit.
   MPC.PWPR.BIT.PFSWE = 1; // Sets PFSWE bit to 1 enable writes to PmnPFS register. 
   MPC.P71PFS.BIT.PSEL = 0x06; // Use GTIOC0A function for P71
   MPC.P74PFS.BIT.PSEL = 0x06; // Use GTIOC0B function for P74
   MPC.PWPR.BIT.PFSWE = 0; // Sets PFSWE bit to 1 disable writes to PmnPFS register.
   MPC.PWPR.BIT.B0WI = 1; // Disables writes to PFSWE bit. 

   PORT7.PMR.BIT.B1 = 1; // P71 I/O port for peripheral function 
   PORT7.PMR.BIT.B4 = 1; // P74 I/O port for peripheral function
   
   GPT0.GTONCR.BIT.OAE = 1; // Pin output
   GPT0.GTONCR.BIT.OBE = 1; // Pin output	
}


void GPT0_config(gpt_config_t* config)
{
	GPT0.GTCR.BIT.MD = config->gpt_mode; // Set GPT mode. Please refer to hardware manual for more information
	GPT0.GTCR.BIT.TPCS = config->gpt_prescalar; // Set prescalar mode
	
	if(config->initial_output_A) 
	GPT0.GTIOR.BIT.GTIOA = (1 << 4) | (config->gpt_cycle_end_output_A << 2) | config->gpt_compare_match_output_A;
	else
	GPT0.GTIOR.BIT.GTIOA = (config->gpt_cycle_end_output_A << 2) | config->gpt_compare_match_output_A;
	
	if(config->initial_output_B) 
	GPT0.GTIOR.BIT.GTIOB = (1 << 4) | (config->gpt_cycle_end_output_B << 2) | config->gpt_compare_match_output_B;
	else
	GPT0.GTIOR.BIT.GTIOB = (config->gpt_cycle_end_output_B << 2) | config->gpt_compare_match_output_B;
		
	if(config->deadtime_included) 
	{
	GPT0.GTDTCR.BIT.TDE = 1;
	GPT0.GTDVU = config->Deadtime_Up_value;
	GPT0.GTDVD = config->Deadtime_Down_value;
	}
	else
	{
	GPT0.GTDTCR.BIT.TDE = 0;
	GPT0.GTCCRB = config->Compare_value_B; //
	}
	
	GPT0.GTPR = config->Overflow_value;
	GPT0.GTCCRA = config->Compare_value_A; // 
	
}

void Start_GPT0()
{
	GPT.GTSTR.BIT.CST0 = 1; // Start count
}