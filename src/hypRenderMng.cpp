#include "hypRenderMng.h"
#include "hypAssetMng.h"
#include "hypGameloop.h"
#include "hypComMng.h"
#include "hypFlockMng.h"
#include "hypModelMng.h"
#include "settings.h"

using namespace std;

//extern ofVec2f  globalScroll;
//extern double   globalZoom;

//hypRenderMng::hypRenderMng():m_zoom(300.f)
//{
//, absPosition(ofVec3f(BACKGROUND_SIZE_X/2, BACKGROUND_SIZE_Y/2, 100))
//}


ofVec2f hypRenderMng::m_poscamera = ofVec2f();


void hypRenderMng::Setup() {

    m_hypAnimationMng.Setup();
    m_hypGamePad.setup();

    ofSetWindowTitle("H.Y.P.E.R.W.A.R");
	ofSetVerticalSync(true);
	ofEnableAlphaBlending();
 	ofEnableSmoothing();
    //ofSetFullscreen(true);

	hypRenderMng::LoadbackgroundImages("background");

	hypFlockMng::Instance()->Setup();

	hypAssetMng::Instance()->LoadAsset("jumelles.png");

}

void hypRenderMng::Update()
{
    m_hypAnimationMng.Update();
 	hypFlockMng::Instance()->Update();
}

void hypRenderMng::Render()
{
    ofClear(1, 1, 1, 0);


    switch (hypGameloop::Instance()->GetEStage())
	{
        case EStage_STANDBY:
        {
            RenderStandby();
        }
        break;
        case EStage_PLAY:
        {
            RenderPlay();
        }
        break;
	}

#ifdef _DEBUG
	m_hypGamePad.draw();
#endif
}

void hypRenderMng::RenderStandby()
{

}

void hypRenderMng::RenderPlay()
{
    #ifdef USE3DPAD
    ofVec3f control = hypComMngSingleton::Instance()->GetVector();
    //cout<<"x= "<<pad.x<<", y= "<<pad.y<<", z= "<<pad.z<<endl;
    #endif
    #ifdef USEMOUSE
    ofVec2f mouseControl = hypModelMngSingleton::Instance()->GetMouse().GetMouseControl();
    ofVec3f control = ofVec3f(mouseControl.x, -mouseControl.y, 0.f);
    //cout<<"control x="<<control.x<<" y="<<control.y<<endl;
    #endif
    #ifdef USEGAMEPAD

    #endif

    padVals.push_back(control);

    // lissage du pad
    ofVec3f moy = ofVec3f(0,0,0);
    if(padVals.size() > 8) {
        padVals.pop_front();
    }
    for( std::list<ofVec3f>::iterator it=padVals.begin(); it != padVals.end(); ++it) {
            moy += *it;
    }
    moy = moy / (float)padVals.size();

    s_fCurrentX -= moy.x * 20.;
    s_fCurrentY += moy.y * 20.;
    //s_fCurrentZ += pad.z * 10.;
    s_zoom -= (moy.z -.5f) * 15.;

    const int OVER = 300;
    const int OVER_Z = 1100; //75;
    const int IDEAL_Z = 1100; // 300

    s_fCurrentX = ofClamp(s_fCurrentX, -BACKGROUND_SIZE_X  + 1920, OVER);
    s_fCurrentY = ofClamp(s_fCurrentY, -BACKGROUND_SIZE_Y  + 1360 - 200, OVER);
   // s_zoom      = ofClamp(s_zoom,      -IDEAL_Z - OVER_Z,          IDEAL_Z + OVER_Z);
    s_zoom      = ofClamp(s_zoom,      -IDEAL_Z - OVER_Z,          -IDEAL_Z);// + OVER_Z);

   m_poscamera = ofVec2f(s_fCurrentX, s_fCurrentY);

   ofPushMatrix();
        ofTranslate(s_fCurrentX,
                    s_fCurrentY,
                    s_zoom);
        RenderBackground();
        RenderAnimations();
    ofPopMatrix();
    RenderOverlay();

    hypModelMngSingleton::Instance()->GetMouse().Update();

}

