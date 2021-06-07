#include <iostream>
#include <vector>

#include "character.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;

using std::vector;

// funciton for creating a map found in map_generator.cpp
vector<vector<string>*>* generate_map(string filename);

// funciton for displaying a map found in map_generator.cpp
void display_map(vector<vector<string>*>* map);

// function for deleteing a map found in map_generator.cpp
void delete_map(vector<vector<string>*>* map);

// function to check if the game should be temrinated
// located in this file
bool check_terminate();

int main()
{
    vector<vector<string>*>* map;

    map = generate_map("level_1.txt");

    Character player(map);

    bool gameOn = true;

    player.add_character();

    while(gameOn)
    {
        system("cls");

        display_map(map);

        player.move_character();

        gameOn = check_terminate();
    }


    delete_map(map);

    map = NULL;

    return 0;
}

bool check_terminate()
{
    char key = _getch();

    if(key == (char)27)
    {
        return false;
    }

    return true;
}