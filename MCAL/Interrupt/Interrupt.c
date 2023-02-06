/*******************************************************************************
 *
 * Module: INTERRUPT
 *
 * File Name: interrupt.C
 *
 * Description: source file to Initilaze Interrupts.
 *
 * Author: Mohamed Abdel Samie
 *
 ******************************************************************************/

#include "Interrupt.h"
//#include "tm4c123gh6pm.h"

/* Global pointer to function to be used in CallBacks */
static void (*g_PORTF_Call_Back_Ptr)(void) = NULL_PTR;

static Int_ConfigChannel *Int_ptr = NULL_PTR;

/*******************************************************************************
* Service Name: GPIOF_Handler
* Description: PORTF switches ISR
*******************************************************************************/
void GPIOF_Handler(void)
{
  /* Check if the SysTick_setCallBack is called */
    if(g_PORTF_Call_Back_Ptr != NULL_PTR)
    {
      /* call the function in the scheduler using call-back concept */
      (*g_PORTF_Call_Back_Ptr)();
      /* CLEAR FLAGS */
      if (GPIO_PORTF_MIS_REG & (1 << PORT_PIN4))
      {
        GPIO_PORTF_ICR_REG |= (1 << PORT_PIN4);
      }
      else if (GPIO_PORTF_MIS_REG & (1 << PORT_PIN0))
      {
        GPIO_PORTF_ICR_REG |= (1 << PORT_PIN0);
      }
      
    }
    else
    {
      GPIO_PORTF_ICR_REG |= (1 << PORT_PIN4);
      GPIO_PORTF_ICR_REG |= (1 << PORT_PIN0);
    }
}

/*******************************************************************************
* Service Name: PORTF_SetCallBack
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): Ptr2Func - Call Back function address
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Setup the PORTF Timer call back
*******************************************************************************/
void PORTF_SetCallBack(void(*Ptr2Func)(void))
{
    g_PORTF_Call_Back_Ptr = Ptr2Func;
}

