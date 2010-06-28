/*
 *  ofxEffects.h
 *  GranCieloProject
 *
 *  Created by fou on 6/23/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#pragma once

#include "ofMain.h"

class ofxEffects {

	public: 

		ofxEffects(); 

		void	setup();
		void	color();		
		void	start();
		void	drawLine();		
		void	drawLineVertical();				

		int translateY, translateX;
	private: 


}; 

