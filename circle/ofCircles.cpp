/*
 *  ofxCircles.cpp
 *  100519_Stasis
 *
 *  Created by fou on 5/21/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "ofMain.h"
#include "granCieloApp.h"
#include "ofCircles.h"



ofCircles::ofCircles()	{
}
void ofCircles::setup()	{
	r = g = b = 0;
	cx1 = cy1 = cx2 = cy2 = x2 = y2 = 0;
	a = 20;
	centerX = ofGetScreenWidth()/2;
	centerY = ofGetScreenHeight()/2;	
	angle = 0;
	radius = 400;
}
void ofCircles::update()	{
	angle = ofRandom(0, 2*PI);
	cx1 = ofGetScreenWidth()/2 + radius*cos(angle);
	cy1 = ofGetScreenHeight()/2 + radius*sin(angle);

	draw();
}
void ofCircles::tangentI()	{
	angle = ofRandom(0, 2*PI);
	cx1 = ofGetScreenWidth()/2 + radius*cos(angle);
	cy1 = ofGetScreenHeight()/2 + radius*sin(angle);
	update();
}
void ofCircles::tangentII()	{
	angle = ofRandom(0, 2*PI);
	cx2 = ofGetScreenWidth()/2 + radius*cos(angle);
	cy2 = ofGetScreenHeight()/2 + radius*sin(angle);
	update();
}

void ofCircles::perimeterPoint()	{
	angle = ofRandom(0, 2*PI);
	x2 = ofGetScreenWidth()/2 + radius*cos(angle);
	y2 = ofGetScreenHeight()/2 + radius*sin(angle);
	update();
}
void ofCircles::draw()	{
	ofNoFill();
	ofSetColor(r,g,b,a);
	ofBezier(centerX, centerY, cx1, cy1, cx2, cy2, x2, y2);
}
