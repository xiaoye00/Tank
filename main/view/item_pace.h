#pragma once

#include "item_base.h"
namespace Tank {
class ItemPace : public ItemBase {
  public:
    ItemPace(QGraphicsItem* parent = nullptr);
    ~ItemPace();
    virtual void preDraw() override;
};
}