#pragma once

#include "ofMain.h"
#include "ofApp.h"

#include "Singleton.h"

#include "ofxFlocking.h"

#include <map>
#include <string>

class hypFlockMng : public Singleton<hypFlockMng> {
public:

	hypFlockMng();
	virtual ~hypFlockMng();

	void Setup();
	void Render();

	void Update();

    ofxFlocking flock;

private:
};

typedef Singleton<hypFlockMng> hypFlockMngSingleton;
