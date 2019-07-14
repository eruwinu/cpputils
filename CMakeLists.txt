cmake_minimum_required(VERSION 3.14)
project(functional_cpp)

# PROD

set(SOURCES
    index.cpp
)

add_library(${PROJECT_NAME} /dev/null)
target_sources(${PROJECT_NAME}
    PRIVATE
        ${SOURCES}
)
target_compile_options(${PROJECT_NAME}
    PRIVATE
        -std=c++14
        -O3
        -Wall -Werror
)

add_library(${PROJECT_NAME}_dbg /dev/null)
target_sources(${PROJECT_NAME}_dbg
    PRIVATE
        ${SOURCES}
)
target_compile_options(${PROJECT_NAME}
    PRIVATE
        -std=c++14
        -ggdb3
        -Wall -Werror
        -fsanitize=address
)

# TEST

enable_testing()
find_package(GTest REQUIRED)

set(TEST_SOURCES
    tests.cpp
)

add_executable(${PROJECT_NAME}_tests /dev/null)
target_sources(${PROJECT_NAME}_tests
    PRIVATE
        ${TEST_SOURCES}
)
target_include_directories(${PROJECT_NAME}_tests
    PRIVATE
        ${GTEST_INCLUDE_DIRS}
)
target_compile_options(${PROJECT_NAME}_tests
    PRIVATE
        -std=c++14
        -ggdb3
        -Wall -Werror
        -fsanitize=address
)
target_link_libraries(${PROJECT_NAME}_tests
    ${PROJECT_NAME}_dbg
    ${GTEST_LIBRARIES}
    gtest_main
)
target_link_options(${PROJECT_NAME}_tests
    PRIVATE
        -fsanitize=address
)