#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegExp>
#include <QStandardItemModel>
#include <QThread>
#include "backend.h"
#include "QMap"
extern QMap<QString,QString> DICT;
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
    void on_export_csv_btn_clicked();
    void on_tableView_doubleClicked(const QModelIndex &index);
    void on_actionChonTepTin_triggered();
    void on_actionChonThuMuc_triggered();
    void viewDetail();
    void create_submenu(QPoint);
    void on_tableView_customContextMenuRequested(const QPoint &pos);

    void on_tableView_2_customContextMenuRequested(const QPoint &pos);

private:
    void readDict();
    QStandardItemModel *model;
    QStandardItemModel *model_2;
    Ui::MainWindow *ui;
    QString csvString; //save wrong file only
    QString csvString_2; // save total result
    QModelIndex index_triggered;
    int totalWrongFile;
    void resetGUI();
    void setupTable();
    void chose_folder();
    void chose_file();
    QThread * thread;
    Backend * backend;
signals:
    void callBackend(QString);
    void resetBackend();
    void stopProcess();
    void renewBackend();// khoi dong lai backend sau khi bi dung
    void itemClick();
public slots:
    void showInfoToScreen(QString);
    void showResultToTable(QString);
    void showResultToTable_2(QString);
    void changeProcessBar(int);
    void setProgressRange(int);
    void showFinishDialog();
    void reviewFile();
    void qickOpenFile();
    void setStatus(QString); //thiet lap trang thai cua giao dien do hoa
};


#endif // MAINWINDOW_H
