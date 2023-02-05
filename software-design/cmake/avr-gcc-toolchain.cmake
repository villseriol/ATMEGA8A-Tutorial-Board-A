set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR avr)
set(CMAKE_CROSSCOMPILING 1)

find_program(AVR_CC avr-gcc)
find_program(AVR_CXX avr-g++)
find_program(AVR_OBJCOPY avr-objcopy)
find_program(AVR_SIZE_TOOL avr-size)
find_program(AVR_OBJDUMP avr-objdump)
find_program(AVR_RANLIB avr-ranlib)
find_program(AVR_STRIP avr-strip)
find_program(AVR_NM avr-nm)
find_program(AVR_LD avr-ld)
find_program(AVR_AR avr-ar)

if (NOT AVR_CC)
    message(FATAL_ERROR "avr-gcc not found")
endif()

if (NOT AVR_CXX)
    message(FATAL_ERROR "avr-g++ not found")
endif()

if (NOT AVR_OBJCOPY)
    message(FATAL_ERROR "avr-objcopy not found")
endif()

if (NOT AVR_SIZE_TOOL)
    message(FATAL_ERROR "avr-size not found")
endif()

if (NOT AVR_OBJDUMP)
    message(FATAL_ERROR "avr-objdump not found")
endif()

if (NOT AVR_RANLIB)
    message(FATAL_ERROR "avr-ranlib not found")
endif()

if (NOT AVR_STRIP)
    message(FATAL_ERROR "avr-strip not found")
endif()

if (NOT AVR_NM)
    message(FATAL_ERROR "avr-nm not found")
endif()

if (NOT AVR_LD)
    message(FATAL_ERROR "avr-ld not found")
endif()

if (NOT AVR_AR)
    message(FATAL_ERROR "avr-ar not found")
endif()

# Set the compiler options
set(CMAKE_C_COMPILER ${AVR_CC})
set(CMAKE_CXX_COMPILER ${AVR_CXX})
set(CMAKE_OBJCOPY ${AVR_OBJCOPY})
set(CMAKE_SIZE_TOOL ${AVR_SIZE_TOOL})
set(CMAKE_OBJDUMP ${AVR_OBJDUMP})
set(CMAKE_RANLIB ${AVR_RANLIB})
set(CMAKE_STRIP ${AVR_STRIP})
set(CMAKE_NM ${AVR_NM})
set(CMAKE_LD ${AVR_LD})
set(CMAKE_AR ${AVR_AR})