#include <gl\glut.h>
#define SunSize 0.3
#define EarthSize 0.10
#define MoonSize 0.020

GLfloat SpeedMultiplicator = 1.0;
GLfloat DaysPerYear = 10.0;
GLfloat year = 0.0;
GLfloat day = 0.0;
GLfloat moonAroundEarth = 0.0;
GLfloat moonItsSelf = 0.0;
GLfloat EarthOrbitRadius = 1.1;
GLfloat MoonOrbitRadius = 0.20;
GLfloat daySpeed = 1.0 * SpeedMultiplicator;
GLfloat yearSpeed = DaysPerYear / 360.0 * daySpeed * SpeedMultiplicator;
GLfloat moonAroundEarthSpeed = 0.2 * SpeedMultiplicator;
GLfloat moonItsSelfSpeed = 1 * SpeedMultiplicator;

void RenderScene(void){
            glPushMatrix();
            gluLookAt(0.0,0.0,-4.0,0.0,0.0,1.0,0.0,-3.0,0.0);
            glColor3f(0.9,1.0,0.2);
            glutSolidSphere(SunSize,40,40);
            glRotatef(year,0.0,0.2,0.5);
            glTranslatef(EarthOrbitRadius,0.0,0.0);
            glPushMatrix();
            glRotatef(day,0.25,1.0,0.0);
            glColor3f(0.0,0.2,0.5);
            glutSolidSphere(EarthSize,10,10);
            glPopMatrix();
            glRotatef(moonAroundEarth,0.0,0.0,0.0);
            glTranslatef(MoonOrbitRadius,0.2,0.0);
            glRotatef(moonItsSelf,0.0,0.0,0.0);
            glColor3f(1.0,1.0,1.0);
            glutSolidSphere(MoonSize,9,9);
            glPopMatrix();
            glPopMatrix();
}

void Init(void){
    glClearColor(0.2,0.0,0.3,0.0);
    glClearDepth(10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Display(void){
    glClear(GL_COLOR_BUFFER_BIT);
    RenderScene();
    glFlush();
    glutSwapBuffers();
}


void Reshape(int x, int y){
    if (y == 0)
      return;
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
      glMatrixMode(GL_MODELVIEW);
      glViewport(0,0,x,y);
      Display();
}

void Idle(void){
      day += daySpeed;
      year += yearSpeed;
      moonItsSelf += moonItsSelfSpeed;
      moonAroundEarth += moonAroundEarthSpeed;
      Display();
}

int main(int argc, char* argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(700,700);
    glutCreateWindow("Sun, Moon and Earth - 18103043");
    Init();
    glutReshapeFunc(Reshape);
    glutDisplayFunc(Display);
    glutIdleFunc(Idle);
    glutMainLoop();
    return 0;
}
