/*
 * DIO_HW.h
 *
 * Created: 12/17/2022
 */

#ifndef DIO_HW_H_
#define DIO_HW_H_

#include "STD_Types.h"

/*******************************************************************************
*                       DEFINES FOR ALL PORTS REGISTERS                        *
*******************************************************************************/

//Ports data registers
//
#define PortA           (*((volatile unsigned long *)0x400043FC))
#define PortB           (*((volatile unsigned long *)0x400053FC))
#define PortC           (*((volatile unsigned long *)0x400063FC))
#define PortD           (*((volatile unsigned long *)0x400073FC))
#define PortE           (*((volatile unsigned long *)0x400243FC))
#define PortF           (*((volatile unsigned long *)0x400253FC))

//ports clock register
//
#define Port_clk        (*((volatile unsigned long *)0x400FE608))

//defines for the bit fields in the SYSCTL_RCGCGPIO register
//
#define portF_clk       0x00000020  // GPIO Port F Run Mode Clock Gating Control
#define portE_clk       0x00000010  // GPIO Port E Run Mode Clock Gating Control
#define portD_clk       0x00000008  // GPIO Port D Run Mode Clock Gating Control
#define portC_clk       0x00000004  // GPIO Port C Run Mode Clock Gating Control
#define portB_clk       0x00000002  // GPIO Port B Run Mode Clock Gating Control
#define portA_clk       0x00000001  // GPIO Port A Run Mode Clock Gating Control

//defines for the ports pull up resistors
//
#define portA_pll       (*((volatile unsigned long *)0x40004510))
#define portB_pll       (*((volatile unsigned long *)0x40005510))
#define portC_pll       (*((volatile unsigned long *)0x40006510))
#define portD_pll       (*((volatile unsigned long *)0x40007510))
#define portE_pll       (*((volatile unsigned long *)0x40024510))
#define portF_pll       (*((volatile unsigned long *)0x40025510))

//special define for the lock register of button in portf only
//
#define portf_lock      (*((volatile unsigned long *)0x40025520))
#define lock_key        0x4C4F434B

//defines for the ports commit register
//
#define portA_cr        (*((volatile unsigned long *)0x40004524))
#define portB_cr        (*((volatile unsigned long *)0x40005524))
#define portC_cr        (*((volatile unsigned long *)0x40006524))
#define portD_cr        (*((volatile unsigned long *)0x40007524))
#define portE_cr        (*((volatile unsigned long *)0x40024524))
#define portF_cr        (*((volatile unsigned long *)0x40025524))

//defines for the ports direction register
//
#define portA_dir       (*((volatile unsigned long *)0x40004400))
#define portB_dir       (*((volatile unsigned long *)0x40005400))
#define portC_dir       (*((volatile unsigned long *)0x40006400))
#define portD_dir       (*((volatile unsigned long *)0x40007400))
#define portE_dir       (*((volatile unsigned long *)0x40024400))
#define portF_dir       (*((volatile unsigned long *)0x40025400))

//defines for the ports digital enable register
//
#define portA_den       (*((volatile unsigned long *)0x4000451C))
#define portB_den       (*((volatile unsigned long *)0x4000551C))
#define portC_den       (*((volatile unsigned long *)0x4000651C))
#define portD_den       (*((volatile unsigned long *)0x4000751C))
#define portE_den       (*((volatile unsigned long *)0x4002451C))
#define portF_den       (*((volatile unsigned long *)0x4002551C))


/*******************************************************************************
*                       defines for the GPIO Interrupts                       *
*******************************************************************************/

/*              NVIC            */
#define NVIC_PRI7_REG             (*((volatile uint32 *)0xE000E41C))
#define NVIC_EN0_REG              (*((volatile uint32 *)0xE000E100))

/*              GPIOA           */
#define GPIO_PORTA_IS_REG         (*((volatile uint32 *)0x40004404))
#define GPIO_PORTA_IBE_REG        (*((volatile uint32 *)0x40004408))
#define GPIO_PORTA_IEV_REG        (*((volatile uint32 *)0x4000440C))
#define GPIO_PORTA_IM_REG         (*((volatile uint32 *)0x40004410))
#define GPIO_PORTA_RIS_REG        (*((volatile uint32 *)0x40004414))
#define GPIO_PORTA_ICR_REG        (*((volatile uint32 *)0x4000441C))

/*              GPIOB           */
#define GPIO_PORTB_IS_REG         (*((volatile uint32 *)0x40005404))
#define GPIO_PORTB_IBE_REG        (*((volatile uint32 *)0x40005408))
#define GPIO_PORTB_IEV_REG        (*((volatile uint32 *)0x4000540C))
#define GPIO_PORTB_IM_REG         (*((volatile uint32 *)0x40005410))
#define GPIO_PORTB_RIS_REG        (*((volatile uint32 *)0x40005414))
#define GPIO_PORTB_ICR_REG        (*((volatile uint32 *)0x4000541C))

