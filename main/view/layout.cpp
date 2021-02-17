#include "layout.h"
#include "../../util/box_creator.h"
#include "../../util/config.h"
#include "../../util/transform.h"
#include "item_pace.h"

Layout::Layout() {
    item_manager = new ItemManager;
}

Layout::~Layout() {
}


void Layout::initiation() {
    Config config;
    config.loadDesign("D:/GitHub/tank/Tank/config/map_demo.xml");
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
