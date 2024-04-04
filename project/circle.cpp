#include <GLFW/glfw3.h>
#include <cmath>

int main() {
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(800, 800, "Circle OpenGL", NULL, NULL);
    glfwMakeContextCurrent(window);
    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0f, 1.0f, 1.0f);
        glBegin(GL_LINE_LOOP);
        for (int i = 0; i < 360; i++) {
            float angle = i * 3.1415926f / 180.0f;
            glVertex2f(cosf(angle), sinf(angle));
        }
        glEnd();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}
