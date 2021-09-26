#include<windows.h>
#include<gl/glut.h>
#include<cstdlib>
#include<iostream>

using namespace std;

void myInit()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glPointSize(1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
    glClear(GL_COLOR_BUFFER_BIT);
}

void display(void)
{
    float dy, dx, step, x, y, k, Xin, Yin;
    float x1, Y1, x2, y2;
    float current_y, current_x, offset1, offset2;
    bool canDraw = false;

    
    x1 = x2 = 0;
    Y1 = y2 = current_y = 5;

    while(current_y < 500)
    {
        while(true){
            offset2 = (rand() % 30) + 5;
            x1 = x2 + offset2;
            Y1 = y2 + offset2;
            offset2 = (rand() % 50) + 20;
            x2 = x1 + offset2;
            y2 = Y1 + offset2;
            dx = x2 - x1;
            dy = y2 - Y1;
            //cout << x1 << " " << Y1 << " " << x2 << " " << y2;
            if (x1 < 500 && Y1 < 500 && x2 < 500 && y2 < 500)
            {
                if (abs(dx) > abs(dy))
                {
                    step = abs(dx);
                }
                else
                    step = abs(dy);

                Xin = dx / step;
                Yin = dy / step;

                x = x1;
                y = Y1;
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
            else
            {
                //cout << "break\n";
                break;
            }      
        }
        offset1 = (rand() % 50) + 10;
        Y1 = y2 = current_y + offset1;
        current_y = Y1;
        x1 = x2 = 0;
        //cout << current_y << "\n";
    }

    x1 = x2 = current_x = 20;
    Y1 = y2 = 0;
    while (current_x < 500)
    {
        while (true) {
            offset2 = (rand() % 30) + 5;
            x1 = x2 + offset2;
            Y1 = y2 + offset2;
            offset2 = (rand() % 50) + 20;
            x2 = x1 + offset2;
            y2 = Y1 + offset2;
            dx = x2 - x1;
            dy = y2 - Y1;
            if (x1 < 500 && Y1 < 500 && x2 < 500 && y2 < 500)
            {
                if (abs(dx) > abs(dy))
                {
                    step = abs(dx);
                }
                else
                    step = abs(dy);

                Xin = dx / step;
                Yin = dy / step;

                x = x1;
                y = Y1;
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
            else
            {
                break;
            }
        }
        offset1 = (rand() % 50) + 10;
        x1 = x2 = current_x + offset1;
        current_x = x1;
        Y1 = y2 = 0;
    }

    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);                 // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutCreateWindow("Pattern using DDA line algo"); // Create a window with the given title
    myInit();
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop();           // Enter the infinitely event-processing loop
    return 0;
}
