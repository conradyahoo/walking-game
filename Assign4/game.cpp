#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include "game.h"

using namespace std;

/*********************************************************************
** Program Filename: game.cpp
** Author: Connor Radding
** Date: 3/8/23
** Description: This .ccp class file contains all the functions requirerd to run the game
** Input: None
** Output: returns various true or false based on the state of the game
*********************************************************************/

/*********************************************************************
** Function: Game()
** Description: constructor for game class
** Parameters: none
** Pre-Conditions: game object is made
** Post-Conditions: game object member variables populated
*********************************************************************/
Game::Game(){

    this->prog_skills = 0;
    this->ai == false;
    this->appease = 0;
    this->student = new Intrepidstudent;
    this->ta1 = new Ta;
    this->ta2 = new Ta;
    this->ta3 = new Ta;
    this->instructor = new Instructor;
}

/*********************************************************************
** Function: set_ai
** Description: sets whether the student is an ai or not
** Parameters: bool variable
** Pre-Conditions: function called
** Post-Conditions: sets ai true or false
*********************************************************************/
void Game::set_ai(bool b){

    this->ai = b;
}

/*********************************************************************
** Function: is_ai
** Description: return whether student is an ai or not
** Parameters: none
** Pre-Conditions: function called
** Post-Conditions: return true or false
*********************************************************************/
bool Game::is_ai(){

    return this->ai;
}

/*********************************************************************
** Function: start_appease_timer
** Description: starts the appease timer at 10 moves
** Parameters: none
** Pre-Conditions: student demonstrates skill
** Post-Conditions: appease counter started
*********************************************************************/
void Game::start_appease_timer(){

    this->appease = 10;
}

/*********************************************************************
** Function: get_appease
** Description: reuturns appease counter
** Parameters: none
** Pre-Conditions: functions called
** Post-Conditions: returns an int of the appease counter
*********************************************************************/
int Game::get_appease(){

    return this->appease;
}

/*********************************************************************
** Function: appease_timer
** Description: if the appease counter is more than 0 it subtracts 1
** Parameters: none
** Pre-Conditions: appease counter has started
** Post-Conditions: -1 appease counter
*********************************************************************/
void Game::appease_timer(){

    if(this->appease > 0){

        this->appease -= 1;
    }
}

/*********************************************************************
** Function: move_ai
** Description: moves the student ai randomly
** Parameters: none
** Pre-Conditions: user has stated they want the ai to play
** Post-Conditions: student is moved by computer
*********************************************************************/
void Game::move_ai(){

    srand(time(0));

    //0 = w, 1 = a, 2 = s, 3 = d
    int move;

    while(1){

        move = rand() % 4;

        //checks if student is trying to move out of bounds
        if (move == 0 && this->student->get_row() == 0){
            continue;
        }
        if (move == 1 && this->student->get_col() == 0){
            continue;
        }
        if (move == 2 && this->student->get_row() == this->maze.get_row() - 1){
            continue;
        }
        if (move == 3 && this->student->get_col() == this->maze.get_col() - 1){
            continue;
        }
        
        //if the location above it is occupiable it sets new student location
        if (move == 0 && this->maze.get_location(this->student->get_row() - 1, this->student->get_col())->is_occupiable()){
            
            // sets old space as false and new location as true
            this->maze.get_location(this->student->get_row(), this->student->get_col())->set_has_student(false);
            this->maze.get_location(this->student->get_row() - 1, this->student->get_col())->set_has_student(true);

            this->student->set_location(this->student->get_row() - 1, this->student->get_col());

            break;
        }
        //if location to the left is occupiable, it sets new student location
        if (move == 1 && this->maze.get_location(this->student->get_row(), this->student->get_col() - 1)->is_occupiable()){
            
            // sets old space as false and new location as true
            this->maze.get_location(this->student->get_row(), this->student->get_col())->set_has_student(false);
            this->maze.get_location(this->student->get_row(), this->student->get_col() - 1)->set_has_student(true);

            this->student->set_location(this->student->get_row(), this->student->get_col() - 1);

            break;
        }
        //if location bellow it is occupiable, it sets new student location
        if (move == 2 && this->maze.get_location(this->student->get_row() + 1, this->student->get_col())->is_occupiable()){
            
            // sets old space as false and new location as true
            this->maze.get_location(this->student->get_row(), this->student->get_col())->set_has_student(false);
            this->maze.get_location(this->student->get_row() + 1, this->student->get_col())->set_has_student(true);

            this->student->set_location(this->student->get_row() + 1, this->student->get_col());

            break;
        }
        //if location to the right of it is occupiable, it sets new student location
        if (move == 3 && this->maze.get_location(this->student->get_row(), this->student->get_col() + 1)->is_occupiable()){
            
            // sets old space as false and new location as true
            this->maze.get_location(this->student->get_row(), this->student->get_col())->set_has_student(false);
            this->maze.get_location(this->student->get_row(), this->student->get_col() + 1)->set_has_student(true);

            this->student->set_location(this->student->get_row(), this->student->get_col() + 1);

            break;
        }

        continue;
    }
}

