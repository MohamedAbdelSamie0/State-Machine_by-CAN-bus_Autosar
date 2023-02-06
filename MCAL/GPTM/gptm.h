/*******************************************************************************
 *
 * Module: GPTM
 *
 * File Name: gptm.h
 *
 * Description: Header file to Initilaze gptm.
 *
 * Auhtor: Mohamed Abdel Samie
 ******************************************************************************/

#include "PORT_HW.h"
   
/*                  extern state variable for 1 sec delay                     */

extern bool g_halfSec_state;


/***                        FUNCTION PROTOTYPES                            ****/

/*******************************************************************************
* Name: Timer1A_halfSec_delay
* Reentrancy: reentrant
* Parameters (in):  None
* Return value: None
* Description: TimerA 1 second Initialization function
*******************************************************************************/

void Timer1A_halfSec_delay(void);

/*******************************************************************************
* Name: Timer1A_Disable
* Reentrancy: reentrant
* Parameters (in):  None
* Return value: None
* Description: TimerA 1 Disable function
*******************************************************************************/

void Timer1A_Disable(void);