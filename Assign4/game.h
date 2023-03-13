#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <fstream>
#include "maze.h"
#include "mazeperson.h"
#include "intrepidstudent.h"
#include "ta.h"
#include "instructor.h"

using namespace std;

/*********************************************************************
** Program Filename: game.h
** Author: Connor Radding
** Date: 3/8/23
** Description: This header file contains all the member variables and function headers for the game class
** Input: none
** Output: none
*********************************************************************/

class Game {
    private:
        Maze maze;
        bool ai;
        int appease;
        int prog_skills;
        Mazeperson* student;
        Mazeperson* ta1;
        Mazeperson* ta2;
        Mazeperson* ta3;
        Mazeperson* instructor;
    public:
        Game();
        bool is_ai();
        void set_ai(bool);
        void start_appease_timer();
        int get_appease();
        void appease_timer();
        void move_ai();
        void move_ta3();
        void move_ta2();
        void move_ta1();
        void get_move();
        void display_maze();
        void demonstrate_skill();
        bool check_tas_and_skill();
        bool check_instructor();
        void check_skills();
        void spawn_student();
        void spawn_skills();
        void spawn_tas();
        void spawn_instructor();
        void load_maze();
        int get_skills();
};



#endif