/*******************************************************************************
 *
 * Module: DIO
 *
 * File Name: DIO_Cfg.h
 *
 * Description: header file to configure DIO.
 *
 * Auhtor: Mohamed Abdel Samie
 ******************************************************************************/

#ifndef DIO_CFG_H
#define DIO_CFG_H

/* Pre-compile option for presence of Dio_FlipChannel API */
#define DIO_FLIP_CHANNEL_API                (STD_ON)

/* Number of the configured Dio Channels */
#define DIO_CONFIGURED_CHANNELS                         (5U)

/* Number of the configured Dio Ports */
#define DIO_CONFIGURED_PORTS 				(1U)

/* Number of the configured Dio Groups */
#define DIO_CONFIGURED_GROUPS 				(1U)


//Channels
/* Channel Index in the array of structures in Dio_PBcfg.c */
#define DioConf_RED_CHANNEL_ID_INDEX         (uint8)0x00
#define DioConf_BLUE_CHANNEL_ID_INDEX        (uint8)0x01
#define DioConf_GREEN_CHANNEL_ID_INDEX       (uint8)0x02
#define DioConf_BUTTON1_CHANNEL_ID_INDEX     (uint8)0x03
#define DioConf_BUTTON2_CHANNEL_ID_INDEX     (uint8)0x04
/* DIO Configured Channel ID's */
#define DioConf_RED_CHANNEL_NUM         (Dio_ChannelType)1 /* Pin 1 in PORTF */
#define DioConf_BLUE_CHANNEL_NUM        (Dio_ChannelType)2 /* Pin 2 in PORTF */
#define DioConf_GREEN_CHANNEL_NUM       (Dio_ChannelType)3 /* Pin 3 in PORTF */
#define DioConf_BUTTON1_CHANNEL_NUM     (Dio_ChannelType)0 /* Pin 0 in PORTF */
#define DioConf_BUTTON2_CHANNEL_NUM     (Dio_ChannelType)4 /* Pin 4 in PORTF */


//Ports
#define DioConf_PORT1_PORT_ID_INDEX        (uint8)0x00
#define DioConf_PORT1_PORT_NUM             (Dio_PortType)5 /* PORTF */

//Channel Groups
#define DioConf_RGB_CHANNEL_GROUP_INDEX         (uint8)0x00
/* DIO Configured Port channel group Mask */
#define DioConf_RGB_CHANNEL_GROUP_MASK          (uint8)0b111
/* DIO Configured Port channel group offset */
#define DioConf_RGB_CHANNEL_GROUP_OFFSET        (uint8)0x01
#define DioConf_RGB_PORT_NUM                    (Dio_PortType)5 /* PORTF */

#endif