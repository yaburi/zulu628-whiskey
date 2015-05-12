// Game.c
// ADT for Knowledge Island
// Nathan Zhen, Jack Abroon, Holly Ahel and Jessica Chen

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "Game.h"

// Default defines
#define DEFAULT_DISCIPLINES {STUDENT_BQN, STUDENT_MMONEY, STUDENT_MJ, 
                STUDENT_MMONEY, STUDENT_MJ, STUDENT_BPS, STUDENT_MTV, 
                STUDENT_MTV, STUDENT_BPS,STUDENT_MTV, STUDENT_BQN, 
                STUDENT_MJ, STUDENT_BQN, STUDENT_THD, STUDENT_MJ, 
                STUDENT_MMONEY, STUDENT_MTV, STUDENT_BQN, STUDENT_BPS}
#define DEFAULT_DICE {9,10,8,12,6,5,3,11,3,11,4,6,4,7,9,2,8,10,5}

// Terra Nullis (state of game before dice is first rolled)
#define TERRA_NULLIS -1

// player ID of each university
#define NO_ONE 0
#define UNI_A 1
#define UNI_B 2
#define UNI_C 3

// Map 
#define NUM_VERTICES 54
#define NUM_EDGES 72
#define VERTICES_PER_EDGE 2
#define VERTICES_PER_REGION 6
 
// KPI earned for each thing built
#define KPIS_CAMPUS 10
#define KPIS_GO8 20
#define KPIS_ARC 2
#define KPIS_PATENT 10
#define KPIS_MOST_ARCS 10
#define KPIS_MOST_PUBLICATIONS 10

// Starting buildings
#define INITIAL_KPIS 20
#define INITIAL_ARCS 0
#define INITIAL_GO8S 0
#define INITIAL_CAMPUSES 2
#define INITIAL_PATENTS 0
#define INITIAL_PUBLICATIONS 0

// Starting resources
#define INITIAL_THD 0
#define INITIAL_BPS 3
#define INITIAL_BQN 3
#define INITIAL_MJ 1
#define INITIAL_MTV 1
#define INITIAL_MMONEY 1

// Starting campuses
#define INITIAL_CAMPUSES 2

// Exchange rates
#define NORMAL_EXCHANGE_RATE 3
#define EXCHANGE_RATE_WITH_CENTRE 2

typedef struct _game { 
    
    // Map (*** not sure how to do yet)
    vertex  // what is on this vertex
    edge    // what is on this edge
    region  // what this region produces

    // Players
    player players[NUM_UNIS];    // players in the game

    // Trackers
    int currentTurn;    // tracks the number of turns
    int whoseTurn;      // tracks whose turn it is
    int mostARCs;       // tracks who currently has the most ARCs
    int mostPublications; // tracks who currently has the most pubs
    int numGO8;         // makes sure GO8's doesn't go past 8

} game;

typedef struct _player {
   
    // Buildings each player has
    int KPIs;
    int ARCs;
    int campuses;
    int GO8Campuses;
    int patents;
    int publications;

    // Disciplines each player has
    int THDs;
    int BPSs;
    int BQNs;
    int MJs;
    int MTVs;
    int MMONEYs;

} player;

typedef struct _vertex {
    
    // Adjacent edges

    // Adjacent regions

} vertex;

typedef struct _edge {
    
    // Adjacent vertices

} edge;

typedef struct _region {

    // Adjacent vertices

    // Determines what student is given depending on number rolled
    int diceNumber;
    int studentType;
} region;


/* **** Functions which change the game aka SETTERS **** */
// make a new game, given the disciplines produced by each
// region, and the value on the dice discs in each region.
// note: each array must be NUM_REGIONS long
// eg if you are using my sample game struct above this function
// would need to set the field currentTurn to -1.  (because the turn
// number is -1 at the start of the game)
// the ordering of the regions is column by column left to right,
// going from the top of each column to the bottom before moving 
// to the next column to the right.
//
// so to create the default game as shown on the badly drawn map:
//
/*
#define DEFAULT_DISCIPLINES {STUDENT_BQN, STUDENT_MMONEY, STUDENT_MJ, 
                STUDENT_MMONEY, STUDENT_MJ, STUDENT_BPS, STUDENT_MTV, 
                STUDENT_MTV, STUDENT_BPS,STUDENT_MTV, STUDENT_BQN, 
                STUDENT_MJ, STUDENT_BQN, STUDENT_THD, STUDENT_MJ, 
                STUDENT_MMONEY, STUDENT_MTV, STUDENT_BQN, STUDENT_BPS }
#define DEFAULT_DICE {9,10,8,12,6,5,3,11,3,11,4,6,4,7,9,2,8,10,5}
*/
//
//   int disciplines[] = DEFAULT_DISCIPLINES;
//   int dice[] = DEFAULT_DICE;
//   Game g = newGame (disciplines, dice);
Game newGame (int discipline[], int dice[]) {

    Game g = malloc (sizeof (Game));

    // Set up initial state of game
    g->currentTurn = TERRA_NULLIS;
    g->whoseTurn = NO_ONE;
    g->mostARCs = NO_ONE;
    g->mostPublications = NO_ONE;
    g->numGO8 = FALSE;

    // Give players default values
    int i = 1; // Name given to each player (increasing each loop)
    while (i <= NUM_UNIS) {
        g->players[i].KPIs  = INITIAL_KPIS;
        g->players[i].ARCs = INITIAL_ARCS;
        g->players[i].campuses = INITIAL_CAMPUSES;
        g->players[i].GO8Campuses = INITIAL_GO8S;
        g->players[i].patents = INITIAL_PATENTS;
        g->players[i].publications = INITIAL_PUBLICATIONS;

    // Give players default number of students
        g->players[i].THDs = INITIAL_THD;
        g->players[i].BPSs = INITIAL_BPS;
        g->players[i].BQNs = INITIAL_BQN;   
        g->players[i].MJs = INITIAL_MJ;
        g->players[i].MTVs = INITIAL_MTV;
        g->players[i].MMONEYs = INITIAL_MMONEY;

        i++;
    }
}

