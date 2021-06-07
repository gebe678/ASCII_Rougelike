#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <conio.h>

using std::vector;
using std::string;

class Character
{
    private:

        // x and y coordinate
        int xValue;
        int yValue;

        // character symbol
        char symbol;

        vector<vector<string>*>* map;

    public:

        Character();

        Character(vector<vector<string>*>* map);

        Character(vector<vector<string>*>* map, int xValue, int yValue);

        Character(vector<vector<string>*>* map, int xValue, int yValue, char symbol);

        void add_character();
        void move_character();
        
};