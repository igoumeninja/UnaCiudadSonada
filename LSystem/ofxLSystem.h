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
 */

#pragma once

#include "ofMain.h"

class ofxLSystem {

	public: 

		ofxLSystem(); 
		ofImage				golondrina;

		void	setup();
		void	color();		
		void	update();
		void	recieveString();		
		void	golondrinas();		

		float	depthLength, depthLengthDefault, depthLengthScale, scale, theta, noise;
		string	lsystemString;	
		bool	startGeneration;
		


	private: 


}; 

