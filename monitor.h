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

    // --- ADDED: Google Home Page Content ---
    // Move slightly forward in Z to draw on top of the screen surface 
    // (Screen depth is 0.05, so the front face is at 0.025. Using 0.026 avoids z-fighting)
    glTranslatef(0.0f, 0.0f, 0.026f); 

    // 1. Search Bar (White flat rectangle)
    glPushMatrix();
    glTranslatef(0.0f, -0.2f, 0.0f);     // Positioned below the center
    glColor3f(1.0f, 1.0f, 1.0f);         // White color 
    drawMonitorCube(1.8f, 0.25f, 0.01f); // Keeps width at 1.8 to stay inside the 3.0 wide screen
    glPopMatrix();

    // 2. "google.com" Text
    glPushMatrix();
    glTranslatef(-0.85f, 0.2f, 0.0f); // Shifted left to center the string, placed above search bar
    glScalef(0.0015f, 0.0015f, 1.0f); // Scale down the large stroke font to fit the screen
    glColor3f(1.0f, 1.0f, 1.0f);      // White text
    
    glLineWidth(2.0f); // Make text a bit thicker to read easily
    const char* text = "google.com";
    for (const char* c = text; *c != '\0'; c++) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
    }
    glLineWidth(1.0f); // Reset line width to default
    
    glPopMatrix();
    // ---------------------------------------

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
