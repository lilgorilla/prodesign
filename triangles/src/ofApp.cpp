#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(2816, 1408);
    ofSetFrameRate(29);
    
    state1 = true;
    state2 = false;
    state3 = false;
    stateswitch = false;
    
    square = 176; //176, 16, 44
    squaretotalX = ofGetWidth() / square;
    squaretotalY = ofGetHeight()/ square;
    center.set(square/2, square/2);
    
    c = 1;
    colors[0] = ofColor(0,188,227); //blue
    colors[1] = ofColor(20,35,51); //navy
    colors[2] = ofColor(29,209,130); //green
    colors[3] = ofColor(232,232,232); //grey
    colors[4] = ofColor(244,244,245); //lightgrey
    previouscolor.set(colors[0]);
    
    tritwo_colors[3] = ofColor(0,188,227); //blue
    tritwo_colors[4] = ofColor(20,35,51); //navy
    tritwo_colors[0] = ofColor(29,209,130); //green
    tritwo_colors[1] = ofColor(232,232,232); //grey
    tritwo_colors[2] = ofColor(244,244,245); //lightgrey
    tritwo_previouscolor.set(tritwo_colors[0]);
    
    trione_tlc.set(0, 0);
    trione_trc.set(square,0);
    trione_blc.set(0, square);
    stlc.set(0, 0);
    strc.set(square, 0);
    sblc.set(0, square);
    
    tritwo_trc.set(square,0); tritwo_strc.set(square, 0);
    tritwo_blc.set(0, square); tritwo_sblc.set(0, square);
    tritwo_brc.set(square, square); tritwo_sbrc.set(square, square);
    

    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    if (state1) {
        trione_trc.x--;
        trione_trc.y++;
        tritwo_blc.x++;
        tritwo_blc.y--;
        if (trione_trc.y > square) {
            trione_trc.set(square, 0);
            tritwo_blc.set(0, square);
            state1 = false;
            state2 = true;
            stateswitch = true;
        }
    }
    if (state2) {
        trione_blc.y--;
        tritwo_trc.y++;
        if (trione_blc.y<0) {
            trione_blc.y = square;
            tritwo_trc.y = 0;
            state2 = false;
            state3 = true;
            stateswitch = true;
        }
    }
    if (state3) {
        trione_tlc.x++;
        tritwo_brc.x--;
        if (trione_tlc.x > square) {
            trione_tlc.x = 0;
            tritwo_brc.x = square;
            state3 = false;
            state1 = true;
            stateswitch = true;
        }
    }
    if (stateswitch) {
        stateswitch = false;
        previouscolor.set(colors[c]);
        tritwo_previouscolor.set(tritwo_colors[c]);
        if (c<4) {
            c++;
        } else{
            c=0;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    for (int i=0; i<=squaretotalX; i++) {
        for (int j=0; j<=squaretotalY; j++) {
            ofPushMatrix();
            ofTranslate(square*i, square*j);
                // TRI ONE
                ofSetColor(colors[c]);
                ofBeginShape();
                    ofVertex(stlc.x, stlc.y);
                    ofVertex(strc.x, strc.y);
                    ofVertex(sblc.x, sblc.y);
                ofEndShape();
                
                ofSetColor(previouscolor);
                ofBeginShape();
                    ofVertex(trione_tlc.x, trione_tlc.y);
                    ofVertex(trione_trc.x, trione_trc.y);
                    ofVertex(trione_blc.x, trione_blc.y);
                ofEndShape();
                
                // TRI TWO
                ofSetColor(tritwo_colors[c]);
                ofBeginShape();
                    ofVertex(tritwo_sbrc);
                    ofVertex(tritwo_sblc);
                    ofVertex(tritwo_strc);
                ofEndShape();
                
                ofSetColor(tritwo_previouscolor);
                ofBeginShape();
                    ofVertex(tritwo_brc);
                    ofVertex(tritwo_blc);
                    ofVertex(tritwo_trc);
                ofEndShape();
            ofPopMatrix();
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}