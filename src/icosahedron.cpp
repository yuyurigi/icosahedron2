#include "icosahedron.h"

//--------------------------------------------------------------
void icosahedron::setup(){
    ofSetVerticalSync(true);

    //myPhoto.load("gradient1.png"); //get color
    //myPhoto.load("gradient2.png");
    myPhoto.load("gradient3.png");
    
    //mesh 1
    for (int i=0; i<12; ++i) {
        mesh.addVertex(ofVec3f(vdata[i][0], vdata[i][1], vdata[i][2]));
        int ii = ofMap(i, 0, 12, 0, 800);
        ofColor myc = readBackground(ii, ii);
        myc.a = ofRandom(100, 150);
        mesh.addColor(myc);
    }
    for (int i=0; i<20; ++i) {
        int r = ofRandom(20);
        int r2 = ofRandom(20);
        int r3 = ofRandom(20);
        mesh.addIndex(indices[r][0]);
        mesh.addIndex(indices[r2][1]);
        mesh.addIndex(indices[r3][2]);
    }
     
    
    //mesh2
    for (int i=0; i<12; ++i) {
        mesh2.addVertex(ofVec3f(vdata2[i][0], vdata2[i][1], vdata2[i][2]));
        int ii = ofMap(i, 0, 12, 0, 800);
        ofColor myc2 = readBackground(ii, ii);
        myc2.a = ofRandom(100, 150);
        mesh2.addColor(myc2);
    }
    
    for (int i=0; i<20; ++i) {
        int r = ofRandom(20);
        int r2 = ofRandom(20);
        int r3 = ofRandom(20);
        mesh2.addIndex(indices[r][0]);
        mesh2.addIndex(indices[r2][1]);
        mesh2.addIndex(indices[r3][2]);
    }
     
}

//--------------------------------------------------------------
void icosahedron::update(){
    ang+=0.5;
    ang2-=0.5;
    
    /*
    if ((ofGetFrameNum()%6) == 0) {
        mesh.clearIndices();
     
        for (int i=0; i<20; ++i) {
            int r = ofRandom(20);
            int r2 = ofRandom(20);
            int r3 = ofRandom(20);
            mesh.addIndex(indices[r][0]);
            mesh.addIndex(indices[r2][1]);
            mesh.addIndex(indices[r3][2]);
        }
        
        mesh2.clearIndices();
        for (int i=0; i<20; ++i) {
            int r = ofRandom(20);
            int r2 = ofRandom(20);
            int r3 = ofRandom(20);
            mesh2.addIndex(indices[r][0]);
            mesh2.addIndex(indices[r2][1]);
            mesh2.addIndex(indices[r3][2]);
        }
         
    }
    */
}

//--------------------------------------------------------------
void icosahedron::draw(){
    ofBackground(241, 240, 238);
    ofEnableDepthTest();
    
    //mesh1
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 0);
    ofScale(1.2);
    ofRotateDeg(ang, 1.0, 1.0, 1.0);
    mesh.drawFaces();
    ofPopMatrix();
    
    //mesh2
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 0);
    ofScale(1.2);
    ofRotateDeg(ang2, 1.0, 1.0, 1.0);
    mesh2.drawFaces();
    ofPopMatrix();
    
    ofDisableDepthTest();
    
    myImage.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
}
//--------------------------------------------------------------
void icosahedron::keyReleased(int key){
    if (key == 'S' || key == 's') {
        myImage.save(ofGetTimestampString("%Y%m%d%H%M%S")+"##.png");
    }
}

//--------------------------------------------------------------
ofColor icosahedron::readBackground(float x, float y){
    ofPixels pixels = myPhoto.getPixels();
    ofColor c = pixels.getColor(x, y);
    return c;
    
}
