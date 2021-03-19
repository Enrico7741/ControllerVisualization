#---------------------------------------------------------------------------------------------------
# Cross-Platform Controller Input Visualization
# Copyright (C) 2021 Enrico Schörnick
# Licensed under the MIT License
# Base file created by Jeff Preshing and released without restrictions
# CMakeDemo: https://github.com/preshing/CMakeDemo
#---------------------------------------------------------------------------------------------------

## Root CMakeLists.txt
cmake_minimum_required(VERSION 3.14)

project(visualization
    VERSION 1.0
    DESCRIPTION "Cross-Platform Controller Input Visualization"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find SDL2
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
find_package(SDL2 REQUIRED COMPONENTS main)

# Create lib
file(GLOB_RECURSE source_list "${PROJECT_SOURCE_DIR}/src/*.cpp")
add_library(visualization_lib STATIC ${source_list})
target_include_directories(visualization_lib PUBLIC ${SDL2_INCLUDE_DIRS} ${SDL2main_INCLUDE_DIRS} include)
target_link_libraries(visualization_lib ${SDL2_LIBS})

# Create executable target
add_executable(visualization Main.cpp)
target_link_libraries(visualization visualization_lib)

# Copy SDL2 DLLs to output folder on Windows
if(WIN32)
    foreach(DLL ${SDL2_DLLS})
        add_custom_command(TARGET visualization POST_BUILD COMMAND
            ${CMAKE_COMMAND} -E copy_if_different ${DLL} $<TARGET_FILE_DIR:visualization>)
    endforeach()
endif()

add_compile_options(
  "-Wall" 
  "-Wpedantic" 
  "-Wextra" 
  "-fexceptions"
  "$<$<CONFIG:DEBUG>:-O0;-g3;-ggdb>"
  "$<$<CONFIG:RELEASE>:-O3>"
)