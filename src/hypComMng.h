#pragma once

#include "ofMain.h"
#include "ofApp.h"

#include "Singleton.h"
#include "hypComThread.h"

#include <map>
#include <string>

/*
#define WAITING 0
#define INIT 1
#define RECEIVING 2
*/

class hypComMng : public Singleton<hypComMng> {

public:

	hypComMng();
	virtual ~hypComMng();

	void Setup();

	void Update();

    //ofSerial padSerial;
    //ofSerial unoSerial;

    ofVec3f GetVector();
    ofVec3f scrollSpeed;

private:
/*
    int state;
    uint8_t trame[16];
    int byteCount = 0;

    ofVec3f scrollSpeed;
    void processCoordinates();
*/

    //static
    hypComThread m_thread;
};

typedef Singleton<hypComMng> hypComMngSingleton;
