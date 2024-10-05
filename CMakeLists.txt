cmake_minimum_required(VERSION 3.22.1)

project(dispatch)

set(CMAKE_BUILD_TYPE Release)

option(ENABLE_MULTITARGET_CODE "Enable platform-dependent code" ON)
if(ENABLE_MULTITARGET_CODE)
    add_definitions(-DENABLE_MULTITARGET_CODE=1)
else()
    add_definitions(-DENABLE_MULTITARGET_CODE=0)
endif()

add_compile_options(-O3)

add_library(target ./TargetSpecific.cpp)
add_executable(normal ./normalFunctions.cpp)
add_executable(multiple ./normalMultiple.cpp)
add_executable(class ./classMemberFunctions.cpp)

target_link_libraries(normal target)
target_link_libraries(multiple target)
target_link_libraries(class target)

set(PREPROCESS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/preprocessed_dump)

file(MAKE_DIRECTORY ${PREPROCESS_DIR})

add_custom_command(
    OUTPUT ${PREPROCESS_DIR}/normalFunctions.cpp
    COMMAND ${CMAKE_CXX_COMPILER} -E -DENABLE_MULTITARGET_CODE=1 ${CMAKE_CURRENT_SOURCE_DIR}/normalFunctions.cpp -o ${PREPROCESS_DIR}/normalFunctions.cpp
    DEPENDS normal
    COMMENT "Generating preprocessed output for normalFunctions.cpp"
)

add_custom_command(
    OUTPUT ${PREPROCESS_DIR}/normalMultiple.cpp
    COMMAND ${CMAKE_CXX_COMPILER} -E -DENABLE_MULTITARGET_CODE=1 ${CMAKE_CURRENT_SOURCE_DIR}/normalMultiple.cpp -o ${PREPROCESS_DIR}/normalMultiple.cpp
    DEPENDS multiple
    COMMENT "Generating preprocessed output for normalMultiple.cpp"
)

add_custom_command(
    OUTPUT ${PREPROCESS_DIR}/classMemberFunctions.cpp
    COMMAND ${CMAKE_CXX_COMPILER} -E -DENABLE_MULTITARGET_CODE=1 ${CMAKE_CURRENT_SOURCE_DIR}/classMemberFunctions.cpp -o ${PREPROCESS_DIR}/classMemberFunctions.cpp
    DEPENDS class
    COMMENT "Generating preprocessed output for classMemberFunctions.cpp"
)

add_custom_target(preprocess ALL
    DEPENDS ${PREPROCESS_DIR}/normalFunctions.cpp
    ${PREPROCESS_DIR}/normalMultiple.cpp
    ${PREPROCESS_DIR}/classMemberFunctions.cpp
)

# cmake -DCMAKE_C_COMPILER=/usr/bin/clang -DCMAKE_CXX_COMPILER=/usr/bin/clang++ ..