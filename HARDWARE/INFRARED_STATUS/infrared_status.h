#ifndef __INFRARED_STATUS__
#define __INFRARED_STATUS__
#include "sys.h"

#define INFRARED_PORT GPIOA
#define INFRARED_CLK RCC_APB2Periph_GPIOA

#define SENSOR1_PIN GPIO_Pin_4
#define SENSOR2_PIN	GPIO_Pin_5
#define SENSOR3_PIN GPIO_Pin_6
#define SENSOR4_PIN GPIO_Pin_7


#define SENSOR1_IN PAin(4)
#define SENSOR2_IN PAin(5)
#define SENSOR3_IN PAin(6)
#define SENSOR4_IN PAin(7)


void INFRARED_SENSOR_Init(void);

#endif
