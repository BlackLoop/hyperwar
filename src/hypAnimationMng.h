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
        Animation(const ofVideoPlayer & movie, const ofVec2f & pos ):m_movie(movie),m_pos(pos)
        {

        }
        void  Render() {
            ofPushMatrix();
                ofTranslate( m_pos.x, m_pos.y, 0);
                //scale here
                //translate here
                m_movie.draw(-0.5f*m_movie.getWidth(), -0.5f * m_movie.getHeight()); // move pivot to centre
            ofPopMatrix();
        }
        ofVideoPlayer m_movie;
        ofVec2f m_pos; //pos center par defaut

    };
    std::map<std::string, ofPtr<Animation > >		m_animations;

};

