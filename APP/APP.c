#include "APP.h"
#include "CAN.h"

int state;

bool deb_var = 1;

void STATE_SWITCHER()
{
  /* Increment the Os time by OS_BASE_TIME */
  g_Time_Tick_Count   += 10;
  
  /* Increment the reser time by OS_BASE_TIME */
  g_reset_time += 10;
  
  if ((g_reset_time % restart_time) == FALSE && g_reset_time != FALSE)
  {
    state = 0;
  }
}