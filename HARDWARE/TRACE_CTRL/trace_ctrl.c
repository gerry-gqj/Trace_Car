#include "trace_ctrl.h"
#include "infrared_status.h"
#include "car_status.h"
#include "led.h"
#include "key.h"
#include "motor_pwm.h"
#include "delay.h"



void TRACE_CTRL(void){
	
	MOTOR_PWM_Config(99,35);
	delay_init();
	KEY_Init();
	
	//********************     传感器从左往右依次为      *************************
	//************ SENSOR1_IN SENSOR2_IN SENSOR3_IN SENSOR4_IN******************
	
	//全是白线，前进
	
	while(1){
		
		if((SENSOR1_IN == 0)&&(SENSOR2_IN == 0)&&(SENSOR3_IN == 0)&&(SENSOR4_IN == 0)){
			
			MOTOR_FL_PWM(90);		
			MOTOR_FR_PWM(90);
			
			MOTOR_RL_PWM(90);
			MOTOR_RR_PWM(90);
			
			Car_Go();
			
			LED3 = 1;
			LED4 = 1;
			LED5 = 1;
			LED6 = 1;
		}

//***********************************************************************************
		
		if((SENSOR1_IN == 1)&&(SENSOR2_IN == 0)&&(SENSOR3_IN == 0)&&(SENSOR4_IN == 0)){	

			MOTOR_FL_PWM(90);		
			MOTOR_FR_PWM(90);
			
			MOTOR_RL_PWM(90);
			MOTOR_RR_PWM(90);
			
			Car_Right_Round();
			
			LED3 = 0;
			LED4 = 0;
			LED5 = 1;
			LED6 = 0;
		}
		
		if((SENSOR1_IN == 1)&&(SENSOR2_IN == 1)&&(SENSOR3_IN == 0)&&(SENSOR4_IN == 0)){

			MOTOR_FL_PWM(90);		
			MOTOR_FR_PWM(90);
			
			MOTOR_RL_PWM(90);
			MOTOR_RR_PWM(90);
			
			Car_Turn_Right();
			
			LED3 = 0;
			LED4 = 0;
			LED5 = 1;
			LED6 = 1;
		}

		if((SENSOR1_IN == 0)&&(SENSOR2_IN == 1)&&(SENSOR3_IN == 0)&&(SENSOR4_IN == 0)){

			MOTOR_FL_PWM(95);		
			MOTOR_FR_PWM(70);
			
			MOTOR_RL_PWM(95);
			MOTOR_RR_PWM(70);
			
			Car_Go();
			
			LED3 = 0;
			LED4 = 0;
			LED5 = 0;
			LED6 = 1;
		}
		
		if((SENSOR1_IN == 1)&&(SENSOR2_IN == 1)&&(SENSOR3_IN == 1)&&(SENSOR4_IN == 0)){

			MOTOR_FL_PWM(90);		
			MOTOR_FR_PWM(90);
			
			MOTOR_RL_PWM(90);
			MOTOR_RR_PWM(90);
			
			Car_Right_Round();
			
			LED3 = 0;
			LED4 = 0;
			LED5 = 0;
			LED6 = 1;
		}
		
		
//*************************************************************************************
		
		
		if((SENSOR1_IN == 0)&&(SENSOR2_IN == 0)&&(SENSOR3_IN == 0)&&(SENSOR4_IN == 1)){
			
			MOTOR_FL_PWM(90);		
			MOTOR_FR_PWM(90);
			
			MOTOR_RL_PWM(90);
			MOTOR_RR_PWM(90);
			
			Car_Left_Round();
			
			LED3 = 0;
			LED4 = 1;
			LED5 = 0;
			LED6 = 0;
		}

		if((SENSOR1_IN == 0)&&(SENSOR2_IN == 0)&&(SENSOR3_IN == 1)&&(SENSOR4_IN == 1)){
			
			MOTOR_FL_PWM(90);		
			MOTOR_FR_PWM(90);
			
			MOTOR_RL_PWM(90);
			MOTOR_RR_PWM(90);
			
			Car_Turn_Left();
			
			LED3 = 1;
			LED4 = 1;
			LED5 = 0;
			LED6 = 0;
		}
		if((SENSOR1_IN == 0)&&(SENSOR2_IN == 0)&&(SENSOR3_IN == 1)&&(SENSOR4_IN == 0)){
			
			MOTOR_FL_PWM(70);		
			MOTOR_FR_PWM(95);
			MOTOR_RL_PWM(70);
			MOTOR_RR_PWM(95);

			Car_Go();
			
			LED3 = 1;
			LED4 = 0;
			LED5 = 0;
			LED6 = 0;
		}
		if((SENSOR1_IN == 0)&&(SENSOR2_IN == 1)&&(SENSOR3_IN == 1)&&(SENSOR4_IN == 1)){
			
			MOTOR_FL_PWM(90);		
			MOTOR_FR_PWM(90);
			
			MOTOR_RL_PWM(90);
			MOTOR_RR_PWM(90);

			Car_Left_Round();
			
			LED3 = 1;
			LED4 = 0;
			LED5 = 0;
			LED6 = 0;
		}
		
		
//**********************************************************************************	
		
		if((SENSOR1_IN == 1)&&(SENSOR2_IN == 1)&&(SENSOR3_IN == 1)&&(SENSOR4_IN == 1)){
			
			MOTOR_FL_PWM(90);		
			MOTOR_FR_PWM(90);
			MOTOR_RL_PWM(90);
			MOTOR_RR_PWM(90);
			
			Car_Stop();
			
			delay_ms(300);
			LED3 = 0;
			LED4 = 0;
			LED5 = 0;
			LED6 = 0;
			delay_ms(300);
			LED3 = 1;
			LED4 = 1;
			LED5 = 1;
			LED6 = 1;
			break;
		}
		
//********************************************************************************
		
//		if(KEY_Scan(0) == WKUP_PRES ){
//			break;
//		}

//********************************************************************************
		
//********************************************************************************
		
	}
}
