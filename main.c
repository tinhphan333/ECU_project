// #include "csvlib/csv_io.h"
// #include "MCAL/Dio/Dio.h"
// #include "MCAL/Pwm/Pwm.h"
// #include "MCAL/Adc/Adc.h"
#include "MCAL/Can/Can.h"
#include "CAN_STACK/CanIf.h"
#include "CAN_STACK/Com.h"
#include "CAN_STACK/PduR.h"

// can,0x3F0 8 03 8B 26 00 00 00 00 00
int main()
{
    // 1. Đọc & parse frame CAN từ CSV
    uint32_t canId;
    uint8_t data[8];
    uint8_t dlc;
    if (Can_Receive(&canId, data, &dlc) == E_OK)
    {
        // 2. Gửi lên CanIf (đóng gói: id + data)
        CanIf_Receive(canId, data, dlc); // -> PduR_RouteReceive ->
        Com_Indication(canId, data, dlc);
    }
    // 3. Ứng dụng nghiệp vụ lấy tốc độ động cơ
    uint16_t engineRpm;
    Com_ReceiveEngineSpeed(&engineRpm);
    printf("Tốc độ động cơ nhận từ CAN = %u vòng/phút\n", engineRpm);
}