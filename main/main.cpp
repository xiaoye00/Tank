#include "mainwindow.h"
#include "../util/util.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    setInstallPath(argv[0]);
    MainWindow w;
    w.show();
    return a.exec();
}
