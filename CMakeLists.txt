cmake_minimum_required(VERSION 3.1.0)
project(toyRobot VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 11)

include(GoogleTest)
enable_testing()

add_library(robot STATIC 
    src/robot.cpp
    src/table.cpp
    src/line_parser.cpp
)

target_include_directories(robot
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/include
)

add_executable(toyRobot main.cpp)

add_subdirectory(test)

target_link_libraries( toyRobot
    robot
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
