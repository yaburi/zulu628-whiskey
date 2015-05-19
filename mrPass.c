/*
 *  Mr Pass.  Brain the size of a planet!
 *
 *  Proudly Created by Richard Buckland
 *  Share Freely Creative Commons SA-BY-NC 3.0. 
 *  More proudly edited by Holy Ahel & Nathan Zhen
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
 
#include "Game.h"
#include "mechanicalTurk.h"

 
action decideAction (Game g) {
 
    action nextAction;
    
    if (getStudents(g, getWhoseTurn(g), STUDENT_MJ) >= 1 && 
        getStudents(g, getWhoseTurn(g), STUDENT_MTV) >= 1 && 
        getStudents(g, getWhoseTurn(g), STUDENT_MMONEY) >= 1) {

        nextAction.actionCode = START_SPINOFF; //start spin off

    } else {
        
        nextAction.actionCode = PASS;
    
    }
    
   
    return nextAction;
}