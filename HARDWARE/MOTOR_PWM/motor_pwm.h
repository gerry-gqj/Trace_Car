#ifndef __MOTOR_PWM__
#define __MOTOR_PWM__
#include "sys.h"




// 电机PWMW输出
#define PWM_OUT GPIOC

// 前双轮 |左 右|
#define FL_PWM GPIO_Pin_6
#define FR_PWM GPIO_Pin_7

// 后双轮 |左 右|
#define RL_PWM GPIO_Pin_8
#define RR_PWM GPIO_Pin_9

// arr; 定时器预装载值
// psc; 定时器预分频系数 实际输出频率=72Mhz/psc
void MOTOR_PWM_Config(u16 arr ,u16 psc);
void MOTOR_FL_PWM(u16 motor_fl_pls);
void MOTOR_FR_PWM(u16 motor_fr_pls);
void MOTOR_RL_PWM(u16 motor_rl_pls);
void MOTOR_RR_PWM(u16 motor_rr_pls);


#endif
