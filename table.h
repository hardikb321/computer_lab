#ifndef TABLE_H
#define TABLE_H
#include <GL/glut.h>

void drawTable() {
    // Table Top
    glPushMatrix();
        glColor3f(0.5f, 0.35f, 0.05f); // Brown
        glScalef(3.0f, 0.1f, 2.0f);   // Made slightly larger for the PC
        glutSolidCube(1.0);
    glPopMatrix();

    // Table Legs
    float legs[4][2] = { {1.4, 0.9}, {-1.4, 0.9}, {1.4, -0.9}, {-1.4, -0.9} };
    for(int i = 0; i < 4; i++) {
        glPushMatrix();
            glColor3f(0.3f, 0.2f, 0.1f); 
            glTranslatef(legs[i][0], -1.0f, legs[i][1]); // Moved down
            glScalef(0.1f, 2.0f, 0.1f); // Lengthened legs
            glutSolidCube(1.0);
        glPopMatrix();
    }
}
#endif
