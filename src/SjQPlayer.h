//
//  SjQPlayer.h
//  sjqPlayer
//
//  Created by sonir on 5/8/15.
//
//

#ifndef __sjqPlayer__SjQPlayer__
#define __sjqPlayer__SjQPlayer__

#define CIRCLE_SIZE 0.15


#include <stdio.h>
#include "slAppManager.h"
#include "setup.h"
#include "slInterpolation.h"



class SjQPlayer : public slAppManager {
    
    public:
        void setup(float sc_w, float sc_h);
        void drawPlayerType();
        void drawCircles();
        void drawMode();
        void setMode(mode_e m);
        mode_e getMode();
    
        bool local;
        player_type_e player_type;
        note_type_e note_type;
        float sc_width;
        float sc_height;
        float circle_size;
        float circle_mergine;
        float circle_space;
    
        Interpolation circle[6];

    private:
        mode_e mode;

    
};

#endif /* defined(__sjqPlayer__SjQPlayer__) */
