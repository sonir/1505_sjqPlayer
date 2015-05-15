//
//  setup.h
//  sjqPlayer
//
//  Created by sonir on 5/7/15.
//
//

#ifndef sjqPlayer_setup_h
#define sjqPlayer_setup_h

#define SC_WIDTH 1024
#define SC_HEIGHT 768
#define MERGINE_TOP 20
#define MERGINE_LEFT 15
#define LINE_HEIGHT 20

//Color
#define PF_COLOR_R 255
#define PF_COLOR_G 0
#define PF_COLOR_B 0

#define TB_COLOR_R 255
#define TB_COLOR_G 255
#define TB_COLOR_B 0

#define GT_COLOR_R 0
#define GT_COLOR_G 255
#define GT_COLOR_B 0

#define BA_COLOR_R 100
#define BA_COLOR_G 100
#define BA_COLOR_B 255

#define DR_COLOR_R 180
#define DR_COLOR_G 70
#define DR_COLOR_B 255

//ANIMATION
#define FILLSIZE_FOR_TRIGGER 1.3
#define FILLSPEED_FOR_RELOAD 3


enum player_type_e {NONE, PF, TB, GT, BA, DR};
enum note_type_e {POINT, HIGH_NOTE, LOW_NOTE, KICK, HAT, SNARE, ALL};
enum mode_e {CATCH_BALL, GLITCH};

typedef struct note_event_t{
    
    player_type_e inst = NONE;
    note_type_e note = POINT;
    
} note_event_t;


#endif
