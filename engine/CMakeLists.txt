file(GLOB_RECURSE ENGINE_SRC ./*/*.cpp)
add_library(engine ${ENGINE_SRC})
target_include_directories(engine PUBLIC ./ ./include)


