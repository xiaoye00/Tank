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
    auto pace_boxes = db->getPaceBoxes();
    for (auto& box : *pace_boxes) {
        auto item = item_manager->createItemPace(box);
        scene_->addItem(item);
    }

    auto building_boxes = db->getBuildingBoxes();
    for (auto& box : *building_boxes) {
        auto item = item_manager->createItemBuilding(box);
        scene_->addItem(item);
    }
    
    auto players = db->getPlayers();
    for (auto& player : *players) {
        auto size = pace_boxes->size();
        auto pos  = getRondomNumber(size - 1);
        auto box  = (*pace_boxes)[pos];
        player->setPosition(pos);
        player->setBox(box);
        auto orient = getRondomNumber(1);
        player->setOrient(orient);
        auto item = item_manager->createItemPlayer(player);
        scene_->addItem(item);
        // dice->addPlayer(player);
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
    auto pace_boxes  = db->getPaceBoxes();
    while (*run_steps) {
        (*run_steps)--;
        player->setPosition((player->Position() + 1) % db->getNumPaces());
        auto box = (*pace_boxes)[player->Position()];
        player->setBox(box);
        item_player->refreshItem();
    }

    setCurrentPlayerID(getNextPlayerID());

    emit signalShowDice();
    
}

void Layout::slotShowDice() 
{
    // dice->resetData();
    

    emit signalUpdateItems();
    
}
} // namespace Tank
