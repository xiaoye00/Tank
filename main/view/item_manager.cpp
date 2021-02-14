#include "item_manager.h"
#include "item_pace.h"

ItemManager::ItemManager(/* args */) {
}

ItemManager::~ItemManager() {
}

ItemBase* ItemManager::createItem(LayoutItemType type, int pos_x, int pos_y, int w, int h) {
    auto item                       = new ItemPace;
    pace_item_map_[pace_item_id_++] = item;
    item->setPos(pos_x, pos_y);
    item->resizeMap(w, h);
    item->setType(type);
    return item;
}