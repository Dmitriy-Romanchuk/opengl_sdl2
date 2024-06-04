cmake_minimum_required(VERSION 3.21.3)
SET(CMAKE_CXX_COMPILER g++)

project(arcanoid)

find_package(OpenGL REQUIRED)
find_package(GLM REQUIRED)

add_subdirectory(external/submodules/SDL)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src  
    ${CMAKE_CURRENT_SOURCE_DIR}/external/submodules/sdl/include 
    ${CMAKE_CURRENT_SOURCE_DIR}/external/glad/include/glad
)

SET(LINKER_FLAGS "-Wall -lmingw32")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${LINKER_FLAGS}")

set(EXTERNAL_SOURCE
  ${CMAKE_CURRENT_SOURCE_DIR}/external/stb_image/stb_image.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/external/glad/src/glad.c
)

set(SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/MainWindow.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Application.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/RenderDevice/RenderDevice.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Pages/GamePage.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/GameObjects/Player.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/GameObjects/Sprite.cpp
)

add_executable(app
  ${EXTERNAL_SOURCE}
  ${SOURCE}
)

# copy dll in the same directory as executable
add_custom_command(TARGET app POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_CURRENT_SOURCE_DIR}/.build/external/submodules/SDL/SDL2d.dll"
        $<TARGET_FILE_DIR:app>)

target_link_libraries(app PRIVATE
  SDL2::SDL2main
  SDL2::SDL2
  ${OPENGL_LIBRARIES}
  ${GLM_LIBRARIES}
)

target_include_directories(app PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/src
)

list(APPEND RESOURCE
  ${CMAKE_CURRENT_SOURCE_DIR}/shaders/frag.glsl
  ${CMAKE_CURRENT_SOURCE_DIR}/shaders/vert.glsl
  ${CMAKE_CURRENT_SOURCE_DIR}/container.jpg
)

