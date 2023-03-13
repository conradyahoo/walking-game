#include <iostream>
#include <string>
#include <fstream>
#include "wall.h"

using namespace std;

/*********************************************************************
** Program Filename: wall.cpp
** Author: Connor Radding
** Date: 3/8/23
** Description: holds all of the functions for the wall class
** Input: setters set the location
** Output: outputs the display characteer and false for has_(anything)
*********************************************************************/

/*********************************************************************
** Function: Wall()
** Description: constructor
** Parameters: none
** Pre-Conditions: wall object is created
** Post-Conditions: sets member variable 
*********************************************************************/
Wall::Wall(){

    this->dis_char = '#';
}

/*********************************************************************
** Function: setters that do nothing
** Description: these setters do nothing but I need them because of the parent function
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: none
*********************************************************************/
void Wall::set_has_student(bool){}
void Wall::set_has_ta(bool){}
void Wall::set_has_instructor(bool){}
void Wall::set_has_skill(bool){}

/*********************************************************************
** Function: is_occupiable
** Description: returns false
** Parameters: none
** Pre-Conditions: function called
** Post-Conditions: returns false
*********************************************************************/
bool Wall::is_occupiable(){

    return false;
}

/*********************************************************************
** Function: get_display_character
** Description: returns dis_char
** Parameters: none
** Pre-Conditions: function called for printing
** Post-Conditions: returns a # symbol
*********************************************************************/
char Wall::get_display_character(){

    return dis_char;
}

/*********************************************************************
** Function: has_student
** Description: returns false
** Parameters: none
** Pre-Conditions: function called
** Post-Conditions: returns false
*********************************************************************/
bool Wall::has_student(){
    return false;
}

/*********************************************************************
** Function: has_ta
** Description: returns false
** Parameters: none
** Pre-Conditions: function called
** Post-Conditions: returns false
*********************************************************************/
bool Wall::has_ta(){
    return false;
}

/*********************************************************************
** Function: has_instructor
** Description: returns false
** Parameters: none
** Pre-Conditions: function called
** Post-Conditions: returns false
*********************************************************************/
bool Wall::has_instructor(){

    return false;
}

/*********************************************************************
** Function: has_skill
** Description: retuns false
** Parameters: none
** Pre-Conditions: function called
** Post-Conditions: returns false
*********************************************************************/
bool Wall::has_skill(){
    return false;
}