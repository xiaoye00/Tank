#include "dice.h"

#include <QVBoxLayout>

#include "util.h"

namespace Tank {
Dice::Dice(QWidget* parent) : QDialog(parent) {
    btn         = new QPushButton(this);
    btn->setText("Go!");
    label       = new QLabel(this);
    label->setText("0");
    auto layout = new QVBoxLayout;
    layout->addWidget(label);
    layout->addWidget(btn);
    setLayout(layout);

    connect(btn, &QPushButton::clicked, this, &Dice::slotButtonClicked);
}

Dice::~Dice() {
}

void Dice::slotButtonClicked(bool) {

    auto num = getRondomNumber(5) + 1;

    label->setText(QString::number(num));

    num_ = num;

    // setResult(num);

    close();

}
} // namespace Tank