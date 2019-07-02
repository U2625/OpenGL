#include <GL/glut.h>
#include <cmath>


int a=0;
int b=0;
GLfloat rquad;
void display()
{
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//  glLineWidth(3);
 glPushMatrix();
  glTranslatef(55, 55, 0);
  glRotatef(a, sin(b / 100) + 1, cos(b / 200) + 1, sin(b / 300) + 1);
  glBegin(GL_QUADS);
  glColor3f(0.3, 0.1, 1.0);
  glVertex2f(-25, -25);
  glVertex2f(25, -25);
  glColor3f(0.7, 0.3, 0.1);
  glVertex2f(25, -25);
  glVertex2f(25, 25);
  glColor3f(0.7, 0.6, 0.6);
  glVertex2f(25, 25);
  glVertex2f(-25, 25);
  glColor3f(0.1, 0.2, 0.1);
  glVertex2f(-25, 25);
  glVertex2f(-25, -25);

  glEnd();
  glPopMatrix();
  glutSwapBuffers();
}
void timer(int = 0)
{
  ++a; ++b;
  display();
  glutTimerFunc(10, timer, 0);
}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(200, 200);
  glutInitWindowPosition(20, 810);
  glutCreateWindow("Cube");
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-100, 100, -100, 100, -100, 100);
  glutDisplayFunc(display);
  timer();
  glutMainLoop();
}
