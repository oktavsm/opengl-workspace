#include <cstdio>

#include <GL/glew.h>
#include <GL/freeglut.h>

void init()
{
    glClearColor(
        0.15f,
        0.15f,
        0.15f,
        1.0f
    );

    glEnable(GL_DEPTH_TEST);
}

void display()
{
    glClear(
        GL_COLOR_BUFFER_BIT |
        GL_DEPTH_BUFFER_BIT
    );

    // ==========================================
    // Rendering goes here
    // ==========================================

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
        "Komputer Grafis"
    );

    // Initialize GLEW
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

    // Print OpenGL information
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