void INTERRUPT_Init(Int_ConfigType *config_ptr)
{
  Int_ptr = config_ptr->Int_channels;
  
  for(uint8 index = 0; index < INTERRUPTS_TO_CONFIG; index++)
    {
    if (Int_ptr[index].mode == SYSTICK)
    {
      /* set systick timer interrupt priority */
       SYSTICK_PRI_R = (SYSTICK_PRI_R & SYSTICK_PRIORITY_MASK)
                      | (IntConf_SYS_INTERRUPT_PRIO << SYSTICK_PRIORITY_BITS_POS);
    }

    else if (Int_ptr[index].mode == GPIO)
    {
      switch (Int_ptr[index].port_num)
      {
        case PORTA_ID:

        ClearBit(GPIO_PORTA_IBE_REG, Int_ptr[index].pin_num);
        SetBit(GPIO_PORTA_ICR_REG, Int_ptr[index].pin_num);
        SetBit(GPIO_PORTA_IM_REG, Int_ptr[index].pin_num);

          if (Int_ptr[index].edge == FALLING)
          {
            ClearBit(GPIO_PORTA_IS_REG, Int_ptr[index].pin_num);
            ClearBit(GPIO_PORTA_IEV_REG, Int_ptr[index].pin_num);
          }

          else if (Int_ptr[index].edge == RISING)
          {
            ClearBit(GPIO_PORTA_IS_REG, Int_ptr[index].pin_num);
            SetBit(GPIO_PORTA_IEV_REG, Int_ptr[index].pin_num);
          }

        break;

        case PORTB_ID:

        ClearBit(GPIO_PORTB_IBE_REG, Int_ptr[index].pin_num);
        SetBit(GPIO_PORTB_ICR_REG, Int_ptr[index].pin_num);
        SetBit(GPIO_PORTB_IM_REG, Int_ptr[index].pin_num);

          if (Int_ptr[index].edge == FALLING)
          {
            ClearBit(GPIO_PORTB_IS_REG, Int_ptr[index].pin_num);
            ClearBit(GPIO_PORTB_IEV_REG, Int_ptr[index].pin_num);
          }

          else if (Int_ptr[index].edge == RISING)
          {
            ClearBit(GPIO_PORTB_IS_REG,Int_ptr[index].pin_num);
            SetBit(GPIO_PORTB_IEV_REG, Int_ptr[index].pin_num);
          }

        break;


        case PORTC_ID:

        ClearBit(GPIO_PORTC_IBE_REG, Int_ptr[index].pin_num);
        SetBit(GPIO_PORTC_ICR_REG, Int_ptr[index].pin_num);
        SetBit(GPIO_PORTC_IM_REG, Int_ptr[index].pin_num);

          if (Int_ptr[index].edge == FALLING)
          {
            ClearBit(GPIO_PORTC_IS_REG, Int_ptr[index].pin_num);
            ClearBit(GPIO_PORTC_IEV_REG, Int_ptr[index].pin_num);
          }

          else if (Int_ptr[index].edge == RISING)
          {
            ClearBit(GPIO_PORTC_IS_REG,Int_ptr[index].pin_num);
            SetBit(GPIO_PORTC_IEV_REG, Int_ptr[index].pin_num);
          }

        break;




        case PORTD_ID:

        ClearBit(GPIO_PORTD_IBE_REG, Int_ptr[index].pin_num);
        SetBit(GPIO_PORTD_ICR_REG, Int_ptr[index].pin_num);
        SetBit(GPIO_PORTD_IM_REG, Int_ptr[index].pin_num);

          if (Int_ptr[index].edge == FALLING)
          {
            ClearBit(GPIO_PORTD_IS_REG, Int_ptr[index].pin_num);
            ClearBit(GPIO_PORTD_IEV_REG, Int_ptr[index].pin_num);
          }

          else if (Int_ptr[index].edge == RISING)
          {
            ClearBit(GPIO_PORTD_IS_REG, Int_ptr[index].pin_num);
            SetBit(GPIO_PORTD_IEV_REG, Int_ptr[index].pin_num);
          }

        break;



        case PORTE_ID:

        ClearBit(GPIO_PORTE_IBE_REG, Int_ptr[index].pin_num);
        SetBit(GPIO_PORTE_ICR_REG, Int_ptr[index].pin_num);
        SetBit(GPIO_PORTE_IM_REG, Int_ptr[index].pin_num);

          if (Int_ptr[index].edge == FALLING)
          {
            ClearBit(GPIO_PORTE_IS_REG, Int_ptr[index].pin_num);
            ClearBit(GPIO_PORTE_IEV_REG, Int_ptr[index].pin_num);
          }

          else if (Int_ptr[index].edge == RISING)
          {
            ClearBit(GPIO_PORTE_IS_REG, Int_ptr[index].pin_num);
            SetBit(GPIO_PORTE_IEV_REG, Int_ptr[index].pin_num);
          }

        break;



        case PORTF_ID:

        /*trigger controlled by IEV */
        ClearBit(GPIO_PORTF_IBE_REG, Int_ptr[index].pin_num);
        
        /*Clear any prior interrupt*/
        SetBit(GPIO_PORTF_ICR_REG, Int_ptr[index].pin_num);
        
        /* unmask interrupt */
        SetBit(GPIO_PORTF_IM_REG, Int_ptr[index].pin_num);

          if (Int_ptr[index].edge == FALLING)
          {
            ClearBit(GPIO_PORTF_IS_REG, Int_ptr[index].pin_num);
            ClearBit(GPIO_PORTF_IEV_REG, Int_ptr[index].pin_num);
          }

          else if (Int_ptr[index].edge == RISING)
          {
            ClearBit(GPIO_PORTF_IS_REG, Int_ptr[index].pin_num);
            SetBit(GPIO_PORTF_IEV_REG, Int_ptr[index].pin_num);
          }

        break;
      }
      
      NVIC_PRI7_REG = (NVIC_PRI7_REG & 0xFF1FFFFF) | (3<<21); 

      NVIC_EN0_REG |= 0x40000000;
      NVIC_PRI7_REG = (NVIC_PRI7_REG & 0xFF1FFFFF) | (2<<21); 

      NVIC_EN0_REG |= 0x40000000;
    }
  }
}