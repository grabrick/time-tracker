cmake_minimum_required(VERSION 3.10)
project(timer)

set(CMAKE_CXX_STANDARD 14)

find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

add_executable(timer src/GUI/mainframe.cpp
        src/GUI/settings/settings.cpp
        src/GUI/settings/settings.hpp
        src/GUI/UI/roundedPanel/roundedPanel.cpp
        src/GUI/UI/roundedPanel/roundedPanel.hpp)
target_link_libraries(timer ${wxWidgets_LIBRARIES})
