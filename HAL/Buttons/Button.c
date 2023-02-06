/*******************************************************************************
 *
 * Module: Buttons
 *
 * File Name: Buttons.h
 *
 * Description: source file to Initilaze the buttons.
 *
 * Author: Team 3
 *
 ******************************************************************************/
#include "Button.h"

/*******************************************************************************
* Service Name: Buttons_init
* Sync/Async: Synchronous
* Reentrancy: non-reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Setup the Buttons
*******************************************************************************/
void
Buttons_init(void)
{
  Disable_Interrupts();
  Port_Init(&Port_Configuration);
  Dio_Init(&Dio_Configuration);
  INTERRUPT_Init(&Interrupt_Configuration);
}