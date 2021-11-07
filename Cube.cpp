#include<GL/glut.h>

GLfloat xRotate, yRotate, zRotate;
GLdouble size = 1.5;

void display(void);
void reshape(int x, int y);
void idle(void){
    xRotate += 0.01;
    yRotate += 0.01;
    zRotate += 0.01;
    display();
}

int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitWindowSize(400,400);
    glutCreateWindow("Tanya18103043-Cube");
    xRotate = yRotate = zRotate = 30.0;
    xRotate=43;
    yRotate=50;

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
	glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}

void display(void)
{

    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0,0.0,-5.0);
    glColor3f(0, 150, 0);
    glRotatef(xRotate,1.0,0.0,0.0);
    glRotatef(yRotate,0.0,1.0,0.0);
    glRotatef(zRotate,0.0,0.0,1.0);
    glScalef(1.0,1.0,1.0);
    glutSolidCube(size);
    glFlush();
}

void reshape(int x, int y)
{
    if (y == 0 || x == 0) return;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(39.0,(GLdouble)x/(GLdouble)y,0.6,21.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);
}

