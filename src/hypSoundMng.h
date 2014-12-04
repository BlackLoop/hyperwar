#pragma once

#include "ofMain.h"
#include "ofApp.h"

#include "Singleton.h"

#include <map>
#include <string>

class hypSoundMng : public Singleton<hypSoundMng> {
public:
    hypSoundMng();
    virtual ~hypSoundMng();
	void Setup();
	void Play(const std::string & name);
	void Update();
private:

	std::map<std::string, ofPtr<ofSoundPlayer> > m_sound;

	std::vector<std::string> m_playlistBackground;
	int m_currentPlayBackgroundIndex;
};

typedef Singleton<hypSoundMng> hypSoundMngSingleton;
