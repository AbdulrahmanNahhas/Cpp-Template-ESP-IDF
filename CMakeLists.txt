#  This line specifies the minimum version of CMake that is required to build the project.
cmake_minimum_required(VERSION 3.16) # should be more then 3.8!!

set(CMAKE_CXX_STANDARED 17)
set(EXTRA_COMPONENT_DIRS core apps)
include_directories(
  core
  apps
)

# This line includes the project.cmake file from the ESP-IDF tools directory.
# This file provides macros and functions for building ESP-IDF projects.
include($ENV{IDF_PATH}/tools/cmake/project.cmake)

# This line defines the project name.
project(LEARNING)












# ----------------------------------------------------------------------------------- #
#                                                                                     #
#                     For more information about build system see                     #
#  https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html #
#                                                                                     #
# ----------------------------------------------------------------------------------- #