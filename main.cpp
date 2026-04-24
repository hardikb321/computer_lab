#include <GL/glut.h>
#include <stdlib.h>

// Include our custom object files
#include "table.h"
#include "monitor.h"
#include "mouse.h"
#include "keyboard.h"
#include "chair.h" 
#include "cpu.h"
#include "wall.h"
#include "roof.h" 
#include "floor.h"

// Camera controls
float camX = 0.0f, camY = 3.0f, camZ = 16.0f; 
float lookX = 0.0f, lookY = 1.0f, lookZ = 0.0f;

// Rotation controls
float angleY = 0.0f; 
float angleX = 0.0f; 

// LIGHTING STATE
bool lightOn = true; 

void drawRoom() {
    

    // Draw the walls
    drawWalls(); 

    // Draw the roof
    drawRoof(); 
    drawFloor();
}

void drawComputerStation(float x, float z) {
    glPushMatrix();
    glTranslatef(x, 0.0f, z); 

   
    glPushMatrix();
    glTranslatef(0.0f, 0.50f, 0.0f); 

    // 1. Draw Table
    drawTable();

    // 2. Draw Monitor
    glPushMatrix();
    glTranslatef(0.0f, 0.05f, -0.5f); 
    glScalef(0.6f, 0.6f, 0.6f);       
    drawMonitor();
    glPopMatrix();

    // 3. Draw Keyboard
    glPushMatrix();
    glTranslatef(0.0f, 0.1f, 0.5f);   
    glScalef(0.15f, 0.15f, 0.15f);    
    drawKeyboard();                   
    glPopMatrix();

    // 4. Draw Mouse
    glPushMatrix();
    glTranslatef(0.8f, 0.1f, 0.5f);   
    glScalef(0.1f, 0.1f, 0.1f);       
    drawHardwareMouse();
    glPopMatrix();

    glPopMatrix(); 
 

    // 5. Draw Chair
    glPushMatrix();
    glTranslatef(0.0f, -0.8f, 2.2f);     
    glRotatef(180.0f, 0.0f, 1.0f, 0.0f); 
    glScalef(0.4f, 0.4f, 0.4f);          
    drawOfficeChair();
    glPopMatrix();

    // 6. Draw CPU Cabinet
    glPushMatrix();
    glTranslatef(1.2f, -0.8f, 0.0f); 
    glScalef(0.8f, 0.8f, 0.8f);       
    drawCPU();
    glPopMatrix();

    glPopMatrix(); 
}

void display() {
    // Dynamically change background color and light state based on toggle
    if (lightOn) {
        glClearColor(0.9f, 0.9f, 0.95f, 1.0f);
        glEnable(GL_LIGHT0);
    } else {
        glClearColor(0.05f, 0.05f, 0.05f, 1.0f); 
        glDisable(GL_LIGHT0);
    }

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Set Camera
    gluLookAt(camX, camY, camZ, lookX, lookY, lookZ, 0.0, 1.0, 0.0);

    // --- APPLY ROTATION TO THE WHOLE SCENE ---
    glPushMatrix(); 
    
    // Up/Down (X-axis) then Left/Right (Y-axis)
    glRotatef(angleX, 1.0f, 0.0f, 0.0f); 
    glRotatef(angleY, 0.0f, 1.0f, 0.0f); 

    drawRoom();

    // Setup 16 stations in a 4x4 Grid
    float startX = -7.5f; 
    float startZ = -9.0f; 
    float spacingX = 5.0f; 
    float spacingZ = 6.0f; 

    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            float posX = startX + (col * spacingX);
            float posZ = startZ + (row * spacingZ);
            drawComputerStation(posX, posZ);
        }
    }

    glPopMatrix(); 
    

    glutSwapBuffers();
}

void keyboardInput(unsigned char key, int x, int y) {
    switch(key) {
        // Movement
        case 'w': camZ -= 0.5; lookZ -= 0.5; break; 
        case 's': camZ += 0.5; lookZ += 0.5; break; 
        case 'a': camX -= 0.5; lookX -= 0.5; break; 
        case 'd': camX += 0.5; lookX += 0.5; break; 
        
        // Rotation
        case 'q': case 'Q': angleY -= 2.0f; break; 
        case 'e': case 'E': angleY += 2.0f; break; 
        case 'r': case 'R': angleX -= 2.0f; break; 
        case 'f': case 'F': angleX += 2.0f; break; 
        
        // TOGGLE LIGHTS
        case 'l': case 'L': lightOn = !lightOn; break; 
        
        case 27: exit(0);
    }
    glutPostRedisplay();
}

void init() {
    
    glEnable(GL_DEPTH_TEST);
    
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    
    GLfloat light_pos[] = { 0.0f, 10.0f, 5.0f, 1.0f }; 
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
}

void reshape(int w, int h) {
    if (h == 0) h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (float)w/h, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_MULTISAMPLE);
    glutInitWindowSize(1024, 768);
    glutCreateWindow("Integrated Computer Lab");

    init();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboardInput); 

    glutMainLoop();
    return 0;
}