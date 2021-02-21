#pragma once
#include <QLabel>
#include <QPushButton>
#include <QWidget>

namespace Tank {

class Dice : public QWidget {
  public:
    Dice(QWidget* parent = nullptr);
    ~Dice();

    QPushButton* btn{nullptr};
    QLabel*      label{nullptr};
};

} // namespace Tank