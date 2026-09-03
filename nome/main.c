#include <GL/glut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    //         le   ri   bo    up
    gluOrtho2D(-0.5, 3.0, -0.5, 2.0);

    // Letra 'J'
    glBegin(GL_LINE_STRIP);
        glVertex2f(0.10f, 0.75f);
        glVertex2f(0.25f, 0.75f);
        glVertex2f(0.25f, 0.75f);
        glVertex2f(0.25f, 0.50f);
        glVertex2f(0.25f, 0.50f);
        glVertex2f(0.10f, 0.50f);
        glVertex2f(0.10f, 0.60f);
    glEnd();

    // Letra 'O'
    glBegin(GL_LINE_STRIP);
        glVertex2f(0.50f, 0.50f);
        glVertex2f(0.50f, 0.75f);
        glVertex2f(0.75f, 0.75f);
        glVertex2f(0.75f, 0.50f);
        glVertex2f(0.50f, 0.50f);
    glEnd();

    // Letra 'R'
    glBegin(GL_LINE_STRIP);
        glVertex2f(1.00f, 0.50f);
        glVertex2f(1.00f, 0.75f);
        glVertex2f(1.25f, 0.75f);
        glVertex2f(1.25f, 0.62f);
        glVertex2f(1.00f, 0.62f);
        glVertex2f(1.25f, 0.50f);
    glEnd();

    // Letra 'G'
    glBegin(GL_LINE_STRIP);
        glVertex2f(1.60f, 0.60f);
        glVertex2f(1.75f, 0.60f);
        glVertex2f(1.75f, 0.50f);
        glVertex2f(1.50f, 0.50f);
        glVertex2f(1.50f, 0.75f);
        glVertex2f(1.75f, 0.75f);
        glVertex2f(1.75f, 0.65f);
    glEnd();

    // Letra 'E'
    glBegin(GL_LINE_STRIP);
        glVertex2d(2.25f, 0.50f);
        glVertex2d(2.00f, 0.50f);
        glVertex2d(2.00f, 0.62f);
        glVertex2d(2.25f, 0.62f);
        glVertex2d(2.00f, 0.62f);
        glVertex2d(2.00f, 0.75f);
        glVertex2d(2.25f, 0.75f);
    glEnd();


    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Teste freeGLUT - Debian 13");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
