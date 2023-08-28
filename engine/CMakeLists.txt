file(GLOB_RECURSE ENGINE_SRC ./src/*.cpp)

set(_ENGINE_ ON) 
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/config.h.in config.h)

add_library(engine ${ENGINE_SRC})


list(APPEND ENGINE_INCLUDE_DIRS "include")
list(APPEND ENGINE_INCLUDE_DIRS "vendor/spdlog/include")
list(APPEND ENGINE_INCLUDE_DIRS "${CMAKE_BINARY_DIR}/engine/")

target_include_directories(engine PRIVATE ${ENGINE_INCLUDE_DIRS})
target_include_directories(engine PUBLIC "./")


