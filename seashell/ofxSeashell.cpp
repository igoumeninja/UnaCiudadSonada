/*
 *  Seashell.cpp
 *  space3d
 *
 *  Created by fou fou on 1/2/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 *	control variables:  type(lines, points), du, dv, width, R, N, H, P, L, K
 *
 */

#include "granCieloApp.h"
//#include "ofxSeashell.h"

void ofxSeashell::init(int rSea, int gSea, int bSea, int aSea, float R, float N, float H, float P, float L, float K, float du, float dv, float seashellType, float seashellScale, float seashellSteps) {

	
	//	R = 8;	//	R = 2;
	//	N = 5,6;
	//	H = 4.5;
	//	P = 1.4;
	//	L = 4;
	//	K = 9;
	
	//	du = 0.005;
	//	dv = 0.0002;
	
	//seashellScale = 1;
	//printf(" %f \n", seashellType);	
	
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_LINE_SMOOTH);       	
	if	(seashellType)	{
		ofFill();
		ofSetColor(rSea, gSea, bSea, aSea);
		
		glBegin(GL_LINE_LOOP); //GL_LINE_LOOP,GL_POINTS, GL_LINE_STRIP  ( http://pyopengl.sourceforge.net/documentation/manual/glBegin.3G.xml )
	}	else	{
		ofNoFill();
		ofSetColor(rSea, gSea, bSea, aSea);
		
		glBegin(GL_POINTS); //GL_LINE_LOOP, GL_POINTS
	}
	
	//	glBegin(GL_POINTS);	//GL_POLYGON, GL_LINE_LOOP
	
    for (int i = 0; i < dim; i++)  {
		u = u + du;
		v = v + dv;
		ws[i] = seashellScale*(u/(2*PI)*R);  // great parameter here 0.9 plays with the width of the spiral 
		xs[i] = ws[i]*cos(N*u)*(1+cos(v));
		ys[i] = ws[i]*sin(N*u)*(1+cos(v));
		zs[i] = ws[i]*(sin(v)+L*powf((sin(v/2)),K))  + H*powf((u/(2*PI)),P);
		glVertex3f(xs[i], ys[i], zs[i]);				
//		for( int i=600; i<650 ; i++ ) {
//				sketch[i].drawMouse(xs[i], ys[i], 0, 0,0,0,255, 1);	
//		}				
	}
	glEnd();
	
	if ( u > seashellSteps)	{
		u = 0;
		for (int i = 0; i < dim; i++)  {
			xs[i] = 0;
			ys[i] = 0;
			zs[i] = 0;
		}
	}
	
	
}

// processing code
/*
 //	  spira1 = new Spiral(2,5.6,4.5,1.4,4,9);
 int dim = 50;
 int counter;
 float theta = 283.8, thetaX;
 float R,N,H,P,L,K,u,v,R2;
 float[] W = new float[dim];
 float[] Fx = new float[dim];
 float[] Fy = new float[dim];
 float[] Fz = new float[dim];
 
 Spiral(float RVar,float NVar,float HVar,float PVar,float LVar,float KVar)  {
 R = RVar;    // radius of tube
 N = NVar;  // number of turns
 H = HVar;  // height
 P = PVar;  // power
 L = LVar;    // Controls spike length
 K = KVar;    // Controls spike sharpness
 }
 void calcPoints()  {
 for (int i = 0; i < dim; i++)  {
 u = u + .005;
 v = v + .0002;
 W[i] = pow((u/(2*PI)*R), 0.9);  // great parameter here 0.9 plays with the width of the spiral 
 Fx[i] = W[i]*cos(N*u)*(1+cos(v));
 Fy[i] = W[i]*sin(N*u)*(1+cos(v));
 Fz[i] = W[i]*(sin(v)+L*pow((sin(v/2)),K))  + H*pow((u/(2*PI)),P);
 }
 }
 
 void render()  {
 fill(255);
 translate(width - 100, height - 100);
 rotateZ(theta/2);
 rotateY(theta);
 stroke(#9D9FD8,100);
 beginShape(TRIANGLE_STRIP);
 for (int i = 0; i < dim-1; i++)  {
 vertex(Fx[i],Fy[i],Fz[i]);
 }
 endShape();
 if (u > 360)  {
 v = u = 0;
 //theta = theta +30;
 }
 }
 }
 */
