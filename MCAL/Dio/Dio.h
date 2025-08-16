/**
 * @file    Dio.h
 * @brief   Khai báo các hàm để mô phỏng điều khiển tín hiệu digital IO.
 * @details File này cung cấp giao diện để khởi tạo các kênh digital IO và ghi giá trị vào các kênh này.
 * @author  phantinhphan333
 * @date    2025-08-02
 * @version 1.0
 */

#ifndef DIO_H
#define DIO_H

#include "csvlib/csv_io.h" // sử dụng các hàm để lấy dữ liệu từ file CSV
#include <stdint.h>        // để sử dụng kiểu dữ liệu uint8_t

/**
 * @enum Dio_Level
 * @brief Mức độ của tín hiệu của kênh digital.
 */
typedef enum
{
    DIO_LOW = 0, // Chiều nghịch
    DIO_HIGH = 1 // Chiều thuận
} Dio_Level;

/**
 * @brief Khởi tạo kênh digital IO.
 * @param void
 * @return void
 */
void Dio_Init(void);

/**
 * @brief Ghi giá trị vào một kênh digital IO.
 * @param channelId ID của kênh digital IO.
 * @param level Giá trị cần ghi (DIO_LOW hoặc DIO_HIGH).
 * @return void
 */
void Dio_WriteChannel(uint8_t channelId, Dio_Level level);

#endif // DIO_H