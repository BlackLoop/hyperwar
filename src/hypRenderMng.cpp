#include "hypRenderMng.h"


#include "hypAssetMng.h"
#include "hypGameloop.h"

using namespace std;

hypRenderMng::hypRenderMng()
{

}

hypRenderMng::~hypRenderMng()
{

}

void hypRenderMng::Setup() {
 //hypAssetMng::Instance()->LoadAsset("test.png");

 m_hypAnimationMng.Setup();
}

void hypRenderMng::Update()
{
    m_hypAnimationMng.Update();
}

void hypRenderMng::Render()
{
    switch (hypGameloop::Instance()->GetEStage())
	{
        case EStage_STANDBY:
        {
            RenderStandby();
        }
        break;
        case EStage_PLAY:
        {
            RenderPlay();
        }
        break;
	}
}

void hypRenderMng::RenderStandby()
{

}

void hypRenderMng::RenderPlay()
{
    RenderBackground();
    m_hypAnimationMng.Render();
}

void hypRenderMng::RenderBackground()
{


}
void hypRenderMng::RenderAnimations()
{


}
