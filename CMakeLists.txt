cmake_minimum_required(VERSION 3.21.3)
SET(CMAKE_CXX_COMPILER g++)

if(CMAKE_VERSION VERSION_LESS "3.26")
  set(build_local_interface "BUILD_INTERFACE")
else()
  set(build_local_interface "BUILD_LOCAL_INTERFACE")
endif()

project(ui_game)

include(FindPackageHandleStandardArgs)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

# TODO: temp hack for linux
if(NOT UNIX)
  find_package(GLM REQUIRED)
endif()

add_subdirectory(external/submodules/sdl)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/src
  ${CMAKE_CURRENT_SOURCE_DIR}/external/submodules/sdl/include
)

SET(LINKER_FLAGS "-Wall")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${LINKER_FLAGS}")

set(EXTERNAL_SOURCE
  ${CMAKE_CURRENT_SOURCE_DIR}/external/stb_image/stb_image.cpp
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

target_link_libraries(app PRIVATE
  SDL3::SDL3-shared
  ${OPENGL_LIBRARIES}
  ${GLEW_LIBRARIES}
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
