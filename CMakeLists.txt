cmake_minimum_required(VERSION 3.10)

project(OpenGLProject)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)

# 使用 pkg-config 查找库
find_package(PkgConfig REQUIRED)

pkg_check_modules(GLFW REQUIRED glfw3)
pkg_check_modules(GLEW REQUIRED glew)

# 添加源文件
add_executable(OpenGLApp main.cpp)

# 包含目录
target_include_directories(OpenGLApp PUBLIC
        ${GLFW_INCLUDE_DIRS}
        ${GLEW_INCLUDE_DIRS}
)

# 链接库
target_link_libraries(OpenGLApp PUBLIC
        ${GLFW_LIBRARIES}
        ${GLEW_LIBRARIES}
        OpenGL::GL
)

# 链接路径（解决 macOS 上的 rpath 问题）
target_link_directories(OpenGLApp PUBLIC
        ${GLFW_LIBRARY_DIRS}
        ${GLEW_LIBRARY_DIRS}
)