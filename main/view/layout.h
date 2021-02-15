#pragma once

#include <QString>

#include "graphics_scene.h"
#include "item_manager.h"
#include "layout_def.h"

class Layout {

  public:
    Layout();
    ~Layout();

    void addScene(GraphicsScene* scene) { scene_ = scene; };
    void createPace(int x, int y);
    void setPaceSize(int size) { pace_size_ = size; };
    void initiation();

  private:
    GraphicsScene* scene_{nullptr};
    ItemManager*   item_manager{nullptr};
    int            pace_size_{0};
};
