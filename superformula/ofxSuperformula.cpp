/*
 *  Superformula.cpp
 *  superformula
 *
 *  Created by fou fou on 1/2/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "granCieloApp.h"
#include "ofxSuperformula.h"

void ofxSuperformula::init(float xf, float yf, int redF, int greenF, int blueF, int alphaF, float m, float n1, float n2, float n3, float step, int epi, int num, float sformType) {	
	//th=0;
	b=1,a=1; 
	
	ofNoFill();
	ofSetColor(redF, greenF, blueF, alphaF);
	ofBeginShape();
	for(int i=1; i < num; i++) {
		r = epi * powf( ( ( powf( labs( cos( (m*th)/4 ) /a ), n2 ) ) + ( powf( labs( sin( m*th/4) /b ), n3) ) ),(-1/n1));  
		th = th + step;
		x = xf + r*cos(th);
		y = yf + r*sin(th);
		ofCurveVertex(x,y);
	}
	ofEndShape();
	
	if	(th > 10*360)	{
		th = 0;
	}
}
