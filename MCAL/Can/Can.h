/**
 * @file    Can.h
 * @brief   Khai báo các hàm để khởi tạo giao tiếp CAN và nhận dữ liệu từ giao thức CAN.
 * @details File này cung cấp giao diện để khởi tạo giao tiếp CAN trong hệ thống và nhận dữ liệu từ giao thức CAN.
 * @author  phantinhphan333
 * @date    2025-08-02
 * @version 1.0
 */

#ifndef CAN_H
#define CAN_H

#include "csvlib/csv_io.h" // sử dụng hàm để đọc chuỗi từ file CSV
#include <stdint.h>        // sử dụng kiểu dữ liệu uint32_t, uint8_t
#include <stdio.h>         // sử dụng hàm printf để in thông báo
#include <string.h>        // sử dụng hàm làm viec với chuỗi như strcpy, strtok

typedef enum
{
    E_OK,    // Trả về khi hàm thực hiện thành công
    E_NOT_OK // Trả về khi có lỗi xảy ra
} Std_ReturnType;

/**
 * @brief Hàm khởi giao tiếp CAN.
 * @details Hàm này khởi tạo các thông số cần thiết để truyền nhận dữ liệu CAN
 * @return void
 */
void Can_Init(void);

/**
 * @brief Hàm nhận dữ liệu từ giao thức CAN.
 * @details Hàm này sẽ đọc dữ liệu từ giao thức CAN và lưu vào các biến được truyền vào.
 * @param canId Con trỏ đến biến để lưu ID của gói tin CAN.
 * @param data Con trỏ đến mảng để lưu dữ liệu của gói tin CAN.
 * @param dlc Con trỏ đến biến để lưu độ dài của gói tin CAN.
 * @return Trả về E_OK nếu thành công, E_NOT_OK nếu có lỗi xảy ra.
 */
Std_ReturnType Can_Receive(uint32_t *canId, uint8_t *data, uint8_t *dlc);

#endif // CAN_H