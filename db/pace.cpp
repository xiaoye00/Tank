#include "pace.h"

#include "building.h"
#include "db.h"

namespace Tank {
Pace::Pace() {
}

Pace::~Pace() {
}

void Pace::setAssociateBuilding(Building* building) {
    building_ = building;
}


} // namespace Tank