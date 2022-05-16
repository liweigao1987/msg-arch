cmake_minimum_required(VERSION 3.6)
project(main3)

set(CMAKE_CXX_STANDARD 11)

message("pwd=$ENV{PWD}")
set(M_ROOT_PATH "$ENV{PWD}/../../../..")
set(M_SOURCE_PATH "${M_ROOT_PATH}/source")
set(M_COMMON_PATH "${M_ROOT_PATH}/../common/source")

include_directories("${M_SOURCE_PATH}/msgqueue")

aux_source_directory("${M_SOURCE_PATH}/msgqueue" M_SOURCE_FILES)

set(SOURCE_FILES main3.cpp)
message("sources=${SOURCE_FILES}")

add_executable(main3 ${SOURCE_FILES})


