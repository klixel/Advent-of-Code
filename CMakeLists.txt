cmake_minimum_required(VERSION 3.26)
project(Advent_of_Code)

set(CMAKE_CXX_STANDARD 20)

add_executable(2023_day01 2023/day01/main.cpp)
add_executable(2023_day02 2023/day02/main.cpp)
add_executable(2023_day09 2023/day09/main.cpp)

#foreach(day RANGE 1 25)
#    if(day LESS 10)
#        set(day "0${day}")
#    endif()
#    add_executable("2023_day${day}" "2023/day${day}/main.cpp")
#endforeach()
