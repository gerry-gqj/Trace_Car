#include "motor_status.h"
#include "stm32f10x.h"
#include "sys.h"


//�˿������������
void MOTOR_STATUS_Config(void){
	
	// **********    �˿�����      **********
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	// **********    ʱ��ʹ��      **********
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	// **********    ���ģʽ���������      **********
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  //�������
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  //50MHz
	
	// **********    ǰ����      **********
	GPIO_InitStructure.GPIO_Pin = STATUS_MOTOR_FL_IN1|STATUS_MOTOR_FL_IN2;
	GPIO_Init(STATUS_OUT, &GPIO_InitStructure);
	GPIO_ResetBits(STATUS_OUT,STATUS_MOTOR_FL_IN1|STATUS_MOTOR_FL_IN2);
	
	// **********    ǰ�ҵ��      **********
	GPIO_InitStructure.GPIO_Pin = STATUS_MOTOR_FR_IN3|STATUS_MOTOR_FR_IN4;
	GPIO_Init(STATUS_OUT, &GPIO_InitStructure);
	GPIO_ResetBits(STATUS_OUT,STATUS_MOTOR_FR_IN3|STATUS_MOTOR_FR_IN4);
	
	// **********    ������     **********
	GPIO_InitStructure.GPIO_Pin = STATUS_MOTOR_RL_IN1|STATUS_MOTOR_RL_IN2;
	GPIO_Init(STATUS_OUT, &GPIO_InitStructure);
	GPIO_ResetBits(STATUS_OUT,STATUS_MOTOR_RL_IN1|STATUS_MOTOR_RL_IN2);
	
	// **********    ���ҵ��      **********
	GPIO_InitStructure.GPIO_Pin = STATUS_MOTOR_RR_IN3|STATUS_MOTOR_RR_IN4;
	GPIO_Init(STATUS_OUT, &GPIO_InitStructure);
	GPIO_ResetBits(STATUS_OUT,STATUS_MOTOR_RR_IN3|STATUS_MOTOR_RR_IN3);
	
}



void MOTOR_FL_STATUS(u8 state){
	
	// **********    ǰ����״̬      **********
	// GO��ǰ��
	// BACK������
	// STOP��ֹͣ
	if(state == GO){
		MOTOR_FL_IN1 = 1;
		MOTOR_FL_IN2 = 0;
	}else if(state == BACK){
		MOTOR_FL_IN1 = 0;
		MOTOR_FL_IN2 = 1;
	}else if (state == STOP){
		MOTOR_FL_IN1 = 0;
		MOTOR_FL_IN2 = 0;
	}
}
	
void MOTOR_FR_STATUS(u8 state){

	// **********    ǰ�ҵ��״̬      **********
	// GO��ǰ��
	// BACK������
	// STOP��ֹͣ
	if(state == GO){
		MOTOR_FR_IN3 = 1;
		MOTOR_FR_IN4 = 0;
	}else if(state == BACK){
		MOTOR_FR_IN3 = 0;
		MOTOR_FR_IN4 = 1;
	}else if (state == STOP){
		MOTOR_FR_IN3 = 0;
		MOTOR_FR_IN4 = 0;
	}
}
	
void MOTOR_RL_STATUS(u8 state){
	
	// **********    ������״̬      **********
	// GO��ǰ��
	// BACK������
	// STOP��ֹͣ
	if(state == GO){
		MOTOR_RL_IN1 = 1;
		MOTOR_RL_IN2 = 0;
	}else if(state == BACK){
		MOTOR_RL_IN1 = 0;
		MOTOR_RL_IN2 = 1;
	}else if (state == STOP){
		MOTOR_RL_IN1 = 0;
		MOTOR_RL_IN2 = 0;
	}
}
	
void MOTOR_RR_STATUS(u8 state){
	
	// **********    ���ҵ��״̬      **********
	// GO��ǰ��
	// BACK������
	// STOP��ֹͣ
	if(state == GO){
		MOTOR_RR_IN3 = 1;
		MOTOR_RR_IN4 = 0;
	}else if(state == BACK){
		MOTOR_RR_IN3 = 0;
		MOTOR_RR_IN4 = 1;
	}else if (state == STOP){
		MOTOR_RR_IN3 = 0;
		MOTOR_RR_IN4 = 0;
	}
}
	
