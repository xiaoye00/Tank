
#include "item_building.h"
#include <QPainter>
#include <QPen>
ItemBuilding::ItemBuilding(QGraphicsItem* parent) : ItemBase(parent) {
}

ItemBuilding::~ItemBuilding() {
}

void ItemBuilding::preDraw() {
    fillMapToTransparency();
    QPainter painter(img_);
    QPen     pen("red");
    painter.setPen(pen);
    painter.drawRect(0, 0, box_->Width() - 1, box_->Height() - 1);

    QString name = QString::number(box_->Index());

    
    painter.drawText(QRectF(
                       (0),
                       (0),
                       box_->Width() - 1,
                       box_->Height() - 1),
                     0,
                     name);
}
