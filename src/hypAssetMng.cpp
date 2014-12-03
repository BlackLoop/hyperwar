
#include "hypAssetMng.h"


using namespace std;

hypAssetMng::hypAssetMng()
{

}

hypAssetMng::~hypAssetMng()
{


}

// charge l'asset image � partir du disque
ofPtr<ofImage> & hypAssetMng::LoadAsset(const string& sFileName)
{
    ofPtr<ofImage> retNULL;
	if(sFileName != "")
	{
		try {
			m_texture[sFileName] = ofPtr<ofImage>(new ofImage());
			m_texture[sFileName]->loadImage(sFileName);
		}
		catch( ... ) {
			cout<<"AssetManager.cpp : unable to load the texture file " + sFileName + " !";
			return retNULL;
		}
	}
	else return retNULL;
	return m_texture[sFileName];
}

// renvoie la texture pr�cedemment charg�e
ofPtr<ofImage> & hypAssetMng::GetAsset(const string& sFileName)
{
	if (m_texture.find(sFileName) == m_texture.end()) LoadAsset(sFileName);
	return m_texture[sFileName];
}



