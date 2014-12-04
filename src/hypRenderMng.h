#pragma once

#include "ofMain.h"
#include "ofApp.h"

#include "Singleton.h"
#include "hypAnimationMng.h"

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

private:
	void RenderBackground();
	void RenderAnimations();

	hypAnimationMng m_hypAnimationMng;
};

typedef Singleton<hypRenderMng> hypRenderMngSingleton;
