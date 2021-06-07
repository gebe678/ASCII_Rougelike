#include "character.h"

Character::Character()
{
    this->map = NULL;

    this->xValue = 0;
    this->yValue = 0;

    this->symbol = '\0';
}

Character::Character(vector<vector<string>*>* map)
{
    this->map = map;

    this->xValue = 1;
    this->yValue = 1;

    this->symbol = '@';
}

Character::Character(vector<vector<string>*>* map, int xValue, int yValue)
{
    this->map = map;

    this->xValue = xValue;
    this->yValue = yValue;

    this->symbol = '@';
}

Character::Character(vector<vector<string>*>* map, int xValue, int yValue, char symbol)
{
    this->map = map;

    this->xValue = xValue;
    this->yValue = yValue;

    this->symbol = symbol;
}

void Character::add_character()
{
    vector<string>* line = this->map->at(yValue);

    string theLine = line->at(0);

    theLine[xValue] = this->symbol;

    line->at(0) = theLine;
}

void Character::move_character()
{
    char key = _getch();

    bool atTop = false;
    bool atBottom = false;

    if(this->yValue == 1)
    {
        atTop = true;
    }
    else if(this->yValue == (int)map->size() - 2)
    {
        atBottom = true;
    }

    vector<string>* above = NULL;
    vector<string>* below = NULL;
    vector<string>* current = NULL;

    string aboveStr = "";
    string belowStr = "";
    string currentStr = "";

    if(!atTop)
    {
        above = map->at(this->yValue - 1);
        aboveStr = above->at(0);
    }

    if(!atBottom)
    {
        below = map->at(this->yValue + 1);
        belowStr = below->at(0);
    }

    current = map->at(yValue);
    currentStr = current->at(0);

    switch(key)
    {
        case 'd':
            

            break;
        
        case 's':
            std:: cout << "in s" << std::endl;
            if(!atBottom)
            {
                currentStr[xValue] = ' ';
                belowStr[xValue] = this->symbol;

                current->at(0) = currentStr;
                below->at(0) = belowStr;
            }

            break;

        case 'a':

            break;

        case 'w':

            break;
    }
}
