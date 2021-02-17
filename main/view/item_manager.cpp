#include "item_manager.h"
#include "item_building.h"
#include "item_pace.h"

ItemManager::ItemManager(/* args */) {
}

ItemManager::~ItemManager() {
}

ItemBase* ItemManager::createItem(LayoutItemType type, int pos_x, int pos_y, int w, int h) {
    ItemBase* item;
    switch (type) {
    case LayoutItemType::kPace: {
        item                            = new ItemPace;
        pace_item_map_[pace_item_id_++] = item;
        item->setItemSize(w, h);
        item->setPos(pos_x, pos_y);
        item->setType(type);
        auto sub_itme = dynamic_cast<ItemPace*>(item);
        sub_itme->preDraw();
    } break;
    case LayoutItemType::kBuilding: {
        item                            = new ItemBuilding;
        pace_item_map_[pace_item_id_++] = item;
        item->setItemSize(w, h);
        item->setPos(pos_x, pos_y);
        item->setType(type);
        auto sub_itme = dynamic_cast<ItemBuilding*>(item);
        sub_itme->preDraw();
    } break;
    default:
        break;
    }

    return item;
}

ItemBase* ItemManager::createItem(LayoutItemType type, Box box) {
    auto center_point = box.getCenterPoint();
    auto item         = createItem(type, center_point.rx(), center_point.ry(), box.Width(), box.Height());
    return item;
}