/*********************************************************************
** Function: move_ta3
** Description: moves ta3 randomly
** Parameters: none
** Pre-Conditions: function called
** Post-Conditions: ta3 is moved
*********************************************************************/
void Game::move_ta3(){

    //0 = w, 1 = a, 2 = s, 3 = d
    int move;

    while(1){

        move = rand() % 4;

        //checks if ta3 is trying to move out of bounds
        if (move == 0 && this->ta3->get_row() == 0){
            continue;
        }
        if (move == 1 && this->ta3->get_col() == 0){
            continue;
        }
        if (move == 2 && this->ta3->get_row() == this->maze.get_row() - 1){
            continue;
        }
        if (move == 3 && this->ta3->get_col() == this->maze.get_col() - 1){
            continue;
        }
        
        //if the move location is occupiable it sets new ta3 location
        if (move == 0 && this->maze.get_location(this->ta3->get_row() - 1, this->ta3->get_col())->is_occupiable()){
            
            this->maze.get_location(this->ta3->get_row(), this->ta3->get_col())->set_has_ta(false);
            this->maze.get_location(this->ta3->get_row() - 1, this->ta3->get_col())->set_has_ta(true);

            this->ta3->set_location(this->ta3->get_row() - 1, this->ta3->get_col());

            break;
        }
        //if the move location is occupiable it sets new ta3 location
        if (move == 1 && this->maze.get_location(this->ta3->get_row(), this->ta3->get_col() - 1)->is_occupiable()){
            
            this->maze.get_location(this->ta3->get_row(), this->ta3->get_col())->set_has_ta(false);
            this->maze.get_location(this->ta3->get_row(), this->ta3->get_col() - 1)->set_has_ta(true);

            this->ta3->set_location(this->ta3->get_row(), this->ta3->get_col() - 1);

            break;
        }
        //if the move location is occupiable it sets new ta3 location
        if (move == 2 && this->maze.get_location(this->ta3->get_row() + 1, this->ta3->get_col())->is_occupiable()){
            
            this->maze.get_location(this->ta3->get_row(), this->ta3->get_col())->set_has_ta(false);
            this->maze.get_location(this->ta3->get_row() + 1, this->ta3->get_col())->set_has_ta(true);

            this->ta3->set_location(this->ta3->get_row() + 1, this->ta3->get_col());

            break;
        }
        //if the move location is occupiable it sets new ta3 location
        if (move == 3 && this->maze.get_location(this->ta3->get_row(), this->ta3->get_col() + 1)->is_occupiable()){
            
            this->maze.get_location(this->ta3->get_row(), this->ta3->get_col())->set_has_ta(false);
            this->maze.get_location(this->ta3->get_row(), this->ta3->get_col() + 1)->set_has_ta(true);

            this->ta3->set_location(this->ta3->get_row(), this->ta3->get_col() + 1);

            break;
        }

        continue;
    }
}

