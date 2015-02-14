#pragma once

#include "ofMain.h"

class Polygon3d{
public:
    ofVec3f mPolygonPosition = ofVec3f(0, 0, 0);
    int mPolygonSize = 0;
    int mPolygonType = 0;   //0: Box, 1:Sphere
    
    Polygon3d(){
        mPolygonPosition = ofVec3f(ofRandom(-2000,2000),
                                   ofRandom(-2000,2000),
                                   ofRandom(-2000,2000));
        mPolygonSize = floor(ofRandom(10,100));
        mPolygonType = floor(ofRandom(2));
        //floor =床 切り捨て ceil = 天井 切り上げ
    };  //constructorー作るとき
    ~Polygon3d(){
    
    };  //destructorー消すとき
    
    void draw() {
        if(mPolygonType == 0){
            ofBoxPrimitive boxPremitive;
            boxPremitive.setPosition(mPolygonPosition);
            boxPremitive.set(mPolygonSize);
            boxPremitive.drawWireframe();
        }else if(mPolygonType==1){
            //ofSpherePrimitive
            ofSpherePrimitive spherePrimitive;
            spherePrimitive.setPosition(mPolygonPosition);
            spherePrimitive.setRadius(mPolygonSize);
            spherePrimitive.drawWireframe();
        }
    }
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofBoxPrimitive box;
    ofSpherePrimitive sphere;
    
    ofEasyCam easyCom;
    ofCamera camera;
    
    vector <Polygon3d *>polygons;

};
