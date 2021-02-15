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

void Layout::createPace(int x, int y) {
    item_manager->createItem(LayoutItemType::kPace, x, y, pace_size_, pace_size_);
}

void Layout::initiation() {
    Config config;
    config.loadDesign("D:/GitHub/tank/Tank/config/map_demo.xml");
    BoxCreator creator;
    creator.setConfig(&config);
    auto [scene_w, scene_h] = config.mapSize();
    scene_->setSize(scene_w, scene_h);
    Transform transform(scene_w, scene_h);
    auto [origin_x, origin_y] = config.originPoint();
    auto box                  = creator.createBox(UtilBoxType::kPace, origin_x, origin_y);
    auto scene_box            = transform.translateToSceneBox(box);
    auto item                 = item_manager->createItem(LayoutItemType::kPace,
                                         scene_box);
    scene_->addItem(item);
    auto data_list = config.getDataList();
    for (auto& data : data_list) {
        for (auto i = 0; i < data.num; i++) {
            box            = box.getNextBox(data.orient);
            auto scene_box = transform.translateToSceneBox(box);
            auto item      = item_manager->createItem(LayoutItemType::kPace,
                                                 scene_box);
            scene_->addItem(item);
        }
    }
}
