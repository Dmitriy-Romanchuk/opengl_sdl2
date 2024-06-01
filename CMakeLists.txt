cmake_minimum_required(VERSION 3.21.3)
SET(CMAKE_CXX_COMPILER g++)

project(ui_game)

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLM REQUIRED)


include(FindPackageHandleStandardArgs)


include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src    
)

SET(LINKER_FLAGS "-Wall -lmingw32 -lSDL2main -lSDL2")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${LINKER_FLAGS}")

set(SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/MainWindow.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Application.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/RenderDevice/RenderDevice.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Pages/GamePage.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/GameObjects/Player.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/GameObjects/Sprite.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/stb_image.cpp
)

add_executable(app ${SOURCE})
target_link_libraries(app ${SDL2_LIBRARIES})
target_link_libraries(app ${OPENGL_LIBRARIES})
target_link_libraries(app ${GLEW_LIBRARIES})
target_link_libraries(app ${GLM_LIBRARIES})

list(APPEND RESOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/shaders/frag.glsl
    ${CMAKE_CURRENT_SOURCE_DIR}/shaders/vert.glsl
    ${CMAKE_CURRENT_SOURCE_DIR}/container.jpg
)

