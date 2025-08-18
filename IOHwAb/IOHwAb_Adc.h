/**
 * @file    IOHwAb_Adc.h
 * @brief   Khai báo các hàm để đọc và chuyển đổi giá trị các cảm biến từ kênh ADC.
 * @details File cung cấp giao diện để đọc và chuyển đổi giá trị các cảm biến từ kênh ADC bao gồm
 *          đọc nhiệt độ, điện áp, dòng điện, moment xoắn và vòng quay.
 * @author  phantinhphan333
 * @date    2025-08-10
 * @version 1.0
 */

#ifndef IOHWAB_ADC_H
#define IOHWAB_ADC_H

#include "MCAL/Adc/Adc.h"

#define ADC_12BIT_MAX 4095 // Định nghĩa giá trị lớn nhất của ADC
#define TEMP_MAX 200       // Giới hạn nhiệt độ là 200 độ C
#define VOLTAGE_MAX 60     // Giới hạn điện áp là 60 V
#define CURRENT_MAX 50     // Giới hạn cường độ dòng điện là 50 A
#define TORQUE_MAX 120     // Giới hạn moment xoắn là 120 Nm
#define RPM_MAX
typedef enum
{
    E_OK,    // Trả về khi hàm thực hiện thành công
    E_NOT_OK // Trả về khi có lỗi xảy ra
} Std_ReturnType;

/**************************************************************************
 * @brief   Đọc và chuyển đổi giá trị nhiệt độ từ ADC.
 * @param   temp_adc  Con trỏ đến biến lưu giá trị ADC.
 * @param   temp_C    Con trỏ đến biến lưu giá trị nhiệt độ tính bằng độ C.
 * @return  Trả về E_OK nếu thành công, ngược lại trả về E_NOT_OK.
 **************************************************************************/
Std_ReturnType IoHwAb_ReadTemp(uint16_t *temp_adc, float *temp_C);

/**************************************************************************
 * @brief   Đọc và chuyển đổi giá trị điện áp từ ADC.
 * @param   voltage_adc  Con trỏ đến biến lưu giá trị ADC.
 * @param   voltage_V    Con trỏ đến biến lưu giá trị điện áp tính bằng Volt.
 * @return  Trả về E_OK nếu thành công, ngược lại trả về E_NOT_OK.
 **************************************************************************/
Std_ReturnType IoHwAb_ReadVoltage(uint16_t *voltage_adc, float *voltage_V);

/**************************************************************************
 * @brief   Đọc và chuyển đổi giá trị dòng điện từ ADC.
 * @param   current_adc  Con trỏ đến biến lưu giá trị ADC.
 * @param   current_A    Con trỏ đến biến lưu giá trị dòng điện tính bằng Ampe.
 * @return  Trả về E_OK nếu thành công, ngược lại trả về E_NOT_OK.
 **************************************************************************/
Std_ReturnType IoHwAb_ReadCurrent(uint16_t *current_adc, float *current_A);

/**************************************************************************
 * @brief   Đọc và chuyển đổi giá trị moment xoắn từ ADC.
 * @param   torque_adc  Con trỏ đến biến lưu giá trị ADC.
 * @param   torque_Nm    Con trỏ đến biến lưu giá trị dòng điện tính bằng Nm.
 * @return  Trả về E_OK nếu thành công, ngược lại trả về E_NOT_OK.
 **************************************************************************/
Std_ReturnType IoHwAb_ReadTorque(uint16_t *torque_adc, float *torque_Nm);

/**************************************************************************
 * @brief   Đọc và chuyển đổi giá trị vòng quay từ ADC.
 * @param   rpm      Con trỏ đến biến lưu giá trị vòng quay tính bằng RPM.
 * @return  Trả về E_OK nếu thành công, ngược lại trả về E_NOT_OK.
 **************************************************************************/
Std_ReturnType IoHwAb_ReadRpm(uint16_t *rpm);

#endif // IOHWAB_ADC_H