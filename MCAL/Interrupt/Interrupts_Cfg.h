#ifndef INTERRUPTS_CFG_H
#define INTERRUPTS_CFG_H

#define INTERRUPTS_TO_CONFIG    3
#define IntConf_SYS_INTERRUPT_PRIO              2


#define IntConf_BUTTON1_ID_INDEX                (uint8)0x00
#define IntConf_BUTTON2_ID_INDEX                (uint8)0x01
#define IntConf_SYSTICK_ID_INDEX                (uint8)0x02

#define IntConf_SYS_INTERRUPT_MODE              SYSTICK

#define IntConf_SW1_INTERRUPT_MODE              GPIO
#define IntConf_SW1_INTERRUPT_EDGE              FALLING
#define IntConf_SW1_INTERRUPT_PORT              PORTF_ID
#define IntConf_SW1_INTERRUPT_CHANNEL           PORT_PIN4

#define IntConf_SW2_INTERRUPT_MODE              GPIO
#define IntConf_SW2_INTERRUPT_EDGE              FALLING
#define IntConf_SW2_INTERRUPT_PORT              PORTF_ID
#define IntConf_SW2_INTERRUPT_CHANNEL           PORT_PIN0

#endif