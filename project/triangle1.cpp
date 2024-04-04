#include <GLFW/glfw3.h>

void drawTriangle() {
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.5f, -0.5f);  // Bottom-left vertex
    glVertex2f(0.5f, -0.5f);   // Bottom-right vertex
    glVertex2f(0.0f, 0.5f);    // Top vertex
    glEnd();
}

int main() {
    glfwInit();

    GLFWwindow* window = glfwCreateWindow(800, 600, "Triangle OpenGL", NULL, NULL);
    glfwMakeContextCurrent(window);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0f, 1.0f, 1.0f);
        drawTriangle();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
