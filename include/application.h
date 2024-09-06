#pragma once
#include "base.h"
#include "vulkanWrapper/instance.h"

namespace FF {
    class Application {
    public:
        Application() = default;
        virtual  ~Application();

      /// \brief Run the application
      /// \return void
      void run();

     private:

      /// \brief Initialize the window
      /// \return void
      void initWindow();

      /// \brief Initialize Vulkan
      /// \return void
      void initVulkan();

      /// \brief Main loop
      /// \return void
      void mainLoop();

      /// \brief Clean up
      /// \return void
      void cleanUp();

     private:
        GLFWwindow* window_{nullptr}; ///< The window
        Wrapper::Instance::Ptr instance_{nullptr}; ///< The Vulkan instance
    };
}