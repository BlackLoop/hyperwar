#include "ofApp.h"

#include "hypGameloop.h"
#include "hypRenderMng.h"
#include "hypComMng.h"
#include "hypModelMng.h"

#include "settings.h"

void ofApp::exit(ofEventArgs &args) {
    hypGameloopSingleton::Instance()->kill();
    hypRenderMngSingleton::Instance()->kill();
    hypModelMngSingleton::Instance()->kill();
#ifdef USE3DPAD
    hypComMngSingleton::Instance()->kill();
#endif // USE3DPAD
}

//--------------------------------------------------------------
void ofApp::setup(){

    hypModelMngSingleton::Instance()->Setup();
    hypGameloopSingleton::Instance()->Setup();
    hypRenderMngSingleton::Instance()->Setup();
#ifdef USE3DPAD
    printf("Loooooool ! cc Barzi\n");
    hypComMngSingleton::Instance()->Setup();
#endif // USE3DPAD
}

//--------------------------------------------------------------
void ofApp::update(){
    hypGameloopSingleton::Instance()->Update();
    hypRenderMngSingleton::Instance()->Update();
#ifdef USE3DPAD
    hypComMngSingleton::Instance()->Update();
#endif

    hypModelMngSingleton::Instance()->Update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    hypRenderMngSingleton::Instance()->Render();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if( key == OF_KEY_UP)    { hypRenderMngSingleton::Instance()->m_zoom += 50.f; cout<<"zoom "<<hypRenderMngSingleton::Instance()->m_zoom<<endl;  }
    if( key == OF_KEY_DOWN)  { hypRenderMngSingleton::Instance()->m_zoom -= 50.f;  cout<<"zoom "<<hypRenderMngSingleton::Instance()->m_zoom<<endl; }
    if( key == 'f' )
    {
        ofToggleFullscreen();
    }
}



//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    hypModelMngSingleton::Instance()->GetMouse().SetMouse(x,y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){


}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){

}
