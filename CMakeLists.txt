cmake_minimum_required(VERSION 3.5)
project(SystemTreePlugin)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt5 components
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets)

# Find Cube (you may need to provide -DCUBE_DIR=... when running cmake)
find_package(Cube REQUIRED)

# Define the plugin as a shared module
add_library(SystemTreePlugin MODULE SystemTreePlugin.cpp)

# Link against Qt and Cube libraries
target_link_libraries(SystemTreePlugin Qt5::Core Qt5::Gui Qt5::Widgets Cube)
