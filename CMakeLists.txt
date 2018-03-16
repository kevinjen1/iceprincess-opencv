cmake_minimum_required (VERSION 2.6)
project (IcePrincess)
find_package(OpenCV 3 REQUIRED)
set(CMAKE_CXX_STANDARD 11)

include_directories(include ${OpenCV_INCLUDE_DIRECTORIES})

add_executable (MarkerGen src/generate.cpp)
target_link_libraries(MarkerGen ${OpenCV_LIBRARIES})

add_executable (Calibration src/calibrate.cpp)
target_link_libraries(Calibration ${OpenCV_LIBRARIES})

add_executable (Detection src/detect.cpp)
target_link_libraries(Detection ${OpenCV_LIBRARIES})