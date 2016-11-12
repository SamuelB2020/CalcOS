@ECHO OFF

arm-none-eabi-gcc -O0 -DRPI2 -mfpu=neon-vfpv4 -mfloat-abi=hard -march=armv7-a -mtune=cortex-a7 -nostartfiles -g rpi.x armblink.c armblink-cstartup.c armblink-cstubs.c armc-012-start.S rpi-systimer.c -o kernel.elf
arm-none-eabi-objcopy kernel.elf -O binary kernel7.img pause
