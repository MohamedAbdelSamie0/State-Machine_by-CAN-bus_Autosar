#ifndef PORT_CFG_H
#define PORT_CFG_H

#define channels_to_config      (5U)
#define PORTS_USED              (1U)

/* Pre-compile option for presence of Port_SetPinDirection API*/
#define PORT_SET_PIN_DIRECTION_API                (STD_ON)

#define portConf_LED1_CHANNEL_ID_INDX            0x0
#define portConf_LED1_CHANNEL_CHANNEL_NUMBER     PORT_PIN1
#define portConf_LED1_CHANNEL_PORT_NUMBER        PORTF_ID
#define portConf_LED1_CHANNEL_CHANNEL_DIRECTION  PORT_PIN_OUT
#define portConf_LED1_CHANNEL_OUTPUT_PIN_MODE	 initial_Low
#define portConf_LED1_CHANNEL_INPUT_PIN_MODE     Disable_Pull_up
#define portConf_LED1_CHANNEL_Mode               DIO

#define portConf_LED2_CHANNEL_ID_INDX            0x1
#define portConf_LED2_CHANNEL_CHANNEL_NUMBER     PORT_PIN2
#define portConf_LED2_CHANNEL_PORT_NUMBER        PORTF_ID
#define portConf_LED2_CHANNEL_CHANNEL_DIRECTION  PORT_PIN_OUT
#define portConf_LED2_CHANNEL_OUTPUT_PIN_MODE	 initial_Low
#define portConf_LED2_CHANNEL_INPUT_PIN_MODE     Disable_Pull_up
#define portConf_LED2_CHANNEL_Mode               DIO

#define portConf_LED3_CHANNEL_ID_INDX            0x2
#define portConf_LED3_CHANNEL_CHANNEL_NUMBER     PORT_PIN3
#define portConf_LED3_CHANNEL_PORT_NUMBER        PORTF_ID
#define portConf_LED3_CHANNEL_CHANNEL_DIRECTION  PORT_PIN_OUT
#define portConf_LED3_CHANNEL_OUTPUT_PIN_MODE    initial_Low
#define portConf_LED3_CHANNEL_INPUT_PIN_MODE     Disable_Pull_up
#define portConf_LED3_CHANNEL_Mode               DIO

#define portConf_SW1_CHANNEL_ID_INDX            0x2
#define portConf_SW1_CHANNEL_CHANNEL_NUMBER     PORT_PIN4
#define portConf_SW1_CHANNEL_PORT_NUMBER        PORTF_ID
#define portConf_SW1_CHANNEL_CHANNEL_DIRECTION  PORT_PIN_IN
#define portConf_SW1_CHANNEL_OUTPUT_PIN_MODE	initial_High
#define portConf_SW1_CHANNEL_INPUT_PIN_MODE     Enable_Pull_up
#define portConf_SW1_CHANNEL_Mode               DIO

#define portConf_SW2_CHANNEL_ID_INDX            0x3
#define portConf_SW2_CHANNEL_CHANNEL_NUMBER     PORT_PIN0
#define portConf_SW2_CHANNEL_PORT_NUMBER        PORTF_ID
#define portConf_SW2_CHANNEL_CHANNEL_DIRECTION  PORT_PIN_IN
#define portConf_SW2_CHANNEL_OUTPUT_PIN_MODE	initial_High
#define portConf_SW2_CHANNEL_INPUT_PIN_MODE     Enable_Pull_up
#define portConf_SW2_CHANNEL_Mode               DIO

/* CAN CHANNEL CONFIG */
 /*
#define
#define
#define
#define
#define
#define
*/

#endif