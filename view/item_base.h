#pragma once

#include <QGraphicsItem>
#include <QPixmap>
#include "layout_def.h"

class ItemBase : public QGraphicsItem {
  public:
    ItemBase(QGraphicsItem* parent = nullptr);
    ~ItemBase(){};

    void     setItemSize(int w, int h);
    void     setImg(QPixmap* img) { img_ = img; };
    QPixmap* fillMapToTransparency();
    QPixmap* resizeMap(int w, int h);
    void     setType(LayoutItemType type) { type_ = type; };

  protected:
    QPixmap*       img_{nullptr};
    virtual QRectF boundingRect() const;

    virtual void paint(QPainter*                       painter,
                       const QStyleOptionGraphicsItem* option,
                       QWidget*                        widget = nullptr) override;

  private:
    int            w_{0};
    int            h_{0};
    LayoutItemType type_;
};