#cmake最低版本要求
cmake_minimum_required(VERSION 3.28)
#项目名称
project(Moving_Ball)
#设置c++标准
set(CMAKE_CXX_STANDARD 17)

add_compile_options(/source-charset:utf-8 /execution-charset:utf-8)

#设置OpenCV路径
set(OpenCV_DIR "D:\\Tools\\OpenCV\\opencv\\build\\x64\\vc16\\lib")

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources/images/black.jpg DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/resources/images/Hands DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(Moving_Ball src/main.cpp
                src/ImageInformation.cpp
                src/ImageProcessing.cpp
                src/BallMove.cpp

)

target_link_libraries(Moving_Ball ${OpenCV_LIBS})



