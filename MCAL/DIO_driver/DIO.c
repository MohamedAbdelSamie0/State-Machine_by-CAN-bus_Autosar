/*******************************************************************************
 *
 * Module: DIO driver
 *
 * File Name: DIO.c
 *
 * Description: Source file to enable and configure the DIO
 *
 * Author: Mohamed Abdel Samie
 *
 ******************************************************************************/

#include "DIO.h"

static Dio_ConfigChannel *Dio_PortChannels = NULL_PTR;
static Dio_PortType *Dio_Ports = NULL_PTR;
static Dio_ChannelGroupType *Dio_ChannelGroups  = NULL_PTR;

void Dio_Init(Dio_ConfigType * ConfigPtr)
{
  /* address of the first Channels structure --> Channels[0] */
  Dio_PortChannels = ConfigPtr->Channels;
  Dio_Ports = ConfigPtr->ports;
  Dio_ChannelGroups = ConfigPtr->groups;
}

void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    Dio_PortLevelType * Port_Ptr = NULL_PTR;
    
	switch(Dio_PortChannels[ChannelId].Port_Num)
	{
		// PortA
		case 0:
                  Port_Ptr = &PortA;
                  break;
		
		// PortB
		case 1:
                  Port_Ptr = &PortB;
                  break;
		
		// PortC
		case 2:
                  Port_Ptr = &PortC;
                  break;
		
		// Port D
		case 3:
                  Port_Ptr = &PortD;
                  break;
                  
		// Port E
		case 4:
                  Port_Ptr = &PortE;
                  break;
		
                // Port F
		case 5:
                  Port_Ptr = &PortF;
                  break;
	}
        if(Level == STD_HIGH)
		{
			/* Write Logic High */
			SetBit(*Port_Ptr,Dio_PortChannels[ChannelId].Ch_Num);
		}
		else if(Level == STD_LOW)
		{
			/* Write Logic Low */
			ClearBit(*Port_Ptr,Dio_PortChannels[ChannelId].Ch_Num);
		}
}

void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{  
  Dio_PortLevelType * Port_Ptr = NULL_PTR;
  
        switch (Dio_Ports[PortId])
		{
		case 0:
                  Port_Ptr = &PortA;
                  break;
		case 1:
		  Port_Ptr = &PortB;
                  break;
		case 2:
		  Port_Ptr = &PortC;
                  break;
		case 3:
		  Port_Ptr = &PortD;
                  break;
                case 4:
                  Port_Ptr = &PortE;
                  break;
                case 5:
                  Port_Ptr = &PortF;
                  break;
                }
        *Port_Ptr = Level;
}


Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId){

  Dio_PortLevelType * PIN_Ptr = NULL_PTR;
	Dio_PortLevelType PortLevel ;
  
  switch (Dio_Ports[PortId])
  {
    	case 0:
          PIN_Ptr = &PortA;
		break;
	case 1:
          PIN_Ptr = &PortB;
		break;
	case 2:
          PIN_Ptr = &PortC;
		break;
	case 3:
          PIN_Ptr = &PortD;
		break;
        case 4:
          PIN_Ptr = &PortE;
		break;
	case 5:
          PIN_Ptr = &PortF;
		break;
  }
    PortLevel = *PIN_Ptr;
  return PortLevel;
}

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    Dio_PortLevelType * PIN_Ptr = NULL_PTR;
    Dio_LevelType ChannelLevel ;
    
	switch(Dio_PortChannels[ChannelId].Port_Num)
	{
	case 0:
          PIN_Ptr = &PortA;
          //return data;
          break;
	case 1:
          PIN_Ptr = &PortB;
          //return data;
          break;
        case 2:
          PIN_Ptr = &PortC;
          //return data;
          break;
	case 3:
          PIN_Ptr = &PortD;
          //return data;
          break;
	case 4:
          PIN_Ptr = &PortE;
          //return data;
          break;
	case 5:
          PIN_Ptr = &PortF;
          //return data;
          break;
        default:
          break;
	}
        
    ChannelLevel = GetBit(*PIN_Ptr,Dio_PortChannels[ChannelId].Ch_Num) ;
	return ChannelLevel ;
}

#if (DIO_FLIP_CHANNEL_API == STD_ON)
Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
  Dio_PortLevelType * PIN_Ptr = NULL_PTR;
  Dio_LevelType ChannelLevel = STD_LOW;
  
	switch(Dio_PortChannels[ChannelId].Port_Num)
	{
	// PORTA
	case 0:
          PIN_Ptr = &PortA;
          break;
	
	// PORTB
	case 1:
          PIN_Ptr = &PortB;
          break;
	
	// PORTC
	case 2:
          PIN_Ptr = &PortC;
          break;
	
	// PORTD
	case 3:
          PIN_Ptr = &PortD;
          break;
	case 4:
          PIN_Ptr = &PortE;
          break;
	case 5:
          PIN_Ptr = &PortF;
          break;
	}
        if(BIT_IS_SET(*PIN_Ptr, Dio_PortChannels[ChannelId].Ch_Num))
        {
          ClearBit(*PIN_Ptr, Dio_PortChannels[ChannelId].Ch_Num);
          ChannelLevel = STD_LOW;
        }
        else if(BIT_IS_CLEAR(*PIN_Ptr, Dio_PortChannels[ChannelId].Ch_Num))
        {
          SetBit(*PIN_Ptr, Dio_PortChannels[ChannelId].Ch_Num);
          ChannelLevel = STD_HIGH;
        }
  return ChannelLevel;
}
#endif

Dio_PortLevelType Dio_ReadChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr){

  Dio_PortLevelType * PIN_Ptr = NULL_PTR;
  Dio_PortLevelType groupLevel ;
                
    switch (ChannelGroupIdPtr->PortIndex) {
		case 0:
                  PIN_Ptr = &PortA;
                  break;
		case 1:
                  PIN_Ptr = &PortB;
                  break;
		case 2:
                  PIN_Ptr = &PortC;
                  break;
		case 3:
                  PIN_Ptr = &PortD;
                  break;
                case 4:
                  PIN_Ptr = &PortE;
                  break;
                case 5:
                  PIN_Ptr = &PortF;
                  break;
		}
    groupLevel = ((*PIN_Ptr)&(ChannelGroupIdPtr->mask))
      >>ChannelGroupIdPtr->offset;
    
    return groupLevel;

}

void Dio_WriteChannelGroup(const Dio_ChannelGroupType* ChannelGroupIdPtr,
                           Dio_PortLevelType Level){

  Dio_PortLevelType *Port_Ptr = NULL_PTR;
    switch (ChannelGroupIdPtr->PortIndex)
    {
		case 0:
                  Port_Ptr = &PortA;
                  break;
		case 1:
                  Port_Ptr = &PortB;
                  break;
		case 2:
                  Port_Ptr = &PortC;
                  break;
		case 3:
                  Port_Ptr = &PortD;
                  break;
                case 4:
                  Port_Ptr = &PortE;
                  break;
                case 5:
                  Port_Ptr = &PortF;
                  break;
		}
    
    if (Level == STD_HIGH)
    {
      *Port_Ptr = (ChannelGroupIdPtr->mask) << (ChannelGroupIdPtr->offset);
    }else if (Level == STD_LOW)
    {
      *Port_Ptr = ~(ChannelGroupIdPtr->mask) << (ChannelGroupIdPtr->offset);
    }
}