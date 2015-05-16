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
    blink.setup("localhost", 65137);
    
    //Setup Sounds
    pf = new Sound("sounds/pf0.wav", "sounds/pf1.wav", "sounds/pf2.wav");
    tb = new Sound("sounds/tb0.wav", "sounds/tb1.wav", "sounds/tb2.wav");
    gt = new Sound("sounds/gt0.wav", "sounds/gt1.wav", "sounds/gt2.wav");
    ba = new Sound("sounds/ba0.wav", "sounds/ba1.wav", "sounds/ba2.wav");
    dr = new Sound("sounds/dr0.wav", "sounds/dr1.wav", "sounds/dr2.wav");

    
    pf->setVolume(ALL, 0.75f);
    tb->setVolume(ALL, 0.5f);
    gt->setVolume(ALL, 0.75f);
    ba->setVolume(ALL, 0.75f);
    dr->setVolume(ALL, 0.75f);
    
    pf->setMultiPlay(ALL, true);
    tb->setMultiPlay(ALL, true);
    gt->setMultiPlay(ALL, true);
    ba->setMultiPlay(ALL, true);
    dr->setMultiPlay(ALL, true);

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
    ofDrawBitmapString("TRIGGER: (UP=CHORD, LEFT=LOW, RIGHT=HIGH)", MERGINE_LEFT,MERGINE_TOP+LINE_HEIGHT*3);
    
    
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
        if(app.player_type==PF){
            if(key=='1')pf->play(POINT);
        }else{
            if(key=='1')pf->play(HIGH_NOTE);
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
        m.addIntArg((int)HIGH_NOTE);
        sender.sendMessage(m);
        
        if(app.player_type==DR){
            ofxOscMessage m2; m2.setAddress("/sjq/blink/bang");
            m2.addIntArg(ofRandom(BLINK_NUM));
            sender.sendMessage(m2);
        }
        
        if(app.local==true){
            note_event_t t; t.inst=app.player_type; t.note=HIGH_NOTE;
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
        pf->play(trg.note);
        app.circle[PF].init(FILLSIZE_FOR_TRIGGER, 0.0, 10);
    }else if(trg.inst==TB){
        tb->play(trg.note);
        app.circle[TB].init(FILLSIZE_FOR_TRIGGER, 0.0, 10);
    }else if(trg.inst==GT){
        gt->play(trg.note);
        app.circle[GT].init(FILLSIZE_FOR_TRIGGER, 0.0, 10);
    }else if(trg.inst==BA){
        ba->play(trg.note);
        app.circle[BA].init(FILLSIZE_FOR_TRIGGER, 0.0, 10);
    }else if(trg.inst==DR){
        dr->play(trg.note);
        app.circle[DR].init(FILLSIZE_FOR_TRIGGER, 0.0, 10);
    }
    
    
}

//--------------------------------------------------------------
void ofApp::reload(player_type_e player){
    
    app.circle[player].init(0., 1.0, FILLSPEED_FOR_RELOAD);
    
}


//--------------------------------------------------------------
void ofApp::bridgeToBlink(ofxOscMessage m){
    
    blink.sendMessage(m);
    
}
