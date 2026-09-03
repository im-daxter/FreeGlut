#include<GL/freeglut.h>

void desenha(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-6, 6, -6, 6);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // triangulo esquerdo
    glBegin(GL_TRIANGLES);
        glColor3f(1,1,0);
        glVertex2f(0, 3);
        glVertex2f(0, -3);
        glColor3f(1,0.2,0);
        glVertex2f(-2.5, 0);
    glEnd();

    // triangulo menor esquerdo
    glBegin(GL_TRIANGLES);
        glColor3f(1,1,0);
        glVertex2f(0, 2.2);
        glVertex2f(0, -0.2);
        glColor3f(1,0.1,0);
        glVertex2f(-1, 1);
    glEnd();

    // triangulo direito
    glBegin(GL_TRIANGLES);
        glColor3f(1,1,0);
        glVertex2f(0,3);
        glVertex2f(0,-3);
        glColor3f(1,0.2,0);
        glVertex2f(2.5,0);
    glEnd();

        // triangulo menor direito
    glBegin(GL_TRIANGLES);
        glColor3f(1,1,0);
        glVertex2f(0,0.2);
        glVertex2f(0,-2.2);
        glColor3f(1,0.1,0);
        glVertex2f(1,-1);
    glEnd();
    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGB );
    glutInitWindowSize(800,600);
    glutCreateWindow("Ola Glut");
    glutDisplayFunc(desenha);
    glClearColor( 0, 0, 1, 0);
    glutMainLoop();
return 0;
}
