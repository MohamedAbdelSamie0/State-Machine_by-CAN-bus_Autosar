#include "PORT.h"

static Port_ConfigChannel *port_PortChannels = NULL_PTR;

void Port_Init(Port_ConfigType *ConfigPtr)
{
  /*
  //portf_init
  SYSCTL_RCGCGPIO_R |= 0X20;
  while ((SYSCTL_RCGCGPIO_R & 0x20) ==0x00){};
  GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
  GPIO_PORTF_CR_R = 0x1F;
  GPIO_PORTF_DIR_R = 0x0E;
  GPIO_PORTF_PUR_R = 0x11;
  GPIO_PORTF_DEN_R = 0x1F;
  GPIO_PORTF_DATA_R |= 0x00;
  */
  
  Port_PortType *port_ptr = NULL_PTR;      /* clock register pointer */
  Port_PortType *pll_ptr = NULL_PTR;       /* pull up register pointer */
  Port_PortType *dir_ptr = NULL_PTR;       /* direction register pointer */
  Port_PortType *den_ptr = NULL_PTR;       /* digital enable register pointer */
  Port_PortType *cr_ptr = NULL_PTR;        /* commit resgister pointer */
  Port_PortType *data_ptr = NULL_PTR;      /* data register pointer */
  port_PortChannels = ConfigPtr->port_channels;
  
/* point to system clock register */
  port_ptr = &Port_clk;
  
/* first for loop for enabling the ports clocks only to avoid re-enabling it */
  for (uint8 index = 0; index < PORTS_USED; index++)
  {
    /* switch case to enable clock to required ports and set the pointers */
    switch (port_PortChannels[index].port)
    {
    case PORTA_ID:
      SetBit(*port_ptr, portA_clk);
      break;
      
    case PORTB_ID:
      SetBit(*port_ptr, portB_clk);
      break;
    
    case PORTC_ID:
      SetBit(*port_ptr, portC_clk);
      break;
    
    case PORTD_ID:
      SetBit(*port_ptr, portD_clk);
      break;
    
    case PORTE_ID:
      SetBit(*port_ptr, portE_clk);
      break;
    
    case PORTF_ID:
      /* shifting is too large to do here since portf_clk = 0x20 */
      *port_ptr |= portF_clk;
      break;
    }
  }
  
  for (uint8 i = 0; i < channels_to_config; i++)
  {
    /* switch case to set the pointers to their corresponding registers */
    switch (port_PortChannels[i].port)
    {
    case PORTA_ID:
      pll_ptr = &portA_pll;
      dir_ptr = &portA_dir;
      data_ptr = &PortA;
      den_ptr = &portA_den;
      cr_ptr = &portA_cr;
      break;
    
    case PORTB_ID:
      pll_ptr = &portB_pll;
      dir_ptr = &portB_dir;
      data_ptr = &PortB;
      den_ptr = &portB_den;
      cr_ptr = &portB_cr;
      break;
      
    case PORTC_ID:
      pll_ptr = &portC_pll;
      dir_ptr = &portC_dir;
      data_ptr = &PortC;
      den_ptr = &portC_den;
      cr_ptr = &portC_cr;
      break;
      
    case PORTD_ID:
      pll_ptr = &portD_pll;
      dir_ptr = &portD_dir;
      data_ptr = &PortD;
      den_ptr = &portD_den;
      cr_ptr = &portD_cr;
      break;
      
    case PORTE_ID:
      pll_ptr = &portE_pll;
      dir_ptr = &portE_dir;
      data_ptr = &PortE;
      den_ptr = &portE_den;
        cr_ptr = &portE_cr;
      break;
      
    case PORTF_ID:
      pll_ptr = &portF_pll;
      dir_ptr = &portF_dir;
      data_ptr = &PortF;
      den_ptr = &portF_den;
      cr_ptr = &portF_cr;
      
/* for portf only there's a locked buton unlock here ;) */
      portf_lock = lock_key;
      break;
    }
    
    /* if to determine the mode of the pins */
      if (port_PortChannels[i].Mode == DIO)
      {
        SetBit(*cr_ptr, port_PortChannels[i].pin_num);
        SetBit(*den_ptr, port_PortChannels[i].pin_num);
        
      }
      else
      {
        /* do nothing only DIO is configured here */
      }
    
    /* if to use pull-up resistor or not here*/
      if  (port_PortChannels[i].pin_in_mode == Enable_Pull_up)
      {
        SetBit(*pll_ptr, port_PortChannels[i].pin_num);
      }
      else if (port_PortChannels[i].pin_in_mode == Disable_Pull_up)
      {
        ClearBit(*pll_ptr, port_PortChannels[i].pin_num);
      }
      
      /* if to set direction of pin */
      if (port_PortChannels[i].direction == PORT_PIN_IN)
      {
        ClearBit(*dir_ptr, port_PortChannels[i].pin_num);
      }
      else if (port_PortChannels[i].direction == PORT_PIN_OUT)
      {
        SetBit(*dir_ptr, port_PortChannels[i].pin_num);
      }
      
      /* if to set the initial state of the channel */
      if (port_PortChannels[i].pin_out_mode == initial_Low)
      {
        ClearBit(*data_ptr, port_PortChannels[i].pin_out_mode);
      }
      else if (port_PortChannels[i].pin_out_mode == initial_High)
      {
        SetBit(*data_ptr, port_PortChannels[i].pin_num);
      }
  }
}

