cmake_minimum_required(VERSION 3.10)
project(Quaternion VERSION 1.0.0 LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

if(WIN32)
    add_definitions(-DAPI_EXPORTS)
    set(CMAKE_SHARED_LIBRARY_PREFIX "")
endif()

set(CMAKE_C_VISIBILITY_PRESET default)
set(CMAKE_VISIBILITY_INLINES_HIDDEN OFF)

set(LIB_NAME quaternion)

add_library(${LIB_NAME} SHARED
        src/quaternion/quaternion.h
        src/quaternion/quaternion.c
)

target_compile_definitions(${LIB_NAME} PRIVATE QUATERNION_BUILDING_DLL)

add_executable(test_quaternion src/main.c)

target_link_libraries(test_quaternion PRIVATE ${LIB_NAME})