#pragma once

#include <string>

class PlayerCreator
{

public:
    PlayerCreator(/* args */);
    ~PlayerCreator();

private:
//player name
std::string name_{"no name"};
//associate to a pace box
int pos_{0};
};


