
#include "item_pace.h"
#include <QPainter>
#include <QPen>
ItemPace::ItemPace(QGraphicsItem* parent) : ItemBase(parent) {
}

ItemPace::~ItemPace() {
}

void ItemPace::preDraw() 
{
    fillMapToTransparency();
    QPainter painter(img_);
    QPen pen("red");
    painter.setPen(pen);
    painter.drawRect(0,0,img_->width()-1,img_->height()-1);
}

