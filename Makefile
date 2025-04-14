# Compiler and tools
CC      = arm-none-eabi-gcc
LD      = arm-none-eabi-ld
AS      = arm-none-eabi-as
OBJCOPY = arm-none-eabi-objcopy
OBJDUMP = arm-none-eabi-objdump
SIZE    = arm-none-eabi-size

# Project name
TARGET = stm32wl55_app

# Paths
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build

# Source files
SRCS = $(wildcard *.c) $(wildcard $(SRC_DIR)/*.c)
ASMS = startup.s

# Object files
OBJS = $(SRCS:.c=.o) $(ASMS:.s=.o)

# Flags
CFLAGS = -mcpu=cortex-m4 -mthumb -Wall -O0 -g3 -I$(INC_DIR)
LDFLAGS = -Tlinker.ld -nostartfiles
ASFLAGS = -mcpu=cortex-m4 -mthumb

# Default target
all: $(TARGET).elf $(TARGET).bin

# Link
$(TARGET).elf: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^
	$(SIZE) $@

# Assembly
%.o: %.s
	$(CC) $(ASFLAGS) -c $< -o $@

# Compile C
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Binary and hex
%.bin: %.elf
	$(OBJCOPY) -O binary $< $@

%.hex: %.elf
	$(OBJCOPY) -O ihex $< $@

# Clean
clean:
	rm -f *.o $(SRC_DIR)/*.o *.elf *.bin *.hex

.PHONY: all clean

