#ifndef MONITOR_H
#define MONITOR_H
#include <GL/glut.h>

void drawMonitorCube(float w, float h, float d) {
    glPushMatrix();
    glScalef(w, h, d);
    glutSolidCube(1.0);
    glPopMatrix();
}

void drawMonitor() {
    glPushMatrix();
    // Move up so the base sits perfectly on the table
    glTranslatef(0.0f, 2.4f, 0.0f); 

    // Bezel (DARK GREY)
    glColor3f(0.1f, 0.1f, 0.1f);
    drawMonitorCube(3.5, 2.2, 0.3);

    // Screen (BLUE)
    glPushMatrix();
    glTranslatef(0, 0, 0.18);
    glColor3f(0.0f, 0.5f, 1.0f);
    drawMonitorCube(3.0, 1.7, 0.05);
    glPopMatrix();

    // Neck
    glPushMatrix();
    glTranslatef(0, -1.6, 0);
    glColor3f(0.25f, 0.25f, 0.25f);
    drawMonitorCube(0.4, 1.2, 0.2);
    glPopMatrix();

    // Base
    glPushMatrix();
    glTranslatef(0, -2.3, 0.3);
    glColor3f(0.2f, 0.2f, 0.2f);
    drawMonitorCube(1.8, 0.2, 1.0);
    glPopMatrix();

    glPopMatrix();
}
#endif
