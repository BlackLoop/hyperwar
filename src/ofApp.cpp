#include "ofApp.h"

#include "hypGameloop.h"
#include "hypRenderMng.h"
//--------------------------------------------------------------
void ofApp::setup(){
    hypGameloopSingleton::Instance()->Setup();
    hypRenderMngSingleton::Instance()->Setup();
}

//--------------------------------------------------------------
void ofApp::update(){
    hypGameloopSingleton::Instance()->Update();
    hypRenderMngSingleton::Instance()->Update();
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
    hypRenderMng::Instance()->m_mouseX = x;
    hypRenderMng::Instance()->m_mouseY = y;
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
