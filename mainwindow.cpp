#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QDebug"
#include "QDir"
#include "QFileInfo"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->stackedWidget->setCurrentIndex(1);
    this->setupTable();
    this->QICK_STOP = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showInfoToScreen(QString text){
    this->ui->textBrowser->append(text);
}

void MainWindow::setupTable(){
    this->model = new QStandardItemModel(0,4,this);
    model->setHorizontalHeaderItem(0,new QStandardItem(QString("Ten file")));
    model->setHorizontalHeaderItem(1,new QStandardItem(QString("Kieu file")));
    model->setHorizontalHeaderItem(2,new QStandardItem(QString("Duoi file goc")));
    model->setHorizontalHeaderItem(3,new QStandardItem(QString("Duong dan")));
    this->ui->tableView->setModel(model);
    this->ui->tableView->setAlternatingRowColors(true);
    this->ui->tableView->adjustSize();
    this->ui->tableView->setColumnWidth(3,700);
    this->ui->tableView->show();
}

void MainWindow::showResultToTable(QString string){
    qDebug() << "chuyen den table" << string;
    QStringList list = string.split(";");
    QList<QStandardItem *> a;
    foreach(QString b, list){
        qDebug() << b;
        a.append(new QStandardItem(b));
    }
    this->model->appendRow(a);
}

void MainWindow::changeProcessBar(int value){
    this->ui->progressBar->setValue(value);
}
void MainWindow::setProgressRange(int maxValue){
    this->ui->progressBar->setRange(0,maxValue);
}


void MainWindow::on_pushButton_clicked()
{
//    this->ui->stackedWidget->setCurrentIndex(0);
    this->folder = QFileDialog::getExistingDirectory(this, tr("Chon thu muc quet"),
                                                     "/home",
                                                     QFileDialog::ShowDirsOnly
                                                     | QFileDialog::DontResolveSymlinks);
    this->ui->textBrowser->append("Ðang doc thu muc "+this->folder+" .....");
    this->ui->label->setText(this->folder);
    emit resetBackend();
    emit callBackend(this->folder);
}

void MainWindow::on_pushButton_2_clicked()
{
    switch(this->ui->stackedWidget->currentIndex()){
        case 1:{this->ui->stackedWidget->setCurrentIndex(0);
        this->ui->pushButton_2->setText(QString::fromUtf8("Xin chào"));
        break;}
    default:{this->ui->stackedWidget->setCurrentIndex(1); this->ui->pushButton_2->setText(QString::fromUtf8("Hi?n th? các file b? d?i duôi"));};
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    qDebug() << "Click to stop";
    emit stopProcess();
}
