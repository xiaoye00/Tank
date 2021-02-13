#include "graphics_view.h"

GraphicsView::GraphicsView(QWidget* parent) : QGraphicsView(parent) {
}


GraphicsView* GraphicsView::inst_ = nullptr;