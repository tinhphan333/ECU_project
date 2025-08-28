#ifndef COM_H
#define COM_H

#include "CanType.h" // Thư viện chứa các kiểu dữ liệu cho CAN

static struct
{
    uint32_t id;
    uint8_t *data;
    uint8_t len;
} g_ENGINE_SPEED_Buffer;

Std_ReturnType Com_Indication(PduIDType pduId, uint8_t *data, uint8_t dlc);

#endif // COM_H