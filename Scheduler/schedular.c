/*******************************************************************************
 *
 * Module: Scheduler
 *
 * File Name: schedular.c
 *
 * Description: Source file to Initilaze scheduler.
 *
 * Auhtor: Mohamed Abdel Samie
 ******************************************************************************/

#include "schedular.h"
#include "CAN.h"

/*******************************************************************************
* Name: scheduler
* Reentrancy: reentrant
* Parameters (in):  None
* Return value: None
* Description: run the readdy configered tasks using states received
from the can bus
*******************************************************************************/
void scheduler(void)
{
    int i;
    while (true)
    {
      for ( i = 0; i < NUM_TASKS; i++)
      {
        canrecieve();
        
        if (tasks[i].ready && receive == tasks[i].id)
        {
          tasks[i].func();
        }
      }
    }
}