#include <iostream>
#include <string>
#include <fstream>
#include "intrepidstudent.h"

using namespace std;

/*********************************************************************
** Program Filename: intrepidstudent.cpp
** Author: Connor Radding
** Date: 3/8/23
** Description: this holds all the functions for the intrepidstudent class
** Input: setters set the row and col of the student
** Output: returns a move char and the location of the student
*********************************************************************/

/*********************************************************************
** Function: intrepidstudent
** Description: constructor
** Parameters: none
** Pre-Conditions: student object created
** Post-Conditions: sets member variables with an int
*********************************************************************/
Intrepidstudent::Intrepidstudent(){
    
    this->row = -1;
    this->col = -1;
}

/*********************************************************************
** Function: get_move
** Description: gets a move from the user and if valid returns it
** Parameters: none
** Pre-Conditions: student is in the maze and ready to move
** Post-Conditions: returns a wasd char
*********************************************************************/
char Intrepidstudent::get_move(){

    char move;
    while(1){
        
        cout << "Move: " << endl;
        cin >> move;
        
        if (move != 'w' || move != 'a' ||move != 's' ||move != 'd'){
            
            cin.clear();
            cin.ignore();
            cout << "Invalid input" << endl;
            continue;
        }
        else{
            
            return move;
        }
    }
}

/*********************************************************************
** Function: set_location
** Description: sets student location
** Parameters: row and col int
** Pre-Conditions: function called
** Post-Conditions: sets location
*********************************************************************/
void Intrepidstudent::set_location(int r, int c){

    this->row = r;
    this->col = c;
}

/*********************************************************************
** Function: get_row
** Description: returns row
** Parameters: none
** Pre-Conditions: function called
** Post-Conditions: returns row
*********************************************************************/
int Intrepidstudent::get_row(){

    return this->row;
}

/*********************************************************************
** Function: get_col
** Description: returns col
** Parameters: none
** Pre-Conditions: function called
** Post-Conditions: returns col
*********************************************************************/
int Intrepidstudent::get_col(){

    return this->col;
}