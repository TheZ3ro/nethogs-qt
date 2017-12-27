#ifndef QPUSHBUTTONARROW_H
#define QPUSHBUTTONARROW_H

#include <QObject>
#include <QWidget>
#include <QPushButton>

class QPushButtonArrow : public QPushButton
{
    Q_OBJECT

public:
    explicit QPushButtonArrow(QWidget * parent = 0);
    int pid;

signals:
    void display_cnx(int pid);

public slots:
    void on_clicked();
};

#endif // QPUSHBUTTONARROW_H
