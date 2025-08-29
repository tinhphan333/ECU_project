/**
 * @file    Com.h
 * @brief   Khai báo các hàm để nhận khi có gói tin mới từ Pdu và giải mã dữ liệu
 * @details File cung cấp giao diện để nhận khi có gói tin mới từ Pdu và giải mã dữ liệu
 * @author  phantinhphan333
 * @date    2025-08-10
 * @version 1.0
 */

#ifndef COM_H
#define COM_H

#include "CanType.h" // Thư viện chứa các kiểu dữ liệu cho CAN
#include <string.h>  // Thư viện cho hàm memcpy
#include <stdint.h>  // Thư viện cho các kiểu dữ liệu chuẩn
#include <stdlib.h>  // Thư viện cho hàm malloc

/**
 * @struct  g_ENGINE_SPEED_Buffer
 * @brief   Cấu trúc dữ liệu để lưu trữ thông tin gói tin tốc độ động cơ
 */
static struct
{
    uint32_t id;
    uint8_t data[8]; // Cấp phát bộ nhớ cho dữ liệu vì sau này cần dùng hàm memcpy
    uint8_t len;
} g_ENGINE_SPEED_Buffer;

/**
 * @brief   Hàm thông báo có gói tin mới từ Pdu
 * @details Hàm này sẽ được gọi khi có gói tin mới từ Pdu
 * @param   pduId ID của gói tin
 * @param   data   Dữ liệu của gói tin
 * @param   dlc    Độ dài của gói tin
 * @return  void
 */
void Com_Indication(PduIDType pduId, uint8_t *data, uint8_t dlc);

/**
 * @brief   Hàm nhận giải mã dữ liệu tốc độ động cơ
 * @details Hàm này sẽ được gọi để giải mã dữ liệu tốc độ động cơ
 * @param   rpm   Con trỏ đến biến lưu trữ giá trị tốc độ động cơ
 * @return  Trạng thái trả về
 */
Std_ReturnType Com_ReceiveEngineSpeed(uint16_t *rpm);

#endif // COM_H