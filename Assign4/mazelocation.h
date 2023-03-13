#ifndef MAZELOCATION_H
#define MAZELOCATION_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/*********************************************************************
** Program Filename: mazelocation.h
** Author: Connor Radding
** Date: 3/8/23
** Description: header file for the abstract class mazeloaction
** Input: none
** Output: virtual functions point to the coresponding child class
*********************************************************************/

class Mazelocation {
    public:
        Mazelocation();
        ~Mazelocation();

        virtual bool is_occupiable() = 0;
        virtual char get_display_character() = 0;

        virtual void set_has_student(bool) = 0;
        virtual void set_has_ta(bool) = 0;
        virtual void set_has_instructor(bool) = 0;
        virtual void set_has_skill(bool) = 0;

        virtual bool has_student() = 0;
        virtual bool has_ta() = 0;
        virtual bool has_instructor() = 0;
        virtual bool has_skill() = 0;
};



#endif