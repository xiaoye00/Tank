#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "status_bar.h"
#include "view/graphics_view.h"
namespace Tank {
class MainWindow : public QMainWindow {
    Q_OBJECT

  public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    GraphicsView* view{nullptr};
    StatusBar*    status_bar;
    // void          setInstallPath(QString path){install_path_ = path; install_path_ = install_path_ + "../";};
    // QString       InstallPath(){return install_path_;};

  private:
    // QString install_path_;
};
}
#endif // MAINWINDOW_H
