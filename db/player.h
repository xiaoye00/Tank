#pragma once

#include <string>

#include "box.h"
namespace Tank {

void setCurrentPlayerID(int id);
int  getCurrentPlayerID();
int  getNextPlayerID();

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
    auto setRunSteps(int steps) { run_steps_ = steps; };
    auto RunSteps() { return &run_steps_; };
    auto setPosition(int pos) { position_ = pos; };
    auto Position() { return position_; };
    auto setColor(std::string color) { color_ = color; };
    auto Color() { return color_; };

  private:
    //player name
    std::string name_{"no name"};
    //associate to a pace box
    Box* box_{nullptr};
    //go orient
    GoOrient orient_;
    //player ID
    int id_{0};
    // run steps
    int run_steps_{0};
    // position
    int position_{0};
    // color
    std::string color_;
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