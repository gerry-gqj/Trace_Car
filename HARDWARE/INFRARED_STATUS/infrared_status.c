#include "infrared_status.h"
#include "stm32f10x.h"

void INFRARED_SENSOR_Init(void){

	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(INFRARED_CLK,ENABLE);
	
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin = SENSOR1_PIN|SENSOR2_PIN|SENSOR3_PIN|SENSOR4_PIN;
	GPIO_Init(INFRARED_PORT,&GPIO_InitStructure);

}


