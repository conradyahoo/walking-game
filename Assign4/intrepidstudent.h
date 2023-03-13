#ifndef INTREPIDSTUDENT_H
#define INTREPIDSTUDENT_H

#include <iostream>
#include <string>
#include <fstream>
#include "mazeperson.h"

using namespace std;

/*********************************************************************
** Program Filename: intrepidstudent.h
** Author: Connor Radding
** Date: 3/8/23
** Description: this header file holds the member variables and functions headers for the intrepidstudent class
** Input: none
** Output: none
*********************************************************************/

class Intrepidstudent: public Mazeperson {
    private:
        int row;
        int col;
    public:
        Intrepidstudent();
        char get_move();
        void set_location(int, int);
        int get_row();
        int get_col();
};

#endif