//#ifndef _TEST_APP
//#define _TEST_APP


#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxDirList.h"
#include "ofxVectorMath.h"
#include "ofxNetwork.h"
#include "ofxOsc.h"
#include "ofxThread.h"
#include "ofxXmlSettings.h"
#include "ofx3DModelLoader.h"

//includes:
#include "ofxSketch.h"
#include "ofxSuperformula.h"
//#include "ofxSeashell.h"
#include "ofCircles.h"
#include "ofxArbol.h"

#include "renderManager.h"
#include "ofFBOTexture.h"
#include "ofxLSystem.h"
#include "ofxEffects.h"


#define MAX_SKETCHES		2048
#define MAX_CIRCLES			1024

#define PORTlisten			12345
#define NUM_MSG_STRINGS		20


class granCieloApp : public ofBaseApp{

	public:
	
		void	setup();
		void	update();
		void	draw();
	
		void	keyPressed  (int key);
		void	keyReleased	(int key);
		void	mouseMoved	(int x, int y );
		void	mouseDragged(int x, int y, int button);
		void	mousePressed(int x, int y, int button);
		void	mouseReleased(int x, int y, int button);
		void	resized		(int w, int h);		
		
		void	beatStrPrint(string beatStr);						
		void	fillBackground();
		void	circleStudies();
		void	playWithComplex();	
		void	feedbackStudies();	
		void	maskStudies();			
		void	syncStudies();
		void	takePictures();

        ofxCvGrayscaleImage		cvGray;
        ofxDirList				dirList;
        ofxVec2f				p;
        ofxTCPClient			client;
        ofxTCPServer			server;
        ofxOscSender			osc_sender;
        ofxThread				thread;
        ofxXmlSettings			settings;
        ofx3DModelLoader		modelLoader;
		
		ofxSketch				sketch[MAX_SKETCHES];
		ofxSuperformula			superformula;		
		//ofxSeashell			seashell;	
		
		//	Effects
		ofxEffects				Effect;
		//	LSystems	
		ofxLSystem				LSystem;
		string	lsystemString;
		int		lsystemGeneration;
		
		//#############	FBO  ########################
	renderManager rm0, rm1, rm2, rm3, rm4, rm5, rm6, rm7, rm8, rm9;
	renderManager rm10, rm11, rm12, rm13, rm14, rm15, rm16, rm17, rm18, rm19;		
	renderManager rm20, rm21, rm22, rm23, rm24, rm25, rm26, rm27, rm28, rm29;		
	ofRectangle quad0, quad1, quad2, quad3, quad4, quad5, quad6, quad7, quad8, quad9;		
	ofRectangle quad10, quad11, quad12, quad13, quad14, quad15, quad16, quad17, quad18, quad19;				
	ofRectangle quad20, quad21, quad22, quad23, quad24, quad25, quad26, quad27, quad28, quad29;				

	ofImage		charco, tejados, ventanaRoja, reloj, textura, tejadosInvierno, montanas, bosque, muroCasaAlta, tejadoCasaAlta;
	ofImage		muroCasaDerecha, tejadosCasaDerecha, ventanaRota, flores, raton, ladrillo, mariposa, arbols, chimanea, burbujas;
	ofImage		montanasBlancas, montanasRojas, casaRedondeada, campanario, casaDerecha, casaAqua, gotas, flore;
	ofImage		muroCasaIzquierda, tejadosCasaIzquierda, tejadoCasaDerechaNueva, muroCasaDerechaNueva, rosa, jasmin, bar, ojo;
	ofImage	barNuevo, casaXBar, tokyo, valencia, azucar, columna,paris, trullo, indio, ultima, tribunal;
	

		ofVideoPlayer 		ciudadDestruida, ciudaddestruidaconlluvia, illusion, ormigas, floresVideo, chanTiChan, pero, hormigas;

		bool defaultFBO;
		bool toggleImage, doRender;
		bool frameByframe;
		bool fbo0, fbo1, fbo2, fbo3, fbo4, fbo5, fbo6, fbo7, fbo8, fbo9;
		bool fbo10, fbo11, fbo12, fbo13, fbo14, fbo15, fbo16, fbo17, fbo18, fbo19;		
		bool fbo20, fbo21, fbo22, fbo23, fbo24, fbo25, fbo26, fbo27, fbo28, fbo29;	
		bool viewFlores2, viewFlores6, viewFlores21, viewFlores23, viewFlores13, viewFlores14, viewFlores10;
		bool viewRaton4, viewRaton20, viewRaton22, viewLadrillo4, viewLadrillo20, viewLadrillo22;
		bool viewCiudadDestruidaConLluvia,viewCiudadDestruida, viewChanTiChan, viewSoloChanTiChan;
		bool viewChimanea, viewVentanaRota, viewMontanas, viewMontanasBlancas, viewMontanasRojas;
		bool viewSketchCasas, viewMuroCasaDerecha, viewtejadosCasaDerecha, viewMuroCasaIzquierda, viewTejadoCasaIzquierda;
		bool viewCasaGrande, viewCampanario, viewCasaDerecha, viewCasaAqua, viewGotas, viewCasasNegras;
		bool viewCasaDerechaNueva, viewJasmin, viewPero, viewBar, viewOjo, viewBarNuevoTRUE, viewBarNuevoFALSE;
		bool viewCasaXBar, viewBarNuevo, viewHormigas;
	bool viewTokyo, viewValencia, viewUltima, viewLineaAmarilla, viewTribunal;
		int  alphaFBO2, afbo6, afbo7, afbo8, afbo123, afbo15_17, afbo21_23;
		
