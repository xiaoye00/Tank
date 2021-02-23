#include "player.h"
#include "db.h"

namespace Tank {

static int playerID    = 0;


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



} // namespace Tank