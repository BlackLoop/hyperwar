
#include "hypAnimationMng.h"


hypAnimationMng::hypAnimationMng()
{


}

hypAnimationMng::~hypAnimationMng()
{


}

void hypAnimationMng::Setup()
{
    /*
	m_animations["test1"] = ofPtr<Animation>(new Animation(ofVideoPlayer(), ofVec2f(206.f, 4856.f) ) );
	m_animations["test1"]->m_movie.setPixelFormat(OF_PIXELS_RGBA); //(or RGBA)
	m_animations["test1"]->m_movie.loadMovie("animations/carlos_anim_1.mov");
	m_animations["test1"]->m_movie.play();
	m_animations["test1"]->m_movie.setLoopState(OF_LOOP_NORMAL);

	m_animations["test2"] = ofPtr<Animation>(new Animation(ofVideoPlayer(), ofVec2f(1653.f, 3267.f) ) );
	m_animations["test2"]->m_movie.setPixelFormat(OF_PIXELS_RGBA); //(or RGBA)
	m_animations["test2"]->m_movie.loadMovie("animations/carlos_anim_2.mov");
	m_animations["test2"]->m_movie.play();
	m_animations["test2"]->m_movie.setLoopState(OF_LOOP_NORMAL);

    m_animations["test3"] = ofPtr<Animation>(new Animation(ofVideoPlayer(), ofVec2f(2838.f, 2433.f) ) );
	m_animations["test3"]->m_movie.setPixelFormat(OF_PIXELS_RGBA); //(or RGBA)
	m_animations["test3"]->m_movie.loadMovie("animations/carlos_anim_3.mov");
	m_animations["test3"]->m_movie.play();
	m_animations["test3"]->m_movie.setLoopState(OF_LOOP_NORMAL);
	*/

}

void hypAnimationMng::Render()
{
      ofSetHexColor(0xFFFFFF);
      for (std::map<std::string, ofPtr<Animation> >::iterator it=m_animations.begin(); it!=m_animations.end(); ++it)
      {
         if (it->second->m_movie.isPlaying()) it->second->Render();
      }
}

void hypAnimationMng::Update()
{
      for (std::map<std::string, ofPtr<Animation> >::iterator it=m_animations.begin(); it!=m_animations.end(); ++it)
      {
         if (it->second->m_movie.isPlaying()) it->second->m_movie.update();
      }
}

