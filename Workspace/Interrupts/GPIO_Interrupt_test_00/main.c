//test_00
//GPIO Interrupt
//on surface

/**
 * main.c
 */
#include "TM4C123GH6PM.h"
#include "IO.h"

#include "PortSetup.h"
#include "InterruptsHandler.h"


int main(void)
{
    GPIOF_init();

    while(1);

	return 0;
}


