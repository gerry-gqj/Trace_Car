#ifndef __MOTOR_PWM__
#define __MOTOR_PWM__
#include "sys.h"




// ���PWMW���
#define PWM_OUT GPIOC

// ǰ˫�� |�� ��|
#define FL_PWM GPIO_Pin_6
#define FR_PWM GPIO_Pin_7

// ��˫�� |�� ��|
#define RL_PWM GPIO_Pin_8
#define RR_PWM GPIO_Pin_9

// arr; ��ʱ��Ԥװ��ֵ
// psc; ��ʱ��Ԥ��Ƶϵ�� ʵ�����Ƶ��=72Mhz/psc
void MOTOR_PWM_Config(u16 arr ,u16 psc);
void MOTOR_FL_PWM(u16 motor_fl_pls);
void MOTOR_FR_PWM(u16 motor_fr_pls);
void MOTOR_RL_PWM(u16 motor_rl_pls);
void MOTOR_RR_PWM(u16 motor_rr_pls);


#endif
