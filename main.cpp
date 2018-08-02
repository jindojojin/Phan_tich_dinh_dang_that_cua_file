#include <QtGui/QApplication>
#include "mainwindow.h"
#include "QThread"
#include "backend.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QThread *thread= new QThread();
    thread->start();
    Backend *backend= new Backend();
    backend->moveToThread(thread);
    QObject::connect(&w,SIGNAL(callBackend(QString)), backend,SLOT(getAllFile(QString)));
    QObject::connect(backend,SIGNAL(sendStringToGui(QString)),&w,SLOT(showInfoToScreen(QString)));
    QObject::connect(backend,SIGNAL(sendResultToTable(QString)),&w,SLOT(showResultToTable(QString)));
    QObject::connect(&w,SIGNAL(resetBackend()),backend,SLOT(resetAll()));
    QObject::connect(backend,SIGNAL(changeProcessBar(int)),&w, SLOT(changeProcessBar(int)));
    QObject::connect(backend,SIGNAL(setProgressRange(int)),&w,SLOT(setProgressRange(int)));
    QObject::connect(&w,SIGNAL(stopProcess()),backend,SLOT(stop()));
    return a.exec();
}
