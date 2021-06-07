// file will contain functions that will handle the map generation

#include <iostream>
#include <fstream>

#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::ifstream;

// funciton that will read a map from the map directory
vector<vector<string>*>* generate_map(string filename)
{

    string mapName = "maps/";
    string mapLine = "";

    mapName.append(filename);

    // create a new vector 
    vector<vector<string>*>* map = new vector<vector<string>*>;

    // open a new file and read the characters into the file

    ifstream file(mapName);


    if(file.is_open())
    {
        while(getline(file, mapLine))
        {
            vector<string>* mLine = new vector<string>;

            mLine->push_back(mapLine);

            map->push_back(mLine);
        }
    }

    // close the file
    file.close();

    return map;
}

// function to display a map
void display_map(vector<vector<string>*>* map)
{
    
    for(long long unsigned i = 0; i < map->size(); i++)
    {
        vector<string>* first_vector = map->at(i);
        printf("%s\n", first_vector->at(0).c_str());
    }
}

// delete the old map from memory
void delete_map(vector<vector<string>*>* map)
{
    for(long long unsigned i = 0; i < map->size(); i++)
    {
        vector<string>* mapLine = map->at(i);

        delete mapLine;
    }

    delete map;
}

int numRows(vector<vector<string>*>* map)
{
    return map->size();
}