#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegExp>
#include <QStandardItemModel>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    QStandardItemModel *model;
    Ui::MainWindow *ui;
    QString folder;
    void setupTable();
    bool QICK_STOP;
signals:
    void callBackend(QString);
    void resetBackend();
    void stopProcess();
public slots:
    void showInfoToScreen(QString);
    void showResultToTable(QString);
    void changeProcessBar(int);
    void setProgressRange(int);
};


#endif // MAINWINDOW_H
