/*
 *  ofxArbol.h
 *  Gran Cielo Project "Una ciudad sonada" 
 *
 *  Created by Aris Bezas Sat, 12 June 2010, 12:04PM
 *
 *  Create arbol class for individual manipulation of arbol characteristics.
 */

#pragma once

class ofxArbol {

	public: // place public functions or variables declarations here

		ofxArbol(); 

		void	setup();
		void	update();
		void	draw(float x, float y, float a, int c);

		float	aa, ab, h, turn;
		float	mouseArbolX, mouseArbolY;
		float	leavesLenght;

	private: // place private functions or variables declarations here


}; 


//#endif 