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
* File Name     : switch.c
* Version       : 1.00
* Device        : R5F563T6
* Tool-Chain    : RX Family C Compiler 1.2.1.0
* H/W Platform  : RSKRX63T
* Description   : Defines interrupt service routine functions for the switch
*                 interrupts. De-bounces switch and sets a key press flag. 
*******************************************************************************/
/*******************************************************************************
* History       : 05.02.2013  Ver. 1.00 First Release
*******************************************************************************/

/*******************************************************************************
* System Includes
*******************************************************************************/
/* Following header file provides standard integer type definitions. */
#include <stdint.h>

/* Following header file provides string type definitions. */
#include <string.h>

/*******************************************************************************
* User Includes (Project Level Includes)
*******************************************************************************/
/* Defines R5F563T6 port registers */
#include "iodefine.h"

/* Switch handler function definitions */
#include "switch.h"

/* Defines interrupt vector declarations */
#include "vect.h"

/*******************************************************************************
* Global Variables
*******************************************************************************/
/* Switch flag global variable */
volatile uint8_t g_switch_flag = 0x00;

/* Switch standby ready global variable */
volatile bool g_switch_standby_ready = true;

/* Detected switch faults counter variable */
volatile uint16_t g_switch_faults_detected = 0;

/* Switch press callback pointer declaration */
void (*g_switch_press_callback_func)(void) = NULL;

/* Switch release callback pointer declaration */
void (*g_switch_release_callback_func)(void) = NULL;

/*******************************************************************************
* Local Function Prototypes
*******************************************************************************/
/* Start debounce timer function prototype */ 
static void start_debounce_timer(const uint16_t compare_match);

/* Switch debounce timer callback function prototype */
static void switch_debounce_cb(void);

/*******************************************************************************
* Function Name : InitialiseSwitchInterrupts
* Description   : Configures the IRQ pins connected to switches SW1-SW3 to
*                 detect switch presses, and invoke an ISR.
* Argument      : none
* Return value  : none

SW1 == IRQ0, P1.0, P(62)
SW2 == IRQ1, P1.1, P(61)
SW3 == IRQ2, P0.0, P(02)
*******************************************************************************/
void InitialiseSwitchInterrupts (void)
{       
    /* Reset the switch flag */
    g_switch_flag = 0x00;
    
    /* Reset the switch standby ready flag */
    g_switch_standby_ready = 0x1;
    
    /* Enable write to PFSWE bit */
    MPC.PWPR.BYTE = 0x00;

    /* Disable write protection to PFS registers */
    MPC.PWPR.BYTE = 0x40;
    
    /* Set IRQ2 on Port0, Bit 0 as an IRQ input pin */
    MPC.P00PFS.BIT.ISEL = 0x1;
    
    /* Select the pin function for the lower 5 bits, P0.0 Hi-Z */
    MPC.P00PFS.BIT.PSEL = 0x0;
    
    /* Set IRQ1 on Port1, Bit 1 as an IRQ input pin */
    MPC.P11PFS.BIT.ISEL = 0x1;
    
    /* Set IRQ0 on Port1, Bit 0 as an IRQ input pin */
    MPC.P10PFS.BIT.ISEL = 0x1;

    /* Select the pin function for the lower 5 bits, P1.0, P1.1 Hi-Z */
    MPC.P10PFS.BIT.PSEL = 0x0;
    
    /* Enable write protection to PFS registers */
    MPC.PWPR.BYTE = 0x80;
    
    /* Disable digital pin filtering for all IRQ pins */
    ICU.IRQFLTE0.BYTE = 0;
    
    /* Switch 1, IRQ0, P1.0, P(62) */
    /* Clear SW1 interrupt requests */
    IEN(ICU, IRQ0) = 0x0;   
    
    /* Set P1.1(SW1) as an input */
    PORT1.PDR.BIT.B1 = 0;
    
    /* Set detection direction as falling edge */
    ICU.IRQCR[0].BIT.IRQMD = 0x1;   
    
    /* Clear IR flag */
    IR(ICU, IRQ0) = 0x0;                      
    
    /* Set interrupt priority level to 7 */
    IPR(ICU, IRQ0) = SWITCH_IPL;    
    
    /* Enable SW1 interrupt requests */
    IEN(ICU, IRQ0) = 0x1;           
              
    /* Switch 2, IRQ1, P1.1, P(61) */
    /* Clear SW2 interrupt requests */
    IEN(ICU, IRQ1) = 0x0;  
    
    /* Set P1.1 (SW2) as an input */
    PORT1.PDR.BIT.B1 = 0;
    
    /* Set detection direction as falling edge */
    ICU.IRQCR[1].BIT.IRQMD = 0x1;  
    
    /* Clear IR flag */
    IR(ICU, IRQ1) = 0x0;                     
    
    /* Set interrupt priority level to 7 */
    IPR(ICU, IRQ1) = SWITCH_IPL;   
    
    /* Enable SW2 interrupt requests */
    IEN(ICU, IRQ1) = 0x1;                        

    /* Swtich 3, IRQ2, P0.0, P(2) */
    /* Clear SW3 interrupt requests */
    IEN(ICU, IRQ2) = 0x0;  
    
    /* Set P0.0(SW3) as an input */
    PORT0.PDR.BIT.B0 = 0;
    
    /* Set detection direction as falling edge */
    ICU.IRQCR[2].BIT.IRQMD = 0x1;  
    
    /* Clear IR flag */
    IR(ICU, IRQ2) = 0x0;
    
    /* Set interrupt priority level to 7 */
    IPR(ICU, IRQ2) = SWITCH_IPL;   
    
    /* Enable SW3 interrupt requests */
    IEN(ICU, IRQ2) = 0x1;
}
/******************************************************************************
* End of function InitialiseSwitchInterrupts
******************************************************************************/

