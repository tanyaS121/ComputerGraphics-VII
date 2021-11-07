#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
int a,b,c,d;
float xr,yr;
void init(void)
{
 glClearColor(0.0,0.0,0.0,1.0);
 glMatrixMode(GL_PROJECTION);
 gluOrtho2D(-500,500,-500,500);
}
void setPixel(GLint x,GLint y)
{
 glBegin(GL_POINTS);
 glVertex2i(x,y);
 glEnd();
}
int round1(double number)
{
 return (number>=0) ? (int)(number+0.5):(int)(number-0.5);
}
void LineWithDDA(int x0,int y0,int x1,int y1)
{
 int dy=y1-y0;
 int dx=x1-x0;
 int steps,i;
 float xinc,yinc,x=x0,y=y0;
 if(abs(dx)>abs(dy))
 {
  steps=abs(dx);
 }
 else
 {
  steps=abs(dy);
 }
 xinc=(float)dx/(float)steps;
 yinc=(float)dy/(float)steps;
 setPixel(round1(x),round1(y));
 for(i=0;i<steps;i++)
 {
  x+=xinc;
  y+=yinc;
  setPixel(round1(x),round1(y));
 }
 glutSwapBuffers();
}
void rotate(int x,int y)
{
 float p=sin((30*3.14)/180);
 float q=cos((30*3.14)/180);
 xr=x*p-y*q;
 yr=x*p+y*q;
}
void draw()
{
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(255,255,255);
 LineWithDDA(a,b,c,d);
 rotate(c,d);
 glColor3f(0,1,0);
 LineWithDDA(a,b,xr,yr);
  rotate(xr,yr);
  glColor3f(1,0,0);
  LineWithDDA(a,b,xr,yr);

 glFlush();
}
int main(int argc,char **argv)
{
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowPosition(50,50);
 glutInitWindowSize(500,500);
 printf("\nEnter x1: ");
 scanf("%d",&a);
 printf("Enter y1: ");
 scanf("%d",&b);
 printf("Enter x2: ");
 scanf("%d",&c);
 printf("Enter y2: ");
 scanf("%d",&d);
 glutCreateWindow("Line Rotation");
 init();
 glutDisplayFunc(draw);
 glutMainLoop();
 return 0;
}
