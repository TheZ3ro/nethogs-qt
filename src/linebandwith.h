#ifndef LINEBANDWITH_H
#define LINEBANDWITH_H

#include "QLineEdit"

#include "QDateTime"

class lineBandwith : public QLineEdit
{
    Q_OBJECT

public:
    explicit lineBandwith(QWidget *parent = 0);

    quint64 new_count(quint64 count);

private:
    quint64 count_prev;
    QDateTime time_prev;

signals:

public slots:

};

#endif // LINEBANDWITH_H
