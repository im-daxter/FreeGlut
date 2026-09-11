#include <GL/freeglut.h>

float altura = 1.0f, largura = 1.0f;
float deslocaX = -1.0f, deslocaY = -0.5f, deslocaZ = 0.0f;
float angulo = 0.0f;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glTranslatef(1.15f, 0.625f, 0.0f);
    glRotatef(angulo, 0.0f, 0.0f, 1.0f);
    //Aplica a escala da imagem
    glScalef(largura, altura, 1.0f);
    glTranslatef(deslocaX, deslocaY, deslocaZ);

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
        glVertex2f(2.25f, 0.50f);
        glVertex2f(2.00f, 0.50f);
        glVertex2f(2.00f, 0.62f);
        glVertex2f(2.25f, 0.62f);
        glVertex2f(2.00f, 0.62f);
        glVertex2f(2.00f, 0.75f);
        glVertex2f(2.25f, 0.75f);
    glEnd();

    glPopMatrix();
    glFlush();
}

void teclado(char tecla, int x, int y)
{
    switch (tecla) {
        // Aumenta e diminui largura
        case '+':
            largura += 0.1f;
            break;

        case '-':
            largura -= 0.1f;
            break;

        // Aumenta e diminui altura
        case '*':
            altura += 0.1f;
            break;

        case '/':
            altura -= 0.1f;
            break;

        // Deslocamento para esquerda e direita
        case 'l':
            deslocaX += 0.1f;
        break;

        case 'h':
            deslocaX -= 0.1f;
        break;

        // Deslocamento para baixo e cima
        case 'k':
            deslocaY += 0.1f;
        break;

        case 'j':
            deslocaY -= 0.1f;
        break;

        // Rotacao em sentido horario e antihorario
        case 't':
            angulo += 15.0f;
        break;

        case 'g':
            angulo -= 15.0f;
        break;

        case 27:
            exit(0);
        break;
    }
    glutPostRedisplay();
}

void configurarProjecao()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
        gluOrtho2D(-0.5, 3.0, -0.5, 3.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("FreeGLUT");
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    configurarProjecao();

    glutDisplayFunc(display);
    glutKeyboardFunc(teclado);

    glutMainLoop();

    return 0;
}
