#pragma once

#include "building.h"
#include "item_base.h"
namespace tank {
class ItemBuilding : public ItemBase {
  public:
    ItemBuilding(QGraphicsItem* parent = nullptr);
    ~ItemBuilding();
    virtual void preDraw() override;
    void         setBuilding(Building* building);

  private:
    Building* building_{nullptr};
};
} // namespace Tank