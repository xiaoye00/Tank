#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "status_bar.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

    StatusBar* status_bar;
};
#endif // MAINWINDOW_H
