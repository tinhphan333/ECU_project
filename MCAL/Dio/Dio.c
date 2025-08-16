/**
 * @file    Dio.c
 * @brief   Định nghĩa các hàm để mô phỏng điều khiển tín hiệu digital IO.
 * @details File này chứa các hàm để khởi tạo các kênh digital IO và ghi giá trị vào các kênh này.
 * @author  phantinhphan333
 * @date    2025-08-02
 * @version 1.0
 */
#include "Dio.h"

void Dio_Init(void)
{
    printf("Khởi tạo kênh Digital IO thành công\n");
}

void Dio_WriteChannel(uint8_t channelId, Dio_Level level)
{
    csv_setInt("direction", level);
    if (level)
        printf("Ghi giá trị thành công\nchannelID: %d - status: HIGH\n", channelId);
    else
        printf("Ghi giá trị thành công\nchannelID: %d - status: LOW\n", channelId);
}
