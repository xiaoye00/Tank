#include "item_manager.h"
#include "item_pace.h"

ItemManager::ItemManager(/* args */) {
}

ItemManager::~ItemManager() {
}

ItemBase* ItemManager::createItem(LayoutItemType type, int pos_x, int pos_y, int w, int h) {
    auto item                       = new ItemPace;
    pace_item_map_[pace_item_id_++] = item;
    item->setItemSize(w,h);
    item->setPos(pos_x, pos_y);
    item->setType(type);
    return item;
}

ItemBase* ItemManager::createItem(LayoutItemType type, Box box) {
    auto center_point = box.getCenterPoint();
    auto item = createItem(type, center_point.rx(), center_point.ry(), box.Width(), box.Height());
    switch (type) {
    case LayoutItemType::kPace: {
        auto pace_itme = dynamic_cast<ItemPace*>(item);
        pace_itme->preDraw();
    } break;
    default:
        break;
    }
    return item;

}