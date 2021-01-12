#include "mainwindow.h"
#include <QApplication>
#include "login.h"
#include "globalvalues.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    GlobalValues::g_mainWindow = &w;
    return a.exec();
}
