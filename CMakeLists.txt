cmake_minimum_required(VERSION 3.24)
project(open-cv-exmaple)
find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )
set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp main.h)
add_executable(open-cv-example ${SOURCE_FILES}) ##CDemo2改为自己的项目名称
target_link_libraries(open-cv-example ${OpenCV_LIBS})  ##CDemo2改为自己的项目名称
