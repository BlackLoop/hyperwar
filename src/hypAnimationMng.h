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
         m_movie.draw(m_pos.x, m_pos.y);
        }
        ofVideoPlayer m_movie;
        ofVec2f m_pos;
    };
    std::map<std::string, ofPtr<Animation > >		m_animations;

};

