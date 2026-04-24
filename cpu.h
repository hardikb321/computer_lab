#ifndef CPU_H
#define CPU_H

#include <GL/glut.h>
#include <math.h>

// Draws a standard desktop CPU cabinet/tower
void drawCPU() {
    // 1. Main Case Body (Dark Grey/Black)
    glColor3f(0.15f, 0.15f, 0.15f);
    
    glBegin(GL_QUADS);
    // Front face
    glVertex3f(-0.25f, 0.0f,  0.5f);
    glVertex3f( 0.25f, 0.0f,  0.5f);
    glVertex3f( 0.25f, 1.2f,  0.5f);
    glVertex3f(-0.25f, 1.2f,  0.5f);
    
    // Back face
    glVertex3f(-0.25f, 0.0f, -0.5f);
    glVertex3f( 0.25f, 0.0f, -0.5f);
    glVertex3f( 0.25f, 1.2f, -0.5f);
    glVertex3f(-0.25f, 1.2f, -0.5f);
    
    // Top face
    glVertex3f(-0.25f, 1.2f, -0.5f);
    glVertex3f( 0.25f, 1.2f, -0.5f);
    glVertex3f( 0.25f, 1.2f,  0.5f);
    glVertex3f(-0.25f, 1.2f,  0.5f);
    
    // Bottom face
    glVertex3f(-0.25f, 0.0f, -0.5f);
    glVertex3f( 0.25f, 0.0f, -0.5f);
    glVertex3f( 0.25f, 0.0f,  0.5f);
    glVertex3f(-0.25f, 0.0f,  0.5f);
    
    // Left face
    glVertex3f(-0.25f, 0.0f, -0.5f);
    glVertex3f(-0.25f, 0.0f,  0.5f);
    glVertex3f(-0.25f, 1.2f,  0.5f);
    glVertex3f(-0.25f, 1.2f, -0.5f);
    
    // Right face
    glVertex3f( 0.25f, 0.0f, -0.5f);
    glVertex3f( 0.25f, 0.0f,  0.5f);
    glVertex3f( 0.25f, 1.2f,  0.5f);
    glVertex3f( 0.25f, 1.2f, -0.5f);
    glEnd();

    // 2. CD/DVD Drive Bay at the top front
    glColor3f(0.05f, 0.05f, 0.05f);
    glBegin(GL_QUADS);
    glVertex3f(-0.20f, 0.9f, 0.51f); 
    glVertex3f( 0.20f, 0.9f, 0.51f);
    glVertex3f( 0.20f, 1.1f, 0.51f);
    glVertex3f(-0.20f, 1.1f, 0.51f);
    glEnd();

    // 3. Power Button (Red, based on reference images)
    glColor3f(0.8f, 0.1f, 0.1f); 
    glBegin(GL_POLYGON);
    // Draw a small circle
    for(int i = 0; i < 360; i += 10) {
        float theta = i * 3.14159f / 180.0f;
        glVertex3f(0.0f + 0.06f * cos(theta), 0.5f + 0.06f * sin(theta), 0.51f);
    }
    glEnd();
    
    // 4. Front Panel Vents/Details
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_QUADS);
    glVertex3f(-0.15f, 0.2f, 0.51f);
    glVertex3f( 0.15f, 0.2f, 0.51f);
    glVertex3f( 0.15f, 0.3f, 0.51f);
    glVertex3f(-0.15f, 0.3f, 0.51f);
    glEnd();
}

#endif
