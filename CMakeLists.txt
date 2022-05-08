cmake_minimum_required(VERSION 3.13)  # CMake version check
project(slot-machine-cpp)
set(CMAKE_CXX_STANDARD 14)            # Enable c++14 standard

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES main.cpp slot-machine.cpp slot-machine.h window.cpp window.h reel.cpp reel.h test-slot-machine.cpp test-slot-machine.h util.h)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(slot-machine-cpp ${SOURCE_FILES})