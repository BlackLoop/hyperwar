
#include  "hypSoundMng.h"
#include <algorithm>    // std::random_shuffle

using namespace std;

hypSoundMng::hypSoundMng()
{


}
hypSoundMng::~hypSoundMng()
{


}

// random generator function:
int myrandom (int i) {
    return std::rand()%i;
}

void hypSoundMng::Setup()
{
    m_sound["fond1"] = ofPtr<ofSoundPlayer>(new ofSoundPlayer() );
	m_sound["fond1"]->loadSound("sons/C_C - Retro Action - 01 0-0-1.wav", true);
	m_sound["fond1"]->setVolume(1.f);
	m_sound["fond1"]->setMultiPlay(false);
	m_sound["fond1"]->setLoop(false);

    m_sound["fond2"] = ofPtr<ofSoundPlayer>(new ofSoundPlayer() );
	m_sound["fond2"]->loadSound("sons/C_C - Retro Action - 02 D-Col.wav", true);
	m_sound["fond2"]->setVolume(1.f);
	m_sound["fond2"]->setMultiPlay(false);
	m_sound["fond2"]->setLoop(false);

    m_sound["fond3"] = ofPtr<ofSoundPlayer>(new ofSoundPlayer() );
	m_sound["fond3"]->loadSound("sons/C_C - Retro Action - 03 0-0-7 Dub.wav", true);
	m_sound["fond3"]->setVolume(1.f);
	m_sound["fond3"]->setMultiPlay(false);
	m_sound["fond3"]->setLoop(false);

    m_sound["fond4"] = ofPtr<ofSoundPlayer>(new ofSoundPlayer() );
	m_sound["fond4"]->loadSound("sons/C_C - Retro Action - 04 Cat Dance.wav", true);
	m_sound["fond4"]->setVolume(1.f);
	m_sound["fond4"]->setMultiPlay(false);
	m_sound["fond4"]->setLoop(false);

    m_sound["fond5"] = ofPtr<ofSoundPlayer>(new ofSoundPlayer() );
	m_sound["fond5"]->loadSound("sons/C_C - Retro Action - 05 So Devil.wav", true);
	m_sound["fond5"]->setVolume(1.f);
	m_sound["fond5"]->setMultiPlay(false);
	m_sound["fond5"]->setLoop(false);

    m_sound["fond6"] = ofPtr<ofSoundPlayer>(new ofSoundPlayer() );
	m_sound["fond6"]->loadSound("sons/C_C - Retro Action - 06 Ru-Nc-Ut.wav", true);
	m_sound["fond6"]->setVolume(1.f);
	m_sound["fond6"]->setMultiPlay(false);
	m_sound["fond6"]->setLoop(false);

    m_sound["fond7"] = ofPtr<ofSoundPlayer>(new ofSoundPlayer() );
	m_sound["fond7"]->loadSound("sons/C_C - Retro Action - 07 To S_3.wav", true);
	m_sound["fond7"]->setVolume(1.f);
	m_sound["fond7"]->setMultiPlay(false);
	m_sound["fond7"]->setLoop(false);

    m_sound["fond8"] = ofPtr<ofSoundPlayer>(new ofSoundPlayer() );
	m_sound["fond8"]->loadSound("sons/C_C - Retro Action - 08 0-0-6.wav", true);
	m_sound["fond8"]->setVolume(1.f);
	m_sound["fond8"]->setMultiPlay(false);
	m_sound["fond8"]->setLoop(false);

    m_sound["fond9"] = ofPtr<ofSoundPlayer>(new ofSoundPlayer() );
	m_sound["fond9"]->loadSound("sons/C_C - Retro Action - 09 NNNNN.wav", true);
	m_sound["fond9"]->setVolume(1.f);
	m_sound["fond9"]->setMultiPlay(false);
	m_sound["fond9"]->setLoop(false);

    m_sound["fond10"] = ofPtr<ofSoundPlayer>(new ofSoundPlayer() );
	m_sound["fond10"]->loadSound("sons/C_C - Retro Action - 10 0-0-2.wav", true);
	m_sound["fond10"]->setVolume(1.f);
	m_sound["fond10"]->setMultiPlay(false);
	m_sound["fond10"]->setLoop(false);

    m_sound["fond"] = ofPtr<ofSoundPlayer>(new ofSoundPlayer() );
	m_sound["fond"]->loadSound("sons/hyperwar_2.2.24bit.wav", true);
	m_sound["fond"]->setVolume(1.f);
	m_sound["fond"]->setMultiPlay(false);
	m_sound["fond"]->setLoop(false);



	m_playlistBackground.push_back("fond1");
	m_playlistBackground.push_back("fond2");
	m_playlistBackground.push_back("fond3");
	m_playlistBackground.push_back("fond4");
	m_playlistBackground.push_back("fond5");
	m_playlistBackground.push_back("fond6");
	m_playlistBackground.push_back("fond7");
	m_playlistBackground.push_back("fond8");
	m_playlistBackground.push_back("fond9");
	m_playlistBackground.push_back("fond10");
    m_playlistBackground.push_back("fond");


	//WEAPONS
    ofDirectory dirWeapons;
    int nFilesweapons = dirWeapons.listDir("sons//weapons");
    dirWeapons.sort();
    if(nFilesweapons) {
        for(int i=0; i<dirWeapons.numFiles(); i++) {
            string filePath = dirWeapons.getPath(i);
            m_sound[filePath] = ofPtr<ofSoundPlayer>(new ofSoundPlayer() );
            m_sound[filePath]->loadSound(filePath, true);
            m_sound[filePath]->setVolume(0.5f);
            m_sound[filePath]->setMultiPlay(false);
            m_sound[filePath]->setLoop(false);
            m_playlistWeapons.push_back(filePath);
        }
    }
    cout<<"m_playlistWeapons.size()"<<m_playlistWeapons.size()<<endl;
    m_currentPlayWeaponsIndex = 0;

    //ARCHIVES
    ofDirectory dirArchives;
    int nFilesarchives = dirArchives.listDir("sons//archives");
    dirArchives.sort();
    if(nFilesarchives) {
        for(int i=0; i<dirArchives.numFiles(); i++) {
            string filePath = dirArchives.getPath(i);
            m_sound[filePath] = ofPtr<ofSoundPlayer>(new ofSoundPlayer() );
            m_sound[filePath]->loadSound(filePath, true);
            m_sound[filePath]->setVolume(1.f);
            m_sound[filePath]->setMultiPlay(false);
            m_sound[filePath]->setLoop(false);

            m_playlistBackground.push_back(filePath);

            cout<<"filePath="<<filePath<<endl;

        }
    }
    std::random_shuffle ( m_playlistBackground.begin(), m_playlistBackground.end(), myrandom);
    m_currentPlayBackgroundIndex = 0;
	Play(m_playlistBackground.at(m_currentPlayBackgroundIndex));

    m_sound["bomb"] = ofPtr<ofSoundPlayer>(new ofSoundPlayer() );
	m_sound["bomb"]->loadSound("sons/Atomic_Bomb-Sound_Explorer-897730679.wav", true);
	m_sound["bomb"]->setVolume(1.f);
	m_sound["bomb"]->setMultiPlay(false);
	m_sound["bomb"]->setLoop(false);

    m_sound["siren"] = ofPtr<ofSoundPlayer>(new ofSoundPlayer() );
	m_sound["siren"]->loadSound("sons/Tornado Siren-SoundBible.com-897026957.wav", true);
	m_sound["siren"]->setVolume(1.f);
	m_sound["siren"]->setMultiPlay(false);
	m_sound["siren"]->setLoop(false);
}

