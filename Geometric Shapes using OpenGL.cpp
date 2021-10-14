#include<windows.h>
#include <stdlib.h>
#include <GL/glut.h>
#include<math.h>

#define PI 3.14159


void drawScene(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	/*glBegin(GL_LINES);
	glVertex3f(-1.0,0.0,0.0); //x-axis
	glVertex3f(1.0,0.0,0.0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(0.0,-1.0,0.0);  //y-axis
	glVertex3f(0.0,1.0,0.0);
	glEnd();*/

    //TRIANGLE
	glBegin(GL_TRIANGLES);
	glColor3ub(255,255,255);
	glVertex2f(-0.1,-0.3);
	glVertex2f(-0.3,-0.3);
	glVertex2f(-0.3,-0.1);
	glEnd();

	//RECTANGLE
	glBegin(GL_QUADS);
	glColor3ub(255,255,255);
	glVertex2f(-0.4, 0.3);
	glVertex2f(-0.1, 0.3);
	glVertex2f(-0.1, 0.1);
	glVertex2f(-0.4, 0.1);
	glEnd();

    //POLYGON
	glBegin(GL_POLYGON);
	glColor3ub(255,255,255);
	glVertex2f(0.2, -0.1);
	glVertex2f(0.1, -0.2);
	glVertex2f(0.1, -0.3);
	glVertex2f(0.2, -0.4);
	glVertex2f(0.3, -0.4);
	glVertex2f(0.4, -0.3);
	glVertex2f(0.4, -0.2);
	glVertex2f(0.3, -0.1);
	glEnd();

	//CIRCLE
	GLfloat x=0.3f, y=0.3f, radius =0.2f;
	int amount =40;
	GLfloat twicePi = 2.0f *PI;
	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(255,255,255);
	glVertex2f(x,y);
	for(int i = 0; i<=amount; i++){
	    glVertex2f(
            x+(radius*cos(i*twicePi/amount)),
            y+(radius*sin(i*twicePi/amount))
        );
    }
    glEnd();

    glFlush();

}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(400, 450);
	glutCreateWindow("Geometric Shapes");
	glutDisplayFunc(drawScene);
	glutMainLoop();
	return 0;
}
