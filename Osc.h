//
//  Osc.h
//  sjqPlayer
//
//  Created by sonir on 5/7/15.
//
//

#pragma once
//#ifndef __sjqPlayer__Osc__
//#define __sjqPlayer__Osc__

#include <stdio.h>
#include "slOscManager.h"
#include "ofApp.h"
#include "setup.h"
class ofApp;


class NoteEvent{
    
    public:
        player_type_e player_type = PF;
        note_type_e note_type = POINT;
    
};

class Osc : public slOscManager{

    public:

        Osc(int port, ofApp *app_adr):slOscManager(port){
        
            app = app_adr;
            n.player_type = PF;
            n.note_type = POINT;
            
        }

        ofApp *app;
        NoteEvent n;
        void fireMessage(ofxOscMessage *m);
//        ofEvent<NoteEvent> triggerEvent;

    
};

//#endif /* defined(__sjqPlayer__Osc__) */
