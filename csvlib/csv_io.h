/**
 * @file    csv_io.h
 * @brief   khai báo các hàm để tương tác với file CSV.
 * @details file này cung cấp giao diện cho việc tương tác với file CSV, bao gồm đọc và ghi các giá trị số nguyên và chuỗi.
 * @author  phantinhphan333
 * @date    2025-08-01
 * @version 1.0
 */

#ifndef CSV_IO_H
#define CSV_IO_H

#include <stdio.h>  // Sử dụng cho việc đóng mở tệp với các hàm fopen, fclose, v.v.
#include <stdlib.h> // Sử dụng cho hàm cấp phát bộ nhớ malloc, free, hàm chuyển đổi chuỗi sang số atoi, v.v.
#include <string.h> // Sử dụng cho hàm xử lý chuỗi như strcpy, strlen, v.v.

#define MAX_LINE_LENGTH 256     /**< @brief Độ dài tối đa của mỗi dòng trong file CSV. */
#define MAX_KEY_VALUE_LENGTH 12 /**< @brief Độ dài tối đa của mỗi từ khóa trong file CSV. */
#define FILE_PATH "UI/data.csv" /**< @brief Đường dẫn file cấu hình. */
#define CSV_GINT_ERROR -1
#define CSV_GSTR_ERROR NULL

/**
 * @brief   Lấy giá trị số nguyên từ file CSV theo key.
 * @details Hàm sẽ đọc từng dòng của file, tìm key khớp và chuyển đổi giá trị tương ứng thành số nguyên.
 * @param   key Tên key cần tìm.
 * @return  Giá trị số nguyên. Trả về CSV_GINT_ERROR nếu không tìm thấy key/file.
 */
int csv_getInt(const char *key);

/**
 * @brief   Cập nhật giá trị số nguyên cho key trong file CSV.
 * @details Hàm sẽ đọc từng dòng của file, tìm key khớp và cập nhật giá trị tương ứng.
 * @param   key Tên key cần cập nhật.
 * @param   value Giá trị số nguyên mới cần cập nhật.
 */
void csv_setInt(const char *key, int value);

/**
 * @brief   Lấy giá trị chuỗi từ file CSV theo key.
 * @details Hàm sẽ đọc từng dòng của file, tìm key khớp và trả về giá trị tương ứng dưới dạng chuỗi.
 * @param   key Tên key cần tìm.
 * @return  Chuỗi giá trị tương ứng. Trả về CSV_GSTR_ERROR nếu không tìm thấy key/file hoặc lỗi cấp phát bộ nhớ.
 */
const char *csv_getString(const char *key);

#endif // CSV_IO_H