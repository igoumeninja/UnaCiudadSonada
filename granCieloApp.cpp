#include "granCieloApp.h"
#include "ofxSketch.h"

void granCieloApp::setup(){
	{
		//	FBO
		fbo0 = fbo1 = fbo2 = fbo3 = fbo4 = fbo5 = false;
		alphaFBO2 = 0;
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
		r7 = g7 = b8 = 0;
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
		
	//	Effects
	Effect.setup();
	//	LSystem
	LSystem.setup();	
	
	
	//##############################################
	//
	//                  Deseo
	//
	//
	deseo = "Quierro hacer la oscuridad luz";
	//
	//
	//
	//##############################################

	//	FBO	
	{
		doRender = true;

		rm0.allocateForNScreens(1, 320, 280); //the first dedicate the screens
		rm0.loadFromXml("fboSettings0.xml");
		quad0  = ofRectangle(1600,400,200,200);
		rm1.allocateForNScreens(1, 500,333); //the first dedicate the screensf
		rm1.loadFromXml("fboSettings1.xml");
		quad1  = ofRectangle(1600,400,200,200);
		rm2.allocateForNScreens(1, 322,422); //the first dedicate the screens
		rm2.loadFromXml("fboSettings2.xml");
		quad2  = ofRectangle(1600,400,200,200);
		rm3.allocateForNScreens(1, 320,280); //the first dedicate the screens the other 2 are the dimension of the image or of the video
		rm3.loadFromXml("fboSettings3.xml");
		quad3  = ofRectangle(1600,400,200,200);
		rm4.allocateForNScreens(1, 400, 396); //the first dedicate the screens the other 2 are the dimension of the image or of the video
		rm4.loadFromXml("fboSettings4.xml");
		quad4  = ofRectangle(1600, 400, 200, 200);		
		rm5.allocateForNScreens(1, 320, 280); //the first dedicate the screens the other 2 are the dimension of the image or of the video
		rm5.loadFromXml("fboSettings5.xml");
		quad5  = ofRectangle(1600, 400, 200, 200);
		rm6.allocateForNScreens(1, 500, 500); //the first dedicate the screens the other 2 are the dimension of the image or of the video
		rm6.loadFromXml("fboSettings6.xml");
		quad6  = ofRectangle(1600,400, 200, 200);

		//Imagenes
		tejados.loadImage("images/tejados500x333.png");
		charco.loadImage("images/charco262x338.png");
		ventanaRoja.loadImage("images/ventanaRoja322x422.png");	
		reloj.loadImage("images/reloj404x396.png");			
		textura.loadImage("images/aqua500x500.jpg");					

		//Video
		ciudaddestruidaconlluvia.loadMovie("videos/ciudaddestruidaconlluvia.avi");		
		illusion.loadMovie("videos/illusion320x280.mov");
		ormigas.loadMovie("videos/ormigas.mov");		
	}
	
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
	
}
void granCieloApp::update(){

	if	(circleView)	{
		for (int i = 0; i < 10; i++){
			circle[i].update();
		}
	}
	
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
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); // GL_SRC_ALPHA_SATURATE,GL_ONE     GL_SRC_ALPHA, GL_ONE
				ofFill();
				strPosX = ofRandom(0, ofGetWidth());
				strPosY = ofRandom(0, ofGetHeight());
				ofSetColor(255,255,255,255);	// even
				ofPushMatrix();
				ofTranslate(strPosX, strPosY, 0);
				testFontSmall.drawString(deseo,0, 0);		
				ofPopMatrix();
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
			if ( m.getAddress() == "/scopeView" )	{
				ofFill();
				ofSetColor(0xFFFFFF);
				//fibonacciDisplay.draw(0,0);			
			}
		}	//	draw Images
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
	}	
}
void granCieloApp::draw(){
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
				if ( doRender ) {		
					rm0.startOffscreenDraw();
						ciudaddestruidaconlluvia.idleMovie();
						ofSetColor(0xFFFFFF);
						ciudaddestruidaconlluvia.draw(0,0, 320,280);
					rm0.endOffscreenDraw();
				}
				rm0.drawOutputDiagnostically(quad0.x, quad0.y, quad0.width, quad0.height);	
			}
		}	//	FBO 0 catastrofe
		{
			if ( fbo1) {
				if ( doRender ) {		
					rm1.startOffscreenDraw();
						ofFill();
						ofSetColor(0xFFFFFF);
						tejados.draw(0,0);						
					rm1.endOffscreenDraw();
				}
				rm1.drawOutputDiagnostically(quad1.x, quad1.y, quad1.width, quad1.height);	
			}
		}	//	FBO 1 desagua
		{
			if ( fbo2 )	{
				if ( doRender ) {		
					rm2.startOffscreenDraw();
						if ( ofGetFrameNum() % 10 == 0)	{
							alphaFBO2 ++;
						}
						ofFill();
						ofSetColor(255,255,255,alphaFBO2);												
						ventanaRoja.draw(0,0);						
					rm2.endOffscreenDraw();
				} 
				rm2.drawOutputDiagnostically(quad2.x, quad2.y, quad2.width, quad2.height);	
			}			
		}	//	FBO 2 ventana rota
		{
			if ( fbo3 )	{
				if ( doRender ) {		
					rm3.startOffscreenDraw();
						illusion.idleMovie();
						ofSetColor(0xFFFFFF);
						illusion.draw(0,0, 320,280);
					rm3.endOffscreenDraw();
				}
				rm3.drawOutputDiagnostically(quad3.x, quad3.y, quad3.width, quad3.height);	
			}
		}	//	FBO 3 illusion
		{
			if ( fbo4 )	{
				if ( doRender ) {		
					rm4.startOffscreenDraw();
						ofFill();
						ofSetColor(0xFFFFFF);
						reloj.draw(0,0);						
					rm4.endOffscreenDraw();
				}
				rm4.drawOutputDiagnostically(quad4.x, quad4.y, quad4.width, quad4.height);	
			}
		}	//	FBO 4 reloj
		{
			if ( fbo5 )	{
				if ( doRender ) {		
					rm5.startOffscreenDraw();
						ormigas.idleMovie();
						ofSetColor(0xFFFFFF);
						ormigas.draw(0,0, 320,280);
					rm5.endOffscreenDraw();
				}
				rm5.drawOutputDiagnostically(quad5.x, quad5.y, quad5.width, quad5.height);	
			}
		}	//	FBO 5 ormigas
		{
			if ( fbo6 )	{
				if ( doRender ) {		
					rm6.startOffscreenDraw();
						ofFill();
						ofSetColor(0xFFFFFF);
						textura.draw(0,0);						
					rm6.endOffscreenDraw();
				}
				rm6.drawOutputDiagnostically(quad6.x, quad6.y, quad6.width, quad6.height);	
			}
		}	//	FBO 6 textura
	}	//	adding to FBO
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
		//texScreen.loadScreenData(0,0,1600, 1200);			
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
			//texScreen.draw(0,0,ofGetWidth(), ofGetHeight());
			texScreen.draw(0,0,3840, 1024);			
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

	if	(key == 'm')	{	ofHideCursor();	}
	if	(key == 'M')	{	ofShowCursor();	}
	if	(key == 'x')	{	bSnapshot = true;	}
    if ( key == 'g')	{	toggleImage = !toggleImage;    }	
	
    if( key == 's'){
	
		if ( fbo0 ) {    rm0.saveToXml(); }
		if ( fbo1 ) {    rm1.saveToXml(); }
		if ( fbo2 ) {    rm2.saveToXml(); }
		if ( fbo3 ) {    rm3.saveToXml(); }
		if ( fbo4 ) {    rm4.saveToXml(); }
		if ( fbo5 ) {    rm5.saveToXml(); }
		if ( fbo6 ) {    rm6.saveToXml(); }

//		rm0.saveToXml();
//		rm1.saveToXml();
//		rm2.saveToXml();
//		rm3.saveToXml();
//		rm4.saveToXml();		
//		rm5.saveToXml();				
//		rm6.saveToXml();				
    }	
    if( key == 'r' ){
		if ( fbo0 ) { rm0.reloadFromXml(); }
		if ( fbo1 ) { rm1.reloadFromXml(); }
		if ( fbo2 ) { rm2.reloadFromXml(); }
		if ( fbo3 ) { rm3.reloadFromXml(); }
		if ( fbo4 ) { rm4.reloadFromXml(); }
		if ( fbo5 ) { rm5.reloadFromXml(); }								
		if ( fbo6 ) { rm6.reloadFromXml(); }										
		
//        rm0.reloadFromXml();
//        rm1.reloadFromXml();		
//        rm2.reloadFromXml();				
//        rm3.reloadFromXml();				
//        rm4.reloadFromXml();						
//        rm5.reloadFromXml();								
//        rm6.reloadFromXml();										
	}	
    if(key == 'c'){
		if ( fbo0 ) { rm0.resetCoordinates(); }
		if ( fbo1 ) { rm1.resetCoordinates(); }
		if ( fbo2 ) { rm2.resetCoordinates(); }
		if ( fbo3 ) { rm3.resetCoordinates(); }
		if ( fbo4 ) { rm4.resetCoordinates(); }
		if ( fbo5 ) { rm5.resetCoordinates(); }									
		if ( fbo6 ) { rm6.resetCoordinates(); }
		
//        rm0.resetCoordinates();
//        rm1.resetCoordinates();		
//		rm2.resetCoordinates();		
//		rm3.resetCoordinates();				
//		rm4.resetCoordinates();						
//		rm5.resetCoordinates();								
//		rm6.resetCoordinates();										
    }	
    if(key == 't'){
        doRender = !doRender;
    }
    if(key == 'n'){
		if ( fbo0 ) { rm0.viewControlPoints = 1; }
		if ( fbo1 ) { rm1.viewControlPoints = 1; }
		if ( fbo2 ) { rm2.viewControlPoints = 1; }
		if ( fbo3 ) { rm3.viewControlPoints = 1; }
		if ( fbo4 ) { rm4.viewControlPoints = 1; }
		if ( fbo5 ) { rm5.viewControlPoints = 1; }
		if ( fbo6 ) { rm6.viewControlPoints = 1; }
													
//		rm0.viewControlPoints = 1;
//		rm1.viewControlPoints = 1;
//		rm2.viewControlPoints = 1;
//		rm3.viewControlPoints = 1;				
//		rm4.viewControlPoints = 1;						
//		rm5.viewControlPoints = 1;								
//		rm6.viewControlPoints = 1;										
    }
    if(key == 'N'){
		if ( fbo0 ) { rm0.viewControlPoints = 0; }
		if ( fbo1 ) { rm1.viewControlPoints = 0; }
		if ( fbo2 ) { rm2.viewControlPoints = 0; }
		if ( fbo3 ) { rm3.viewControlPoints = 0; }
		if ( fbo4 ) { rm4.viewControlPoints = 0; }
		if ( fbo5 ) { rm5.viewControlPoints = 0; }
		if ( fbo6 ) { rm6.viewControlPoints = 0; }
													
//		rm0.viewControlPoints = 0;
//		rm1.viewControlPoints = 0;
//		rm2.viewControlPoints = 0;
//		rm3.viewControlPoints = 0;				
//		rm4.viewControlPoints = 0;						
//		rm5.viewControlPoints = 0;								
//		rm6.viewControlPoints = 0;										
    }

	if (key == 'a'){
		arbolView = true;	
	}
	if (key == 'A'){
		arbolView = false;	
	}
	
	if(key == 'f' or key == 'F'){
		full = !full;
		if(full){
			ofSetFullscreen(true);
		} else {
			ofSetFullscreen(false);
		}
	}		
