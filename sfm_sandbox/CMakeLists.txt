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

# Main executable
add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

add_library(dataloader SHARED
    #dataloader
    ${CMAKE_CURRENT_SOURCE_DIR}/src/dataloader/dataLoader.cpp
)

target_include_directories(dataloader PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/dataloader
    ${CMAKE_CURRENT_SOURCE_DIR}/include/shared
)

add_library(shared SHARED
    #shared
    ${CMAKE_CURRENT_SOURCE_DIR}/src/shared/camera.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/shared/frame.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/shared/image.cpp
)

target_include_directories(shared PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include/shared
)

# Add includes
target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/dataloader
    ${CMAKE_CURRENT_SOURCE_DIR}/include/shared
)

# target_include_directories(${PROJECT_NAME} PUBLIC ${OpenCV_INCLUDE_DIRS})
# Link modules and dependencies
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} dataloader shared)


#Visualizer demo executable
add_executable(vizualizer_demo ${CMAKE_CURRENT_SOURCE_DIR}/src/visualizer_demo.cpp)
# Link Open3D libraries
target_link_libraries(vizualizer_demo PRIVATE ${Open3D_LIBRARIES})

# Add more dependencies as needed
