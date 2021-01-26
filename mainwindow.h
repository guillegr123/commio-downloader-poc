#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUrl>
#include <QFile>
#include <filedownloader.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void saveFile();
    void updateProgress(qint64 ist, qint64 max);
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    FileDownloader *downloader;
};
#endif // MAINWINDOW_H
