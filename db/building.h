#pragma once
#include "box.h"

namespace Tank {

class Player;

class Building {
  public:
    Building();
    ~Building();

    auto setBox(Box* box) {
        box_ = box;
        id_  = box_->ID();
    };
    auto getBox() { return box_; };
    void setOwner(Player* player);
    auto getOwner() { return owner_; };
    auto ID() { return id_; };

  private:
    Box*    box_{nullptr};
    Player* owner_{nullptr};
    int     id_{0};
};

} // namespace Tank