#pragma once

#include "ofMain.h"
#include "ofApp.h"
#include "ofxCinderTimeline.h"

#include "Singleton.h"
#include "hypAnimationMng.h"


#include <map>
#include <string>
//m_zoom(300.f)
class hypRenderMng : public Singleton<hypRenderMng>
{
public:
	hypRenderMng()
    {

    }
	~hypRenderMng()
	{

	}

	void Setup();
	void Render();
	void RenderStandby();
	void RenderPlay();

	void Update();


    static ofVec2f m_poscamera;

    float Constrain(float amt, float low, float high);

    float m_zoom;
    //ofVec3f absPosition;
    //ofVec3f relPosition;

/*
    void        setPosX( float );
    void        setPosY( float );
    void        setPosZ( float );
*/

/*
    ofVec3f moveMouse();
    ofVec3f moveKbd();
    ofVec3f move3DPad();
    ofVec3f moveEase( ofVec3f toEase, float factXY, float factZ, float delta);
    */
    ofxCinderTimeline::Timeline& timeline() { return *mTimeline; }
    void InitBloodAnim();
    void InitBombAnim();
    bool m_displayBinocular;
private:

	void RenderBackground();
    void RenderOverlay();
    void RenderCreatures();
	hypAnimationMng m_hypAnimationMng;
	void RenderAnimations();
    void RenderFlock();
    void RenderBlood();
    void RenderBomb();

    ofxCinderTimeline::Anim<float> m_alphaBomb;
    ofxCinderTimeline::Anim<float> m_alphaBlood;

    void LoadbackgroundImages(const string & dirName);
    void LoadCreaturesImages(const std::string & dirName);
    void LoadBloodImages(const string & dirName);
    std::vector< ofImage > m_backgroundImages;

    struct ImagePos
    {
        public:
        ImagePos(const ofPtr < ofImage > & img, const ofVec2f & pos ):
            m_imagePtr(img),
            m_pos(pos) {}
        ofPtr < ofImage > m_imagePtr;
        ofVec2f m_pos;
    };

    std::vector< ImagePos > m_CreaturesImages;

    std::vector< ofPtr < ofImage > > m_bloodImages;
    int m_BloodImageIndex = 0;
    std::list <ofVec3f> padVals;

    std::shared_ptr<ofxCinderTimeline::Timeline> mTimeline;
};

typedef Singleton<hypRenderMng> hypRenderMngSingleton;
