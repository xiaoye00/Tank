#pragma once

#include <string>

class Player {
  public:
    Player(){};
    ~Player(){};

    auto setName(const char* name) { name_ = name; };
    auto Name() { return name_.c_str(); };
    auto setPos(int pos) { pos_ = pos; };
    auto Pos() { return pos_; };

  private:
    //player name
    std::string name_{"no name"};
    //associate to a pace box
    int pos_{0};
};

class PlayerCreator {

  public:
    PlayerCreator(/* args */){};
    ~PlayerCreator(){};

    auto createPlayer(const char* name, int pos = 0) {
        Player player;
        player.setName(name);
        player.setPos(pos);
        return player;
    }
};
