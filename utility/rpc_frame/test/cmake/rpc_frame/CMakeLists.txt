cmake_minimum_required(VERSION 3.6)
project(rpc_frame)

set(CMAKE_CXX_STANDARD 11)

message("pwd=$ENV{PWD}")
set(M_ROOT_PATH "$ENV{PWD}/../../../..")
set(M_SOURCE_PATH "${M_ROOT_PATH}/source")
set(M_COMMON_PATH "${M_ROOT_PATH}/../common/source")

include_directories("${M_COMMON_PATH}/common")
include_directories("${M_SOURCE_PATH}/msgqueue")
include_directories("${M_SOURCE_PATH}/socket")

aux_source_directory("${M_SOURCE_PATH}/" M_SOURCE_FILES)
aux_source_directory("${M_COMMON_PATH}/common" M_SOURCE_FILES)
aux_source_directory("${M_SOURCE_PATH}/socket" M_SOURCE_FILES)

set(SOURCE_FILES main.cpp;${M_SOURCE_FILES})
message("sources=${SOURCE_FILES}")

add_subdirectory(main5)
add_subdirectory(main6)

add_executable(rpc_frame ${SOURCE_FILES})
TARGET_LINK_LIBRARIES(rpc_frame pthread uuid)