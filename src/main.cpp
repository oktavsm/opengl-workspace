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
    int size = 25;
    for(int i = 0; i < 8 ; i++){
        for (int j=0; j < 8; j++){
            if((i+j)%2==0){
                glColor3f(1.0f, 1.0f, 1.0f);
            }else{
                glColor3f(0.0f, 0.0f, 0.0f);
            }
            glBegin(GL_POLYGON);
                glVertex3f(i*size, j*size, 0.0);
                glVertex3f(i*size, (j+1)*size, 0.0);
                glVertex3f((i+1)*size, (j+1)*size, 0.0);
                glVertex3f((i+1)*size, j*size, 0.0);
            glEnd();
        }
    }
    // // Kotak Merah di Z = 0.0 (Posisi normal)
    // glColor3f(0.0f, 0.0f, 0.0f);
    // glBegin(GL_POLYGON);
    //     glVertex3f(-20.0, -20.0,   0.0);
    //     glVertex3f(-20.0,  20.0,   0.0);
    //     glVertex3f( 80.0,  80.0,   0.0);
    //     glVertex3f( 80.0, -20.0,   0.0);
    // glEnd();

    // // Kotak Biru di Z = -50.0 (Lebih jauh ke belakang/menjauh dari mata kita)
    // glColor3f(1.0f, 1.0f, 1.0f);
    // glBegin(GL_POLYGON);
    //     glVertex3f( 20.0,  20.0, 0.0);
    //     glVertex3f( 20.0, 120.0, 0.0);
    //     glVertex3f(120.0, 120.0, 0.0);
    //     glVertex3f(120.0,  20.0, 0.0);
    // glEnd();

    glutSwapBuffers();
}

void reshape(int width, int height)
{
    if (height == 0) height = 1;
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    // ----------------------------------------------------
    // EKSPERIMEN Z-AXIS (NEAR & FAR)
    // Format: glOrtho(left, right, bottom, top, near, far)
    // ----------------------------------------------------
    
    // Skenario 1: (Silakan comment Skenario 2, dan uncomment baris ini)
    // Kotak merah (z=0) dan biru (z=-50) masuk ke rentang near (-100) sampai far (100)
    // glOrtho(-100.0, 150.0, -100.0, 150.0, -100.0, 100.0);
    
    // Skenario 2: (Default kita coba yang ini dulu)
    // Kotak merah kelihatan (z=0), tapi Kotak Biru (z=-50) HILANG!
    // Kenapa hilang? Karena 'far' cuma mentok di 10.0 (nggak sampai 50.0).
    glOrtho(0, 200.0, 0.0, 200.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
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
        600,
        600
    );

    glutInitWindowPosition(
        0,
        0
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