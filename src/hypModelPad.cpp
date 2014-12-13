#include "hypModelPad.h"

hypModelPad::hypModelPad()
{

}

hypModelPad::~hypModelPad()
{


}

void hypModelPad::Update()
{


}

void hypModelPad::SetValueX(float x)
{
    m_valueX = x;
}

void hypModelPad::SetValueY(float y)
{
    m_valueY = y;
}
void hypModelPad::SetValueZ(float z)
{
    m_valueZ = z;
}

ofVec3f hypModelPad::GetValueControl()
{
    return ofVec3f(m_valueX, m_valueY, m_valueZ);
}


