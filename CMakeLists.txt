cmake_minimum_required(VERSION 3.3)
project(test_eigen)

## Set C++ standard for the whole project
set(CMAKE_CXX_STANDARD 11)

find_package(Threads REQUIRED)

set(CMAKE_BINARY_DIR ${PROJECT_SOURCE_DIR}/build)
set(CMAKE_CURRENT_BINARY_DIR ${CMAKE_BINARY_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

# external dependencies
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/external)

# Location where external projects will be downloaded
set (DOWNLOAD_LOCATION ${CMAKE_CURRENT_BINARY_DIR}/downloads
    CACHE PATH "Location where external projects will be downloaded.")
mark_as_advanced(DOWNLOAD_LOCATION)

include(eigen)

set(dml_EXTERNAL_DEPENDENCIES eigen)

set(DML_INCLUDE_LIST ${PROJECT_SOURCE_DIR}/include ${EIGEN_INCLUDE_DIRS})

file(GLOB SRCS "src/*.cpp")

set(COMMON_SRCS ${SRCS})

include_directories(${DML_INCLUDE_LIST})

macro(add_dml_executable NAME)
  message("add_executable(${NAME} ${ARGN})")
  add_executable(${NAME} ${ARGN})
  target_link_libraries(${NAME} ${dml_EXTERNAL_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
  add_dependencies(${NAME} ${dml_EXTERNAL_DEPENDENCIES})
  requires_eigen(${NAME})
endmacro(add_dml_executable)

add_dml_executable(main ${COMMON_SRCS})