void hypSoundMng::Update(){
 string nameCurrent = m_playlistBackground.at(m_currentPlayBackgroundIndex);
 if(m_sound.find(nameCurrent) != m_sound.end() && !m_sound[nameCurrent]->getIsPlaying())
 {
    m_currentPlayBackgroundIndex++;
    m_currentPlayBackgroundIndex %= m_playlistBackground.size();
    //cout<<"m_currentPlayBackgroundIndex="<<m_currentPlayBackgroundIndex<<endl;
    Play(m_playlistBackground.at(m_currentPlayBackgroundIndex));
 }
}

void hypSoundMng::PlayNextBackroundPlaylist()
{
     string nameCurrent = m_playlistBackground.at(m_currentPlayBackgroundIndex);
     if(m_sound.find(nameCurrent) != m_sound.end() && m_sound[nameCurrent]->getIsPlaying())
     {
        m_sound[nameCurrent]->stop();
        m_currentPlayBackgroundIndex++;
        m_currentPlayBackgroundIndex %= m_playlistBackground.size();
        //cout<<"m_currentPlayBackgroundIndex="<<m_currentPlayBackgroundIndex<<endl;
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

void hypSoundMng::PlayWeaponsAlea() {
    if (m_playlistWeapons.size() == 0) return;
    string name = m_playlistWeapons.at(m_currentPlayWeaponsIndex);
    m_currentPlayWeaponsIndex++;
    m_currentPlayWeaponsIndex %= m_playlistWeapons.size();
	if(m_sound.find(name) != m_sound.end())
    {
        m_sound[name]->play();
    }
    else cout<<"hypSoundMng.cpp : no file with the name "<< name <<endl;
}
