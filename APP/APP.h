#include "DIO.h"
#include "PORT.h"
#include "tm4c123gh6pm.h"
#include "Interrupt.h"
#include "Timer.h"
#include <stdbool.h>

#define debounce        500
#define restart_time    5000

/* Global variable store the Os Time */
static uint16 g_Time_Tick_Count;
extern int state;
extern bool reset;
static uint16 g_reset_time;

/*******************************************************************************
*                                APP prototypes                                *
*******************************************************************************/

void STATE_SWITCHER();