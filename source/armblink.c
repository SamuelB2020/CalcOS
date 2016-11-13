void kernel_main( unsigned int r0, unsigned int r1, unsigned int atags )
{
    LedInit();
    while(1)
    {
        LedOn();
        waitSeconds(2);
        LedOff();
        waitSeconds(2);
    }
}
