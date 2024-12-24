#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main() {
    // 初始化GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // 创建GLFW窗口
    GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL App", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // 将窗口上下文设置为当前
    glfwMakeContextCurrent(window);

    // 初始化GLEW
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    // 渲染循环
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        // 渲染代码（例如，设置颜色）
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // 设置为蓝色背景

        // 交换缓冲区并处理事件
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}