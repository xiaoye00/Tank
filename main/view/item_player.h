#pragma once

#include "item_base.h"
#include "player.h"
namespace tank {
class ItemPlayer : public ItemBase {
  Q_OBJECT
  public:
    ItemPlayer(QGraphicsItem* parent = nullptr);
    ~ItemPlayer();
    virtual void preDraw() override;

    void setPlayer(Player* player);
    auto getPlayer() { return player_; };
    void refreshItem();

  public slots:

    void slotRefreshPos();

  private:
    Player* player_{nullptr};
};
} // namespace Tank