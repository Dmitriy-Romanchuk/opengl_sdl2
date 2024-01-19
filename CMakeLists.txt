cmake_minimum_required(VERSION 3.21.3)
SET(CMAKE_CXX_COMPILER g++)

project(ui_game)

find_package(SDL2 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(GLM REQUIRED)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    #${SDL2_INCLUDE_DIRS}
    #${OPENGL_INCLUDE_DIRS}
    #${GLEW_INCLUDE_DIRS}
    
)

SET(LINKER_FLAGS "-lmingw32 -lSDL2main -lSDL2")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${LINKER_FLAGS}")

set(SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/CApp.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/CApp_OnInit.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/CApp_OnEvent.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/CApp_OnLoop.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/CApp_OnRender.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/CApp_OnCleanup.cpp
)

add_executable(app ${SOURCE})
target_link_libraries(app ${SDL2_LIBRARIES})
target_link_libraries(app ${OPENGL_LIBRARIES})
target_link_libraries(app ${GLEW_LIBRARIES})
target_link_libraries(app ${GLM_LIBRARIES})
