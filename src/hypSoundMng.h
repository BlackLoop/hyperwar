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
	void PlayWeaponsAlea();
	void Update();
private:

	std::map<std::string, ofPtr<ofSoundPlayer> > m_sound;

	std::vector<std::string> m_playlistBackground;
	int m_currentPlayBackgroundIndex;

	std::vector<std::string> m_playlistWeapons;
	int m_currentPlayWeaponsIndex;

};

typedef Singleton<hypSoundMng> hypSoundMngSingleton;
