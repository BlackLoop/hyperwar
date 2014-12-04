#include "hypRenderMng.h"

#include "hypAssetMng.h"
#include "hypGameloop.h"
#include "hypFlockMng.h"

using namespace std;

hypRenderMng::hypRenderMng():m_zoom(300.f)
{

}

hypRenderMng::~hypRenderMng()
{

}

void hypRenderMng::Setup() {
 //hypAssetMng::Instance()->LoadAsset("test.png");

    ofSetWindowTitle("H.Y.P.E.R.W.A.R");
	ofSetVerticalSync(true);
	ofEnableAlphaBlending();
	ofEnableSmoothing();

 hypRenderMng::LoadbackgroundImages("background");

 hypFlockMng::Instance()->Setup();

 //hypRenderMng::warcam = new ofCamera();

}

void hypRenderMng::Update()
{
 hypFlockMng::Instance()->Update();
}

void hypRenderMng::Render()
{
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
    ofClear(0, 0, 0, 0);
	//ofEnableLighting();

    ofPushMatrix();
    ofTranslate( m_mouseX ,m_mouseY, m_zoom);
    RenderBackground();
    ofPopMatrix();
}

void hypRenderMng::RenderBackground()
{
     int X_TILES_NB = 8;
     int Y_TILES_NB = 8;
     int TILE_WIDTH = 1920;
     int TILE_HEIGHT = 1360;

    ofTranslate( -3*TILE_WIDTH/2, -2*TILE_HEIGHT/2 );
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

