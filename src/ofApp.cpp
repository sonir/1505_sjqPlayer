#include "ofApp.h"

using namespace std;
//--------------------------------------------------------------
void ofApp::setup(){
    
    
    //SetupNode
    ofSystem("open ../../../data/launch");
//        ofSystem("sh ../../../data/open_osc-hub.sh");
    
    //SetDefault
    player_type = PF;
    note_type = POINT;
    
    //System
    local = false;
    
    //Setup OSC
    osc = new Osc(7401,this);
    sender.setup("127.0.0.1", 7400);
    
    //Setup Sounds
    synth.loadSound("sounds/synth.wav");
    beats.loadSound("sounds/1085.mp3");
    vocals.loadSound("sounds/Violet.mp3");

    synth.setVolume(0.75f);
    beats.setVolume(0.75f);
    vocals.setVolume(0.5f);

    beats.setMultiPlay(false);
    vocals.setMultiPlay(true);



}


//--------------------------------------------------------------
void ofApp::update(){

    ofBackground(0,0,0);
    // update the sound playing system:
    ofSoundUpdate();
    osc->update();
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
//    //SET Player
    if(key=='p')player_type = PF;
    if(key=='t')player_type = TB;
    if(key=='g')player_type = GT;
    if(key=='b')player_type = BA;
    if(key=='d')player_type = DR;
    
    //SoundPlayback
    if(local){
        if(player_type==PF){
            if(key=='1')synth.play();
        }else{
            if(key=='1')vocals.play();
        }
    }
    
    //SendOSC
    if(key=='1'){
        
        ofxOscMessage m;
        m.setAddress("/test2");
        m.addIntArg(player_type);
        m.addIntArg(note_type);
        sender.sendMessage(m);
        
    }

//    if(key=='1')synth.play();
//    if(key=='2')vocals.play();


}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

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


void ofApp::noteTrigger(player_type_e player_type){
    
    if(player_type==PF){
        synth.play();
    }else{
        vocals.play();
    }
    
    
}


