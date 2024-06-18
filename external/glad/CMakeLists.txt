cmake_minimum_required(VERSION 3.21.3)

set(GLAD_SRCS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/glad.c
)

add_library(glad STATIC ${GLAD_SRCS})
target_include_directories(glad PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(EXTERNAL_LIBRARIES ${EXTERNAL_LIBRARIES} glad PARENT_SCOPE)