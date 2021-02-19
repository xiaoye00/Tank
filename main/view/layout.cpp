#include "layout.h"
#include "box_creator.h"
#include "config.h"
#include "transform.h"
#include "item_pace.h"
#include "util.h"
#include "db.h"

Layout::Layout() {
    item_manager = new ItemManager;
}

Layout::~Layout() {
}


void Layout::initiation() {
    auto xml_path = InstallPath();
    xml_path += "map_demo.xml";
    Config config;
    auto path = xml_path.c_str();
    config.loadDesign(path);
    auto db = DB::getInstance();
    auto [scene_w, scene_h] = db->MapSize();
    scene_->setSize(scene_w, scene_h);
    auto& boxes = db->getPaceBoxes();
    for (auto& box : boxes) {
        auto item = item_manager->createItem(LayoutItemType::kPace,
                                             box);
        scene_->addItem(item);
    }

    boxes = db->getBuildingBoxes();
    for (auto& box : boxes) {
        auto item = item_manager->createItem(LayoutItemType::kBuilding,
                                             box);
        scene_->addItem(item);
    }
}