void hypRenderMng::RenderBackground()
{

    ofPushMatrix();
    //ofTranslate( -3*TILE_WIDTH/2, -2*TILE_HEIGHT/2 );
    for(int j=0; j < Y_TILES_NB; j++) {
        for(int i=0; i < X_TILES_NB; i++) {
            int x = TILE_WIDTH  * i;
            int y = TILE_HEIGHT * j;
            ofSetColor(255, 255);
            m_backgroundImages[ i + j * (X_TILES_NB ) ].draw( x, y);
        }
    }
    ofPopMatrix();
}

void hypRenderMng::RenderAnimations()
{
    m_hypAnimationMng.Render();
}

void hypRenderMng::RenderFlock()
{
    hypFlockMng::Instance()->Render();
}

void hypRenderMng::LoadbackgroundImages(string dirName)
{
    ofDirectory dir;

    int nFiles = dir.listDir( dirName );
    dir.sort();

    if(nFiles) {
        for(int i=0; i<dir.numFiles(); i++) {
            string filePath = dir.getPath(i);
            m_backgroundImages.push_back(ofImage());
            m_backgroundImages.back().loadImage(filePath); // TODO: switch to loadasset... pb with point image
            //backgroundImages.back() = hypAssetMng::Instance()->LoadAsset(filePath);
            m_backgroundImages.back().setImageType(OF_IMAGE_GRAYSCALE);
            cout << "loaded" << filePath << '\n';
        }
    }
    else printf("Could not find folder for background\n");
}

void hypRenderMng::LoadSequencesImages(string dirName)
{

}
/*
// MOTION DEVICES
// MOUSE
ofVec3f hypRenderMng::moveMouse()
{
    // Mouse


	float fCenterX = 1024.f / 2.0f;
	float fCenterY = 768.f / 2.0f;

    float fMouseFromCenterX =  s_mouseX - fCenterX;
    float fMouseFromCenterY =  s_mouseY - fCenterY;

    float fMouseXNorm = (2.f*fMouseFromCenterX) / 1024.f;
    float fMouseYNorm = (2.f*fMouseFromCenterY) / 768.f;

    if (s_mouseX != s_fLastMouseX || s_mouseY != s_fLastMouseY) {
        s_fTargetX = -fOverflowX/2.f + fMouseXNorm * I_BKGND_WIDTH/2.0f;
        s_fTargetY = -fOverflowY/2.f + fMouseYNorm * I_BKGND_HEIGHT/2.0f;
    }

    return ofVec3f( s_fTargetX, s_fTargetY, 0);
}

// KEYBOARD
ofVec3f hypRenderMng::moveKbd()
{
    // Zoom (from keyboard)
	const float ZOOM_EASING = 5.0f;
    if(s_zoom < m_zoom) { s_zoom += ZOOM_EASING; cout << s_zoom<<" s_zoom\n";}
    if(s_zoom > m_zoom) { s_zoom -= ZOOM_EASING; cout << s_zoom<<" s_zoom\n";}
    return ofVec3f( 0, 0, s_zoom);
}

ofVec3f hypRenderMng::move3DPad() {

}

// EASING FUNCTION
ofVec3f hypRenderMng::moveEase( ofVec3f toEase, float factZ, float factXY, float delta)
{
    ofVec2f vDist(s_fTargetX - s_fCurrentX,
                  s_fTargetX - s_fCurrentY);
//    ofVec2f vDist( toEase, curPos);

    if (vDist.length() > delta) {

        if (s_fCurrentX < s_fTargetX) {
            s_fCurrentX += delta;
        }
        else {
            s_fCurrentX += -delta;
        }

        if (s_fCurrentY < s_fTargetY) {
            s_fCurrentY += delta;
        }
        else {
            s_fCurrentY += -delta;
        }
    }

    return ofVec3f(s_fCurrentX, s_fCurrentY);
}
*/

void hypRenderMng::RenderOverlay()
{
    hypAssetMng::Instance()->GetAsset("jumelles.png")->draw(0,0,ofGetWindowWidth(), ofGetWindowHeight());

}
