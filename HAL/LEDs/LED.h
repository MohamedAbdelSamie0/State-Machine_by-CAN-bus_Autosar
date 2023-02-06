/*******************************************************************************
 *
 * Module: LED
 *
 * File Name: LED.h
 *
 * Description: header file to Initilaze and use the LEDs.
 *
 * Author: Team 3
 *
 ******************************************************************************/
#include "PORT.h"
#include "DIO.h"
#include "Interrupt.h"

/*******************************************************************************
* Service Name: LED_init
* Sync/Async: Synchronous
* Reentrancy: non-reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Setup the LEDs
*******************************************************************************/
void LED_init(void);

/*******************************************************************************
* Service Name: RED_LED
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): level
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to turn of or off the red LED
*******************************************************************************/
void RED_LED(Dio_LevelType level);

/*******************************************************************************
* Service Name: BLUE_LED
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): level
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to turn of or off the blue LED
*******************************************************************************/
void BLUE_LED(Dio_LevelType level);

/*******************************************************************************
* Service Name: GREEN_LED
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): level
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to turn of or off the green LED
*******************************************************************************/
void GREEN_LED(Dio_LevelType level);

/*******************************************************************************
* Service Name: WHITE_LED
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): level
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to turn of or off the white LED
*******************************************************************************/
void WHITE_LED(Dio_LevelType level);