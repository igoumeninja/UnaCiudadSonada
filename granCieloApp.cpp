#include "granCieloApp.h"
#include "ofxSketch.h"

void granCieloApp::setup(){
	{
		//	FBO
		defaultFBO = false;
		fbo0 = fbo1 = fbo2 = fbo3 = fbo4 = fbo5 = fbo6 = fbo7 = fbo8 = fbo9 = false;
		fbo10 = fbo11 = fbo12 = fbo13 = fbo14 = fbo15 = fbo16 = fbo17 = fbo18 = fbo19 = false;
		fbo20 = fbo21 = fbo22 = fbo23 = fbo24 = fbo25 = fbo26 = fbo27 = fbo28 = fbo29 = false;				
		afbo6 = 0, afbo7 = 0, afbo8 = 0, alphaFBO2 = 0;
		viewFlores6 = viewFlores21 = viewFlores13 = viewFlores14 = false;
				
		//	Arbol
		arbolView = 0;
		
		//	MIDI
		a1 = 255;
		a2 = 255;
		a3 = 8;
		a4 = 8;
		a5 = 70;
		a6 = 40;
		a7 = 140;
		a8 = 18; //for Blending:  GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA  a8=18 (oriaka)
		r1 = 255;
		g1 = b1 = 0;
		r2 = g2 = b2 = 0;
		r3 = g3 = b3 = 0;
		r4 = g4 = b4 = 0;
		r5 = g5 = b5 = 0;
		r6 = g6 = b6 = 0;
		r7 = g7 = b8 = 255;
		r8 = g8 = b8 = 0;				
		viewSoundChanels = 0;
		midi85 = midi93 = 127;
		
		drawWithMouse = 1;
		numMouseSketches = 99;
		minMouseElasticity = 0.0;
		maxMouseElasticity = 0.99;
		minMouseDamping = 0.0;
		maxMouseDamping = 0.99;
		
		numSoundSketches = 99;
		minSoundElasticity = 0.0;
		maxSoundElasticity = 0.99;
		minSoundDamping = 0.0;
		maxSoundDamping = 0.99;
		
		mouseLines = 0;
		soundLines = 0;
		
		ampInLow =0;
		ampInHigh = 0.15;
		freqInLow = 120;
		freqInHigh = 4000;
		
		snapCounter = 3;
		r = 300; sr = r/2;
		x1 = sx1 = ofGetScreenWidth()/2;
		y1 = sy1 = ofGetScreenHeight()/2;
		th1 = sth1 = ofRandom(0, 2*PI);
		th2 = sth2 = ofRandom(0, 2*PI);
		
		seashellR = 4; 
		seashellN = 5.6;
		seashellH = 4.5;
		seashellP = 1.4;
		seashellL = 4;
		seashellK = 9;
		seashellDu = 0.005; 
		seashellDv = 0.0002;
		seashellType = 0;
		seashellScale = 1;
		seashellSteps = 300;
		
		sformM = 1;
		sformn1 =  1;
		sformn2 =  0;
		sformn3 =  0;
		sformStep =  0.1;
		sformScale = 200;
		sformNum = 100;
		sformType = 0;
		
		feedbackView = 0;
		feedbackSpeedX = 0;
		feedbackSpeedY = 0;
		timeLine = 0;
		viewRotate = 0;
				
		view_fillBackground = 1;
	
		beatsView = 1;
		
		strPosX = strPosY = 200;
		}
	Effect.setup();	//	Effects
	LSystem.setup();	//	LSystem
	{
	//##############################################
	//
	//                  Deseo
	//
	//
	deseo = "just  pull";
	//
	//
	//
	//##############################################
	}
	{
		doRender = true;

		rm0.allocateForNScreens(1, 320, 280); //the first dedicate the screens
		rm0.loadFromXml("xml/fboSettings0.xml");
		quad0  = ofRectangle(1000,400,200,200);
		rm1.allocateForNScreens(2, 3507, 1350); //the first dedicate the screensf
		rm1.loadFromXml("xml/fboSettings1.xml");
		quad1  = ofRectangle(1000,400,200,200);
		rm2.allocateForNScreens(2, 322,422); //the first dedicate the screens
		rm2.loadFromXml("xml/fboSettings2.xml");
		quad2  = ofRectangle(1000,400,200,200);
		rm3.allocateForNScreens(2, 320,280); //the first dedicate the screens the other 2 are the dimension of the image or of the video
		rm3.loadFromXml("xml/fboSettings3.xml");
		quad3  = ofRectangle(1000,400,200,200);
		rm4.allocateForNScreens(2, 400, 396); //the first dedicate the screens the other 2 are the dimension of the image or of the video
		rm4.loadFromXml("xml/fboSettings4.xml");
		quad4  = ofRectangle(1000, 400, 200, 200);		
		rm5.allocateForNScreens(1, 430, 660); //the first dedicate the screens the other 2 are the dimension of the image or of the video
		rm5.loadFromXml("xml/fboSettings5.xml");
		quad5  = ofRectangle(1000, 400, 200, 200);
		rm6.allocateForNScreens(1, 500, 500); //the first dedicate the screens the other 2 are the dimension of the image or of the video
		rm6.loadFromXml("xml/fboSettings6.xml");
		quad6  = ofRectangle(1000,400, 200, 200);
		rm7.allocateForNScreens(3, 500, 500); //the first dedicate the screens the other 2 are the dimension of the image or of the video
		rm7.loadFromXml("xml/fboSettings7.xml");
		quad7  = ofRectangle(1000,400, 200, 200);
		rm8.allocateForNScreens(2, 500, 500); //the first dedicate the screens the other 2 are the dimension of the image or of the video
		rm8.loadFromXml("xml/fboSettings8.xml");
		quad8  = ofRectangle(1000,400, 200, 200);
		rm9.allocateForNScreens(2, 500, 500); //the first dedicate the screens the other 2 are the dimension of the image or of the video
		rm9.loadFromXml("xml/fboSettings9.xml");
		quad9  = ofRectangle(1000,400, 200, 200);

		rm10.allocateForNScreens(2, 500, 500); //the first dedicate the screens
		rm10.loadFromXml("xml/fboSettings10.xml");
		quad10  = ofRectangle(1000,400,200,200);
		rm11.allocateForNScreens(2, 500, 500); //the first dedicate the screens
		rm11.loadFromXml("xml/fboSettings11.xml");
		quad11  = ofRectangle(1000,400,200,200);
		rm12.allocateForNScreens(2, 500, 500); //the first dedicate the screens
		rm12.loadFromXml("xml/fboSettings12.xml");
		quad12  = ofRectangle(1000,400,200,200);
		rm13.allocateForNScreens(1, 500, 500); //the first dedicate the screens
		rm13.loadFromXml("xml/fboSettings13.xml");
		quad13  = ofRectangle(1000,400,200,200);
		rm14.allocateForNScreens(1, 500, 500); //the first dedicate the screens
		rm14.loadFromXml("xml/fboSettings14.xml");
		quad14  = ofRectangle(1000, 400, 200, 200);		
		rm15.allocateForNScreens(2, 500, 500); //the first dedicate the screens
		rm15.loadFromXml("xml/fboSettings15.xml");
		quad15  = ofRectangle(1000, 400, 200, 200);
		rm16.allocateForNScreens(1, 500, 500); //the first dedicate the screens
		rm16.loadFromXml("xml/fboSettings16.xml");
		quad16  = ofRectangle(1000,400, 200, 200);
		rm17.allocateForNScreens(1, 500, 500); //the first dedicate the screens the other 2 are the dimension of the image or of the video
		rm17.loadFromXml("xml/fboSettings17.xml");
		quad17  = ofRectangle(1000,400, 200, 200);
		rm18.allocateForNScreens(1, 500, 500); //the first dedicate the screens the other 2 are the dimension of the image or of the video
		rm18.loadFromXml("xml/fboSettings18.xml");
		quad18  = ofRectangle(1000,400, 200, 200);
		rm19.allocateForNScreens(2, 500, 500); //the first dedicate the screens the other 2 are the dimension of the image or of the video
		rm19.loadFromXml("xml/fboSettings19.xml");
		quad19  = ofRectangle(1000,400, 200, 200);

		rm20.allocateForNScreens(2, 500, 500); //the first dedicate the screens
		rm20.loadFromXml("xml/fboSettings20.xml");
		quad20  = ofRectangle(1000,400,200,200);
		rm21.allocateForNScreens(1, 500, 500); //the first dedicate the screens
		rm21.loadFromXml("xml/fboSettings21.xml");
		quad21  = ofRectangle(1000,400,200,200);
		rm22.allocateForNScreens(1, 500, 500); //the first dedicate the screens
		rm22.loadFromXml("xml/fboSettings22.xml");
		quad22  = ofRectangle(1000,400,200,200);
		rm23.allocateForNScreens(1, 500, 500); //the first dedicate the screens
		rm23.loadFromXml("xml/fboSettings23.xml");
		quad23  = ofRectangle(1000,400,200,200);
		rm24.allocateForNScreens(2, 500, 500); //the first dedicate the screens
		rm24.loadFromXml("xml/fboSettings24.xml");
		quad24  = ofRectangle(1000, 400, 200, 200);		
		rm25.allocateForNScreens(2, 500, 500); //the first dedicate the screens
		rm25.loadFromXml("xml/fboSettings25.xml");
		quad25  = ofRectangle(1000, 400, 200, 200);
		rm26.allocateForNScreens(1, 500, 500); //the first dedicate the screens
		rm26.loadFromXml("xml/fboSettings26.xml");
		quad26  = ofRectangle(1000,400, 200, 200);
		rm27.allocateForNScreens(2, 500, 500); //the first dedicate the screens the other 2 are the dimension of the image or of the video
		rm27.loadFromXml("xml/fboSettings27.xml");
		quad27  = ofRectangle(1000,400, 200, 200);
		rm28.allocateForNScreens(1, 500, 500); //the first dedicate the screens the other 2 are the dimension of the image or of the video
		rm28.loadFromXml("xml/fboSettings28.xml");
		quad28  = ofRectangle(1000,400, 200, 200);
		rm29.allocateForNScreens(2, 500, 500); //the first dedicate the screens the other 2 are the dimension of the image or of the video
		rm29.loadFromXml("xml/fboSettings29.xml");
		quad29  = ofRectangle(1000,400, 200, 200);

		//Imagenes
		tejados.loadImage("images/tejados500x333.png");
		charco.loadImage("images/charco262x338.png");
		ventanaRoja.loadImage("images/ventanaRoja322x422.png");	
		reloj.loadImage("images/reloj404x396.png");			
		textura.loadImage("images/aqua500x500.jpg");
		tejadosInvierno.loadImage("images/TejadoInvierno_Textura3507x1350.jpg");
		montanas.loadImage("images/montanas.jpg");
		bosque.loadImage("images/bosque500x500.jpg");
		muroCasaAlta.loadImage("images/TejadoOtono500x500.jpg");	
		tejadosCasaDerecha.loadImage("images/tejadoCasaDerecha.jpg");	
		ventanaRota.loadImage("images/ventanaRota.jpg");	
		flores.loadImage("images/flores.png");	
		raton.loadImage("images/raton.png");	
		ladrillo.loadImage("images/ladrillo.png");
		mariposa.loadImage("images/mariposa.png");	
	    chimanea.loadImage("images/chimanea.png");	
		arbols.loadImage("images/arbol.png");
		burbujas.loadImage("images/burbujas.png");
		montanasBlancas.loadImage("images/montanasBlancas.jpg");
		montanasRojas.loadImage("images/montanasRojas.jpg");
			

		//Video
		ciudadDestruida.loadMovie("videos/ciudadDestruida.avi");		
		ciudaddestruidaconlluvia.loadMovie("videos/ciudaddestruidaconlluvia.avi");		
		illusion.loadMovie("videos/illusion320x280.mov");
		ormigas.loadMovie("videos/ormigas.mov");	
		floresVideo.loadMovie("videos/FloresYHojasQueCrecen430x660.avi");
		chanTiChan.loadMovie("videos/chantichan.avi");	
	}	//	FBO	
	{	
	ofBackground(r8,g8,b8);
	
	testFont.loadFont("Batang.ttf", 96, true, true, true);
	testFontSmall.loadFont("Batang.ttf", 36, true, true, true);
	
	texScreen.allocate(ofGetWidth(), ofGetHeight(), GL_RGB);	//1920x1080
	
	cout << "listening for osc messages on port " << PORTlisten << "\n";
	receiver.setup( PORTlisten );
	current_msg_string = 0;
	
	// arbol
	arbol.setup();
	
	//  SkeTch
	for (int i = 0; i < MAX_SKETCHES; i++){
		sketch[i].init(0, ofRandom(minSoundElasticity, maxSoundElasticity), ofRandom(minSoundDamping, maxSoundDamping));	//to 1o stoixeio einai to id 0:
		sketch[i].init(1, ofRandom(minMouseElasticity, maxMouseElasticity), ofRandom(minMouseDamping, maxMouseDamping)); //id:1 => mouse init(int sketchID, float elast, float aposv)
	}
	
	ofSetCircleResolution(200);
	bSmooth = true; 
	bool 	bAuto = false;
	ofSetWindowTitle("Una Ciudad Sonada");
	ofSetFrameRate(200); // if vertical sync is off, we can go a bit fast... this caps the framerate at 60fps.
	
	snapCounter = 0;
	bSnapshot = false;
	phase = 0;
	memset(snapString, 0, 255);		// clear the string by setting all chars to 0
	
	ofSetBackgroundAuto(bAuto);
	ofEnableSmoothing();
	ofEnableAlphaBlending(); 
	//glutSetCursor(GLUT_CURSOR_CYCLE);  // change cursor icon (http://pyopengl.sourceforge.net/documentation/manual/glutSetCursor.3GLUT.html)
	}	// Other
	
}
void granCieloApp::update(){
	//OSC
	for ( int i=0; i<NUM_MSG_STRINGS; i++ )	{
		if ( timers[i] < ofGetElapsedTimef() )
			msg_strings[i] = "";
	}	
	while( receiver.hasWaitingMessages() )
	{
		ofxOscMessage m;
		receiver.getNextMessage( &m ); 
		{

			if ( m.getAddress() == "/defaultFBO" )	{	int fboStatus = m.getArgAsInt32(0);
				if (fboStatus == 1)		{	defaultFBO = TRUE;	cout << "true"	<< endl;}	
				if	( fboStatus == 0 )	{	defaultFBO = FALSE;	cout << "false"	<< endl;}
			}									
			if ( m.getAddress() == "/fbo" )		{	
				fbo0=fbo1=fbo2=fbo3=fbo4=fbo5=fbo6=fbo7=fbo8=fbo9=fbo10=fbo11=fbo12=fbo13=fbo14=fbo15=fbo16=fbo17=fbo18=fbo19=fbo20=fbo21=fbo22=fbo23=fbo24=fbo25=fbo26=fbo27=fbo28=fbo29= FALSE;	
			}			
			if ( m.getAddress() == "/fbo0" )	{	int fboStatus = m.getArgAsInt32(0);
				if (fboStatus == 1)		{	fbo0 = TRUE;	}	
				if	( fboStatus == 0 )	{	fbo0 = FALSE;	}
				if(fbo0){
					ciudadDestruida.play();
				} else {
					ciudadDestruida.stop();			
				}						
			}						

			if ( m.getAddress() == "/fbo1" )	{	int fboStatus = m.getArgAsInt32(0);
				if (fboStatus == 1)		{	fbo1 = TRUE;	}	
				if	( fboStatus == 0 )	{	fbo1 = FALSE;	}
			}						
			if ( m.getAddress() == "/fbo2" )	{	int fboStatus = m.getArgAsInt32(0);
				if (fboStatus == 1)		{	fbo2 = TRUE;	}	
				if	( fboStatus == 0 )	{	fbo2 = FALSE;	}
			}						
			if ( m.getAddress() == "/fbo3" )	{	int fboStatus = m.getArgAsInt32(0);
				if (fboStatus == 1)		{	fbo3 = TRUE;	}	
				if	( fboStatus == 0 )	{	fbo3 = FALSE;	}
			}						
			if ( m.getAddress() == "/fbo4" )	{	int fboStatus = m.getArgAsInt32(0);
				if (fboStatus == 1)		{	fbo4 = TRUE;	}	
				if	( fboStatus == 0 )	{	fbo4 = FALSE;	}
			}						
			if ( m.getAddress() == "/fbo5" )	{	int fboStatus = m.getArgAsInt32(0);
				if (fboStatus == 1)		{	fbo5 = TRUE;	}	
				if	( fboStatus == 0 )	{	fbo5 = FALSE;	}
				if(fbo5){
					floresVideo.play();
				} else {
					floresVideo.stop();			
				}						
			}						
			if ( m.getAddress() == "/fbo6" )	{	int fboStatus = m.getArgAsInt32(0);
				if ( fboStatus == 1)		{	fbo6 = TRUE;	}	
				if ( fboStatus == 0 )	{	fbo6 = FALSE;	}
			}						
			if ( m.getAddress() == "/fbo7" )	{	int fboStatus = m.getArgAsInt32(0);
				if  ( fboStatus == 1)		{	fbo7 = TRUE;	}	
				if	( fboStatus == 0 )	{	fbo7 = FALSE;	}
			}						
			if ( m.getAddress() == "/fbo8" )	{	int fboStatus = m.getArgAsInt32(0);
				if  ( fboStatus == 1)		{	fbo8 = TRUE;	}	
				if	( fboStatus == 0 )	{	fbo8 = FALSE;	}
			}						
			if ( m.getAddress() == "/fbo9" )	{	int fboStatus = m.getArgAsInt32(0);
				if  ( fboStatus == 1)		{	fbo9 = TRUE;	}	
				if	( fboStatus == 0 )	{	fbo9 = FALSE;	}
			}						
			if ( m.getAddress() == "/fbo10" )	{	int fboStatus = m.getArgAsInt32(0);
				if  ( fboStatus == 1)		{	fbo10 = TRUE;	}	
				if	( fboStatus == 0 )	{	fbo10 = FALSE;	}
			}						
			if ( m.getAddress() == "/fbo11" )	{	int fboStatus = m.getArgAsInt32(0);
				if (fboStatus == 1)		{	fbo11 = TRUE;	}	
				if	( fboStatus == 0 )	{	fbo11 = FALSE;	}
			}						
			if ( m.getAddress() == "/fbo12" )	{	int fboStatus = m.getArgAsInt32(0);
				if (fboStatus == 1)		{	fbo12 = TRUE;	}	
				if	( fboStatus == 0 )	{	fbo12 = FALSE;	}
			}						
			if ( m.getAddress() == "/fbo13" )	{	int fboStatus = m.getArgAsInt32(0);
				if (fboStatus == 1)		{	fbo13 = TRUE;	}	
				if	( fboStatus == 0 )	{	fbo13 = FALSE;	}
			}						
			if ( m.getAddress() == "/fbo14" )	{	int fboStatus = m.getArgAsInt32(0);
				if (fboStatus == 1)		{	fbo14 = TRUE;	}	
				if	( fboStatus == 0 )	{	fbo14 = FALSE;	}
			}						
			if ( m.getAddress() == "/fbo15" )	{	int fboStatus = m.getArgAsInt32(0);
				if (fboStatus == 1)		{	fbo15 = TRUE;	}	
				if	( fboStatus == 0 )	{	fbo15 = FALSE;	}
			}						
			if ( m.getAddress() == "/fbo16" )	{	int fboStatus = m.getArgAsInt32(0);
				if (fboStatus == 1)		{	fbo16 = TRUE;	}	
				if	( fboStatus == 0 )	{	fbo16 = FALSE;	}
			}						
			if ( m.getAddress() == "/fbo17" )	{	int fboStatus = m.getArgAsInt32(0);
				if (fboStatus == 1)		{	fbo17 = TRUE;	}	
				if	( fboStatus == 0 )	{	fbo17 = FALSE;	}
			}						
			if ( m.getAddress() == "/fbo18" )	{	int fboStatus = m.getArgAsInt32(0);
				if (fboStatus == 1)		{	fbo18 = TRUE;	}	
				if	( fboStatus == 0 )	{	fbo18 = FALSE;	}
			}						
			if ( m.getAddress() == "/fbo19" )	{	int fboStatus = m.getArgAsInt32(0);
				if (fboStatus == 1)		{	fbo19 = TRUE;	}	
				if	( fboStatus == 0 )	{	fbo19 = FALSE;	}
			}						
			if ( m.getAddress() == "/fbo20" )	{	int fboStatus = m.getArgAsInt32(0);
				if (fboStatus == 1)		{	fbo20 = TRUE;	}	
				if	( fboStatus == 0 )	{	fbo20 = FALSE;	}
			}						
			if ( m.getAddress() == "/fbo21" )	{	int fboStatus = m.getArgAsInt32(0);
				if (fboStatus == 1)		{	fbo21 = TRUE;	}	
				if	( fboStatus == 0 )	{	fbo21 = FALSE;	}
			}						
			if ( m.getAddress() == "/fbo22" )	{	int fboStatus = m.getArgAsInt32(0);
				if (fboStatus == 1)		{	fbo22 = TRUE;	}	
				if	( fboStatus == 0 )	{	fbo22 = FALSE;	}
			}						
			if ( m.getAddress() == "/fbo23" )	{	int fboStatus = m.getArgAsInt32(0);
				if (fboStatus == 1)		{	fbo23 = TRUE;	}	
				if	( fboStatus == 0 )	{	fbo23 = FALSE;	}
			}						
			if ( m.getAddress() == "/fbo24" )	{	int fboStatus = m.getArgAsInt32(0);
				if (fboStatus == 1)		{	fbo24 = TRUE;	}	
				if	( fboStatus == 0 )	{	fbo24 = FALSE;	}
			}						
			if ( m.getAddress() == "/fbo25" )	{	int fboStatus = m.getArgAsInt32(0);
				if (fboStatus == 1)		{	fbo25 = TRUE;	}	
				if	( fboStatus == 0 )	{	fbo25 = FALSE;	}
			}						
			if ( m.getAddress() == "/fbo26" )	{	int fboStatus = m.getArgAsInt32(0);
				if (fboStatus == 1)		{	fbo26 = TRUE;	}	
				if	( fboStatus == 0 )	{	fbo26 = FALSE;	}
			}						
			if ( m.getAddress() == "/fbo27" )	{	int fboStatus = m.getArgAsInt32(0);
				if (fboStatus == 1)		{	fbo27 = TRUE;	}	
				if	( fboStatus == 0 )	{	fbo27 = FALSE;	}
			}						
			if ( m.getAddress() == "/fbo28" )	{	int fboStatus = m.getArgAsInt32(0);
				if (fboStatus == 1)		{	fbo28 = TRUE;	}	
				if	( fboStatus == 0 )	{	fbo28 = FALSE;	}
			}						
			if ( m.getAddress() == "/fbo29" )	{	int fboStatus = m.getArgAsInt32(0);
				if (fboStatus == 1)		{	fbo29 = TRUE;	}	
				if	( fboStatus == 0 )	{	fbo29 = FALSE;	}
			}
		}	//  FBO TRUE FALSE
		{
			
			if ( m.getAddress() == "/afbo6" )	{
				float afbo6temp = m.getArgAsFloat(0);
				afbo6 = int(afbo6temp);
			}			
			if ( m.getAddress() == "/afbo7" )	{
				float afbo7temp = m.getArgAsFloat(0);
				afbo7 = int(afbo7temp);
			}			
			if ( m.getAddress() == "/afbo8" )	{
				float afbo8temp = m.getArgAsFloat(0);
				afbo8 = int(afbo8temp);
			}			
			if ( m.getAddress() == "/afbo123" )	{
				float afbo123temp = m.getArgAsFloat(0);
				afbo123 = int(afbo123temp);
			}			
			if ( m.getAddress() == "/afbo15_17" )	{
				float afbo15_17temp = m.getArgAsFloat(0);
				afbo15_17 = int(afbo15_17temp);
			}			
			if ( m.getAddress() == "/afbo21_23" )	{
				float afbo21_23temp = m.getArgAsFloat(0);
				afbo21_23 = int(afbo21_23temp);
			}			
						
		}	//	FBO alpha
		{
			if ( m.getAddress() == "/viewMontanasRojasTRUE" )	{
				viewMontanasRojas = true;
			}			
			if ( m.getAddress() == "/viewMontanasRojasFALSE" )	{
				viewMontanasRojas = false;
			}			
			if ( m.getAddress() == "/viewMontanasBlancasTRUE" )	{
				viewMontanasBlancas = true;
			}			
			if ( m.getAddress() == "/viewMontanasBlancasFALSE" )	{
				viewMontanasBlancas = false;
			}			
			if ( m.getAddress() == "/viewMontanasTRUE" )	{
				viewMontanas = true;
			}			
			if ( m.getAddress() == "/viewMontanasFALSE" )	{
				viewMontanas = false;
			}			
			if ( m.getAddress() == "/viewVentanaRotaTRUE" )	{
				viewVentanaRota = true;
			}			
			if ( m.getAddress() == "/viewVentanaRotaFALSE" )	{
				viewVentanaRota = false;
			}			
			if ( m.getAddress() == "/viewChimaneaTRUE" )	{
				viewChimanea = true;
				//cout << "viewChanTiChanTRUE" << endl;
			}			
			if ( m.getAddress() == "/viewChimaneaFALSE" )	{
				viewChimanea = false;
				//cout << "viewChanTiChanTRUE" << endl;
			}			
			if ( m.getAddress() == "/viewChanTiChanTRUE" )	{
				viewChanTiChan = true;
				//cout << "viewChanTiChanTRUE" << endl;
			}			
			if ( m.getAddress() == "/viewChanTiChanFALSE" )	{
				viewChanTiChan = false;
				//cout << "viewChanTiChanFALSE" << endl;
			}			
			
			if ( m.getAddress() == "/viewFlores6TRUE" )	{
				viewFlores6 = true;
				//cout << "TRUEflores6" << endl;
			}			
			if ( m.getAddress() == "/viewFlores6FALSE" )	{
				viewFlores6 = false;
			}			
			if ( m.getAddress() == "/viewFlores13TRUE" )	{
				viewFlores13 = true;
			}			
			if ( m.getAddress() == "/viewFlores13FALSE" )	{
				viewFlores13 = false;
			}			
			if ( m.getAddress() == "/viewFlores14TRUE" )	{
				viewFlores14 = true;
			}			
			if ( m.getAddress() == "/viewFlores14FALSE" )	{
				viewFlores14 = false;
			}			
			if ( m.getAddress() == "/viewFlores2TRUE" )	{
				viewFlores2 = true;
			}			
			if ( m.getAddress() == "/viewFlores2FALSE" )	{
				viewFlores2 = false;
			}			
			if ( m.getAddress() == "/viewFlores10TRUE" )	{
				viewFlores10 = true;
			}			
			if ( m.getAddress() == "/viewFlores10FALSE" )	{
				viewFlores10 = false;
			}			
			if ( m.getAddress() == "/viewRaton4FALSE" )	{
				viewRaton4 = false;
			}			
			if ( m.getAddress() == "/viewRaton20FALSE" )	{
				viewRaton20 = false;
			}			
			if ( m.getAddress() == "/viewRaton22FALSE" )	{
				viewRaton22 = false;
			}			
			if ( m.getAddress() == "/viewRaton4TRUE" )	{
				viewRaton4 = true;
			}			
			if ( m.getAddress() == "/viewRaton20TRUE" )	{
				viewRaton20 = true;
			}			
			if ( m.getAddress() == "/viewRaton22TRUE" )	{
				viewRaton22 = true;
			}		
				
			if ( m.getAddress() == "/viewLadrillo4FALSE" )	{
				viewLadrillo4 = false;
			}			
			if ( m.getAddress() == "/viewLadrillo20FALSE" )	{
				viewLadrillo20 = false;
			}			
			if ( m.getAddress() == "/viewLadrillo22FALSE" )	{
				viewLadrillo22 = false;
			}			
			if ( m.getAddress() == "/viewLadrillo4TRUE" )	{
				viewLadrillo4 = true;
			}			
			if ( m.getAddress() == "/viewLadrillo20TRUE" )	{
				viewLadrillo20 = true;
			}			
			if ( m.getAddress() == "/viewLadrillo22TRUE" )	{
				viewLadrillo22 = true;
			}			

			if ( m.getAddress() == "/viewCiudadDestruidaConLluviaTRUE" )	{
				cout << "viewCiudadDestruidaConLluviaTRUE" << endl;
				viewCiudadDestruidaConLluvia = true;
			}			
			if ( m.getAddress() == "/viewCiudadDestruidaConLluviaFALSE" )	{
				cout << "viewCiudadDestruidaConLluviaFALSE" << endl;
				viewCiudadDestruidaConLluvia = false;
			}			
			if ( m.getAddress() == "/viewCiudadDestruidaTRUE" )	{
				cout << "viewCiudadDestruidaConLluviaTRUE" << endl;			
				viewCiudadDestruida = true;
			}			
			if ( m.getAddress() == "/viewCiudadDestruidaFALSE" )	{
				cout << "viewCiudadDestruidaConLluviaFALSE" << endl;			
				viewCiudadDestruida = false;
			}			
			
		}	//	FBO View
		{
			if ( m.getAddress() == "/drawLine" )	{
				Effect.drawLine();
			}		
			if ( m.getAddress() == "/drawLineVertical" )	{
				Effect.drawLineVertical();
			}		
			if ( m.getAddress() == "/startEffect" )	{
				Effect.start();
			}		
			if ( m.getAddress() == "/deseo" )	{
				a8 = r8 = g8 = b8 = 0;
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // GL_SRC_ALPHA_SATURATE,GL_ONE     GL_SRC_ALPHA, GL_ONE
				ofFill();
				strPosX = ofRandom(0, ofGetWidth());
				strPosY = ofRandom(0, ofGetHeight());
				ofSetColor(255,255,255,255);	// even
				ofPushMatrix();
				ofTranslate(strPosX, strPosY, 0);
				testFontSmall.loadFont("Batang.ttf", int(ofRandom(2,40)), true, true, true);
				testFontSmall.drawString(deseo,0, 0);		
				ofPopMatrix();
			}		
			if ( m.getAddress() == "/deseoConString" )	{
				deseo = m.getArgAsString( 0 );
				a8 = r8 = g8 = b8 = 0;
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // GL_SRC_ALPHA_SATURATE,GL_ONE     GL_SRC_ALPHA, GL_ONE
				ofFill();
				strPosX = ofRandom(0, ofGetWidth());
				strPosY = ofRandom(0, ofGetHeight());
				ofSetColor(255,255,255,255);	// even
				ofPushMatrix();
				ofTranslate(strPosX, strPosY, 0);
				testFontSmall.loadFont("Batang.ttf", int(ofRandom(2,40)), true, true, true);
				testFontSmall.drawString(deseo,0, 0);		
				ofPopMatrix();
			}		
			if ( m.getAddress() == "/mariposa" )	{
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // GL_SRC_ALPHA_SATURATE,GL_ONE     GL_SRC_ALPHA, GL_ONE
				ofFill();
				ofSetColor(0xFFFFFF);
				strPosX = ofRandom(0, ofGetWidth());
				strPosY = ofRandom(0, ofGetHeight());
				//cout << "aqui" << endl;
				ofPushMatrix();
				ofTranslate(strPosX, strPosY, 0);
				mariposa.draw(0, 0);						
				ofPopMatrix();
			}		
			if ( m.getAddress() == "/arbol" )	{
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // GL_SRC_ALPHA_SATURATE,GL_ONE     GL_SRC_ALPHA, GL_ONE
				ofFill();
				ofSetColor(0xFFFFFF);
				strPosX = ofRandom(0, ofGetWidth());
				strPosY = ofRandom(0, ofGetHeight());
				//cout << "aqui" << endl;
				ofPushMatrix();
				ofTranslate(strPosX, strPosY, 0);
				arbols.draw(0, 0);						
				ofPopMatrix();
			}		
			if ( m.getAddress() == "/burbujas" )	{
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // GL_SRC_ALPHA_SATURATE,GL_ONE     GL_SRC_ALPHA, GL_ONE
				ofFill();
				ofSetColor(0xFFFFFF);
				strPosX = ofRandom(0, ofGetWidth());
				strPosY = ofRandom(0, ofGetHeight());
				//cout << "aqui" << endl;
				ofPushMatrix();
				ofTranslate(strPosX, strPosY, 0);
				burbujas.draw(0, 0);						
				ofPopMatrix();
			}		
			if ( m.getAddress() == "/golondrinas" )	{			
				LSystem.lsystemString = m.getArgAsString( 0 );
				LSystem.depthLength = m.getArgAsInt32( 1 );
				LSystem.theta = m.getArgAsFloat( 2 );
				LSystem.scale = m.getArgAsFloat( 3 );				
				LSystem.noise = m.getArgAsFloat( 4 );	
				lsystemGeneration = m.getArgAsInt32( 5 );
				if	(lsystemGeneration == 0)	{
					LSystem.startGeneration = true;
				}				
				LSystem.golondrinas();					
			}

		}	//	effects
		{
			if ( m.getAddress() == "/lsystem" )	{
				//lsystemString = m.getArgAsString( 0 );
				//cout << lsystemString << endl;
				LSystem.lsystemString = m.getArgAsString( 0 );
				LSystem.depthLength = m.getArgAsInt32( 1 );
				LSystem.theta = m.getArgAsFloat( 2 );
				LSystem.scale = m.getArgAsFloat( 3 );				
				LSystem.noise = m.getArgAsFloat( 4 );	
				lsystemGeneration = m.getArgAsInt32( 5 );
				if	(lsystemGeneration == 0)	{
					LSystem.startGeneration = true;
				}				
				
//				cout << LSystem.depthLength <<	endl;
//				cout << LSystem.scale <<	endl;
//				cout << LSystem.depthLength <<	endl;								
				LSystem.recieveString();					
							
			}
		}	//	LSystems
		{
			if ( m.getAddress() == "/sync" )	{
				str = m.getArgAsString( 0 );
				if	(str == "beats")	{
					beat = m.getArgAsInt32( 1 );
					std::stringstream out;
					out << beat;
					beatStr = out.str();				
				}
				if	(beatsView)	{
					if ( beat % 2 == 0 ) {
						ofSetColor(0,0,0,255);	// even
						} else {
						ofSetColor(255,0,0,255);	// odd
					}
					syncStudies();
				}
			}
			if ( m.getAddress() == "/beatsView" )	{
				beatsView = m.getArgAsInt32( 0 );
			}
		}	//	Synchronization
		{
			if ( m.getAddress() == "/arbolView" )	{
				arbolView = m.getArgAsInt32( 0 );
			}
			if ( m.getAddress() == "/arbolHeigth" )	{
				arbol.h = m.getArgAsFloat( 0 );
			}
			if ( m.getAddress() == "/arbolLeaves" )	{
				arbol.leavesLenght = m.getArgAsFloat( 0 );
			}		
			if ( m.getAddress() == "/arbolWind" )	{
				float wind = m.getArgAsFloat( 0 );
				arbol.aa = ofMap(wind, 0, 1, 0.5, -0.5);
				arbol.ab = ofMap(wind, 0, 1, -0.5, 0.5);				
			}		
		}	//	Arbol
		{
			if ( m.getAddress() == "/viewSoundChanels" )	{
				viewSoundChanels = m.getArgAsInt32( 0 );
			}
			if	(viewSoundChanels)	{			
				if ( m.getAddress() == "/soundLines" )	{
					soundLines = m.getArgAsFloat( 0 );
				}					
				if ( m.getAddress() == "/numSoundSketches" )	{
					numSoundSketches = m.getArgAsFloat( 0 );
				}	
				
				if ( m.getAddress() == "/minSoundElasticity" )	{
					minSoundElasticity = m.getArgAsFloat( 0 );
					//printf("minSoundElasticity: %f \n", minSoundElasticity);
					for( int i=1000; i<1000+numSoundSketches; i++ ) {
						sketch[i].init(0, ofRandom(minSoundElasticity, maxSoundElasticity), ofRandom(minSoundDamping, maxSoundDamping));	//to 1o stoixeio einai to id 0:
					}
				}		
				if ( m.getAddress() == "/maxSoundElasticity" )	{
					maxSoundElasticity = m.getArgAsFloat( 0 );
					//printf("maxSoundElasticity: %f \n", maxSoundElasticity);
					
					for( int i=1000; i<1000+numSoundSketches; i++ ) {
						sketch[i].init(0, ofRandom(minSoundElasticity, maxSoundElasticity), ofRandom(minSoundDamping, maxSoundDamping));	//to 1o stoixeio einai to id 0:
					}			
				}		
				if ( m.getAddress() == "/minSoundDamping" )	{
					minSoundDamping = m.getArgAsFloat( 0 );
					for( int i=1000; i<1000+numSoundSketches; i++ ) {
						sketch[i].init(0, ofRandom(minSoundElasticity, maxSoundElasticity), ofRandom(minSoundDamping, maxSoundDamping));	//to 1o stoixeio einai to id 0:
					}
				}		
				if ( m.getAddress() == "/maxSoundDamping" )	{
					maxSoundDamping = m.getArgAsFloat( 0 );
					for( int i=1000; i<1000+numSoundSketches; i++ ) {
						sketch[i].init(0, ofRandom(minSoundElasticity, maxSoundElasticity), ofRandom(minSoundDamping, maxSoundDamping));	//to 1o stoixeio einai to id 0:
					}			
				}
				if ( m.getAddress() == "/minAmp" )		{
					ampInLow =  m.getArgAsFloat( 0 );
					//printf(" %f \n", ampInLow);			
				}		
				if ( m.getAddress() == "/maxAmp" )		{
					ampInHigh =  m.getArgAsFloat( 0 );	
				}		
				if ( m.getAddress() == "/minFreq" )		{
					freqInLow =  m.getArgAsFloat( 0 );			
				}		
				if ( m.getAddress() == "/maxFreq" )		{
					freqInHigh =  m.getArgAsFloat( 0 );			
				}
				
				if	(viewSoundChanels)	{
					if ( m.getAddress() == "/ampChan0" )	{
						ampChan0 = m.getArgAsFloat( 0 );
						//printf(" %f \n", ampChan0);			
					}
					if ( m.getAddress() == "/ampChan1" )	{
						ampChan1 = m.getArgAsFloat( 0 );
					}
					if ( m.getAddress() == "/ampChan2" )	{
						ampChan2 = m.getArgAsFloat( 0 );
					}
					if ( m.getAddress() == "/ampChan4" )	{
						ampChan3 = m.getArgAsFloat( 0 );
					}
					if ( m.getAddress() == "/ampChan5" )	{
						ampChan3 = m.getArgAsFloat( 0 );
					}
					if ( m.getAddress() == "/ampChan6" )	{
						ampChan3 = m.getArgAsFloat( 0 );
					}
					if ( m.getAddress() == "/ampChan7" )	{
						ampChan3 = m.getArgAsFloat( 0 );
					}
					if ( m.getAddress() == "/freqChan0" )	{
						freqChan0 = m.getArgAsFloat( 0 );
					}
					if ( m.getAddress() == "/freqChan1" )	{
						freqChan1 = m.getArgAsFloat( 0 );
					}
					if ( m.getAddress() == "/freqChan2" )	{
						freqChan2 = m.getArgAsFloat( 0 );
					}
					if ( m.getAddress() == "/freqChan3" )	{
						freqChan3 = m.getArgAsFloat( 0 );
					}
					if ( m.getAddress() == "/freqChan4" )	{
						freqChan0 = m.getArgAsFloat( 0 );
					}
					if ( m.getAddress() == "/freqChan5" )	{
						freqChan1 = m.getArgAsFloat( 0 );
					}
					if ( m.getAddress() == "/freqChan6" )	{
						freqChan2 = m.getArgAsFloat( 0 );
					}
					if ( m.getAddress() == "/freqChan7" )	{
						freqChan3 = m.getArgAsFloat( 0 );
					}
				}	// sound input	
								
			}	//sound lines characteristics (channel I)
		
		}	//	Sound Interaction
		{		
			if ( m.getAddress() == "/viewSuperformula" )	{
				viewSuperformula = m.getArgAsInt32( 0 );
			}
			if	(viewSuperformula)		{
				if ( m.getAddress() == "/sformM" )	{
					sformM = m.getArgAsFloat( 0 );
				}							
				if ( m.getAddress() == "/sformn1" )	{
					sformn1 = m.getArgAsFloat( 0 );
				}							
				if ( m.getAddress() == "/sformn2" )	{
					sformn2 = m.getArgAsFloat( 0 );
				}							
				if ( m.getAddress() == "/sformn3" )	{
					sformn3 = m.getArgAsFloat( 0 );
				}							
				if ( m.getAddress() == "/sformStep" )	{
					sformStep = m.getArgAsFloat( 0 );
				}							
				if ( m.getAddress() == "/sformScale" )	{
					sformScale = m.getArgAsFloat( 0 );
				}							
				if ( m.getAddress() == "/sformNum" )	{
					sformNum = m.getArgAsFloat( 0 );
				}						
				if ( m.getAddress() == "/sformType" )	{
					sformType = m.getArgAsFloat( 0 );
				}										
			}								
		}	//	Superformula
		{
			if ( m.getAddress() == "/viewSeashell" )	{
				viewSeashell = m.getArgAsInt32( 0 );
			}	
			if	(viewSeashell)	{
				if ( m.getAddress() == "/seashellR" )	{
					seashellR = m.getArgAsFloat( 0 );
				}					
				if ( m.getAddress() == "/seashellN" )	{
					seashellN = m.getArgAsFloat( 0 );
				}					
				if ( m.getAddress() == "/seashellH" )	{
					seashellH = m.getArgAsFloat( 0 );
				}					
				if ( m.getAddress() == "/seashellP" )	{
					seashellP = m.getArgAsFloat( 0 );
				}					
				if ( m.getAddress() == "/seashellL" )	{
					seashellL = m.getArgAsFloat( 0);
				}					
				if ( m.getAddress() == "/seashellK" )	{
					seashellK = m.getArgAsFloat( 0 );
				}					
				if ( m.getAddress() == "/seashellDu" )	{
					seashellDu = m.getArgAsFloat( 0 );
					//printf(" %f \n", seashellDu);			
				}					
				if ( m.getAddress() == "/seashellDv" )	{
					seashellDv = m.getArgAsFloat( 0 );
					//printf(" %f \n", seashellDv);			
				}					
				if ( m.getAddress() == "/seashellType" )	{
					seashellType = m.getArgAsInt32( 0 );
					//printf(" %f \n", seashellType);			
				}					
				if ( m.getAddress() == "/seashellScale" )	{
					seashellScale = m.getArgAsFloat( 0 );
					//printf(" %f \n", seashellScale);			
				}					
				if ( m.getAddress() == "/seashellSteps" )	{
					seashellSteps = m.getArgAsFloat( 0 );
					//printf(" %f \n", seashellScale);			
				}					
			}						
							
		}	//	Seashell
		{
			if ( m.getAddress() == "/feedbackView" )	{
				feedbackView = m.getArgAsInt32( 0 );
			}
			if	(feedbackView)	{
				if ( m.getAddress() == "/feedbackSpeedX" )	{
					feedbackSpeedX = m.getArgAsFloat( 0 );
					//printf(" %f \n", feedbackSpeed);			
				}	
				if ( m.getAddress() == "/feedbackSpeedY" )	{
					feedbackSpeedY = m.getArgAsFloat( 0 );
					//printf(" %f \n", feedbackSpeed);			
				}	
				if ( m.getAddress() == "/timeLine" )	{
					timeLine = m.getArgAsInt32( 0 );
				}		
				if ( m.getAddress() == "/viewRotate" )	{
					viewRotate = m.getArgAsInt32( 0 );
				}														
			}			
		}	//	Feedback
		{
			if ( m.getAddress() == "/circleView" )	{
				circleView = m.getArgAsInt32( 0 );
			}			
			if	(circleView)	{
				if ( m.getAddress() == "/tangentI" )	{
					tangentI = m.getArgAsInt32( 0 );
					for (int i = 0; i < 10; i++){
						circle[i].tangentI();
					}										
				}
				if ( m.getAddress() == "/tangentII" )	{
					tangentII = m.getArgAsInt32( 0 );
					for (int i = 0; i < 10; i++){
						circle[i].tangentII();
					}														
				}
				if ( m.getAddress() == "/theta" )	{
					theta = m.getArgAsFloat( 0 );
					//printf(" %f \n", theta);
					//				circle[0].perimeterPoint();	
					for (int i = 0; i < 10; i++){
						circle[i].perimeterPoint();
					}										
				}			
			}
		}	//	Circle
		{
			if	(drawWithMouse)	{	
				if ( m.getAddress() == "/mouseLines" )	{
					mouseLines = m.getArgAsFloat( 0 );
				}					
				if ( m.getAddress() == "/numMouseSketches" )	{
					numMouseSketches = m.getArgAsFloat( 0 );
				}		
				
				if ( m.getAddress() == "/minMouseElasticity" )	{
					minMouseElasticity = m.getArgAsFloat( 0 );			
					for( int i=1000; i<1000 + numMouseSketches; i++ ) {
						sketch[i].init(1, ofRandom(minMouseElasticity, maxMouseElasticity), ofRandom(minMouseDamping, maxMouseDamping)); //id:1 => mouse init(int sketchID, float elast, float aposv)
					}		
				}		
				if ( m.getAddress() == "/maxMouseElasticity" )	{
					maxMouseElasticity = m.getArgAsFloat( 0 );
					for( int i=1000; i<1000 + numMouseSketches; i++ ) {
						sketch[i].init(1, ofRandom(minMouseElasticity, maxMouseElasticity), ofRandom(minMouseDamping, maxMouseDamping)); //id:1 => mouse init(int sketchID, float elast, float aposv)
					}		
				}		
				if ( m.getAddress() == "/minMouseDamping" )	{
					minMouseDamping = m.getArgAsFloat( 0 );
					for( int i=1000; i<1000 + numMouseSketches; i++ ) {
						sketch[i].init(1, ofRandom(minMouseElasticity, maxMouseElasticity), ofRandom(minMouseDamping, maxMouseDamping)); //id:1 => mouse init(int sketchID, float elast, float aposv)
					}		
				}		
				if ( m.getAddress() == "/maxMouseDamping" )	{
					maxMouseDamping = m.getArgAsFloat( 0 );
					for( int i=1000; i<1000 + numMouseSketches; i++ ) {
						sketch[i].init(1, ofRandom(minMouseElasticity, maxMouseElasticity), ofRandom(minMouseDamping, maxMouseDamping)); //id:1 => mouse init(int sketchID, float elast, float aposv)
					}		
				}
			}	//mouse characteristics
		}	//	Mouse Interaction
		{
			if ( m.getAddress() == "/midi1" )		{
				midi1 = m.getArgAsInt32(0);
				a1 = midi1;			//a1 = ofMap(midi1, 0, 127, 0, 255);			
			}		
			if ( m.getAddress() == "/midi2" )		{
				midi2 = m.getArgAsInt32(0);
				a2 = midi2;			//a2 = ofMap(midi2, 0, 127, 0, 255);			
			}		
			if ( m.getAddress() == "/midi3" )		{
				midi3 = m.getArgAsInt32(0);
				a3 = midi3;			//a3 = ofMap(midi3, 0, 127, 0, 255);			
			}		
			if ( m.getAddress() == "/midi4" )		{
				midi4 = m.getArgAsInt32(0);
				a4 = midi4;			//a4 = ofMap(midi4, 0, 127, 0, 255);			
			}		
			if ( m.getAddress() == "/midi5" )		{
				midi5 = m.getArgAsInt32(0);
				a5 = midi5;			//a5 = ofMap(midi5, 0, 127, 0, 255);			
			}		
			if ( m.getAddress() == "/midi6" )		{
				midi6 = m.getArgAsInt32(0);
				a6 = midi6;			//a6 = ofMap(midi6, 0, 127, 0, 255);			
			}		
			if ( m.getAddress() == "/midi7" )		{
				midi7 = m.getArgAsInt32(0);
				a7 = midi7;			//a7 = ofMap(midi7, 0, 127, 0, 255);			
			}		
			if ( m.getAddress() == "/midi8" )		{
				midi8 = m.getArgAsInt32(0);
				a8 = midi8;			//a8 = ofMap(midi8, 0, 127, 0, 255);
			}		
			if ( m.getAddress() == "/midi81" )		{
				midi81 = m.getArgAsInt32(0);
				r1 = ofMap(midi81, 0, 127, 0, 255);			
			}		
			if ( m.getAddress() == "/midi82" )		{
				midi82 = m.getArgAsInt32(0);
				r2 = ofMap(midi82, 0, 127, 0, 255);			
			}		
			if ( m.getAddress() == "/midi83" )		{
				midi83 = m.getArgAsInt32(0);
				r3 = ofMap(midi83, 0, 127, 0, 255);				
			}		
			if ( m.getAddress() == "/midi84" )		{
				midi84 = m.getArgAsInt32(0);
				r4 = ofMap(midi84, 0, 127, 0, 255);			
			}		
			if ( m.getAddress() == "/midi85" )		{
				midi85 = m.getArgAsInt32(0);
				r5 = ofMap(midi85, 0, 127, 0, 255);			
			}		
			if ( m.getAddress() == "/midi86" )		{
				midi86 = m.getArgAsInt32(0);
				r6 = ofMap(midi86, 0, 127, 0, 255);			
			}		
			if ( m.getAddress() == "/midi87" )		{
				midi87 = m.getArgAsInt32(0);
				r7 = ofMap(midi87, 0, 127, 0, 255);			
			}		
			if ( m.getAddress() == "/midi88" )		{
				midi88 = m.getArgAsInt32(0);
				r8 = ofMap(midi88, 0, 127, 0, 255);			
			}		
			if ( m.getAddress() == "/midi89" )		{
				midi89 = m.getArgAsInt32(0);
				g1 = ofMap(midi89, 0, 127, 0, 255);			
			}		
			if ( m.getAddress() == "/midi90" )		{
				midi90 = m.getArgAsInt32(0);
				g2 = ofMap(midi90, 0, 127, 0, 255);			
			}		
			if ( m.getAddress() == "/midi91" )		{
				midi91 = m.getArgAsInt32(0);
				g3 = ofMap(midi91, 0, 127, 0, 255);			
			}		
			if ( m.getAddress() == "/midi92" )		{
				midi92 = m.getArgAsInt32(0);
				g4 = ofMap(midi92, 0, 127, 0, 255);			
			}		
			if ( m.getAddress() == "/midi93" )		{
				midi93 = m.getArgAsInt32(0);
				g5 = ofMap(midi93, 0, 127, 0, 255);			
			}		
			if ( m.getAddress() == "/midi94" )		{
				midi94 = m.getArgAsInt32(0);
				g6 = ofMap(midi94, 0, 127, 0, 255);			
			}		
			if ( m.getAddress() == "/midi95" )		{
				midi95 = m.getArgAsInt32(0);
				g7 = ofMap(midi95, 0, 127, 0, 255);			
			}		
			if ( m.getAddress() == "/midi96" )		{
				midi96 = m.getArgAsInt32(0);
				g8 = ofMap(midi96, 0, 127, 0, 255);			
			}		
			if ( m.getAddress() == "/midi97" )		{
				midi97 = m.getArgAsInt32(0);
				b1 = ofMap(midi97, 0, 127, 0, 255);			
			}		
			if ( m.getAddress() == "/midi98" )		{
				midi98 = m.getArgAsInt32(0);
				b2 = ofMap(midi98, 0, 127, 0, 255);			
			}		
			if ( m.getAddress() == "/midi99" )		{
				midi99 = m.getArgAsInt32(0);
				b3 = ofMap(midi99, 0, 127, 0, 255);			
			}		
			if ( m.getAddress() == "/midi100" )		{
				midi100 = m.getArgAsInt32(0);
				b4 = ofMap(midi100, 0, 127, 0, 255);			
			}		
			if ( m.getAddress() == "/midi101" )		{
				midi101 = m.getArgAsInt32(0);
				b5 = ofMap(midi101, 0, 127, 0, 255);			
			}		
			if ( m.getAddress() == "/midi102" )		{
				midi102 = m.getArgAsInt32(0);
				b6 = ofMap(midi102, 0, 127, 0, 255);			
			}		
			if ( m.getAddress() == "/midi103" )		{
				midi103 = m.getArgAsInt32(0);
				b7 = ofMap(midi103, 0, 127, 0, 255);			
			}		
			if ( m.getAddress() == "/midi104" )		{
				midi104 = m.getArgAsInt32(0);
				b8 = ofMap(midi104, 0, 127, 0, 255);			
			}
		}	//  MIDI r, g, b. a		
		{
			if ( m.getAddress() == "/a8" )		{
				float a8temp = int(m.getArgAsFloat(0));
				a8 = int(a8temp);
			}		
			if ( m.getAddress() == "/r8" )		{
				float r8temp = int(m.getArgAsFloat(0));
				r8 = int(r8temp);
			}		
			if ( m.getAddress() == "/g8" )		{
				float g8temp = int(m.getArgAsFloat(0));
				g8 = int(g8temp);
			}		
			if ( m.getAddress() == "/b8" )		{
				float b8temp = int(m.getArgAsFloat(0));
				b8 = int(b8temp);
			}		
			if ( m.getAddress() == "/a7" )		{
				float a7temp = int(m.getArgAsFloat(0));
				a7 = int(a7temp);
			}		
			if ( m.getAddress() == "/r7" )		{
				float r7temp = int(m.getArgAsFloat(0));
				r7 = int(r7temp);
			}		
			if ( m.getAddress() == "/g7" )		{
				float g7temp = int(m.getArgAsFloat(0));
				g7 = int(g7temp);
			}		
			if ( m.getAddress() == "/b7" )		{
				float b7temp = int(m.getArgAsFloat(0));
				b7 = int(b7temp);
			}		
		}	//	rgb directamente
		{
			if ( m.getAddress() == "/background" )		{
			
				int rBack = m.getArgAsInt32(0);
				int gBack = m.getArgAsInt32(1);
				int bBack = m.getArgAsInt32(2);								
				ofBackground(rBack, gBack, bBack);
			}		
		}	//	background
		{
			if ( m.getAddress() == "/soloChanTiChanTRUE" )		{
				xSolo = m.getArgAsFloat(0);
				ySolo = m.getArgAsFloat(1);
				viewSoloChanTiChan = true;
//				for( int i=1000; i<1000 + numMouseSketches; i++ ) {
//					sketch[i].drawMouse(xSolo, ySolo, 0, r7, g7, b7, a7/3, mouseLines);	
//				}			
			}		
			if ( m.getAddress() == "/soloChanTiChanFALSE" )		{
				viewSoloChanTiChan = false;
			}		
		}	//	sKeTch
	}	
}
void granCieloApp::draw(){
	if	(	viewSoloChanTiChan	)	{
		for( int i=0; i<numMouseSketches; i++ ) {
			sketch[i].drawMouse(xSolo, ySolo, 0, r7, g7, b7, a7/3, mouseLines);	
		}
		
	}
	{	
	//framerate
	//	ofSetColor(0,0,0); //set font color
	//	ofDrawBitmapString( " frameRate: " + ofToString(ofGetFrameNum(), 1), 20, 20);  // view framerateNum 
	//	ofDrawBitmapString( " frameRate: " + ofToString(ofGetFrameRate(), 1), 20, 20);  // view framerate  (http://www.openframeworks.cc/documentation?detail=ofUtils#ofToString)
	} // view framerate
	if	(view_fillBackground)	{
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // GL_SRC_ALPHA_SATURATE,GL_ONE     GL_SRC_ALPHA, GL_ONE
		ofFill();	
		ofSetColor(r8, g8, b8, a8);
		ofRect(0,0,ofGetWidth(),ofGetHeight());			
	}
	{
		{
			if ( fbo0 )	{
				rm0.startOffscreenDraw();
					if	(	viewChanTiChan	)	{
						chanTiChan.idleMovie();
						ofSetColor(0xFFFFFF);
						chanTiChan.play();							
						chanTiChan.draw(0,0, 320,280);
					}
					if	(	viewCiudadDestruida	)	{
						ciudadDestruida.idleMovie();
						ofSetColor(0xFFFFFF);
						ciudadDestruida.play();							
						ciudadDestruida.draw(0,0, 320,280);
					}
					if	(	defaultFBO	)	{							
						ofSetColor(255,255,255);
						ofRect(0, 0, rm0.width, rm0.height);							
						ofSetColor(0xFF0000);
						ofLine(0, 0, rm0.width, rm0.height);							
						ofSetColor(0xFF0000);
						ofLine(rm0.width, 0, 0, rm0.height);							
					}					
				
				rm0.endOffscreenDraw();
				rm0.drawOutputDiagnostically(quad0.x, quad0.y, quad0.width, quad0.height);	
			}
		}	//	FBO 0 catastrofe
		{
			if ( fbo1) {
				rm1.startOffscreenDraw();
				if	(	defaultFBO	)	{							
					ofSetColor(255,255,255);
					ofRect(0, 0, rm1.width, rm1.height);							
					ofSetColor(0xFF0000);
					ofLine(0, 0, rm1.width, rm1.height);							
					ofSetColor(0xFF0000);
					ofLine(rm1.width, 0, 0, rm1.height);							
				}					
				if	(	viewMontanas	)	{												
					ofFill();
					ofSetColor(255,255,255,afbo123);												
					tejadosInvierno.draw(0,0);						
				}					
				rm1.endOffscreenDraw();
				rm1.drawOutputDiagnostically(quad1.x, quad1.y, quad1.width, quad1.height);	
			}
		}	//	FBO 1 desagua
		{
			if ( fbo2 )	{
				rm2.startOffscreenDraw();
					if	( viewFlores6 )	{
						ofFill();
						ofSetColor(0xFFFFFF);
						flores.draw(0,0);						
					}	
	//					if	( )	{					
	//						ofFill();
	//						ofSetColor(255,255,255,afbo123);												
	//						ventanaRoja.draw(0,0);						
	//						}
					if	(	defaultFBO	)	{							
						ofSetColor(255,255,255);
						ofRect(0, 0, rm2.width, rm2.height);							
						ofSetColor(0xFF0000);
						ofLine(0, 0, rm2.width, rm2.height);							
						ofSetColor(0xFF0000);
						ofLine(rm2.width, 0, 0, rm2.height);							
					}									
				rm2.endOffscreenDraw();
				rm2.drawOutputDiagnostically(quad2.x, quad2.y, quad2.width, quad2.height);	
			}			
		}	//	FBO 2 ventana rota
		{
			if ( fbo3 )	{
				rm3.startOffscreenDraw();
					if	(	defaultFBO	)	{							
						ofSetColor(255,255,255);
						ofRect(0, 0, rm3.width, rm3.height);							
						ofSetColor(0xFF0000);
						ofLine(0, 0, rm3.width, rm3.height);							
						ofSetColor(0xFF0000);
						ofLine(rm3.width, 0, 0, rm3.height);							
					}									
//					if (	viewFBO3	) {
//						illusion.idleMovie();
//						ofSetColor(0xFFFFFF);
//						illusion.draw(0,0, 320,280);						
//					}
				rm3.endOffscreenDraw();
				rm3.drawOutputDiagnostically(quad3.x, quad3.y, quad3.width, quad3.height);	
			}
		}	//	FBO 3 
		{
			if ( fbo4 )	{
				rm4.startOffscreenDraw();
					if	(	viewRaton4	)	{
						ofFill();
						ofSetColor(0xFFFFFF);
						raton.draw(0,0);						
					}
					if	(	viewLadrillo4	)	{
						ofFill();
						ofSetColor(0xFFFFFF);
						ladrillo.draw(0,0);						
					}
					if	(	defaultFBO	)	{							
						ofSetColor(255,255,255);
						ofRect(0, 0, rm4.width, rm4.height);							
						ofSetColor(0xFF0000);
						ofLine(0, 0, rm4.width, rm4.height);							
						ofSetColor(0xFF0000);
						ofLine(rm4.width, 0, 0, rm4.height);							
					}													
				rm4.endOffscreenDraw();
				rm4.drawOutputDiagnostically(quad4.x, quad4.y, quad4.width, quad4.height);	
			}
		}	//	FBO 4 
		{
			if ( fbo5 )	{
				rm5.startOffscreenDraw();
					if	(	defaultFBO	)	{							
						ofSetColor(255,255,255);
						ofRect(0, 0, rm5.width, rm5.height);							
						ofSetColor(0xFF0000);
						ofLine(0, 0, rm5.width, rm5.height);							
						ofSetColor(0xFF0000);
						ofLine(rm5.width, 0, 0, rm5.height);							
					}																	
//					if (viewBFBO5) {
//						floresVideo.idleMovie();
//						ofSetColor(0xFFFFFF);
//						floresVideo.draw(0,0, 430, 660);
//					}
				rm5.endOffscreenDraw();
				rm5.drawOutputDiagnostically(quad5.x, quad5.y, quad5.width, quad5.height);	
			}
		}	//	FBO 5 flores
		{
			if ( fbo6 )	{
				rm6.startOffscreenDraw();
					if	(	defaultFBO	)	{							
						ofSetColor(255,255,255);
						ofRect(0, 0, rm6.width, rm6.height);							
						ofSetColor(0xFF0000);
						ofLine(0, 0, rm6.width, rm6.height);							
						ofSetColor(0xFF0000);
						ofLine(rm6.width, 0, 0, rm6.height);							
					}																					
					if	( viewFlores6 )	{
						ofFill();
						ofSetColor(0xFFFFFF);
						flores.draw(0,0);						
					}	
					if	(	viewMontanasRojas	)	{					
						ofFill();
						ofSetColor(255,255,255,afbo6);												
						montanasRojas.draw(0,0);						
					}
				rm6.endOffscreenDraw();
				rm6.drawOutputDiagnostically(quad6.x, quad6.y, quad6.width, quad6.height);	
			}
		}	//	FBO 6 textura
		{
			if ( fbo7 )	{
				rm7.startOffscreenDraw();
					if	(	defaultFBO	)	{							
						ofSetColor(255,255,255);
						ofRect(0, 0, rm7.width, rm7.height);							
						ofSetColor(0xFF0000);
						ofLine(0, 0, rm7.width, rm7.height);							
						ofSetColor(0xFF0000);
						ofLine(rm7.width, 0, 0, rm7.height);							
					}																	
					if (	viewMontanas	) {
						ofFill();
						ofSetColor(255,255,255,afbo7);												
						montanas.draw(0,0);																		
					}
				rm7.endOffscreenDraw();
				rm7.drawOutputDiagnostically(quad7.x, quad7.y, quad7.width, quad7.height);	
			}
		}	//	FBO 7
		{
			if ( fbo8 )	{
				rm8.startOffscreenDraw();
					if	(	defaultFBO	)	{							
						ofSetColor(255,255,255);
						ofRect(0, 0, rm8.width, rm8.height);							
						ofSetColor(0xFF0000);
						ofLine(0, 0, rm8.width, rm8.height);							
						ofSetColor(0xFF0000);
						ofLine(rm8.width, 0, 0, rm8.height);							
					}																	
					if (	viewMontanasBlancas	) {
						ofFill();
						ofSetColor(255,255,255,afbo8);												
						montanasBlancas.draw(0,0);																		
					}
				rm8.endOffscreenDraw();
				rm8.drawOutputDiagnostically(quad8.x, quad8.y, quad8.width, quad8.height);	
			}
		}	//	FBO 8
		{
			if ( fbo9 )	{
				rm9.startOffscreenDraw();
					if	(	defaultFBO	)	{							
						ofSetColor(255,255,255);
						ofRect(0, 0, rm9.width, rm9.height);							
						ofSetColor(0xFF0000);
						ofLine(0, 0, rm9.width, rm9.height);							
						ofSetColor(0xFF0000);
						ofLine(rm9.width, 0, 0, rm9.height);							
					}																	
				rm9.endOffscreenDraw();
				rm9.drawOutputDiagnostically(quad9.x, quad9.y, quad9.width, quad9.height);	
			}
		}	//	FBO 9

		{
			if ( fbo10 )	{
				rm10.startOffscreenDraw();
					if	(	defaultFBO	)	{							
						ofSetColor(255,255,255);
						ofRect(0, 0, rm10.width, rm10.height);							
						ofSetColor(0xFF0000);
						ofLine(0, 0, rm10.width, rm10.height);							
						ofSetColor(0xFF0000);
						ofLine(rm10.width, 0, 0, rm10.height);							
					}																	
				rm10.endOffscreenDraw();
				rm10.drawOutputDiagnostically(quad10.x, quad10.y, quad10.width, quad10.height);	
			}
		}	//	FBO 10
		{
			if ( fbo11) {
				rm11.startOffscreenDraw();
					if	(	defaultFBO	)	{							
						ofSetColor(255,255,255);
						ofRect(0, 0, rm11.width, rm11.height);							
						ofSetColor(0xFF0000);
						ofLine(0, 0, rm11.width, rm11.height);							
						ofSetColor(0xFF0000);
						ofLine(rm11.width, 0, 0, rm11.height);							
					}																	
				rm11.endOffscreenDraw();
				rm11.drawOutputDiagnostically(quad11.x, quad11.y, quad11.width, quad11.height);	
			}
		}	//	FBO 11
		{
			if ( fbo12 )	{
				rm12.startOffscreenDraw();
				if	(	defaultFBO	)	{							
					ofSetColor(255,255,255);
					ofRect(0, 0, rm12.width, rm12.height);							
					ofSetColor(0xFF0000);
					ofLine(0, 0, rm12.width, rm12.height);							
					ofSetColor(0xFF0000);
					ofLine(rm12.width, 0, 0, rm12.height);							
				}																	
				rm12.endOffscreenDraw();
				rm12.drawOutputDiagnostically(quad12.x, quad12.y, quad12.width, quad12.height);	
			}			
		}	//	FBO 12
		{
			if ( fbo13 )	{
				rm13.startOffscreenDraw();
				if	(	defaultFBO	)	{							
					ofSetColor(255,255,255);
					ofRect(0, 0, rm13.width, rm13.height);							
					ofSetColor(0xFF0000);
					ofLine(0, 0, rm13.width, rm13.height);							
					ofSetColor(0xFF0000);
					ofLine(rm13.width, 0, 0, rm13.height);							
				}																					
				if	( viewFlores13 )	{
					ofFill();
					ofSetColor(0xFFFFFF);
					flores.draw(0,0);						
				}
				rm13.endOffscreenDraw();
				rm13.drawOutputDiagnostically(quad13.x, quad13.y, quad13.width, quad13.height);	
			}
		}	//	FBO 13
		{
			if ( fbo14 )	{
				rm14.startOffscreenDraw();
				if	(	defaultFBO	)	{							
					ofSetColor(255,255,255);
					ofRect(0, 0, rm14.width, rm14.height);							
					ofSetColor(0xFF0000);
					ofLine(0, 0, rm14.width, rm14.height);							
					ofSetColor(0xFF0000);
					ofLine(rm14.width, 0, 0, rm14.height);							
				}																					
				if	( viewFlores14 )	{
						ofFill();
						ofSetColor(0xFFFFFF);
						flores.draw(0,0);						
					}
				rm14.endOffscreenDraw();
				rm14.drawOutputDiagnostically(quad14.x, quad14.y, quad14.width, quad14.height);	
			}
		}	//	FBO 14
		{
			if ( fbo15 )	{
				rm15.startOffscreenDraw();
				if	(	defaultFBO	)	{							
					ofSetColor(255,255,255);
					ofRect(0, 0, rm15.width, rm15.height);							
					ofSetColor(0xFF0000);
					ofLine(0, 0, rm15.width, rm15.height);							
					ofSetColor(0xFF0000);
					ofLine(rm15.width, 0, 0, rm15.height);							
				}																					
//				if	( viewFBO15 )	{
//					ofFill();
//					ofSetColor(255,255,255,afbo15_17);												
//					muroCasaAlta.draw(0,0);
//				}
				rm15.endOffscreenDraw();
				rm15.drawOutputDiagnostically(quad15.x, quad15.y, quad15.width, quad15.height);	
			}
		}	//	FBO 15
		{
			if ( fbo16 )	{
				rm16.startOffscreenDraw();
				if	(	defaultFBO	)	{							
					ofSetColor(255,255,255);
					ofRect(0, 0, rm16.width, rm16.height);							
					ofSetColor(0xFF0000);
					ofLine(0, 0, rm16.width, rm16.height);							
					ofSetColor(0xFF0000);
					ofLine(rm16.width, 0, 0, rm16.height);							
				}																									
				rm16.endOffscreenDraw();
				rm16.drawOutputDiagnostically(quad16.x, quad16.y, quad16.width, quad16.height);	
			}
		}	//	FBO 16
		{
			if ( fbo17 )	{
				rm17.startOffscreenDraw();
				if	(	defaultFBO	)	{							
					ofSetColor(255,255,255);
					ofRect(0, 0, rm17.width, rm17.height);							
					ofSetColor(0xFF0000);
					ofLine(0, 0, rm17.width, rm17.height);							
					ofSetColor(0xFF0000);
					ofLine(rm17.width, 0, 0, rm17.height);							
				}	
//				if (	viewFBO17	) {
//					ofFill();
//					ofSetColor(255,255,255,afbo15_17);												
//					muroCasaAlta.draw(0,0);					
//				}					
				rm17.endOffscreenDraw();
				rm17.drawOutputDiagnostically(quad17.x, quad17.y, quad17.width, quad17.height);	
			}
		}	//	FBO 17
		{
			if ( fbo18 )	{
				rm18.startOffscreenDraw();
				if	(	defaultFBO	)	{							
					ofSetColor(255,255,255);
					ofRect(0, 0, rm18.width, rm18.height);							
					ofSetColor(0xFF0000);
					ofLine(0, 0, rm18.width, rm18.height);							
					ofSetColor(0xFF0000);
					ofLine(rm18.width, 0, 0, rm18.height);							
				}	
				rm18.endOffscreenDraw();
				rm18.drawOutputDiagnostically(quad18.x, quad18.y, quad18.width, quad18.height);	
			}
		}	//	FBO 18
		{
			if ( fbo19 )	{
				rm19.startOffscreenDraw();
				if	(	defaultFBO	)	{							
					ofSetColor(255,255,255);
					ofRect(0, 0, rm19.width, rm19.height);							
					ofSetColor(0xFF0000);
					ofLine(0, 0, rm19.width, rm19.height);							
					ofSetColor(0xFF0000);
					ofLine(rm19.width, 0, 0, rm19.height);							
				}					
				rm19.endOffscreenDraw();
				rm19.drawOutputDiagnostically(quad19.x, quad19.y, quad19.width, quad19.height);	
			}
		}	//	FBO 19


		{
			if ( fbo20 )	{
				rm20.startOffscreenDraw();
					if	(	defaultFBO	)	{							
						ofSetColor(255,255,255);
						ofRect(0, 0, rm20.width, rm20.height);							
						ofSetColor(0xFF0000);
						ofLine(0, 0, rm20.width, rm20.height);							
						ofSetColor(0xFF0000);
						ofLine(rm20.width, 0, 0, rm20.height);							
					}					
					if	(	viewRaton20	)	{
						ofFill();
						ofSetColor(0xFFFFFF);
						raton.draw(0,0);						
					}
					if	(	viewLadrillo20	)	{
						ofFill();
						ofSetColor(0xFFFFFF);
						ladrillo.draw(0,0);						
					}
				rm20.endOffscreenDraw();
				rm20.drawOutputDiagnostically(quad20.x, quad20.y, quad20.width, quad20.height);	
			}
		}	//	FBO 20
		{
			if ( fbo21) {
				rm21.startOffscreenDraw();
					if	(	defaultFBO	)	{							
						ofSetColor(255,255,255);
						ofRect(0, 0, rm21.width, rm21.height);							
						ofSetColor(0xFF0000);
						ofLine(0, 0, rm21.width, rm21.height);							
						ofSetColor(0xFF0000);
						ofLine(rm21.width, 0, 0, rm21.height);							
					}					
				
					if	( viewFlores14 )	{
						ofFill();
						ofSetColor(0xFFFFFF);
						flores.draw(0,0);						
					}	
					if	(	viewVentanaRota	)	{										
						ofFill();
						ofSetColor(255,255,255,afbo21_23);												
						ventanaRota.draw(0,0);
					}
					if	(	viewChimanea	)	{										
						ofFill();
						ofSetColor(255,255,255,afbo123);												
						chimanea.draw(0,0);						
					}						
				rm21.endOffscreenDraw();
				rm21.drawOutputDiagnostically(quad21.x, quad21.y, quad21.width, quad21.height);	
			}
		}	//	FBO 21
		{
			if ( fbo22 )	{
				rm22.startOffscreenDraw();
					if	(	defaultFBO	)	{							
						ofSetColor(255,255,255);
						ofRect(0, 0, rm22.width, rm22.height);							
						ofSetColor(0xFF0000);
						ofLine(0, 0, rm22.width, rm22.height);							
						ofSetColor(0xFF0000);
						ofLine(rm22.width, 0, 0, rm22.height);							
					}									
					if	(	viewRaton22	)	{
						ofFill();
						ofSetColor(0xFFFFFF);
						raton.draw(0,0);						
					}
					if	(	viewLadrillo22	)	{
						ofFill();
						ofSetColor(0xFFFFFF);
						ladrillo.draw(0,0);						
					}
				rm22.endOffscreenDraw();
				rm22.drawOutputDiagnostically(quad22.x, quad22.y, quad22.width, quad22.height);	
			}			
		}	//	FBO 22
		{
			if ( fbo23 )	{
				rm23.startOffscreenDraw();
					if	(	defaultFBO	)	{							
						ofSetColor(255,255,255);
						ofRect(0, 0, rm23.width, rm23.height);							
						ofSetColor(0xFF0000);
						ofLine(0, 0, rm23.width, rm23.height);							
						ofSetColor(0xFF0000);
						ofLine(rm23.width, 0, 0, rm23.height);							
					}					
//					if (viewFBO23) {
//						ofFill();
//						ofSetColor(255,255,255,afbo21_23);												
//						tejadosCasaDerecha.draw(0,0);						
//					}					
				rm23.endOffscreenDraw();
				rm23.drawOutputDiagnostically(quad23.x, quad23.y, quad23.width, quad23.height);	
			}
		}	//	FBO 23
		{
			if ( fbo24 )	{
				if ( doRender ) {			
					rm24.startOffscreenDraw();
						ofFill();
						ofSetColor(25, 230, 255);
						ofRect(0,0,500,500);
					rm24.endOffscreenDraw();
				}
				rm24.drawOutputDiagnostically(quad24.x, quad24.y, quad24.width, quad24.height);	
			}
		}	//	FBO 24
		{
			if ( fbo25 )	{
				if ( doRender ) {		
					rm25.startOffscreenDraw();
						ofFill();
						ofSetColor(10, 120, 215);
						ofRect(0,0,500,500);
					rm25.endOffscreenDraw();
				}
				rm25.drawOutputDiagnostically(quad25.x, quad25.y, quad25.width, quad25.height);	
			}
		}	//	FBO 25
		{
			if ( fbo26 )	{
				if ( doRender ) {		
					rm26.startOffscreenDraw();
						ofFill();
						ofSetColor(110, 20, 255);
						ofRect(0,0,500,500);
					rm26.endOffscreenDraw();
				}
				rm26.drawOutputDiagnostically(quad26.x, quad26.y, quad26.width, quad26.height);	
			}
		}	//	FBO 26
		{
			if ( fbo27 )	{
				if ( doRender ) {		
					rm27.startOffscreenDraw();
						ofFill();
						ofSetColor(55, 55, 220);
						ofRect(0,0,500,500);
					rm27.endOffscreenDraw();
				}
				rm27.drawOutputDiagnostically(quad27.x, quad27.y, quad27.width, quad27.height);	
			}
		}	//	FBO 27
		{
			if ( fbo28 )	{
				if ( doRender ) {		
					rm28.startOffscreenDraw();
						ofFill();
						ofSetColor(110, 255, 120);
						ofRect(0,0,500,500);
					rm28.endOffscreenDraw();
				}
				rm28.drawOutputDiagnostically(quad28.x, quad28.y, quad28.width, quad28.height);	
			}
		}	//	FBO 28
		{
			if ( fbo29 )	{
				if ( doRender ) {		
					rm29.startOffscreenDraw();
						ofFill();
						ofSetColor(10, 120, 155);
						ofRect(0,0,500,500);
					rm29.endOffscreenDraw();
				}
				rm29.drawOutputDiagnostically(quad29.x, quad29.y, quad29.width, quad29.height);	
			}
		}	//	FBO 29

	}	//	FBO Manager
	if	(view_fillBackground)	{
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // GL_SRC_ALPHA_SATURATE,GL_ONE     GL_SRC_ALPHA, GL_ONE
		ofFill();	
		ofSetColor(r8, g8, b8, a8);
		ofRect(0,0,ofGetWidth(),ofGetHeight());			
	}		
	if	(arbolView)	{
		arbol.mouseArbolX = mouseX;
		arbol.mouseArbolY = mouseY;
		arbol.update();
	}		
	if	(circleView)	{
		th3 = ofRandom(0, 2*PI);
		cx1 = ofGetScreenWidth()/2 + r*cos(th3);
		cy1 = ofGetScreenHeight()/2 + r*sin(th3);
		
		cx2 = ofGetScreenWidth()/2 + r*cos(th1);
		cy2 = ofGetScreenHeight()/2 + r*sin(th1);
		
		x2 = ofGetScreenWidth()/2 + r*cos(th2);
		y2 = ofGetScreenHeight()/2 + r*sin(th2);
		
		sth3 = ofRandom(0, 2*PI);
		
		scx1 = ofGetScreenWidth()/2 + sr*cos(sth3);
		scy1 = ofGetScreenHeight()/2 + sr*sin(sth3);
		
		scx2 = ofGetScreenWidth()/2 + sr*cos(sth1);
		scy2 = ofGetScreenHeight()/2 + sr*sin(sth1);
		
		sx2 = ofGetScreenWidth()/2 + sr*cos(sth2);
		sy2 = ofGetScreenHeight()/2 + sr*sin(sth2);
		
		ofSetColor(r3,g3,b3,a3);
		ofBezier(x1, y1, cx1, cy1, cx2, cy2, x2, y2);
		ofSetColor(255-r3,255-g3,255-b3,a3);
		//	ofSetColor(255, 255, 255 ,12);
		ofBezier(sx1, sy1, scx1, scy1, scx2, scy2, sx2, sy2);
	}
	if	(viewSuperformula)	{
		//(m, n1, n2, n3, step, epi, num)
		//superformula.init(1, -1, 0, 0, 0.1, 20, 180);
		//		superformula.init(ofMap(r1, 0, 255, 0.01, 50), 1, ofMap(g1, 0, 255, -6, 16), ofMap(b1, 0, 255, 0.01, 20), ofMap(r2, 0, 255, 0.1, 10), ofMap(g2, 0, 255, 10, 500), 180);
		//		superformula.init(int(ofRandom(3.0,6.0)), ofRandom(0.0 ,0.5), ofRandom(0.0, 6.0), int(ofRandom(0.0,10.0)), ofRandom(0.01,10.0), int(ofRandom(50.0, 150.0)), 10);
		
		//init(float m, float n1, float n2, float n3, float step, int epi, int num);
		//superformula.init(ofGetWidth()/2, ofGetHeight()/2, r4, g4, b4, a4, sformM, sformn1, sformn2, sformn3, sformStep, sformScale, sformNum, sformType);
		//		superformula.update(mouseX, mouseY, r4, g4, b4, a4);
		//superformula.update(ofGetWidth()/2, ofGetHeight()/2, r4, g4, b4, a4);
	}	//	superformula
	if	(viewSeashell)	{
		//ofTranslate(mouseX, mouseY);		// ofGetWidth()/2, ofGetHeight()/2
		ofTranslate(200,200);		// translate to the middleofGetWidth()/2, ofGetHeight()/2		
		ofRotateX(midi85);
		ofRotateY(midi93);
		ofRotateZ(midi101);		
		//seashell.init(r5, g5, b5,a5, seashellR, seashellN, seashellH, seashellP, seashellL, seashellK, seashellDu, seashellDv, seashellType, seashellScale, seashellSteps);
		ofRotateZ(-midi101);		
		ofRotateY(-midi93);
		ofRotateX(-midi85);
		ofTranslate(-200, -200);				
		//ofTranslate(-mouseX, -mouseY);		
	}		//  seashell
	if	(viewSoundChanels)	{
		Yamp0 = ofMap(ampChan0, ampInLow, ampInHigh, 0, ofGetHeight());
		Xfreq0 = ofMap(freqChan0, freqInLow, freqInHigh, 0, ofGetWidth());
		for( int i=1000; i<1000+numSoundSketches; i++ ) {
			sketch[i].drawSound(Xfreq0, Yamp0, 0, r6, g6, b6, a6, soundLines);	
		}
		if (Yamp0 < 0.05)	{	Xfreq0 = 0;					Yamp0 =  0;					}
				
	{
		/*
		if (Yamp1 < 0.05)	{	Xfreq1 = ofGetWidth()/2;	Yamp1 =  0;		}
		if (Yamp2 < 0.05)	{	Xfreq2 = ofGetWidth();		Yamp2 =  0;		}
		if (Yamp3 < 0.05)	{	Xfreq3 = ofGetWidth();		Yamp3 =  ofGetHeight()/2;		}
		if (Yamp4 < 0.05)	{	Xfreq4 = ofGetWidth();		Yamp4 =  ofGetHeight();		}
		if (Yamp5 < 0.05)	{	Xfreq5 = ofGetWidth()/2;	Yamp5 =  ofGetHeight();		}
		if (Yamp6 < 0.05)	{	Xfreq6 = 0;					Yamp6 =  ofGetHeight();		}
		if (Yamp7 < 0.05)	{	Xfreq7 = 0;					Yamp7 =  ofGetHeight()/2;		}

		Yamp0=Yamp1=Yamp2=Yamp3=Yamp4=Yamp5=Yamp6=Yamp7 = ofMap(ampChan0, ampInLow, ampInHigh, 0, ofGetScreenHeight());
		Xfreq0=Xfreq1=Xfreq2=Xfreq3=Xfreq4=Xfreq5=Xfreq6=Xfreq7 = ofMap(freqChan0, freqInLow, freqInHigh, 0, ofGetScreenWidth());
	
		for( int i=1500; i<1500+numSoundSketches; i++ ) {
			sketch[i].drawSound(ofGetWidth() - Xfreq0, Yamp0, 0, r6, g6, b6, a6, soundLines);				
		}		
		for( int i=0; i<numSoundSketches; i++ ) {
			sketch[i].drawSound(Xfreq0, Yamp0, 0, r6, g6, b6, a6, soundLines);	
		}
		for( int i=100; i<100 + numSoundSketches; i++ ) {
			sketch[i].drawSound(Xfreq1, Yamp1, 0, r6, g6, b6, a6, soundLines);	
		}
		for( int i=200; i<200 + numSoundSketches; i++ ) {
			sketch[i].drawSound(ofGetWidth() - Xfreq2, Yamp2, 0, r6, g6, b6, a6, soundLines);	
		}		
		for( int i=300; i<300 + numSoundSketches; i++ ) {
			sketch[i].drawSound(ofGetWidth() - Xfreq3, Yamp3, 0, r6, g6, b6, a6, soundLines);	
		}		
		for( int i=400; i<400 + numSoundSketches; i++ ) {
			sketch[i].drawSound(ofGetWidth() - Xfreq4, ofGetHeight() - Yamp4, 0, r6, g6, b6, a6, soundLines);	
		}		
		for( int i=500; i<500 + numSoundSketches; i++ ) {
			sketch[i].drawSound(Xfreq5, ofGetHeight() - Yamp5, 0, r6, g6, b6, a6, soundLines);	
		}		
		for( int i=600; i<600 + numSoundSketches; i++ ) {
			sketch[i].drawSound(Xfreq6, ofGetHeight() - Yamp6, 0, r6, g6, b6, a6, soundLines);	
		}		
		for( int i=700; i<700 + numSoundSketches; i++ ) {
			sketch[i].drawSound(Xfreq7, Yamp7, 0, r6, g6, b6, a6, soundLines);	
		}	
		*/
		}	//	Develop
	}  	//  viewSoundChanels 
	if	(drawWithMouse)	{
		if	(drawNow)	{
			//sketch[1000].sound(mouseX, mouseY);
			for( int i=1000; i<1000 + numMouseSketches; i++ ) {
				sketch[i].drawMouse(mouseX, mouseY, 0, r7, g7, b7, a7/3, mouseLines);	
			}
		}	else	{
			//sketch[1000].stoping(mouseX, mouseY);	
			for( int i=1000; i<1000 + numMouseSketches; i++ ) {
				sketch[i].drawMouse(mouseX, mouseY, 0, r7, g7, b7, 0, mouseLines);	
			}
		}
	}	//	draw with mouse
	if	(feedbackView)	{
		//texScreen.loadScreenData(0,0,ofGetScreenWidth(),ofGetScreenHeight());	
		//texScreen.loadScreenData(0,0,1000, 1200);			
		//texScreen.loadScreenData(0,0,1920, 1080);			
		//texScreen.loadScreenData(0,0,3840, 1024);					
		texScreen.loadScreenData(0,0,ofGetWidth(), ofGetHeight());					
		
		
		// finally, draw that texture on screen, how ever you want
		// (note: you can even draw the texture before you call loadScreenData, 
		// in order to make some trails or feedback type effects)
		if	(timeLine)	{
			glPushMatrix();
			ofSetColor(0xffffff);
			glTranslatef(feedbackSpeedX,feedbackSpeedY,0);
			texScreen.draw(0,0,ofGetWidth(), ofGetHeight());
			//texScreen.draw(0,0,3840, 1024);			
			//texScreen.draw(0,0,1920,1080);
			glPopMatrix();
		}
	}
	if	(bSnapshot)	{
		takePictures();
	}
}
void granCieloApp::syncStudies ()	{
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // GL_SRC_ALPHA_SATURATE,GL_ONE     GL_SRC_ALPHA, GL_ONE
		ofFill();
		strPosX = ofRandom(0, ofGetWidth());
		strPosY = ofRandom(0, ofGetHeight());
		ofSetColor(r1,g1,b1,a1);	// even
		ofPushMatrix();
		ofTranslate(strPosX, strPosY, 0);
		testFontSmall.drawString(beatStr,0, 0);		
		ofPopMatrix();
}
void granCieloApp::takePictures()	{
	img.grabScreen(0,0,600, 600);
	//img.grabScreen(0,0,4256,2832);
	char fileName[255];
	sprintf(fileName, "100406_%0.3i.png", snapCounter);
	img.saveImage(fileName);
	sprintf(snapString, "x %s", fileName);
	snapCounter++;
	bSnapshot = false;
}
void granCieloApp::keyPressed  (int key){

	if ( key == '0' ) {		
		fbo0 = !fbo0;	
		if(fbo0){
			ciudaddestruidaconlluvia.play();
		} else {
			ciudaddestruidaconlluvia.stop();			
		}		
	
	}		
	if ( key == '1' ) {		fbo1 = !fbo1;	}		
	if ( key == '2' ) {		fbo2 = !fbo2;	}		
	if ( key == '3' ) {		
		fbo3 = !fbo3;	
		if(fbo3){
			illusion.play();
		} else {
			illusion.stop();			
		}		
	}			
	if ( key == '4' ) {		fbo4 = !fbo4;	}	
	if ( key == '5' ) {		
		fbo5 = !fbo5;	
		if(fbo5){
			ormigas.play();
		} else {
			ormigas.stop();			
		}		
	}			
	if ( key == '6' ) {		fbo6 = !fbo6;	}		
	if ( key == '7' ) {		fbo7 = !fbo7;	}			
	if ( key == '8' ) {		fbo8 = !fbo8;	}			
	if ( key == '9' ) {		fbo9 = !fbo9;	}					
	if ( key == 'q' ) {		fbo10 = !fbo10;	}					
	if ( key == 'w' ) {		fbo11 = !fbo11;	}					
	if ( key == 'e' ) {		fbo12 = !fbo12;	}					
	if ( key == 'r' ) {		fbo13 = !fbo13;	}					
	if ( key == 't' ) {		fbo14 = !fbo14;	}					
	if ( key == 'y' ) {		fbo15 = !fbo15;	}					
	if ( key == 'u' ) {		fbo16 = !fbo16;	}					
	if ( key == 'i' ) {		fbo17 = !fbo17;	}					
	if ( key == 'o' ) {		fbo18 = !fbo18;	}					
	if ( key == 'p' ) {		fbo19 = !fbo19;	}					
	if ( key == 'a' ) {		fbo20 = !fbo20;	}					
	if ( key == 's' ) {		fbo21 = !fbo21;	}					
	if ( key == 'd' ) {		fbo22 = !fbo22;	}					
	if ( key == 'f' ) {		fbo23 = !fbo23;	}					
	if ( key == 'g' ) {		fbo24 = !fbo24;	}					
	if ( key == 'h' ) {		fbo25 = !fbo25;	}					
	if ( key == 'j' ) {		fbo26 = !fbo26;	}					
	if ( key == 'k' ) {		fbo27 = !fbo27;	}					
	if ( key == 'l' ) {		fbo28 = !fbo28;	}					
	if ( key == ';' ) {		fbo29 = !fbo29;	}					
		
	
	if	(key == 'm')	{	ofHideCursor();	}
	if	(key == 'M')	{	ofShowCursor();	}
//	if	(key == 'x')	{	bSnapshot = true;	}
//  if ( key == 'g')	{	toggleImage = !toggleImage;    }	
	
    if( key == 'x'){	
		if ( fbo0 ) {    rm0.saveToXml(); }
		if ( fbo1 ) {    rm1.saveToXml(); }
		if ( fbo2 ) {    rm2.saveToXml(); }
		if ( fbo3 ) {    rm3.saveToXml(); }
		if ( fbo4 ) {    rm4.saveToXml(); }
		if ( fbo5 ) {    rm5.saveToXml(); }
		if ( fbo6 ) {    rm6.saveToXml(); }
		if ( fbo7 ) {    rm7.saveToXml(); }		
		if ( fbo8 ) {    rm8.saveToXml(); }		
		if ( fbo9 ) {    rm9.saveToXml(); }						
		if ( fbo10 ) {    rm10.saveToXml(); }
		if ( fbo11 ) {    rm11.saveToXml(); }
		if ( fbo12 ) {    rm12.saveToXml(); }
		if ( fbo13 ) {    rm13.saveToXml(); }
		if ( fbo14 ) {    rm14.saveToXml(); }
		if ( fbo15 ) {    rm15.saveToXml(); }
		if ( fbo16 ) {    rm16.saveToXml(); }
		if ( fbo17 ) {    rm17.saveToXml(); }		
		if ( fbo18 ) {    rm18.saveToXml(); }		
		if ( fbo19 ) {    rm19.saveToXml(); }						
		if ( fbo20 ) {    rm20.saveToXml(); }
		if ( fbo21 ) {    rm21.saveToXml(); }
		if ( fbo22 ) {    rm22.saveToXml(); }
		if ( fbo23 ) {    rm23.saveToXml(); }
		if ( fbo24 ) {    rm24.saveToXml(); }
		if ( fbo25 ) {    rm25.saveToXml(); }
		if ( fbo26 ) {    rm26.saveToXml(); }
		if ( fbo27 ) {    rm27.saveToXml(); }		
		if ( fbo28 ) {    rm28.saveToXml(); }		
		if ( fbo29 ) {    rm29.saveToXml(); }						
    }	
    if( key == 'z' ){
		if ( fbo0 ) { rm0.reloadFromXml(); }
		if ( fbo1 ) { rm1.reloadFromXml(); }
		if ( fbo2 ) { rm2.reloadFromXml(); }
		if ( fbo3 ) { rm3.reloadFromXml(); }
		if ( fbo4 ) { rm4.reloadFromXml(); }
		if ( fbo5 ) { rm5.reloadFromXml(); }								
		if ( fbo6 ) { rm6.reloadFromXml(); }										
		if ( fbo7 ) { rm7.reloadFromXml(); }												
		if ( fbo8 ) { rm8.reloadFromXml(); }												
		if ( fbo9 ) { rm9.reloadFromXml(); }																
		if ( fbo10 ) { rm10.reloadFromXml(); }
		if ( fbo11 ) { rm11.reloadFromXml(); }
		if ( fbo12 ) { rm12.reloadFromXml(); }
		if ( fbo13 ) { rm13.reloadFromXml(); }
		if ( fbo14 ) { rm14.reloadFromXml(); }
		if ( fbo15 ) { rm15.reloadFromXml(); }								
		if ( fbo16 ) { rm16.reloadFromXml(); }										
		if ( fbo17 ) { rm17.reloadFromXml(); }												
		if ( fbo18 ) { rm18.reloadFromXml(); }												
		if ( fbo19 ) { rm19.reloadFromXml(); }																
		if ( fbo20 ) { rm20.reloadFromXml(); }
		if ( fbo21 ) { rm21.reloadFromXml(); }
		if ( fbo22 ) { rm22.reloadFromXml(); }
		if ( fbo23 ) { rm23.reloadFromXml(); }
		if ( fbo24 ) { rm24.reloadFromXml(); }
		if ( fbo25 ) { rm25.reloadFromXml(); }								
		if ( fbo26 ) { rm26.reloadFromXml(); }										
		if ( fbo27 ) { rm27.reloadFromXml(); }												
		if ( fbo28 ) { rm28.reloadFromXml(); }												
		if ( fbo29 ) { rm29.reloadFromXml(); }																
	}	
    if(key == 'c'){
		if ( fbo0 ) { rm0.resetCoordinates(); }
		if ( fbo1 ) { rm1.resetCoordinates(); }
		if ( fbo2 ) { rm2.resetCoordinates(); }
		if ( fbo3 ) { rm3.resetCoordinates(); }
		if ( fbo4 ) { rm4.resetCoordinates(); }
		if ( fbo5 ) { rm5.resetCoordinates(); }									
		if ( fbo6 ) { rm6.resetCoordinates(); }
		if ( fbo7 ) { rm7.resetCoordinates(); }		
		if ( fbo8 ) { rm8.resetCoordinates(); }		
		if ( fbo9 ) { rm9.resetCoordinates(); }					
		if ( fbo10 ) { rm10.resetCoordinates(); }
		if ( fbo11 ) { rm11.resetCoordinates(); }
		if ( fbo12 ) { rm12.resetCoordinates(); }
		if ( fbo13 ) { rm13.resetCoordinates(); }
		if ( fbo14 ) { rm14.resetCoordinates(); }
		if ( fbo15 ) { rm15.resetCoordinates(); }									
		if ( fbo16 ) { rm16.resetCoordinates(); }
		if ( fbo17 ) { rm17.resetCoordinates(); }		
		if ( fbo18 ) { rm18.resetCoordinates(); }		
		if ( fbo19 ) { rm19.resetCoordinates(); }					
		if ( fbo20 ) { rm20.resetCoordinates(); }
		if ( fbo21 ) { rm21.resetCoordinates(); }
		if ( fbo22 ) { rm22.resetCoordinates(); }
		if ( fbo23 ) { rm23.resetCoordinates(); }
		if ( fbo24 ) { rm24.resetCoordinates(); }
		if ( fbo25 ) { rm25.resetCoordinates(); }									
		if ( fbo26 ) { rm26.resetCoordinates(); }
		if ( fbo27 ) { rm27.resetCoordinates(); }		
		if ( fbo28 ) { rm28.resetCoordinates(); }		
		if ( fbo29 ) { rm29.resetCoordinates(); }					
    }	
//    if(key == 't'){
//        doRender = !doRender;
//    }
    if(key == 'n'){
		if ( fbo0 ) { rm0.viewControlPoints = 1; }
		if ( fbo1 ) { rm1.viewControlPoints = 1; }
		if ( fbo2 ) { rm2.viewControlPoints = 1; }
		if ( fbo3 ) { rm3.viewControlPoints = 1; }
		if ( fbo4 ) { rm4.viewControlPoints = 1; }
		if ( fbo5 ) { rm5.viewControlPoints = 1; }
		if ( fbo6 ) { rm6.viewControlPoints = 1; }
		if ( fbo7 ) { rm7.viewControlPoints = 1; }		
		if ( fbo8 ) { rm8.viewControlPoints = 1; }		
		if ( fbo9 ) { rm9.viewControlPoints = 1; }						
		if ( fbo10 ) { rm10.viewControlPoints = 1; }
		if ( fbo11 ) { rm11.viewControlPoints = 1; }
		if ( fbo12 ) { rm12.viewControlPoints = 1; }
		if ( fbo13 ) { rm13.viewControlPoints = 1; }
		if ( fbo14 ) { rm14.viewControlPoints = 1; }
		if ( fbo15 ) { rm15.viewControlPoints = 1; }
		if ( fbo16 ) { rm16.viewControlPoints = 1; }
		if ( fbo17 ) { rm17.viewControlPoints = 1; }		
		if ( fbo18 ) { rm18.viewControlPoints = 1; }		
		if ( fbo19 ) { rm19.viewControlPoints = 1; }						
		if ( fbo20 ) { rm20.viewControlPoints = 1; }
		if ( fbo21 ) { rm21.viewControlPoints = 1; }
		if ( fbo22 ) { rm22.viewControlPoints = 1; }
		if ( fbo23 ) { rm23.viewControlPoints = 1; }
		if ( fbo24 ) { rm24.viewControlPoints = 1; }
		if ( fbo25 ) { rm25.viewControlPoints = 1; }
		if ( fbo26 ) { rm26.viewControlPoints = 1; }
		if ( fbo27 ) { rm27.viewControlPoints = 1; }		
		if ( fbo28 ) { rm28.viewControlPoints = 1; }		
		if ( fbo29 ) { rm29.viewControlPoints = 1; }						
    }
    if(key == 'N'){
		if ( fbo0 ) { rm0.viewControlPoints = 0; }
		if ( fbo1 ) { rm1.viewControlPoints = 0; }
		if ( fbo2 ) { rm2.viewControlPoints = 0; }
		if ( fbo3 ) { rm3.viewControlPoints = 0; }
		if ( fbo4 ) { rm4.viewControlPoints = 0; }
		if ( fbo5 ) { rm5.viewControlPoints = 0; }
		if ( fbo6 ) { rm6.viewControlPoints = 0; }
		if ( fbo7 ) { rm7.viewControlPoints = 0; }		
		if ( fbo8 ) { rm8.viewControlPoints = 0; }		
		if ( fbo9 ) { rm9.viewControlPoints = 0; }				
		if ( fbo10 ) { rm10.viewControlPoints = 0; }
		if ( fbo11 ) { rm11.viewControlPoints = 0; }
		if ( fbo12 ) { rm12.viewControlPoints = 0; }
		if ( fbo13 ) { rm13.viewControlPoints = 0; }
		if ( fbo14 ) { rm14.viewControlPoints = 0; }
		if ( fbo15 ) { rm15.viewControlPoints = 0; }
		if ( fbo16 ) { rm16.viewControlPoints = 0; }
		if ( fbo17 ) { rm17.viewControlPoints = 0; }		
		if ( fbo18 ) { rm18.viewControlPoints = 0; }		
		if ( fbo19 ) { rm19.viewControlPoints = 0; }				
		if ( fbo20 ) { rm20.viewControlPoints = 0; }
		if ( fbo21 ) { rm21.viewControlPoints = 0; }
		if ( fbo22 ) { rm22.viewControlPoints = 0; }
		if ( fbo23 ) { rm23.viewControlPoints = 0; }
		if ( fbo24 ) { rm24.viewControlPoints = 0; }
		if ( fbo25 ) { rm25.viewControlPoints = 0; }
		if ( fbo26 ) { rm26.viewControlPoints = 0; }
		if ( fbo27 ) { rm27.viewControlPoints = 0; }		
		if ( fbo28 ) { rm28.viewControlPoints = 0; }		
		if ( fbo29 ) { rm29.viewControlPoints = 0; }				
    }

//	if (key == 'a'){
//		arbolView = true;	
//	}
//	if (key == 'A'){
//		arbolView = false;	
//	}
	
	if(key == 'v' or key == 'V'){
		full = !full;
		if(full){
			ofSetFullscreen(true);
		} else {
			ofSetFullscreen(false);
		}
	}		
	if(key == 'b' or key == 'B'){
		ofBackground(255, 255, 255);
	}	
}
void granCieloApp::keyReleased(int key){
	
}
void granCieloApp::mouseMoved(int x, int y ){
}
void granCieloApp::mouseDragged(int x, int y, int button){
	if ( fbo0 ) { rm0.mouseDragOutputPoint(quad0, ofPoint( x, y)); }
	if ( fbo1 ) { rm1.mouseDragOutputPoint(quad1, ofPoint( x, y)); }
	if ( fbo2 ) { rm2.mouseDragOutputPoint(quad2, ofPoint( x, y)); }
	if ( fbo3 ) { rm3.mouseDragOutputPoint(quad3, ofPoint( x, y)); }
	if ( fbo4 ) { rm4.mouseDragOutputPoint(quad4, ofPoint( x, y)); }
	if ( fbo5 ) { rm5.mouseDragOutputPoint(quad5, ofPoint( x, y)); }
	if ( fbo6 ) { rm6.mouseDragOutputPoint(quad6, ofPoint( x, y)); }
	if ( fbo7 ) { rm7.mouseDragOutputPoint(quad7, ofPoint( x, y)); }	
	if ( fbo8 ) { rm8.mouseDragOutputPoint(quad8, ofPoint( x, y)); }	
	if ( fbo9 ) { rm9.mouseDragOutputPoint(quad9, ofPoint( x, y)); }			
	if ( fbo10 ) { rm10.mouseDragOutputPoint(quad10, ofPoint( x, y)); }
	if ( fbo11 ) { rm11.mouseDragOutputPoint(quad11, ofPoint( x, y)); }
	if ( fbo12 ) { rm12.mouseDragOutputPoint(quad12, ofPoint( x, y)); }
	if ( fbo13 ) { rm13.mouseDragOutputPoint(quad13, ofPoint( x, y)); }
	if ( fbo14 ) { rm14.mouseDragOutputPoint(quad14, ofPoint( x, y)); }
	if ( fbo15 ) { rm15.mouseDragOutputPoint(quad15, ofPoint( x, y)); }
	if ( fbo16 ) { rm16.mouseDragOutputPoint(quad16, ofPoint( x, y)); }
	if ( fbo17 ) { rm17.mouseDragOutputPoint(quad17, ofPoint( x, y)); }	
	if ( fbo18 ) { rm18.mouseDragOutputPoint(quad18, ofPoint( x, y)); }	
	if ( fbo19 ) { rm19.mouseDragOutputPoint(quad19, ofPoint( x, y)); }			
	if ( fbo20 ) { rm20.mouseDragOutputPoint(quad20, ofPoint( x, y)); }
	if ( fbo21 ) { rm21.mouseDragOutputPoint(quad21, ofPoint( x, y)); }
	if ( fbo22 ) { rm22.mouseDragOutputPoint(quad22, ofPoint( x, y)); }
	if ( fbo23 ) { rm23.mouseDragOutputPoint(quad23, ofPoint( x, y)); }
	if ( fbo24 ) { rm24.mouseDragOutputPoint(quad24, ofPoint( x, y)); }
	if ( fbo25 ) { rm25.mouseDragOutputPoint(quad25, ofPoint( x, y)); }
	if ( fbo26 ) { rm26.mouseDragOutputPoint(quad26, ofPoint( x, y)); }
	if ( fbo27 ) { rm27.mouseDragOutputPoint(quad27, ofPoint( x, y)); }	
	if ( fbo28 ) { rm28.mouseDragOutputPoint(quad28, ofPoint( x, y)); }	
	if ( fbo29 ) { rm29.mouseDragOutputPoint(quad29, ofPoint( x, y)); }			
}
void granCieloApp::mousePressed	(int x, int y, int button)	{
	drawNow = true;	
	if ( fbo0 ) { rm0.mouseSelectOutputPoint(quad0, ofPoint( x,  y)); }
	if ( fbo1 ) { rm1.mouseSelectOutputPoint(quad1, ofPoint( x,  y)); }
	if ( fbo2 ) { rm2.mouseSelectOutputPoint(quad2, ofPoint( x,  y)); }
	if ( fbo3 ) { rm3.mouseSelectOutputPoint(quad3, ofPoint( x,  y)); }
	if ( fbo4 ) { rm4.mouseSelectOutputPoint(quad4, ofPoint( x,  y)); }
	if ( fbo5 ) { rm5.mouseSelectOutputPoint(quad5, ofPoint( x,  y)); }
	if ( fbo6 ) { rm6.mouseSelectOutputPoint(quad6, ofPoint( x,  y)); }
	if ( fbo7 ) { rm7.mouseSelectOutputPoint(quad7, ofPoint( x,  y)); }	
	if ( fbo8 ) { rm8.mouseSelectOutputPoint(quad8, ofPoint( x,  y)); }	
	if ( fbo9 ) { rm9.mouseSelectOutputPoint(quad9, ofPoint( x,  y)); }			
	if ( fbo10 ) { rm10.mouseSelectOutputPoint(quad10, ofPoint( x,  y)); }
	if ( fbo11 ) { rm11.mouseSelectOutputPoint(quad11, ofPoint( x,  y)); }
	if ( fbo12 ) { rm12.mouseSelectOutputPoint(quad12, ofPoint( x,  y)); }
	if ( fbo13 ) { rm13.mouseSelectOutputPoint(quad13, ofPoint( x,  y)); }
	if ( fbo14 ) { rm14.mouseSelectOutputPoint(quad14, ofPoint( x,  y)); }
	if ( fbo15 ) { rm15.mouseSelectOutputPoint(quad15, ofPoint( x,  y)); }
	if ( fbo16 ) { rm16.mouseSelectOutputPoint(quad16, ofPoint( x,  y)); }
	if ( fbo17 ) { rm17.mouseSelectOutputPoint(quad17, ofPoint( x,  y)); }	
	if ( fbo18 ) { rm18.mouseSelectOutputPoint(quad18, ofPoint( x,  y)); }	
	if ( fbo19 ) { rm19.mouseSelectOutputPoint(quad19, ofPoint( x,  y)); }			
	if ( fbo20 ) { rm20.mouseSelectOutputPoint(quad20, ofPoint( x,  y)); }
	if ( fbo21 ) { rm21.mouseSelectOutputPoint(quad21, ofPoint( x,  y)); }
	if ( fbo22 ) { rm22.mouseSelectOutputPoint(quad22, ofPoint( x,  y)); }
	if ( fbo23 ) { rm23.mouseSelectOutputPoint(quad23, ofPoint( x,  y)); }
	if ( fbo24 ) { rm24.mouseSelectOutputPoint(quad24, ofPoint( x,  y)); }
	if ( fbo25 ) { rm25.mouseSelectOutputPoint(quad25, ofPoint( x,  y)); }
	if ( fbo26 ) { rm26.mouseSelectOutputPoint(quad26, ofPoint( x,  y)); }
	if ( fbo27 ) { rm27.mouseSelectOutputPoint(quad27, ofPoint( x,  y)); }	
	if ( fbo28 ) { rm28.mouseSelectOutputPoint(quad28, ofPoint( x,  y)); }	
	if ( fbo29 ) { rm29.mouseSelectOutputPoint(quad29, ofPoint( x,  y)); }			
}
void granCieloApp::mouseReleased	(int x, int y, int button)	{
	drawNow = false;
}
void granCieloApp::resized(int w, int h){
	
}

