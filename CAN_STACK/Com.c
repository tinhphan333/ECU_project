/**
 * @file    Com.c
 * @brief   Định nghĩa các hàm để nhận khi có gói tin mới từ Pdu và giải mã dữ liệu.
 * @details File này chứa các hàm để nhận khi có gói tin mới từ Pdu và giải mã dữ liệu.
 * @author  phantinhphan333
 * @date    2025-08-10
 * @version 1.0
 */

#include "Com.h"

void Com_Indication(PduIDType pduId, uint8_t *data, uint8_t dlc)
{
    if (pduId == PDU_ENGINE_SPEED) // So sánh ID và ID tốc độ động cơ
    {
        g_ENGINE_SPEED_Buffer.id = pduId; // Sao chép ID
        g_ENGINE_SPEED_Buffer.len = dlc;  // Sao chép dlc

        // Sao chép dữ liệu - dùng memcpy() để sao chép vùng dữ liệu an toàn, nếu chỉ dùng như id và len thì khi có gói tin mới có thể làm mất dữ liệu.
        memcpy(g_ENGINE_SPEED_Buffer.data, data, dlc);
    }
}

Std_ReturnType Com_ReceiveEngineSpeed(uint16_t *rpm)
{
    uint16_t raw_rpm_data = (uint16_t)((g_ENGINE_SPEED_Buffer.data[0] << 8) | g_ENGINE_SPEED_Buffer.data[1]); // Gộp hai byte thành một giá trị 16 bit

    // Kiểm tra con trỏ rpm
    if (rpm == NULL)
    {
        return E_NOT_OK;
    }
    *rpm = raw_rpm_data / 4; // Công thức: (data[0] x 256 + data[1])/ 4
    return E_OK;
}