#ifndef __MOTOR_STATUS__
#define __MOTOR_STATUS__
#include "sys.h"

// ******** 电机控制引脚配置 **********

#define STATUS_OUT GPIOB

#define STATUS_MOTOR_FL_IN1 GPIO_Pin_5
#define STATUS_MOTOR_FL_IN2 GPIO_Pin_6

#define STATUS_MOTOR_FR_IN3 GPIO_Pin_7
#define STATUS_MOTOR_FR_IN4 GPIO_Pin_8


#define STATUS_MOTOR_RL_IN1 GPIO_Pin_9
#define STATUS_MOTOR_RL_IN2 GPIO_Pin_10

#define STATUS_MOTOR_RR_IN3 GPIO_Pin_11
#define STATUS_MOTOR_RR_IN4 GPIO_Pin_12


// ******** 位操作 设置输出电机控制电平 *********
// 前左电机
#define MOTOR_FL_IN1 PBout(5)
#define MOTOR_FL_IN2 PBout(6)
// 前右电机
#define MOTOR_FR_IN3 PBout(7)
#define MOTOR_FR_IN4 PBout(8)
// 后左电机
#define MOTOR_RL_IN1 PBout(9)
#define MOTOR_RL_IN2 PBout(10)
// 后右电机
#define MOTOR_RR_IN3 PBout(11)
#define MOTOR_RR_IN4 PBout(12)


#define GO    0 //定义电机状态 前进
#define BACK  1 //后退
#define STOP  2 //停车

void MOTOR_STATUS_Config(void);
void MOTOR_FL_STATUS(u8 state);
void MOTOR_FR_STATUS(u8 state);
void MOTOR_RL_STATUS(u8 state);
void MOTOR_RR_STATUS(u8 state);
#endif

