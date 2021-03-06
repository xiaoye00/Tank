#include "player.h"
#include "db.h"

namespace tank {

static int playerID = 0;

void setCurrentPlayerID(int id) {
    playerID = id;
}

int getCurrentPlayerID() {
    return playerID;
}

int getNextPlayerID() {
    auto db = DB::getInstance();
    auto id = (playerID + 1) % db->getNumPlayers();
    return id;
}

bool Player::expend(int cost) {
    if (money_ >= cost) {
        money_ -= cost;
        return true;
    }
    return false;
}

} // namespace tank