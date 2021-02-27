#pragma once
#include <QDialog>
#include <QDialogButtonBox>
#include <QLabel>
#include <QPushButton>

#include "player.h"

namespace tank {

class Dice : public QDialog {
    Q_OBJECT
  public:
    Dice(QWidget* parent = nullptr);
    ~Dice();

    QPushButton* btn{nullptr};
    QLabel*      label_num{nullptr};
    QLabel*      label_name{nullptr};
    int          Num() { return num_; };
    void         addPlayer(Player* player) { player_list_.push_back(player); };
    void         resetData();

  signals:
    void signalPostDice();

  public slots:
    void slotButtonClicked(bool);

  private:
    int            num_{0};
    QList<Player*> player_list_;
};

} // namespace Tank