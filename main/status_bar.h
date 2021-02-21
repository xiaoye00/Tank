#pragma once
#include <QLineEdit>
#include <QStatusBar>
namespace Tank {
class StatusBar : public QStatusBar {
    Q_OBJECT
  public:
    StatusBar(QWidget* parent = nullptr);
    ~StatusBar(){};
    QLineEdit* line_edit;

  public slots:

    void slotPos(int x, int y);
};
}