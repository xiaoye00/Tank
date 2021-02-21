
#include "status_bar.h"

#include <QVBoxLayout>
namespace Tank {
StatusBar::StatusBar(QWidget* parent) : QStatusBar(parent) {
    line_edit     = new QLineEdit(this);
    auto v_layout = new QVBoxLayout;
    v_layout->addWidget(line_edit);
    setLayout(v_layout);
}

void StatusBar::slotPos(int x, int y) {
    line_edit->setText(QString::number(x) + "," + QString::number(y));
}
}
