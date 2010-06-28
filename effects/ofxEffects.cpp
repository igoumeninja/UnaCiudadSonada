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
}
void ofxEffects::start()	{
	translateY = ofGetHeight();
	ofTranslate(0, translateY, 0);
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
	translateY = translateY -1;
	ofSetLineWidth(1);
}