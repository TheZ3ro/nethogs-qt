/*
 * scanthread.h
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


#ifndef SCANTHREAD_H
#define SCANTHREAD_H

#include <QThread>


#include <netinet/ip.h>
#include <netinet/ip6.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>

extern "C" {
#include "decpcap.h"
}

class ScanThread : public QThread
{
    Q_OBJECT
public:
    explicit ScanThread(QObject *parent = 0);
    void run();

signals:

public slots:
};


struct dpargs {
    const char * device;
    int sa_family;
    in_addr ip_src;
    in_addr ip_dst;
    in6_addr ip6_src;
    in6_addr ip6_dst;
};


class handle {
public:
    handle (dp_handle * m_handle, const char * m_devicename = NULL,
            handle * m_next = NULL) {
        content = m_handle; next = m_next; devicename = m_devicename;
    }
    dp_handle * content;
    const char * devicename;
    handle * next;
};

#endif // SCANTHREAD_H
