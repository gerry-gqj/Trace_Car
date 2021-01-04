#include "motor_pwm.h"
#include "stm32f10x.h"

// arr; 定时器预装载值
// psc; 定时器预分频系数 实际输出频率=72Mhz/psc
void MOTOR_PWM_Config(u16 arr,u16 psc){

//**********************结构体配置******************************************	
	//IO口配置
	GPIO_InitTypeDef GPIO_InitStructure;
	//定时器基础设置
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	//定时器比较输出配置
	TIM_OCInitTypeDef TIM_OCInitStructure;
	
//***********************时钟使能*******************************************	
	
	//IO口外设时钟使能
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE); 
	//定时器TIM2/TIM3时钟使能
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8,ENABLE);

//***********************IO口配置*******************************************	
		
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //复用功能推挽输出
	GPIO_InitStructure.GPIO_Pin = FL_PWM|FR_PWM|RL_PWM|RR_PWM;  //输出引脚
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PWM_OUT,&GPIO_InitStructure);
	
//***********************定时器配置*****************************************	
	
	//********   定时器基础配置    *********
	TIM_TimeBaseInitStructure.TIM_ClockDivision = 0; //设置时钟分割，滤波除颤
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up; //向上计数
	TIM_TimeBaseInitStructure.TIM_Period = arr; //预装载值,用来设置定时器计数周期
	TIM_TimeBaseInitStructure.TIM_Prescaler = psc; //预分频系数
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM8,&TIM_TimeBaseInitStructure);
	
	
	//*********    TIM_CH1    **********
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性高
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //PWM模式
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //允许输出
	TIM_OCInitStructure.TIM_Pulse = 0; //占空比
	TIM_OC1Init(TIM8,&TIM_OCInitStructure);
	
	//*********    TIM_CH2    **********
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性高
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //PWM模式
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //允许输出
	TIM_OCInitStructure.TIM_Pulse = 0; //占空比
	TIM_OC2Init(TIM8,&TIM_OCInitStructure);
	
	
	//*********    TIM_CH3    **********
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性高
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //PWM模式
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //允许输出
	TIM_OCInitStructure.TIM_Pulse = 0; //占空比
	TIM_OC3Init(TIM8,&TIM_OCInitStructure);
	
	
	//*********    TIM_CH4    **********
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性高
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //PWM模式
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //允许输出
	TIM_OCInitStructure.TIM_Pulse = 0; //占空比
	TIM_OC4Init(TIM8,&TIM_OCInitStructure);
	
	//*********    MOE 主输出使能    ********
	TIM_CtrlPWMOutputs(TIM8,ENABLE);
	
	//*********    TIM8_CH1/2/3/4预装载使能    ********
	TIM_OC1PreloadConfig(TIM8,ENABLE);
	TIM_OC2PreloadConfig(TIM8,ENABLE);
	TIM_OC3PreloadConfig(TIM8,ENABLE);
	TIM_OC4PreloadConfig(TIM8,ENABLE);
	
	//*********   自动重装寄存器使能   ********
	TIM_ARRPreloadConfig(TIM8,ENABLE);
	
	//*********   定时器使能    **********
	TIM_Cmd(TIM8,ENABLE);
}



//前左
void MOTOR_FL_PWM(u16 motor_fl_pls){
	
//	TIM_OCInitTypeDef TIM_OCInitStructure;
//	
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性高
//	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //PWM模式
//	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //允许输出
//	TIM_OCInitStructure.TIM_Pulse = motor_fl_pls; //占空比
//	TIM_OC1Init(TIM8,&TIM_OCInitStructure);
//	
////	TIM_OC1PolarityConfig(TIM8,TIM_OCPreload_Enable);
//	TIM_CtrlPWMOutputs(TIM8,ENABLE);
//	TIM_ARRPreloadConfig(TIM8,ENABLE);
//	TIM_Cmd(TIM8,ENABLE);
	
	
	TIM_SetCompare1(TIM8,motor_fl_pls);

}

//前右
void MOTOR_FR_PWM(u16 motor_fr_pls){
	
//	TIM_OCInitTypeDef TIM_OCInitStructure;
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性高
//	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //PWM模式
//	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //允许输出
//	TIM_OCInitStructure.TIM_Pulse = motor_fr_pls; //占空比
//	TIM_OC2Init(TIM8,&TIM_OCInitStructure);
//	
////	TIM_OC2PolarityConfig(TIM8,TIM_OCPreload_Enable);
//	TIM_CtrlPWMOutputs(TIM8,ENABLE);
//	TIM_ARRPreloadConfig(TIM8,ENABLE);
//	TIM_Cmd(TIM8,ENABLE);
	
	TIM_SetCompare2(TIM8,motor_fr_pls);
}

//后左
void MOTOR_RL_PWM(u16 motor_rl_pls){

//	TIM_OCInitTypeDef TIM_OCInitStructure;
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性高
//	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //PWM模式
//	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //允许输出
//	TIM_OCInitStructure.TIM_Pulse = motor_rl_pls; //占空比
//	TIM_OC3Init(TIM8,&TIM_OCInitStructure);
//	
////	TIM_OC3PolarityConfig(TIM8,TIM_OCPreload_Enable);
//	TIM_CtrlPWMOutputs(TIM8,ENABLE);
//	TIM_ARRPreloadConfig(TIM8,ENABLE);
//	TIM_Cmd(TIM8,ENABLE);
	
	TIM_SetCompare3(TIM8,motor_rl_pls);
}

//后右
void MOTOR_RR_PWM(u16 motor_rr_pls){

//	TIM_OCInitTypeDef TIM_OCInitStructure;
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //输出极性高
//	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //PWM模式
//	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //允许输出
//	TIM_OCInitStructure.TIM_Pulse = motor_rr_pls; //占空比
//	TIM_OC4Init(TIM8,&TIM_OCInitStructure);
//	
////	TIM_OC4PolarityConfig(TIM8,TIM_OCPreload_Enable);
//	TIM_CtrlPWMOutputs(TIM8,ENABLE);
//	TIM_ARRPreloadConfig(TIM8,ENABLE);
//	TIM_Cmd(TIM8,ENABLE);
	
	TIM_SetCompare4(TIM8,motor_rr_pls);
	
}
