#include "qpushbuttonarrow.h"

#include <QtDebug>

QPushButtonArrow::QPushButtonArrow(QWidget * parent) : QPushButton(parent)
{
    setIcon(QIcon(":/arrow.jpeg"));
    connect(this, SIGNAL(clicked()), this, SLOT(on_clicked()));
}

void QPushButtonArrow::on_clicked()
{
    emit display_cnx(pid);
}
