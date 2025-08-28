/**
 * @file    CanIf.h
 * @brief   Khai báo các hàm để nhận dữ liệu đã đọc từ CAN Driver và đóng gói dữ liệu để truyền lên lớp phía trên.
 * @details File cung cấp giao diện để khởi tạo các hàm nhận dữ liệu đã đọc từ CAN Driver và đóng gói dữ liệu để truyền lên lớp phía trên.
 * @author  phantinhphan333
 * @date    2025-08-10
 * @version 1.0
 */

#include "MCAL/Can/Can.h" // Thư viện đọc dữ liệu từ CAN Driver
#include "CanType.h"      // Thư viện chứa các kiểu dữ liệu cho CAN

/**
 * @brief Hàm nhận dữ liệu từ CAN Driver và gửi lên lớp PduR.
 * @param canId ID của gói tin CAN.
 * @return Trả về E_OK nếu thành công, E_NOT_OK nếu có lỗi xảy ra.
 */
Std_ReturnType CanIf_Receive(uint32_t canId, uint8_t *data, uint8_t dlc);
