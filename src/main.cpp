#include <cstdio>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include "utils.hpp"

namespace {

constexpr GLfloat vertices[][2] = {
    {10.0f, 90.0f},
    {25.0f, 75.0f},
    {35.0f, 90.0f},
    {25.0f, 10.0f},
    {45.0f, 25.0f},
    {70.0f, 10.0f},
    {55.0f, 25.0f},
    {70.0f, 75.0f},
    {55.0f, 90.0f},
    {90.0f, 75.0f},
    {90.0f, 90.0f},
};

void drawTriangleStrip(GLenum polygonMode, GLfloat red, GLfloat green, GLfloat blue)
{
    glPolygonMode(GL_FRONT_AND_BACK, polygonMode);
    glColor3f(red, green, blue);

    glBegin(GL_TRIANGLE_STRIP);
    for (const auto& vertex : vertices)
        glVertex2fv(vertex);
    glEnd();
}

} // namespace

void init()
{
    glClearColor(
        1.0f,
        1.0f,
        1.0f,
        1.0f
    );

    glLineWidth(2.0f);
}

void display()
{
    glClear(
        GL_COLOR_BUFFER_BIT |
        GL_DEPTH_BUFFER_BIT
    );

    drawTriangleStrip(GL_FILL, 0.55f, 0.78f, 0.80f);
    drawTriangleStrip(GL_LINE, 0.12f, 0.38f, 0.40f);
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    utils::checkGLError("display");
    glutSwapBuffers();
}

void reshape(int width, int height)
{
    if (height == 0)
        height = 1;

    glViewport(
        0,
        0,
        width,
        height
    );

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(
        GLUT_DOUBLE |
        GLUT_RGB |
        GLUT_DEPTH
    );

    glutInitWindowSize(
        800,
        600
    );

    glutInitWindowPosition(
        100,
        100
    );

    glutCreateWindow(
        "Komputer Grafis - Triangulasi"
    );

    GLenum err = glewInit();

    if (err != GLEW_OK)
    {
        fprintf(
            stderr,
            "GLEW Error: %s\n",
            glewGetErrorString(err)
        );

        return 1;
    }

    printf(
        "OpenGL Vendor  : %s\n",
        glGetString(GL_VENDOR)
    );

    printf(
        "OpenGL Renderer: %s\n",
        glGetString(GL_RENDERER)
    );

    printf(
        "OpenGL Version : %s\n",
        glGetString(GL_VERSION)
    );

    printf(
        "GLEW Version   : %s\n",
        glewGetString(GLEW_VERSION)
    );

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();

    return 0;
}
