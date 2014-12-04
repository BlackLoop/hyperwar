#pragma once


#include "Singleton.h"
#include <iostream>

    enum EStage {
        EStage_UNDEFINED,
        EStage_STANDBY,
        EStage_PLAY
    };

class hypGameloop : public Singleton<hypGameloop> {
public:

	EStage GetEStage(){
        return m_eStage;
	}
	hypGameloop();
	virtual ~hypGameloop();
	void Setup();
	void Update();

private:
	EStage m_eStage;

};

typedef Singleton<hypGameloop> hypGameloopSingleton;
