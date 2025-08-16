#ifndef IOHWAB_ADC_H
#define IOHWAB_ADC_H

#include <stdint.h>

// Khai báo kiểu trả về cho các hàm ADC
typedef enum
{
    ADC_OK = 0,     // Trả về khi thực hiện thành công
    ADC_ERROR = -1, // Trả về khi có lỗi xảy ra
} Std_ReturnType;

/**************************************************************************
 * @brief   Đọc giá trị nhiệt độ từ ADC.
 * @param   temp_adc  Con trỏ đến biến lưu giá trị ADC.
 * @param   temp_C    Con trỏ đến biến lưu giá trị nhiệt độ tính bằng độ C.
 * @return  Trả về ADC_OK nếu thành công, ngược lại trả về ADC_ERROR.
 **************************************************************************/
Std_ReturnType IoHwAb_ReadTemp(uint16_t *temp_adc, float *temp_C);

/**************************************************************************
 * @brief   Đọc giá trị điện áp từ ADC.
 * @param   voltage_adc  Con trỏ đến biến lưu giá trị ADC.
 * @param   voltage_V    Con trỏ đến biến lưu giá trị điện áp tính bằng Volt.
 * @return  Trả về ADC_OK nếu thành công, ngược lại trả về ADC_ERROR.
 **************************************************************************/
Std_ReturnType IoHwAb_ReadVoltage(uint16_t *voltage_adc, float *voltage_V);

/**************************************************************************
 * @brief   Đọc giá trị dòng điện từ ADC.
 * @param   current_adc  Con trỏ đến biến lưu giá trị ADC.
 * @param   current_A    Con trỏ đến biến lưu giá trị dòng điện tính bằng Ampe.
 * @return  Trả về ADC_OK nếu thành công, ngược lại trả về ADC_ERROR.
 **************************************************************************/
Std_ReturnType IoHwAb_ReadCurrent(uint16_t *current_adc, float *current_A);

/**************************************************************************
 * @brief   Đọc giá trị moment xoắn từ ADC.
 * @param   torque_adc  Con trỏ đến biến lưu giá trị ADC.
 * @param   torque_Nm    Con trỏ đến biến lưu giá trị dòng điện tính bằng Nm.
 * @return  Trả về ADC_OK nếu thành công, ngược lại trả về ADC_ERROR.
 **************************************************************************/
Std_ReturnType IoHwAb_ReadTorque(uint16_t *torque_adc, float *torque_Nm);

/**************************************************************************
 * @brief   Đọc giá trị vòng quay từ ADC.
 * @param   rpm      Con trỏ đến biến lưu giá trị vòng quay tính bằng RPM.
 * @return  Trả về ADC_OK nếu thành công, ngược lại trả về ADC_ERROR.
 **************************************************************************/
Std_ReturnType IoHwAb_ReadRpm(uint16_t *rpm);

#endif // IOHWAB_ADC_H