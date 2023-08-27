cmake_minimum_required(VERSION 3.24)


# install prefix
set(CMAKE_INSTALL_PREFIX "./")
# compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
#cxx set(CMAKE_CXX_STANDARD 17) set(CMAKE_CXX_STANDARD_REQUIRED ON) # compiler 
set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,AppleClang,Clang,LCC,GNU>")
set(msvc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")

add_library(compiler_flags INTERFACE)
target_compile_options(
	compiler_flags
	INTERFACE
	"$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wformat=2;-Wunused>>"
	"$<${msvc_like_cxx}:$<BUILD_INTERFACE:-W3>>"
)

project(engine VERSION 1.0.0)

add_subdirectory(engine)
add_subdirectory(sandbox)

target_link_libraries(engine PUBLIC compiler_flags)
target_link_libraries(sandbox PUBLIC compiler_flags engine)


# install
install(
	TARGETS 
		sandbox engine
	DESTINATION
		bin	
)
