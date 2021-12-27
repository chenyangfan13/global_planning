cmake_minimum_required(VERSION 3.2.1)
project (dijkstra)

# Add project cmake modules to path.
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/cmake)

find_package(Eigen3 REQUIRED)
find_package(OpenCV REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

include(CMakeToolsHelpers OPTIONAL)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 14)

add_executable(dijkstra src/main.cpp src/dijkstra.cpp src/Node.cpp include/dijkstra.h include/Node.h)
target_link_libraries(dijkstra ${Boost_LIBRARIES} ${OpenCV_LIBS})
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${Boost_INCLUDE_DIRS}
)
