/*
 * Dio_PBcfg.c
 *
 * Created: 12/23/2022
 */

#include "DIO.h"

/* PB structure used with Dio_Init API */
Dio_ConfigType Dio_Configuration = {
		
                .Channels[DioConf_RED_CHANNEL_ID_INDEX ].Ch_Num =DioConf_RED_CHANNEL_NUM,
		.Channels[DioConf_RED_CHANNEL_ID_INDEX ].Port_Num =DioConf_PORT1_PORT_NUM,
                
		.Channels[DioConf_BLUE_CHANNEL_ID_INDEX ].Ch_Num =DioConf_BLUE_CHANNEL_NUM,
		.Channels[DioConf_BLUE_CHANNEL_ID_INDEX ].Port_Num =DioConf_PORT1_PORT_NUM,
                
                .Channels[DioConf_GREEN_CHANNEL_ID_INDEX ].Ch_Num =DioConf_GREEN_CHANNEL_NUM,
		.Channels[DioConf_GREEN_CHANNEL_ID_INDEX ].Port_Num =DioConf_PORT1_PORT_NUM,
                
		.Channels[DioConf_BUTTON1_CHANNEL_ID_INDEX ].Ch_Num =DioConf_BUTTON1_CHANNEL_NUM,
		.Channels[DioConf_BUTTON1_CHANNEL_ID_INDEX ].Port_Num =DioConf_PORT1_PORT_NUM,
                
		.Channels[DioConf_BUTTON2_CHANNEL_ID_INDEX ].Ch_Num =DioConf_BUTTON2_CHANNEL_NUM,
		.Channels[DioConf_BUTTON2_CHANNEL_ID_INDEX ].Port_Num =DioConf_PORT1_PORT_NUM,
                
		.ports[DioConf_PORT1_PORT_ID_INDEX]=DioConf_PORT1_PORT_NUM ,

		.groups[DioConf_RGB_CHANNEL_GROUP_INDEX ].PortIndex =DioConf_RGB_PORT_NUM,
		.groups[DioConf_RGB_CHANNEL_GROUP_INDEX ].offset =DioConf_RGB_CHANNEL_GROUP_OFFSET,
		.groups[DioConf_RGB_CHANNEL_GROUP_INDEX ].mask =DioConf_RGB_CHANNEL_GROUP_MASK,
};

Dio_ChannelGroupType Group_Configuration = {

  .mask = DioConf_RGB_CHANNEL_GROUP_MASK,
  .offset = DioConf_RGB_CHANNEL_GROUP_OFFSET,
  .PortIndex = DioConf_RGB_PORT_NUM,
};