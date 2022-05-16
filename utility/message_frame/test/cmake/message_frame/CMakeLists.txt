cmake_minimum_required(VERSION 3.8)
project(message_frame)

set(CMAKE_CXX_STANDARD 11)

message("pwd=$ENV{PWD}")
set(M_ROOT_PATH "$ENV{PWD}/../../../..")
set(M_SOURCE_PATH "${M_ROOT_PATH}/source")
set(M_COMMON_PATH "${M_ROOT_PATH}/../common/source")

include_directories("${M_SOURCE_PATH}/mediator")
include_directories("${M_SOURCE_PATH}/message")
include_directories("${M_SOURCE_PATH}/partner")
include_directories("${M_COMMON_PATH}/concurrency")
include_directories("${M_COMMON_PATH}/common")

aux_source_directory("${M_SOURCE_PATH}/" M_SOURCE_FILES)
aux_source_directory("${M_SOURCE_PATH}/mediator" M_SOURCE_FILES)
aux_source_directory("${M_SOURCE_PATH}/message" M_SOURCE_FILES)
aux_source_directory("${M_SOURCE_PATH}/partner" M_SOURCE_FILES)
aux_source_directory("${M_COMMON_PATH}/concurrency" M_SOURCE_FILES)
aux_source_directory("${M_COMMON_PATH}/common" M_SOURCE_FILES)

set(SOURCE_FILES main.cpp;${M_SOURCE_FILES})
message("sources=${SOURCE_FILES}")

add_executable(message_frame ${SOURCE_FILES})
TARGET_LINK_LIBRARIES(message_frame pthread uuid)