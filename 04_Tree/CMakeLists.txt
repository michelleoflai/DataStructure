cmake_minimum_required(VERSION 3.20.0)

project(TREE)

set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

include_directories(${PROJECT_SOURCE_DIR}/include)

aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC_SUB)

aux_source_directory(${PROJECT_SOURCE_DIR} SRC_CUR)

add_executable(tree_exe ${SRC_SUB} ${SRC_CUR})