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

    ofSetWindowTitle("H.Y.P.E.R.W.A.R");
	ofSetVerticalSync(true);
	ofEnableAlphaBlending();
 	ofEnableSmoothing();
    ofSetFullscreen(true);

	LoadbackgroundImages("background");
	LoadCreaturesImages("creature300");
    LoadBloodImages("blood");
    hypAssetMng::Instance()->LoadAsset("bombs.png");

	hypFlockMng::Instance()->Setup();

	hypAssetMng::Instance()->LoadAsset("jumelles.png");

    mTimeline = ofxCinderTimeline::Timeline::create();
    mTimeline->stepTo(ofGetElapsedTimef());

    m_displayBinocular = true;

}

void hypRenderMng::Update()
{
    m_hypAnimationMng.Update();
 	hypFlockMng::Instance()->Update();
 	mTimeline->stepTo(ofGetElapsedTimef());
}

void hypRenderMng::Render()
{
    ofClear(255, 255, 255, 255);


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
    ofVec3f padControl = hypModelMngSingleton::Instance()->GetModelPad().GetValueControl();
    ofVec3f control = ofVec3f(padControl.x, -padControl.y, padControl.z);
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
    const int OVER_Z = 1000; //75;
    const int IDEAL_Z = 300; // 300

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
        RenderCreatures();
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

void hypRenderMng::LoadbackgroundImages(const string & dirName)
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

void hypRenderMng::LoadCreaturesImages(const string & dirName)
{
    ofDirectory dir;

    int nFiles = dir.listDir( dirName );
    dir.sort();

    if(nFiles) {
        for(int i=0; i<dir.numFiles(); i++) {
            string filePath = dir.getPath(i);
            m_CreaturesImages.push_back(ImagePos(hypAssetMngSingleton::Instance()->LoadAsset(filePath), ofVec2f(ofRandom(0.f, BACKGROUND_SIZE_X),ofRandom(0.f, BACKGROUND_SIZE_Y))));
            //m_CreaturesImages.back().m_imagePtr->setImageType(OF_IMAGE_GRAYSCALE);
            cout << "loaded" << filePath << '\n';
        }
    }
    else printf("Could not find folder for creature\n");
}

void hypRenderMng::LoadBloodImages(const string & dirName)
{
    ofDirectory dir;

    int nFiles = dir.listDir( dirName );
    dir.sort();

    if(nFiles) {
        for(int i=0; i<dir.numFiles(); i++) {
            string filePath = dir.getPath(i);
            m_bloodImages.push_back(hypAssetMngSingleton::Instance()->LoadAsset(filePath));
            cout << "loaded" << filePath << '\n';
        }
    }
    else printf("Could not find folder for creature\n");
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

    RenderBlood();
    RenderBomb();

    if(m_displayBinocular)
    {
        ofSetColor(255,255,255,255);
        hypAssetMng::Instance()->GetAsset("jumelles.png")->draw(0,0,ofGetWindowWidth(), ofGetWindowHeight());
    }
}

void hypRenderMng::RenderCreatures()
{
    ofSetColor(255,255,255,255);
   for ( vector< ImagePos >::iterator iter = m_CreaturesImages.begin() ; iter != m_CreaturesImages.end() ; ++iter)
   {
        if(iter->m_imagePtr) iter->m_imagePtr->draw(iter->m_pos);
   }
}


//BLOOD
void hypRenderMng::InitBloodAnim()
{
   // m_alphaBlood.stop();
    timeline().apply(&m_alphaBlood, 150.f, 0.5f, ofxCinderTimeline::EaseOutCubic());
    timeline().appendTo(&m_alphaBlood, 150.f, 0.5f);
    timeline().appendTo(&m_alphaBlood, 0.f, 0.5f, ofxCinderTimeline::EaseOutCubic());
    m_BloodImageIndex++;
    m_BloodImageIndex %= m_bloodImages.size();
}

void hypRenderMng::RenderBlood()
{
     if (m_alphaBlood.value() == 0.f && !m_bloodImages.at(m_BloodImageIndex)) return;

    ofSetColor(255,255,255,m_alphaBlood.value());
    ofPushMatrix();
    ofTranslate( ofGetWindowWidth()*0.5f, ofGetWindowHeight()*0.5f);
    //scale here
    //translate here
    m_bloodImages.at(m_BloodImageIndex)->draw(-0.5f * m_bloodImages.at(m_BloodImageIndex)->getWidth(), -0.5f * m_bloodImages.at(m_BloodImageIndex)->getHeight() ); // move pivot to center
    ofPopMatrix();
}

// BOMB
void hypRenderMng::InitBombAnim()
{
    //m_alphaBomb.stop();
    timeline().apply(&m_alphaBomb, 255.f, 1.0f, ofxCinderTimeline::EaseOutCubic());
    timeline().appendTo(&m_alphaBomb, 255.f, 1.f);
    timeline().appendTo(&m_alphaBomb, 0.f, 1.0f, ofxCinderTimeline::EaseOutCubic());
}

void hypRenderMng::RenderBomb()
{
    if (m_alphaBomb.value() == 0.f ) return;
    ofSetColor(255,255,255,m_alphaBomb.value());
    hypAssetMng::Instance()->GetAsset("bombs.png")->draw(0,0,ofGetWindowWidth(), ofGetWindowHeight());
}
