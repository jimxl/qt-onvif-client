#include "systemdateandtime.h"

using namespace ONVIF;

SystemDateAndTime::SystemDateAndTime(QObject *parent) : QObject(parent) {
}

void SystemDateAndTime::setUtcTime(int year, int month, int day, int hour, int minute, int second) {
    QDate date;
    date.setDate(year, month, day);
    QTime time;
    time.setHMS(hour, minute, second);
    this->m_utcTime = QDateTime(date, time, Qt::UTC);
}

void SystemDateAndTime::setLocalTime(int year, int month, int day, int hour, int minute, int second) {
    QDate date;
    date.setDate(year, month, day);
    QTime time;
    time.setHMS(hour, minute, second);
    this->m_localTime = QDateTime(date, time);
}
