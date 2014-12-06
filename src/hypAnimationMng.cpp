
#include "hypAnimationMng.h"
#include "hypRenderMng.h"
#include <math.h>
hypAnimationMng::hypAnimationMng()
{


}

hypAnimationMng::~hypAnimationMng()
{


}

void hypAnimationMng::Setup()
{
    /*
    old animations

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

	m_animations["bruno_partout_eau"] = ofPtr<Animation>(new Animation(ofVideoPlayer(), ofVec2f(8942.5f, 366.5f ) ) ); //old 337.5f
	m_animations["bruno_partout_eau"]->m_movie.setPixelFormat(OF_PIXELS_RGBA); //(or RGBA)
	m_animations["bruno_partout_eau"]->m_movie.loadMovie("animations/bruno_partout_eau.mov");
	m_animations["bruno_partout_eau"]->m_movie.play();
	m_animations["bruno_partout_eau"]->m_movie.setPaused(true);
	m_animations["bruno_partout_eau"]->m_movie.setLoopState(OF_LOOP_NORMAL);

    m_animations["bruno_ouonveut"] = ofPtr<Animation>(new Animation(ofVideoPlayer(), ofVec2f(12383.f, 8007.f) ) );
	m_animations["bruno_ouonveut"]->m_movie.setPixelFormat(OF_PIXELS_RGBA); //(or RGBA)
	m_animations["bruno_ouonveut"]->m_movie.loadMovie("animations/bruno_ouonveut.mov");
	m_animations["bruno_ouonveut"]->m_movie.play();
	m_animations["bruno_ouonveut"]->m_movie.setPaused(true);
	m_animations["bruno_ouonveut"]->m_movie.setLoopState(OF_LOOP_NORMAL);

    m_animations["bruno_kraken"] = ofPtr<Animation>(new Animation(ofVideoPlayer(), ofVec2f(8254.5f, 9921.f) ) );
	m_animations["bruno_kraken"]->m_movie.setPixelFormat(OF_PIXELS_RGBA); //(or RGBA)
	m_animations["bruno_kraken"]->m_movie.loadMovie("animations/bruno_kraken.mov");
	m_animations["bruno_kraken"]->m_movie.play();
	m_animations["bruno_kraken"]->m_movie.setPaused(true);
	m_animations["bruno_kraken"]->m_movie.setLoopState(OF_LOOP_NORMAL);

    m_animations["carlos_ANIM1"] = ofPtr<Animation>(new Animation(ofVideoPlayer(), ofVec2f(476.f, 5508.5f) ) );
	m_animations["carlos_ANIM1"]->m_movie.setPixelFormat(OF_PIXELS_RGBA); //(or RGBA)
	m_animations["carlos_ANIM1"]->m_movie.loadMovie("animations/carlos_ANIM1.mov");
	m_animations["carlos_ANIM1"]->m_movie.play();
	m_animations["carlos_ANIM1"]->m_movie.setPaused(true);
	m_animations["carlos_ANIM1"]->m_movie.setLoopState(OF_LOOP_NORMAL);

    m_animations["carlos_ANIM2"] = ofPtr<Animation>(new Animation(ofVideoPlayer(), ofVec2f(1869.5f, 3511.f) ) );
	m_animations["carlos_ANIM2"]->m_movie.setPixelFormat(OF_PIXELS_RGBA); //(or RGBA)
	m_animations["carlos_ANIM2"]->m_movie.loadMovie("animations/carlos_ANIM2.mov");
	m_animations["carlos_ANIM2"]->m_movie.play();
	m_animations["carlos_ANIM2"]->m_movie.setPaused(true);
	m_animations["carlos_ANIM2"]->m_movie.setLoopState(OF_LOOP_NORMAL);


    m_animations["carlos_ANIM3"] = ofPtr<Animation>(new Animation(ofVideoPlayer(), ofVec2f(3336.5f, 3005.5f) ) );
	m_animations["carlos_ANIM3"]->m_movie.setPixelFormat(OF_PIXELS_RGBA); //(or RGBA)
	m_animations["carlos_ANIM3"]->m_movie.loadMovie("animations/carlos_ANIM3.mov");
	m_animations["carlos_ANIM3"]->m_movie.play();
	m_animations["carlos_ANIM3"]->m_movie.setPaused(true);
	m_animations["carlos_ANIM3"]->m_movie.setLoopState(OF_LOOP_NORMAL);

    m_animations["hyppo_A2ANIM1"] = ofPtr<Animation>(new Animation(ofVideoPlayer(), ofVec2f(4893.5f, 7296.f), 2.f ) );
	m_animations["hyppo_A2ANIM1"]->m_movie.setPixelFormat(OF_PIXELS_RGBA); //(or RGBA)
	m_animations["hyppo_A2ANIM1"]->m_movie.loadMovie("animations/hyppo_A2ANIM_scale2.mov");
	m_animations["hyppo_A2ANIM1"]->m_movie.play();
	m_animations["hyppo_A2ANIM1"]->m_movie.setPaused(true);
	m_animations["hyppo_A2ANIM1"]->m_movie.setLoopState(OF_LOOP_NORMAL);

    m_animations["hyppo_C2ANIM1"] = ofPtr<Animation>(new Animation(ofVideoPlayer(), ofVec2f(13684.f, 7746.5f), 2.f ) );
	m_animations["hyppo_C2ANIM1"]->m_movie.setPixelFormat(OF_PIXELS_RGBA); //(or RGBA)
	m_animations["hyppo_C2ANIM1"]->m_movie.loadMovie("animations/hyppo_C2ANIM_scale2.mov");
	m_animations["hyppo_C2ANIM1"]->m_movie.play();
	m_animations["hyppo_C2ANIM1"]->m_movie.setPaused(true);
	m_animations["hyppo_C2ANIM1"]->m_movie.setLoopState(OF_LOOP_NORMAL);


    m_animations["fond_B1ANIM1"] = ofPtr<Animation>(new Animation(ofVideoPlayer(), ofVec2f(6116.5f, 905.5f) ) );
	m_animations["fond_B1ANIM1"]->m_movie.setPixelFormat(OF_PIXELS_RGBA); //(or RGBA)
	m_animations["fond_B1ANIM1"]->m_movie.loadMovie("animations/fond_B1ANIM1_v2.mov");
	m_animations["fond_B1ANIM1"]->m_movie.play();
	m_animations["fond_B1ANIM1"]->m_movie.setPaused(true);
	m_animations["fond_B1ANIM1"]->m_movie.setLoopState(OF_LOOP_NORMAL);

    m_animations["fond_B1ANIM2"] = ofPtr<Animation>(new Animation(ofVideoPlayer(), ofVec2f(7962.f, 1333.f) ) );
	m_animations["fond_B1ANIM2"]->m_movie.setPixelFormat(OF_PIXELS_RGBA); //(or RGBA)
	m_animations["fond_B1ANIM2"]->m_movie.loadMovie("animations/fond_B1ANIM2_v2.mov");
	m_animations["fond_B1ANIM2"]->m_movie.play();
	m_animations["fond_B1ANIM2"]->m_movie.setPaused(true);
	m_animations["fond_B1ANIM2"]->m_movie.setLoopState(OF_LOOP_NORMAL);

    m_animations["fond_B1ANIM3"] = ofPtr<Animation>(new Animation(ofVideoPlayer(), ofVec2f(7459.f, 2930.f) ) );
	m_animations["fond_B1ANIM3"]->m_movie.setPixelFormat(OF_PIXELS_RGBA); //(or RGBA)
	m_animations["fond_B1ANIM3"]->m_movie.loadMovie("animations/fond_B1ANIM3.mov");
	m_animations["fond_B1ANIM3"]->m_movie.play();
	m_animations["fond_B1ANIM3"]->m_movie.setPaused(true);
	m_animations["fond_B1ANIM3"]->m_movie.setLoopState(OF_LOOP_NORMAL);

    m_animations["fond_B1ANIM4"] = ofPtr<Animation>(new Animation(ofVideoPlayer(), ofVec2f(7356.f, 3694.f) ) );
	m_animations["fond_B1ANIM4"]->m_movie.setPixelFormat(OF_PIXELS_RGBA); //(or RGBA)
	m_animations["fond_B1ANIM4"]->m_movie.loadMovie("animations/fond_B1ANIM4.mov");
	m_animations["fond_B1ANIM4"]->m_movie.play();
	m_animations["fond_B1ANIM4"]->m_movie.setPaused(true);
	m_animations["fond_B1ANIM4"]->m_movie.setLoopState(OF_LOOP_NORMAL);

    m_animations["fond_B1ANIM5"] = ofPtr<Animation>(new Animation(ofVideoPlayer(), ofVec2f(6663.f, 6894.f) ) );
	m_animations["fond_B1ANIM5"]->m_movie.setPixelFormat(OF_PIXELS_RGBA); //(or RGBA)
	m_animations["fond_B1ANIM5"]->m_movie.loadMovie("animations/fond_B1ANIM5.mov");
	m_animations["fond_B1ANIM5"]->m_movie.play();
	m_animations["fond_B1ANIM5"]->m_movie.setPaused(true);
	m_animations["fond_B1ANIM5"]->m_movie.setLoopState(OF_LOOP_NORMAL);

    m_animations["fond_B1ANIM6"] = ofPtr<Animation>(new Animation(ofVideoPlayer(), ofVec2f(6658.f, 5090.f) ) );
	m_animations["fond_B1ANIM6"]->m_movie.setPixelFormat(OF_PIXELS_RGBA); //(or RGBA)
	m_animations["fond_B1ANIM6"]->m_movie.loadMovie("animations/fond_B1ANIM6.mov");
	m_animations["fond_B1ANIM6"]->m_movie.play();
	m_animations["fond_B1ANIM6"]->m_movie.setPaused(true);
	m_animations["fond_B1ANIM6"]->m_movie.setLoopState(OF_LOOP_NORMAL);

    m_animations["fond_B2ANIM1"] = ofPtr<Animation>(new Animation(ofVideoPlayer(), ofVec2f(7770.f, 5626.f) ) );
	m_animations["fond_B2ANIM1"]->m_movie.setPixelFormat(OF_PIXELS_RGBA); //(or RGBA)
	m_animations["fond_B2ANIM1"]->m_movie.loadMovie("animations/fond_B2ANIM1.mov");
	m_animations["fond_B2ANIM1"]->m_movie.play();
	m_animations["fond_B2ANIM1"]->m_movie.setPaused(true);
	m_animations["fond_B2ANIM1"]->m_movie.setLoopState(OF_LOOP_NORMAL);

    m_animations["fond_C1ANIM1"] = ofPtr<Animation>(new Animation(ofVideoPlayer(), ofVec2f(11923.5f, 3423.5f), 2.5f ) );
	m_animations["fond_C1ANIM1"]->m_movie.setPixelFormat(OF_PIXELS_RGBA); //(or RGBA)
	m_animations["fond_C1ANIM1"]->m_movie.loadMovie("animations/fond_C1ANIM_scale2p5.mov");
	m_animations["fond_C1ANIM1"]->m_movie.play();
	m_animations["fond_C1ANIM1"]->m_movie.setPaused(true);
	m_animations["fond_C1ANIM1"]->m_movie.setLoopState(OF_LOOP_NORMAL);
}

void hypAnimationMng::Render()
{
      ofSetHexColor(0xFFFFFF);
      for (std::map<std::string, ofPtr<Animation> >::iterator it=m_animations.begin(); it!=m_animations.end(); ++it)
      {
         if (it->second->m_movie.isPlaying() && !it->second->m_movie.isPaused()) it->second->Render();
      }
}

void hypAnimationMng::Update()
{
    // center of camera
    ofVec2f pos_center_cam = ofVec2f ( -hypRenderMng::m_poscamera.x + ofGetWindowWidth()*0.5f,  -hypRenderMng::m_poscamera.y + ofGetWindowHeight()*0.5f );

    //pause manager en fonction de la camera
    float distance_play_video = 1000.f;
    for (std::map<std::string, ofPtr<Animation> >::iterator it=m_animations.begin(); it!=m_animations.end(); ++it)
    {
       if ((fabs(it->second->m_pos_center.x - pos_center_cam.x) < distance_play_video) && (fabs(it->second->m_pos_center.x - pos_center_cam.x) < distance_play_video))
       {
            //PLAY
            if (it->second->m_movie.isPaused()) it->second->m_movie.setPaused(false);
       }
       else
       {
           //PAUSE
           if (!it->second->m_movie.isPaused())
           {
               it->second->m_movie.firstFrame();
               it->second->m_movie.setPaused(true);
           }
       }
    }

    //update movie
    for (std::map<std::string, ofPtr<Animation> >::iterator it=m_animations.begin(); it!=m_animations.end(); ++it)
    {
        if (it->second->m_movie.isPlaying() && !it->second->m_movie.isPaused()) it->second->m_movie.update();
    }
}

