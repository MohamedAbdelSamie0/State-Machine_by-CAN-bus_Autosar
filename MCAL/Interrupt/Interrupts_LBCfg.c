#include "Interrupt.h"

Int_ConfigType Interrupt_Configuration = {
  /*            SW1 config              */
  IntConf_SW1_INTERRUPT_MODE, IntConf_SW1_INTERRUPT_EDGE,
  IntConf_SW1_INTERRUPT_PORT, IntConf_SW1_INTERRUPT_CHANNEL,
  
  /*            SW2 config              */
  IntConf_SW2_INTERRUPT_MODE, IntConf_SW2_INTERRUPT_EDGE,
  IntConf_SW2_INTERRUPT_PORT, IntConf_SW2_INTERRUPT_CHANNEL,
  
  /*        systick (mode and priority only)                */
  IntConf_SYS_INTERRUPT_MODE,
};