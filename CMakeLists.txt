cmake_minimum_required(VERSION 3.14)

project(functional_cpp)

set(SOURCES
    main.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
target_compile_definitions(${PROJECT_NAME}
    PUBLIC
        std=c++14
)

add_executable(${PROJECT_NAME}_dbg ${SOURCES})
target_compile_definitions(${PROJECT_NAME}_dbg
    PUBLIC
        std=c++14
        ggdb3
)