#include <iostream>
#include "application.h"
#include "vulkanWrapper/instance.h"

int main() {
    FF::Application app;
    try {
        app.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}