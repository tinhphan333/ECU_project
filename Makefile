# Tên file thực thi cuối cùng
TARGET := main

# Các thư mục chứa mã nguồn (.c)
SOURCE_DIRS := . \
			CAN_STACK \
			csvlib \
			IOHwAb \
			MCAL/Adc \
			MCAL/Can \
			MCAL/Dio \
			MCAL/Pwm 

# Các thư mục chứa file tiêu đề (.h)
HEADER_DIRS := $(SOURCE_DIRS)

# Các tệp mã nguồn và tệp object tương ứng
SOURCES := $(foreach dir,$(SOURCE_DIRS),$(wildcard $(dir)/*.c))
OBJECTS := $(SOURCES:.c=.o)

# Trình biên dịch và các cờ 
CC := gcc
CFLAGS := $(foreach dir,$(HEADER_DIRS),-I$(dir)) -Wall -Wextra 

# Quy tắc đầu tiên là quy tắc mặc định sẽ được thực thi
all: $(TARGET)

# Quy tắc biên dịch file thực thi từ các file object
$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ 

# Quy tắc biên dịch từng file .c thành file .o
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Quy tắc dọn dẹp thư mục build 
clean:
	rm -f $(OBJECTS) $(TARGET)

# Quy tắc chạy chương trình thực thi
run: $(TARGET)
	./$(TARGET)

# Quy tắc giả (phony target) để tránh xung đột với các file có cùng tên
.PHONY: all clean run




