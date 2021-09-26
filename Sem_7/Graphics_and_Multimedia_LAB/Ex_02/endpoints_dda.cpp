#include<windows.h>
#include<gl/glut.h>
#include<cstdlib>
#include<iostream>
using namespace std;

float x1[8], Y1[8], x2[8], y2[8];

void myInit()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glPointSize(1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 800.0, 600.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
}

void display(void)
{
    float dy, dx, step, x, y, k, Xin, Yin;

    for (int i = 0; i < 8; i++)
    {
        dx = x2[i] - x1[i];
        dy = y2[i] - Y1[i];

        if (abs(dx) > abs(dy))
        {
            step = abs(dx);
        }
        else
            step = abs(dy);

        Xin = dx / step;
        Yin = dy / step;

        x = x1[i];
        y = Y1[i];
        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();

        for (k = 1; k <= step; k++)
        {
            x = x + Xin;
            y = y + Yin;

            glBegin(GL_POINTS);
            glVertex2i(x, y);
            glEnd();
        }
    }

    glFlush();
}

int main(int argc, char** argv)
{
    for (int i = 0; i < 8; i++)
    {
        cout << "x1 : ";
        cin >> x1[i];
        cout << "y1 : ";
        cin >> Y1[i];
        cout << "x2 : ";
        cin >> x2[i];
        cout << "y2 : ";
        cin >> y2[i];
    }
    
    glutInit(&argc, argv);                 // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutCreateWindow("DDA line algo"); // Create a window with the given title
    myInit();
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop();           // Enter the infinitely event-processing loop
    return 0;
}

// 500 150 600 50 300 150 200 50 500 200 700 150 300 200 100 150 500 350 700 400 300 350 100 400 500 400 600 550 300 400 200 550