//
//  Sound.h
//  sjqPlayer
//
//  Created by sonir on 5/9/15.
//
//

#ifndef __sjqPlayer__Sound__
#define __sjqPlayer__Sound__

#include <stdio.h>
#include "ofMain.h"
#include "setup.h"

class Sound {
    
    public:
    
        Sound(string point_src, string high_src, string low_src);
        void setVolume(note_type_e t, float vol);
        void setMultiPlay(note_type_e t, bool flg);
        void play(note_type_e t);
        void update();
    
        ofSoundPlayer point;
        ofSoundPlayer high;
        ofSoundPlayer low;
    
    
};

#endif /* defined(__sjqPlayer__Sound__) */