//	if(key == '5' or key == '%'){
//		ofBackground(255, 255, 255);
//	}	
	if(key == 'b' or key == 'B'){
		ofBackground(0,0,0);
	}	
//	if(key == '5' or key == '%'){
//		LSystem.setup();
//	}	
	
//	switch(key) {
//		case '1':
//			th1 = sth1 = ofRandom(0, 2*PI);
//			break;
//		case '2':
//			th2 = sth2 = ofRandom(0, 2*PI);
//			break;
//		case '3':
//			cx1 = scx1 = ofRandom(ofGetWidth()/2 - r*cos(th1), ofGetWidth()/2 + r*cos(th1));
//			cy1 = scy1 = ofRandom(ofGetHeight()/2 - r*sin(th1), ofGetHeight()/2 + r*sin(th1));
//			break;
//
//	}
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
							
//	rm0.mouseDragOutputPoint(quad0, ofPoint( x, y));
//	rm1.mouseDragOutputPoint(quad1, ofPoint( x, y));
//	rm2.mouseDragOutputPoint(quad2, ofPoint( x, y));	
//	rm3.mouseDragOutputPoint(quad3, ofPoint( x, y));		
//	rm4.mouseDragOutputPoint(quad4, ofPoint( x, y));		
//	rm5.mouseDragOutputPoint(quad5, ofPoint( x, y));			
//	rm6.mouseDragOutputPoint(quad6, ofPoint( x, y));				
}
void granCieloApp::mousePressed	(int x, int y, int button)	{
	//	system("say hello");
	drawNow = true;	
	if ( fbo0 ) { rm0.mouseSelectOutputPoint(quad0, ofPoint( x,  y)); }
	if ( fbo1 ) { rm1.mouseSelectOutputPoint(quad1, ofPoint( x,  y)); }
	if ( fbo2 ) { rm2.mouseSelectOutputPoint(quad2, ofPoint( x,  y)); }
	if ( fbo3 ) { rm3.mouseSelectOutputPoint(quad3, ofPoint( x,  y)); }
	if ( fbo4 ) { rm4.mouseSelectOutputPoint(quad4, ofPoint( x,  y)); }
	if ( fbo5 ) { rm5.mouseSelectOutputPoint(quad5, ofPoint( x,  y)); }
	if ( fbo6 ) { rm6.mouseSelectOutputPoint(quad6, ofPoint( x,  y)); }
							
//	rm0.mouseSelectOutputPoint(quad0, ofPoint( x,  y));
//	rm1.mouseSelectOutputPoint(quad1, ofPoint( x,  y));
//	rm2.mouseSelectOutputPoint(quad2, ofPoint( x,  y));		
//	rm3.mouseSelectOutputPoint(quad3, ofPoint( x,  y));						
//	rm4.mouseSelectOutputPoint(quad4, ofPoint( x,  y));							
//	rm5.mouseSelectOutputPoint(quad5, ofPoint( x,  y));								
//	rm6.mouseSelectOutputPoint(quad6, ofPoint( x,  y));									
}
void granCieloApp::mouseReleased	(int x, int y, int button)	{
	drawNow = false;
}
void granCieloApp::resized(int w, int h){
	
}

