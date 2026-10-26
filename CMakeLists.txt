# =============================================================================
# CMakeLists.txt
#
#
# =============================================================================

cmake_minimum_required(VERSION 3.16)
project(solar LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# find_package(GLEW REQUIRED)
find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

add_library(solar_core STATIC
    src/core/Logger.cpp
)
target_include_directories(solar_core PUBLIC src/core)

add_executable(solar
    src/main.cpp
    src/app/Application.cpp
    src/app/AppContext.cpp
    src/app/Window.cpp

)

target_compile_options(solar PRIVATE -Wall -Wextra)
target_link_libraries(solar PRIVATE glfw OpenGL::GL ${CMAKE_DL_LIBS})
target_link_libraries(solar PRIVATE solar_core glfw OpenGL::GL ${CMAKE_DL_LIBS})
# target_link_libraries(solar PRIVATE GLEW::GLEW glfw OpenGL::GL)