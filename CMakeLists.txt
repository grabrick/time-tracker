cmake_minimum_required(VERSION 3.27)
project(timer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/opt/homebrew/Cellar/6.7.0/macos/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(
        timer src/main.cpp
        src/GUI/timeBlock/timeBlock.cpp
        src/GUI/timeBlock/timeBlock.hpp
        src/GUI/buttonsBlock/buttonsBlock.cpp
        src/GUI/buttonsBlock/buttonsBlock.hpp
        src/GUI/buttonsBlock/buttons/buttons.cpp
        src/GUI/buttonsBlock/buttons/buttons.hpp
        src/assets/animation/animatedButton/animatedButton.cpp
        src/assets/animation/animatedButton/animatedButton.hpp
        src/GUI/historyBlock/historyBlock.cpp
        src/GUI/historyBlock/historyBlock.hpp
)

target_link_libraries(timer
        Qt::Core
        Qt::Gui
        Qt::Widgets
)