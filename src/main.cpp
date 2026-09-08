#include <cstdio>
#include <cstdlib>

#include <GL/glew.h>
#include <GL/freeglut.h>

#include "utils.hpp"

// Mode tampilan: 
// 0 = Fill + Outline Triangulasi (Default sesuai gambar soal)
// 1 = Cool Color Interpolation (Gradasi warna dingin / icy-blue smooth shading)
// 2 = Wireframe Only (Hanya jaring-jaring segitiga)
// 3 = Solid Fill Only (Hanya warna isi)
static int displayMode = 0;

// Fungsi menggambar seluruh bentuk menggunakan primitif GL_TRIANGLES (Flat / Single Color)
void drawTriangles()
{
    glBegin(GL_TRIANGLES);

        // ==========================================
        // 1. Sisi Kiri (Left Wing & Left Shaft)
        // ==========================================
        
        // Segitiga 1: Sayap kiri bawah
        glVertex2f(10.0f, 85.0f);
        glVertex2f(10.0f, 65.0f);
        glVertex2f(30.0f, 65.0f);

        // Segitiga 2: Sayap kiri atas ke tiang
        glVertex2f(10.0f, 85.0f);
        glVertex2f(30.0f, 65.0f);
        glVertex2f(45.0f, 85.0f);

        // Segitiga 3: Tiang kiri luar
        glVertex2f(30.0f, 65.0f);
        glVertex2f(30.0f, 15.0f);
        glVertex2f(45.0f, 85.0f);

        // Segitiga 4: Tiang kiri dalam
        glVertex2f(30.0f, 15.0f);
        glVertex2f(45.0f, 30.0f);
        glVertex2f(45.0f, 85.0f);

        // ==========================================
        // 2. Bagian Bawah (Bottom Base)
        // ==========================================

        // Segitiga 5: Dasar U bagian kiri
        glVertex2f(30.0f, 15.0f);
        glVertex2f(70.0f, 15.0f);
        glVertex2f(45.0f, 30.0f);

        // Segitiga 6: Dasar U bagian kanan
        glVertex2f(70.0f, 15.0f);
        glVertex2f(55.0f, 30.0f);
        glVertex2f(45.0f, 30.0f);

        // ==========================================
        // 3. Sisi Kanan (Right Shaft & Right Wing)
        // ==========================================

        // Segitiga 7: Tiang kanan dalam
        glVertex2f(70.0f, 15.0f);
        glVertex2f(55.0f, 30.0f);
        glVertex2f(55.0f, 85.0f);

        // Segitiga 8: Tiang kanan luar
        glVertex2f(70.0f, 65.0f);
        glVertex2f(70.0f, 15.0f);
        glVertex2f(55.0f, 85.0f);

        // Segitiga 9: Sayap kanan atas ke tiang
        glVertex2f(90.0f, 85.0f);
        glVertex2f(70.0f, 65.0f);
        glVertex2f(55.0f, 85.0f);

        // Segitiga 10: Sayap kanan bawah
        glVertex2f(90.0f, 85.0f);
        glVertex2f(90.0f, 65.0f);
        glVertex2f(70.0f, 65.0f);

    glEnd();
}

