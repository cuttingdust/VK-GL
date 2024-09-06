#include "application.h"

constexpr int WIDTH = 800;
constexpr int HEIGHT = 600;

FF::Application::~Application() {

}
void FF::Application::initVulkan() {

}
void FF::Application::initWindow() {
  glfwInit();

  /// 设置环境, 关闭OpenGL API 并且禁止窗口改变大小
  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  window_ = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
  if (!window_)
  {
    std::cerr << "Failed to create window!" << std::endl;
    throw std::runtime_error("Failed to create window!");
  }
}
void FF::Application::mainLoop() {
  while (!glfwWindowShouldClose(window_))
  {
    glfwPollEvents();
  }
}
void FF::Application::cleanUp() {
  glfwDestroyWindow(window_);
  glfwTerminate();
}
void FF::Application::run() {
  initWindow();
  initVulkan();
  mainLoop();
  cleanUp();
}