/******************************************************************************
* Function Name : SetSwitchPressCallback
* Description   : Takes a pointer to a function, and sets it as the callback
*                 function for the switch interrupts. The passed function is
*                 executed every time any switch is pressed down.
* Argument      : pointer to callback function (set to NULL to disable)
* Return value  : none
******************************************************************************/
void SetSwitchPressCallback (void( *const callback)(void))
{
    /* Store the callback function pointer into the global variable */
    g_switch_press_callback_func = callback;
}
/******************************************************************************
* End of function SetSwitchPressCallback
******************************************************************************/

/******************************************************************************
* Function Name : SetSwitchReleaseCallback
* Description   : Takes a pointer to a function, and sets it as the callback
*                 function for the switch interrupts. The passed function is
*                 executed every time any switch is released.
* Argument      : pointer to callback function (set to NULL to disable)
* Return value  : none
******************************************************************************/
void SetSwitchReleaseCallback (void( *const callback)(void))
{
    /* Store the callback function pointer into the global variable */
    g_switch_release_callback_func = callback;
}
/******************************************************************************
* End of function SetSwitchReleaseCallback
******************************************************************************/

/******************************************************************************
* Function Name : ControlSwitchInterrupts
* Description   : Enables or disables the switch IRQ interrupts, based on the
*                 input variable, control.
* Argument      : uint8_t - 0x1  : Enables switch interrupts.
*                           0x0  : Disables switch interrupts.
* Return value  : none
******************************************************************************/
void ControlSwitchInterrupts (const uint8_t control)
{    
    /* Check if control input is 0x1 */
    if (control)
    {
        /* Enable SW1 interrupt requests */
        IEN(ICU, IRQ0) = 0x1;
    
        /* Enable SW2 interrupt requests */
        IEN(ICU, IRQ1) = 0x1;
    
        /* Enable SW3 interrupt requests */
        IEN(ICU, IRQ2) = 0x1;
    }
    else
    {   
        /* Control input is 0x0 */
        /* Disable SW1 interrupts */
        IEN(ICU, IRQ0) = 0x0;
        
        /* Disable SW2 interrupts */
        IEN(ICU, IRQ1) = 0x0;
    
        /* Disable SW3 interrupts */
        IEN(ICU, IRQ2) = 0x0;
    } 
}   
/******************************************************************************
* End of function ControlSwitchInterrupts
******************************************************************************/ 
    
