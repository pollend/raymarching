cmake_minimum_required(VERSION 3.4)

project(assigment_3)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


#########################################################
# FIND BOOST
#########################################################
find_package(Boost REQUIRED COMPONENTS)
#########################################################
# FIND GLUT
#########################################################
find_package(GLUT REQUIRED)
include_directories(${GLUT_INCLUDE_DIRS})
link_directories(${GLUT_LIBRARY_DIRS})
add_definitions(${GLUT_DEFINITIONS})
if(NOT GLUT_FOUND)
    message(ERROR " GLUT not found!")
endif(NOT GLUT_FOUND)
#########################################################
# FIND OPENGL
#########################################################
find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})
if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)

#########################################################
# FIND GLEW
#########################################################
find_package(GLEW REQUIRED)
link_libraries(${GLEW_LIBRARIES})
if (NOT GLEW_FOUND)
    message(ERROR " GLEW not found!")
endif()
#########################################################
# Include Files
#########################################################

include_directories(${GLEW_INCLUDE_DIRS})
include_directories(src)
include_directories(qvm/include)

FILE(GLOB SOURCE 
"src/*.cpp")

FILE(GLOB HEADER
"src/*.h")

MESSAGE(source files: "${SOURCE}")

add_executable(app ./app/app.cpp ${SOURCE} ${HEADER} src/Shaders/Program.cpp src/Shaders/Program.h src/Shaders/Source.cpp src/Shaders/Source.h)
target_link_libraries (app ${CMAKE_THREAD_LIBS_INIT})