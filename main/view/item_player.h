#pragma once

#include "item_base.h"

class ItemPlayer : public ItemBase {
  public:
    ItemPlayer(QGraphicsItem* parent = nullptr);
    ~ItemPlayer();
    virtual void preDraw() override;
};