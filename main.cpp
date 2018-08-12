#include <QtGui/QApplication>
#include "mainwindow.h"
#include "QThread"
#include "backend.h"
#include "workerthread.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    WorkerThread *thread= new WorkerThread();
    thread->start();
    Backend *backend= new Backend();
    backend->moveToThread(thread);
    QObject::connect(&w,SIGNAL(callBackend(QString)), backend,SLOT(getAllFile(QString)));
    QObject::connect(backend,SIGNAL(sendStringToGui(QString)),&w,SLOT(showInfoToScreen(QString)));
    QObject::connect(backend,SIGNAL(sendResultToTable(QString)),&w,SLOT(showResultToTable(QString)));
    QObject::connect(backend,SIGNAL(sendResultToTable_2(QString)),&w,SLOT(showResultToTable_2(QString)));
    QObject::connect(&w,SIGNAL(resetBackend()),backend,SLOT(resetAll()));
    QObject::connect(backend,SIGNAL(changeProcessBar(int)),&w, SLOT(changeProcessBar(int)));
    QObject::connect(backend,SIGNAL(setProgressRange(int)),&w,SLOT(setProgressRange(int)));
    QObject::connect(&w,SIGNAL(stopProcess()),thread,SLOT(term()));
    QObject::connect(&w,SIGNAL(renewBackend()),thread,SLOT(restart()));
    QObject::connect(backend,SIGNAL(showFinishDialog()),&w, SLOT(showFinishDialog()));
    QObject::connect(backend,SIGNAL(setStatus(QString)),&w, SLOT(setStatus(QString)));


    return a.exec();
}
