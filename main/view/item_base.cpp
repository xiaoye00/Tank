#include "item_base.h"

#include <QPainter>
ItemBase::ItemBase(QGraphicsItem* parent) : QGraphicsItem(parent) {
    setVisible(true);
}

void ItemBase::setItemSize(int w, int h) {
    w_ = w;
    h_ = h;
    QTransform matrix;
    matrix.translate(-(w >> 1), -(h >> 1));
    setTransform(matrix);
    resizeMap(w, h);
}

QPixmap* ItemBase::fillMapToTransparency() {

    if (img_) {
        img_->fill(Qt::transparent);
    }
    return img_;
}

QRectF ItemBase::boundingRect() const {
    return QRectF(0, 0, w_, h_);
}

void ItemBase::paint(QPainter*                       painter,
                     const QStyleOptionGraphicsItem* option,
                     QWidget*                        widget) {
    draw(painter);
}

QPixmap* ItemBase::resizeMap(int w, int h) {
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