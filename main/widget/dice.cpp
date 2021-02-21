#include "dice.h"
namespace Tank {
Dice::Dice(QWidget* parent) : QWidget(parent) {
    btn   = new QPushButton(this);
    label = new QLabel(this);
}

Dice::~Dice() {
}
} // namespace Tank