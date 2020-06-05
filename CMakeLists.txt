cmake_minimum_required (VERSION 3.5)

project (Compiler)
if(CMAKE_COMPILER_IS_GNUCXX)
	set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -std=c++17")
endif(CMAKE_COMPILER_IS_GNUCXX)

if (MSVC_VERSION GREATER_EQUAL "1900")
    include(CheckCXXCompilerFlag)
    CHECK_CXX_COMPILER_FLAG("/std:c++latest" _cpp_latest_flag_supported)
    if (_cpp_latest_flag_supported)
        add_compile_options("/std:c++latest")
    endif()
endif()

set (source_dir "${PROJECT_SOURCE_DIR}/src/")
set (header_dir "${PROJECT_SOURCE_DIR}/headers/")

file (GLOB source_files 
	"${source_dir}/*.cc"
	"${header_dir}/*.h"
	)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_executable (Compiler ${source_files})

