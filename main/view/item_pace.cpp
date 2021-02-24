
#include "item_pace.h"

#include <QPainter>
#include <QPen>

#include "building.h"

namespace Tank {
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

    auto building = pace_->getAssociateBuilding();

    if (building) {
        auto id = building->getBox()->ID();

        name = QString::number(id);
    }

    painter.drawText(QRectF(
                       (0),
                       (0),
                       box_->Width() - 1,
                       box_->Height() - 1),
                     0,
                     name);
}

void ItemPace::setPace(Pace* pace) {
    pace_ = pace;
    setItemSize(pace_->getBox());
}
} // namespace Tank
