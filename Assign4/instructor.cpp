#include <iostream>
#include <string>
#include <fstream>
#include "instructor.h"
#include <cstdlib>

using namespace std;

/*********************************************************************
** Program Filename: instructor.cpp
** Author: Connor Radding
** Date: 3/8/23
** Description: This .cpp file holds all the instructor functions for the class
** Input: setters set the row and col
** Output: returns row and col based on the instructors location
*********************************************************************/

/*********************************************************************
** Function: Instructor()
** Description: instructor constructor (hey that rhymes(i think?))
** Parameters: none
** Pre-Conditions: instructor object is created
** Post-Conditions: row and col is set as junk values
*********************************************************************/
Instructor::Instructor(){
    
    this->row = -1;
    this->col = -1;
}

/*********************************************************************
** Function: get_move
** Description: returns garbage value as this function should never be called
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns char
*********************************************************************/
char Instructor::get_move(){

    return 'n';
}

/*********************************************************************
** Function: set_location
** Description: setter for instructor location
** Parameters: a row and col integer
** Pre-Conditions: suitable space is found for instructor
** Post-Conditions: sets the location
*********************************************************************/
void Instructor::set_location(int r, int c){

    this->row = r;
    this->col = c;
}

/*********************************************************************
** Function: get_row
** Description: returns the row
** Parameters: none
** Pre-Conditions: function called
** Post-Conditions: returns row
*********************************************************************/
int Instructor::get_row(){

    return this->row;
}

/*********************************************************************
** Function: get_col
** Description: returns the col for instructor
** Parameters: none
** Pre-Conditions: function called
** Post-Conditions: returns col int
*********************************************************************/
int Instructor::get_col(){

    return this->col;
}