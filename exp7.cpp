#include<iostream>
#include<stdlib.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
using namespace std;

void myInit(){
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
}

void handleResize(int w, int h){
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w /(double)h, 1.0, 200.0);
}

float sun_move=0.0f;

bool start1 = false;
bool start2 = false;
bool start3 = false;

void keyboard(unsigned char key, int x, int y){
    switch(key){
        case 'n' : start1 = true;
                   break;
        case 'd' : start2 = true;
                   break;
    }
}

void circle(float x, float y, double r){
    float x1, y1;
    glBegin(GL_POLYGON);
    for(int i=0; i<200; i++){
        float pi = 3.1416;
        float A = (i*2*pi)/25;
        float x1 = x +((r- 0.07) * cos(A));
        float y1 = y +((r)*sin(A));
        glVertex2f(x1,y1);
    }
    glEnd();
}

void sky(){
    glColor3f(0.118, 0.565, 1.000);
    glBegin(GL_QUADS);
    glVertex2f(-1000.0, 0.02);
    glVertex2f(-1000.0, 1000.0);
    glVertex2f(1000.0, 1000.0);
    glVertex2f(1000.0, 0.01);
    glEnd();
}

void field(){
    glColor3f(0.420, 0.557, 0.137);
    glBegin(GL_QUADS);
    glVertex2f(-5000.0, 0.4000);
    glVertex2f(-1000.0, -0.9);
    glVertex2f(500.0, -1000.0);
    glVertex2f(350.0, 0.001);
    glEnd();
}

void sun(){
    glColor3f(1.000, 0.843, 0.000);
    circle(-0.15, 0.75, 0.25);
}

void moon(){
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    circle(0.15, 0.75, 0.20);
    glPopMatrix();
}

void hill(){

    glBegin(GL_POLYGON);
    glColor3f(0.6, 0.3, 0.0);
    glVertex2f(-0.50, 0.01);
    glVertex2f(0.003, 0.40);
    glVertex2f(0.30, 0.001);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.3, 0.1);
    glVertex2f(-0.08, 0.01);
    glVertex2f(-0.50, 0.60);
    glVertex2f(-0.800, 0.01);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.3, 0.1, 0.0);
    glVertex2f(-1.3, 0.01);
    glVertex2f(-0.65, 0.38);
    glVertex2f(-0.1000, 0.01);
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(0.4, 0.3, 0.2);
    glVertex2f(1.0, 0.01);
    glVertex2f(0.8, 0.45);
    glVertex2f(0.1000, 0.01);
    glEnd();
}

void tree1(){
    glColor3f(0.38, 0.19, 0.0);
    glLineWidth(8);
    glBegin(GL_LINES);
    glVertex2f(0.74, 0.0);
    glVertex2f(0.74, 0.11);
    glEnd();

    glColor3f(0.0, 0.43, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.80, 0.10);
    glVertex2f(0.74, 0.5);
    glVertex2f(0.68, 0.10);
    glEnd();
}
void tree2(){
    glColor3f(0.38, 0.19, 0.0);
    glLineWidth(8);
    glBegin(GL_LINES);
    glVertex2f(0.56, 0.0);
    glVertex2f(0.56, 0.11);
    glEnd();

    glColor3f(0.0, 0.43, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.62, 0.10);
    glVertex2f(0.56, 0.5);
    glVertex2f(0.50, 0.10);
    glEnd();
}

void tree3(){
    glColor3f(0.38, 0.19, 0.0);
    glLineWidth(8);
    glBegin(GL_LINES);
    glVertex2f(0.50, 0.0);
    glVertex2f(0.50, 0.11);
    glEnd();

    glColor3f(0.3, 0.43, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.60, 0.10);
    glVertex2f(0.50, 0.5);
    glVertex2f(0.40, 0.10);
    glEnd();
}

void house1(){
    //roof
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-0.95, -0.04);
    glVertex2f(-0.80, 0.20);
    glVertex2f(-0.80, 0.20);
    glVertex2f(-0.6, -0.04);
    glEnd();

    //window
    glColor3f(0.0, 0.31, 0.31);
    glBegin(GL_QUADS);
    glVertex2f(-0.89, -0.08);
    glVertex2f(-0.89, -0.20);
    glVertex2f(-0.82, -0.20);
    glVertex2f(-0.82, -0.08);
    glEnd();

    //door
    glColor3f(0.0, 0.31, 0.31);
    glBegin(GL_QUADS);
    glVertex2f(-0.81, -0.09);
    glVertex2f(-0.81, -0.32);
    glVertex2f(-0.73, -0.32);
    glVertex2f(-0.73, -0.09);
    glEnd();

    //window
    glColor3f(0.0, 0.31, 0.31);
    glBegin(GL_QUADS);
    glVertex2f(-0.72, -0.08);
    glVertex2f(-0.72, -0.20);
    glVertex2f(-0.65, -0.20);
    glVertex2f(-0.65, -0.08);
    glEnd();

    glColor3f(1.0, 0.14, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.91, -0.32);
    glVertex2f(-0.91, -0.04);
    glVertex2f(-0.63, -0.02);
    glVertex2f(-0.63, -0.32);
    glEnd();
}

void Display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    tree1();
    tree2();
    tree3();
    house1();
    hill();
    field();

    //sun
    glPushMatrix();
    glTranslatef(0.0, sun_move, 0.0);
    sun();
    glPopMatrix();
    if(start3 == true){
        moon();
    }

    if(start1 == true){
        sun_move -= 0.005;
        if(sun_move < -0.67){
            glDisable(GL_LIGHT0);
            start1 = false;
            start3 = true;
        }
    }

    if(start2 == true){
        start3 = false;
        glEnable(GL_LIGHT0);
        sun_move += 0.005;
        if(sun_move > 0.03){
            glEnable(GL_LIGHT0);
        }
        if(sun_move > 0){
            start2 = false;
        }
    }

    sky();
    glutSwapBuffers();
}

void update(int value){
    glutPostRedisplay();
    glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(700, 500);
    glutCreateWindow("Scenary - 18103043");
    myInit();
    glutDisplayFunc(Display);
    glutReshapeFunc(handleResize);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(25, update, 0);
    glutMainLoop();
    return 0;
}
