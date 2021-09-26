#include<windows.h>
#include<GL/glut.h>

void myInit()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Set background color to black and opaque
    //glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(3);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 800.0, 0.0, 600.0);
}

void display() {

    glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer

    // Points - 2
    glBegin(GL_POINTS);
    glColor3f(1.0f, 1.0f, 1.0f);
    // point 1
    glVertex2d(100, 500);
    // point 2
    glVertex2d(70, 540);
    glEnd();

    // lines - 2
    glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f);
    // line 1
    glVertex3f(150.0f, 500.0f, 0.0f); // origin of the line
    glVertex3f(200.0f, 560.0f, 0.0f); // ending point of the line
    // line 2
    glVertex2d(150, 560);
    glVertex2d(200, 500);
    glEnd();

    // line strip
    glBegin(GL_LINE_STRIP);
    glColor3d(127, 0, 255);
    glVertex2d(300, 550);
    glVertex2d(400, 500);
    glVertex2d(500, 550);
    glEnd();

    // line loop
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0f, 0.5f, 0.0f);
    glVertex2d(550, 500);
    glVertex2d(650, 500);
    glVertex2d(650, 550);
    glVertex2d(550, 550);
    glEnd();

    // triangle
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2d(70, 350);
    glVertex2d(140, 450);
    glVertex2d(210, 350);
    glEnd();

    // triangle strip
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2d(300, 300);
    glVertex2d(350, 300);
    glVertex2d(350, 350);
    glVertex2d(400, 300);
    glVertex2d(400, 350);
    glVertex2d(450, 350);
    glEnd();

    // triangle fan
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0f, 0.5f, 1.0f);
    glVertex2d(690, 300);
    glVertex2d(620, 360);
    glVertex2d(650, 400);
    glVertex2d(730, 400);
    glVertex2d(760, 360);
    glEnd();

    // quads
    glBegin(GL_QUADS);
    glColor3f(0.5f, 1.0f, 1.0f);
    glVertex2d(50, 150);
    glVertex2d(100, 200);
    glVertex2d(150, 200);
    glVertex2d(200, 150);
    glEnd();

    // quad strip
    glBegin(GL_QUAD_STRIP);
    glColor4f(1.0f, 1.0f, 0.0f, 0.0f);
    glVertex2d(300, 200);
    glVertex2d(300, 100);
    glVertex2d(350, 200);
    glVertex2d(350, 100);
    glVertex2d(450, 250);
    glVertex2d(450, 50);
    glEnd();

    // polygon
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2d(550, 150);
    glVertex2d(600, 200);
    glVertex2d(700, 200);
    glVertex2d(750, 150);
    glVertex2d(700, 100);
    glVertex2d(600, 100);
    glEnd();

    glFlush();  // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    glutInit(&argc, argv);                 // Initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,600);   // Set the window's initial width & height
    glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
    glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
    myInit();
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutMainLoop();           // Enter the infinitely event-processing loop
    return 0;
}