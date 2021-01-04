#include "stm32f10x.h"
#include "motor_pwm.h"
#include "motor_status.h"
#include "car_status.h"
#include "infrared_status.h"
#include "trace_ctrl.h"
#include "delay.h"
#include "led.h"
#include "sys.h"
#include "key.h"


int main(){
	
	delay_init();
	LED_Init();	
	KEY_Init();
	MOTOR_STATUS_Config();
	INFRARED_SENSOR_Init();
	MOTOR_PWM_Config(199,0);

	MOTOR_FL_PWM(50);		
	MOTOR_FR_PWM(50);
	MOTOR_RL_PWM(50);
	MOTOR_RR_PWM(50);
	
	while(1){
		switch (KEY_Scan(0)){
			case KEY0_PRES: TRACE_CTRL(); break;
			case KEY1_PRES: Car_Go(); break;
			case WKUP_PRES: Car_Stop(); break;
			default: delay_ms(20); LED0=!LED0;
		}
//		delay_ms(300);
//		LED3 = 0;
//		LED4 = 0;
//		LED5 = 0;
//		LED6 = 0;
//		
//		delay_ms(300);
//		LED3 = 1;
//		LED4 = 1;
//		LED5 = 1;
//		LED6 = 1;
	}
}



