cmake_minimum_required(VERSION 3.21.3)
set(CMAKE_CXX_COMPILER g++)

project(arcanoid)

find_package(OpenGL REQUIRED)

set(EXTERNAL_LIBRARIES)
set(EXTERNAL_SOURCE)
# ${CMAKE_CURRENT_SOURCE_DIR}/external/stb_image/stb_image.cpp

add_subdirectory(${PROJECT_SOURCE_DIR}/external)

message(STATUS "EXTERNAL_LIBRARIES - ${EXTERNAL_LIBRARIES}")
message(STATUS "EXTERNAL_SOURCE - ${EXTERNAL_SOURCE}")

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/src
  ${CMAKE_CURRENT_SOURCE_DIR}/external/submodules/sdl/include
  ${CMAKE_CURRENT_SOURCE_DIR}/external/submodules/glm
  ${CMAKE_CURRENT_SOURCE_DIR}/external/glad/include/glad
)

set(LINKER_FLAGS -Wall)

if(WIN)
  list(APPEND LINKER_FLAGS
    -lmingw32
  )
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${LINKER_FLAGS}")

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
if(WIN)
  add_custom_command(TARGET app POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    "${CMAKE_CURRENT_SOURCE_DIR}/.build/external/submodules/SDL/SDL2d.dll"
    $<TARGET_FILE_DIR:app>)
endif()

target_link_libraries(app PRIVATE ${EXTERNAL_LIBRARIES}
  # glad
  # SDL2::SDL2main
  # SDL2::SDL2
)

target_include_directories(app PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/src
  ${CMAKE_CURRENT_SOURCE_DIR}/external
)

list(APPEND RESOURCE
  ${CMAKE_CURRENT_SOURCE_DIR}/shaders/frag.glsl
  ${CMAKE_CURRENT_SOURCE_DIR}/shaders/vert.glsl
  ${CMAKE_CURRENT_SOURCE_DIR}/container.jpg
)
