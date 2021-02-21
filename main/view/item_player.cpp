
#include "item_player.h"
#include <QPainter>
#include <QPen>
namespace Tank {
ItemPlayer::ItemPlayer(QGraphicsItem* parent) : ItemBase(parent) {
}

ItemPlayer::~ItemPlayer() {
}

void ItemPlayer::preDraw() {
    fillMapToTransparency();
    QPainter painter(img_);
    QPen     pen("blue");
    painter.setPen(pen);
    painter.drawEllipse(0, 0, box_->Width() - 1, box_->Height() - 1);

    QString name;

    name = player_->Name();

    auto x = 0;
    auto y = box_->Height() / 4;

    // painter.drawText(0, 0, name);

    painter.drawText(QRectF(
                       (x),
                       (y),
                       box_->Width() - 1,
                       box_->Height() / 2),
                     0,
                     name);
}

void ItemPlayer::setPlayer(Player* player) {
    player_ = player;
    setItemSize(player_->getBox());
}
} // namespace Tank
