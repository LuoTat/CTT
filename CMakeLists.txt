# 设置 CMake 的最低版本
cmake_minimum_required(VERSION 3.30)

# 设置工程名称和版本
project(CTT VERSION 1.0.0 LANGUAGES CXX)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 23)

# 设置编译器的参数
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -Werror")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -Wextra -Werror")

# 设置默认编译类型
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
    message(STATUS "未指定编译类型,设置默认编译类型:Release")
endif ()

# 显示编译信息
message(STATUS "Build type:               ${CMAKE_BUILD_TYPE}")

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "CXX编译器参数:              ${CMAKE_CXX_FLAGS_DEBUG}")
elseif (CMAKE_BUILD_TYPE STREQUAL "Release")
    message(STATUS "CXX编译器参数:              ${CMAKE_CXX_FLAGS_RELEASE}")
endif ()

add_executable(Main main.cxx token.cxx lexer.cxx)

add_executable(DFAtran dfa_tran.cxx)
