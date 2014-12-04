#include "hypGameloop.h"
#include  "hypSoundMng.h"

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
