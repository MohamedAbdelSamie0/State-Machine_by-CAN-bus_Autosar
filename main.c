#include "APP.h"
#include "schedular.h"
#include "CAN.h"
#include "gptm.h"
#include "Button.h"
#include "LED.h"

int main()
{  
  Buttons_init();
  LED_init();
  Systick_oneshotConfig(10);
  SysTick_SetCallBack(STATE_SWITCHER);
  initcan();
  Enable_Interrupts();
  
  
  init_tasks();
  /* Start SysTickTimer to generate interrupt every 10ms */
  SysTick_Start();
  
 // scheduler();
  while(1)
  {
    Timer1A_halfSec_delay();
    cantransmit(state);
    Timer1A_Disable();
  }
  /* stuck in while no return */
  //return 0;
}