/*********************************************************************
** Function: move_ta2
** Description: moves ta2 randomly
** Parameters: none
** Pre-Conditions: function called
** Post-Conditions: ta2 is moved
*********************************************************************/
void Game::move_ta2(){

    //0 = w, 1 = a, 2 = s, 3 = d
    int move;

    while(1){

        move = rand() % 4;

        //checks if ta2 is trying to move out of bounds
        if (move == 0 && this->ta2->get_row() == 0){
            continue;
        }
        if (move == 1 && this->ta2->get_col() == 0){
            continue;
        }
        if (move == 2 && this->ta2->get_row() == this->maze.get_row() - 1){
            continue;
        }
        if (move == 3 && this->ta2->get_col() == this->maze.get_col() - 1){
            continue;
        }
        
        //if the move location is occupiable it sets new ta2 location
        if (move == 0 && this->maze.get_location(this->ta2->get_row() - 1, this->ta2->get_col())->is_occupiable()){
            
            this->maze.get_location(this->ta2->get_row(), this->ta2->get_col())->set_has_ta(false);
            this->maze.get_location(this->ta2->get_row() - 1, this->ta2->get_col())->set_has_ta(true);

            this->ta2->set_location(this->ta2->get_row() - 1, this->ta2->get_col());

            break;
        }
        //if the move location is occupiable it sets new ta2 location
        if (move == 1 && this->maze.get_location(this->ta2->get_row(), this->ta2->get_col() - 1)->is_occupiable()){
            
            this->maze.get_location(this->ta2->get_row(), this->ta2->get_col())->set_has_ta(false);
            this->maze.get_location(this->ta2->get_row(), this->ta2->get_col() - 1)->set_has_ta(true);

            this->ta2->set_location(this->ta2->get_row(), this->ta2->get_col() - 1);

            break;
        }
        //if the move location is occupiable it sets new ta2 location
        if (move == 2 && this->maze.get_location(this->ta2->get_row() + 1, this->ta2->get_col())->is_occupiable()){
            
            this->maze.get_location(this->ta2->get_row(), this->ta2->get_col())->set_has_ta(false);
            this->maze.get_location(this->ta2->get_row() + 1, this->ta2->get_col())->set_has_ta(true);

            this->ta2->set_location(this->ta2->get_row() + 1, this->ta2->get_col());

            break;
        }
        //if the move location is occupiable it sets new ta2 location
        if (move == 3 && this->maze.get_location(this->ta2->get_row(), this->ta2->get_col() + 1)->is_occupiable()){
            
            this->maze.get_location(this->ta2->get_row(), this->ta2->get_col())->set_has_ta(false);
            this->maze.get_location(this->ta2->get_row(), this->ta2->get_col() + 1)->set_has_ta(true);

            this->ta2->set_location(this->ta2->get_row(), this->ta2->get_col() + 1);

            break;
        }

        continue;
    }
}

/*********************************************************************
** Function: move_ta1
** Description: moves ta1 randomly
** Parameters: none
** Pre-Conditions: function called
** Post-Conditions: ta1 is moved
*********************************************************************/
void Game::move_ta1(){

    //0 = w, 1 = a, 2 = s, 3 = d
    int move;

    while(1){

        move = rand() % 4;

        //checks if ta1 is trying to move out of bounds
        if (move == 0 && this->ta1->get_row() == 0){
            continue;
        }
        if (move == 1 && this->ta1->get_col() == 0){
            continue;
        }
        if (move == 2 && this->ta1->get_row() == this->maze.get_row() - 1){
            continue;
        }
        if (move == 3 && this->ta1->get_col() == this->maze.get_col() - 1){
            continue;
        }
        
        //if the move location is occupiable it sets new ta1 location
        if (move == 0 && this->maze.get_location(this->ta1->get_row() - 1, this->ta1->get_col())->is_occupiable()){
            
            this->maze.get_location(this->ta1->get_row(), this->ta1->get_col())->set_has_ta(false);
            this->maze.get_location(this->ta1->get_row() - 1, this->ta1->get_col())->set_has_ta(true);

            this->ta1->set_location(this->ta1->get_row() - 1, this->ta1->get_col());

            break;
        }
        //if the move location is occupiable it sets new ta1 location
        if (move == 1 && this->maze.get_location(this->ta1->get_row(), this->ta1->get_col() - 1)->is_occupiable()){
            
            this->maze.get_location(this->ta1->get_row(), this->ta1->get_col())->set_has_ta(false);
            this->maze.get_location(this->ta1->get_row(), this->ta1->get_col() - 1)->set_has_ta(true);

            this->ta1->set_location(this->ta1->get_row(), this->ta1->get_col() - 1);

            break;
        }
        //if the move location is occupiable it sets new ta1 location
        if (move == 2 && this->maze.get_location(this->ta1->get_row() + 1, this->ta1->get_col())->is_occupiable()){
            
            this->maze.get_location(this->ta1->get_row(), this->ta1->get_col())->set_has_ta(false);
            this->maze.get_location(this->ta1->get_row() + 1, this->ta1->get_col())->set_has_ta(true);

            this->ta1->set_location(this->ta1->get_row() + 1, this->ta1->get_col());

            break;
        }
        //if the move location is occupiable it sets new ta1 location
        if (move == 3 && this->maze.get_location(this->ta1->get_row(), this->ta1->get_col() + 1)->is_occupiable()){
            
            this->maze.get_location(this->ta1->get_row(), this->ta1->get_col())->set_has_ta(false);
            this->maze.get_location(this->ta1->get_row(), this->ta1->get_col() + 1)->set_has_ta(true);

            this->ta1->set_location(this->ta1->get_row(), this->ta1->get_col() + 1);

            break;
        }

        continue;
    }
}

