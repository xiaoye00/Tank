#include "graphics_view.h"

#include <QMouseEvent>

namespace Tank {

GraphicsView::GraphicsView(QWidget* parent) : QGraphicsView(parent) {
    setMouseTracking(true);
    layout_ = new Layout();
    scene_  = new GraphicsScene;
    dice_   = new Dice;
    timer   = new QTimer(this);

    initiation();
}

void GraphicsView::initiation() {

    layout_->addScene(scene_);
    layout_->initiation();
    setScene(scene_);
    viewport()->update();
    show();

    connect(layout_, &Layout::signalUpdateItems, this, slotShowDice);
    connect(dice_, &Dice::signalPostDice, layout_, &Layout::slotRunTasks);
    connect(layout_, &Layout::signalShowDice, this, &GraphicsView::slotShowDice);
    connect(timer, &QTimer::timeout,this,&GraphicsView::slotOnTimer);
}

void GraphicsView::mouseMoveEvent(QMouseEvent* event) {
    auto point = mapToScene(event->pos());
    emit sendPos(point.rx(), point.ry());
    QGraphicsView::mouseMoveEvent(event);
}

void GraphicsView::slotShowDice() {

    timer->start(1000);
}

void GraphicsView::slotOnTimer() 
{
    dice_->resetData();
    dice_->show();
    timer->stop();
}

void GraphicsView::mouseDoubleClickEvent(QMouseEvent* event) {
    QGraphicsView::mouseDoubleClickEvent(event);
}

GraphicsView* GraphicsView::inst_ = nullptr;
} // namespace Tank