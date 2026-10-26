# =============================================================================
# CMakeLists.txt
#
#
# =============================================================================

cmake_minimum_required(VERSION 3.16)
project(solar LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(solar
    SolarSim.cpp
    Logger.cpp
)

target_compile_options(solar PRIVATE -Wall -Wextra)
target_link_libraries(solar PRIVATE glfw OpenGL::GL ${CMAKE_DL_LIBS})