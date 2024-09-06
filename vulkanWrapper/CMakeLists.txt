cmake_minimum_required(VERSION 3.12)
project(vulkanWrapper)

aux_source_directory(./ SRC)
file(GLOB_RECURSE INCLUDE ./*.h)

add_library(${PROJECT_NAME} ${INCLUDE} ${SRC})
