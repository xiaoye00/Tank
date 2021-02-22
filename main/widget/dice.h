#pragma once
#include <QDialog>
#include <QDialogButtonBox>
#include <QLabel>
#include <QPushButton>

namespace Tank {

class Dice : public QDialog {
    Q_OBJECT
  public:
    Dice(QWidget* parent = nullptr);
    ~Dice();

    QPushButton* btn{nullptr};
    QLabel*      label{nullptr};
    int          Num(){return num_;};

  public slots:
    void slotButtonClicked(bool);

  private:
    int num_{0};
};

} // namespace Tank