#pragma once
#include "box.h"

namespace Tank {
class Building;
class Pace {
  public:
    Pace();
    ~Pace();

    auto setBox(Box* box) {
        box_ = box;
        id_  = box->ID();
    };
    auto getBox() { return box_; };

    void setAssociateBuilding(Building* building);
    auto getAssociateBuilding() { return building_; };

    auto ID() { return id_; };

  private:
    Box*      box_{nullptr};
    Building* building_{nullptr};
    int       id_{0};
};

} // namespace Tank