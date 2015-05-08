//
//  Osc.cpp
//  sjqPlayer
//
//  Created by sonir on 5/7/15.
//
//

#include "Osc.h"

void Osc::fireMessage(ofxOscMessage *m){
    
    if(m->getAddress() == "/test1"){
        
        float fnum = m->getArgAsFloat(0);
        ofNotifyEvent(test1, fnum);
        
    }
    else if(m->getAddress() == "/sjq/mobile/catchball"){
        
        trg.inst = (player_type_e)m->getArgAsInt32(0);
        trg.note = (note_type_e)m->getArgAsInt32(1);
        ofapp->noteTrigger(trg);
        
    }else if(m->getAddress() == "/sjq/mobile/glitch"){
        
        trg.inst = (player_type_e)m->getArgAsInt32(0);
        trg.note = (note_type_e)m->getArgAsInt32(1);
        ofapp->noteTrigger(trg);
        
    }else if(m->getAddress() == "/sjq/performer/play"){
        
        player_type_e performer = (player_type_e)m->getArgAsInt32(0);
        ofapp->reload(performer);
        
    }

    
}