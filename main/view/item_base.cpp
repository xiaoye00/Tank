#include "item_base.h"

#include <QPainter>

namespace Tank {

ItemBase::ItemBase(QGraphicsItem* parent) : QGraphicsItem(parent) {
    setVisible(true);
}

void ItemBase::setItemSize(Box* box) {
    box_         = box;
    auto       w = box_->Width();
    auto       h = box_->Height();
    QTransform matrix;
    matrix.translate(-(w >> 1), -(h >> 1));
    setTransform(matrix);
    resizeMap_(w, h);
    auto center_point = box_->getCenterPoint();
    setPos(center_point.rx(), center_point.ry());
}

QPixmap* ItemBase::fillMapToTransparency() {

    if (img_) {
        img_->fill(Qt::transparent);
    }
    return img_;
}

QRectF ItemBase::boundingRect() const {

    return QRectF(0, 0, box_->Width(), box_->Height());
}

void ItemBase::paint(QPainter*                       painter,
                     const QStyleOptionGraphicsItem* option,
                     QWidget*                        widget) {
    draw(painter);
}

QPixmap* ItemBase::resizeMap_(int w, int h) {
    if (img_) {
        if (w != img_->width() || h != img_->height()) {
            delete img_;
            img_ = new QPixmap(w, h);
        }
    } else {
        img_ = new QPixmap(w, h);
    }

    return img_;
}

void ItemBase::draw(QPainter* painter) {
    if (img_) {
        painter->drawPixmap(0, 0, *img_);
    }
}
} // namespace Tank