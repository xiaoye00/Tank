#pragma once

#include "item_base.h"
namespace Tank {
class ItemBuilding : public ItemBase {
  public:
    ItemBuilding(QGraphicsItem* parent = nullptr);
    ~ItemBuilding();
    virtual void preDraw() override;
};
}