#pragma once

#include <string>

#include "box_creator.h"

class Player {
  public:
    Player(){};
    ~Player(){};

    auto setName(const char* name) { name_ = name; };
    auto Name() { return name_.c_str(); };
    auto setBox(Box* box) { box_ = box; };
    auto getBox() { return box_; };

  private:
    //player name
    std::string name_{"no name"};
    //associate to a pace box
    Box* box_{nullptr};
};

class PlayerCreator {

  public:
    PlayerCreator(/* args */){};
    ~PlayerCreator(){};

    auto createPlayer(const char* name, Box* box = nullptr) {
        auto player = new Player;
        player->setName(name);
        player->setBox(box);
        return player;
    }
};
