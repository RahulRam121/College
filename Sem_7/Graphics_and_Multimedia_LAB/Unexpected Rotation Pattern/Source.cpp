#include<gl/glut.h>
#include<iostream>
#include<cstdlib>

float X1 = 50, Y1 = 0;

void myInit()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glPointSize(1);
	//gluOrtho2D(0, 800, 0, 600);
	glClear(GL_COLOR_BUFFER_BIT);
}

void putPixel(float x, float y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

float angle;
float degree = 1;

static void Timer(int value) {
	angle = (degree* 3.1416) / 180;
	degree++;
	if (degree == 360) degree = 1;
	glutPostRedisplay();
	// 100 milliseconds
	glutTimerFunc(100, Timer, 0);
}

void Display()
{
	float x, y;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.9, 0.9, 0.1);
	glBegin(GL_LINES);
		glVertex2f(0, 0);
		x = (X1 * cos(angle) - Y1 * sin(angle));
		y = (X1 * sin(angle) + Y1 * cos(angle));
		X1 = x;
		Y1 = y;
		glVertex2f(x, y);
	glEnd();

	glFlush();
	//glutPostRedisplay();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutCreateWindow("Testing");
	myInit();
	glutDisplayFunc(Display);
	Timer(0);
	glutMainLoop();
	return 0;
}