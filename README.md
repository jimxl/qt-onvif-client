qt-onvif-client
===============

fork from https://github.com/jimxl/qt-onvif-client

I'm not a QT developer, so my conventions may be poor.

On Ubuntu Linux 14.04 x64. qt 5.2.1


Runtime notes
==================
sudo apt-get install qtcreator libqt5xmlpatterns5-dev

QHttp
===========
Qt5 document: "The QFtp, QUrlInfo, QHttp classes are not public anymore (QHttp has been discouraged since Qt 4.7). Use QNetworkAccessManager instead to avoid binary breaks in the future. Programs that require raw FTP/HTTP streams, can use the compatibility add-ons QtFtp and QtHttp which provides the QFtp and QHttp classes as they existed in Qt 4."

reference: http://qt-project.org/forums/viewthread/24466

    cd /spot/qtwork
    git clone https://git.gitorious.org/qt/qthttp.git /spot/qtwork/qthttp-compat
    cd /spot/qtwork/qthttp-compat

    qmake --version
    /usr/lib/x86_64-linux-gnu/qt5/bin/syncqt.pl -version 5.2.1

adding to project:

     QT +=  http

Hopefully that helps you get it working ;)
