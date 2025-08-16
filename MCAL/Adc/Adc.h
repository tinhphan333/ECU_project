/**
 * @file    Adc.h
 * @brief   Khai báo các hàm để khởi tạo và đọc giá trị từ các kênh ADC.
 * @details File này cung cấp giao diện để khởi tạo và đọc giá trị từ các kênh ADC.
 * @author  phantinhphan333
 * @date    2025-08-02
 * @version 1.0
 */

#ifndef ADC_H
#define ADC_H

#include "csvlib/csv_io.h" // Thư viện CSV để ghi dữ liệu vào file CSV
#include <stdint.h>        // Sử dụng kiểu dữ liệu uint8_t và uint16_t
#include <stdio.h>         // sử dụng printf để in thông báo

/**
 * @enum ADC_ChannelID
 * @brief Các kênh ADC có thể sử dụng.
 * @details Mỗi kênh ADC tương ứng với một cảm biến khác nhau trong hệ thống.
 */
typedef enum
{
    TEMP = 0, // Kênh ADC cho cảm biến nhiệt độ
    VOLTAGE,  // Kênh ADC cho cảm biến điện áp
    CURRENT,  // Kênh ADC cho cảm biến dòng điện
    TORQUE,   // Kênh ADC cho cảm biến moment
    RPM,      // Kênh ADC cho cảm biến tốc độ động cơ
} ADC_ChannelID;

/**
 * @brief Hàm khởi tạo kênh ADC.
 * @param void
 * @return void
 */
void Adc_Init(void);

/**
 * @brief Hàm đọc giá trị từ kênh ADC.
 * @param channelId ID của kênh ADC cần đọc.
 * @return Giá trị đọc được từ kênh ADC, hoặc 0 nếu kênh không hợp lệ.
 */
uint16_t Adc_ReadChannel(ADC_ChannelID channelId);

#endif // ADC_H