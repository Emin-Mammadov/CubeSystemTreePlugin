cmake_minimum_required(VERSION 3.5)
project(SystemTreePlugin)

# Find Qt5 and Cube dependencies
find_package(Qt5 REQUIRED Core Gui)
find_package(Cube REQUIRED)

# Define the plugin
add_library(SystemTreePlugin MODULE SystemTreePlugin.cpp)

# Link Qt5 and Cube libraries
target_link_libraries(SystemTreePlugin Qt5::Core Qt5::Gui Cube)
