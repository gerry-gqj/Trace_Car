#ifndef __PWM_H
#define __PWM_H
#include "sys.h"

#define IN11 PBout(5)
#define IN12 PBout(6)
#define IN13 PBout(7)
#define IN14 PBout(8)

#define IN21 PBout(9)
#define IN22 PBout(10)
#define IN23 PBout(11)
#define IN24 PBout(12)


void TIM1_PWM_Init(u16 arr,u16 psc);

#endif
