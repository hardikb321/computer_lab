#ifndef CHAIR_H
#define CHAIR_H
#include <GL/glut.h>
#include <cmath>

float chairSwivel = 15.0f; // Spin the seat slightly so it looks natural

// Renamed to avoid clashing with keyboard's drawBox
void drawChairBox(float w, float h, float d) {
    glPushMatrix();
    glScalef(w, h, d);
    glutSolidCube(1.0);
    glPopMatrix();
}

void drawChairCylinder(float baseRad, float topRad, float height) {
    GLUquadric* quad = gluNewQuadric();
    gluQuadricNormals(quad, GLU_SMOOTH);
    gluCylinder(quad, baseRad, topRad, height, 32, 32);
    gluDeleteQuadric(quad);
}

void drawOfficeChair() {
    float plasticColor[] = { 0.1f, 0.1f, 0.1f };
    float fabricColor[] = { 0.22f, 0.18f, 0.20f }; 

    glPushMatrix();

    // 1. BASE AND CASTERS
    glColor3fv(plasticColor);
    glPushMatrix();
    glTranslatef(0.0f, 0.3f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    drawChairCylinder(0.3f, 0.2f, 0.4f);
    glPopMatrix();

    for (int i = 0; i < 5; i++) {
        glPushMatrix();
        glRotatef(i * 72.0f, 0.0f, 1.0f, 0.0f);
        glTranslatef(0.8f, 0.3f, 0.0f);
        drawChairBox(1.6f, 0.15f, 0.2f);
        glTranslatef(0.7f, -0.1f, 0.0f);
        glutSolidSphere(0.15f, 16, 16);
        glTranslatef(0.0f, -0.05f, 0.0f);
        drawChairBox(0.1f, 0.3f, 0.3f);
        glPopMatrix();
    }

    // 2. SEAT ASSEMBLY (Swivels)
    glPushMatrix();
    glRotatef(chairSwivel, 0.0f, 1.0f, 0.0f);

    glColor3fv(plasticColor);
    glPushMatrix();
    glTranslatef(0.0f, 0.3f, 0.0f);
    glRotatef(-90.0f, 1.0f, 0.0f, 0.0f);
    drawChairCylinder(0.1f, 0.1f, 1.8f);
    glPopMatrix();

    glColor3fv(fabricColor);
    glPushMatrix();
    glTranslatef(0.0f, 2.1f, 0.2f);
    glScalef(2.0f, 0.3f, 2.2f);
    glutSolidSphere(1.0, 32, 32);
    glPopMatrix();

    glColor3fv(plasticColor);
    glPushMatrix();
    glTranslatef(0.0f, 1.8f, 0.0f);
    drawChairBox(1.0f, 0.4f, 1.0f);
    glPopMatrix();

    // 3. ARMRESTS
    glColor3fv(plasticColor);
    glPushMatrix();
    glTranslatef(-1.1f, 1.8f, 0.2f);
    drawChairBox(0.2f, 0.1f, 0.8f);
    glTranslatef(-0.2f, 0.6f, 0.0f);
    drawChairBox(0.15f, 1.2f, 0.2f);
    glTranslatef(0.0f, 0.6f, 0.2f);
    drawChairBox(0.3f, 0.15f, 1.2f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(1.1f, 1.8f, 0.2f);
    drawChairBox(0.2f, 0.1f, 0.8f);
    glTranslatef(0.2f, 0.6f, 0.0f);
    drawChairBox(0.15f, 1.2f, 0.2f);
    glTranslatef(0.0f, 0.6f, 0.2f);
    drawChairBox(0.3f, 0.15f, 1.2f);
    glPopMatrix();

    // 4. BACKREST
    glColor3fv(plasticColor);
    glPushMatrix();
    glTranslatef(0.0f, 1.9f, -0.8f);
    glRotatef(-15.0f, 1.0f, 0.0f, 0.0f);
    drawChairBox(0.4f, 1.5f, 0.15f);
    glPopMatrix();

    glColor3fv(fabricColor);
    glPushMatrix();
    glTranslatef(0.0f, 3.5f, -1.1f);
    glRotatef(-10.0f, 1.0f, 0.0f, 0.0f);
    glScalef(1.8f, 1.6f, 0.3f);
    glutSolidSphere(1.0, 32, 32);
    glPopMatrix();

    glPopMatrix(); // End Swivel
    glPopMatrix(); // End Chair
}
#endif
