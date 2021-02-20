
#include "item_pace.h"
#include <QPainter>
#include <QPen>
ItemPace::ItemPace(QGraphicsItem* parent) : ItemBase(parent) {
}

ItemPace::~ItemPace() {
}

void ItemPace::preDraw() {
    fillMapToTransparency();
    QPainter painter(img_);
    QPen     pen("green");
    painter.setPen(pen);
    painter.drawRect(0, 0, box_->Width() - 1, box_->Height() - 1);

    QString name;

    auto boxes = box_->getAssociateBoxes();

    // name = QString::number(box_->Index());

    for(auto box : boxes){
        name = QString::number(box);
    }

    painter.drawText(QRectF(
                       (0),
                       (0),
                       box_->Width() - 1,
                       box_->Height() - 1),
                     0,
                     name);
}
