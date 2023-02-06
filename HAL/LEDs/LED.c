/*******************************************************************************
 *
 * Module: LED
 *
 * File Name: LED.h
 *
 * Description: source file to Initilaze the LEDs.
 *
 * Author: Team 3
 *
 ******************************************************************************/
#include "LED.h"

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
void
LED_init(void)
{
  Disable_Interrupts();
  Port_Init(&Port_Configuration);
  Dio_Init(&Dio_Configuration);
}

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
void
RED_LED(Dio_LevelType level)
{
  Dio_WriteChannelGroup(&Group_Configuration, STD_LOW);
  Dio_WriteChannel(DioConf_RED_CHANNEL_ID_INDEX, level);
}

/*******************************************************************************
* Service Name: RED_LED
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): level
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to turn of or off the blue LED
*******************************************************************************/
void
BLUE_LED(Dio_LevelType level)
{
  Dio_WriteChannelGroup(&Group_Configuration, STD_LOW);
  Dio_WriteChannel(DioConf_BLUE_CHANNEL_ID_INDEX, level);
}

/*******************************************************************************
* Service Name: RED_LED
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): level
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to turn of or off the green LED
*******************************************************************************/
void
GREEN_LED(Dio_LevelType level)
{
  Dio_WriteChannelGroup(&Group_Configuration, STD_LOW);
  Dio_WriteChannel(DioConf_GREEN_CHANNEL_ID_INDEX, level);
}

/*******************************************************************************
* Service Name: RED_LED
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): level
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to turn of or off the white LED
*******************************************************************************/
void
WHITE_LED(Dio_LevelType level)
{
  Dio_WriteChannelGroup(&Group_Configuration, level);
}