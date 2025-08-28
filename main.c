#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csvlib/csv_io.h"
#include "MCAL/Dio/Dio.h"
#include "MCAL/Pwm/Pwm.h"
#include "MCAL/Adc/Adc.h"
#include "MCAL/Can/Can.h"

// can,0x3F0 8 03 8B 26 00 00 00 00 00
int main()
{
    uint32_t Canid;
    uint8_t data[8];
    uint8_t dlc;

    Can_Receive(&Canid, data, &dlc);
    printf("Can: %x ", Canid);
    printf("%d ", dlc);
    for (int i = 0; i < 8; i++)
    {
        printf("%x ", data[i]);
    }
    return 0;
}