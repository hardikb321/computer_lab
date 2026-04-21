#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <GL/glut.h>
#include <vector>
#include <string>

struct KeyDef {
    float x, z, w, d, heightOffset;
    std::string label;
};

std::vector<KeyDef> keys;
const float UNIT = 0.5f;
const float GAP = 0.06f;

void addKey(float &cursorX, float z, float widthU, float depthU, std::string label) {
    float keyW = (widthU * UNIT) - GAP;
    float keyD = (depthU * UNIT) - GAP;
    float centerX = cursorX + (keyW / 2.0f);
    float centerZ = z + (keyD / 2.0f) - (UNIT / 2.0f);
    keys.push_back({centerX, centerZ, keyW, keyD, 0.0f, label});
    cursorX += widthU * UNIT;
}

void initKeyboard() {
    if(!keys.empty()) return; // Prevent initializing twice
    float cx = -3.75f, z = -1.5f;

    addKey(cx, z, 1.0f, 1.0f, "Esc"); cx += 0.5f;
    for(int i=0; i<12; i++) addKey(cx, z, 1.0f, 1.0f, "");
    
    z += UNIT + 0.1f; cx = -3.75f;
    for(int i=0; i<13; i++) addKey(cx, z, 1.0f, 1.0f, "");
    addKey(cx, z, 2.0f, 1.0f, "Bksp");

    z += UNIT; cx = -3.75f;
    addKey(cx, z, 1.5f, 1.0f, "Tab");
    for(int i=0; i<12; i++) addKey(cx, z, 1.0f, 1.0f, "");
    addKey(cx, z, 1.5f, 1.0f, "\\");

    z += UNIT; cx = -3.75f;
    addKey(cx, z, 1.75f, 1.0f, "Caps");
    for(int i=0; i<11; i++) addKey(cx, z, 1.0f, 1.0f, "");
    addKey(cx, z, 2.25f, 1.0f, "Enter");

    z += UNIT; cx = -3.75f;
    addKey(cx, z, 2.25f, 1.0f, "Shift");
    for(int i=0; i<10; i++) addKey(cx, z, 1.0f, 1.0f, "");
    addKey(cx, z, 2.75f, 1.0f, "Shift");

    z += UNIT; cx = -3.75f;
    addKey(cx, z, 1.25f, 1.0f, "Ctrl"); addKey(cx, z, 1.25f, 1.0f, "Win"); addKey(cx, z, 1.25f, 1.0f, "Alt");
    addKey(cx, z, 6.25f, 1.0f, " ");
    addKey(cx, z, 1.25f, 1.0f, "Alt"); addKey(cx, z, 1.25f, 1.0f, "Win"); addKey(cx, z, 1.25f, 1.0f, "Menu"); addKey(cx, z, 1.25f, 1.0f, "Ctrl");
}

void drawKeyboard() {
    // Baseplate
    glColor3f(0.08f, 0.08f, 0.08f);
    glPushMatrix();
    glTranslatef(0.0f, -0.2f, -0.2f);
    glScalef(7.8f, 0.2f, 3.3f);
    glutSolidCube(1.0);
    glPopMatrix();

    // Keys
    glColor3f(0.15f, 0.15f, 0.15f);
    for(auto &k : keys) {
        glPushMatrix();
        glTranslatef(k.x, k.heightOffset, k.z);
        glScalef(k.w, 0.25f, k.d);
        glutSolidCube(1.0);
        glPopMatrix();
    }
}
#endif
