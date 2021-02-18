#include "layout.h"
#include "box_creator.h"
#include "config.h"
#include "transform.h"
#include "item_pace.h"
#include "util.h"

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
    auto [scene_w, scene_h] = config.mapSize();
    scene_->setSize(scene_w, scene_h);
    auto& boxes = config.getPaceBoxes();
    for (auto& box : boxes) {
        auto item = item_manager->createItem(LayoutItemType::kPace,
                                             box);
        scene_->addItem(item);
    }

    boxes = config.getBuildingBoxes();
    for (auto& box : boxes) {
        auto item = item_manager->createItem(LayoutItemType::kBuilding,
                                             box);
        scene_->addItem(item);
    }
}
