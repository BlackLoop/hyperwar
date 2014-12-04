#pragma once

#include "ofMain.h"
#include "ofApp.h"

#include "Singleton.h"

#include <map>
#include <string>

class hypAssetMng : public Singleton<hypAssetMng>
{
public:

	hypAssetMng();
	~hypAssetMng();
    ofPtr<ofImage> & LoadAsset(const std::string& sFileName);
    ofPtr<ofImage> & GetAsset(const std::string& sFileName);

private:
    std::map<std::string, ofPtr<ofImage> > m_texture;
};

typedef Singleton<hypAssetMng> hypAssetMngSingleton;
