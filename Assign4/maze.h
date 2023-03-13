#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "mazelocation.h"
#include "openspace.h"
#include "wall.h"

using namespace std;

/*********************************************************************
** Program Filename:
** Author: Connor Radding
** Date: 3/8/23
** Description: this is the header file for the maze class
** Input: none
** Output: none
*********************************************************************/

class Maze {
    private:
        int row;
        int col;
        vector <vector<Mazelocation*> > locations;
    public:
        Maze();
        void load_vector();
        Maze(const Maze&);
        Maze& operator=(const Maze& old_m);
        ~Maze();
        void print_maze(int, int);
        Mazelocation* get_location(int, int);
        void set_row(int);
        void set_col(int);
        int get_row();
        int get_col();

};

#endif