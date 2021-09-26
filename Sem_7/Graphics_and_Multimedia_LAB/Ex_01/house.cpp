#include <windows.h>  // For MS Windows
#include <GL/glut.h>

void myInit()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    //glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(3);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0, 0.0, 600.0);
}

// glVertex2d();

void display() {
    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer

    // house basic outline block
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.855f, 0.725f);
    glVertex2d(200, 400);
    glVertex2d(200, 100);
    glVertex2d(600, 100);
    glVertex2d(600, 400);
    glEnd();

    // door
    glBegin(GL_QUADS); 
    glColor3f(0.7f, 0.0f, 0.0f); 
    glVertex2d(300, 300);
    glVertex2d(300, 100);
    glVertex2d(400, 100);
    glVertex2d(400, 300); 
    glEnd();

    // window outline
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.0f, 0.0f);
    glVertex2d(450, 300);
    glVertex2d(450, 200);
    glVertex2d(550, 200);
    glVertex2d(550, 300);
    glEnd();

    // chimney
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.0f, 0.0f);
    glVertex2d(510, 520);
    glVertex2d(510, 400);
    glVertex2d(550, 400);
    glVertex2d(550, 520);
    glEnd();

    // step
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.0f, 0.0f);
    glVertex2d(280, 120);
    glVertex2d(280, 100);
    glVertex2d(420, 100);
    glVertex2d(420, 120);
    glEnd();

    // window vertical inside line
    glBegin(GL_LINES);
    glColor3f(0.3f, 0.0f, 0.0f);
    glVertex2d(500, 200);
    glVertex2d(500, 300);
    glEnd();

    // window horizontal inside line
    glBegin(GL_LINES);
    glColor3f(0.3f, 0.0f, 0.0f);
    glVertex2d(450, 250);
    glVertex2d(550, 250);
    glEnd();

    // door nob
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2d(390, 190);
    glEnd();

    // roof
    glBegin(GL_TRIANGLES);
    glColor3f(0.7f, 0.0f, 0.0f);
    glVertex2d(170, 400);
    glVertex2d(630, 400);
    glVertex2d(400, 550);
    glEnd();

    glFlush();  // Render now
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);                 // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutCreateWindow("OpenGL House build"); // Create a window with the given title
    myInit();
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop();           // Enter the infinitely event-processing loop
    return 0;
}