/*******************************************************************************
 *
 * Module: Buttons
 *
 * File Name: Buttons.h
 *
 * Description: header file to Initilaze the buttons.
 *
 * Author: Team 3
 *
 ******************************************************************************/

#include "PORT.h"
#include "DIO.h"
#include "Interrupt.h"

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
void Buttons_init(void);