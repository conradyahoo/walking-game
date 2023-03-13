#include <iostream>
#include <string>
#include <fstream>
#include "ta.h"
#include <cstdlib>

using namespace std;

/*********************************************************************
** Program Filename: ta.cpp
** Author: Connor Radding
** Date: 3/8/23
** Description: holds all of the functions for the child clas ta
** Input: setters set location
** Output: outputs random moves and its location
*********************************************************************/

/*********************************************************************
** Function: Ta
** Description: constructor
** Parameters: none
** Pre-Conditions: ta object is created
** Post-Conditions: sets member variables
*********************************************************************/
Ta::Ta(){
    
    this->row = -1;
    this->col = -1;
}

/*********************************************************************
** Function: get_move
** Description: gets random move
** Parameters: none
** Pre-Conditions: ta needs to move
** Post-Conditions: returns move char
*********************************************************************/
char Ta::get_move(){

    srand(time(0));

    //gets random number
    int move = rand() % 4;

    if (move == 0){
        return 'w';
    }
    if (move == 1){
        return 'a';
    }
    if (move == 2){
        return 's';
    }
    if (move == 3){
        return 'd';
    }
}

/*********************************************************************
** Function: set_location
** Description: sets the location for ta
** Parameters: row and col int
** Pre-Conditions: ta needs a new location
** Post-Conditions: location is set
*********************************************************************/
void Ta::set_location(int r, int c){

    this->row = r;
    this->col = c;
}

/*********************************************************************
** Function: get_row
** Description: getter for row
** Parameters: none
** Pre-Conditions: function called
** Post-Conditions: returns row int
*********************************************************************/
int Ta::get_row(){

    return this->row;
}

/*********************************************************************
** Function: get_col
** Description: getter for ta col
** Parameters: none
** Pre-Conditions: function called
** Post-Conditions: returns col int
*********************************************************************/
int Ta::get_col(){

    return this->col;
}