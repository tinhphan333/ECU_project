/**
 * @file    IOHwAb_Adc.c
 * @brief   Định nghĩa các hàm để đọc và chuyển đổi giá trị các cảm biến từ kênh ADC.
 * @details File chứa các hàm để đọc và chuyển đổi giá trị các cảm biến từ kênh ADC bao gồm
 *          đọc nhiệt độ, điện áp, dòng điện, moment xoắn và vòng tua máy.
 * @author  phantinhphan333
 * @date    2025-08-10
 * @version 1.0
 */

#include "IOHwAb_Adc.h"

Std_ReturnType IoHwAb_ReadTemp(uint16_t *temp_adc, float *temp_C)
{
    // Kiểm tra con trỏ ADC truyền vào
    if (temp_adc == NULL)
    {
        printf("Lỗi đọc cảm biến nhiệt độ\n");
        return E_NOT_OK;
    }

    *(temp_adc) = Adc_ReadChannel(TEMP);                     // Đọc giá trị từ kênh ADC và gán giá trị cho biến
    *(temp_C) = (float)*(temp_adc)*TEMP_MAX / ADC_12BIT_MAX; // Chuyển đổi giá trị sang độ C
    return E_OK;
}

Std_ReturnType IoHwAb_ReadVoltage(uint16_t *voltage_adc, float *voltage_V)
{
    // Kiểm tra con trỏ ADC truyền vào
    if (voltage_adc == NULL)
    {
        printf("Lỗi đọc cảm biến điện áp\n");
        return E_NOT_OK;
    }

    *(voltage_adc) = Adc_ReadChannel(VOLTAGE);                        // Đọc giá trị từ kênh ADC và gán giá trị cho biến
    *(voltage_V) = (float)*(voltage_adc)*VOLTAGE_MAX / ADC_12BIT_MAX; // Chuyển đổi giá trị sang Volt
    return E_OK;
}

Std_ReturnType IoHwAb_ReadCurrent(uint16_t *current_adc, float *current_A)
{
    // Kiểm tra con trỏ ADC truyền vào
    if (current_adc == NULL)
    {
        printf("Lỗi đọc cảm biến dòng điện\n");
        return E_NOT_OK;
    }

    *(current_adc) = Adc_ReadChannel(CURRENT);                        // Đọc giá trị từ kênh ADC và gán giá trị cho biến
    *(current_A) = (float)*(current_adc)*CURRENT_MAX / ADC_12BIT_MAX; // Chuyển đổi giá trị sang Ampe
    return E_OK;
}

Std_ReturnType IoHwAb_ReadTorque(uint16_t *torque_adc, float *torque_Nm)
{
    // Kiểm tra con trỏ ADC truyền vào
    if (torque_adc == NULL)
    {
        printf("Lỗi đọc cảm biến moment xoắn\n");
        return E_NOT_OK;
    }

    *(torque_adc) = Adc_ReadChannel(TORQUE);                        // Đọc giá trị từ kênh ADC và gán giá trị cho biến
    *(torque_Nm) = (float)*(torque_adc)*TORQUE_MAX / ADC_12BIT_MAX; // Chuyển đổi giá trị sang Nm
    return E_OK;
}

Std_ReturnType IoHwAb_ReadRpm(uint16_t *rpm)
{
    // Kiểm tra con trỏ ADC truyền vào
    if (rpm == NULL)
    {
        printf("Lỗi đọc cảm biến vòng tua máy\n");
        return E_NOT_OK;
    }
    *(rpm) = Adc_ReadChannel(RPM); // Đọc giá trị từ kênh ADC và gán giá trị cho biến
    return E_OK;
}
