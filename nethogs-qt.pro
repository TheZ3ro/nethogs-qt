#-------------------------------------------------
#
# Project created by QtCreator 2016-09-29T17:28:12
#
#-------------------------------------------------

QT       += core gui network
QT += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = nethogs-qt
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    connection.cpp \
    conninode.cpp \
    devices.cpp \
    inode2prog.cpp \
    packet.cpp \
    process.cpp \
    decpcap.c \
    scanthread.cpp \
    refreshthread.cpp \
    linebandwith.cpp \
    smallchart.cpp \
    qpushbuttonarrow.cpp

HEADERS  += mainwindow.h \
    connection.h \
    conninode.h \
    decpcap.h \
    devices.h \
    inode2prog.h \
    nethogs.h \
    packet.h \
    process.h \
    scanthread.h \
    refreshthread.h \
    linebandwith.h \
    smallchart.h \
    qpushbuttonarrow.h

FORMS    += mainwindow.ui

#CONFIG += -DDEBUG=1
#CONFIG += link_pkgconfig
#PKGCONFIG += pcap

#PKGCONFIG += geoip TODO ;-)

CONFIG += -O2 -Wall

LIBS += -lpcap -lm

RESOURCES += \
    nethogs-qt.qrc