		float xSolo, ySolo, xLineaAmarilla, yLineaAmarilla;
		
		
		//############  Deseo   ###################
		string deseo, deseo1, deseo2, deseo3, deseo4, deseo5;
		
		//##########	Beat  #################
		ofTrueTypeFont testFont, testFontSmall, deseosFont, deseosFontSmall;
		string str,beatStr;
		int	beat, beatsView;
		int strPosX, strPosY;

		//arbol
		ofxArbol				arbol;
		bool	arbolView;
		float	aa, ab, h, turn;
		
		//	Feedback
		ofTexture		texScreen, texScreen2;
		float 			feedbackSpeedX,	feedbackSpeedY;
		int				feedbackView, timeLine, viewRotate, view_fillBackground;
		
		//	Circle
		ofCircles				circle[MAX_CIRCLES];				
		float		circleView, viewSeashell,viewSuperformula;
		float		theta, tangentI, tangentII;
		float		x1, x2, cx1, cx2;
		float		y1, y2, cy1, cy2;
		float		r, th1, th2, th3;
		float		sx1, sx2, scx1, scx2;
		float		sy1, sy2, scy1, scy2;
		float		sr, sth1, sth2, sth3;

		//Seashell		
		float seashellR, seashellN, seashellH, seashellP, seashellL, seashellK, seashellDu, seashellDv, seashellType, seashellScale, seashellSteps;

		//Superformula
		float sformM, sformn1, sformn2, sformn3, sformStep, sformScale, sformNum, sformType;

		//from GUI
		float			numMouseSketches, numSoundSketches, mouseLines, soundLines, viewSoundChanels;
		float			minSoundElasticity, maxSoundElasticity, minSoundDamping, maxSoundDamping;
		float			minMouseElasticity, maxMouseElasticity, minMouseDamping, maxMouseDamping;

//		for ImageCapture		
		int				snapCounter, full;
		char 			snapString[255];
		ofImage 		img;
		bool 			bSnapshot;		
		float 			phase;

//		myThing
		float			Yamp0, Yamp1, Yamp2, Yamp3, Yamp4, Yamp5, Yamp6, Yamp7;
		float			Xfreq0, Xfreq1, Xfreq2, Xfreq3, Xfreq4, Xfreq5, Xfreq6,Xfreq7;
		bool			bSmooth;
		float			ampIn,ampOut, freqIn, freqOut;
		float			ampChan0, ampChan1, ampChan2, ampChan3;		
		float			freqChan0, freqChan1, freqChan2, freqChan3;				
		float			ampInLow,ampOutLow, ampInHigh, ampOutHigh;
		float			freqInLow, freqOutLow,  freqInHigh, freqOutHigh;

		bool			drawNow, drawWithMouse, rotate, viewCamera, viewBlob, viewDiff;
		int				midi1, midi2, midi3, midi4, midi5, midi6, midi7, midi8;
		int				midi65, midi66, midi67, midi68, midi69;
		int				midi70, midi71, midi72, midi73, midi74, midi75, midi76, midi77, midi78, midi79;
		int				midi80, midi81, midi82, midi83, midi84, midi85, midi86, midi87, midi88, midi89;
		int				midi90, midi91, midi92, midi93, midi94, midi95, midi96, midi97, midi98, midi99;
		int				midi100, midi101, midi102, midi103, midi104;
		int				r1, r2, r3, r4, r5, r6, r7, r8;
		int				g1, g2, g3, g4, g5, g6, g7, g8;
		int				b1, b2, b3, b4, b5, b6, b7, b8;				
		int				a1, a2, a3, a4, a5, a6, a7, a8;		
		
//		background
		float			fillRate;
		
private:
		ofxOscReceiver	receiver;
		int				current_msg_string;
		string			msg_strings[NUM_MSG_STRINGS];
		float			timers[NUM_MSG_STRINGS];
		
};

//#endif
