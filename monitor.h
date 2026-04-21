#ifndef MONITOR_H
#define MONITOR_H
#include <GL/glut.h>
#include <string>

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
    drawMonitorCube(3.5, 2.2, 0.3);

    // Screen (Google homepage style)
    glPushMatrix();
    glTranslatef(0, 0, 0.18);

    // White screen background
    glColor3f(1.0f, 1.0f, 1.0f);
    drawMonitorCube(3.0, 1.7, 0.05);

    // Draw UI elements on top of the screen
    glDisable(GL_LIGHTING);
    glColor3f(0.0f, 0.0f, 0.0f);

    // Google logo text
    glPushMatrix();
    glTranslatef(-0.62f, 0.28f, 0.03f);
    glScalef(0.0015f, 0.0015f, 1.0f);
    glColor3f(0.2f, 0.2f, 0.2f);
    drawBitmapText(0, 0, GLUT_BITMAP_TIMES_ROMAN_24, "Google");
    glPopMatrix();

    // Search bar
    glPushMatrix();
    glTranslatef(-0.95f, -0.05f, 0.03f);
    glColor3f(0.95f, 0.95f, 0.95f);
    drawMonitorCube(1.9f, 0.28f, 0.01f);
    glPopMatrix();

    // Search bar outline
    glPushMatrix();
    glTranslatef(-0.95f, -0.05f, 0.031f);
    glColor3f(0.75f, 0.75f, 0.75f);
    glutWireCube(0.0); // no-op placeholder, keeps same structure
    glPopMatrix();

    // Search text
    glPushMatrix();
    glTranslatef(-0.87f, -0.09f, 0.04f);
    glScalef(0.0012f, 0.0012f, 1.0f);
    glColor3f(0.5f, 0.5f, 0.5f);
    drawBitmapText(0, 0, GLUT_BITMAP_HELVETICA_18, "Search Google or type a URL");
    glPopMatrix();

    glEnable(GL_LIGHTING);
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
