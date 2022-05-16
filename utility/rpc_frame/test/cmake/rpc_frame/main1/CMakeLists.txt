cmake_minimum_required(VERSION 3.6)
project(main1)

set(CMAKE_CXX_STANDARD 11)

message("pwd=$ENV{PWD}")
set(M_ROOT_PATH "$ENV{PWD}/../../../..")
set(M_SOURCE_PATH "${M_ROOT_PATH}/source")
set(M_COMMON_PATH "${M_ROOT_PATH}/../common/source")

include_directories("${M_COMMON_PATH}/common")
include_directories("${M_SOURCE_PATH}/shared_memory")

aux_source_directory("${M_SOURCE_PATH}/" M_SOURCE_FILES)
aux_source_directory("${M_COMMON_PATH}/common" M_SOURCE_FILES)
aux_source_directory("${M_SOURCE_PATH}/shared_memory" M_SOURCE_FILES)

set(SOURCE_FILES main1.cpp;${M_SOURCE_FILES})
message("sources=${SOURCE_FILES}")

add_executable(main1 ${SOURCE_FILES})


