#include "hypMouse.h"

hypMouse::hypMouse():
    m_mouseX(0.f),
    m_mouseY(0.f),
    m_fLastMouseX(0.f),
    m_fLastMouseY(0.f)
{


}
hypMouse::~hypMouse()
{


}

void hypMouse::Update()
{
    m_fLastMouseX = m_mouseX;
    m_fLastMouseY = m_mouseY;
}

void hypMouse::SetMouse(int x , int y)
{
    m_mouseX = static_cast<float>(x);
    m_mouseY = static_cast<float>(y);
}

ofVec2f hypMouse::GetMouseControl()
{
    float mouseMapX = ofMap(m_mouseX, 0.f, ofGetWindowWidth(), -1.f,1.f );
    float mouseMapY = ofMap(m_mouseY, 0.f, ofGetWindowHeight(), -1.f,1.f );
    return ofVec2f(mouseMapX, mouseMapY);
}

