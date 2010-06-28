/*
 *  ofxArbol.cpp
 *  Gran Cielo Project "Una ciudad sonada"
 *
 *  Created by Aris Bezas Sat, 12 June 2010, 12:04PM
 *
 *  Create arbol class for individual manipulation of arbol characteristics.
 *
 */
 
 
#include "ofMain.h"
#include "granCieloApp.h"
#include "ofxArbol.h"

ofxArbol::ofxArbol()	{
}

void ofxArbol::setup(){
	aa = -0.2;
	ab = 0.2;
	h = 125;
	turn = -1;
	leavesLenght = 30;
}
void ofxArbol::update(){
//	aa = - ofMap(mouseArbolX, 0, ofGetWidth(), 0.5, 0.001);
//	ab = ofMap(mouseArbolX, 0, ofGetWidth(), 0.001, 0.5);
	draw(ofGetWidth()/2,ofGetHeight(),-HALF_PI,5);
}
void ofxArbol::draw(float x, float y, float a, int c)	{
	float nx=x+h*cos(a); //h control height
	float ny=y+h*sin(-turn*a);
	ofFill();
	ofSetColor(0, 0, 0, 55);
	ofSetLineWidth(3);
	ofLine(x,y,nx,ny);
	ofSetColor(255, int(ofMap(mouseArbolX, 0, ofGetWidth(), 0, 255)),0, 55);
	ofEllipse(nx, ny, 15, 15);  
	ofEllipse(nx, ny, 20, 20);  
	ofSetLineWidth(1);
	ofSetColor(0,0,0,20);	
	ofNoFill();
	ofBezier(nx, ny, nx + ofRandom(-leavesLenght,leavesLenght), ny + ofRandom(-leavesLenght,leavesLenght), nx + ofRandom(-leavesLenght,leavesLenght), ny + ofRandom(-leavesLenght,leavesLenght), nx + ofRandom(-leavesLenght,leavesLenght), ny + ofRandom(-leavesLenght,leavesLenght));
	
	if (c>0) {
		draw(nx, ny, a+aa, c-1);
		draw(nx, ny, a+ab, c-1);
	}

}
