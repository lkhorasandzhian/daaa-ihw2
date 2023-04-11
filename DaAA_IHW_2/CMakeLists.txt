cmake_minimum_required(VERSION 3.25)
project(DaAA_IHW_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(DaAA_IHW_2 main.cpp
        library/searching_algorithms.cpp library/searching_algorithms.h
        library/text_generator.cpp library/text_generator.h
        library/result_file_recorder.cpp library/result_file_recorder.h library/test.cpp library/test.h library/unit_test.cpp library/unit_test.h library/elementary_counter.cpp library/elementary_counter.h)
