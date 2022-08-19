#include <GLFW/glfw3.h>
#include "vector3.h"
#include "window.h"

using namespace Charps;

int main(void)
{
    Window window(100, 100, "test");
    window.init();

    while (!glfwWindowShouldClose(window.windowGLFW)) {
        std::cout << window.input.getAxisValue("vertical");
        // UPDATE
        window.update();
        //if (window.input.keyPressed(GLFW_KEY_GRAVE_ACCENT)) std::cout << "#";

        // RENDER
        window.render();
    }

    glfwTerminate();
    return 0;
}