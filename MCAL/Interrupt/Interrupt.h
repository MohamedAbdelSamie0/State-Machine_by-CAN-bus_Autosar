/*******************************************************************************
 *
 * Module: INTERRUPT
 *
 * File Name: interrupt.h
 *
 * Description: Header file to Initilaze Interrupts.
 *
 * Author: Mohamed Abdel Samie
 *
 ******************************************************************************/


#ifndef INTERRUPT_H
#define INTERRUPT_H

#include "PORT.h"
#include "Interrupts_Cfg.h"

/******************** MACROS FOR GLOBLAL INTERRUPTS ***************************/
#define Enable_Interrupts()    __asm("CPSIE I")
#define Disable_Interrupts()   __asm("CPSID I")
#define Enable_Exceptions()    __asm("CPSIE F")
#define Disable_Exceptions()   __asm("CPSID F") 
#define Wait_For_Interrupt()   __asm("WFI")


typedef enum 
{
SYSTICK , GPIO
} Int_ModeType;

typedef enum
{
FALLING , RISING
} Int_EdgesType;


typedef struct
{
Int_ModeType mode;
Int_EdgesType edge;
uint8 port_num;
uint8 pin_num;
}Int_ConfigChannel;

typedef struct
{
  Int_ConfigChannel Int_channels[INTERRUPTS_TO_CONFIG];
}Int_ConfigType;

/*        extern PB structure to be used for initialization          */
extern Int_ConfigType Interrupt_Configuration;

/************************** Function Prototypes *******************************/
void INTERRUPT_Init(Int_ConfigType *config_ptr);
void PORTF_SetCallBack(void(*Ptr2Func)(void));


#endif