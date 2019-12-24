cmake_minimum_required(VERSION 3.4)
project(dummy_robot)

set(CMAKE_CXX_STANDARD 11)

# all include libraries
include_directories(include)

# Robot library
add_library(teleop_robot_lib SHARED include/RobotPosition.h src/RobotPosition.c
                        include/Teleop.h src/Teleop.c)

# Lab 3: using the robot class
# Lab 4: sensors on robot
add_executable(teleop_robot src/main.c)
target_link_libraries(teleop_robot teleop_robot_lib m)