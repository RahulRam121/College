#include <windows.h>
#include <gl/glut.h>
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int> pntX;
vector<int> pntY;

int choice, vertices;

void myInit()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glPointSize(1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glEnable(GL_BLEND); //Enable blending.
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //Set blending function.
    gluOrtho2D(-1000, 1000, -1000, 1000);
}

void drawPolygon()
{
    glBegin(GL_QUADS);  
    glColor4f(1.0f, 0.0f, 0.0f, 0.3f);
    for (int i = 0; i < vertices; i++)
    {
        glVertex2i(pntX[i], pntY[i]);
    }
    glEnd();
}

void refectionAlongX()
{
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.0f);
    for (int i = 0; i < vertices; i++)
    {
        glVertex2i(pntX[i], -1 * pntY[i]);
    }
    glEnd();
}

void refectionAlongY()
{
    glBegin(GL_QUADS);
    glColor3f(0.0f, 0.0f, 1.0f);
    for (int i = 0; i < vertices; i++)
    {
        glVertex2i(-1 * pntX[i], pntY[i]);
    }
    glEnd();
}

void reflectionAlongAxis()
{
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.5f, 1.0f);
    for (int i = 0; i < vertices; i++)
    {
        glVertex2i(-1 * pntX[i], -1 * pntY[i]);
    }
    glEnd();
}

void reflectionAlongXY()
{
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.5f, 0.5f);
    for (int i = 0; i < vertices; i++)
    {
        glVertex2i(pntY[i], pntX[i]);
    }
    glEnd();
}

void shearingAlongX(int x)
{
    glBegin(GL_QUADS);

    glColor3f(0.0f, 1.0f, 1.0f);
    for (int i = 0; i < vertices; i++)
    {
        if (i >= 2)
        {
            glVertex2i(pntX[i] + x, pntY[i]);
        }
        else
        {
            glVertex2i(pntX[i], pntY[i]);
        }
    }
    glEnd();
}

void shearingAlongY(int y)
{
    glBegin(GL_QUADS);
    glColor4f(1.0f, 0.0f, 1.0f, 0.7f);
    for (int i = 0; i < vertices; i++)
    {
        if (i >= 1 && i < 3)
        {
            glVertex2i(pntX[i], pntY[i] + y);
        }
        else
        {
            glVertex2i(pntX[i], pntY[i]);
        }
    }
    glEnd();
}

void printMenu()
{
    cout << "\n1. Reflection along X-axis" << "\n";
    cout << "2. Reflection along Y-axis" << "\n";
    cout << "3. Reflection along Origin" << "\n";
    cout << "4. Reflection along x=y" << "\n";
    cout << "5. Shearing along X-axis" << "\n";
    cout << "6. Shearing along Y-axis" << "\n";
    cout << "-1. exit" << "\n";
    cout << "Choose : " << "\n";
}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    int x, y;

    cout << "Number of edges : ";
    cin >> vertices;

    for (int i = 0; i < vertices; i++)
    {
        cout << "x coordinate : ";
        cin >> x;
        cout << "y coordinate : ";
        cin >> y;
        pntX.push_back(x);
        pntY.push_back(y);
    }

    //drawPolygon();

    printMenu();
    cin >> choice;
    while (choice != -1)
    {
        switch (choice)
        {
            case 1: 
            {
                refectionAlongX();
                break;
            }
            case 2: 
            {
                refectionAlongY();
                break;
            }
            case 3:
            {
                reflectionAlongAxis();
                break;
            }
            case 4:
            {
                reflectionAlongXY();
                break;
            }
            case 5:
            {
                cout << "Shearing parameter along X-axis: ";
                cin >> x;
                shearingAlongX(x);
                break;
            }
            case 6:
            {
                cout << "Shearing parameter along Y-axis: ";
                cin >> y;
                shearingAlongY(y);
                break;
            }
        }
        printMenu();
        cin >> choice;
    }
    drawPolygon();

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);                 // Initialize GLUT

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 1000);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutCreateWindow("2D Transformations"); // Create a window with the given title
    myInit();
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop();           // Enter the infinitely event-processing loop
    return 0;
}

// 4 100 100 400 100 400 300 100 300 1 2 3 4 5 100 6 100 -1

// 4 250 100 400 250 250 400 100 250 1 2 3 4 5 100 6 100 -1

// 4 100 400 400 400 400 600 100 600 1 2 3 4 5 100 6 100 -1