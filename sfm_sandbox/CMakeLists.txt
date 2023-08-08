cmake_minimum_required(VERSION 3.12)
project(SFMsandbox)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Find opencv
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

#Find Open3D
# Set the Open3D root directory
set(Open3D_DIR /usr/local/include/open3d/lib/cmake/Open3D CACHE PATH "Open3D root directory")
# Find Open3D package
find_package(Open3D REQUIRED)
include_directories(${Open3D_INCLUDE_DIRS})
# Set output directories for binaries and libraries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)


# Add subdirectories for each module
# add_subdirectory(frontend)
# add_subdirectory(module2)
# Add more modules as needed

# Main executable
add_executable(${PROJECT_NAME} main.cpp)

# target_include_directories(${PROJECT_NAME} PUBLIC ${OpenCV_INCLUDE_DIRS})
# Link modules and dependencies
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})


#Visualizer demo executable
add_executable(vizualizer_demo visualizer/src/visualizer_demo.cpp)
# Link Open3D libraries
target_link_libraries(vizualizer_demo PRIVATE ${Open3D_LIBRARIES})

# Add more dependencies as needed
