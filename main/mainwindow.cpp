#include "mainwindow.h"

namespace tank {

MainWindow::MainWindow(QWidget* parent)
  : QMainWindow(parent) {

    //set window to the max size
    showMaximized();

    view = GraphicsView::getInstance();
    setCentralWidget(view);

    status_bar = new StatusBar(this);
    setStatusBar(status_bar);

    connect(view, &GraphicsView::sendPos, status_bar, &StatusBar::slotPos);
}

MainWindow::~MainWindow() {
}
} // namespace Tank
