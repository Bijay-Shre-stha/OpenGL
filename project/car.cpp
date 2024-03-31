#include <GLFW/glfw3.h>
#include <cmath>

float carPositionX = -0.8f; // Initial x-position of the car

void drawCar() {
    // Draw body
    glColor3f(0.5, 0.5, 0.5); // Gray
    glBegin(GL_POLYGON);
    glVertex2f(carPositionX - 0.2, -0.3);
    glVertex2f(carPositionX + 0.2, -0.3);
    glVertex2f(carPositionX + 0.4, -0.6);
    glVertex2f(carPositionX - 0.4, -0.6);
    glEnd();

    // Draw windows
    glColor3f(0.7, 0.7, 1.0); // Light blue
    glBegin(GL_POLYGON);
    glVertex2f(carPositionX - 0.1, -0.2);
    glVertex2f(carPositionX + 0.1, -0.2);
    glVertex2f(carPositionX + 0.3, -0.5);
    glVertex2f(carPositionX - 0.3, -0.5);
    glEnd();

    // Draw wheels
    glColor3f(0.1, 0.1, 0.1); // Dark gray
    const float wheelRadius = 0.1;
    const float wheelOffset = 0.25;
    const int numWheelSegments = 50;
    glBegin(GL_POLYGON);
    for (int i = 0; i < numWheelSegments; ++i) {
        float theta = 2.0f * 3.1415926f * float(i) / float(numWheelSegments);
        float x = carPositionX - wheelOffset + wheelRadius * cosf(theta);
        float y = -0.6 + wheelRadius * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();

    glBegin(GL_POLYGON);
    for (int i = 0; i < numWheelSegments; ++i) {
        float theta = 2.0f * 3.1415926f * float(i) / float(numWheelSegments);
        float x = carPositionX + wheelOffset + wheelRadius * cosf(theta);
        float y = -0.6 + wheelRadius * sinf(theta);
        glVertex2f(x, y);
    }
    glEnd();
}

void updateCarPosition(float deltaTime) {
    // Update the x-position of the car based on time
    const float speed = 0.3f;
    carPositionX += speed * deltaTime;

    // Wrap around the screen if the car goes off the right edge
    if (carPositionX > 1.2f)
        carPositionX = -1.2f;
}

int main(void) {
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(800, 600, "Car Animation Example", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window)) {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        // Update the car position
        float currentTime = glfwGetTime();
        static float previousTime = currentTime;
        float deltaTime = currentTime - previousTime;
        previousTime = currentTime;
        updateCarPosition(deltaTime);

        // Draw the car
        drawCar();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
