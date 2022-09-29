cmake_minimum_required(VERSION 3.1.0)
project(toyRobot_test VERSION 0.1.0)

add_subdirectory(googletest)

add_executable(${PROJECT_NAME} test_robot.cpp)
target_include_directories(toyRobot_test
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/../include
)
target_link_libraries(${PROJECT_NAME}
    robot
    gtest_main)
#add_test(NAME example_test COMMAND example)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