// free all the memory malloced for the game
void disposeGame (Game g) {
    assert (g != NULL);
    free (g);
}

// make the specified action for the current player and update the 
// game state accordingly.  
// The function may assume that the action requested is legal.
// START_SPINOFF is not a legal action here
void makeAction (Game g, action a) {

}

// advance the game to the next turn, 
// assuming that the dice has just been rolled and produced diceScore
// the game starts in turn -1 (we call this state "Terra Nullis") and 
// moves to turn 0 as soon as the first dice is thrown. 
void throwDice (Game g, int diceScore) {

}

/* **** Functions which GET data about the game aka GETTERS **** */

// what type of students are produced by the specified region?
// regionID is the index of the region in the newGame arrays (above) 
// see discipline codes above
int getDiscipline (Game g, int regionID) {

}

// what dice value produces students in the specified region?
// 2..12
int getDiceValue (Game g, int regionID) {

}

// which university currently has the prestige award for the most ARCs?
// this is NO_ONE until the first arc is purchased after the game 
// has started.  
int getMostARCs (Game g) {

}

// which university currently has the prestige award for the most pubs?
// this is NO_ONE until the first publication is made.
int getMostPublications (Game g) {

}

// return the current turn number of the game -1,0,1, ..
int getTurnNumber (Game g) {

}

// return the player id of the player whose turn it is 
// the result of this function is NO_ONE during Terra Nullis
int getWhoseTurn (Game g) {
    
    int playerID;
    
    if (g->currentTurn%3 == 0) {
        playerID = UNI_A;
    } else if (g->currentTurn%3 == 1) {
        playerID = UNI_B;
    } else if (g->currentTurn%3 == 2) {
        playerID = UNI_C;
    } else {
        playerID = NO_ONE;
    }

    return player;
}

// return the contents of the given vertex (ie campus code or 
// VACANT_VERTEX)
int getCampus(Game g, path pathToVertex) {

}

// the contents of the given edge (ie ARC code or vacent ARC)
int getARC(Game g, path pathToEdge) {

}

// returns TRUE if it is legal for the current
// player to make the specified action, FALSE otherwise.
//
// "legal" means everything is legal: 
//   * that the action code is a valid action code which is legal to 
//     be made at this time
//   * that any path is well formed and legal ie consisting only of 
//     the legal direction characters and of a legal length, 
//     and which does not leave the island into the sea at any stage.
//   * that disciplines mentioned in any retraining actions are valid 
//     discipline numbers, and that the university has sufficient
//     students of the correct type to perform the retraining
//
// eg when placing a campus consider such things as: 
//   * is the path a well formed legal path 
//   * does it lead to a vacent vertex?
//   * under the rules of the game are they allowed to place a 
//     campus at that vertex?  (eg is it adjacent to one of their ARCs?)
//   * does the player have the 4 specific students required to pay for 
//     that campus?
// It is not legal to make any action during Terra Nullis ie 
// before the game has started.
// It is not legal for a player to make the moves OBTAIN_PUBLICATION 
// or OBTAIN_IP_PATENT (they can make the move START_SPINOFF)
// you can assume that any pths passed in are NULL terminated strings.
int isLegalAction (Game g, action a) {

}

// --- get data about a specified player ---

// return the number of KPI points the specified player currently has
int getKPIpoints (Game g, int player) {

    return KPIpoints;
}

// return the number of ARC grants the specified player currently has
int getARCs (Game g, int player) {

    return numOfARCs;
}

// return the number of GO8 campuses the specified player currently has
int getGO8s (Game g, int player) {

    return numOfGO8s;
}

// return the number of normal Campuses the specified player currently has
int getCampuses (Game g, int player) {

    return numOfCampuses;
}

// return the number of IP Patents the specified player currently has
int getIPs (Game g, int player) {

}

// return the number of Publications the specified player currently has
int getPublications (Game g, int player) {

}

// return the number of students of the specified discipline type 
// the specified player currently has
int getStudents (Game g, int player, int discipline) {
    
    int numStudents = 0;
    
    if (discipline == BPSs) {
        numStudents = player->BPSs;
    
    }else if (discipline == THDs) {
        numStudents = player->THDs;
        
    } else if (discipline == BQNs) {
        numStudents = player->BQNs);
        
    } else if (discipline == MJs) {
        numStudents = player->MJs;
        
    } else if (discipline == MTVs) {
        numStudents = player->MMONEYs;
        
    } else if (discipline == MMONEYs) {
        numStudents = player->MMONEYs;
    }
    
    return numStudents;
}

// return how many students of discipline type disciplineFrom
// the specified player would need to retrain in order to get one 
// student of discipline type disciplineTo.  This will depend 
// on what retraining centers, if any, they have a campus at.
int getExchangeRate (Game g, int player, 
                     int disciplineFrom, int disciplineTo) {

}
