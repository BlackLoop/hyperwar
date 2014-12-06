#include "hypRenderMng.h"
#include "hypAssetMng.h"
#include "hypGameloop.h"
#include "hypFlockMng.h"

using namespace std;

ofVec2f hypRenderMng::m_poscamera = ofVec2f();


hypRenderMng::hypRenderMng():m_zoom(300.f)
{

}

hypRenderMng::~hypRenderMng()
{

}

void hypRenderMng::Setup() {
 //hypAssetMng::Instance()->LoadAsset("test.png");

 m_hypAnimationMng.Setup();
 m_hypGamePad.setup();
 //hypAssetMng::Instance()->LoadAsset("test.png");

    ofSetWindowTitle("H.Y.P.E.R.W.A.R");
	ofSetVerticalSync(true);
	ofEnableAlphaBlending();
 	ofEnableSmoothing();
    ofSetFullscreen(true);

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
    ofClear(0, 0, 0, 0);


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

	//ofEnableLighting();

    static float s_fLastMouseX = 0.f;
    static float s_fLastMouseY = 0.f;

	float fCenterX =  ofGetWindowWidth() / 2.f; //1024.f / 2.0f;
	float fCenterY = ofGetWindowHeight() / 2.f ; //768.f / 2.0f;

    float fMouseFromCenterX =  m_mouseX - fCenterX;
    float fMouseFromCenterY =  m_mouseY - fCenterY;

    float fMouseXNorm = (2.f*fMouseFromCenterX) / ofGetWindowWidth() ; //1024.f;
    float fMouseYNorm = (2.f*fMouseFromCenterY) / ofGetWindowHeight(); //768.f;

    float I_BKGND_WIDTH  = 8.f*1920.f;
    float I_BKGND_HEIGHT = 8.f*1360.f;

    float fOverflowX = 8.f*1920.f;// - 1024;
    float fOverflowY = 8.f*1360.f;// - 768;

    static float s_fCurrentX = -fOverflowX/2.f;
	static float s_fCurrentY = -fOverflowY/2.f;

    static float s_fTargetX = 0.f;
    static float s_fTargetY = 0.f;

    if (m_mouseX != s_fLastMouseX || m_mouseY != s_fLastMouseY) {
        s_fTargetX = -fOverflowX/2.f + fMouseXNorm * I_BKGND_WIDTH/2.0f;
        s_fTargetY = -fOverflowY/2.f + fMouseYNorm * I_BKGND_HEIGHT/2.0f;
    }

    RenderOverlay();
    ofPushMatrix();
        ofVec2f vDist(s_fTargetX - s_fCurrentX,
                      s_fTargetX - s_fCurrentY);

        float factorSpeed = 10.f;
        if (vDist.length() > 1.f) {

            if (s_fCurrentX < s_fTargetX) {
                s_fCurrentX += -factorSpeed;
            }
            else {
                s_fCurrentX += factorSpeed;
            }

            if (s_fCurrentY < s_fTargetY) {
                s_fCurrentY += -factorSpeed;
            }
            else {
                s_fCurrentY += factorSpeed;
            }

        }
        //cout<<"s_fCurrentX"<<s_fCurrentX<<", "<<"s_fCurrentY" << s_fCurrentY<<endl;
        s_fCurrentX = ofClamp(s_fCurrentX, -1.f * I_BKGND_WIDTH + 1920, -12.f);
        s_fCurrentY = ofClamp(s_fCurrentY, -1.f * I_BKGND_HEIGHT + 1360, -12.f);

        m_poscamera = ofVec2f(s_fCurrentX, s_fCurrentY);
        ofTranslate(s_fCurrentX,
                    s_fCurrentY,
                    -100.0f);

        RenderBackground();
        RenderAnimations();
    ofPopMatrix();
    RenderOverlay();

    s_fLastMouseX = m_mouseX;
    s_fLastMouseY = m_mouseY;
}

void hypRenderMng::RenderBackground()
{
     int X_TILES_NB = 8;
     int Y_TILES_NB = 8;
     int TILE_WIDTH = 1920;
     int TILE_HEIGHT = 1360;

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


void hypRenderMng::RenderOverlay()
{
    hypAssetMng::Instance()->GetAsset("jumelles.png")->draw(0,0,ofGetWindowWidth(), ofGetWindowHeight());

}
