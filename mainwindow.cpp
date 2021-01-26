#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    downloader = new FileDownloader(this);

    connect(downloader, &FileDownloader::downloadProgress, this, &MainWindow::updateProgress);
    connect(downloader, SIGNAL (downloaded()), this, SLOT (saveFile()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::saveFile() {
    ui->progressBar->setEnabled(false);
    ui->progressBar->setValue(100);

    QFile file(qEnvironmentVariable("HOME") + "/Downloads/comm.io.app.zip");
    //QFile file(qEnvironmentVariable("HOME") + "/Downloads/config.json");
    file.open(QIODevice::WriteOnly);
    file.write(downloader->downloadedData());
    file.close();

    QApplication::quit();
}

void MainWindow::on_pushButton_clicked()
{
    //qDebug() << "MainWindow.on_pushButton_clicked";
    ui->progressBar->setEnabled(true);
    ui->pushButton->setEnabled(false);

    QUrl fileUrl("https://mauricio-is-testing.s3.amazonaws.com/comm.io.app.zip");
    //QUrl fileUrl("https://mauricio-is-testing.s3.amazonaws.com/sandbox-config.json");
    downloader->download(fileUrl);
}

void MainWindow::updateProgress(qint64 ist, qint64 max) {
    int progress = (ist * 100) / max;
    //qDebug() << "MainWindow::updateProgress: ist=" << ist << ", max=" << max << ", calc=" << progress;
    ui->progressBar->setValue(progress);
}
