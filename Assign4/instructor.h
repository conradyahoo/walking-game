#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include <iostream>
#include <string>
#include <fstream>
#include "mazeperson.h"

using namespace std;

/*********************************************************************
** Program Filename: instructor.h
** Author: Connor Radding
** Date: 3/8/23
** Description: this header file holds the member variables for and function headers for the instructor class
** Input: none
** Output: none
*********************************************************************/

class Instructor: public Mazeperson {
    private:
        int row;
        int col;
    public:
        Instructor();
        char get_move();
        void set_location(int, int);
        int get_row();
        int get_col();
};

#endif