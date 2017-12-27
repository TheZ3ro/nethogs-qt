#include "smallchart.h"

#include <QtCharts/QSplineSeries>
#include <QtCharts/QValueAxis>
#include <QtCharts/QLogValueAxis>
#include <QtCharts/QDateTimeAxis>

#include <QtCore/QtMath>

#include <QtDebug>

QT_CHARTS_USE_NAMESPACE

SmallChart::SmallChart(QWidget *parent)
{
    ylog = true;
    xdate = false;

    QChart * chart = new QChart();
    setChart(chart);
    x = 1;
    max_val = 1;

    if (xdate) {
        start_time = QDateTime::currentDateTime();
    }

    series_recv.setName(tr("RECV"));
    series_sent.setName(tr("SENT"));

    chart->addSeries(&series_recv);
    chart->addSeries(&series_sent);

    //chart->legend()->hide();

    if (xdate) {
        QDateTimeAxis *axisX = new QDateTimeAxis;
        this->chart()->setAxisX(axisX, &series_recv);
        this->chart()->setAxisX(axisX, &series_sent);
#if 0 // DEBUG
        QDateTime now = QDateTime::currentDateTime();

        series_recv.append(now.toMSecsSinceEpoch(),10);
        series_sent.append(now.toMSecsSinceEpoch(),100);
        qDebug() << now << now.toMSecsSinceEpoch();
        axisX->setRange(start_time, now);
        axisY->setRange(1, 1000);
#endif
    } else {
        QValueAxis *axisX = new QValueAxis;
        this->chart()->setAxisX(axisX, &series_recv);
        this->chart()->setAxisX(axisX, &series_sent);
    }

    if (ylog) {
        QLogValueAxis *axisY = new QLogValueAxis;
        axisY->setLabelFormat("%g");
        axisY->setTitleText("Values in Bytes/s (Logarithmic Axis)");
        axisY->setBase(8);
        chart->addAxis(axisY, Qt::AlignLeft);
        this->chart()->setAxisY(axisY, &series_recv);
        this->chart()->setAxisY(axisY, &series_sent);
    } else {
        QValueAxis *axisY = new QValueAxis;
        axisY->setTitleText("Values in Bytes/s");
        this->chart()->setAxisY(axisY, &series_recv);
        this->chart()->setAxisY(axisY, &series_sent);
    }
    setRenderHint(QPainter::Antialiasing);
}

void SmallChart::add_points(quint64 r,quint64 s)
{

    if (xdate) {
        QDateTime now = QDateTime::currentDateTime();

        series_recv.append(now.toMSecsSinceEpoch(),r+1);
        series_sent.append(now.toMSecsSinceEpoch(),s+1);

        chart()->axisX()->setRange(start_time.toMSecsSinceEpoch(), start_time.toMSecsSinceEpoch()+1000);
        chart()->axisY()->setRange(1, 2);

    } else {
        if (ylog) {
            series_recv.append(x,r+1);
            series_sent.append(x,s+1);

            max_val = qMax(max_val, r+1);
            max_val = qMax(max_val, s+1);

            chart()->axisX()->setRange(0, x);
            chart()->axisY()->setRange(1, max_val);
            x++;
        } else {
            series_recv.append(x,r);
            series_sent.append(x,s);

            max_val = qMax(max_val, r);
            max_val = qMax(max_val, s);
            max_val = qMin(max_val, (quint64)1);

            chart()->axisX()->setRange(0, x);
            chart()->axisY()->setRange(0, max_val);
            x++;
        }
    }
}


void SmallChart::reset()
{

    series_recv.clear();
    series_sent.clear();
    x=1;
    chart()->axisX()->setRange(0, 1);
    if (ylog) {
        chart()->axisY()->setRange(1, 2);
    } else {
        chart()->axisY()->setRange(0, 1);
    }

    if (xdate) {
        start_time = QDateTime::currentDateTime();
        chart()->axisX()->setRange(start_time.toMSecsSinceEpoch(), start_time.toMSecsSinceEpoch()+1000);
        chart()->axisY()->setRange(1, 2);
    }
}
