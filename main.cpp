#include "ofMain.h"
#include "granCieloApp.h"
#include "ofAppGlutWindow.h"

//========================================================================
int main( ){

    ofAppGlutWindow window;
	//ofSetupOpenGL(&window, 640,480, OF_WINDOW);			// <-------- setup the GL context  1920x1080
	//ofSetupOpenGL(&window, 1000, 500, OF_WINDOW);			// <-------- setup the GL context  1920x1080
	//ofSetupOpenGL(&window, 3840, 1024, OF_WINDOW);	// Matrox 3 proyectores3840, 1024
	ofSetupOpenGL(&window, 3840, 1024, OF_FULLSCREEN);	// Matrox 3 proyectores3840, 1024	//ofSetupOpenGL(&window, 300, 300, OF_WINDOW);			// <-------- setup the GL context  1920x1080	//ofSetupOpenGL(&window, 1920, 1080, OF_WINDOW);			// projector
	//ofSetupOpenGL(&window, 1600, 1200, OF_WINDOW);			// projector
	// this kicks off the running of my app	
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp( new granCieloApp());

}
