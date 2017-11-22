project(SnakeFML)
cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++14")

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

find_package(SFML 2 REQUIRED graphics window system audio)

find_package(XYGINEXT)

include_directories(${SFML_INCLUDE_DIR} ${XY_INCLUDE_DIR})

set(HDRS
    Snake.hpp
    Mouse.hpp
    MouseSpawner.hpp
    World.hpp
    Score.hpp
    Options.hpp
    SnakeFML.hpp
    SnakingState.hpp
    MenuState.hpp
    PausedState.hpp
)

set(SRCS
    Snake.cpp
    Mouse.cpp
    MouseSpawner.cpp
    Main.cpp
    World.cpp
    Score.cpp
    Options.cpp
    WaterEffect.frag
    SnakeFML.cpp
    SnakingState.cpp
    MenuState.cpp
    PausedState.cpp
)

add_executable("${PROJECT_NAME}" ${HDRS} ${SRCS})

target_link_libraries("${PROJECT_NAME}" ${SFML_LIBRARIES} ${XYXT_LIBRARIES})

install(TARGETS "${PROJECT_NAME}" DESTINATION ${CMAKE_INSTALL_PREFIX})
FILE(GLOB images "*.png")
INSTALL(FILES ${images} DESTINATION ${CMAKE_INSTALL_PREFIX})
install(FILES KBZipaDeeDooDah.ttf DESTINATION ${CMAKE_INSTALL_PREFIX})
install(FILES WaterEffect.frag DESTINATION ${CMAKE_INSTALL_PREFIX})
