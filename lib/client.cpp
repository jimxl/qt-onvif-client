#include "client.h"
#include <QEventLoop>
#include <QUrl>
#include <QDebug>
#include <QMessageBox>

using namespace ONVIF;

Client::Client(const QString &url) {
    mUrl = url;
    //reply->ignoreSslErrors();
}

QString Client::sendData(const QString &data) {
    //    qDebug() << "send to url => " << mUrl << " | data => " << data;

    QUrl url(mUrl);
    QNetworkRequest requete(url);
    requete.setHeader( QNetworkRequest::ContentTypeHeader, QVariant( QString("text/xml;charset=utf-8")));
    requete.setHeader(QNetworkRequest::ContentLengthHeader, QVariant( qulonglong(data.size()) ));
    requete.setAttribute(QNetworkRequest::CacheLoadControlAttribute, QVariant( int(QNetworkRequest::AlwaysNetwork) ));
    //requete.setHeader(QNetworkRequest::ContentTypeHeader,QVariant("application/x-www-form-urlencoded"));
    QNetworkAccessManager *manager = new QNetworkAccessManager;
    reply = manager->post(requete, data.toUtf8());
    reply->ignoreSslErrors();
    waitForFinished(reply);
    if(reply->error() != QNetworkReply::NoError) {
        qDebug() << reply->error();
        return "";
    }
    return QString(reply->readAll());
}

void Client::waitForFinished(const QNetworkReply* reply) {
    QEventLoop loop;
    connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
}

