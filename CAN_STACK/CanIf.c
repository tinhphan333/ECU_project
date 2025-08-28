/**
 * @file    CanIf.c
 * @brief   Định nghĩa các hàm để nhận dữ liệu đã đọc từ CAN Driver và đóng gói dữ liệu để truyền lên lớp phía trên.
 * @details File chứa các hàm để khởi tạo các hàm nhận dữ liệu đã đọc từ CAN Driver và đóng gói dữ liệu để truyền lên lớp phía trên.
 * @author  phantinhphan333
 * @date    2025-08-10
 * @version 1.0
 *
 */
#include "CanIf.h" // Thư viện chứa các hàm nhận dữ liệu từ CAN Driver
#include "PduR.h"  // Thư viện chứa các hàm để gửi dữ liệu lên lớp PduR

// Hàm ánh xạ ID của gói tin CAN thành ID của gói tin PDU
static PduIDType CanIf_MatchPduIdFromCanId(uint32_t canId)
{
    // khai báo kiểu đóng gói dữ liệu CAN
    PduIDType pduId;
    pduId = canId; // ánh xạ canId thành pduId
    return pduId;
}

Std_ReturnType CanIf_Receive(uint32_t canId, uint8_t *data, uint8_t dlc)
{
    // Gán dữ liệu vào PduIDType
    PduIDType pduId = CanIf_MatchPduIdFromCanId(canId);

    // Gán dữ liệu vào PduInfoType
    PduInfoType pduInfo;
    pduInfo.data = data;
    pduInfo.length = dlc;

    // Kiểm tra kết quả trả về của hàm PduR_RouteReceive
    if (PduR_RouteReceive(pduId, &pduInfo) == E_OK) // Gọi hàm để gửi dữ liệu lên PduR
    {
        return E_OK;
    }
    return E_NOT_OK;
}