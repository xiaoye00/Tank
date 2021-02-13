#include "mainwindow.h"

#include "graphics_view.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    auto view = GraphicsView::getInstance();
    setCentralWidget(view);
}

MainWindow::~MainWindow()
{
}

