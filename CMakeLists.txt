# =============================================================================
# CMakeLists.txt
#
# Build system for the SolarSim project
# =============================================================================

###############################################################################
# Project Setup
###############################################################################
cmake_minimum_required(VERSION 3.16)
project(solar LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

###############################################################################
# External Dependencies
###############################################################################
find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

###############################################################################
# Util Library Compiled Separately
###############################################################################
add_library(solar_utils STATIC
    src/utils/Logger.cpp
)
target_include_directories(solar_utils PUBLIC src/utils)

###############################################################################
# Define Executable
###############################################################################
add_executable(solar
    src/main.cpp
    src/core/Application.cpp
    src/core/Window.cpp
    src/render/HelloTriangle.cpp
)

###############################################################################
# Compiler Options
###############################################################################
target_compile_options(solar PRIVATE -Wall -Wextra)

###############################################################################
# Link Libraries to Executable
###############################################################################
target_link_libraries(solar PRIVATE
    solar_utils
    GLEW::GLEW
    glfw
    OpenGL::GL
    ${CMAKE_DL_LIBS}
)