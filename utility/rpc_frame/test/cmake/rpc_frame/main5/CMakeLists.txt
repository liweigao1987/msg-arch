cmake_minimum_required(VERSION 3.6)
project(main5)

set(CMAKE_CXX_STANDARD 11)

message("pwd=$ENV{PWD}")
set(M_ROOT_PATH "$ENV{PWD}/../../../..")
set(M_SOURCE_PATH "${M_ROOT_PATH}/source")
set(M_COMMON_PATH "${M_ROOT_PATH}/../common/source")

set(SOURCE_FILES main5.cpp)
message("sources=${SOURCE_FILES}")

add_executable(main5 ${SOURCE_FILES})