/*              GPIOC           */
#define GPIO_PORTC_IS_REG         (*((volatile uint32 *)0x40006404))
#define GPIO_PORTC_IBE_REG        (*((volatile uint32 *)0x40006408))
#define GPIO_PORTC_IEV_REG        (*((volatile uint32 *)0x4000640C))
#define GPIO_PORTC_IM_REG         (*((volatile uint32 *)0x40006410))
#define GPIO_PORTC_RIS_REG        (*((volatile uint32 *)0x40006414))
#define GPIO_PORTC_ICR_REG        (*((volatile uint32 *)0x4000641C))

/*              GPIOD           */
#define GPIO_PORTD_IS_REG         (*((volatile uint32 *)0x40007404))
#define GPIO_PORTD_IBE_REG        (*((volatile uint32 *)0x40007408))
#define GPIO_PORTD_IEV_REG        (*((volatile uint32 *)0x4000740C))
#define GPIO_PORTD_IM_REG         (*((volatile uint32 *)0x40007410))
#define GPIO_PORTD_RIS_REG        (*((volatile uint32 *)0x40007414))
#define GPIO_PORTD_ICR_REG        (*((volatile uint32 *)0x4000741C))

/*              GPIOE           */
#define GPIO_PORTE_IS_REG         (*((volatile uint32 *)0x40024404))
#define GPIO_PORTE_IBE_REG        (*((volatile uint32 *)0x40024408))
#define GPIO_PORTE_IEV_REG        (*((volatile uint32 *)0x4002440C))
#define GPIO_PORTE_IM_REG         (*((volatile uint32 *)0x40024410))
#define GPIO_PORTE_RIS_REG        (*((volatile uint32 *)0x40024414))
#define GPIO_PORTE_ICR_REG        (*((volatile uint32 *)0x4002441C))

/*              GPIOF           */
#define GPIO_PORTF_IS_REG         (*((volatile uint32 *)0x40025404))
#define GPIO_PORTF_IBE_REG        (*((volatile uint32 *)0x40025408))
#define GPIO_PORTF_IEV_REG        (*((volatile uint32 *)0x4002540C))
#define GPIO_PORTF_IM_REG         (*((volatile uint32 *)0x40025410))
#define GPIO_PORTF_RIS_REG        (*((volatile uint32 *)0x40025414))
#define GPIO_PORTF_ICR_REG        (*((volatile uint32 *)0x4002541C))
#define GPIO_PORTF_MIS_REG        (*((volatile uint32 *)0x40025418))


/*******************************************************************************
*                       defines for the SYSTICK Interrupts                       *
*******************************************************************************/
#define SYSTICK_PRI_R           (*((volatile uint32 *)0xE000ED20))
#define SYSTICK_CTRL_REG        (*((volatile unsigned long *)0xE000E010))
#define SYSTICK_RELOAD_REG      (*((volatile unsigned long *)0xE000E014))
#define SYSTICK_CURRENT_REG     (*((volatile unsigned long *)0xE000E018))

/**     defines for the pri register bit fields         **/
#define SYSTICK_PRIORITY_MASK  0x1FFFFFFF
#define SYSTICK_PRIORITY_BITS_POS   29

/*******************************************************************************
*                       defines for the CAN controller                         *
*******************************************************************************/
//run mode clock ctrl(legacy register for alternative functions of channels)
//
#define mode_register   (*((volatile unsigned long *)0x400FE100))

//alternative function select register & PCTL(used in conjunction with AFSEL
//
#define PORTE_AFSEL     (*((volatile unsigned long *)0x4005C420))
#define PORTE_PCTL      (*((volatile unsigned long *)0x4005C52C))

//bit fields for CAN0.
//
#define CAN0_RCGC       0x01000000  // CAN0 Clock Gating Control
#define CAN0_rx_tx      0x30        //use in AFSEL register
#define CAN0_PCTL_MUX   0x110000    //use in PCTL register

/*******************************************************************************
*                       defines for the TIMER module                           *
*******************************************************************************/

#define RCGCTIMER       (*((volatile unsigned long *)0x400FE604))
#define TIMER1_CTL      (*((volatile unsigned long *)0x4003100C))
#define TIMER1_CFG      (*((volatile unsigned long *)0x40031000))
#define TIMER1_TAMR     (*((volatile unsigned long *)0x40031004))
#define TIMER1_TAPR     (*((volatile unsigned long *)0x40031038))
#define TIMER1_TAILER   (*((volatile unsigned long *)0x40031028))
#define TIMER1_ICR      (*((volatile unsigned long *)0x40031024))
#define TIMER1_IMR      (*((volatile unsigned long *)0x40031018))
#define TIMER1_MIS      (*((volatile unsigned long *)0x40031020))

/******************************************************************************/

#endif
/* DIO_HW_H_ */