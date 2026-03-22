#include <gl/glut.h>
#include <gl/gl.h>
#include <math.h>

#define PI 3.14159265358979323846

float car_x = -1.2f;      
float rotasi_roda = 0.0f;  
float awan = 0.0f; 

void drawCircle(float r, int points, bool filled) {
    if (filled) glBegin(GL_POLYGON);
    else glBegin(GL_LINE_LOOP);
    
    for (int i = 0; i < points; i++) {
        float angle = 2.0f * PI * i / points;
        glVertex2f(cos(angle) * r, sin(angle) * r);
    }
    glEnd();
}

void drawBackground() {
    glColor3f(0.53f, 0.81f, 0.98f); 
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -0.4f);
        glVertex2f(1.0f, -0.4f);
        glVertex2f(1.0f, 1.0f);
        glVertex2f(-1.0f, 1.0f);
    glEnd();

    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_QUADS);
        glVertex2f(-1.0f, -1.0f);
        glVertex2f(1.0f, -1.0f);
        glVertex2f(1.0f, -0.4f);
        glVertex2f(-1.0f, -0.4f);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(3.0f);
    glBegin(GL_LINES);
        for (float x = -0.9f; x < 1.0f; x += 0.3f) {
            glVertex2f(x, -0.7f);
            glVertex2f(x + 0.15f, -0.7f);
        }
    glEnd();
}


void drawCloud(float x, float y, float scale) {
    glPushMatrix();
    glTranslatef(x + awan, y, 0.0f); 
    glScalef(scale, scale, 1.0f);
    glColor3f(1.0f, 1.0f, 1.0f); 
    glPushMatrix(); drawCircle(0.1f, 20, true); 
	glPopMatrix();
    glPushMatrix(); glTranslatef(0.12f, 0.02f, 0.0f); 
	drawCircle(0.08f, 20, true); 
	glPopMatrix();
    glPushMatrix(); glTranslatef(-0.12f, 0.02f, 0.0f); 
	drawCircle(0.08f, 20, true); 
	glPopMatrix();
    glPushMatrix(); glTranslatef(0.0f, 0.08f, 0.0f); 
	drawCircle(0.07f, 20, true); 
	glPopMatrix();
    
    glPopMatrix();
}

void drawWheel(float r) {
    glPushMatrix();
    glRotatef(rotasi_roda, 0.0f, 0.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    drawCircle(r, 40, true);
    glColor3f(0.7f, 0.7f, 0.7f);
    drawCircle(r * 0.7f, 30, true);
    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(2.0f);
    glBegin(GL_LINES);
    for (int i = 0; i < 8; i++) {
        float angle = (float)i * (2.0f * PI / 8.0f);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(cos(angle) * r * 0.7f, sin(angle) * r * 0.7f);
    }
    glEnd();
    glPopMatrix();
}

void RenderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity(); 
    drawBackground();
    drawCloud(-0.6f, 0.7f, 1.2f);
    drawCloud(0.3f, 0.8f, 0.8f);
    drawCloud(0.8f, 0.6f, 1.0f);
    glPushMatrix();
    glTranslatef(car_x, -0.6f, 0.0f);
    glColor3f(1.0f, 0.71f, 0.75f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.35f, 0.0f);
        glVertex2f(0.35f, 0.0f);
        glVertex2f(0.35f, 0.12f);
        glVertex2f(0.15f, 0.12f);
        glVertex2f(0.10f, 0.25f); 
        glVertex2f(-0.15f, 0.25f);
        glVertex2f(-0.25f, 0.12f);
        glVertex2f(-0.35f, 0.12f);
    glEnd();

    glColor3f(0.7f, 0.9f, 1.0f); 
    glPushMatrix();
    glTranslatef(0.03f, 0.15f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.08f, 0.0f);
        glVertex2f(0.05f, 0.07f);
        glVertex2f(0.01f, 0.07f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.16f, 0.15f, 0.0f);
    glBegin(GL_QUADS);
        glVertex2f(0.0f, 0.0f);
        glVertex2f(0.12f, 0.0f);
        glVertex2f(0.11f, 0.07f);
        glVertex2f(0.03f, 0.07f);
    glEnd();
    glPopMatrix();
    glPointSize(10.0f);
    glBegin(GL_POINTS);
        glColor3f(1.0f, 1.0f, 0.0f);
        glVertex2f(0.35f, 0.06f);
    glEnd();

    glBegin(GL_POINTS);
        glColor3f(1.0f, 0.2f, 0.2f);
        glVertex2f(-0.35f, 0.06f);
    glEnd();

    glPushMatrix();
    glTranslatef(-0.2f, 0.0f, 0.0f); 
    drawWheel(0.07f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.2f, 0.0f, 0.0f); 
    drawWheel(0.07f);
    glPopMatrix();
    glPopMatrix(); 
    glutSwapBuffers(); 
}

void Timer(int value) {
    car_x += 0.01f;
    if (car_x > 1.3f) car_x = -1.3f;
    rotasi_roda -= 15.0f;
    if (rotasi_roda < -360.0f) rotasi_roda += 360.0f;
    awan += 0.0005f;
    if (awan > 0.5f) awan = -0.5f;
    glutPostRedisplay(); 
    glutTimerFunc(16, Timer, 0); 
}

void Init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Mobil 2D Primitif dengan Animasi & Stack");
    Init();
    glutDisplayFunc(RenderScene);
    glutTimerFunc(0, Timer, 0); 
    glutMainLoop();
    return 0;
}
