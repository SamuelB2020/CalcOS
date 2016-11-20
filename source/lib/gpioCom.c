#include "GPIOCom.h"
#include <stdint.h>
#include "gpio.h"
typedef int bool;
#define true 1
#define false 0
static rpi_gpio_t* rpiGpio = (rpi_gpio_t*)0x3F200000UL;

extern void SetPinMode( rpi_gpio_pin_t gpio, rpi_gpio_alt_function_t func )
{
    rpi_reg_rw_t* fsel_reg = &((rpi_reg_rw_t*)rpiGpio)[ gpio / 10 ];
    rpi_reg_rw_t fsel_copy = *fsel_reg;
    fsel_copy &= ~( FS_MASK << ( ( gpio % 10 ) * 3 ) );
    fsel_copy |= (func << ( ( gpio % 10 ) * 3 ) );
    *fsel_reg = fsel_copy;
}
extern void GPIORead(int pin){

}
extern void GPIODigitalWrite(int pin,bool value){

}
extern void GPIOAnalogWrite(int pin, int value){
    
}
extern void GPIOInit(int pin, bool value){
    if(value == 1){
        SetPinMode(pin, FS_OUTPUT);
    }
    if(value == 0){
        SetPinMode(pin, FS_INPUT);
    }
    else{
        //catch
    }
    
}