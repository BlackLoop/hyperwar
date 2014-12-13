
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

    struct Axis
    {
        int m_id;
        float m_value;
    };
    ofEvent<Axis> onAxisChanged;

    ofEvent<void> onButtonPressed0;
    ofEvent<void> onButtonPressed1;
    ofEvent<void> onButtonPressed2;
    ofEvent<void> onButtonPressed3;
    ofEvent<void> onButtonPressed4;
    ofEvent<void> onButtonPressed5;
    ofEvent<void> onButtonPressed6;
};


