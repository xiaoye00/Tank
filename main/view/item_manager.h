#pragma once
#include "item_base.h"
#include "layout_def.h"
#include "box_creator.h"

class ItemManager {
  public:
    ItemManager(/* args */);
    ~ItemManager();

    // ItemBase* createItem(LayoutItemType type, int pos_x, int pos_y, int w, int h);
    ItemBase* createItem(LayoutItemType type, Box box);

  private:

    
};
