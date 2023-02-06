/*******************************************************************************
 *
 * Module: SYSTICK TIMER
 *
 * File Name: Timer.h
 *
 * Description: Header file to Initilaze Systick Timer.
 *
 * Author: Mohamed Abdel Samie
 *
 ******************************************************************************/

#ifndef TIMER_H
#define TIMER_H

#include "PORT_HW.h"
#include "BitMath.h"
#include "STD_Types.h"

/********************************************************************************
*                               Function Prototypes                            *
*******************************************************************************/
void Systick_oneshotConfig(uint32 Tick_Time);


/************************************************************************************
* Service Name: SysTick_Start
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): Tick_Time - Time in miliseconds
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Setup the SysTick Timer configuration to count n miliseconds:
*              - Set the Reload value
*              - Enable SysTick Timer with System clock 16Mhz
*              - Enable SysTick Timer Interrupt and set its priority
************************************************************************************/	
void SysTick_Start(void);

/************************************************************************************
* Service Name: SysTick_Stop
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Stop the SysTick Timer.
************************************************************************************/
void SysTick_Stop(void);

/************************************************************************************
* Service Name: SysTick_SetCallBack
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): Ptr2Func - Call Back function address
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Setup the SysTick Timer call back
************************************************************************************/
void SysTick_SetCallBack(void (*Ptr2Func)(void));

#endif