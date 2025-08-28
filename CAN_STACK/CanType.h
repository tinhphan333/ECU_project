#ifndef CANTYPE_H
#define CANTYPE_H

#include <stdint.h> // Thư viện cho các kiểu dữ liệu

#define PDU_ENGINE_SPEED 0x3F0 // ID của gói tin động cơ

/**
 * @struct Std_ReturnType
 * @brief Kiểu trả trạng thái thực hiện của các hàm
 */
typedef enum
{
    E_OK,    // Trả về khi hàm thực hiện thành công
    E_NOT_OK // Trả về khi có lỗi xảy ra
} Std_ReturnType;

/**
 * @struct PduIDType
 * @brief Kiểu dữ liệu cho ID của gói dữ liệu PDU
 */
typedef uint32_t PduIDType; // Kiểu dữ liệu cho ID của gói dữ liệu PDU

/**
 * @struct PduInfoType
 * @brief Kiểu dữ liệu cho thông tin gói dữ liệu PDU
 */
typedef struct
{
    uint8_t *data;  // Con trỏ đến gói dữ liệu PDU
    uint8_t length; // Độ dài của gói dữ liệu PDU
} PduInfoType;

#endif // CANTYPE_H