cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Initialise pico_sdk from installed location
# (note this can come from environment, CMake cache etc)

# == DO NOT EDIT THE FOLLOWING LINES for the Raspberry Pi Pico VS Code Extension to work ==
if(WIN32)
    set(USERHOME $ENV{USERPROFILE})
else()
    set(USERHOME $ENV{HOME})
endif()
set(sdkVersion 2.3.0)
set(toolchainVersion 15_2_Rel1)
set(picotoolVersion 2.3.0)
set(picoVscode ${USERHOME}/.pico-sdk/cmake/pico-vscode.cmake)
if (EXISTS ${picoVscode})
    include(${picoVscode})
endif()
# ====================================================================================

set(PICO_BOARD pico2 CACHE STRING "Board type")

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(Boton C CXX ASM)

# Initialise the Raspberry Pi Pico SDK
pico_sdk_init()

# Build the reusable Boton library
add_library(Boton
    ./../src/Boton.cpp
    ./PicoHardware.cpp
)

target_include_directories(Boton
    PUBLIC
        ./../src
)

target_link_libraries(Boton
    PUBLIC
        pico_stdlib
)

# Build the example firmware
# cada ejemplo es una carpeta con un main.cpp
function(agregar_ejemplo nombre)
    add_executable(${nombre}
        ${nombre}/main.cpp
    )

    target_link_libraries(${nombre}
        Boton
        pico_stdlib
    )

    pico_set_program_name(${nombre} "${nombre}")
    pico_set_program_version(${nombre} "0.1 (2026-10-06)")

    pico_enable_stdio_uart(${nombre} 0)
    pico_enable_stdio_usb(${nombre} 1)

    pico_add_extra_outputs(${nombre})
endfunction()

agregar_ejemplo(ej00_leerBoton)
agregar_ejemplo(ej01_encenderLed)
agregar_ejemplo(ej02_alternarLed)
agregar_ejemplo(ej03_contarPulsaciones)
agregar_ejemplo(ej04_dosBotones)
