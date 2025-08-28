/**
 * @file    PduR.h
 * @brief   Khai báo các hàm để nhận dữ liệu gói PDU từ CanIf và gửi dữ liệu lên lớp Com.
 * @details File cung cấp giao diện để nhận dữ liệu gói PDU từ CanIf và gửi dữ liệu lên lớp Com.
 * @author  phantinhphan333
 * @date    2025-08-10
 * @version 1.0
 */

#ifndef PDUR_H
#define PDUR_H

#include "CanType.h" // Thư viện chứa các kiểu dữ liệu cho CAN

/**
 * @brief Nhận dữ liệu gói PDU từ CanIf và gửi dữ liệu lên lớp Com.
 * @param pduId ID của gói tin PDU.
 * @param pduInfo Thông tin gói tin PDU.
 * @return Trả về E_OK nếu thành công, E_NOT_OK nếu có lỗi xảy ra.
 */
Std_ReturnType PduR_RouteReceive(PduIDType pduId, PduInfoType *pduInfo);

#endif // PDUR_H