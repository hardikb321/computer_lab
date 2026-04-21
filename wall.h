#ifndef WALL_H
#define WALL_H

#include <GL/glut.h>

void drawWalls() {
    // 1. Draw the Main Walls (Light Beige/Cream)
    glBegin(GL_QUADS);
    
    // Back Wall (at Z = -15.0)
    glColor3f(0.9f, 0.85f, 0.8f); 
    glVertex3f(-15.0f, -1.5f, -15.0f);
    glVertex3f( 15.0f, -1.5f, -15.0f);
    glVertex3f( 15.0f,  8.0f, -15.0f); // Height of 8.0
    glVertex3f(-15.0f,  8.0f, -15.0f);

    // Left Wall (at X = -15.0)
    glColor3f(0.85f, 0.8f, 0.75f); // Slightly darker to simulate corner shadows
    glVertex3f(-15.0f, -1.5f,  15.0f);
    glVertex3f(-15.0f, -1.5f, -15.0f);
    glVertex3f(-15.0f,  8.0f, -15.0f);
    glVertex3f(-15.0f,  8.0f,  15.0f);

    // Right Wall (at X = 15.0)
    glColor3f(0.85f, 0.8f, 0.75f); 
    glVertex3f( 15.0f, -1.5f, -15.0f);
    glVertex3f( 15.0f, -1.5f,  15.0f);
    glVertex3f( 15.0f,  8.0f,  15.0f);
    glVertex3f( 15.0f,  8.0f, -15.0f);
    
    glEnd();

    // 2. Draw Baseboard Trim (Dark Brown)
    glColor3f(0.3f, 0.2f, 0.1f);
    glBegin(GL_QUADS);
    
    // Back trim
    glVertex3f(-14.9f, -1.5f, -14.9f); // Pulled slightly forward (0.1f) to prevent z-fighting
    glVertex3f( 14.9f, -1.5f, -14.9f);
    glVertex3f( 14.9f, -1.0f, -14.9f);
    glVertex3f(-14.9f, -1.0f, -14.9f);

    // Left trim
    glVertex3f(-14.9f, -1.5f,  14.9f);
    glVertex3f(-14.9f, -1.5f, -14.9f);
    glVertex3f(-14.9f, -1.0f, -14.9f);
    glVertex3f(-14.9f, -1.0f,  14.9f);

    // Right trim
    glVertex3f( 14.9f, -1.5f, -14.9f);
    glVertex3f( 14.9f, -1.5f,  14.9f);
    glVertex3f( 14.9f, -1.0f,  14.9f);
    glVertex3f( 14.9f, -1.0f, -14.9f);
    
    glEnd();
}

#endif