/******************************************************************************
* Function Name : Excep_ICU_IRQ0
* Description   : Switch 1 callback ISR function. The function disables switch
*                 interrupts, then uses the debounce timer to re-enable them
*                 after the debounce period finishes.
* Argument      : none
* Return value  : none
* Extra Notes   : Switch 1 == IRQ0, P1.0, P(62). RSKRX63T-L
******************************************************************************/
#pragma interrupt (Excep_ICU_IRQ0(vect=VECT_ICU_IRQ0))
void Excep_ICU_IRQ0 (void)
{       
    /* Disable switch 1 interrupts */
    IEN(ICU, IRQ0) = 0x0;
    
    /* Set standby ready flag as false */
    g_switch_standby_ready = false;
                        
    /* Check if interrupt was generated by falling edge */
    if (0x1 == ICU.IRQCR[0].BIT.IRQMD)
    {
        /* Start debounce timer */
        start_debounce_timer(DEBOUNCE_SHORT);     
        
        /* Set detection direction as rising edge */
        ICU.IRQCR[0].BIT.IRQMD = 0x2;
                
        /* Set global switch flag to indicate SW1 is held down */
        g_switch_flag |= SWITCHHOLD_1;
    }
    else
    {   
        /* Start debounce timer */
        start_debounce_timer(DEBOUNCE_LONG);      
            
        /* Set detection direction to falling edge */
        ICU.IRQCR[0].BIT.IRQMD = 0x1;
        
        /* Clear SW1 held-down flag bit in switch flag */
        /* type cast required to remove warning for 
            Implicit conversion: unsigned int to unsigned char*/ 
        g_switch_flag &= ((uint8_t)0xF0 | ~SWITCHHOLD_1);
        
        /* Set global switch flag to indicate SW1 press complete */
        g_switch_flag |= SWITCHPRESS_1;
    
        /* Check if switch release callback function is not NULL */
        if (g_switch_release_callback_func)
        {
            /* Execute user callback function */
            g_switch_release_callback_func();
        }
    }
}
/******************************************************************************
* End of function Excep_ICU_IRQ0
******************************************************************************/ 

/******************************************************************************
* Function Name : Excep_ICU_IRQ1
* Description   : Switch 2 callback ISR function. The function disables switch
*                 interrupts, then uses the debounce timer to re-enable them
*                 after the debounce period finishes.
* Argument      : none
* Return value  : none
* Extra Notes   : Switch 2 == IRQ1, P1.1, P(61). RSKRX63T-L
******************************************************************************/
#pragma interrupt (Excep_ICU_IRQ1(vect=VECT_ICU_IRQ1))
void Excep_ICU_IRQ1 (void)
{       
    /* Disable switch 2 interrupts */
    IEN(ICU, IRQ1) = 0x0;
    
    /* Set standby ready flag as false */
    g_switch_standby_ready = false;
        
    /* Check if interrupt triggered from falling edge */
    if (0x1 == ICU.IRQCR[1].BIT.IRQMD)
    {
        /* Start debounce timer */
        start_debounce_timer(DEBOUNCE_SHORT);
        
        /* Set detection direction as rising edge */
        ICU.IRQCR[1].BIT.IRQMD = 0x2;
        
        /* Set global switch flag to indicate SW2 is held down */
        g_switch_flag |= SWITCHHOLD_2;
    }
    else
    {       
        /* Start debounce timer */
        start_debounce_timer(DEBOUNCE_LONG);
        
        /* Set detection direction to falling edge */
        ICU.IRQCR[1].BIT.IRQMD = 0x1;
        
        /* Clear SW2 held-down flag bit in switch flag */
        /* type cast required to remove warning for 
            Implicit conversion: unsigned int to unsigned char*/ 
        g_switch_flag &= ((uint8_t)0xF0 | ~SWITCHHOLD_2);
        
        /* Set global switch flag to indicate SW2 press complete */
        g_switch_flag |= SWITCHPRESS_2;
    
        /* Check if switch release callback function is not NULL */
        if (g_switch_release_callback_func)
        {
            /* Execute user callback function */
            g_switch_release_callback_func();
        }
    }
}
/******************************************************************************
* End of function Excep_ICU_IRQ1
******************************************************************************/ 

