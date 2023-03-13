#ifndef WALL_H
#define WALL_H

#include <iostream>
#include <string>
#include <fstream>
#include "mazelocation.h"

using namespace std;

/*********************************************************************
** Program Filename: wall.h
** Author: Connor Radding
** Date: 3/8/23
** Description: header file for the child wall class
** Input: none
** Output: none
*********************************************************************/

class Wall: public Mazelocation{
    private:
        char dis_char;
    public:
        Wall();
        bool is_occupiable();
        char get_display_character();

        bool has_student();
        bool has_ta();
        bool has_instructor();
        bool has_skill();

        void set_has_student(bool);
        void set_has_ta(bool);
        void set_has_instructor(bool);
        void set_has_skill(bool);

};

#endif