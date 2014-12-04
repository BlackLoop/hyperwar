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
	cout << "AXIS " << e.axis << " VALUE " << ofToString(e.value) << endl;
}

void hypGamePad::buttonPressed(ofxGamepadButtonEvent& e)
{
	cout << "BUTTON " << e.button << " PRESSED" << endl;
}

void hypGamePad::buttonReleased(ofxGamepadButtonEvent& e)
{
	cout << "BUTTON " << e.button << " RELEASED" << endl;
}
