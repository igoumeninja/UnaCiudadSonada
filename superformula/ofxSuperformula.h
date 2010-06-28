/*
 *  Superformula.h
 *  superformula
 *
 *  Created by fou fou on 1/2/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once


class ofxSuperformula {
public:	
	float			x, y, xf, yf, r, th, step, epi;
	float			m, n1, n2, n3, a, b, type;	
	int				redF, greenF, blueF, alphaF;
	int				num;
	
    void			init(float xf, float yf, int redF, int greenF, int blueF, int alphaF, float m, float n1, float n2, float n3, float step, int epi, int num, float sformType);

};

