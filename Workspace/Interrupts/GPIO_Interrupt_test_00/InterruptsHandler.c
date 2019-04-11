/*
 * InterruptsHandler.c
 *
 *  Created on: Apr 11, 2019
 *      Author: jimen
 */
#include "TM4C123GH6PM.h"
#include "IO.h"


void GPIOF_Handler(void) {
    GPIOF_AHB->ICR |= (SW1 | SW2);
    GPIOF_AHB->DATA ^= ledRed;
}


