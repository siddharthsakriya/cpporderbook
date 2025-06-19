cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_STANDARD 17)

# Add include/ so headers are found
include_directories(include)

# Collect all .cpp files
file(GLOB SOURCES "src/*.cpp")

# Build main + src/*.cpp into executable
add_executable(my_project ${SOURCES} main.cpp)
