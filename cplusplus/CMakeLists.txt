cmake_minimum_required(VERSION 3.15)
project(splicedlist)

# Define C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find Python
find_package(Python 3.10 COMPONENTS Interpreter Development REQUIRED)

# Find pybind11
find_package(pybind11 REQUIRED)

# Add the main library
add_library(splicedlist_lib splicedList.cpp)

# Create the Python module
pybind11_add_module(splicedList splicedList_pybind.cpp)

# Link the main library to the Python module
target_link_libraries(splicedList PRIVATE splicedlist_lib)

# Include directories
target_include_directories(splicedlist_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(splicedList PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})