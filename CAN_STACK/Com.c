#include "Com.h"

// Hàm callback khi có frame mới
void Com_Indication(PduIDType pduId, uint8_t *data, uint8_t dlc)
{
    if (pduId == PDU_ENGINE_SPEED)
    {
        memcpy(g_ENGINE_SPEED_Buffer, data, dlc);
        memcpy(PDU.id, pduId);
    }
}

// API nghiệp vụ để xử lý dữ liệu nhận được từ lớp CanIf
Std_ReturnType Com_ReceiveEngineSpeed(uint16_t *rpm)
{

    // Ví dụ tốc độ động cơ nằm ở 2 byte đầu tiên
    *rpm = 750;
    return E_OK;
}