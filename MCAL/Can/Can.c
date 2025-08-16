/**
 * @file    Can.c
 * @brief   Định nghĩa các hàm để khởi tạo giao tiếp CAN và nhận dữ liệu từ giao thức CAN.
 * @details File chứa các hàm để khởi tạo giao tiếp CAN trong hệ thống và nhận dữ liệu từ giao thức CAN.
 * @author  phantinhphan333
 * @date    2025-08-02
 * @version 1.0
 */
#include "Can.h"

void Can_Init(void)
{
    printf("Khởi tạo giao tiếp CAN thành công.\n");
}

Std_ReturnType Can_Receive(uint32_t *canId, uint8_t *data, uint8_t *dlc)
{
    // 1. Kiểm tra tham số đầu vào
    if (canId == NULL || data == NULL || dlc == NULL)
    {
        return E_NOT_OK;
    }

    // 2. Lấy dữ liệu chuỗi từ file CSV
    char *csv_canstr = csv_getString("can");
    if (csv_canstr == NULL)
    {
        return E_NOT_OK;
    }

    // 3. Phân tách chuỗi thành các phần tử
    int n = sscanf(csv_canstr, "%x %hhu %hhx %hhx %hhx %hhx %hhx %hhx %hhx %hhx",
                   canId, dlc,
                   &data[0], &data[1], &data[2], &data[3],
                   &data[4], &data[5], &data[6], &data[7]);

    // 4. Giải phóng bộ nhớ đã cấp phát
    free(csv_canstr);

    // 5. Kiểm tra kết quả
    if (n < 10)
    {
        return E_NOT_OK;
    }
    return E_OK;
}