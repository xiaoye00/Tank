
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
    painter.drawRect(0, 0, w_ - 1, h_ - 1);
}
