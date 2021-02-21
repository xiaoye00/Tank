#pragma once

#include <string>

#include "box.h"
namespace Tank {
class Player {
  public:
    Player(){};
    ~Player(){};

    auto setName(const char* name) { name_ = name; };
    auto Name() { return name_.c_str(); };
    auto setBox(Box* box) { box_ = box; };
    auto getBox() { return box_; };
    template <typename T>
    auto setOrient(T orient) { orient_ = (GoOrient)orient; };
    auto Orient() { return orient_; };
    auto setID(int id) { id_ = id; };
    auto ID() { return id_; };

  private:
    //player name
    std::string name_{"no name"};
    //associate to a pace box
    Box* box_{nullptr};
    //go orient
    GoOrient orient_;
    //player ID
    int id_{0};
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
} // namespace Tank