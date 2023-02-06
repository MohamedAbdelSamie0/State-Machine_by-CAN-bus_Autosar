/*******************************************************************************
 *
 * Module: schedular
 *
 * File Name: schedular_Cfg.h
 *
 * Description: Header file to configure the scheduler.
 *
 * Author: Mohamed Abdel Samie
 *
 ******************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include "PORT.h"
#include "DIO.h"

#define NUM_TASKS 4

/* Task control block (TCB) structure */
typedef struct task
{
    int id;
    int periodicity;
    bool ready;
    void (*func)(void);
} task_t;

/* Array of tasks */
extern task_t tasks[NUM_TASKS];

void init_tasks(void);

void task0(void);
void task1(void);
void task2(void);
void task3(void);
