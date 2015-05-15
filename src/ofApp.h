#pragma once

#include <pthread.h>
#include <stdlib.h>
#include "ofMain.h"
#include "setup.h"
#include "SjQPlayer.h"
#include "Sound.h"
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

    void noteTrigger(note_event_t trg);
    void reload(player_type_e player);
    void bridgeToBlink(ofxOscMessage m);
    
    //Deconstructor
    ~ofApp(){
        
        system("killall Terminal");
        
    }

    //App
    SjQPlayer app;
    //Sound
    Sound  *pf;
    Sound  *tb;
    Sound  *gt;
    Sound  *ba;
    Sound  *dr;
    
    //OSC
    Osc *osc;
    ofxOscSender sender;
    ofxOscSender blink;

    
};
