
#include "LPC13xx.h"

#define LED_GPIO        1
#define LED_PIN         8
#define LED_PIN_MASK    (1 << LED_PIN)


void delay(int n)
{
    int i, j;
    
    for (i=0; i<n; i++) {
        for (j=0; j<5000; j++) {
        }
    }
}

void ledInit(void)
{
    /* Enable GPIO Clock */
    LPC_SYSCON->SYSAHBCLKCTRL   |= (1 << 6);
    
    /* Configure LED's pin to output mode */
    LPC_IOCON->PIO1_8   = 0 | (2 << 3);
    LPC_GPIO1->DIR      |= LED_PIN_MASK;
    
    /* Turn off LED */
    LPC_GPIO1->DATA     |= LED_PIN_MASK;
    
}

void ledOn(void)
{
    LPC_GPIO1->DATA  &= ~LED_PIN_MASK;
}

void ledOff(void)
{
    LPC_GPIO1->DATA |= LED_PIN_MASK;
}

main()
{
    ledInit();
    
    for (;;) {
        ledOn();
        delay(1000);
        ledOff();
        delay(1000);
    }
}

