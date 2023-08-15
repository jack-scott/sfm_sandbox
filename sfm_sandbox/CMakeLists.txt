cmake_minimum_required(VERSION 3.12)
project(SFMsandbox)

option(GUI "Build the gui" OFF)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -lstdc++fs")


# Set build type
set(CMAKE_BUILD_TYPE Debug)

# Find the GTest library
find_package(GTest REQUIRED)

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

find_package(GTSAM REQUIRED)
include_directories(${gtsam_INCLUDE_DIRS})


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
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} dataloader shared gtsam)

if (GUI)
    #Visualizer demo executable
    add_executable(vizualizer_demo ${CMAKE_CURRENT_SOURCE_DIR}/src/visualizer_demo.cpp)
    # Link Open3D libraries
    target_link_libraries(vizualizer_demo PRIVATE ${Open3D_LIBRARIES})
endif()

#Tests
# Add the test executable
add_executable(tests 
    ${CMAKE_CURRENT_SOURCE_DIR}/test/dataLoader_tests.cpp)

# Add includes
target_include_directories(tests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include/dataloader
    ${CMAKE_CURRENT_SOURCE_DIR}/include/shared
)

# Link the test executable with the GTest library
target_link_libraries(tests GTest::GTest GTest::Main dataloader shared gtsam ${OpenCV_LIBS})  
