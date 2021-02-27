
#include "item_building.h"
#include <QPainter>
#include <QPen>
#include "player.h"
namespace tank {
ItemBuilding::ItemBuilding(QGraphicsItem* parent) : ItemBase(parent) {
}

ItemBuilding::~ItemBuilding() {
}

void ItemBuilding::preDraw() {
    fillMapToTransparency();
    QPainter painter(img_);
    QPen     pen("gray");
    pen.setWidth(4);
    auto     owner = building_->getOwner();
    if (owner) {
        pen.setColor(owner->Color().c_str());
    }
    painter.setPen(pen);
    painter.drawRect(0, 0, box_->Width() - 1, box_->Height() - 1);

    auto box_id = box_->ID();

    QString name = QString::number(box_id);

    painter.drawText(QRectF(
                       (0),
                       (0),
                       box_->Width() - 1,
                       box_->Height() - 1),
                     0,
                     name);
}

void ItemBuilding::setBuilding(Building* building) {
    building_ = building;
    setItemSize(building_->getBox());
}
} // namespace Tank
