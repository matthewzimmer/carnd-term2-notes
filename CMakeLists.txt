cmake_minimum_required(VERSION 3.6)
project(term2_notes)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES scratchpad/hello_world.cpp scratchpad/hello_world.h scratchpad/Car.cpp scratchpad/Car.h)
add_executable(term2_notes ${SOURCE_FILES})

set(kalman_sources
        L5_Lidar_and_Radar_with_Kalman_Filters/5_Kalman_Filter_Equations_in_C++_Part1/KalmanFilter.cpp
        L5_Lidar_and_Radar_with_Kalman_Filters/5_Kalman_Filter_Equations_in_C++_Part1/KalmanFilter.h)

add_executable(KalmanFilter ${kalman_sources})