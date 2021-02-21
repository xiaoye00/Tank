#pragma once

#include "item_base.h"
#include "player.h"
namespace Tank {
class ItemPlayer : public ItemBase {
  public:
    ItemPlayer(QGraphicsItem* parent = nullptr);
    ~ItemPlayer();
    virtual void preDraw() override;

    void setPlayer(Player* player);

  private:
    Player* player_{nullptr};
};
}