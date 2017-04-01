cmake_minimum_required(VERSION 3.6)
project(term2_notes)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES scratchpad/hello_world.cpp scratchpad/hello_world.h scratchpad/Car.cpp scratchpad/Car.h)
add_executable(term2_notes ${SOURCE_FILES})

set(kalman_sources
        L5_Lidar_and_Radar_with_Kalman_Filters/5_Kalman_Filter_Equations_in_C++_Part1/KalmanFilter.cpp
        L5_Lidar_and_Radar_with_Kalman_Filters/5_Kalman_Filter_Equations_in_C++_Part1/KalmanFilter.h)

add_executable(KalmanFilter ${kalman_sources})


file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/L5_Lidar_and_Radar_with_Kalman_Filters/11_Laser_Measurements_Part_3/obj_pose-laser-radar-synthetic-input.txt
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(11_Laser_Measurements_Part_3
        L5_Lidar_and_Radar_with_Kalman_Filters/11_Laser_Measurements_Part_3/main.cpp
        L5_Lidar_and_Radar_with_Kalman_Filters/11_Laser_Measurements_Part_3/main.h
        L5_Lidar_and_Radar_with_Kalman_Filters/11_Laser_Measurements_Part_3/ground_truth_package.h
        L5_Lidar_and_Radar_with_Kalman_Filters/11_Laser_Measurements_Part_3/measurement_package.h
        L5_Lidar_and_Radar_with_Kalman_Filters/11_Laser_Measurements_Part_3/tracking.h
        L5_Lidar_and_Radar_with_Kalman_Filters/11_Laser_Measurements_Part_3/tracking.cpp
        L5_Lidar_and_Radar_with_Kalman_Filters/11_Laser_Measurements_Part_3/kalman_filter.h
        L5_Lidar_and_Radar_with_Kalman_Filters/11_Laser_Measurements_Part_3/kalman_filter.cpp)

add_executable(16_Jacobian_Matrix_Part_1
        L5_Lidar_and_Radar_with_Kalman_Filters/16_Jacobian_Matrix_Part_1/main.cpp
        L5_Lidar_and_Radar_with_Kalman_Filters/16_Jacobian_Matrix_Part_1/main.h)

add_executable(20_Evalating_KF_Performance_Part_1 L5_Lidar_and_Radar_with_Kalman_Filters/20_Evalating_KF_Performance_Part_1/main.cpp L5_Lidar_and_Radar_with_Kalman_Filters/20_Evalating_KF_Performance_Part_1/main.h)

add_executable(14_Generating_Sigma_Points_Assignment_1 L7_Unscented_Kalman_Filters/14_Generating_Sigma_Points_Assignment_1/main.cpp L7_Unscented_Kalman_Filters/14_Generating_Sigma_Points_Assignment_1/ukf.cpp L7_Unscented_Kalman_Filters/14_Generating_Sigma_Points_Assignment_1/ukf.h)

add_executable(17_Augmentation_Assignment_1 L7_Unscented_Kalman_Filters/17_Augmentation_Assignment_1/main.cpp L7_Unscented_Kalman_Filters/17_Augmentation_Assignment_1/ukf.h L7_Unscented_Kalman_Filters/17_Augmentation_Assignment_1/ukf.cpp)

add_executable(20_Sigma_Point_Prediction_Assignment_1 L7_Unscented_Kalman_Filters/20_Sigma_Point_Prediction_Assignment_1/ukf.cpp L7_Unscented_Kalman_Filters/20_Sigma_Point_Prediction_Assignment_1/ukf.h L7_Unscented_Kalman_Filters/20_Sigma_Point_Prediction_Assignment_1/main.cpp)

add_executable(23_Predicted_Mean_and_Covariance_Assignment_1 L7_Unscented_Kalman_Filters/23_Predicted_Mean_and_Covariance_Assignment_1/main.cpp L7_Unscented_Kalman_Filters/23_Predicted_Mean_and_Covariance_Assignment_1/ukf.cpp L7_Unscented_Kalman_Filters/23_Predicted_Mean_and_Covariance_Assignment_1/ukf.h)