/******************************************************************************
* Function Name : Excep_ICU_IRQ2
* Description   : Switch 3 callback ISR function. The function disables switch
*                 interrupts, then uses the debounce timer to re-enable them
*                 after the debounce period finishes.
* Argument      : none
* Return value  : none
* Extra Notes   : Switch 3 == IRQ2, P0.0, P(2). RSKRX63T-L
******************************************************************************/
#pragma interrupt (Excep_ICU_IRQ2(vect=VECT_ICU_IRQ2))
void Excep_ICU_IRQ2 (void)
{
    /* Disable switch 3 interrupts */
    IEN(ICU, IRQ2) = 0x0;  
    
    /* Set standby ready flag as false */
    g_switch_standby_ready = false;
                
    /* Check if detection direction is set to falling edge */
    if (0x1 == ICU.IRQCR[2].BIT.IRQMD)
    {
        /* Start debounce timer */
        start_debounce_timer(DEBOUNCE_SHORT);
        
        /* Set detection direction as rising edge */
        ICU.IRQCR[2].BIT.IRQMD = 0x2;
        
        /* Set global switch flag to indicate SW3 is held down */
        g_switch_flag |= SWITCHHOLD_3;
    }
    else
    {
        /* Start debounce timer */
        start_debounce_timer(DEBOUNCE_LONG);      
        
        /* Set detection direction to falling edge */
        ICU.IRQCR[2].BIT.IRQMD = 0x1;
        
        /* Clear SW3 held-down flag bit in switch flag */
        /* type cast required to remove warning for 
            Implicit conversion: unsigned int to unsigned char*/ 
        g_switch_flag &= ((uint8_t)0xF0 | ~SWITCHHOLD_3);
        
        /* Set global switch flag to indicate SW1 press complete */
        g_switch_flag |= SWITCHPRESS_3;
    
        /* Check if switch release callback function is not NULL */
        if (g_switch_release_callback_func)
        {
            /* Execute user callback function */
            g_switch_release_callback_func();
        }
    }
}
/******************************************************************************
* End of function Excep_ICU_IRQ2
******************************************************************************/ 

/******************************************************************************
* Function Name : switch_debounce_cb
* Description   : Switch debounce timer callback function. Function is executed
*                 by the CMT channel ISR. Function re-enables all switch all
*                 switch interrupts; then verifies a correct switch press was
*                 detected, and calls the user switch press callback function.
* Argument      : none
* Return value  : none
******************************************************************************/
static void switch_debounce_cb (void)
{   
    /* Clear IRQ0 interrupt flag */
    IR(ICU, IRQ0) = 0;
    
    /* Re-enable switch 1 interrupts */
    IEN(ICU, IRQ0) = 0x1;

    /* Clear IRQ1 interrupt flag */
    IR(ICU, IRQ1) = 0;

    /* Re-enable switch 2 interrupts */
    IEN(ICU, IRQ1) = 0x1;

    /* Clear IRQ2 interrupt flag */
    IR(ICU, IRQ2) = 0;

    /* Re-enable switch 3 interrupts */
    IEN(ICU, IRQ2) = 0x1;
    
    /* Check if switch 1 hold flag is set, IRQ0 */ 
    if ((g_switch_flag & 0x0F) & SWITCHHOLD_1)
    {
        /* Check if switch 1 pin level is high (switch press duration
           less than debounce, invalid switch press) */
        if (PORT1.PIDR.BIT.B0)
        {
            /* Reset detection direction to falling edge */
            ICU.IRQCR[0].BIT.IRQMD = 0x1;
            
            /* Clear switch press flag */
            /* type cast required to remove warning for 
                Implicit conversion: unsigned int to unsigned char*/ 
            g_switch_flag &= ((uint8_t)0xF0 | ~SWITCHHOLD_1);
            
            /* Increment detected switch faults counter */
            g_switch_faults_detected++;
        }
        else
        {
            /* Switch 1 pin level is low (valid switch press) */
            /* Check if switch press callback function is not NULL */
            if (g_switch_press_callback_func)
            {
                /* Execute user callback function */
                g_switch_press_callback_func();
            }
        }
    }
    
    /* Check if switch 2 hold flag is set, IRQ1 */    
    if ((g_switch_flag & 0x0F) & SWITCHHOLD_2)
    {
        /* Check if switch 2 pin level is high (switch press duration
           less than debounce, invalid switch press) */
        if (PORT1.PIDR.BIT.B1)
        {
            /* Reset detection direction to falling edge */
            ICU.IRQCR[1].BIT.IRQMD = 0x1;
            
            /* Clear switch press flag */
            /* type cast required to remove warning for 
                Implicit conversion: unsigned int to unsigned char*/ 
            g_switch_flag &= ((uint8_t)0xF0 | ~SWITCHHOLD_2);
            
            /* Increment detected switch faults counter */
            g_switch_faults_detected++;
        }
        else
        {
            /* Switch 2 pin level is low (valid switch press) */
            /* Check if switch press callback function is not NULL */
            if (g_switch_press_callback_func)
            {
                /* Execute user callback function */
                g_switch_press_callback_func();
            }
        }
    }
    
    /* Check if switch 3 hold flag is set, IRQ2 */ 
    if ((g_switch_flag & 0x0F) & SWITCHHOLD_3)
    {
        /* Check if switch 3 pin level is high (switch press duration
           less than debounce, invalid switch press) */
        if (PORT0.PIDR.BIT.B0)
        {
            /* Reset detection direction to falling edge */
            ICU.IRQCR[2].BIT.IRQMD = 0x1;
            
            /* Clear switch press flag */
            /* type cast required to remove warning for 
                Implicit conversion: unsigned int to unsigned char*/ 
            g_switch_flag &= ((uint8_t)0xF0 | ~SWITCHHOLD_3);
            
            /* Increment detected switch faults counter */
            g_switch_faults_detected++;
        }
        else
        {
            /* Switch 3 pin level is low (valid switch press) */
            /* Check if switch press callback function is not NULL */
            if (g_switch_press_callback_func)
            {
                /* Execute user callback function */
                g_switch_press_callback_func();
            }
        }
    }
    
    /* Check if any switches are held down */
    if (0x00 == (g_switch_flag & 0x0F))
    {       
        g_switch_standby_ready = true;
    }       
}
/******************************************************************************
* End of function switch_debounce_cb
******************************************************************************/

