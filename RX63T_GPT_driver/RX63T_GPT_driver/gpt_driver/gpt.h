/*******************************************************************************
* File Name     : gpt.h
* Version       : 1.00
* Device        : R5F563T6
* Tool-Chain    : RX Family C Compiler 1.2.1.0
* H/W Platform  : RSKRX63T
* Description   : GPT timer driver 
*******************************************************************************/

#ifndef GPT_H
#define GPT_H

#include<stdint.h>
#include<stdbool.h>

typedef enum {SAWWAVE_PWM, SAWWAVE_ONE_SHOT_PULSE, TRIWAVE_PWM1 = 4, TRIWAVE_PWM2, TRIWAVE_PWM3} gpt_mode_t;
typedef enum {PCLKA, PCLKAby2, PCLKAby4, PCLKAby8} gpt_prescalar_t;
typedef enum {RETAIN, LOW, HIGH, TOGGLE} gpt_output_t;

typedef struct _gpt_config{
	gpt_mode_t gpt_mode;
	gpt_prescalar_t gpt_prescalar;
	gpt_output_t gpt_compare_match_output_A;
	gpt_output_t gpt_cycle_end_output_A;
	gpt_output_t gpt_compare_match_output_B;
	gpt_output_t gpt_cycle_end_output_B;
	bool initial_output_A;
	bool initial_output_B;
	uint16_t Overflow_value;      // max value is 2^16 * (1/prescalar_setting_clock)
	uint16_t Compare_value_A;		
	uint16_t Compare_value_B;
	uint16_t Deadtime_Up_value;
	uint16_t Deadtime_Down_value;
	bool deadtime_included;
} gpt_config_t;

void Init_GPT0();
void GPT0_config(gpt_config_t* config);
void Start_GPT0();

#endif
