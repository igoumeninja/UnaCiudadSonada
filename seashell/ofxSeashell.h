/*
 *  Seashell.h
 *  space3d
 *
 *  Created by fou fou on 1/2/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "ofxSeashell.h"

#pragma once

#define dim	50

class ofxSeashell {
public:	
	float			ws[dim];
	float			xs[dim];
	float			ys[dim];
	float			zs[dim];		
	int				counter, rSea, gSea, bSea, aSea;
	float			theta, thetaX;
	float			R,N,H,P,L,K,u,v,R2;
	float			seashellType, seashellScale, seashellSteps;
	float			du,dv;
	ofxSketch			sketch[100];
	
	
    void init(int rSea, int gSea, int bSea, int aSea, float R, float N, float H, float P, float L, float K, float du, float dv, float seashellType, float seashellScale, float seashellSteps);
};


