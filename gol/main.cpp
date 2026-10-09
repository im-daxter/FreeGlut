#include <windows.h>
#include <GL/freeglut.h>
#include <stdio.h>

#include <math.h>
#define PI 3.1415926535898

GLfloat escala = 1;
int i = 0, continua = 0;

GLfloat xp1 = 300.0f;
GLfloat yp1 = 200.0f;
GLsizei rsize = 50;

float deslocaX = 0.0f;

// Vetor de translacao
GLfloat xstep = 3.0f;
GLfloat ystep = 3.0f;
GLfloat windowWidth;
GLfloat windowHeight;

void desenhaCirculo()
{
    glColor3f(1, 0, 0);
    glLineWidth(5);

    float ang, x, y;

    glBegin(GL_LINE_LOOP);
        for (i = 0; i < 360; i++) {
            //angle = 2*PI*i/circle_points;
            ang = (i * PI) / 180.0;
            x = xp1 + (cos(ang) * 25);
            y = yp1 + (sin(ang) * 25);
            glVertex2f(x, y);
        }

    glEnd();
}

void Desenha(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);

    desenhaCirculo();
    glutSwapBuffers();
}

void Timer(int value)
{
    //if(xp1 > windowWidth-rsize || xp1 < 0)
    //    xstep = -xstep;
    //if(yp1 > windowHeight-rsize || yp1 < 0)
    //    ystep = yp1;

    if( xp1 > windowWidth-rsize )
        xp1 = windowWidth-rsize-1;

    //if ( yp1 > windowHeight-rsize ) {
    //    yp1 = 200;
    //}

    if ( yp1 > 700 ) {
        yp1 = 200;
        ystep = 3.0f;
        continua = 0;
    }

    //xp1 += xstep;
    yp1 += ystep;


    if ( continua == 1 ) {
    glutTimerFunc(5, Timer, 0);
    }

    glutPostRedisplay();
}

void teclado(unsigned char tecla, int x, int y)
{
    switch(tecla) {

        case ' ':
            continua = 1;
            glutTimerFunc(5, Timer, 0);
        break;

        case 'a':
            xp1 -= xstep;
        break;

        case 'd':
            xp1 += xstep;
        break;

        case 27:
            exit(0);
        break;
    }

    glutPostRedisplay();
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
    //printf("\n w: %d h: %d ", w, h);
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    windowWidth = w;
    windowHeight = h;
    gluOrtho2D(0.0f, windowWidth, 0.0f, windowHeight);
}
int main(int argc, char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutCreateWindow("Animacao");

    glutDisplayFunc(Desenha);
    glutReshapeFunc(AlteraTamanhoJanela);
    //glutTimerFunc(5, Timer, 0);
    glutKeyboardFunc(teclado);

    glutMainLoop();
}
