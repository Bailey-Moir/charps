#include <GLFW/glfw3.h>
#include "vector3.h"
#include <iostream>
#include <thread>
#include "window.h"

using namespace Charps;
using namespace std;

int main(void)
{
    Window window(100, 100, "test");

    window.init();

    while (!glfwWindowShouldClose(window.windowGLFW)) {
        // UPDATE
        window.update();

        // RENDER
        window.render();
    }

    glfwTerminate();
    return 0;
}