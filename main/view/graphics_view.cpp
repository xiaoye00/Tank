#include "graphics_view.h"

#include <QMouseEvent>
namespace Tank {
GraphicsView::GraphicsView(QWidget* parent) : QGraphicsView(parent) {
    setMouseTracking(true);
    scene_  = new GraphicsScene;
    layout_ = new Layout;
    layout_->addScene(scene_);
    layout_->initiation();
    setScene(scene_);
    viewport()->update();
    show();
}

void GraphicsView::mouseMoveEvent(QMouseEvent* event) {
    auto point = mapToScene(event->pos());
    emit sendPos(point.rx(), point.ry());
    QGraphicsView::mouseMoveEvent(event);
}

GraphicsView* GraphicsView::inst_ = nullptr;
}