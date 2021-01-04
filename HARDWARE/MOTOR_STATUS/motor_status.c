#include "motor_status.h"
#include "stm32f10x.h"
#include "sys.h"


//端口输出基础配置
void MOTOR_STATUS_Config(void){
	
	// **********    端口配置      **********
	GPIO_InitTypeDef  GPIO_InitStructure;
	
	// **********    时钟使能      **********
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	// **********    输出模式、输出速率      **********
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;  //推挽输出
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;  //50MHz
	
	// **********    前左电机      **********
	GPIO_InitStructure.GPIO_Pin = STATUS_MOTOR_FL_IN1|STATUS_MOTOR_FL_IN2;
	GPIO_Init(STATUS_OUT, &GPIO_InitStructure);
	GPIO_ResetBits(STATUS_OUT,STATUS_MOTOR_FL_IN1|STATUS_MOTOR_FL_IN2);
	
	// **********    前右电机      **********
	GPIO_InitStructure.GPIO_Pin = STATUS_MOTOR_FR_IN3|STATUS_MOTOR_FR_IN4;
	GPIO_Init(STATUS_OUT, &GPIO_InitStructure);
	GPIO_ResetBits(STATUS_OUT,STATUS_MOTOR_FR_IN3|STATUS_MOTOR_FR_IN4);
	
	// **********    后左电机     **********
	GPIO_InitStructure.GPIO_Pin = STATUS_MOTOR_RL_IN1|STATUS_MOTOR_RL_IN2;
	GPIO_Init(STATUS_OUT, &GPIO_InitStructure);
	GPIO_ResetBits(STATUS_OUT,STATUS_MOTOR_RL_IN1|STATUS_MOTOR_RL_IN2);
	
	// **********    后右电机      **********
	GPIO_InitStructure.GPIO_Pin = STATUS_MOTOR_RR_IN3|STATUS_MOTOR_RR_IN4;
	GPIO_Init(STATUS_OUT, &GPIO_InitStructure);
	GPIO_ResetBits(STATUS_OUT,STATUS_MOTOR_RR_IN3|STATUS_MOTOR_RR_IN3);
	
}



void MOTOR_FL_STATUS(u8 state){
	
	// **********    前左电机状态      **********
	// GO：前进
	// BACK：后退
	// STOP：停止
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

	// **********    前右电机状态      **********
	// GO：前进
	// BACK：后退
	// STOP：停止
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
	
	// **********    后左电机状态      **********
	// GO：前进
	// BACK：后退
	// STOP：停止
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
	
	// **********    后右电机状态      **********
	// GO：前进
	// BACK：后退
	// STOP：停止
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
	
