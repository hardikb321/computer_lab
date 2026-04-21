#ifndef FLOOR_H
#define FLOOR_H

#include <GL/glut.h>

void drawFloor() {
    // 1. Draw a single, solid floor base (Light grey)
    glColor3f(0.8f, 0.8f, 0.8f); 
    glNormal3f(0.0f, 1.0f, 0.0f); // Point the normal up for lighting
    
    glBegin(GL_QUADS);
    glVertex3f(-15.0f, -1.5f,  15.0f);
    glVertex3f( 15.0f, -1.5f,  15.0f);
    glVertex3f( 15.0f, -1.5f, -15.0f);
    glVertex3f(-15.0f, -1.5f, -15.0f);
    glEnd();

    // 2. Draw the grid lines
    // Disable lighting temporarily so the lines render as a flat, solid color
    glDisable(GL_LIGHTING);
    
    glColor3f(0.5f, 0.5f, 0.5f); // Medium-dark grey for the lines
    glLineWidth(1.5f); // Make the lines slightly thicker
    
    // Set the Y coordinate slightly higher than the floor to prevent z-fighting (glitching)
    float lineY = -1.49f; 
    float spacing = 1.5f; // How far apart the lines should be
    
    glBegin(GL_LINES);
    
    // Draw lines running front-to-back (along Z-axis)
    for(float x = -15.0f; x <= 15.0f; x += spacing) {
        glVertex3f(x, lineY, -15.0f);
        glVertex3f(x, lineY,  15.0f);
    }
    
    // Draw lines running left-to-right (along X-axis)
    for(float z = -15.0f; z <= 15.0f; z += spacing) {
        glVertex3f(-15.0f, lineY, z);
        glVertex3f( 15.0f, lineY, z);
    }
    
    glEnd();
    
    // Re-enable lighting for the rest of the scene
    glEnable(GL_LIGHTING); 
}

#endif
