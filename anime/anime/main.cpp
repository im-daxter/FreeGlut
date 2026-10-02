#include <windows.h>
#include <GL/freeglut.h>
#include <stdio.h>
GLfloat x1 = 100.0f;
GLfloat y1 = 150.0f;
GLsizei rsize = 50; // Tamanho da aresta

// Vetor de translacao
GLfloat xstep = 3.0f;
GLfloat ystep = 3.0f;

// Variaveis globais para gerenciar o tamanho da janela
GLfloat windowWidth;
GLfloat windowHeight;

void DesenhaTriangulo(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex2i(x1 + rsize / 2, y1 + rsize);
        glVertex2i(x1, y1);
        glVertex2i(x1 + rsize, y1);
    glEnd();

    glutSwapBuffers();
}

void TimerTriangulo(int value)
{
// Muda a dire o quando chega na borda esquerda ou direita
    if(x1 > windowWidth - rsize || x1 < 0)
        xstep = -xstep;

// Muda a dire o quando chega na borda superior ou inferior
    if(y1 > windowHeight - rsize || y1 < 0)
        ystep = -ystep;

// Verifica o de bordas. Se a window for menor e o quadrado sair do volume de visualizacao
    if(x1 < windowWidth - rsize)
        x1 = windowWidth - rsize - 1;

    if(y1 > windowHeight - rsize)
        y1 = windowHeight - rsize - 1;

    x1 -= xstep;
    y1 -= ystep;

    glutPostRedisplay();
    glutTimerFunc(5, TimerTriangulo, 0); // ( taxa de tempo em ms, funcao, outro parametro qualquer )
}

void DesenhaQuadrado(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.0f, 0.0f);

    glBegin(GL_QUADS);
        glVertex2i(x1, y1 + rsize);
        glVertex2i(x1, y1);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex2i(x1 + rsize, y1);
        glVertex2i(x1 + rsize, y1 + rsize);
    glEnd();

    glutSwapBuffers();
}

void Timer(int value)
{
// Muda a dire o quando chega na borda esquerda ou direita
    if(x1 > windowWidth - rsize || x1 < 0)
        xstep = -xstep;

// Muda a dire o quando chega na borda superior ou inferior
    if(y1 > windowHeight - rsize || y1 < 0)
        ystep = -ystep;

// Verifica o de bordas. Se a window for menor e o quadrado sair do volume de visualizacao
    if(x1 > windowWidth - rsize)
        x1 = windowWidth - rsize - 1;

    if(y1 > windowHeight - rsize)
        y1 = windowHeight - rsize - 1;

    x1 += xstep;
    y1 += ystep;

    glutPostRedisplay();
    glutTimerFunc(5, Timer, 0); // ( taxa de tempo em ms, funcao, outro parametro qualquer )
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
    printf("\n w: %d h: %d ", w, h);
    glViewport(0, 0, w, h); // Redefine o sistema de coordenadas, de acordo com o tamanho da janela
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
    //glutDisplayFunc(DesenhaQuadrado);
    glutDisplayFunc(DesenhaTriangulo);
    glutReshapeFunc(AlteraTamanhoJanela);
    //glutTimerFunc(5, Timer, 0);
    glutTimerFunc(5, TimerTriangulo, 0);
    glutMainLoop();
}

// cada vez que acertar o clique no quadrado e no triangulo, adicione um contador
