/**
 * @file    PduR.c
 * @brief   Định nghĩa các hàm để nhận dữ liệu gói PDU từ CanIf và gửi dữ liệu lên lớp Com.
 * @details File chứa các hàm nhận dữ liệu gói PDU từ CanIf và gửi dữ liệu lên lớp Com.
 * @author  phantinhphan333
 * @date    2025-08-10
 * @version 1.0
 */

#include "PduR.h"
#include "Com.h" // Thư viện chứa các hàm để gửi dữ liệu lên lớp Com

Std_ReturnType PduR_RouteReceive(PduIDType pduId, PduInfoType *pduInfo)
{
    Com_Indication(pduId, pduInfo->data, pduInfo->length);
    return E_OK;
}
