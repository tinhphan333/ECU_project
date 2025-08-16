/**
 * @file    Pwm.c
 * @brief   Định nghĩa các hàm để khởi tạo và sử dụng các kênh PWM mô phỏng điều khiển tốc độ động cơ.
 * @details File này chứa các hàm để khởi tạo các kênh điều khiển PWM và hàm thay đổi giá trị tốc độ động cơ
 * @author  phantinhphan333
 * @date    2025-08-02
 * @version 1.0
 */
#include "Pwm.h"

void Pwm_Init(void)
{
    printf("Khởi tạo kênh PWM thành công\n");
}

void Pwm_SetDutyCycle(uint8_t channelId, uint16_t duty)
{
    csv_setInt("duty", duty); // Lưu giá trị duty vào file CSV
    printf("Thiết lập giá trị PWM thành công\nchannelID: %d - duty: %d\n", channelId, duty);
}
