#ifndef SMALLCHART_H
#define SMALLCHART_H

#include <QtWidgets/QWidget>
#include <QtCharts/QChartGlobal>
#include <QtCharts/QLineSeries>
#include "QDateTime"

QT_CHARTS_BEGIN_NAMESPACE
class QLineSeries;
class QChart;
QT_CHARTS_END_NAMESPACE

QT_CHARTS_USE_NAMESPACE

#include <QChartView>

class SmallChart : public QChartView
{
    Q_OBJECT
public:
    SmallChart(QWidget *parent);

private:
    QLineSeries series_recv;
    QLineSeries series_sent;
    int x;
    quint64 max_val;
    QDateTime start_time;
    bool ylog;
    bool xdate;

public slots:
    void add_points(quint64,quint64);
    void reset();

};

#endif // SMALLCHART_H
