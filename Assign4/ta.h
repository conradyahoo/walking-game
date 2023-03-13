#ifndef TA_H
#define TA_H

#include <iostream>
#include <string>
#include <fstream>
#include "mazeperson.h"

using namespace std;

/*********************************************************************
** Program Filename: ta.h
** Author: Connor Radding
** Date: 3/8/23
** Description: header file for the child class ta
** Input: none
** Output: none
*********************************************************************/

class Ta: public Mazeperson {
    private:
        int row;
        int col;
    public:
        Ta();
        char get_move();
        void set_location(int, int);
        int get_row();
        int get_col();
};

#endif