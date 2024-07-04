cmake_minimum_required(VERSION 3.26)
project(Driving_school_reservation_system)

set(CMAKE_CXX_STANDARD 17)

add_executable(Driving_school_reservation_system main.cpp)

add_executable(student serve/student.cpp)
add_executable(manager serve/manager.cpp)
add_executable(coach serve/coach.cpp)
add_executable(globalFun serve/globalFun.cpp)
add_executable(orderFile serve/orderFile.cpp)