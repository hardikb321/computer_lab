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

    // Screen (WHITE)
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.18f);
    glColor3f(1.0f, 1.0f, 1.0f); // Screen Background
    drawMonitorCube(3.0, 1.7, 0.05);

    // --- Google Home Page Content ---
    glTranslatef(0.0f, 0.0f, 0.026f); // Move forward to avoid Z-fighting
    
    // TEMPORARILY DISABLE LIGHTING to prevent colors from washing out
    GLboolean lightState;
    glGetBooleanv(GL_LIGHTING, &lightState);
    glDisable(GL_LIGHTING);

    // 1. Search Bar (Black Outline)
    glPushMatrix();
    glTranslatef(0.0f, -0.2f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.0f); // Black outline
    glLineWidth(2.0f);           // Slightly thicker outline
    glPushMatrix();
    glScalef(1.8f, 0.25f, 0.01f);
    glutWireCube(1.0);           
    glPopMatrix();
    glLineWidth(1.0f);
    glPopMatrix();

    // 2. "search..." inside the search bar (Black Text)
    glPushMatrix();
    glTranslatef(-0.85f, -0.24f, 0.0f); 
    glScalef(0.0008f, 0.0008f, 1.0f); 
    glColor3f(0.0f, 0.0f, 0.0f);        
    const char* searchText = "search...";
    for (const char* c = searchText; *c != '\0'; c++) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
    }
    glPopMatrix();

    // 3. "Google.com" Text
    glPushMatrix();
    glTranslatef(-0.85f, 0.2f, 0.0f); // Shifted slightly for better visual centering
    glScalef(0.0015f, 0.0015f, 1.0f); 
    glLineWidth(2.0f);
    
    // Official Google Colors: Blue, Red, Yellow, Blue, Green, Red
    float gColors[6][3] = {
        {0.26f, 0.52f, 0.96f}, // G - Blue
        {0.92f, 0.26f, 0.21f}, // o - Red
        {0.98f, 0.73f, 0.02f}, // o - Yellow
        {0.26f, 0.52f, 0.96f}, // g - Blue
        {0.20f, 0.66f, 0.33f}, // l - Green
        {0.92f, 0.26f, 0.21f}  // e - Red
    };
    
    const char* gText = "Google";
    for (int i = 0; i < 6; i++) {
        glColor3fv(gColors[i]); // Apply specific color per character
        glutStrokeCharacter(GLUT_STROKE_ROMAN, gText[i]);
    }
    
    // Write ".com" in Black
    glColor3f(0.0f, 0.0f, 0.0f); 
    const char* comText = ".com";
    for (const char* c = comText; *c != '\0'; c++) {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, *c);
    }
    
    glLineWidth(1.0f); // Reset line width
    glPopMatrix();

    // RESTORE LIGHTING STATE after UI is drawn
    if (lightState) glEnable(GL_LIGHTING);
    // ---------------------------------------

    glPopMatrix(); // End Screen Content

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
