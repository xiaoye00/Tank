#include "layout.h"

#include "item_pace.h"

Layout::Layout() {
    item_manager = new ItemManager;
}

Layout::~Layout() {
}

void Layout::createPace(int x, int y) {
    item_manager->createItem(LayoutItemType::kPace, x, y, pace_size_, pace_size_);
}
