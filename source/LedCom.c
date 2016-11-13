
#include "gpio.h"
volatile unsigned int* gpioController = (unsigned int*)GPIO_BASE;
extern void LedInit(){
int loop;

    gpioController[LED_GPFSEL]|=( 1 << LED_GPFBIT );
}
extern void LedOn(){
    gpioController[LED_GPSET] = ( 1 << LED_GPIO_BIT );

}
extern void LedOff(){
       gpioController[LED_GPCLR] = ( 1 << LED_GPIO_BIT );
 }