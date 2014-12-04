#pragma once

#include "ofMain.h"
#include "ofApp.h"

#include "Singleton.h"

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

private:
	void RenderBackground();
	void RenderAnimations();
    void RenderFlock();

    void LoadbackgroundImages(string dirName);
    void LoadSequencesImages(string dirName);

    std::vector< ofImage > m_backgroundImages;
};

typedef Singleton<hypRenderMng> hypRenderMngSingleton;
