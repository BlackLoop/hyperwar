
#pragma once

#include "ofMain.h"
#include "ofApp.h"


#include <map>
#include <string>

class hypMouse {
public:
    hypMouse();
    ~hypMouse();
	void Update();
	void SetMouse(int x , int y);
    float GetMouseX() { cout<<"m_mouseX="<<m_mouseX<<endl; return m_mouseX ; };
    float GetMouseY() { cout<<"m_mouseY"<<m_mouseY<<endl; return m_mouseY ; };
    float GetLastMouseX() { return m_fLastMouseX ; };
    float GetLastMouseY() { return m_fLastMouseY ; };
    ofVec2f GetMouseControl();
private:
    float m_mouseX ;
    float m_mouseY ;
    float m_fLastMouseX ;
    float m_fLastMouseY ;
};

