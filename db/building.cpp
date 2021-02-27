#include "building.h"

#include "player.h"

namespace tank {
Building::Building() {
}

Building::~Building() {
}

void Building::setOwner(Player* player) {
    owner_ = player;
}

} // namespace Tank