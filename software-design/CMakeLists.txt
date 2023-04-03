cmake_minimum_required(VERSION 3.10)
project(atmega8a-evaluation-board)

include(cmake/atmega-8a-device.cmake)

######################################################################
######################################################################
find_program(AVRDUDE avrdude)
set(AVRDUDE_ARGS -e -v -p ${DEVICE} -c usbasp)

set(CMAKE_ASM_FLAGS "-x assembler-with-cpp ${CFLAGS}")
set(CMAKE_C_STANDARD 99)

add_compile_options(-Wall -Os)

add_executable(main src/main.cpp)
set_target_properties(
   main
   PROPERTIES
   OUTPUT_NAME main.elf
   COMPILE_FLAGS "-DF_CPU=${CLOCK} -mmcu=${DEVICE}"
)

execute_process(
   COMMAND ${AVR_OBJCOPY} -j .text -j .data -O ihex main.elf main.hex
   COMMAND ${AVR_SIZE_TOOL} -d main.elf
   WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

add_custom_target(
   flash
   COMMAND ${AVRDUDE} ${AVRDUDE_ARGS} -u -U flash:w:main.hex:i
   WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

# add_custom_target(
#    fuse
#    COMMAND ${AVRDUDE_ARGS} -U lfuse:w:${L_FUSE}:m -U hfuse:w:${H_FUSE}:m
#    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
# )

add_custom_target(
   disassemble
   COMMAND ${AVR_OBJDUMP} -d -S main.elf
   WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)