#pragma once
#include "box.h"

namespace Tank {

class Player;

class Building {
  public:
    Building();
    ~Building();

    auto setBox(Box* box) { box_ = box; };
    auto getBox() { return box_; };
    void setOwner(Player* player);
    auto getOwner(){return owner_;};

  private:
    Box*    box_{nullptr};
    Player* owner_{nullptr};
};

} // namespace Tank