#include "layout.h"
#include "item_pace.h"
#include "util/config.h"

Layout::Layout() {
    item_manager = new ItemManager;
}

Layout::~Layout() {
}

void Layout::createPace(int x, int y) {
    item_manager->createItem(LayoutItemType::kPace, x, y, pace_size_, pace_size_);
}

void Layout::initiation() 
{
    Config config;
    config.loadDesign("D:/GitHub/tank/Tank/config/map_demo.xml");

}
