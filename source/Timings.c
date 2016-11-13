#include "rpi-systimer.h"
extern void waitSeconds(uint32_t num){
    RPI_WaitMicroSeconds(num*1000000);

}