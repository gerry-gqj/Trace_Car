#include "trace_ctrl.h"
#include "infrared_status.h"
#include "car_status.h"

void TRACE_CTRL(void){
	
	
	//********************     ������������������Ϊ      *************************
	//************ SENSOR1_IN SENSOR2_IN SENSOR3_IN SENSOR4_IN******************
	
	//ȫ�ǰ��ߣ�ǰ��
	if((SENSOR1_IN == 0)&&(SENSOR2_IN == 0)&&(SENSOR3_IN == 0)&&(SENSOR4_IN == 0)){
			Car_Go();
	}
	if((SENSOR1_IN == 0)&&(SENSOR2_IN == 0)&&(SENSOR3_IN == 1)&&(SENSOR4_IN == 0)){	
		Car_Turn_Right();
	}
	
	if((SENSOR2_IN == 0)&&(SENSOR2_IN == 0)&&(SENSOR2_IN == 1)&&(SENSOR2_IN == 1)){
			Car_Turn_Right();
	}

	if((SENSOR2_IN == 0)&&(SENSOR2_IN == 0)&&(SENSOR2_IN == 0)&&(SENSOR2_IN == 1)){
		Car_Turn_Right();
	}

	if((SENSOR2_IN == 0)&&(SENSOR2_IN == 1)&&(SENSOR2_IN == 0)&&(SENSOR2_IN == 0)){
		Car_Turn_Left();
	}

	if((SENSOR2_IN == 1)&&(SENSOR2_IN == 1)&&(SENSOR2_IN == 0)&&(SENSOR2_IN == 0)){
		Car_Turn_Left();
	}
	if((SENSOR2_IN == 1)&&(SENSOR2_IN == 0)&&(SENSOR2_IN == 0)&&(SENSOR2_IN == 0)){
		Car_Turn_Left();
	}
	
	if((SENSOR2_IN == 1)&&(SENSOR2_IN == 1)&&(SENSOR2_IN == 1)&&(SENSOR2_IN == 1)){
		 Car_Stop();
	}
}


