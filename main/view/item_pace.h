#pragma once

#include "item_base.h"
#include "pace.h"
namespace Tank {
class ItemPace : public ItemBase {
  public:
    ItemPace(QGraphicsItem* parent = nullptr);
    ~ItemPace();
    virtual void preDraw() override;

    void setPace(Pace* pace);
    auto getPace() { return pace_; };

  private:
    Pace* pace_{nullptr};
};
} // namespace Tank