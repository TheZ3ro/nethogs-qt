QT += core gui network
QT += charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = nethogs-qt
TEMPLATE = app

SOURCES += src/main.cpp\
    src/mainwindow.cpp \
    src/scanthread.cpp \
    src/refreshthread.cpp \
    src/linebandwith.cpp \
    src/smallchart.cpp \
    src/qpushbuttonarrow.cpp \
    src/nethogs/connection.cpp \
    src/nethogs/conninode.cpp \
    src/nethogs/devices.cpp \
    src/nethogs/inode2prog.cpp \
    src/nethogs/packet.cpp \
    src/nethogs/process.cpp \
    src/nethogs/decpcap.c

HEADERS += src/mainwindow.h \
    src/scanthread.h \
    src/refreshthread.h \
    src/linebandwith.h \
    src/smallchart.h \
    src/qpushbuttonarrow.h \
    src/nethogs/connection.h \
    src/nethogs/conninode.h \
    src/nethogs/decpcap.h \
    src/nethogs/devices.h \
    src/nethogs/inode2prog.h \
    src/nethogs/nethogs.h \
    src/nethogs/packet.h \
    src/nethogs/process.h

FORMS += src/mainwindow.ui

#CONFIG += -DDEBUG=1
#CONFIG += link_pkgconfig
#PKGCONFIG += pcap
#PKGCONFIG += geoip TODO ;-)

CONFIG += -O2 -Wall

LIBS += -lpcap -lm

RESOURCES += \
    src/icons/nethogs-qt.qrc
