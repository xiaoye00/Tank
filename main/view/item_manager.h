#pragma once
#include "box.h"
#include "item_base.h"
#include "item_building.h"
#include "item_pace.h"
#include "item_player.h"
#include "layout_def.h"
#include "player.h"
namespace Tank {
class ItemManager {
  public:
    ItemManager(/* args */);
    ~ItemManager();

    ItemPace* createItemPace(Box* inst) {
        auto item = new ItemPace;
        auto box  = static_cast<Box*>(inst);
        item->setItemSize(box);
        item->setType(LayoutItemType::kPace);
        item->preDraw();
        return item;
    }

    ItemBuilding* createItemBuilding(Box* inst) {

        auto item = new ItemBuilding;
        auto box  = static_cast<Box*>(inst);
        item->setItemSize(box);
        item->setType(LayoutItemType::kBuilding);
        item->preDraw();
        return item;
    }

    ItemPlayer* createItemPlayer(Player* inst) {
        auto player = static_cast<Player*>(inst);
        auto box    = player->getBox();
        auto item   = new ItemPlayer;
        auto id = box->Index();
        item->setPlayer(player);
        item->setType(LayoutItemType::kPlayer);
        item->preDraw();
        return item;
    }

  private:
};
}
