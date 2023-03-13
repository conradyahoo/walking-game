#ifndef OPENSPACE_H
#define OPENSPACE_H

#include <iostream>
#include <string>
#include <fstream>
#include "mazelocation.h"

using namespace std;

/*********************************************************************
** Program Filename: openspace.h
** Author: Connor Radding
** Date: 3/8/23
** Description: header file for the child class openspace
** Input: none
** Output: none
*********************************************************************/

class Openspace: public Mazelocation{
    private:
        char dis_char;
        bool student;
        bool ta;
        bool instructor;
        bool skill;
    public:
        Openspace();
        bool is_occupiable();
        char get_display_character();
        
        void set_has_student(bool);
        void set_has_ta(bool);
        void set_has_instructor(bool);
        void set_has_skill(bool);
        
        bool has_student();
        bool has_ta();
        bool has_instructor();
        bool has_skill();
        
};

#endif