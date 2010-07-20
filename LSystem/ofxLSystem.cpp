/*
 *  ofxLSystem.h
 *
 *  Created by Aris Bezas Fri, 18 June 2010, 03:48PM
 *
 * Create class to control LSystem development for string rewriting class RedLSystem (SuperCollider) 
 * L-Systems studies
 * RedLSystem: rewrite strings, simple string rewrite class.
 * RedLTurtle
 * new(lsystem, length, theta, scale, noise)
		lsystem - an instance of RedLSystem or a string.
		length - line segment length in pixels.  default 40.
		theta - angle in degrees.  default 20.
		scale - the amount to scale all moving commands ($F, $G, $|) in percent.  default 1.
		noise - the amount of uniform noise to add to all angles in radians.  default 0.

 * $F: draw forward
 * $G: go forward
 * $+: turn right by theta
 * $-: turn left by theta
 * $[: push state
 * $]: pop state
 * $|: draw forward scaled by depth
 * an integer before each character repeats that command n times.
 *
 *
 *	TODO
 *	*	Fix scale 
 *	*	Add noise parameter
 *	*	Adding your own commands
 *	*	Adding repetitions of a command
 *
 *	*	*	Special thanks to Till Bovermann, redFrik
 */

#include "ofMain.h"
#include "granCieloApp.h"
#include "ofxLSystem.h"

ofxLSystem::ofxLSystem()	{
}

void ofxLSystem::setup(){
	//golondrina.loadImage("images/golondrina.png");	
	golondrina.loadImage("images/mariposa100.png");		
	depthLengthDefault = 50;
	scale = 0.65;
	startGeneration = true;
}
void ofxLSystem::color(){
	ofFill();
//	ofSetColor(int(ofRandom(0,255)),int(ofRandom(0,255)),int(ofRandom(0,255)),255);
	ofSetColor(255,255,0,255);	
}
void ofxLSystem::recieveString(){
//	lsystemString = "";
	int j;
	depthLength = scale*depthLength;	
	ofPushMatrix();
	if	(startGeneration)	{	
//		depthLength = depthLengthDefault;		
		ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 0);			
	}
	color();
	for (j=0; j < lsystemString.length(); j++)	{
	//cout << lsystemString[j] << endl;
		if	(lsystemString[j] == 'F')	{
			//ofLine(0,0,0, - depthLength);
			ofCircle(0,0,3);
			ofTranslate(0, - depthLength, 0);				
		}
		if	(lsystemString[j] == 'G')	{
			ofTranslate(0, - depthLength, 0);						
		}
		if	(lsystemString[j] == '+')	{
			ofRotate(theta);
		}
		if	(lsystemString[j] == '-')	{
			ofRotate(-theta);
		}
		if	(lsystemString[j] == '[')	{
			ofPushMatrix();
		}
		if	(lsystemString[j] == ']')	{
			ofPopMatrix();
		}
		if	(lsystemString[j] == '|')	{
		//cout	<<	scale	<< endl;
			depthLengthScale = scale*depthLength;	
			ofLine(0,0,0, - depthLengthScale);
			ofTranslate(0, - depthLengthScale, 0);						
			depthLengthScale = depthLength;
		}
	}	
	ofPopMatrix();			
}
void ofxLSystem::golondrinas(){
//	lsystemString = "";
	int j;
	depthLength = scale*depthLength;	
	ofPushMatrix();
	if	(startGeneration)	{	
//		depthLength = depthLengthDefault;		
		ofTranslate(ofGetWidth()/2, ofGetHeight()/2, 0);			
	}
	color();
	for (j=0; j < lsystemString.length(); j++)	{
	//cout << lsystemString[j] << endl;
		if	(lsystemString[j] == 'F')	{
			ofSetColor(0xFFFFFF);
			//ofCircle(0,0,3);			
			golondrina.draw(0, 0);						
			ofTranslate(0, - depthLength, 0);				
		}
		if	(lsystemString[j] == 'G')	{
			ofTranslate(0, - depthLength, 0);						
		}
		if	(lsystemString[j] == '+')	{
			ofRotate(theta);
		}
		if	(lsystemString[j] == '-')	{
			ofRotate(-theta);
		}
		if	(lsystemString[j] == '[')	{
			ofPushMatrix();
		}
		if	(lsystemString[j] == ']')	{
			ofPopMatrix();
		}
		if	(lsystemString[j] == '|')	{
		//cout	<<	scale	<< endl;
			depthLengthScale = scale*depthLength;	
			ofLine(0,0,0, - depthLengthScale);
			ofTranslate(0, - depthLengthScale, 0);						
			depthLengthScale = depthLength;
		}
	}	
	ofPopMatrix();			
}
