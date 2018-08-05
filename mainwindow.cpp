#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QDebug"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resetGUI();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resetGUI(){
    this->ui->stackedWidget->setCurrentIndex(1);
    this->setupTable();
    this->setStatus("new");
    this->totalWrongFile= 0;
}

void MainWindow::showInfoToScreen(QString text){
    this->ui->textBrowser->append(text);
}

void MainWindow::showFinishDialog(){
    QString a= QString::fromUtf8("Số tệp tin đã quét: %1 \nSố tệp tin đã phân tích: %2 \nSố tệp tin được phát hiện là đã bị đổi đuôi mở rộng: %3")
            .arg(this->ui->progressBar->maximum())
            .arg(this->ui->progressBar->value())
            .arg(this->totalWrongFile);
    QMessageBox::information(this,QString::fromUtf8("Hoàn tất"),a);
}

void MainWindow::setStatus(QString status){

    if(status== "new"){
        this->ui->stop_btn->setEnabled(false);
        this->ui->change_tab_btn->setEnabled(false);
        this->ui->chose_folder_btn->setEnabled(true);
    }
    else if(status=="running"){
        this->ui->stop_btn->setEnabled(true);
        this->ui->change_tab_btn->setEnabled(true);
        this->ui->chose_folder_btn->setEnabled(false);
        }
    else if(status=="finished"){
        this->ui->stop_btn->setEnabled(false);
        this->ui->change_tab_btn->setEnabled(true);
        this->ui->chose_folder_btn->setEnabled(true);
        }
    else return;
}

void MainWindow::setupTable(){
    this->model = new QStandardItemModel(0,4,this);
    model->setHorizontalHeaderItem(0,new QStandardItem(QString::fromUtf8("Tên tệp tin")));
    model->setHorizontalHeaderItem(1,new QStandardItem(QString::fromUtf8("Định dạng tệp tin")));
    model->setHorizontalHeaderItem(2,new QStandardItem(QString::fromUtf8("Đuôi mở rộng đúng của tệp tin")));
    model->setHorizontalHeaderItem(3,new QStandardItem(QString::fromUtf8("Đường dẫn")));
    this->ui->tableView->setModel(model);
    this->ui->tableView->setAlternatingRowColors(true);
    this->ui->tableView->setColumnWidth(3,700);
    this->ui->tableView->show();
}

void MainWindow::showResultToTable(QString string){
//    qDebug() << "chuyen den table" << string;
    QStringList list = string.split(";");
    QList<QStandardItem *> a;
    foreach(QString b, list){
        qDebug() << b;
        a.append(new QStandardItem(b));
    }
    this->model->appendRow(a);
    this->totalWrongFile ++;
}

void MainWindow::changeProcessBar(int value){
    this->ui->progressBar->setValue(value);
}

void MainWindow::setProgressRange(int maxValue){
    this->ui->progressBar->setRange(0,maxValue);
}

void MainWindow::on_chose_folder_btn_clicked()
{
    QString folder = QFileDialog::getExistingDirectory(this, QString::fromUtf8("Chọn thư mục quét"),
                                                     "/home",
                                                     QFileDialog::ShowDirsOnly
                                                     | QFileDialog::DontResolveSymlinks);
    this->ui->textBrowser->append(QString::fromUtf8("Ðang quét các tệp tin trong thư mục ")+folder+" .....");
    this->ui->label->setText(folder);
    emit renewBackend();
    emit resetBackend();
    emit callBackend(folder);
    this->resetGUI();
    this->setStatus("running");
}

void MainWindow::on_change_tab_btn_clicked()
{
    switch(this->ui->stackedWidget->currentIndex()){
        case 1:{this->ui->stackedWidget->setCurrentIndex(0);
        this->ui->change_tab_btn->setText(QString::fromUtf8("Hiển thị chi tiết quá trình phân tích"));
        break;}
    default:{this->ui->stackedWidget->setCurrentIndex(1); this->ui->change_tab_btn->setText(QString::fromUtf8("Hiện thị các tệp tin đã bị đổi đuôi mở rộng"));};
    }
}

void MainWindow::on_stop_btn_clicked()
{
    qDebug() << "Click to stop";
    emit stopProcess();
}
