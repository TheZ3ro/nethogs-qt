/*
 * mainwindow.h
 *
 * Copyright (c) 2016 Stephane List
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QElapsedTimer>
#include <QHostInfo>

#include "scanthread.h"
#include "refreshthread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ScanThread *scanThread;
    RefreshThread *refreshThread;
    int searchRow(int pid);
    QString searchIcon(const QString & procname);
  //  QElapsedTimer timer;
    QString uid2username(uid_t uid);
    quint64 total_speed_recv;
    quint64 total_speed_sent;

public slots:
    void refreshLine(const QString& procname, quint64 rcv, quint64 sent, int pid, unsigned int uid, const QString& devname);
    void deleteLine(int pid);
    void updateGraph();
    void update_cnx_list(int pid);
    void cnxDetected(const QHostAddress& sourceip, quint16 sport, const QHostAddress& destip, quint16 dport);
    void lookedUp(const QHostInfo &host);


private slots:
    void on_actionAbout_Qt_triggered();
    void on_actionAbout_triggered();
    void on_actionExit_triggered();

    void on_actionReset_triggered();

    void on_pushButton_back_clicked();

signals:
    void new_speed(quint64,quint64);
    void reset_graph();

};

#endif // MAINWINDOW_H
