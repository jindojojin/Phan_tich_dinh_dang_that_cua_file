#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegExp>
#include <QStandardItemModel>
#include <QThread>
#include "backend.h"
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

    void on_chose_folder_btn_clicked();

    void on_change_tab_btn_clicked();

    void on_stop_btn_clicked();

private:
    QStandardItemModel *model;
    Ui::MainWindow *ui;
    QString folder;
    int totalWrongFile;
    void resetGUI();
    void setupTable();
    QThread * thread;
    Backend * backend;
signals:
    void callBackend(QString);
    void resetBackend();
    void stopProcess();
    void renewBackend();// khoi dong lai backend sau khi bi dung
public slots:
    void showInfoToScreen(QString);
    void showResultToTable(QString);
    void changeProcessBar(int);
    void setProgressRange(int);
    void showFinishDialog();
    void setStatus(QString); //thiet lap trang thai cua giao dien do hoa
};


#endif // MAINWINDOW_H
