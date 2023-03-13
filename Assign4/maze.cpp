#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include "maze.h"

using namespace std;

/*********************************************************************
** Program Filename: maze.cpp
** Author: Connor Radding
** Date: 3/8/23
** Description: this class holds all the functions for the maze class
** Input: setters set the maze size
** Output: outputs maze locations and prints the maze to the user
*********************************************************************/

/*********************************************************************
** Function: Maze()
** Description: constructor
** Parameters: none
** Pre-Conditions: maze object created
** Post-Conditions: sets member variables
*********************************************************************/
Maze::Maze(){

    this->row = -1;
    this->row = -1;

}

/*********************************************************************
** Function: load_vector
** Description: loads the 2D maze vector with openspace and wall objects
** Parameters: none
** Pre-Conditions: function called
** Post-Conditions: creates 2D vector with 4 wall obects and the rest openspace objects
*********************************************************************/
void Maze::load_vector(){

    srand(time(0));

    //gets four random locations for the 4 walls
    int temp_row1 = rand() % this->row;
    int temp_col1 = rand() % this->col;
    int temp_row2 = rand() % this->row;
    int temp_col2 = rand() % this->col;
    int temp_row3 = rand() % this->row;
    int temp_col3 = rand() % this->col;
    int temp_row4 = rand() % this->row;
    int temp_col4 = rand() % this->col;

    srand(time(0));

    //runs for row size
    for (int i = 0; i < this->row; i++){
        
        //1d vector
        vector<Mazelocation*> row_vec;
        
        //runs for col size
        for (int j = 0; j < this->col; j++){
            
            //if the random wall locations match the vector space it fills that location with a wall
            if(temp_row1 == i && temp_col1 == j){

                row_vec.push_back(new Wall);
            }
            else if(temp_row2 == i && temp_col2 == j){

                row_vec.push_back(new Wall);
            }
            else if(temp_row3 == i && temp_col3 == j){

                row_vec.push_back(new Wall);
            }
            else if(temp_row4 == i && temp_col4 == j){

                row_vec.push_back(new Wall);
            }
            else{
                //if no matches it is an openspace
                row_vec.push_back(new Openspace);
            }
        }
        
        this->locations.push_back(row_vec);
    }
}

/*********************************************************************
** Function: operator=
** Description: AOO
** Parameters: old Maze object
** Pre-Conditions: need to create new object with old object
** Post-Conditions: returns a new maze by reference
*********************************************************************/
Maze& Maze::operator=(const Maze& old_m){

    this->row = old_m.row;
	this->col = old_m.col;

	//free memory first
	if (this->locations.empty() == false){
		
        for (int i = 0; i < this->row; i++){

            for (int j = 0; j < this->col; j++){

                delete locations[i][j];
            }    
            
            locations.clear();
        }
	}
	//deep copy
	for (int i = 0; i < this->row; ++i){
        
        vector<Mazelocation*> row_vec;

        for (int j = 0; j < this->col; ++j){
            
            row_vec.push_back(old_m.locations[i][j]);
        }
        
        this->locations.push_back(row_vec);
	}
	
	return *this;
}

/*********************************************************************
** Function: Maze()
** Description: copy constructor
** Parameters: old maze object
** Pre-Conditions: need to create new object with old one
** Post-Conditions: creates new maze object
*********************************************************************/
//copy constructor
Maze::Maze(const Maze& old_m){

	this->row = old_m.row;
	this->col = old_m.col;

	//deep copy

	for (int i = 0; i < this->row; ++i){
        
        vector<Mazelocation*> row_vec;

        for (int j = 0; j < this->col; ++j){
            
            row_vec.push_back(old_m.locations[i][j]);
        }
        
        this->locations.push_back(row_vec);
	}
}

/*********************************************************************
** Function: ~Maze
** Description: destructor
** Parameters: none
** Pre-Conditions: maze object goes out of scope
** Post-Conditions: deletes all dynamic memory in 2D vector
*********************************************************************/
Maze::~Maze(){

    for (int i = 0; i < this->row; i++){

        for (int j = 0; j < this->col; j++){

            delete locations[i][j];
        }    
        
        locations.clear();
    }
}

/*********************************************************************
** Function: print_maze
** Description: prints maze to user
** Parameters: skills and appease counter
** Pre-Conditions: maze is populated
** Post-Conditions: prints maze
*********************************************************************/
void Maze::print_maze(int skills, int appease){

    cout << "Programming Skills: " << skills << "    Appease timer: "<< appease <<endl;

    //runs for row size
    for (int i = 0; i < this->row; i++){

        //runs for col size
        for (int j = 0; j < this->col; j++){

            //top layer of maze
            cout << "+-----";
        }
        cout << "+\n";
        
        for (int j = 0; j < this->col; j++){

            //if has student
            if (this->locations[i][j]->has_student()){
                cout << "|  " << "*" << "  ";
            }
            //if has ta
            else if (this->locations[i][j]->has_ta()){
                cout << "|  " << "T" << "  ";
            }
            //if has instructor
            else if (this->locations[i][j]->has_instructor()){
                cout << "|  " << "%" << "  ";
            }
            //if has nothing in it print wall or open space char
            else{
                cout << "|  " << this->locations[i][j]->get_display_character() << "  ";
            }
        }
        cout << "|\n";

        for (int j = 0; j < this->col; j++){

            //if location has both student and ta print ta under student
            if (this->locations[i][j]->has_student() && this->locations[i][j]->has_ta()){
                cout << "|  " << "T" << "  ";
            }
            //if has a skill
            if (this->locations[i][j]->has_skill()){
                cout << "|  " << "$" << "  ";
            }
            //if has nothing
            else {
                cout << "|  " << this->locations[i][j]->get_display_character() << "  ";
            }
        }
        cout << "|\n";
    }

    for (int j = 0; j < this->col; j++){
            //bottom row of maze
            cout << "+-----";
        }
    cout << "+" << endl;
}

/*********************************************************************
** Function: get_location
** Description: return specified location
** Parameters: row and col
** Pre-Conditions: function called for many reasons
** Post-Conditions: returns a mazelocation pointer
*********************************************************************/
Mazelocation* Maze::get_location(int r, int c){

    return this->locations[r][c];
}

/*********************************************************************
** Function: set_row
** Description: sets row size
** Parameters: row int
** Pre-Conditions: user inputed how big they want the maze to be
** Post-Conditions: sets row size
*********************************************************************/
void Maze::set_row(int r){

    this->row = r;
}

/*********************************************************************
** Function: set_col
** Description: sets col size
** Parameters: col int
** Pre-Conditions: user inputed how big they want the maze
** Post-Conditions: sets col
*********************************************************************/
void Maze::set_col(int c){

    this->col = c;
}

/*********************************************************************
** Function: get_row
** Description: returns row size
** Parameters: none
** Pre-Conditions: function called
** Post-Conditions: returns row int
*********************************************************************/
int Maze::get_row(){

    return this->row;
}

/*********************************************************************
** Function: get_col
** Description: returns col size
** Parameters: none
** Pre-Conditions: function called
** Post-Conditions: returns col int
*********************************************************************/
int Maze::get_col(){

    return this->col;
}