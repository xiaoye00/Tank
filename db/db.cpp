#include "db.h"

namespace Tank {

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

DB* DB::inst_ = nullptr;
} // namespace Tank