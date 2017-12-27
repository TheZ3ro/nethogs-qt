#include "linebandwith.h"

#include <QtDebug>

lineBandwith::lineBandwith(QWidget *parent) : QLineEdit(parent)
{
    time_prev = QDateTime::currentDateTime();
    count_prev = 0;
}

quint64 lineBandwith::new_count(quint64 count)
{
    quint64 bandwith = count-count_prev;
    QDateTime now = QDateTime::currentDateTime();
    quint64 ms_lapse = time_prev.msecsTo(now);
    QString s;

    if (ms_lapse < 1000) ms_lapse = 1000; // prevent division by 0 ;-)
    quint64 speed = bandwith * 1000 / ms_lapse;

    if (speed == 0) {
        s = "-"; }
    else if (speed < 1900) {
        s.setNum(speed);
        s.append(" B/s"); }
    else if (speed < 1900000) {
        s.setNum(speed/1024);
        s.append(" kB/s"); }
    else if (speed < 1900000000) {
        s.setNum(speed/(1024*1024));
        s.append(" MB/s"); }
    else {
        s.setNum(speed/(1024*1024*1024));
        s.append(" GB/s");
    }
    setText(s);
    time_prev.swap(now);
    count_prev = count;
    return speed;
}
