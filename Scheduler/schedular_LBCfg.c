/*******************************************************************************
 *
 * Module: Schedulaer
 *
 * File Name: schedular_LBCfg.c
 *
 * Description: Source file to configure scheduler.
 *
 * Auhtor: Mohamed Abdel Samie
 ******************************************************************************/

#include "schedular.h"

task_t tasks[NUM_TASKS];

/* Initialize tasks */
void init_tasks(void)
{
    tasks[0].id = 0;
    tasks[0].periodicity = 10;
    tasks[0].ready = true;
    tasks[0].func = task0;
    
    tasks[1].id = 1;
    tasks[1].periodicity = 10;
    tasks[1].ready = true;
    tasks[1].func = task1;
    
    tasks[2].id = 2;
    tasks[2].periodicity = 10;
    tasks[2].ready = true;
    tasks[2].func = task2;
    
    tasks[3].id = 3;
    tasks[3].periodicity = 10;
    tasks[3].ready = true;
    tasks[3].func = task3;
}

/* Task functions */
void task0(void)
{
    /* Task is not ready until some event makes it ready again */
    //tasks[0].ready = false;
    Dio_WriteChannelGroup(&Group_Configuration, STD_HIGH);
    //Dio_WriteChannel(DioConf_RED_CHANNEL_ID_INDEX, STD_HIGH);
}

void task1(void)
{
    /* Task is not ready until some event makes it ready again */
    //tasks[1].ready = false;
    Dio_WriteChannelGroup(&Group_Configuration, STD_LOW);
    Dio_WriteChannel(DioConf_BLUE_CHANNEL_ID_INDEX, STD_HIGH);
}

void task2(void)
{
    /* Task is not ready until some event makes it ready again */
    //tasks[2].ready = false;
    Dio_WriteChannelGroup(&Group_Configuration, STD_LOW);
    Dio_WriteChannel(DioConf_GREEN_CHANNEL_ID_INDEX, STD_HIGH);
}

void task3(void)
{
    /* Task is not ready until some event makes it ready again */
  Dio_WriteChannelGroup(&Group_Configuration, STD_LOW);
  Dio_WriteChannel(DioConf_RED_CHANNEL_ID_INDEX, STD_HIGH);
}