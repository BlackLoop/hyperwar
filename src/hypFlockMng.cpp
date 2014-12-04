#include "hypFlockMng.h"

#include "hypAssetMng.h"
#include "hypGameloop.h"

using namespace std;

hypFlockMng::hypFlockMng()
{

}

hypFlockMng::~hypFlockMng()
{

}

void hypFlockMng::Setup()
{
    int startCount = 10;
    for (int i = startCount; i > 0; i--) {
        flock.addBoid();
    }
}

void hypFlockMng::Update()
{
    flock.update();
}

void hypFlockMng::Render()
{
    flock.draw();
}
