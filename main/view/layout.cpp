#include "layout.h"
#include "../widget/dice.h"

#include "config.h"
#include "db.h"
#include "item_pace.h"
#include "item_player.h"
#include "player.h"
#include "transform.h"
#include "util.h"
namespace tank {
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
        auto pace = (*paces)[pos];
        player->setPosition(pos);
        player->setPace(pace);
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

void Layout::adjustPlayerView() {
    auto item_player = item_manager->getCurrentItemPlayer();
    auto player      = item_player->getPlayer();
    auto box = player->getBox();
    //calculate left
    auto lux = box->LUX() + view_box_.LUX();
    //out of left threshold
    if (lux < -scene_->width()/2)
    {
        /* code */
    }
    // calculate right
    auto rlx = box->RLX();
    //out of right threshold
    if (rlx > scene_->width()/2)
    {
        /* code */
    }

    //calculate top
    auto luy = box->LUY();
    //out of top threshold
    if (luy < -scene_->height()/2)
    {
        /* code */
    }

    //calculate bottom
    auto rly = box->RLY();
    //out of bottom threshold
    if (rly > scene_->height()/2)
    {
        /* code */
    }
    
    
    
    
}

void Layout::slotRunTasks() {
    auto item_player = item_manager->getCurrentItemPlayer();
    auto player      = item_player->getPlayer();
    auto run_steps   = player->RunSteps();
    auto db          = DB::getInstance();
    auto paces       = db->getPaces();
    if (player->Orient() == GoOrient::kGoAhead) {
        while (*run_steps) {
            (*run_steps)--;
            player->setPosition((player->Position() + 1) % db->getNumPaces());
            auto pace = (*paces)[player->Position()];
            player->setPace(pace);
            item_player->refreshItem();
        }
    } else {
        while (*run_steps) {
            (*run_steps)--;
            player->setPosition((player->Position() - 1 + db->getNumPaces()) % db->getNumPaces());
            auto pace = (*paces)[player->Position()];
            player->setPace(pace);
            item_player->refreshItem();
        }
    }

    auto pace = player->getPace();

    auto building = pace->getAssociateBuilding();

    if (building) {
        if (!building->getOwner()) {
            building->setOwner(player);
        }

        auto item_building = item_manager->getItemBuildingByBuilding(building);

        item_building->preDraw();

        item_building->update();
    }

    setCurrentPlayerID(getNextPlayerID());

    emit signalShowDice();
}

void Layout::slotShowDice() {
    // dice->resetData();

    emit signalUpdateItems();
}
} // namespace tank
