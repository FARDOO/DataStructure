cmake_minimum_required(VERSION 3.22)
project(DataStructure)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../")

add_compile_options(-Wall -Werror -Wconversion)

include_directories(include)

set(SOURCE_FILES
        include/circular_list.hpp
        include/node.hpp
        include/queue.hpp
)

add_executable(DataStructure
        ${SOURCE_FILES}
        main.cpp
)