/*********************************************************************
** Function: get_move()
** Description: gets the move from the user and moves student
** Parameters: none
** Pre-Conditions: function called and student spawned
** Post-Conditions: student is moved to new location
*********************************************************************/
void Game::get_move(){

    string move;

    //gets move from user and error checks only wasd input
    while(true){

        while(true){
            
            cout << "Enter move(wasd): " << endl;
            cin >> move;

            if (move != "w" && move != "a" && move != "s" && move != "d"){

                cout << "Error, enter a valid move" << endl;

                cin.clear();
                cin.ignore();

                continue;
            }

            break;
        }

        //checks if student is trying to move out of bounds
        if (move == "w" && this->student->get_row() == 0){
            continue;
        }
        if (move == "a" && this->student->get_col() == 0){
            continue;
        }
        if (move == "s" && this->student->get_row() == this->maze.get_row() - 1){
            continue;
        }
        if (move == "d" && this->student->get_col() == this->maze.get_col() - 1){
            continue;
        }
        
        //if the move location is occupiable it sets new student location
        if (move == "w" && this->maze.get_location(this->student->get_row() - 1, this->student->get_col())->is_occupiable()){
            
            this->maze.get_location(this->student->get_row(), this->student->get_col())->set_has_student(false);
            this->maze.get_location(this->student->get_row() - 1, this->student->get_col())->set_has_student(true);

            this->student->set_location(this->student->get_row() - 1, this->student->get_col());

            break;
        }
        //if the move location is occupiable it sets new student location
        if (move == "a" && this->maze.get_location(this->student->get_row(), this->student->get_col() - 1)->is_occupiable()){
            
            this->maze.get_location(this->student->get_row(), this->student->get_col())->set_has_student(false);
            this->maze.get_location(this->student->get_row(), this->student->get_col() - 1)->set_has_student(true);

            this->student->set_location(this->student->get_row(), this->student->get_col() - 1);

            break;
        }
        //if the move location is occupiable it sets new student location
        if (move == "s" && this->maze.get_location(this->student->get_row() + 1, this->student->get_col())->is_occupiable()){
            
            this->maze.get_location(this->student->get_row(), this->student->get_col())->set_has_student(false);
            this->maze.get_location(this->student->get_row() + 1, this->student->get_col())->set_has_student(true);

            this->student->set_location(this->student->get_row() + 1, this->student->get_col());

            break;
        }
        //if the move location is occupiable it sets new student location
        if (move == "d" && this->maze.get_location(this->student->get_row(), this->student->get_col() + 1)->is_occupiable()){
            
            this->maze.get_location(this->student->get_row(), this->student->get_col())->set_has_student(false);
            this->maze.get_location(this->student->get_row(), this->student->get_col() + 1)->set_has_student(true);

            this->student->set_location(this->student->get_row(), this->student->get_col() + 1);

            break;
        }

        continue;
    }
}

/*********************************************************************
** Function: display_maze
** Description: calles the maze class print_maze function with skills and appease counter
** Parameters: none
** Pre-Conditions: functions called
** Post-Conditions: maze is printed to user
*********************************************************************/
void Game::display_maze(){

    this->maze.print_maze(this->prog_skills, this->appease);
}

/*********************************************************************
** Function: demonstrate_skill
** Description: prompts the player to demonstrate skill and error checks input
** Parameters: none
** Pre-Conditions: student is caught by the ta and has a skill
** Post-Conditions: player succesfully types p
*********************************************************************/
void Game::demonstrate_skill(){

    string demo;

    cout << "The TA caught you! ";

    while(1){
        
        if (this->ai == false){
            
            cout << "Demonstrate a programming skill(p): " << endl;
            cin.clear();
            cin.ignore();
            cin >> demo;
        }
        else{
            
            cout << "Demonstrate a programming skill(p): p" << endl;

            demo = "p";
        }

        if (demo != "p"){

            cout << "you kinda have to or you lose, try again" << endl;

            continue;
        }
        else{

            break;
        }
    }
}


