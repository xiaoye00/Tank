
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
    painter.drawRect(0, 0, w_ - 1, h_ - 1);
}
