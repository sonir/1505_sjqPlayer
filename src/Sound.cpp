//
//  Sound.cpp
//  sjqPlayer
//
//  Created by sonir on 5/9/15.
//
//

#include "Sound.h"
using namespace std;

Sound::Sound(string point_src, string high_src, string low_src){
    
    point.loadSound(point_src);
    high.loadSound(high_src);
    low.loadSound(low_src);
    
    
}

void Sound::setVolume(note_type_e t, float vol){
    
    switch(t){
            
        case POINT:
            point.setVolume(vol);
            break;

        case HIGH_NOTE:
            high.setVolume(vol);
            break;

        case LOW_NOTE:
            low.setVolume(vol);
            break;
            
        case ALL:
            point.setVolume(vol);
            high.setVolume(vol);
            low.setVolume(vol);
            
        default:
            cout << "SOUND:unknown note type was specified" << endl;
    }
    
}

void Sound::setMultiPlay(note_type_e t, bool flg){
    
    switch(t){
            
        case POINT:
            point.setMultiPlay(flg);
            break;
            
        case HIGH_NOTE:
            high.setMultiPlay(flg);
            break;
            
        case LOW_NOTE:
            low.setMultiPlay(flg);
            break;
            
        case ALL:
            point.setMultiPlay(flg);
            high.setMultiPlay(flg);
            low.setMultiPlay(flg);
            break;
            
        default:
            cout << "Sound.setMultiPlay:unknown note type was specified" << endl;
    }
    
}


void Sound::play(note_type_e t){
    
    switch(t){
            
        case POINT:
            point.play();
            break;
            
        case HIGH_NOTE:
            high.play();
            break;
            
        case LOW_NOTE:
            low.play();
            break;
            
        case ALL:
            point.play();
            high.play();
            low.play();
            break;
            
        default:
            cout << "Sound.play:unknown note type was specified" << endl;
    }
    
    
}

void Sound::update(){
    
//    point.update();
//    high.update();
//    low.update();
    
}
