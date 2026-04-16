cmake_minimum_required(VERSION 3.12)

# Configure the project
project(game_of_life)

# C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Export compile commands in json format for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find ncurses library
find_package(Curses REQUIRED)

# Project sources
set(PROJECT_SOURCES
    main.cpp
    playing_field.cpp
)

# Create executable
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

# Compile options
set(GLOBAL_COMPILE_OPTION
    -O2
    -Wall
    -Wextra
    -Wshadow
    -Wpedantic
    -Wno-unused-parameter
)

target_compile_options(
    ${PROJECT_NAME} PRIVATE
    ${GLOBAL_COMPILE_OPTION}
)

# Include directories
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

# Link libraries
target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})