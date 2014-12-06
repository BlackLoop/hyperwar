
#include  "hypSoundMng.h"

using namespace std;

hypSoundMng::hypSoundMng()
{


}
hypSoundMng::~hypSoundMng()
{


}

void hypSoundMng::Setup()
{
    m_sound["fond1"] = ofPtr<ofSoundPlayer>(new ofSoundPlayer() );
	m_sound["fond1"]->loadSound("sons/C_C - Retro Action - 01 0-0-1.wav");
	m_sound["fond1"]->setVolume(1.f);
	m_sound["fond1"]->setMultiPlay(false);
	m_sound["fond1"]->setLoop(false);

    m_sound["fond2"] = ofPtr<ofSoundPlayer>(new ofSoundPlayer() );
	m_sound["fond2"]->loadSound("sons/C_C - Retro Action - 02 D-Col.wav");
	m_sound["fond2"]->setVolume(1.f);
	m_sound["fond2"]->setMultiPlay(false);
	m_sound["fond2"]->setLoop(false);

    m_sound["fond3"] = ofPtr<ofSoundPlayer>(new ofSoundPlayer() );
	m_sound["fond3"]->loadSound("sons/C_C - Retro Action - 03 0-0-7 Dub.wav");
	m_sound["fond3"]->setVolume(1.f);
	m_sound["fond3"]->setMultiPlay(false);
	m_sound["fond3"]->setLoop(false);

/*
    m_sound["fond4"] = ofPtr<ofSoundPlayer>(new ofSoundPlayer() );
	m_sound["fond4"]->loadSound("sons/C_C - Retro Action - 04 Cat Dance.wav");
	m_sound["fond4"]->setVolume(1.f);
	m_sound["fond4"]->setMultiPlay(false);
	m_sound["fond4"]->setLoop(false);

    m_sound["fond5"] = ofPtr<ofSoundPlayer>(new ofSoundPlayer() );
	m_sound["fond5"]->loadSound("sons/C_C - Retro Action - 05 So Devil.wav");
	m_sound["fond5"]->setVolume(1.f);
	m_sound["fond5"]->setMultiPlay(false);
	m_sound["fond5"]->setLoop(false);

    m_sound["fond6"] = ofPtr<ofSoundPlayer>(new ofSoundPlayer() );
	m_sound["fond6"]->loadSound("sons/C_C - Retro Action - 06 Ru-Nc-Ut.wav");
	m_sound["fond6"]->setVolume(1.f);
	m_sound["fond6"]->setMultiPlay(false);
	m_sound["fond6"]->setLoop(false);

    m_sound["fond7"] = ofPtr<ofSoundPlayer>(new ofSoundPlayer() );
	m_sound["fond7"]->loadSound("sons/C_C - Retro Action - 07 To S_3.wav");
	m_sound["fond7"]->setVolume(1.f);
	m_sound["fond7"]->setMultiPlay(false);
	m_sound["fond7"]->setLoop(false);

    m_sound["fond8"] = ofPtr<ofSoundPlayer>(new ofSoundPlayer() );
	m_sound["fond8"]->loadSound("sons/C_C - Retro Action - 08 0-0-6.wav");
	m_sound["fond8"]->setVolume(1.f);
	m_sound["fond8"]->setMultiPlay(false);
	m_sound["fond8"]->setLoop(false);

    m_sound["fond9"] = ofPtr<ofSoundPlayer>(new ofSoundPlayer() );
	m_sound["fond9"]->loadSound("sons/C_C - Retro Action - 09 NNNNN.wav");
	m_sound["fond9"]->setVolume(1.f);
	m_sound["fond9"]->setMultiPlay(false);
	m_sound["fond9"]->setLoop(false);

    m_sound["fond10"] = ofPtr<ofSoundPlayer>(new ofSoundPlayer() );
	m_sound["fond10"]->loadSound("sons/C_C - Retro Action - 10 0-0-2.wav");
	m_sound["fond10"]->setVolume(1.f);
	m_sound["fond10"]->setMultiPlay(false);
	m_sound["fond10"]->setLoop(false);
*/
	m_playlistBackground.push_back("fond1");
	m_playlistBackground.push_back("fond2");
	m_playlistBackground.push_back("fond3");
	/*
	m_playlistBackground.push_back("fond4");
	m_playlistBackground.push_back("fond5");
	m_playlistBackground.push_back("fond6");
	m_playlistBackground.push_back("fond7");
	m_playlistBackground.push_back("fond8");
	m_playlistBackground.push_back("fond9");
	m_playlistBackground.push_back("fond10");*/

    m_currentPlayBackgroundIndex = 0;
	Play(m_playlistBackground.at(m_currentPlayBackgroundIndex));
}

void hypSoundMng::Update(){
 string nameCurrent = m_playlistBackground.at(m_currentPlayBackgroundIndex);
 if(m_sound.find(nameCurrent) != m_sound.end() && !m_sound[nameCurrent]->getIsPlaying())
 {
    m_currentPlayBackgroundIndex++;
    m_currentPlayBackgroundIndex %= m_playlistBackground.size();
    cout<<"m_currentPlayBackgroundIndex="<<m_currentPlayBackgroundIndex<<endl;
    Play(m_playlistBackground.at(m_currentPlayBackgroundIndex));
 }
}

void hypSoundMng::Play(const string & name) {
	if(m_sound.find(name) != m_sound.end())
    {
        m_sound[name]->play();
    }
    else cout<<"hypSoundMng.cpp : no file with the name "<< name <<endl;
}
