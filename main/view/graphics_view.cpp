#include "graphics_view.h"

GraphicsView::GraphicsView(QWidget* parent) : QGraphicsView(parent) {
    scene_ = new GraphicsScene;
    layout_ = new Layout;
    layout_->addScene(scene_);
    layout_->initiation();
    setScene(scene_);
    viewport()->update();
    show();
}


GraphicsView* GraphicsView::inst_ = nullptr;