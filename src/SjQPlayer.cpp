//
//  SjQPlayer.cpp
//  sjqPlayer
//
//  Created by sonir on 5/8/15.
//
//

#include "SjQPlayer.h"

void SjQPlayer::setup(float sc_w, float sc_h){
    
    sc_width = sc_w;
    sc_height = sc_h;
    circle_size = (sc_width*CIRCLE_SIZE)/2;
    circle_mergine = MERGINE_LEFT+circle_size*2;
    circle_space = circle_size*2+20;
    
    setMode(CATCH_BALL);
    player_type = NONE;
    note_type = POINT;
    
    //System
    local = false;
  
    
    
}

void SjQPlayer::drawPlayerType(){
    
    string s = "PLAYER: ";
    
    switch(player_type){
            
        case PF:
            ofSetColor(PF_COLOR_R, PF_COLOR_G, PF_COLOR_B);
            s+= "[PF]";
            break;

        case TB:
            ofSetColor(TB_COLOR_R, TB_COLOR_G, TB_COLOR_B);
            s+= "[TB]";
            break;

        case GT:
            ofSetColor(GT_COLOR_R, GT_COLOR_G, GT_COLOR_B);
            s+= "[GT]";
            break;

        case BA:
            ofSetColor(BA_COLOR_R, BA_COLOR_G, BA_COLOR_B);
            s+= "[BA]";
            break;

        case DR:
            ofSetColor(DR_COLOR_R, DR_COLOR_G, DR_COLOR_B);
            s+= "[DR]";
            break;

        default:
            s += "unknown player specified";
            break;
            
            
    }
    
    s += " (p=PF, t=TB, g=GT, b=BA, d=DR)";
    
    ofDrawBitmapString(s, MERGINE_LEFT,MERGINE_TOP);
    
}


void SjQPlayer::drawCircles(){

    //PF
    ofNoFill();
    ofSetColor(PF_COLOR_R, PF_COLOR_G, PF_COLOR_B);
    ofCircle(circle_mergine, (sc_height/2), circle_size);
    ofFill();
    ofCircle(circle_mergine, (sc_height/2), circle_size*circle[PF].update());
    
    //TB
    ofNoFill();
    ofSetColor(TB_COLOR_R, TB_COLOR_G, TB_COLOR_B);
    ofCircle(circle_mergine+circle_space, (sc_height/2), circle_size);
    ofFill();
    ofCircle(circle_mergine+circle_space, (sc_height/2), circle_size*circle[TB].update());
    
    //GT
    ofNoFill();
    ofSetColor(GT_COLOR_R, GT_COLOR_G, GT_COLOR_B);
    ofCircle(circle_mergine+circle_space*2, (sc_height/2), circle_size);
    ofFill();
    ofCircle(circle_mergine+circle_space*2, (sc_height/2), circle_size*circle[GT].update());
    
    //BA
    ofNoFill();
    ofSetColor(BA_COLOR_R, BA_COLOR_G, BA_COLOR_B);
    ofCircle(circle_mergine+circle_space*3, (sc_height/2), circle_size);
    ofFill();
    ofCircle(circle_mergine+circle_space*3, (sc_height/2), circle_size*circle[BA].update());
    
    //DR
    ofNoFill();
    ofSetColor(DR_COLOR_R, DR_COLOR_G, DR_COLOR_B);
    ofCircle(circle_mergine+circle_space*4, (sc_height/2), circle_size);
    ofFill();
    ofCircle(circle_mergine+circle_space*4, (sc_height/2), circle_size*circle[DR].update());

    
}


void SjQPlayer::drawMode(){
    
    string s = "MODE: ";
    if(mode == CATCH_BALL) s+= "CATCH_BALL";
    else if(mode == GLITCH) s+= "GLITCH";
    else s+= "UNKNOWN_MODE";
    
    s+= " (m)";
    ofDrawBitmapString(s, MERGINE_LEFT,MERGINE_TOP+(LINE_HEIGHT*2));
    
    
}

void SjQPlayer::setMode(mode_e m){
    
    mode = m;
    
}

mode_e SjQPlayer::getMode(){
    
    return mode;
    
}