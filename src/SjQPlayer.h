//
//  SjQPlayer.h
//  sjqPlayer
//
//  Created by sonir on 5/8/15.
//
//

#ifndef __sjqPlayer__SjQPlayer__
#define __sjqPlayer__SjQPlayer__

#include <stdio.h>
#include "slAppManager.h"
#include "setup.h"


class SjQPlayer : public slAppManager {
    
    public:
        void setup();
        bool local;
        player_type_e player_type;
        note_type_e note_type;
    
    
};

#endif /* defined(__sjqPlayer__SjQPlayer__) */
