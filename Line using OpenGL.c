#include <windows.h>
#include <GL/glut.h>

void display(){
    glColor3f(1,1,1);
    glBegin(GL_LINES);
    {
        glVertex3f(-45,10,0);
        glVertex3f(-30,30,0);
    }
    glEnd();
    glFlush();
}

void init(){
    glOrtho(-50.0, 20.0, -100.0, 40.0, -1.0, 1.0);
}

int main(int a, char **b){
    glutInit(&a,b);
    glutInitWindowSize(1400,1000);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Line using OpenGL - Tanya - 18103043");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
