@ECHO OFF

arm-none-eabi-gcc -O0 -DRPI2 -mfpu=neon-vfpv4 -mfloat-abi=soft -march=armv7-a -mtune=cortex-a7 -nostartfiles -g -Wl,-T,rpi.x LedCom.c Timings.c armblink-cstubs.c armblink-cstartup.c armblink.c rpi-systimer.c armc-012-start.S -o kernel.elf
 arm-none-eabi-objcopy kernel.elf -O binary kernel7.img
 pause