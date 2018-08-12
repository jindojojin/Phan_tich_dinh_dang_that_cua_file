#-------------------------------------------------
#
# Project created by QtCreator 2018-07-26T09:30:12
#
#-------------------------------------------------

QT       += core gui

TARGET = FileTypeIndentify
TEMPLATE = app


SOURCES += main.cpp \
        mainwindow.cpp \
    backend.cpp \
    workerthread.cpp \
    file_detail_window.cpp

HEADERS  += mainwindow.h \
    backend.h \
    workerthread.h \
    file_detail_window.h

FORMS    += mainwindow.ui \
    file_detail_window.ui



