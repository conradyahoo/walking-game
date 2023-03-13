#ifndef MAZEPERSON_H
#define MAZEPERSON_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/*********************************************************************
** Program Filename: mazeperson.h
** Author: Connor Radding
** Date: 3/8/23
** Description: header file for the abstract mazeperson class
** Input: none
** Output: virtual functions point to the coresponding child class functions
*********************************************************************/

class Mazeperson {
    public:
        Mazeperson();
        ~Mazeperson();

        virtual char get_move() = 0;
        virtual void set_location(int, int) = 0;
        virtual int get_row() = 0;
        virtual int get_col() = 0;
};

#endif