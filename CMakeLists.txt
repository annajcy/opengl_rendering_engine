cmake_minimum_required(VERSION 3.10)

project(OpenGLApp)

# 设置C++标准
set(CMAKE_CXX_STANDARD 17)

# 查找OpenGL和GLEW库
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

# 使用pkg-config查找GLFW
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW REQUIRED glfw3)

# 设置源文件
add_executable(OpenGLApp main.cpp)

# 链接OpenGL、GLEW和GLFW库
target_link_libraries(OpenGLApp OpenGL::GL GLEW::GLEW ${GLFW_LIBRARIES})

# 添加GLFW的头文件路径
target_include_directories(OpenGLApp PRIVATE ${GLFW_INCLUDE_DIRS})