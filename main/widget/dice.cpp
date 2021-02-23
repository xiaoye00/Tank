#include "dice.h"

#include <QVBoxLayout>

#include "db.h"
#include "util.h"

namespace Tank {
Dice::Dice(QWidget* parent) : QDialog(parent) {
    btn = new QPushButton(this);
    label = new QLabel(this);
    resetData();
    auto layout = new QVBoxLayout;
    layout->addWidget(label);
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
    label->setText("0");
    num_ = 0;
}

void Dice::slotButtonClicked(bool) {

    auto num = getRondomNumber(5) + 1;

    label->setText(QString::number(num));

    num_ = num;

    auto db = DB::getInstance();

    auto player = db->getCurrentPlayer();

    player->setRunSteps(num_);

    emit signalPostDice();

    hide();
}
} // namespace Tank