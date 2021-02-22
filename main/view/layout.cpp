#include "layout.h"
#include "../widget/dice.h"
#include "box.h"
#include "config.h"
#include "db.h"
#include "item_pace.h"
#include "player.h"
#include "transform.h"
#include "util.h"
namespace Tank {
Layout::Layout() {
    item_manager = new ItemManager;
    getRondomNumber(10);
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
        player->setBox(box);
        auto orient = getRondomNumber(1);
        player->setOrient(orient);
        auto item = item_manager->createItemPlayer(player);
        scene_->addItem(item);
    }

    Dice* dice = new Dice;
    dice->exec();
    auto num = dice->Num();
    //who first
    auto who    = getRondomNumber(1);
    auto player = db->getPlayerByID(who);
    // dice->exec();
}
} // namespace Tank
