#include "building.h"

#include "player.h"

namespace Tank {
Building::Building() {
}

Building::~Building() {
}

void Building::setOwner(Player* player) {
    owner_ = player;
}

} // namespace Tank