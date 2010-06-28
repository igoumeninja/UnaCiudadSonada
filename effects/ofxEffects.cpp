/*
 *  ofxEffects.cpp
 *  GranCieloProject
 *
 *  Created by fou on 6/23/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "ofMain.h"
#include "granCieloApp.h"
#include "ofxEffects.h"


ofxEffects::ofxEffects()	{	}

void ofxEffects::setup()	{
	translateY = ofGetHeight();
	translateX = ofGetWidth();		
}
void ofxEffects::start()	{
	translateY = ofGetHeight();
	ofTranslate(0, translateY, 0);
	translateX = ofGetWidth();
	ofTranslate(translateX, 0, 0);
}
void ofxEffects::color(){
	ofFill();
//	ofSetColor(int(ofRandom(0,255)),int(ofRandom(0,255)),int(ofRandom(0,255)),255);
	ofSetColor(255,255,255,255);	
}


void ofxEffects::drawLine()	{	
	color();
	ofTranslate(0, translateY, 0);
	//ofRect(0,0,ofGetWidth(), 20);
	ofSetLineWidth(10);
	ofLine(0,0,ofGetWidth(), 0);
	translateY = translateY - 10;
	ofSetLineWidth(1);
}

void ofxEffects::drawLineVertical()	{	
	color();
	ofTranslate(translateX, 0, 0);
	//ofRect(0,0,ofGetWidth(), 20);
	ofSetLineWidth(10);
	ofLine(0,0,0,ofGetHeight());
	translateX = translateX - 1;
	ofSetLineWidth(1);
}