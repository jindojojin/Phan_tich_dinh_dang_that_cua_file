#ifndef WORKERTHREAD_H
#define WORKERTHREAD_H

#include <QThread>

class WorkerThread : public QThread
{
    Q_OBJECT
public:
    explicit WorkerThread(QObject *parent = 0);
    bool isTer();
private:
    bool ter;
signals:

public slots:
    void term();
    void restart();
};

#endif // WORKERTHREAD_H
