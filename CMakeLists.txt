cmake_minimum_required(VERSION 3.8)
project(blade)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODEL_PATH} "${blade_SOURCE_DIR}/cmake")

set(SOURCE_FILES
        include/animatedsprite.h
        include/blade.h
        include/entity.h
        include/graphics.h
        include/player.h
        include/settings.h
        include/sprite.h
        include/timer.h
        include/vector2.h
        src/animatedsprite.cpp
        src/blade.cpp
        src/entity.cpp
        src/graphics.cpp
        src/main.cpp
        src/player.cpp
        src/sprite.cpp
        src/timer.cpp
        )

add_executable(blade ${SOURCE_FILES})

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(include)
include_directories(${SDL2_INCLUDE_DIR}
                    ${SDL2_IMAGE_INCLUDE_DIR})
target_link_libraries(blade ${SDL2_LIBRARY}
                             ${SDL2_IMAGE_LIBRARIES})

