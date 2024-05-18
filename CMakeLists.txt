cmake_minimum_required(VERSION 3.27)
project(timer)

set(CMAKE_CXX_STANDARD 20)

# Найти wxWidgets
find_package(wxWidgets REQUIRED COMPONENTS core base)

# Включить библиотеки и заголовочные файлы wxWidgets
include(${wxWidgets_USE_FILE})

add_executable(
        timer GUI/window.cpp
#        GUI/window.cpp
#        GUI/window.hpp
)

# Линковка с wxWidgets
target_link_libraries(timer ${wxWidgets_LIBRARIES})


#cmake_minimum_required(VERSION 3.10)
#project(TimeTracker)
#
#set(CMAKE_CXX_STANDARD 14)
#
## Найти wxWidgets
#find_package(wxWidgets REQUIRED COMPONENTS core base)
#
## Включить библиотеки и заголовочные файлы wxWidgets
#include(${wxWidgets_USE_FILE})
#
## Указать исходные файлы вашего проекта
#add_executable(TimeTracker src/GUI/window.cpp)
#
## Линковка с wxWidgets
#target_link_libraries(TimeTracker ${wxWidgets_LIBRARIES})
