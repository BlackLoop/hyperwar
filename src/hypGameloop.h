#pragma once

#include "hypGamePad.h"
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
    void onAxisChanged(hypGamePad::Axis & axis);
    void onScenario0();
    void onScenario1();
    void onScenario2();
    void onScenario3();
    void onScenario4();
    void onScenario5();
    void onScenario6();
	EStage m_eStage;
	hypGamePad m_hypGamePad;

};

typedef Singleton<hypGameloop> hypGameloopSingleton;
