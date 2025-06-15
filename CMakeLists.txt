cmake_minimum_required(VERSION 3.12)
project(MetricsLib CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(metrics_programm
    VKInterSummerFall2025/collection.cpp
    VKInterSummerFall2025/filewriting.cpp
    VKInterSummerFall2025/metrics.h
    VKInterSummerFall2025/collection.h
    VKInterSummerFall2025/filewriting.h
    VKInterSummerFall2025/Source.cpp)

target_include_directories(metrics_programm PRIVATE VKInterSummerFall2025)