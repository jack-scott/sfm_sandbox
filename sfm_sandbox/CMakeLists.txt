cmake_minimum_required(VERSION 3.12)
project(SFMsandbox)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set output directories for binaries and libraries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Include directories
include_directories(include)

# Add subdirectories for each module
add_subdirectory(frontend)
# add_subdirectory(module2)
# Add more modules as needed

# Main executable
add_executable(${PROJECT_NAME} main.cpp)

# Link modules and dependencies
target_link_libraries(${PROJECT_NAME} frontend)
# Add more dependencies as needed
