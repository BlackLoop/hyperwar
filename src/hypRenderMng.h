#pragma once

#include "ofMain.h"
#include "ofApp.h"

#include "Singleton.h"
#include "hypAnimationMng.h"
#include "hypGamePad.h"

#include <map>
#include <string>

class hypRenderMng : public Singleton<hypRenderMng> {
public:

	hypRenderMng();
	virtual ~hypRenderMng();

	void Setup();
	void Render();
	void RenderStandby();
	void RenderPlay();

	void Update();

    int m_mouseX;
    int m_mouseY;

    float Constrain(float amt, float low, float high);

    float m_zoom;
    //ofVec3f absPosition;
    //ofVec3f relPosition;

/*
    void        setPosX( float );
    void        setPosY( float );
    void        setPosZ( float );
*/

    ofVec3f moveMouse();
    ofVec3f moveKbd();
    ofVec3f move3DPad();
    ofVec3f moveEase( ofVec3f toEase, float factXY, float factZ, float delta);

private:
	void RenderBackground();

	hypAnimationMng m_hypAnimationMng;
	void RenderAnimations();
    void RenderFlock();

    void LoadbackgroundImages(string dirName);
    void LoadSequencesImages(string dirName);

    std::vector< ofImage > m_backgroundImages;
    hypGamePad m_hypGamePad;
    std::list <ofVec3f> padVals;
};

typedef Singleton<hypRenderMng> hypRenderMngSingleton;