/*********************************************************************
** Function: check_tas_and_skill
** Description: the function checks around the available ajacent spaces of student and checks if there is a ta
** Parameters: none
** Pre-Conditions: game has started
** Post-Conditions: returns true if player demonstrates skill and false if player doesn't have any skills
*********************************************************************/
//returns true if player demonstrates skill and false if player doesn't have any skills
bool Game::check_tas_and_skill(){

    //loops through all the ajacent blocks and checks for ta
    for (int i = -1; i < 2; i++){ //starts at the bottom row and goes up
        
        for (int j = -1; j < 2; j++){
            
            // checks if the the ajacent space is in the maze or out of bounds
            if (this->student->get_row() - i >= 0 && this->student->get_row() - i <= maze.get_row() - 1 && this->student->get_col() - j >= 0 && this->student->get_col() - j <= maze.get_col() - 1){

                //checks if the ajacent space has a ta
                if (this->maze.get_location(this->student->get_row() - i, this->student->get_col() - j)->has_ta()){

                    //if they have a programming skill it demonstrates skill and starts the timer
                    if (prog_skills != 0){

                        display_maze();

                        demonstrate_skill();

                        this->prog_skills -= 1;

                        start_appease_timer();

                        return true;
                    }
                    
                    else{

                        //with no skills it returns false
                        return false;
                    }
                }
            }
        }
    }
    //if no tas return true
    return true;
}

/*********************************************************************
** Function: check_instructor
** Description: checks the ajacent student spaces for the instructor
** Parameters: none
** Pre-Conditions: function called
** Post-Conditions: returns true if instructor is there and false if they aren't
*********************************************************************/
bool Game::check_instructor(){

    //loops through all the ajacent blocks and checks for instructor
    for (int i = -1; i < 2; i++){ //starts at the bottom row and goes up

        for (int j = -1; j < 2; ++j){

            int temp_row = this->student->get_row() - i;
            int temp_col = this->student->get_col() - j;

            //checks if space is within the bounds of the maze
            if (temp_row >= 0 && temp_row <= maze.get_row() - 1 && temp_col >= 0 && temp_col <= maze.get_col() - 1){

                //if the instructor is found returns true
                if (this->maze.get_location(temp_row, temp_col)->has_instructor()){
                    
                    return true;
                }
            }
        }
    }
    //if no instructor returns false
    return false;
}

/*********************************************************************
** Function: check_skills
** Description: checks if the student is in the same space as a skill
** Parameters: none
** Pre-Conditions: game has started
** Post-Conditions: if the skill is found student earns +1 skill
*********************************************************************/
void Game::check_skills(){

    // if skill is found in same space it removes the skill from space and adds +1 skill to student
    if (this->maze.get_location(this->student->get_row(), this->student->get_col())->has_skill()){

        this->prog_skills += 1;

        this->maze.get_location(this->student->get_row(), this->student->get_col())->set_has_skill(false);
    }
}

/*********************************************************************
** Function: spawn_student
** Description: spawns the student to a random space in the maze
** Parameters: none
** Pre-Conditions: student object exists
** Post-Conditions: student gets a location in the maze
*********************************************************************/
void Game::spawn_student(){

    int temp_row;
    int temp_col;

    while(1){

        //gets random maze location
        temp_row = rand() % this->maze.get_row();
        temp_col = rand() % this->maze.get_col();

        //if the space is occupiable
        if (this->maze.get_location(temp_row, temp_col)->is_occupiable()){

            //if the space doesn't have the instructor
            if (this->maze.get_location(temp_row, temp_col)->has_instructor() == false){

                //if the space doesn't have a ta
                if (this->maze.get_location(temp_row, temp_col)->has_ta() == false){
                
                    //if all conditions met sets students location
                    this->student->set_location(temp_row, temp_col);
                    this->maze.get_location(temp_row, temp_col)->set_has_student(true);

                    break;
                }
            }
        }
    }
}

