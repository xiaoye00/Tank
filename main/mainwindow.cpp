#include "mainwindow.h"

#include "view/graphics_view.h"

MainWindow::MainWindow(QWidget* parent)
  : QMainWindow(parent) {
    auto view = GraphicsView::getInstance();
    setCentralWidget(view);
    status_bar = new StatusBar(this);
    setStatusBar(status_bar);

    connect(view, &GraphicsView::sendPos, status_bar, &StatusBar::slotPos);
}

MainWindow::~MainWindow() {
}
