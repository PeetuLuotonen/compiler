cmake_minimum_required (VERSION 3.5)

project (Compiler)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++14")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")
set (header_dir "${PROJECT_SOURCE_DIR}/headers/")

file (GLOB source_files 
	"${source_dir}/*.cc"
	"${header_dir}/*.h"
	)

add_executable (Compiler ${source_files})

