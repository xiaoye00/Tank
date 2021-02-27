#include "db.h"

namespace tank {

DB::~DB() {
}



Player* DB::getPlayerByID(int ID) {
    for (auto player : player_list_) {
        if (auto id = player->ID(); id == ID) {
            return player;
        }
    }
    return nullptr;
}

Player* DB::getCurrentPlayer() {
    return getPlayerByID(getCurrentPlayerID());
}



DB* DB::inst_ = nullptr;
} // namespace Tank