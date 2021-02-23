#include "graphics_view.h"

#include <QMouseEvent>
namespace Tank {

GraphicsView::GraphicsView(QWidget* parent) : QGraphicsView(parent) {
    setMouseTracking(true);
    layout_ = new Layout();
    scene_  = new GraphicsScene;

    initiation();
}

void GraphicsView::initiation() {
    
    layout_->addScene(scene_);
    layout_->initiation();
    setScene(scene_);
    viewport()->update();
    show();

    connect(layout_, &Layout::signalUpdateItems, this, updateItems);
}

void GraphicsView::mouseMoveEvent(QMouseEvent* event) {
    auto point = mapToScene(event->pos());
    emit sendPos(point.rx(), point.ry());
    QGraphicsView::mouseMoveEvent(event);
}

void GraphicsView::updateItems() {

    viewport()->update();
}

GraphicsView* GraphicsView::inst_ = nullptr;
} // namespace Tank