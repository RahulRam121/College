#include<windows.h>
#include<gl/glut.h>
#include<cstdlib>
#include<iostream>
using namespace std;


void myInit()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
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

void plotOctants(int X1, int Y1, int x, int y)
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

void midPointCircle(int X1, int Y1, int r)
{
    int x = 0;
    int y = r;
    float p = 5 / 4 - r;
    plotOctants(X1, Y1, x, y);

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
        plotOctants(X1, Y1, x, y);
    }
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    glPointSize(2);

    int r = 160;
    int temp = 0;
    glColor3f(0.8, 0.3, 0.0);
    while (temp <= r)
    {
        midPointCircle(400, 300, temp);
        temp++;
    }

    temp = 160;
    r = 200;
    glColor3f(1.0, 0.7, 0.0);
    while (temp <= r)
    {
        midPointCircle(400, 300, temp);
        temp++;
    }

    temp = 0;
    r = 20;
    glColor3f(1.0, 1.0, 1.0);
    while (temp <= r)
    {
        midPointCircle(450, 350, temp);
        temp++;
    }

    temp = 0;
    r = 20;
    glColor3f(1.0, 1.0, 1.0);
    while (temp <= r)
    {
        midPointCircle(450, 250, temp);
        temp++;
    }

    temp = 0;
    r = 20;
    glColor3f(1.0, 1.0, 1.0);
    while (temp <= r)
    {
        midPointCircle(350, 350, temp);
        temp++;
    }

    temp = 0;
    r = 20;
    glColor3f(1.0, 1.0, 1.0);
    while (temp <= r)
    {
        midPointCircle(350, 250, temp);
        temp++;
    }

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);                 // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutCreateWindow("Button"); // Create a window with the given title
    myInit();
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop();           // Enter the infinitely event-processing loop
    return 0;
}

// 300 300 100