#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction)
{
  Port_PortType local_port;
  Port_PinType local_pin;
  Port_PortType *DIR_ptr;
  
  local_port = Pin / PINS_PER_PORT;
  local_pin = Pin % PINS_PER_PORT;
  
  switch (local_port)
  {
    case PORTA_ID:
      DIR_ptr = &portA_dir;
      break;
    case PORTB_ID:
      DIR_ptr = &portB_dir;
      break;
    case PORTC_ID:
      DIR_ptr = &portC_dir;
      break;
    case PORTD_ID:
      DIR_ptr = &portD_dir;
      break;
    case PORTE_ID:
      DIR_ptr = &portE_dir;
      break;
    case PORTF_ID:
      DIR_ptr = &portF_dir;
      break;
  }
  if (PORT_PIN_OUT == Direction)
  {
    SetBit(*DIR_ptr, local_pin);
  }
  else if (PORT_PIN_IN == Direction)
  {
    ClearBit(*DIR_ptr, local_pin);
  }
}
#endif

/*Sets the port pin mode*/
/* and the commit register since there is no function for it */
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode)
{
  Port_PortType local_port;
  Port_PinType local_pin;
  Port_PortType *DEN_ptr;
  Port_PortType *CR_ptr;
  
  local_port = Pin / PINS_PER_PORT;
  local_pin = Pin % PINS_PER_PORT;
  
  switch (local_port)
  {
    case PORTA_ID:
      DEN_ptr = &portA_den;
      CR_ptr = &portA_cr;
      break;
    case PORTB_ID:
      DEN_ptr = &portB_den;
      CR_ptr = &portB_cr;
      break;
    case PORTC_ID:
      DEN_ptr = &portC_den;
      CR_ptr = &portC_cr;
      break;
    case PORTD_ID:
      DEN_ptr = &portD_den;
      CR_ptr = &portD_den;
      break;
    case PORTE_ID:
      DEN_ptr = &portE_den;
      CR_ptr = &portE_cr;
      break;
    case PORTF_ID:
      DEN_ptr = &portF_den;
      CR_ptr = &portF_cr;
      break;
  }
  if (DIO == Mode)
  {
    SetBit(*CR_ptr, local_pin);
    SetBit(*DEN_ptr, local_pin);
  }
  else
  {
    /* do nothing only DIO is configurable here */
  }
}

