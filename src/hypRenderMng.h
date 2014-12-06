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
    static ofVec2f m_poscamera;

    float Constrain(float amt, float low, float high);

    float m_zoom;


private:
	void RenderBackground();
    void RenderOverlay();
	hypAnimationMng m_hypAnimationMng;
	void RenderAnimations();
    void RenderFlock();

    void LoadbackgroundImages(string dirName);
    void LoadSequencesImages(string dirName);

    std::vector< ofImage > m_backgroundImages;
    hypGamePad m_hypGamePad;
};

typedef Singleton<hypRenderMng> hypRenderMngSingleton;
