/*
 * PortSetup.c
 *
 *  Created on: Apr 11, 2019
 *      Author: jimen
 */
#include "TM4C123GH6PM.h"
#include "IO.h"

#define unlock      0x4C4F434B



void GPIOF_init(void) {
    SYSCTL->RCGCGPIO |= (1U<<5);
    SYSCTL->GPIOHBCTL |= (1U<<5);
    GPIOF_AHB->LOCK = unlock;
//    GPIOF_AHB->CR = (ledRed | ledBlue | ledGreen | SW1 | SW2);
    GPIOF_AHB->DEN |= (ledRed | ledBlue | ledGreen | SW1 | SW2);
    GPIOF_AHB->DIR |= (ledRed | ledBlue | ledGreen);
    GPIOF_AHB->DIR &= ~(SW1 | SW2);
    GPIOF_AHB->PUR |= (SW1 | SW2);          //enable weak pull-up resistor
    GPIOF_AHB->IS &= ~(SW1 | SW2);          //make SWs edge sensitive
    GPIOF_AHB->IBE &= ~(SW1 | SW2);         //make this register in conjuction with IEV
    GPIOF_AHB->IEV &= ~(SW1 | SW2);         //make SWs rising edge triggered
    GPIOF_AHB->ICR |= (SW1 | SW2);          //clear previous interrupts
    GPIOF_AHB->IM |= (SW1 | SW2);           //unmask the interrupt for SWs
    NVIC->IP[30] = 0X00600000;              //assign priority as 3
    NVIC->ISER[0] |= (1U<<30);              //enable interrupt for IRQ30
    __enable_irq();
}

