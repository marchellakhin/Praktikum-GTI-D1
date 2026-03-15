#include <GL/glut.h>

void Kubus(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.3f, 0.6f, 0.9f);
    glBegin(GL_QUADS);

    glVertex2f(-0.6,-0.6); 
	glVertex2f(-0.2,-0.6); 
	glVertex2f(-0.2,-0.2); 
	glVertex2f(-0.6,-0.2);

    glVertex2f(-0.2,-0.6); 
	glVertex2f(0.2,-0.6); 
	glVertex2f(0.2,-0.2); 
	glVertex2f(-0.2,-0.2);

    glVertex2f(0.2,-0.6); 
	glVertex2f(0.6,-0.6); 
	glVertex2f(0.6,-0.2); 
	glVertex2f(0.2,-0.2);

    glVertex2f(-0.4,-0.2); 
	glVertex2f(0.0,-0.2); 
	glVertex2f(0.0,0.2); 
	glVertex2f(-0.4,0.2);

    glVertex2f(0.0,-0.2); 
	glVertex2f(0.4,-0.2); 
	glVertex2f(0.4,0.2); 
	glVertex2f(0.0,0.2);

    glVertex2f(-0.2,0.2); 
	glVertex2f(0.2,0.2); 
	glVertex2f(0.2,0.6); 
	glVertex2f(-0.2,0.6);

    glEnd();
    glFlush();

    glColor3f(0.0f,0.0f,0.0f);
    glLineWidth(1);

    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.6,-0.6); 
	glVertex2f(-0.2,-0.6); 
	glVertex2f(-0.2,-0.2); 
	glVertex2f(-0.6,-0.2);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.2,-0.6); 
	glVertex2f(0.2,-0.6); 
	glVertex2f(0.2,-0.2); 
	glVertex2f(-0.2,-0.2);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(0.2,-0.6); 
	glVertex2f(0.6,-0.6); 
	glVertex2f(0.6,-0.2); 
	glVertex2f(0.2,-0.2);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.4,-0.2); 
	glVertex2f(0.0,-0.2); 
	glVertex2f(0.0,0.2); 
	glVertex2f(-0.4,0.2);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(0.0,-0.2); 
	glVertex2f(0.4,-0.2); 
	glVertex2f(0.4,0.2); 
	glVertex2f(0.0,0.2);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.2,0.2); 
	glVertex2f(0.2,0.2); 
	glVertex2f(0.2,0.6); 
	glVertex2f(-0.2,0.6);
    glEnd();
    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutCreateWindow("Kubus Bertingkat");

    glutDisplayFunc(Kubus);

    glClearColor(1.0f, 0.8f, 0.9f, 1.0f);

    glutMainLoop();
    return 0;
}
