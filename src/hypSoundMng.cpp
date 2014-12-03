
#include  "hypSoundMng.h"

using namespace std;

hypSoundMng::hypSoundMng()
{


}
hypSoundMng::~hypSoundMng()
{


}

void hypSoundMng::Setup()
{/*
    m_sound["test"] = ofPtr<ofSoundPlayer>(new ofSoundPlayer() );
	m_sound["test"]->loadSound("sons/test.wav");
	m_sound["test"]->setVolume(1.f);
	m_sound["test"]->setMultiPlay(true);
	*/
}

void hypSoundMng::Play(const string & name) {
	if(m_sound.find(name) != m_sound.end())
    {
        m_sound[name]->play();
    }
    else cout<<"hypSoundMng.cpp : no file with the name "<< name <<endl;
}
