#include "layout.h"
#include "box_creator.h"
#include "config.h"
#include "db.h"
#include "item_pace.h"
#include "player_creator.h"
#include "transform.h"
#include "util.h"

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
    auto& pace_boxes = db->getPaceBoxes();
    for (auto& box : pace_boxes) {
        auto item = item_manager->createItemPace(box);
        scene_->addItem(item);
    }

    auto building_boxes = db->getBuildingBoxes();
    for (auto& box : building_boxes) {
        auto item = item_manager->createItemBuilding(box);
        scene_->addItem(item);
    }

    auto players = db->getPlayers();
    for (auto& player : players) {
        auto size = pace_boxes.size();
        auto pos  = getRondomNumber(size - 1);
        auto box  = pace_boxes[pos];
        player->setBox(box);

        auto item = item_manager->createItemPlayer(player);
        scene_->addItem(item);
    }
}
