#include "layout.h"
#include "../widget/dice.h"
#include "box.h"
#include "config.h"
#include "db.h"
#include "item_pace.h"
#include "item_player.h"
#include "player.h"
#include "transform.h"
#include "util.h"
namespace Tank {
Layout::Layout() {
    item_manager = new ItemManager;
    getRondomNumber(10);
    // dice = new Dice;
}

Layout::~Layout() {
}

void Layout::initiation() {
    auto xml_path = InstallPath();
    xml_path += "map_demo.xml";
    Config config;
    auto   path = xml_path.c_str();
    config.loadDesign(path);
    auto db                 = DB::getInstance();
    auto [scene_w, scene_h] = db->MapSize();
    scene_->setSize(scene_w, scene_h);
    auto paces = db->getPaces();
    for (auto& pace : *paces) {
        auto item = item_manager->createItemPace(pace);
        scene_->addItem(item);
    }

    auto buildings = db->getBuildings();
    for (auto& building : *buildings) {
        auto item = item_manager->createItemBuilding(building);
        scene_->addItem(item);
    }

    auto players = db->getPlayers();
    for (auto& player : *players) {
        auto size = paces->size();
        auto pos  = getRondomNumber(size - 1);
        auto box  = (*paces)[pos]->getBox();
        player->setPosition(pos);
        player->setBox(box);
        auto orient = getRondomNumber(1);
        player->setOrient(orient);
        auto item = item_manager->createItemPlayer(player);
        scene_->addItem(item);
    }

    //who first
    auto who    = getRondomNumber(1);
    auto player = db->getPlayerByID(who);
    setCurrentPlayerID(who);

    // connect(dice, &Dice::signalPostDice, this, &Layout::slotRunTasks);
    // connect(this, &Layout::signalShowDice, this, &Layout::slotShowDice);
}

void Layout::slotRunTasks() {
    auto item_player = item_manager->getCurrentItemPlayer();
    auto player      = item_player->getPlayer();
    auto run_steps   = player->RunSteps();
    auto db          = DB::getInstance();
    auto paces       = db->getPaces();
    while (*run_steps) {
        (*run_steps)--;
        player->setPosition((player->Position() + 1) % db->getNumPaces());
        auto box = (*paces)[player->Position()]->getBox();
        player->setBox(box);
        item_player->refreshItem();
    }

    auto pos = player->Position();

    auto itme_buildings = item_manager->getItemBuildings();

    auto pace = (*paces)[pos];

    auto building = pace->getAssociateBuilding();

    if (building) {
        if (!building->getOwner()) {
            building->setOwner(player);
        }

        auto item_building = itme_buildings[building->getBox()->Index()];

        item_building->preDraw();

        item_building->update();
    }

    // auto item_pace =  (*paces)[pos];

    setCurrentPlayerID(getNextPlayerID());

    emit signalShowDice();
}

void Layout::slotShowDice() {
    // dice->resetData();

    emit signalUpdateItems();
}
} // namespace Tank
