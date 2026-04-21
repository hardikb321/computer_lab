#ifndef ROOF_H
#define ROOF_H

#include <GL/glut.h>

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
    // We disable lighting temporarily so the panels look like they are glowing bright white
    glDisable(GL_LIGHTING); 
    glColor3f(1.0f, 1.0f, 1.0f); 
    
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
