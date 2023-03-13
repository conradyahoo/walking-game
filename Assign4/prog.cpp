#include <iostream>
#include <string>
#include "game.h"
#include "mazeperson.h"

using namespace std;

/*********************************************************************
** Program Filename: prog.cpp
** Author: Connor Radding
** Date: 3/8/23
** Description: runs all of the neccessary functions for the game
** Input: none
** Output: outputs prompts for ai or manual and end game state prompts
*********************************************************************/

/*********************************************************************
** Function: main
** Description: the main function that runs the game
** Parameters: none
** Pre-Conditions: program starts
** Post-Conditions: finishes game
*********************************************************************/
int main(){

    Game game;

    // gets whether the student is an ai or the user
    char p;
    while(true){
        
        cout << "AI or manual play?(a/m): " << endl;
        cin >> p;

        if(p != 'a' && p != 'm'){

            cin.clear();
            cin.ignore();
            cout << "Error, try again" << endl;

            continue;
        }
        
        if(p == 'a'){
            game.set_ai(true);
            break;
        }
        if(p == 'm'){
            game.set_ai(false);
            break;
        }
    }

    //loads maze with openspace or wall
    game.load_maze();


    //spawn everyone within the maze
    game.spawn_instructor();

    game.spawn_tas();

    game.spawn_skills();

    game.spawn_student();

    while(true){
        
        //check skills around student
        game.check_skills();

        //check instructor around student
        if(game.check_instructor() == true){

            //if skills is less than 3 the user loses
            if(game.get_skills() < 3){
                
                game.display_maze();

                cout << "The Instructor has given you a failing grade!" << endl;
                return 1;
            }
            //if skills is 3 or more user wins
            else{

                game.display_maze();

                cout << "The Instructor has given you a passing grade!" << endl;
                return 2;
            }
        }
        
        //only checks if the appease timer is 0
        if(game.get_appease() == 0){

            //check tas and check skills to see if student can demonstrate
            if (game.check_tas_and_skill() == false){

                game.display_maze();

                cout << "The TA's caught you with no programmig skills!" << endl;
                return 3;
            }
        }

        //update maze to user
        game.display_maze();
    
        //if student is the user it gets the users move
        if(game.is_ai() == false){
            
            game.get_move();
        }
        //if the student is an ai it automotacly gets move
        if(game.is_ai() == true){

            game.move_ai();
        }
        
        //move all the tas
        game.move_ta1();
        game.move_ta2();
        game.move_ta3();

        //updates appease timer
        game.appease_timer();
    }

    return 0;
}