// Fungsi menggambar triangulasi dengan Color Interpolation bertema dingin (Ice / Oceanic Blue)
// Menggunakan warna per-vertex yang diinterpolasi otomatis oleh OpenGL (Gouraud Shading)
void drawInterpolatedTriangles()
{
    glShadeModel(GL_SMOOTH);
    glBegin(GL_TRIANGLES);

        // ==========================================
        // 1. Sisi Kiri (Left Wing & Left Shaft)
        // ==========================================
        
        // Segitiga 1: Sayap kiri bawah
        glColor3f(0.75f, 0.95f, 1.00f); glVertex2f(10.0f, 85.0f); // Icy Frost
        glColor3f(0.35f, 0.75f, 0.95f); glVertex2f(10.0f, 65.0f); // Glacier Blue
        glColor3f(0.20f, 0.85f, 0.85f); glVertex2f(30.0f, 65.0f); // Frost Mint

        // Segitiga 2: Sayap kiri atas ke tiang
        glColor3f(0.75f, 0.95f, 1.00f); glVertex2f(10.0f, 85.0f); // Icy Frost
        glColor3f(0.20f, 0.85f, 0.85f); glVertex2f(30.0f, 65.0f); // Frost Mint
        glColor3f(0.70f, 0.95f, 1.00f); glVertex2f(45.0f, 85.0f); // Arctic Cyan

        // Segitiga 3: Tiang kiri luar
        glColor3f(0.20f, 0.85f, 0.85f); glVertex2f(30.0f, 65.0f); // Frost Mint
        glColor3f(0.08f, 0.12f, 0.50f); glVertex2f(30.0f, 15.0f); // Deep Midnight Indigo
        glColor3f(0.70f, 0.95f, 1.00f); glVertex2f(45.0f, 85.0f); // Arctic Cyan

        // Segitiga 4: Tiang kiri dalam
        glColor3f(0.08f, 0.12f, 0.50f); glVertex2f(30.0f, 15.0f); // Deep Midnight Indigo
        glColor3f(0.05f, 0.30f, 0.70f); glVertex2f(45.0f, 30.0f); // Deep Ocean Blue
        glColor3f(0.70f, 0.95f, 1.00f); glVertex2f(45.0f, 85.0f); // Arctic Cyan

        // ==========================================
        // 2. Bagian Bawah (Bottom Base)
        // ==========================================

        // Segitiga 5: Dasar U bagian kiri
        glColor3f(0.08f, 0.12f, 0.50f); glVertex2f(30.0f, 15.0f); // Deep Midnight Indigo
        glColor3f(0.08f, 0.12f, 0.50f); glVertex2f(70.0f, 15.0f); // Deep Midnight Indigo
        glColor3f(0.05f, 0.30f, 0.70f); glVertex2f(45.0f, 30.0f); // Deep Ocean Blue

        // Segitiga 6: Dasar U bagian kanan
        glColor3f(0.08f, 0.12f, 0.50f); glVertex2f(70.0f, 15.0f); // Deep Midnight Indigo
        glColor3f(0.05f, 0.30f, 0.70f); glVertex2f(55.0f, 30.0f); // Deep Ocean Blue
        glColor3f(0.05f, 0.30f, 0.70f); glVertex2f(45.0f, 30.0f); // Deep Ocean Blue

        // ==========================================
        // 3. Sisi Kanan (Right Shaft & Right Wing)
        // ==========================================

        // Segitiga 7: Tiang kanan dalam
        glColor3f(0.08f, 0.12f, 0.50f); glVertex2f(70.0f, 15.0f); // Deep Midnight Indigo
        glColor3f(0.05f, 0.30f, 0.70f); glVertex2f(55.0f, 30.0f); // Deep Ocean Blue
        glColor3f(0.70f, 0.95f, 1.00f); glVertex2f(55.0f, 85.0f); // Arctic Cyan

        // Segitiga 8: Tiang kanan luar
        glColor3f(0.20f, 0.85f, 0.85f); glVertex2f(70.0f, 65.0f); // Frost Mint
        glColor3f(0.08f, 0.12f, 0.50f); glVertex2f(70.0f, 15.0f); // Deep Midnight Indigo
        glColor3f(0.70f, 0.95f, 1.00f); glVertex2f(55.0f, 85.0f); // Arctic Cyan

        // Segitiga 9: Sayap kanan atas ke tiang
        glColor3f(0.75f, 0.95f, 1.00f); glVertex2f(90.0f, 85.0f); // Icy Frost
        glColor3f(0.20f, 0.85f, 0.85f); glVertex2f(70.0f, 65.0f); // Frost Mint
        glColor3f(0.70f, 0.95f, 1.00f); glVertex2f(55.0f, 85.0f); // Arctic Cyan

        // Segitiga 10: Sayap kanan bawah
        glColor3f(0.75f, 0.95f, 1.00f); glVertex2f(90.0f, 85.0f); // Icy Frost
        glColor3f(0.35f, 0.75f, 0.95f); glVertex2f(90.0f, 65.0f); // Glacier Blue
        glColor3f(0.20f, 0.85f, 0.85f); glVertex2f(70.0f, 65.0f); // Frost Mint

    glEnd();
}

void init()
{
    // Warna background putih bersih (sesuai modul/soal)
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    // Tebal garis untuk wireframe/outline
    glLineWidth(2.0f);
}

void display()
{
    glClear(
        GL_COLOR_BUFFER_BIT |
        GL_DEPTH_BUFFER_BIT
    );

    if (displayMode == 0)
    {
        // Mode 0: Tampilkan warna teal + garis batas triangulasi (seperti gambar soal)
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glColor3f(0.55f, 0.78f, 0.80f); // Warna teal
        drawTriangles();

        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glColor3f(0.12f, 0.38f, 0.40f); // Warna garis gelap
        drawTriangles();
    }
    else if (displayMode == 1)
    {
        // Mode 1: Cool Color Interpolation (Gradasi Icy / Ocean Blue)
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        drawInterpolatedTriangles();

        // Outline kontras halus agar pembagian segitiga tetap terlihat jelas
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glColor3f(0.05f, 0.15f, 0.35f); // Deep navy outline
        drawTriangles();
    }
    else if (displayMode == 2)
    {
        // Mode 2: Wireframe saja
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glColor3f(0.12f, 0.38f, 0.40f);
        drawTriangles();
    }
    else if (displayMode == 3)
    {
        // Mode 3: Solid Fill saja
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
        glColor3f(0.55f, 0.78f, 0.80f);
        drawTriangles();
    }

    // Kembalikan polygon mode ke fill
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
    // Koordinat ortografis 0 - 100
    glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void keyInput(unsigned char key, int x, int y)
{
    switch (key)
    {
    case ' ':
        // Tekan spasi untuk toggle mode (0 -> 1 -> 2 -> 3 -> 0)
        displayMode = (displayMode + 1) % 4;
        glutPostRedisplay();
        break;
    case 27: // Tombol Escape
        exit(0);
        break;
    default:
        break;
    }
}

int main(int argc, char** argv)
{
    printf("========================================================\n");
    printf("🎨 Aktivitas Individu 3 - Exercise 2.14 Triangulasi\n");
    printf("Kontrol Interaksi:\n");
    printf("  [Spasi] : Toggle Mode:\n");
    printf("            0. Teal Fill + Outline (Sesuai Soal Modul)\n");
    printf("            1. Cool Color Interpolation (Tema Es/Oceanic)\n");
    printf("            2. Wireframe Only\n");
    printf("            3. Solid Fill Only\n");
    printf("  [Esc]   : Keluar Program\n");
    printf("========================================================\n");

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
        100,
        100
    );

    glutCreateWindow(
        "Aktivitas 3 - Exercise 2.14 Triangulasi"
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

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyInput);

    glutMainLoop();

    return 0;
}