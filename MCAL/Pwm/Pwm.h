/**
 * @file    Pwm.h
 * @brief   Khai báo các hàm để khởi tạo và sử dụng các kênh PWM mô phỏng điều khiển tốc độ động cơ.
 * @details File này cung cấp giao diện để khởi tạo các kênh điều khiển PWM và hàm thay đổi giá trị tốc độ động cơ
 * @author  phantinhphan333
 * @date    2025-08-02
 * @version 1.0
 */

#ifndef PWM_H
#define PWM_H

#include "csvlib/csv_io.h" // sử dụng các hàm để lấy dữ liệu từ file CSV
#include <stdint.h>        // sử dụng kiểu dữ liệu uint16

/**
 * @brief Khởi tạo kênh Pwm để điều khiển động cơ.
 * @param void
 * @return void
 */
void Pwm_Init(void);

/**
 * @brief Thiết lập giá trị PWM cho kênh điều khiển động cơ.
 * @param channelId ID của kênh PWM cần thiết lập.
 * @param duty Giá trị tốc độ động cơ.
 * @return void
 */
void Pwm_SetDutyCycle(uint8_t channelId, uint16_t duty);

#endif // PWM_H