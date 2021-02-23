#pragma once

#include <QList>
#include <QMap>

#include "box.h"
#include "item_base.h"
#include "item_building.h"
#include "item_pace.h"
#include "item_player.h"
#include "layout_def.h"
#include "player.h"
#include "pace.h"
#include "building.h"

namespace Tank {

class ItemPace;
class ItemBuilding;
class ItemPlayer;

class ItemManager {
  public:
    ItemManager(/* args */);
    ~ItemManager();

    ItemPace* createItemPace(Pace* inst);

    ItemBuilding* createItemBuilding(Building* inst);

    ItemPlayer* createItemPlayer(Player* inst);

    auto getItemPaces() { return item_paces_; };
    auto getItemBuildings() { return item_buildings_; };
    auto getItemPlayers() { return item_players_; };

    ItemPlayer* getCurrentItemPlayer();

  private:
    QMap<int, ItemPace*>     item_paces_;
    QMap<int, ItemBuilding*> item_buildings_;
    QMap<int, ItemPlayer*>   item_players_;
};
} // namespace Tank
