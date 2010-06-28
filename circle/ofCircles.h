/*
 *  ofxCircles.h
 *  100519_Stasis
 *
 *  Created by fou on 5/21/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef _OF_CIRCLES// if this class hasn't been defined, the program can define it
#define _OF_CIRCLES // by using this if statement you prevent the class to be called more 
// than once which would confuse the compiler

#include "ofMain.h"


class ofCircles {
	
public: 
	
	ofCircles(); 
	void setup();
	void update();	
	void perimeterPoint();	
	void tangentI();		
	void tangentII();		
	void draw();
	
	float mx;
	float my;
	
	float	centerX, centerY, angle, radius;
	int		r,g,b,a;
	float	cx1, cy1, cx2, cy2, x2, y2;
	
	
	
private:
	
	
};


#endif 