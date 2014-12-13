#pragma once

#include "ofMain.h"
#include "ofApp.h"

#include "Singleton.h"
#include "hypMouse.h"

#include <map>
#include <string>

class hypModelMng : public Singleton<hypModelMng> {
public:
    hypModelMng();
    virtual ~hypModelMng();
	void Setup();
	void Update();
	hypMouse & GetMouse() {return m_hypMouse; };
private:
    hypMouse m_hypMouse;
};

typedef Singleton<hypModelMng> hypModelMngSingleton;
