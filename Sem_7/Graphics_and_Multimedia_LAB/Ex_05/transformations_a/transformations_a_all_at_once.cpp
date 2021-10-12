#include <windows.h>
#include <gl/glut.h>
#include <math.h>
#include <iostream>
#include <vector>
using namespace std;

double degree;
vector<int> pntX;
vector<int> pntY;

vector<int> lpntX;
vector<int> lpntY;

int choice, vertices;

void myInit()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glPointSize(1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1000, 1000, -1000, 1000);
}

//double round(double d)
//{
//    return floor(d + 0.5);
//}

void drawLine()
{
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    for (int i = 0; i < vertices; i++)
    {
        glVertex2i(lpntX[i], lpntY[i]);
    }
    glEnd();
}

void translateLine(int x, int y)
{
    glBegin(GL_LINES);
    glColor3f(0.0, 1.0, 0.0);
    for (int i = 0; i < vertices; i++)
    {
        glVertex2i(lpntX[i] + x, lpntY[i] + y);
    }
    glEnd();
}

void scaleLine(double x, double y)
{
    glBegin(GL_LINES);
    glColor3f(1.0, 1.0, 0.0);
    for (int i = 0; i < vertices; i++)
    {
        glVertex2i(round(lpntX[i] * x), round(lpntY[i] * y));
    }
    glEnd();
}

void rotateLine(double angleRad)
{
    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 1.0);
    //glVertex2i(round((0 * cos(angleRad)) - (lpntY[0] * sin(angleRad))), round((0 * sin(angleRad)) + (lpntY[0] * cos(angleRad))));
    for (int i = 0; i < vertices; i++)
    {
        glVertex2i(round((lpntX[i] * cos(angleRad)) - (lpntY[i] * sin(angleRad))), round((lpntX[i] * sin(angleRad)) + (lpntY[i] * cos(angleRad))));
    }
    glEnd();
}

void drawPolygon()
{
    glBegin(GL_QUADS);
    glColor3f(1.0, 0.0, 0.0);
    for (int i = 0; i < vertices; i++)
    {
        glVertex2i(pntX[i], pntY[i]);
    }
    glEnd();
}

void translatePolygon(int x, int y)
{
    glBegin(GL_QUADS);
    glColor3f(0.0, 1.0, 0.0);
    for (int i = 0; i < vertices; i++)
    {
        glVertex2i(pntX[i] + x, pntY[i] + y);
    }
    glEnd();
}

void rotatePolygon(double angleRad)
{
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 1.0);
    for (int i = 0; i < vertices; i++)
    {
        glVertex2i(round((pntX[i] * cos(angleRad)) - (pntY[i] * sin(angleRad))), round((pntX[i] * sin(angleRad)) + (pntY[i] * cos(angleRad))));
    }
    glEnd();
}

void scalePolygon(double x, double y)
{
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 0.0);
    for (int i = 0; i < vertices; i++)
    {
        glVertex2i(round(pntX[i] * x), round(pntY[i] * y));
    }
    glEnd();
}

void printMenu()
{
    cout << "1. Translation" << "\n";
    cout << "2. Rotation" << "\n";
    cout << "3. Scaling" << "\n";
    cout << "-1. exit" << "\n";
    cout << "Choose : " << "\n";
}



void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    int x, y;
    /*cin >> choice;

    while (choice != -1)
    {
        cout << "number of edges : ";
        cin >> vertices;

        for (int i = 1; i <= vertices; i++)
        {
            cout << "x coordinate : ";
            cin >> x;
            cout << "y coordinate : ";
            cin >> y;
            if (vertices == 2)
            {
                lpntx.push_back(x);
                lpntx.push_back(y);
            }
            else
            {
                pntx.push_back(x);
                pnty.push_back(y);
            }

        }
    }*/
    vertices = 4;
    for (int i = 1; i <= vertices; i++)
    {
        cout << "x coordinate : ";
        cin >> x;
        cout << "y coordinate : ";
        cin >> y;
        pntX.push_back(x);
        pntY.push_back(y);
    }

    cout << "Scaling\n";
    cout << "Scaling factor for x : ";
    cin >> x;
    cout << "Scaling factor for y : ";
    cin >> y;
    scalePolygon(x, y);

    drawPolygon();
    cout << "Translation\n";
    cout << "new x coordinate : ";
    cin >> x;
    cout << "new y coordinate : ";
    cin >> y;
    translatePolygon(x, y);

    cout << "Rotation\n";
    cout << "Degree : ";
    cin >> degree;
    rotatePolygon(degree * 3.1416 / 180);

    vertices = 2;
    for (int i = 1; i <= vertices; i++)
    {
        cout << "x coordinate : ";
        cin >> x;
        cout << "y coordinate : ";
        cin >> y;
        lpntX.push_back(x);
        lpntY.push_back(y);
    }

    cout << "Scaling\n";
    cout << "Scaling factor for x : ";
    cin >> x;
    cout << "Scaling factor for y : ";
    cin >> y;
    scaleLine(x, y);

    drawLine();
    cout << "Translation\n";
    cout << "new x coordinate : ";
    cin >> x;
    cout << "new y coordinate : ";
    cin >> y;
    translateLine(x, y);

    cout << "Rotation\n";
    cout << "Degree : ";
    cin >> degree;
    rotateLine(degree * 3.1416 / 180);

    /*vertices = 2;
    for (int i = 1; i <= vertices; i++)
    {
        cout << "x coordinate : ";
        cin >> x;
        cout << "y coordinate : ";
        cin >> y;
        lpntx.push_back(x);
        lpntx.push_back(y);
    }*/


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

// 0 0 400 0 400 200 0 200 2 2 50 50 120 -100 -100 -100 -300 2 2 60 60 45