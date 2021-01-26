#ifndef FILEDOWNLOADER_H
#define FILEDOWNLOADER_H

#include <QObject>
#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

class FileDownloader : public QObject
{
 Q_OBJECT
 public:
  explicit FileDownloader(QObject *parent = 0);
  virtual ~FileDownloader();
  void download(QUrl fileUrl);
  QByteArray downloadedData() const;

 signals:
  void downloaded();
  void downloadProgress(qint64 ist, qint64 max);

 private slots:
  void fileDownloaded(QNetworkReply* pReply);
  void fileDownloadProgress(qint64 ist, qint64 max);
  private:
  QNetworkAccessManager m_WebCtrl;
  QByteArray m_DownloadedData;
};

#endif // FILEDOWNLOADER_H
