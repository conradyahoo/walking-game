#include <iostream>
#include <string>
#include <fstream>
#include "openspace.h"

using namespace std;

/*********************************************************************
** Program Filename: openspace.cpp
** Author: Connor Radding
** Date: 3/8/23
** Description: this holds all the functions for the child class openspace
** Input: setters set true or false for whats in the space
** Output: outputs true or false based on the state of the space
*********************************************************************/

/*********************************************************************
** Function: Openspace()
** Description: constructor
** Parameters: none
** Pre-Conditions: openspace object created
** Post-Conditions: sets member variables
*********************************************************************/
Openspace::Openspace(): dis_char(' '), student(false), ta(false), instructor(false), skill(false){}

/*********************************************************************
** Function: is_occupiable
** Description: returns true
** Parameters: none
** Pre-Conditions: function called
** Post-Conditions: returns true
*********************************************************************/
bool Openspace::is_occupiable(){

    return true;
}

/*********************************************************************
** Function: get_display_character
** Description: returns display character
** Parameters: none
** Pre-Conditions: function called
** Post-Conditions: returns the dis_char variables
*********************************************************************/
char Openspace::get_display_character(){
    return dis_char;
}

/*********************************************************************
** Function: set_has_student
** Description: sets has student as true or false
** Parameters: bool
** Pre-Conditions: function called
** Post-Conditions: sets student bool
*********************************************************************/
void Openspace::set_has_student(bool s){
    this->student = s;
}

/*********************************************************************
** Function: set_has_ta
** Description: sets ta
** Parameters: bool
** Pre-Conditions: function called
** Post-Conditions: sets ta
*********************************************************************/
void Openspace::set_has_ta(bool t){
    this->ta = t;
}

/*********************************************************************
** Function: set_has_instructor
** Description: sets instructor
** Parameters: bool
** Pre-Conditions: function called
** Post-Conditions: sets instructor
*********************************************************************/
void Openspace::set_has_instructor(bool i){
    
    this->instructor = i;
}
/*********************************************************************
** Function: set_has_skill
** Description: sets skill
** Parameters: bool
** Pre-Conditions: none
** Post-Conditions: sets skill
*********************************************************************/
void Openspace::set_has_skill(bool sk){
    this->skill = sk;
}

/*********************************************************************
** Function: has_student
** Description: returns bool
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns bool
*********************************************************************/
bool Openspace::has_student(){
    return this->student;
}
/*********************************************************************
** Function: has_ta
** Description: returns bool
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns bool
*********************************************************************/
bool Openspace::has_ta(){
    
    return this->ta;
}
/*********************************************************************
** Function: has_instructor
** Description: returns bool
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns bool
*********************************************************************/
bool Openspace::has_instructor(){

    return this->instructor;
}
/*********************************************************************
** Function: has_skill
** Description: returns bool
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns bool
*********************************************************************/
bool Openspace::has_skill(){
    return this->skill;
}