#pragma once

#include <pthread.h>
#include <stdlib.h>
#include "ofMain.h"
#include "setup.h"
#include "threadedObject.h"
#include"Osc.h"
class Osc;


class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    void noteTrigger(player_type_e player_type);
    ~ofApp(){
        
        system("killall Terminal");
        
    }

    //SystemParams
    bool local;
    //Sound
    player_type_e player_type;
    note_type_e note_type;
    ofSoundPlayer  beats;
    ofSoundPlayer  synth;
    ofSoundPlayer  vocals;
    //OSC
    Osc *osc;
    ofxOscSender sender;

    
};
