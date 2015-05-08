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
    else if(m->getAddress() == "/test2"){
        
        app->noteTrigger(PF);
        
    }

    
}