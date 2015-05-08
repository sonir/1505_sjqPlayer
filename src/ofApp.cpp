#include "ofApp.h"

using namespace std;
//--------------------------------------------------------------
void ofApp::setup(){
 
    ofSetCircleResolution(50);
    
    //SetupNode
    ofSystem("open ../../../data/launch");
    
    //SetDefault
    app.setup(SC_WIDTH,SC_HEIGHT);
    
    //Setup OSC
    osc = new Osc(7401,this);
    sender.setup("127.0.0.1", 7400);
    
    //Setup Sounds
    pf.loadSound("sounds/pf0.wav");
    tb.loadSound("sounds/tb0.wav");
    gt.loadSound("sounds/gt0.wav");
    ba.loadSound("sounds/ba0.wav");
    dr.loadSound("sounds/dr0.wav");

    
    pf.setVolume(0.75f);
    tb.setVolume(0.5f);
    gt.setVolume(0.75f);
    ba.setVolume(0.75f);
    dr.setVolume(0.85f);

    pf.setMultiPlay(true);
    tb.setMultiPlay(true);
    gt.setMultiPlay(true);
    ba.setMultiPlay(true);
    dr.setMultiPlay(true);



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

    ofSetColor(255, 255, 255);
    app.drawPlayerType();

    ofSetColor(255, 255, 255);
    string s="LOCAL: ";
    if(app.local==true)s+="ON";
    else s+="OFF";
    s+=" (SPC)";
    ofDrawBitmapString(s, MERGINE_LEFT,MERGINE_TOP+LINE_HEIGHT);
    
    app.drawCircles();
    
    ofSetColor(255, 255, 255);
    app.drawMode();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    //SYSTEM
    
    //SET Player
    if(key=='p')app.player_type = PF;
    if(key=='t')app.player_type = TB;
    if(key=='g')app.player_type = GT;
    if(key=='b')app.player_type = BA;
    if(key=='d')app.player_type = DR;
    //MODE Change
    if(key=='m'){
//        app.mode = GLITCH;
        if(app.getMode()==CATCH_BALL){
            cout << "A" << endl;
            app.setMode(GLITCH);
        }else{
            cout << "B" << endl;
            app.setMode(CATCH_BALL);
        }
        cout << app.getMode() << endl;
        
    }
    
    //SoundPlayback
    if(app.local){
        if(app.player_type==PF){
            if(key=='1')pf.play();
        }else{
            if(key=='1')gt.play();
        }
    }
    
    //SendOSC
    if(key=='1'){
        cout << "foo2" << endl;

        ofxOscMessage m;
        m.setAddress("/test2");
        m.addIntArg(app.player_type);
        m.addIntArg(app.note_type);
        sender.sendMessage(m);
        
    }
    if(key==' '){
        
        if(app.local==true){
            app.local = false;
        }else if(app.local==false){
            app.local = true;
        }
//        app.local=~app.local;
        
    }
    //Sound Play
    string adr;
    if(app.getMode() == CATCH_BALL) adr= "/sjq/mobile/catchball";
    else if (app.getMode() == GLITCH) adr= "/sjq/mobile/glitch";
    
    if(key==OF_KEY_LEFT){
        ofxOscMessage m;
        m.setAddress(adr);
        m.addIntArg((int)app.player_type);
        m.addIntArg((int)LOW_NOTE);
        sender.sendMessage(m);
        
        if(app.local==true){
            note_event_t t; t.inst=app.player_type; t.note=LOW_NOTE;
            noteTrigger(t);
        }
    }
    if(key==OF_KEY_RIGHT){
        ofxOscMessage m;
        m.setAddress(adr);
        m.addIntArg((int)app.player_type);
        m.addIntArg((int)HI_NOTE);
        sender.sendMessage(m);
        
        if(app.local==true){
            note_event_t t; t.inst=app.player_type; t.note=HI_NOTE;
            noteTrigger(t);
        }

    }
    if(key==OF_KEY_UP){
        ofxOscMessage m;
        m.setAddress(adr);
        m.addIntArg((int)app.player_type);
        m.addIntArg((int)POINT);
        sender.sendMessage(m);
        
        if(app.local==true){
            note_event_t t; t.inst=app.player_type; t.note=POINT;
            noteTrigger(t);
        }

    }
    if(key==OF_KEY_DOWN){
        
//        ofxOscMessage m;
//        m.setAddress("/sjq/performer/play");
//        m.addIntArg((int)app.player_type);
//        sender.sendMessage(m);
        
    }

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


void ofApp::noteTrigger(note_event_t trg){
    
    
    if(trg.inst==PF){
        pf.play();
        app.circle[PF].init(FILLSIZE_FOR_TRIGGER, 0.0, 10);
    }else if(trg.inst==TB){
        tb.play();
        app.circle[TB].init(FILLSIZE_FOR_TRIGGER, 0.0, 10);
    }else if(trg.inst==GT){
        gt.play();
        app.circle[GT].init(FILLSIZE_FOR_TRIGGER, 0.0, 10);
    }else if(trg.inst==BA){
        ba.play();
        app.circle[BA].init(FILLSIZE_FOR_TRIGGER, 0.0, 10);
    }else if(trg.inst==DR){
        dr.play();
        app.circle[DR].init(FILLSIZE_FOR_TRIGGER, 0.0, 10);
    }
    
    
}

void ofApp::reload(player_type_e player){
    
    app.circle[player].init(0., 1.0, FILLSPEED_FOR_RELOAD);
    
}


