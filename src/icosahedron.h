#pragma once

#include "ofMain.h"

const int X2 = 58;
const int Z2 = 250;

const int X = 219;
const int Y = 96;
const int Z = 158;


static GLfloat vdata[12][3] = {
    {-X, 0.0, Z},{X, 0.0, Z}, {-X, 0.0, -Z}, {X, 0.0, -Z},
    {0.0, Z, X}, {0.0, Z, -X}, {0.0, -Z, X}, {0.0, -Z, -X},
    {Z, X, 0.0}, {-Z, X, 0.0}, {Z, -X, 0.0}, {-Z, -X, 0.0} };

static GLfloat vdata2[12][3] = {
{-X2, 0.0, Z2},{X2, 0.0, Z2}, {-X2, 0.0, -Z2}, {X2, 0.0, -Z2},
{0.0, Z2, X2}, {0.0, Z2, -X2}, {0.0, -Z2, X2}, {0.0, -Z2, -X2},
{Z2, X2, 0.0}, {-Z2, X2, 0.0}, {Z2, -X2, 0.0}, {-Z2, -X2, 0.0} };

static GLint indices[20][3] = {
    {0,4,1}, {0,9,4}, {9,5,4},{4,5,8},{4,8,1},{8,10,1},{8,3,10},{5,3,8},{5,2,3},{2,7,3},{7,10,3},{7,6,10},{7,11,6},{11,0,6},{0,1,6},{6,1,10},{9,0,11},{9,11,2},{9,2,5},{7,2,11}};

class icosahedron : public ofBaseApp{
public:
    float ang, ang2;
    ofMesh mesh, mesh2;
    ofImage myImage, myPhoto;
    void setup();
    void update();
    void draw();
    void keyReleased(int key);
    ofColor readBackground(float x, float y);
};
