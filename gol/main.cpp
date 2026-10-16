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
int contador = 0, errou = 0;

// Vetor de translacao
GLfloat xstep = 3.0f;
GLfloat ystep = 3.0f;
GLfloat windowWidth;
GLfloat windowHeight;

void desenhaTexto(char *aux)
{
    while ( *aux ) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *aux++);
    }
}

void desenhaCirculo(void)
{
    glColor3f(1, 0, 0);
    glLineWidth(5);

    float ang, x, y;

    glBegin(GL_LINE_LOOP);
        for ( i = 0; i < 360; i++ ) {
            //angle = 2*PI*i/circle_points;
            ang = ( i * PI ) / 180.0;
            x = xp1 + (cos(ang) * 15);
            y = yp1 + (sin(ang) * 15);
            glVertex2f( x, y );
        }

    glEnd();
}

void desenhaGol(void)
{
    glColor3f(1, 1, 1);
    glLineWidth(5);

    float traveE = 150, traveD = 450;
    float chao = 310, travessao = 450;

    glBegin(GL_LINES);
        glVertex2f( traveE, chao );
        glVertex2f( traveE , travessao );

        glVertex2f( traveD, chao );
        glVertex2f( traveD , travessao );

        glVertex2f( traveE, travessao );
        glVertex2f( traveD, travessao );
    glEnd();
}

void Desenha(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);

    desenhaCirculo();
    desenhaGol();
    glutSwapBuffers();
}

void Timer(int value)
{
    if( xp1 > windowWidth-rsize )
        xp1 = windowWidth-rsize-1;

    if ( yp1 > 450 ) {
        yp1 = 200;
        ystep = 4.0f;
        continua = 0;
    }

    yp1 += ystep;

    if ( yp1 == 450 && xp1 > 150 && xp1 < 450 ) {
        //contador++;
        printf("GOL");

        glPushMatrix(); //
            glColor3f(1.0f, 1.0f, 1.0f);
            //glTranslatef(100.0f, 200.0f, 0.0f);
            glScalef(2.0f, 2.0f, 0.0f);
            desenhaTexto("GOL");
        glPopMatrix();
    }

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
    glutKeyboardFunc(teclado);

    glutMainLoop();
}
