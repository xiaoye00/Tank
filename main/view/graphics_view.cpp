#include "graphics_view.h"

// #include <QGuiApplication>
#include <QMouseEvent>

namespace tank {

GraphicsView::GraphicsView(QWidget* parent) : QGraphicsView(parent) {
    setMouseTracking(true);
    layout_          = new Layout();
    scene_           = new GraphicsScene;
    dice_            = new Dice;
    dice_timer_show_ = new QTimer(this);
    dice_timer_hide_ = new QTimer(this);

    initiation();
}

void GraphicsView::initiation() {

    layout_->addScene(scene_);
    layout_->initiation();
    setScene(scene_);
    viewport()->update();
    show();

    // connect(layout_, &Layout::signalUpdateItems, this, slotShowDice);
    connect(dice_, &Dice::signalPostDice, layout_, &Layout::slotRunTasks);
    connect(layout_, &Layout::signalShowDice, this, &GraphicsView::slotShowDice);
    connect(dice_timer_hide_, &QTimer::timeout, this, &GraphicsView::slotDiceHide);
    connect(dice_timer_show_, &QTimer::timeout, this, &GraphicsView::slotDiceShow);
}

void GraphicsView::mouseMoveEvent(QMouseEvent* event) {
    auto point = mapToScene(event->pos());
    emit sendPos(point.rx(), point.ry());
    QGraphicsView::mouseMoveEvent(event);
}

void GraphicsView::slotShowDice() {

    dice_timer_hide_->start(500);
}

void GraphicsView::slotDiceHide() {

    dice_->hide();
    dice_timer_hide_->stop();
    dice_timer_show_->start(500);
}

void GraphicsView::slotDiceShow() {
    dice_->resetData();
    dice_->show();
    dice_timer_show_->stop();
}

void GraphicsView::mouseDoubleClickEvent(QMouseEvent* event) {
    QGraphicsView::mouseDoubleClickEvent(event);
}

void GraphicsView::resizeEvent(QResizeEvent* event) {
    tank::Box box;
    // box.setLUX(event->size().)
    QGraphicsView::resizeEvent(event);
}

GraphicsView* GraphicsView::inst_ = nullptr;
} // namespace tank