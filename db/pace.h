#pragma once
#include "box.h"

namespace Tank {
class Building;
class Pace {
  public:
    Pace();
    ~Pace();

    auto setBox(Box* box) { box_ = box; };
    auto getBox() { return box_; };

    void setAssociateBuilding(Building* building);
    auto getAssociateBuilding() { return building_; };

  private:
    Box*      box_{nullptr};
    Building* building_{nullptr};
};

} // namespace Tank