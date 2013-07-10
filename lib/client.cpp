#include "client.h"
#include <QHttp>
#include <QEventLoop>
#include <QUrl>
#include <QDebug>

using namespace ONVIF;

Client::Client(const QString &url) {
    mUrl = url;
}

QString Client::sendData(const QString &data) {
//    qDebug() << "send to url => " << mUrl << " | data => " << data;
    QHttp http;
    http.ignoreSslErrors();
    QUrl url(mUrl);
    http.setHost(url.host());
    http.post(url.path(), data.toUtf8());
    waitForFinish(http);
    if(http.error() != QHttp::NoError) {
        return "";
    }
    return QString(http.readAll());
}

void Client::waitForFinish(const QHttp &http) {
    QEventLoop loop;
    connect(&http, SIGNAL(done(bool)), &loop, SLOT(quit()));
    loop.exec();    
}
