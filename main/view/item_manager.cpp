#include "item_manager.h"

namespace tank {
ItemManager::ItemManager(/* args */) {
}

ItemManager::~ItemManager() {
}

ItemPace* ItemManager::createItemPace(Pace* inst) {
    auto item = new ItemPace;
    auto pace = static_cast<Pace*>(inst);
    item->setPace(pace);
    item->setType(LayoutItemType::kPace);
    item->preDraw();
    item_paces_[item->getBox()->ID()] = item;
    return item;
}

ItemBuilding* ItemManager::createItemBuilding(Building* inst) {

    auto item     = new ItemBuilding;
    auto building = static_cast<Building*>(inst);
    item->setBuilding(building);
    item->setType(LayoutItemType::kBuilding);
    item->preDraw();
    item_buildings_[item->getBox()->ID()] = item;
    return item;
}

ItemPlayer* ItemManager::createItemPlayer(Player* inst) {
    auto player = static_cast<Player*>(inst);
    auto box    = player->getBox();
    auto item   = new ItemPlayer;
    auto id     = box->ID();
    item->setPlayer(player);
    item->setType(LayoutItemType::kPlayer);
    item->preDraw();
    item_players_[item->getPlayer()->ID()] = item;
    return item;
}

ItemPace* ItemManager::getItemPaceByID(int id) {
    if (item_paces_.find(id) != item_paces_.end()) {
        return item_paces_[id];
    }
    return nullptr;
}

ItemBuilding* ItemManager::getItemBuildingByBuilding(Building* building) 
{
    return getItemBuildingByID(building->ID());
}

ItemBuilding* ItemManager::getItemBuildingByID(int id) {
    if (item_buildings_.find(id) != item_buildings_.end()) {
        return item_buildings_[id];
    }
    return nullptr;
}

ItemPlayer* ItemManager::getItemPlayerByID(int id) {
    if (item_players_.find(id) != item_players_.end()) {
        return item_players_[id];
    }
    return nullptr;
}

ItemPlayer* ItemManager::getCurrentItemPlayer() {
    for (auto player : item_players_) {
        if (player->getPlayer()->ID() == getCurrentPlayerID()) {
            return player;
        }
    }
    return nullptr;
}
} // namespace Tank