#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>

class Backend : public QObject
{
    Q_OBJECT
public:
    explicit Backend(QObject *parent = 0);
private:
    bool running;
    bool isTotalFileEqualZero;
    QList<QString> files;
    int totalFolders;
    void readInfo();
    void addToDict(QString); //add line to dict to translation
signals:
    void sendStringToGui(QString);
    void sendResultToTable(QString);
    void sendResultToTable_2(QString);
    void changeProcessBar(int);
    void setProgressRange(int);
    void showFinishDialog();
    void setStatus(QString);
public slots:
    void run(QString);
    void getAllFile(QString);
    void resetAll();
};

#endif // BACKEND_H
