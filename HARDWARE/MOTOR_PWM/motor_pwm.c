#include "motor_pwm.h"
#include "stm32f10x.h"

// arr; ��ʱ��Ԥװ��ֵ
// psc; ��ʱ��Ԥ��Ƶϵ�� ʵ�����Ƶ��=72Mhz/psc
void MOTOR_PWM_Config(u16 arr,u16 psc){

//**********************�ṹ������******************************************	
	//IO������
	GPIO_InitTypeDef GPIO_InitStructure;
	//��ʱ����������
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	//��ʱ���Ƚ��������
	TIM_OCInitTypeDef TIM_OCInitStructure;
	
//***********************ʱ��ʹ��*******************************************	
	
	//IO������ʱ��ʹ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE); 
	//��ʱ��TIM2/TIM3ʱ��ʹ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_TIM8,ENABLE);

//***********************IO������*******************************************	
		
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;  //���ù����������
	GPIO_InitStructure.GPIO_Pin = FL_PWM|FR_PWM|RL_PWM|RR_PWM;  //�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(PWM_OUT,&GPIO_InitStructure);
	
//***********************��ʱ������*****************************************	
	
	//********   ��ʱ����������    *********
	TIM_TimeBaseInitStructure.TIM_ClockDivision = 0; //����ʱ�ӷָ�˲�����
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up; //���ϼ���
	TIM_TimeBaseInitStructure.TIM_Period = arr; //Ԥװ��ֵ,�������ö�ʱ����������
	TIM_TimeBaseInitStructure.TIM_Prescaler = psc; //Ԥ��Ƶϵ��
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM8,&TIM_TimeBaseInitStructure);
	
	
	//*********    TIM_CH1    **********
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //������Ը�
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //PWMģʽ
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�������
	TIM_OCInitStructure.TIM_Pulse = 0; //ռ�ձ�
	TIM_OC1Init(TIM8,&TIM_OCInitStructure);
	
	//*********    TIM_CH2    **********
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //������Ը�
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //PWMģʽ
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�������
	TIM_OCInitStructure.TIM_Pulse = 0; //ռ�ձ�
	TIM_OC2Init(TIM8,&TIM_OCInitStructure);
	
	
	//*********    TIM_CH3    **********
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //������Ը�
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //PWMģʽ
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�������
	TIM_OCInitStructure.TIM_Pulse = 0; //ռ�ձ�
	TIM_OC3Init(TIM8,&TIM_OCInitStructure);
	
	
	//*********    TIM_CH4    **********
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //������Ը�
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //PWMģʽ
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�������
	TIM_OCInitStructure.TIM_Pulse = 0; //ռ�ձ�
	TIM_OC4Init(TIM8,&TIM_OCInitStructure);
	
	//*********    MOE �����ʹ��    ********
	TIM_CtrlPWMOutputs(TIM8,ENABLE);
	
	//*********    TIM8_CH1/2/3/4Ԥװ��ʹ��    ********
	TIM_OC1PreloadConfig(TIM8,ENABLE);
	TIM_OC2PreloadConfig(TIM8,ENABLE);
	TIM_OC3PreloadConfig(TIM8,ENABLE);
	TIM_OC4PreloadConfig(TIM8,ENABLE);
	
	//*********   �Զ���װ�Ĵ���ʹ��   ********
	TIM_ARRPreloadConfig(TIM8,ENABLE);
	
	//*********   ��ʱ��ʹ��    **********
	TIM_Cmd(TIM8,ENABLE);
}



//ǰ��
void MOTOR_FL_PWM(u16 motor_fl_pls){
	
//	TIM_OCInitTypeDef TIM_OCInitStructure;
//	
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //������Ը�
//	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //PWMģʽ
//	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�������
//	TIM_OCInitStructure.TIM_Pulse = motor_fl_pls; //ռ�ձ�
//	TIM_OC1Init(TIM8,&TIM_OCInitStructure);
//	
////	TIM_OC1PolarityConfig(TIM8,TIM_OCPreload_Enable);
//	TIM_CtrlPWMOutputs(TIM8,ENABLE);
//	TIM_ARRPreloadConfig(TIM8,ENABLE);
//	TIM_Cmd(TIM8,ENABLE);
	
	
	TIM_SetCompare1(TIM8,motor_fl_pls);

}

//ǰ��
void MOTOR_FR_PWM(u16 motor_fr_pls){
	
//	TIM_OCInitTypeDef TIM_OCInitStructure;
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //������Ը�
//	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //PWMģʽ
//	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�������
//	TIM_OCInitStructure.TIM_Pulse = motor_fr_pls; //ռ�ձ�
//	TIM_OC2Init(TIM8,&TIM_OCInitStructure);
//	
////	TIM_OC2PolarityConfig(TIM8,TIM_OCPreload_Enable);
//	TIM_CtrlPWMOutputs(TIM8,ENABLE);
//	TIM_ARRPreloadConfig(TIM8,ENABLE);
//	TIM_Cmd(TIM8,ENABLE);
	
	TIM_SetCompare2(TIM8,motor_fr_pls);
}

//����
void MOTOR_RL_PWM(u16 motor_rl_pls){

//	TIM_OCInitTypeDef TIM_OCInitStructure;
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //������Ը�
//	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //PWMģʽ
//	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�������
//	TIM_OCInitStructure.TIM_Pulse = motor_rl_pls; //ռ�ձ�
//	TIM_OC3Init(TIM8,&TIM_OCInitStructure);
//	
////	TIM_OC3PolarityConfig(TIM8,TIM_OCPreload_Enable);
//	TIM_CtrlPWMOutputs(TIM8,ENABLE);
//	TIM_ARRPreloadConfig(TIM8,ENABLE);
//	TIM_Cmd(TIM8,ENABLE);
	
	TIM_SetCompare3(TIM8,motor_rl_pls);
}

//����
void MOTOR_RR_PWM(u16 motor_rr_pls){

//	TIM_OCInitTypeDef TIM_OCInitStructure;
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High; //������Ը�
//	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1; //PWMģʽ
//	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable; //�������
//	TIM_OCInitStructure.TIM_Pulse = motor_rr_pls; //ռ�ձ�
//	TIM_OC4Init(TIM8,&TIM_OCInitStructure);
//	
////	TIM_OC4PolarityConfig(TIM8,TIM_OCPreload_Enable);
//	TIM_CtrlPWMOutputs(TIM8,ENABLE);
//	TIM_ARRPreloadConfig(TIM8,ENABLE);
//	TIM_Cmd(TIM8,ENABLE);
	
	TIM_SetCompare4(TIM8,motor_rr_pls);
	
}
