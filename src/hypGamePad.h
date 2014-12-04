
#pragma once

#include "ofMain.h"
#include "ofxGamepadHandler.h"

class hypGamePad {
public:
    hypGamePad();
    ~hypGamePad();
    void setup();
    void update();
    void draw();
    void axisChanged(ofxGamepadAxisEvent& e);
    void buttonPressed(ofxGamepadButtonEvent& e);
    void buttonReleased(ofxGamepadButtonEvent& e);
};


