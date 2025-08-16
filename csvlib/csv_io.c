/**
 * @file    csv_io.c
 * @brief   Định nghĩa các hàm để tương tác với file CSV.
 * @details file này chứa phần định nghĩa các hàm tương tác với file CSV, bao gồm đọc và ghi các giá trị số nguyên và chuỗi.
 * @author  phantinhphan333
 * @date    2025-08-01
 * @version 1.0
 */
#include "csv_io.h"

static void Free_KeyValue(char **keys, char **values, int count)
{
    for (int i = 0; i < count; i++)
    {
        free(keys[i]);   // Giải phóng bộ nhớ cho từng từ khóa
        free(values[i]); // Giải phóng bộ nhớ cho từng giá trị
    }
}

int csv_getInt(const char *key)
{
    FILE *file = fopen(FILE_PATH, "r"); // Mở file ở chế độ đọc
    if (file == NULL)
    {
        printf("Lỗi mở file\n");
        return CSV_GINT_ERROR;
    }
    char line[MAX_LINE_LENGTH]; // Dùng để lưu từng dòng đọc từ file
    while (fgets(line, sizeof(line), file))
    {
        char line_copy[MAX_LINE_LENGTH];
        strcpy(line_copy, line); // Tạo bản sao của dòng để sử dụng strtok(chuỗi đầu vào, ký tự phân tách), hàm này sẽ thay đổi ký tự phân tách trong chuỗi gốc thành ký tự null

        char *current_key = strtok(line_copy, ","); // Dấu phẩy là ký tự phân tách
        char *current_value = strtok(NULL, "\n");   // Bắt đầu từ Null (dấu phẩy đã được thay thế bằng ký tự null ở trên)

        if (current_key && current_value && strcmp(current_key, key) == 0)
        {
            fclose(file);               // Đóng file trước khi trả về giá trị
            return atoi(current_value); // Chuyển đổi chuỗi sang số nguyên và trả về
        }
    }
    fclose(file); // Đóng file nếu không tìm thấy khóa
    printf("Không tìm thấy từ khóa: %s\n", key);
    return CSV_GINT_ERROR; // Trả về giá trị lỗi nếu không tìm thấy khóa
}

void csv_setInt(const char *key, int value)
{
    char *keys[MAX_KEY_VALUE_LENGTH];   // Mảng để lưu các từ khóa
    char *values[MAX_KEY_VALUE_LENGTH]; // Mảng để lưu các giá trị tương ứng
    int count = 0;                      // Số lượng từ khóa và giá trị
    int found_index = -1;               // Biến để lưu chỉ số của từ khóa nếu tìm thấy

    // 1. Đọc file CSV và lưu các từ khóa và giá trị vào mảng keys và values
    FILE *file = fopen(FILE_PATH, "r");
    if (file == NULL)
    {
        printf("Lỗi mở file để đọc\n");
        Free_KeyValue(keys, values, count);
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file))
    {
        char *current_key = strtok(line, ",");
        char *current_value = strtok(NULL, "\n");

        if (current_key && current_value)
        {
            if (count >= MAX_KEY_VALUE_LENGTH)
            {
                printf("Hãy cập nhập thêm số lượng cặp key-value qua macro: MAX_KEY_VALUE_LENGTH \n");
                Free_KeyValue(keys, values, count);
                fclose(file);
                return;
            }

            // keys = realloc(keys, (count + 1) * sizeof(char *));     // Cấp phát lại bộ nhớ cho mảng keys
            // values = realloc(values, (count + 1) * sizeof(char *)); // Cấp phát lại bộ nhớ cho mảng values

            keys[count] = malloc(strlen(current_key) + 1); // +1 để chứa ký tự null
            values[count] = malloc(strlen(current_value) + 1);

            strcpy(keys[count], current_key);     // Sao chép từ khóa vào mảng keys
            strcpy(values[count], current_value); // Sao chép giá trị vào mảng values

            if (strcmp(keys[count], key) == 0)
            {
                found_index = count; // Lưu chỉ số của từ khóa nếu tìm thấy
            }

            count++; // Tăng số lượng từ khóa và giá trị
        }
    }
    if (found_index == -1)
    {
        printf("Không tìm thấy từ khóa: %s\n", key);
        fclose(file);
        return; // Nếu không tìm thấy từ khóa, không cần cập nhật
    }
    fclose(file); // Đóng file sau khi đọc xong

    // 2. Cập nhật giá trị cho từ khóa
    char strValue[12];                                                        // một số nguyên 32-bit là 12 byte = 10 giá trị + 1 ký tự null + 1 ký tự dấu trừ
    sprintf(strValue, "%d", value);                                           // Chuyển đổi giá trị số nguyên thành chuỗi
    values[found_index] = realloc(values[found_index], strlen(strValue) + 1); // Cấp phát lại bộ nhớ cho giá trị mới
    strcpy(values[found_index], strValue);

    // 3. Ghi lại toàn bộ dữ liệu vào file CSV
    file = fopen(FILE_PATH, "w");
    if (file == NULL)
    {
        printf("Lỗi mở file để ghi\n");
        Free_KeyValue(keys, values, count);
        return;
    }
    // Ghi từng từ khóa và giá trị vào file
    for (int i = 0; i < count; i++)
    {
        fprintf(file, "%s,%s\n", keys[i], values[i]);
    }
    fclose(file); // Đóng file sau khi ghi xong

    // 4. Giải phóng bộ nhớ đã cấp phát
    Free_KeyValue(keys, values, count);
}

const char *csv_getString(const char *key)
{
    FILE *file = fopen(FILE_PATH, "r");
    if (file == NULL)
    {
        printf("Lỗi mở file\n");
        return CSV_GSTR_ERROR;
    }
    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file))
    {
        char line_copy[MAX_LINE_LENGTH];
        strcpy(line_copy, line);

        char *current_key = strtok(line_copy, ",");
        char *current_value = strtok(NULL, "\n");

        if (current_key && current_value && strcmp(current_key, key) == 0)
        {
            fclose(file);
            char *str = malloc(strlen(current_value) + 1); // Cấp phát bộ nhớ cho chuỗi kết quả
            if (str == NULL)
            {
                printf("Lỗi cấp phát bộ nhớ\n");
                return CSV_GSTR_ERROR; // Trả về lỗi nếu không thể cấp phát bộ nhớ
            }
            strcpy(str, current_value); // Sao chép giá trị vào chuỗi kết quả
            return str;                 // Trả về chuỗi kết quả
        }
    }
    fclose(file);
    printf("Không tìm thấy từ khóa: %s\n", key);
    return CSV_GSTR_ERROR;
}