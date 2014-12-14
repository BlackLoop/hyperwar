#include "hypGameloop.h"
#include "hypSoundMng.h"
#include "hypModelMng.h"
#include "hypRenderMng.h"

hypGameloop::hypGameloop() :
    	m_eStage(EStage_PLAY)
{

}

hypGameloop::~hypGameloop()
{

}

void hypGameloop::Setup()
{
	hypSoundMngSingleton::Instance()->Setup();
	m_hypGamePad.setup();
	ofAddListener(m_hypGamePad.onAxisChanged, this, &hypGameloop::onAxisChanged);
	ofAddListener(m_hypGamePad.onButtonPressed0, this, &hypGameloop::onScenario0);
	ofAddListener(m_hypGamePad.onButtonPressed1, this, &hypGameloop::onScenario1);
	ofAddListener(m_hypGamePad.onButtonPressed2, this, &hypGameloop::onScenario2);
	ofAddListener(m_hypGamePad.onButtonPressed3, this, &hypGameloop::onScenario3);
	ofAddListener(m_hypGamePad.onButtonPressed4, this, &hypGameloop::onScenario4);
	ofAddListener(m_hypGamePad.onButtonPressed5, this, &hypGameloop::onScenario5);
	ofAddListener(m_hypGamePad.onButtonPressed6, this, &hypGameloop::onScenario6);
}
/*
hypGameloop::EStage hypGameloop::GetEStage()
{ 
    return m_eStage;
}
*/
void hypGameloop::Update()
{
    hypSoundMng::Instance()->Update();
	switch (m_eStage)
	{
		case EStage_STANDBY:
		{

		}
		break;
		case EStage_PLAY:
		{

		}
		break;
	}
}
void hypGameloop::onAxisChanged(hypGamePad::Axis & axis)
{
    if(axis.m_id == 0)  hypModelMngSingleton::Instance()->GetModelPad().SetValueX(axis.m_value); // entre -1 et 1
    else if(axis.m_id == 1)  hypModelMngSingleton::Instance()->GetModelPad().SetValueY(axis.m_value); // entre -1 et 1
    else if(axis.m_id == 3)  hypModelMngSingleton::Instance()->GetModelPad().SetValueZ(axis.m_value); // entre -1 et 1
}
void hypGameloop::onScenario0()
{
    cout<<"onScenario0()"<<endl;
    hypSoundMngSingleton::Instance()->PlayWeaponsAlea();
}

void hypGameloop::onScenario1()
{
    cout<<"onScenario1()"<<endl;
    hypRenderMngSingleton::Instance()->InitBombAnim();
    hypSoundMngSingleton::Instance()->Play("bomb");
}

void hypGameloop::onScenario2()
{
    cout<<"onScenario2()"<<endl;
    hypSoundMngSingleton::Instance()->PlayWeaponsAlea();
}

void hypGameloop::onScenario3()
{
    cout<<"onScenario3()"<<endl;
    hypSoundMngSingleton::Instance()->PlayWeaponsAlea();
    hypRenderMngSingleton::Instance()->InitBloodAnim();
}

void hypGameloop::onScenario4()
{
    cout<<"onScenario4()"<<endl;
    hypSoundMngSingleton::Instance()->PlayNextBackroundPlaylist();
}

void hypGameloop::onScenario5()
{
    cout<<"onScenario5()"<<endl;
    hypRenderMngSingleton::Instance()->m_displayBinocular = !hypRenderMngSingleton::Instance()->m_displayBinocular;
    hypSoundMngSingleton::Instance()->PlayWeaponsAlea();
}

void hypGameloop::onScenario6()
{
    cout<<"onScenario6()"<<endl;
    hypSoundMngSingleton::Instance()->Play("siren");
    hypSoundMngSingleton::Instance()->PlayWeaponsAlea();
}

