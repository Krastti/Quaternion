cmake_minimum_required(VERSION 3.10)
project(Quaternion VERSION 1.0.0 LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Windows: убираем префикс "lib" у DLL и экспортируем символы
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

target_include_directories(${LIB_NAME} PUBLIC src)

target_compile_definitions(${LIB_NAME} PRIVATE QUATERNION_BUILDING_DLL)

# Линкуем math-библиотеку на Linux/macOS (на Windows она встроена в libc)
if(UNIX)
    target_link_libraries(${LIB_NAME} PRIVATE m)
endif()

add_executable(test_quaternion src/main.c)

target_link_libraries(test_quaternion PRIVATE ${LIB_NAME})

# На Linux .so ищется рядом с исполняемым файлом
# без необходимости выставлять LD_LIBRARY_PATH вручную
if(UNIX AND NOT APPLE)
    set_target_properties(test_quaternion PROPERTIES
        BUILD_RPATH "$ORIGIN"
        INSTALL_RPATH "$ORIGIN"
    )
endif()
