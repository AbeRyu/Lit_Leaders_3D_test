#include "ofApp.h"
#define NUM_OF_POLYGONS 200

//--------------------------------------------------------------
void ofApp::setup(){
    ofEnableDepthTest();
    // z軸の前後の判定を直してくれるやーつ。
    
    for (int i = 0; i < NUM_OF_POLYGONS ; i++){
        polygons.push_back(new Polygon3d);
    }
    
    //for debugging
//    for(int i = 0; i < NUM_OF_POLYGONS ;i++){
//        cout << i << ": " << polygons.at(i)->mPolygonPosition << endl;
//    }
}

//--------------------------------------------------------------
void ofApp::update(){
    camera.setPosition(2000*cos((double)ofGetElapsedTimeMillis()/500), 0, 2000*sin((double)ofGetElapsedTimeMillis()/500));
    camera.lookAt(ofVec3f(0,0,0));
    
    //半径1の円において　(x,y) = (cosθ,sinθ);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2 , 0);
    
    camera.begin();

    /*
    box.setPosition(0, 0, 0);
    box.set(100);
    ofSetColor(255);
    box.drawWireframe();
    */
    
    
    //Polygon3d polygon1 = Polygon3d();
    /*
    polygon1.mPolygonPosition = ofVec3f(100,300,-200);
    polygon1.mPolygonSize = 300;
    polygon1.mPolygonType = 0;
    */
    //polygon1.draw();
    
    for(int i = 0; i < NUM_OF_POLYGONS ; i++){
        ofSetColor(ofRandom(255), ofRandom(255), ofRandom(255));
        polygons.at(i)->draw();
        
        //ofSetColor(255);
        //ofLine(ofVec3f(0,0,0), polygons.at(i)->mPolygonPosition);
        
        ofSetColor(255,0,0);
        if(i != 0){
            ofLine(polygons.at(i-1)->mPolygonPosition,polygons.at(i)->mPolygonPosition);
        }
    }
    
    camera.end();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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
