cmake_minimum_required(VERSION 3.4)

project(assigment_3)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


find_package(Boost REQUIRED COMPONENTS)


FILE(GLOB SOURCE 
"src/*.cpp")

FILE(GLOB HEADER
"src/*.h")

MESSAGE(source files: "${SOURCE}")

include_directories(src)
include_directories(qvm/include)
add_executable(app ./app/app.cpp ${SOURCE} ${HEADER})
target_link_libraries (app ${CMAKE_THREAD_LIBS_INIT})