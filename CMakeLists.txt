cmake_minimum_required(VERSION 3.22.1)

project(dispatch)

set(CMAKE_BUILD_TYPE Debug)

option(ENABLE_MULTITARGET_CODE "Enable platform-dependent code" ON)
if (ENABLE_MULTITARGET_CODE)
add_definitions(-DENABLE_MULTITARGET_CODE=1)
else()
add_definitions(-DENABLE_MULTITARGET_CODE=0)
endif()

# add_compile_options(-O3 -march=native -funroll-loops -fopt-info-vec)

add_library(target ./TargetSpecific.cpp)
add_executable(normal ./normalFunctions.cpp)
add_executable(multiple ./normalMultiple.cpp)
add_executable(class  ./classMemberFunctions.cpp)

target_link_libraries(normal target)
target_link_libraries(multiple target)
target_link_libraries(class target)