#include "hypGameloop.h"
#include  "hypSoundMng.h"

hypGameloop::hypGameloop()
{

}

hypGameloop::~hypGameloop()
{

}

void hypGameloop::Setup()
{
	hypSoundMngSingleton::Instance()->Setup();

	m_eStage = EStage_STANDBY;
}
/*
hypGameloop::EStage hypGameloop::GetEStage()
{ 
    return m_eStage;
}
*/
void hypGameloop::Update()
{
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
