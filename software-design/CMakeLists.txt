cmake_minimum_required(VERSION 3.10)
project(atmega8a-evaluation-board)

######################################################################
######################################################################
set(CMAKE_ASM_FLAGS "-x assembler-with-cpp ${CFLAGS}")
set(CMAKE_C_STANDARD 99)

set(DEVICE "atmega8a")
set(CLOCK "16000000")
set(PROGRAMMER "-e -v -p ${DEVICE} -c arduino -P COM3 -b 19200 -D")

set(L_FUSE "0b11110111")
set(H_FUSE "0b10011001")
set(E_FUSE "0xFF")

add_compile_options(-Wall -Os)

add_executable(main src/main.cpp)
set_target_properties(
   main
   PROPERTIES
   OUTPUT_NAME main.elf
   COMPILE_FLAGS "-DF_CPU=${CLOCK} -mmcu=${DEVICE}"
)

# Tune the lines below only if you know what you are doing:

# AVRDUDE = avrdude $(PROGRAMMER) -p $(DEVICE)
# COMPILE = avr-gcc -Wall -Os -DF_CPU=$(CLOCK) -mmcu=$(DEVICE)

# # symbolic targets:
# all: main.hex

# .cpp.o:
# 	$(COMPILE) -c $< -o $@

# flash: all
# 	$(AVRDUDE) -u -U flash:w:main.hex:i

# fuse:
# 	$(AVRDUDE) -U lfuse:w:$(L_FUSE):m -U hfuse:w:$(H_FUSE):m

# clean:
# 	del main.hex main.elf main.o

# # file targets:
# main.elf: main.o
# 	$(COMPILE) -o main.elf main.o

# main.hex: main.elf
# 	avr-objcopy -j .text -j .data -O ihex main.elf main.hex
# 	avr-size -d main.elf

# disasm:	main.elf
# 	avr-objdump -d -S main.elf