#pragma once

#include "ofMain.h"
#include "ofApp.h"

#include "Singleton.h"
#include "hypMouse.h"
#include "hypModelPad.h";

#include <map>
#include <string>

class hypModelMng : public Singleton<hypModelMng> {
public:
    hypModelMng();
    virtual ~hypModelMng();
	void Setup();
	void Update();
	hypMouse & GetMouse() {return m_hypMouse; };
	hypModelPad & GetModelPad() {return m_hypModelPad;};
private:
    hypMouse m_hypMouse;
    hypModelPad m_hypModelPad;
};

typedef Singleton<hypModelMng> hypModelMngSingleton;
