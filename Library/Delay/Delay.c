#include "TM4C123GH6PM.h"

void ms_timer0Setup(void);
void s_timer0Setup(void);

/***************************************/
         //GLOBAL FUNCTIONS
/***************************************/

void msDelay_t0(uint32_t ttime) {
    uint32_t i;
    ms_timer0Setup();
    for(i=0; i<ttime; i++) {
        while((TIMER0->RIS & 0x01)==0);
        TIMER0->ICR |= 0x01;
    }
}

//void sDelay_t0(uint32_t ttime) {
//    uint32_t i;
//    s_timer0Setup();
//    for(i=0; i<ttime; i++) {
//        while((TIMER0->RIS & 0x01)==0);
//        TIMER0->ICR |= 0x01;
//    }
//}

/****************************************/
         //LOCAL FUNCTIONS//
/****************************************/
void ms_timer0Setup(void) {
    SYSCTL->RCGCTIMER |= 0x01;
    TIMER0->CTL = 0x00;
    TIMER0->CFG = 0x04;
    TIMER0->TAMR |= 0x02;
    TIMER0->TAILR = 16000 -1;
    TIMER0->ICR |= 0x01;
    TIMER0->CTL |= 0x01;
}

//void s_timer0Setup(void) {
//    SYSCTL->RCGCTIMER |= 0x01;
//    TIMER0->CTL = 0x00;
//    TIMER0->CFG = 0x04;
//    TIMER0->TAMR |= 0x02;
//    TIMER0->TAILR = 16000000 -1;
//    TIMER0->ICR |= 0x01;
//    TIMER0->CTL |= 0x01;
//}
