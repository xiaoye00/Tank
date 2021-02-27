#include "dice.h"

#include <QVBoxLayout>

#include "db.h"
#include "util.h"

namespace tank {
Dice::Dice(QWidget* parent) : QDialog(parent) {
    btn        = new QPushButton(this);
    label_num      = new QLabel(this);
    label_name = new QLabel(this);
    resetData();
    auto layout = new QVBoxLayout;
    layout->addWidget(label_name);
    layout->addWidget(label_num);
    layout->addWidget(btn);
    setLayout(layout);
    setVisible(true);
    // setWindowFlags(Qt::Window);

    connect(btn, &QPushButton::clicked, this, &Dice::slotButtonClicked);
}

Dice::~Dice() {
}

void Dice::resetData() {
    btn->setText("Go!");
    label_num->setText("0");
    num_ = 0;

    auto db = DB::getInstance();

    auto player = db->getCurrentPlayer();

    if(player)
    {
        label_name->setText(player->Name());
    }
}

void Dice::slotButtonClicked(bool) {

    auto num = getRondomNumber(5) + 1;

    label_num->setText(QString::number(num));

    num_ = num;

    auto db = DB::getInstance();

    auto player = db->getCurrentPlayer();

    player->setRunSteps(num_);

    emit signalPostDice();

    //
}
} // namespace Tank