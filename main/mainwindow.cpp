#include "mainwindow.h"



MainWindow::MainWindow(QWidget* parent)
  : QMainWindow(parent) {
    view = GraphicsView::getInstance();
    setCentralWidget(view);
    status_bar = new StatusBar(this);
    setStatusBar(status_bar);

    connect(view, &GraphicsView::sendPos, status_bar, &StatusBar::slotPos);
}

MainWindow::~MainWindow() {
}
