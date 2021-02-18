#pragma once

#include <QGraphicsItem>
#include <QPixmap>
#include <list>
#include "box_creator.h"
#include "layout_def.h"

class ItemBase : public QGraphicsItem {
  public:
    ItemBase(QGraphicsItem* parent = nullptr);
    ~ItemBase(){};

    void         setItemSize(Box box);
    void         setImg(QPixmap* img) { img_ = img; };
    QPixmap*     fillMapToTransparency();
    void         setType(LayoutItemType type) { type_ = type; };
    virtual void preDraw(){};
    virtual void draw(QPainter* painter);
    auto         getBox() { return box_; };

  protected:
    QPixmap*         img_{nullptr};
    virtual QRectF   boundingRect() const;
    virtual QPixmap* resizeMap_(int w, int h);
    virtual void     paint(QPainter*                       painter,
                           const QStyleOptionGraphicsItem* option,
                           QWidget*                        widget = nullptr) override;

    LayoutItemType type_;
    std::list<int> associate_item_;
    Box            box_;
};