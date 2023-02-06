/*******************************************************************************
 *
 * Module: GPTM
 *
 * File Name: gptm.c
 *
 * Description: Source file to Initilaze gptm.
 *
 * Auhtor: Mohamed Abdel Samie
 ******************************************************************************/

#include "gptm.h"

   bool g_halfSec_state = 0;
   
/*******************************************************************************
* Name: TIMER1A_Handler
* Reentrancy: reentrant
* Parameters (in):  None
* Return value: None
* Description: TimerA ISR
*******************************************************************************/

void
TIMER1A_Handler(void)
{
  if(TIMER1_MIS & 0x1)
  {
    TIMER1_ICR = 0x1;    /* Timer1A timeout flag bit clears*/
    g_halfSec_state = TRUE;
  }
}

/*******************************************************************************
* Name: Timer1A_halfSec_delay
* Reentrancy: reentrant
* Parameters (in):  None
* Return value: None
* Description: TimerA 500ms second Enable function
*******************************************************************************/

void
Timer1A_halfSec_delay(void)
{
  g_halfSec_state = FALSE;
  RCGCTIMER |= (1<<1);  /*enable clock Timer1 subtimer A in run mode */
  TIMER1_CTL = 0; /* disable timer1 output */
  TIMER1_CFG = 0x4; /*select 16-bit configuration option */
  TIMER1_TAMR = 0x02; /*select periodic down counter mode of timer1 */
  TIMER1_TAPR = 250-1; /* TimerA prescaler value */
  TIMER1_TAILER = 32000-1 ; /* TimerA counter starting count down value  */
  TIMER1_ICR = 0x1;          /* TimerA timeout flag bit clears*/
  TIMER1_IMR |=(1<<0); /*enables TimerA time-out  interrupt mask */
  TIMER1_CTL |= 0x01;        /* Enable TimerA module */
  NVIC_EN0_REG |= (1<<21); /*enable IRQ21 */
  
  while (!g_halfSec_state){};
}

/*******************************************************************************
* Name: Timer1A_Disable
* Reentrancy: reentrant
* Parameters (in):  None
* Return value: None
* Description: TimerA 1 Disable function
*******************************************************************************/

void Timer1A_Disable(void)
{
  TIMER1_CTL = 0; /* disable timer1 output */
}