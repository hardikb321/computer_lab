#include <GL/glut.h>

// Camera controls
float camX = 0.0f, camY = 3.0f, camZ = 15.0f;
float lookX = 0.0f, lookY = 2.0f, lookZ = 0.0f;

// --- REPLACE THESE WITH YOUR ACTUAL OBJECT CODE ---
void drawTable() {
    glColor3f(0.5, 0.3, 0.1); // Brown
    // Dummy table top
    glPushMatrix();
    glTranslatef(0, 1.5, 0);
    glScalef(3, 0.2, 2);
    glutSolidCube(1.0);
    glPopMatrix();
}

void drawChair() {
    glColor3f(0.2, 0.2, 0.8); // Blue
    // Dummy chair seat
    glPushMatrix();
    glTranslatef(0, 0.8, 0);
    glScalef(1, 0.2, 1);
    glutSolidCube(1.0);
    glPopMatrix();
}

void drawKeyboard() {
    glColor3f(0.8, 0.8, 0.8); // Light Grey
    glPushMatrix();
    glScalef(1.2, 0.1, 0.4);
    glutSolidCube(1.0);
    glPopMatrix();
}

void drawMouse() {
    glColor3f(0.9, 0.1, 0.1); // Red
    glPushMatrix();
    glScalef(0.2, 0.1, 0.3);
    glutSolidCube(1.0);
    glPopMatrix();
}
// ---------------------------------------------------

// Function to draw the room (Floor and 3 Walls)
void drawRoom() {
    // Floor
    glColor3f(0.3, 0.3, 0.3); // Dark Grey
    glBegin(GL_QUADS);
    glVertex3f(-10.0, 0.0,  10.0);
    glVertex3f( 10.0, 0.0,  10.0);
    glVertex3f( 10.0, 0.0, -10.0);
    glVertex3f(-10.0, 0.0, -10.0);
    glEnd();

    // Back Wall
    glColor3f(0.7, 0.7, 0.7); // Light Grey Wall
    glBegin(GL_QUADS);
    glVertex3f(-10.0, 0.0, -10.0);
    glVertex3f( 10.0, 0.0, -10.0);
    glVertex3f( 10.0, 5.0, -10.0);
    glVertex3f(-10.0, 5.0, -10.0);
    glEnd();
}

// Function to assemble ONE complete computer station
void drawComputerStation(float x, float z) {
    glPushMatrix(); // Save the room's coordinates
    
    // Move to the specific location in the room
    glTranslatef(x, 0.0, z);

    // 1. Draw Table at base location
    drawTable();

    // 2. Draw Chair (pushed back a bit on the Z axis)
    glPushMatrix();
    glTranslatef(0, 0, 1.5); 
    drawChair();
    glPopMatrix();

    // 3. Draw Keyboard (on top of the table)
    glPushMatrix();
    glTranslatef(0, 1.6, 0.5); // Move up to table height
    drawKeyboard();
    glPopMatrix();

    // 4. Draw Mouse (next to the keyboard)
    glPushMatrix();
    glTranslatef(0.8, 1.6, 0.5); 
    drawMouse();
    glPopMatrix();

    glPopMatrix(); // Go back to the room's global coordinates
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Set the camera
    gluLookAt(camX, camY, camZ, lookX, lookY, lookZ, 0.0, 1.0, 0.0);

    // Draw the environment
    drawRoom();

    // Assemble the Lab (Place 4 stations around the room)
    drawComputerStation(-4.0, -4.0); // Back Left
    drawComputerStation( 4.0, -4.0); // Back Right
    drawComputerStation(-4.0,  2.0); // Front Left
    drawComputerStation( 4.0,  2.0); // Front Right

    glutSwapBuffers();
}

// Let the user "walk" around the lab
void keyboard(unsigned char key, int x, int y) {
    switch(key) {
        case 'w': camZ -= 0.5; lookZ -= 0.5; break; // Walk forward
        case 's': camZ += 0.5; lookZ += 0.5; break; // Walk backward
        case 'a': camX -= 0.5; lookX -= 0.5; break; // Walk left
        case 'd': camX += 0.5; lookX += 0.5; break; // Walk right
        case 27: exit(0); // Escape key
    }
    glutPostRedisplay();
}

void init() {
    glEnable(GL_DEPTH_TEST); // Make sure front objects hide back objects
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("3D Computer Lab");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