/*********************************************************************
** Function: spawn_skills
** Description: spawns 6 skills within the maze
** Parameters: none
** Pre-Conditions: function called
** Post-Conditions: spawns six skills in the maze
*********************************************************************/
void Game::spawn_skills(){

    int temp_row;
    int temp_col;

    //runs 6 times
    for (int i = 0; i < 6; i++){

        while(1){

            // gets random location
            temp_row = rand() % this->maze.get_row();
            temp_col = rand() % this->maze.get_col();

            //if location is occupiable
            if (this->maze.get_location(temp_row, temp_col)->is_occupiable()){
                
                //if location doesn't have instructor
                if (this->maze.get_location(temp_row, temp_col)->has_instructor() == false){
                    
                    //sets the location
                    this->maze.get_location(temp_row, temp_col)->set_has_skill(true);
                    
                    break;
                }
            }
        }
    }
}

/*********************************************************************
** Function: spawn_tas
** Description: spawns 3 tas within the maze
** Parameters: none
** Pre-Conditions: functions called
** Post-Conditions: spawns all tas in the maze
*********************************************************************/
void Game::spawn_tas(){

    int temp_row;
    int temp_col;

    while(1){

        //gets random location
        temp_row = rand() % this->maze.get_row();
        temp_col = rand() % this->maze.get_col();

        //if location is occupiable
        if (this->maze.get_location(temp_row, temp_col)->is_occupiable()){

            //if location doesn't have instructor
            if (this->maze.get_location(temp_row, temp_col)->has_instructor() == false){
                
                //sets location
                this->ta1->set_location(temp_row, temp_col);
                this->maze.get_location(temp_row, temp_col)->set_has_ta(true);

                break;
            }
        }
    }

    while(1){

        //gets random location
        temp_row = rand() % this->maze.get_row();
        temp_col = rand() % this->maze.get_col();

        //if location is occupiable
        if (this->maze.get_location(temp_row, temp_col)->is_occupiable()){

            //if location doesn't have instructor
            if (this->maze.get_location(temp_row, temp_col)->has_instructor() == false){
                
                //sets location
                this->ta2->set_location(temp_row, temp_col);
                this->maze.get_location(temp_row, temp_col)->set_has_ta(true);

                break;
            }
        }
    }

    while(1){

        //gets random location
        temp_row = rand() % this->maze.get_row();
        temp_col = rand() % this->maze.get_col();

        //if location is occupiable
        if (this->maze.get_location(temp_row, temp_col)->is_occupiable()){

            //if location doesn't have instructor
            if (this->maze.get_location(temp_row, temp_col)->has_instructor() == false){
                
                //sets location
                this->ta3->set_location(temp_row, temp_col);
                this->maze.get_location(temp_row, temp_col)->set_has_ta(true);

                break;
            }
        }
    }
}

/*********************************************************************
** Function: spawn_instructor
** Description: spawns the instructor within the maze
** Parameters: none
** Pre-Conditions: function called
** Post-Conditions: spawns instructor
*********************************************************************/
void Game::spawn_instructor(){

    srand(time(0));

    int temp_row;
    int temp_col;

    while(true){

        //gets random location
        temp_row = rand() % this->maze.get_row();
        temp_col = rand() % this->maze.get_col();

        //if location is occupiable
        if (this->maze.get_location(temp_row, temp_col)->is_occupiable()){

            //sets instructor location
            this->instructor->set_location(temp_row, temp_col);
            this->maze.get_location(temp_row, temp_col)->set_has_instructor(true);

            break;
        }
    }
}

/*********************************************************************
** Function: load_maze
** Description: loads the maze with open spaces and walls with user inputed size
** Parameters: none
** Pre-Conditions: function called
** Post-Conditions: loads maze with spaces
*********************************************************************/
void Game::load_maze(){

    int row, col;

    // gets row size for maze
    while(1){
        
        cout << "row size for maze (min 5): " << endl;
        cin >> row;

        if(!cin.good() || row < 5){

            cout << "Error, enter a valid positive integer greater or equal to 5\n\n";
            continue;
        }

        break;
    }

    //gets col size for maze
    while(1){
        cout << "collum size for maze (min 5): " << endl;
        cin >> col;

        if(!cin.good() || col < 5){

            cout << "Error, enter a valid positive integer greater or equal to 5\n\n";
            continue;
        }

        break;
    }

    //sets the row and col size in the maze class
    this->maze.set_row(row);
    this->maze.set_col(col);

    //loads the maze vector
    this->maze.load_vector();
}

/*********************************************************************
** Function: get_skills
** Description: returns number of skills user has
** Parameters: none
** Pre-Conditions: function called
** Post-Conditions: return an int
*********************************************************************/
int Game::get_skills(){

    return this->prog_skills;
}