#ifndef MONITOR_H
#define MONITOR_H

#include <GL/glut.h>

void drawMonitorCube(float w, float h, float d) {
    glPushMatrix();
    glScalef(w, h, d);
    glutSolidCube(1.0);
    glPopMatrix();
}

void drawBitmapText(float x, float y, void *font, const char *text) {
    glRasterPos2f(x, y);
    for (const char *c = text; *c != '\0'; ++c) {
        glutBitmapCharacter(font, *c);
    }
}

void drawMonitor() {
    glPushMatrix();
    // Move up so the base sits perfectly on the table
    glTranslatef(0.0f, 2.4f, 0.0f);

    // Bezel (DARK GREY)
    glColor3f(0.1f, 0.1f, 0.1f);
    drawMonitorCube(3.5f, 2.2f, 0.3f);

    // Screen (Google homepage style)
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.18f);

    // Screen background
    glColor3f(1.0f, 1.0f, 1.0f);
    drawMonitorCube(3.0f, 1.7f, 0.05f);

    glDisable(GL_LIGHTING);

    // Google logo text
    glColor3f(0.2f, 0.2f, 0.2f);
    glPushMatrix();
    glTranslatef(-0.52f, 0.18f, 0.03f);
    drawBitmapText(0.0f, 0.0f, GLUT_BITMAP_HELVETICA_18, "Google");
    glPopMatrix();

    // Search bar
    glPushMatrix();
    glTranslatef(-0.92f, -0.08f, 0.03f);
    glColor3f(0.95f, 0.95f, 0.95f);
    drawMonitorCube(1.85f, 0.26f, 0.01f);
    glPopMatrix();

    // Search prompt inside the bar
    glColor3f(0.55f, 0.55f, 0.55f);
    glPushMatrix();
    glTranslatef(-0.82f, -0.12f, 0.04f);
    drawBitmapText(0.0f, 0.0f, GLUT_BITMAP_HELVETICA_12, "Search Google");
    glPopMatrix();

    glEnable(GL_LIGHTING);
    glPopMatrix();

    // Neck
    glPushMatrix();
    glTranslatef(0.0f, -1.6f, 0.0f);
    glColor3f(0.25f, 0.25f, 0.25f);
    drawMonitorCube(0.4f, 1.2f, 0.2f);
    glPopMatrix();

    // Base
    glPushMatrix();
    glTranslatef(0.0f, -2.3f, 0.3f);
    glColor3f(0.2f, 0.2f, 0.2f);
    drawMonitorCube(1.8f, 0.2f, 1.0f);
    glPopMatrix();

    glPopMatrix();
}

#endif