/******************************************************************************
* Function Name : start_debounce_timer
* Description   : Function initialises the CMT timer (the first time the
*                 function is called), and starts the CMT timer to perform
*                 generate the switch debounce interrupt.
* Argument      : uint16_t compare_match    : compare match value to trigger
*                                             *interrupt at.
* Return value  : none
******************************************************************************/
static void start_debounce_timer (const uint16_t compare_match)
{
    /* Declare local static variable to track if the CMT timer has been 
        initialised yet */
    static bool timer_initialised = false;
    
    /* Check if the CMT timer is not initialised (first time function has been
       called). */
    if (!timer_initialised)
    {   
        /* Disable register protection */
        SYSTEM.PRCR.WORD = 0xA50B;  
    
        /* Enable the CMT0 module */
        MSTP_CMT0 = 0;
    
        /* Re-enable register protection */
        SYSTEM.PRCR.BIT.PRKEY = 0xA5u;
        SYSTEM.PRCR.WORD &= 0xFF00u; 
    
        /* Set CMT0 clock source as PLCK/512 */
        CMT0.CMCR.BIT.CKS = 0x2;
     
        /* Enable compare match interrupt */
        CMT0.CMCR.BIT.CMIE = 1;
    
        /* Enable CMT0 interrupt request */
        IEN(CMT0, CMI0) = 1;
    
        /* Set interrupt priority to 12 */
        IPR(CMT0, CMI0) = 12u;
        
        /* Set the timer inititalised flag */
        timer_initialised = true;
    }
    
    /* Set compare match to to generate debounce period */
    CMT0.CMCOR = compare_match;
    
    /* Reset count to zero */
    CMT0.CMCNT = 0x0000;
        
    /* Start timer */
    CMT.CMSTR0.BIT.STR0 = 1;
}
/******************************************************************************
* End of function start_debounce_timer
******************************************************************************/

/******************************************************************************
* Function Name : Excep_CMT0_CMI0
* Description   : Interupt service routine for the CMT channel 0 compare
*                 interrupt.
* Argument      : none
* Return value  : none
******************************************************************************/
#pragma interrupt (Excep_CMT0_CMI0(vect=VECT_CMT0_CMI0))
void Excep_CMT0_CMI0 (void)
{
    /* Stop the CMT0 timer running */
    CMT.CMSTR0.BIT.STR0 = 0;
    
    /* Call the switch debounce callback function */
    switch_debounce_cb();
}
/******************************************************************************
* End of function Excep_CMT0_CMI0
******************************************************************************/

