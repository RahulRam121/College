#include<windows.h>
#include<gl/glut.h>
#include<cstdlib>
#include<iostream>
using namespace std;

int x1[8], Y1[8], x2[8], y2[8], type[8];
int lines = 0;

void myInit()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glPointSize(1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0, 0.0, 600.0);
    glClear(GL_COLOR_BUFFER_BIT);
}

void putPixel(int x, int y)
{
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void slantingMPositive(int i)
{
    int dx, dy, x, y, p;

    x = x1[i]; y = Y1[i];

    dx = x2[i] - x1[i];
    dy = y2[i] - Y1[i];

    

    // slope m < 1
    if (dx > dy)
    {
        p = 2 * dy - dx;
        while (x <= x2[i])
        {
            putPixel(x, y);
            x++;
            if (p < 0)
            {
                p += 2 * dy;
            }
            else
            {
                p += 2 * dy - 2 * dx;
                y++;
            }
        }
    }
    // slope m >= 1
    else
    {
        p = 2 * dx - dy;
        while (y <= y2[i])
        {
            putPixel(x, y);
            y++;
            if (p < 0)
            {
                p += 2 * dx;
            }
            else
            {
                p += 2 * dx - 2 * dy;
                x++;
            }
        }
    }

}

void slantingMNegative(int i)
{
    int dx, dy, x, y, p;

    x = x1[i]; y = Y1[i];

    dx = x2[i] - x1[i];
    dy = Y1[i] - y2[i];

    // slope m < 1
    if (dx > dy)
    {
        p = 2 * dy - dx;
        while (x <= x2[i])
        {
            putPixel(x, y);
            x++;
            if (p < 0)
            {
                p += 2 * dy;
            }
            else
            {
                p += 2 * dy - 2 * dx;
                y--;
            }
        }
    }
    // slope m >= 1
    else
    {
        p = 2 * dx - dy;
        while (y >= y2[i])
        {
            putPixel(x, y);
            y--;
            if (p < 0)
            {
                p += 2 * dx;
            }
            else
            {
                p += 2 * dx - 2 * dy;
                x++;
                
            }
        }
    }
}

void sleeping(int i)
{
    int x, y;
    y = Y1[i]; x = x1[i];
    while (x <= x2[i])
    {
        putPixel(x, y);
        x++;
    }
}

void standing(int i)
{
    int x, y;
    x = x1[i]; y = Y1[i];
    while (y <= y2[i])
    {
        putPixel(x, y);
        y++;
    }
}

void display(void)
{

    for (int i = 0; i < lines; i++)
    {
        switch (type[i])
        {
        case 1: slantingMPositive(i); break;
        case 2: slantingMNegative(i); break;
        case 3: standing(i); break;
        case 4: sleeping(i); break;
        default: break;
        }
    }

    glFlush();
}

void printMenu()
{
    cout << "1. Slanting line (m+ve)" << "\n";
    cout << "2. Slanting line (m-ve)" << "\n";
    cout << "3. Standing line" << "\n";
    cout << "4. Sleeping line" << "\n";
    cout << "-1. exit" << "\n";
    cout << "Choose : " << "\n";
}

int main(int argc, char** argv)
{
    int input;
    printMenu();
    cin >> input;
    
    while(input != -1)
    {
        type[lines] = input;
        cout << "x1 : ";
        cin >> x1[lines];
        cout << "y1 : ";
        cin >> Y1[lines];
        cout << "x2 : ";
        cin >> x2[lines];
        cout << "y2 : ";
        cin >> y2[lines++];
        printMenu();
        cin >> input;
    }

    glutInit(&argc, argv);                 // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutCreateWindow("Alphabets"); // Create a window with the given title
    myInit();
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop();           // Enter the infinitely event-processing loop
    return 0;
}

// 1 100 100 200 400 2 200 400 300 100 4 150 250 250 250 -1