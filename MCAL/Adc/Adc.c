/**
 * @file    Adc.c
 * @brief   Định nghĩa các hàm để khởi tạo và đọc giá trị từ các kênh ADC.
 * @details File này chứa các hàm để khởi tạo và đọc giá trị từ các kênh ADC.
 * @author  phantinhphan333
 * @date    2025-08-02
 * @version 1.0
 */
#include "Adc.h"

void Adc_Init(void)
{
    printf("Khởi tạo kênh ADC thành công\n");
}

uint16_t Adc_ReadChannel(ADC_ChannelID channelId)
{
    switch (channelId)
    {
    case TEMP:
        return csv_getInt("temp");
    case VOLTAGE:
        return csv_getInt("voltage");
    case CURRENT:
        return csv_getInt("current");
    case TORQUE:
        return csv_getInt("torque");
    case RPM:
        return csv_getInt("rpm");
    default:
        printf("Kênh ADC không hợp lệ\n");
        return 0;
    }
}
