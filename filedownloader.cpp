#include "filedownloader.h"

FileDownloader::FileDownloader(QObject *parent) :
 QObject(parent)
{
 connect(
  &m_WebCtrl, SIGNAL (finished(QNetworkReply*)),
  this, SLOT (fileDownloaded(QNetworkReply*))
 );
}

FileDownloader::~FileDownloader() { }

void FileDownloader::download(QUrl fileUrl) {
    //qDebug() << "FileDownloader.download";
    QNetworkRequest request(fileUrl);
    QNetworkReply *reply = m_WebCtrl.get(request);
    connect(reply, &QNetworkReply::downloadProgress, this, &FileDownloader::fileDownloadProgress);
}

void FileDownloader::fileDownloaded(QNetworkReply* pReply) {
    m_DownloadedData = pReply->readAll();
    //emit a signal
    pReply->deleteLater();
    emit downloaded();
}

QByteArray FileDownloader::downloadedData() const {
    return m_DownloadedData;
}

void FileDownloader::fileDownloadProgress(qint64 ist, qint64 max) {
    //qDebug() << "FileDownloader.fileDownloadProgress";
    emit downloadProgress(ist, max);
}
