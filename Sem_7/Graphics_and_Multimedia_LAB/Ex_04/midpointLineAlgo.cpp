#include<windows.h>
#include<gl/glut.h>
#include<cstdlib>
#include<iostream>
using namespace std;

int X1, Y1, r;

void myInit()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glPointSize(1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0, 0.0, 600.0);
}

void putPixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void plotOctants(int x, int y)
{
    putPixel(X1 + x, Y1 + y);
    putPixel(X1 + x, Y1 - y);
    putPixel(X1 - x, Y1 + y);
    putPixel(X1 - x, Y1 - y);
    putPixel(X1 + y, Y1 + x);
    putPixel(X1 - y, Y1 + x);
    putPixel(X1 + y, Y1 - x);
    putPixel(X1 - y, Y1 - x);
}

void midPointCircle()
{
    int x = 0;
    int y = r;
    float p = 5 / 4 - r;
    plotOctants(x, y);

    while (y > x)
    {
        x++;
        if (p < 0)
        {
            p += 2 * x + 1;
        }
        else
        {
            y--;
            p += 2 * (x - y) + 1;
        }
        plotOctants(x, y);
    }
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    midPointCircle();
    glFlush();
}

int main(int argc, char** argv)
{
    cout << "X coordinate: "; cin >> X1;
    cout << "Y coordinate: "; cin >> Y1;
    cout << "Radius: "; cin >> r;

    glutInit(&argc, argv);                 // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutCreateWindow("Midpoint Circle Algo"); // Create a window with the given title
    myInit();
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop();           // Enter the infinitely event-processing loop
    return 0;
}

// 300 300 100