
#pragma once

#include "ofMain.h"
#include "ofApp.h"


#include <map>
#include <string>

class hypModelPad {
public:
    hypModelPad();
    ~hypModelPad();
	void Update();
	void SetValueX(float x);
    void SetValueY(float y);
    void SetValueZ(float z);
    ofVec3f GetValueControl();
private:
    float m_valueX ;
    float m_valueY ;
    float m_valueZ ;
};


