#pragma once

#include <string>

#include "box.h"
#include "pace.h"
namespace tank {

void setCurrentPlayerID(int id);
int  getCurrentPlayerID();
int  getNextPlayerID();

class Player {
  public:
    Player(){};
    ~Player(){};

    auto setName(const char* name) { name_ = name; };
    auto Name() { return name_.c_str(); };
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
    auto setPace(Pace* pace) {
        pace_ = pace;
        box_  = pace_->getBox();
    };
    auto getPace() { return pace_; };
    auto setMoney(int money) { money_ = money; };
    auto Money() { return money_; };
    bool expend(int cost);

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
    //Pace
    Pace* pace_;
    //money
    int money_{0};
};

class PlayerCreator {

  public:
    PlayerCreator(/* args */){};
    ~PlayerCreator(){};

    auto createPlayer(const char* name) {
        auto player = new Player;
        player->setName(name);
        return player;
    }
};
} // namespace tank