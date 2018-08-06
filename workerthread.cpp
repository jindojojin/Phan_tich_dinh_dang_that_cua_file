#include "workerthread.h"

WorkerThread::WorkerThread(QObject *parent) :
    QThread(parent)
{
    this->ter = false;
}
bool WorkerThread::isTer() {
    return this->ter;
};
void WorkerThread::term() {
    this->ter = true;
};
void WorkerThread::restart(){
    this->ter = false;
}
