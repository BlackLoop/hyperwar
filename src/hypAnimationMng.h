#pragma once

#include "ofMain.h"
#include "ofApp.h"

#include "Singleton.h"

#include <map>
#include <string>

class hypAnimationMng {
public:

	hypAnimationMng();
	virtual ~hypAnimationMng();

	void Setup();
	void Render();
	void Update();

private:
    struct Animation
    {
        public:
        Animation(const ofVideoPlayer & movie, const ofVec2f & poscenter, float scale = 1.f ):m_movie(movie),m_pos_center(poscenter),m_scale(scale)
        {

        }
        void  Render() {
            ofPushMatrix();
                ofTranslate( m_pos_center.x, m_pos_center.y, 0);
                //scale here
                ofScale(m_scale, m_scale);
                //translate here
                m_movie.draw(-0.5f*m_movie.getWidth(), -0.5f * m_movie.getHeight()); // move pivot to center
            ofPopMatrix();
        }
        ofVideoPlayer m_movie;
        ofVec2f m_pos_center; //pos center par defaut
        float m_scale;

    };
    std::map<std::string, ofPtr<Animation > >		m_animations;

};

