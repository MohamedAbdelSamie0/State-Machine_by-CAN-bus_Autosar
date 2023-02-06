/*******************************************************************************
 *
 * Module: PORT
 *
 * File Name: PORT.h
 *
 * Description: header file to Initilaze DIO.
 *
 * Auhtor: Mohamed Abdel Samie
 ******************************************************************************/

#ifndef PORT_H_
#define PORT_H_

#include "PORT_HW.h"
#include "BitMath.h"
#include "PORT_Cfg.h"


/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/
//[SWS_Port_00229]
typedef uint8 Port_PinType;

typedef uint32 volatile Port_PortType;

//[SWS_Port_00231]
//[SWS_Port_00124]
typedef uint8 Port_PinModeType;

//[SWS_Port_00230]
//[SWS_Port_00220]
typedef enum
{
  PORT_PIN_IN,
  PORT_PIN_OUT
}Port_PinDirectionType;

typedef enum
{
  Disable_Pull_up,
  Enable_Pull_up
}Port_InputModeType;

typedef enum
{
  initial_Low,
  initial_High
}Port_OutputModeType;

/* enum for channels alternative modes */
typedef enum
{
  DIO,
  CAN
}Port_ChannelModeType;

//[SWS_Port_00228]
typedef struct
{
  Port_PortType port;
  Port_PinType pin_num;
  Port_PinDirectionType direction;
  Port_InputModeType pin_in_mode;
  Port_OutputModeType pin_out_mode;
  Port_ChannelModeType Mode;
}Port_ConfigChannel;

/* external data structure for initialization of this module. */
typedef struct{
  Port_ConfigChannel port_channels[channels_to_config];
}Port_ConfigType;

/*              PIN and port defines             */
#define PORTA_ID				(0U)
#define PORTB_ID				(1U)
#define PORTC_ID				(2U)
#define PORTD_ID				(3U)
#define PORTE_ID				(4U)
#define PORTF_ID				(5U)

#define PORT_PIN0 			        (Port_PinType)(0U)
#define PORT_PIN1 				(Port_PinType)(1U)
#define PORT_PIN2 				(Port_PinType)(2U)
#define PORT_PIN3 				(Port_PinType)(3U)
#define PORT_PIN4 				(Port_PinType)(4U)
#define PORT_PIN5 				(Port_PinType)(5U)
#define PORT_PIN6 				(Port_PinType)(6U)
#define PORT_PIN7 				(Port_PinType)(7U)

#define PINS_PER_PORT				(8U)
#define NUMBER_OF_PORTS				(6U)
#define PINS_NUM				(48U)

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/* Initializes the Port Driver module */
void Port_Init(Port_ConfigType *ConfigPtr);

/* Sets the port pin direction */
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction);
#endif

/* Refreshes port direction */
void Port_RefreshPortDirection(void);

/*Sets the port pin mode*/
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode);

/* Extern PB structures to be used by Port and other modules */
extern Port_ConfigType Port_Configuration;

typedef enum{
        /* portA */
	PIN_0=0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7,
        /* portB */
	PIN_8,
	PIN_9,
	PIN_10,
	PIN_11,
	PIN_12,
	PIN_13,
	PIN_14,
	PIN_15,
        /* portC */
	PIN_16,
	PIN_17,
	PIN_18,
	PIN_19,
	PIN_20,
	PIN_21,
	PIN_22,
	PIN_23,
        /* portD */
	PIN_24,
	PIN_25,
	PIN_26,
	PIN_27,
	PIN_28,
	PIN_29,
	PIN_30,
	PIN_31,
        /* portE */
	PIN_32,
	PIN_33,
	PIN_34,
	PIN_35,
	PIN_36,
        PIN_37,
        PIN_38,
        PIN_39,
        /* portF */
	PIN_40,
	PIN_41,
	PIN_42,
	PIN_43,
	PIN_44,
        PIN_45,
        PIN_46,
        PIN_47
}PINS;

#endif
/* PORT_H_ */