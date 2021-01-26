#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <iostream>

void msgHandler(QtMsgType type, const QMessageLogContext &, const QString &str)
{
    const char symbols[] = { 'I', 'E', '!', 'X' };
    QString output = QString("[%1] %2").arg( symbols[type] ).arg(str);
    std::cerr << output.toStdString() << std::endl;
    if( type == QtFatalMsg ) abort();
}

int main(int argc, char *argv[])
{
    qInstallMessageHandler(msgHandler);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
