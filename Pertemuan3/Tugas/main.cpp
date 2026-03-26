#include <GL/glut.h>


// Variabel rotasi
static int shoulder = 0, elbow = 0;
static int wrist = 0, finger = 0;

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity(); 
    glTranslatef(0.0, 0.0, -8.0); 
    glColor3f(1.0, 1.0, 1.0);

	//lengan
    glPushMatrix(); 
		//bahu
        glTranslatef(-1.0, 0.0, 0.0);
        glRotatef((GLfloat) shoulder, 0.0, 0.0, 1.0);
        glTranslatef(1.0, 0.0, 0.0);
		//lengan atas
        glPushMatrix();
            glScalef(2.0, 0.4, 1.0);
            glutWireCube(1.0);
        glPopMatrix();
		//siku
        glTranslatef(1.0, 0.0, 0.0);
        glRotatef((GLfloat) elbow, 0.0, 0.0, 1.0);
        glTranslatef(1.0, 0.0, 0.0);
		//lengan bawah
        glPushMatrix();
            glScalef(2.0, 0.4, 1.0);
            glutWireCube(1.0);
        glPopMatrix();
		//telapak tangan
        glTranslatef(1.0, 0.0, 0.0);
        glRotatef((GLfloat) wrist, 0.0, 0.0, 1.0);
        glTranslatef(0.5, 0.0, 0.0);
        glPushMatrix();
            glScalef(1.0, 0.4, 0.6); // Sedikit lebih lebar agar proporsional
            glutWireCube(1.0);
        glPopMatrix();
		
		//jari
        glTranslatef(0.5, 0.0, 0.0);
        float yPos[] = {0.15, 0.05, -0.05, -0.15};
        for (int i = 0; i < 4; i++) {
            glPushMatrix();
                glTranslatef(0.0, yPos[i], 0.0);

                glRotatef((GLfloat) finger, 0.0, 0.0, 1.0);
                glTranslatef(0.15, 0.0, 0.0);
                glPushMatrix();
                    glScalef(0.3, 0.08, 0.1);
                    glutWireCube(1.0);
                glPopMatrix();

                glTranslatef(0.15, 0.0, 0.0);
                glRotatef((GLfloat) finger, 0.0, 0.0, 1.0);
                glTranslatef(0.15, 0.0, 0.0);
                glPushMatrix();
                    glScalef(0.3, 0.08, 0.1);
                    glutWireCube(1.0);
                glPopMatrix();
            glPopMatrix();
        }

        glPushMatrix();
            glTranslatef(-0.3, -0.2, 0.0); 
            glRotatef(-45.0, 0.0, 0.0, 1.0); 

            glRotatef((GLfloat) finger, 0.0, 0.0, 1.0);
            glTranslatef(0.15, 0.0, 0.0);
            glPushMatrix();
                glScalef(0.3, 0.1, 0.1);
                glutWireCube(1.0);
            glPopMatrix();

            glTranslatef(0.15, 0.0, 0.0);
            glRotatef((GLfloat) finger, 0.0, 0.0, 1.0);
            glTranslatef(0.1, 0.0, 0.0);
            glPushMatrix();
                glScalef(0.2, 0.1, 0.1);
                glutWireCube(1.0);
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 's': shoulder = (shoulder + 5) % 360; break;
        case 'S': shoulder = (shoulder - 5) % 360; break;
        case 'e': elbow = (elbow + 5) % 360; break;
        case 'E': elbow = (elbow - 5) % 360; break;
        case 'w': wrist = (wrist + 5) % 360; break;
        case 'W': wrist = (wrist - 5) % 360; break;
        case 'f': finger = (finger + 5) % 90; break;  
        case 'F': finger = (finger - 5) % 90; break;
        case 27: exit(0); break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Pergerakan Lengan & Jari");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}
