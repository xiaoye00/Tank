#include "../util/util.h"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char* argv[]) {
    QApplication a(argc, argv);

    setInstallPath(argv[0]);
    tank::MainWindow w;
    w.show();
    return a.exec();
}

