#ifndef MOUSE_H
#define MOUSE_H
#include <GL/glut.h>

void drawHardwareMouse() {
    glPushMatrix();
    
    // Body
    glColor3f(0.08f, 0.08f, 0.08f);
    glPushMatrix();
    glScalef(1.2f, 0.5f, 1.8f);
    glutSolidSphere(0.8, 32, 32);
    glPopMatrix();

    // Scroll Wheel
    glColor3f(0.02f, 0.02f, 0.02f);
    glPushMatrix();
    glTranslatef(0.0f, 0.34f, -0.7f);
    glRotatef(90.0f, 0.0f, 1.0f, 0.0f);
    glutSolidTorus(0.06, 0.15, 16, 16);
    glPopMatrix();

    glPopMatrix();
}
#endif
