#ifndef ROOF_H
#define ROOF_H

#include <GL/glut.h>

// Allows us to read the global light state from main.cpp!
extern bool lightOn; 

void drawRoof() {
    // 1. Draw the Main Ceiling (Off-white)
    glColor3f(0.9f, 0.9f, 0.9f); 
    glBegin(GL_QUADS);
    // Placed at Y = 8.0 to match the top of your walls
    glVertex3f(-15.0f, 8.0f,  15.0f);
    glVertex3f( 15.0f, 8.0f,  15.0f);
    glVertex3f( 15.0f, 8.0f, -15.0f);
    glVertex3f(-15.0f, 8.0f, -15.0f);
    glEnd();

    // 2. Draw Fluorescent Light Panels
    // We disable lighting temporarily so the panels look flat
    glDisable(GL_LIGHTING); 
    
    // --- CHANGED: Check if lights are on or off ---
    if (lightOn) {
        glColor3f(1.0f, 1.0f, 1.0f); // Bright white when ON
    } else {
        glColor3f(0.2f, 0.2f, 0.2f); // Dark gray when OFF
    }
    // ----------------------------------------------
    
    glBegin(GL_QUADS);
    // Create a 3x3 grid of lights across the ceiling
    for (float x = -10.0f; x <= 10.0f; x += 10.0f) {
        for (float z = -10.0f; z <= 10.0f; z += 10.0f) {
            // Drop panels slightly below the ceiling (7.95f) to prevent z-fighting
            glVertex3f(x - 2.0f, 7.95f, z + 0.5f);
            glVertex3f(x + 2.0f, 7.95f, z + 0.5f);
            glVertex3f(x + 2.0f, 7.95f, z - 0.5f);
            glVertex3f(x - 2.0f, 7.95f, z - 0.5f);
        }
    }
    glEnd();
    
    // Re-enable lighting for the rest of the scene
    glEnable(GL_LIGHTING);
}

#endif