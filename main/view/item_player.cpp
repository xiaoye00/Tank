
#include "item_player.h"
#include <QPainter>
#include <QPen>
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

    // QString name;

    // auto boxes = box_->getAssociateBoxes();

    // // name = QString::number(box_->Index());

    // for(auto box : boxes){
    //     name = QString::number(box);
    // }

    // painter.drawText(QRectF(
    //                    (0),
    //                    (0),
    //                    box_->Width() - 1,
    //                    box_->Height() - 1),
    //                  0,
    //                  name);
}
