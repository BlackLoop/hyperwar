#include "hypGamePad.h"


hypGamePad::hypGamePad()
{


}

hypGamePad::~hypGamePad()
{


}

void hypGamePad::setup(){

	ofxGamepadHandler::get()->enableHotplug();

	//CHECK IF THERE EVEN IS A GAMEPAD CONNECTED
	if(ofxGamepadHandler::get()->getNumPads()>0){
			ofxGamepad* pad = ofxGamepadHandler::get()->getGamepad(0);
			ofAddListener(pad->onAxisChanged, this, &hypGamePad::axisChanged);
			ofAddListener(pad->onButtonPressed, this, &hypGamePad::buttonPressed);
			ofAddListener(pad->onButtonReleased, this, &hypGamePad::buttonReleased);
	}
}

void hypGamePad::update(){

}


void hypGamePad::draw(){
ofxGamepadHandler::get()->draw(10,10);
}
void hypGamePad::axisChanged(ofxGamepadAxisEvent& e)
{
	//cout << "AXIS " << e.axis << " VALUE " << ofToString(e.value) << endl;
    Axis axis;
    axis.m_id = e.axis;
    axis.m_value = e.value;
    ofNotifyEvent(onAxisChanged, axis);
}

void hypGamePad::buttonPressed(ofxGamepadButtonEvent& e)
{
	//cout << "BUTTON " << e.button << " PRESSED" << endl;

    switch(e.button)
    {
        case 0:
            ofNotifyEvent(onButtonPressed0);
        break;
        case 1:
            ofNotifyEvent(onButtonPressed1);
        break;
        case 2:
            ofNotifyEvent(onButtonPressed2);
        break;
        case 3:
            ofNotifyEvent(onButtonPressed3);
        break;
        case 4:
            ofNotifyEvent(onButtonPressed4);
        break;
        case 5:
            ofNotifyEvent(onButtonPressed5);
        break;
        case 6:
            ofNotifyEvent(onButtonPressed6);
        break;
    }

}

void hypGamePad::buttonReleased(ofxGamepadButtonEvent& e)
{
	//cout << "BUTTON " << e.button << " RELEASED" << endl;
}
