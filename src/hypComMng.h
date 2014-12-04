#pragma once

#include "ofMain.h"
#include "ofApp.h"

#include "Singleton.h"

#include <map>
#include <string>

#define WAITING 0
#define INIT 1
#define RECEIVING 2

class hypComMng : public Singleton<hypComMng> {

public:

	hypComMng();
	virtual ~hypComMng();

	void Setup();

	void Update();


private:

    ofSerial padSerial;
    ofSerial unoSerial;
    int state;
    uint8_t trame[16];
    int byteCount = 0;

    void processCoordinates();

};

typedef Singleton<hypComMng> hypComMngSingleton;
