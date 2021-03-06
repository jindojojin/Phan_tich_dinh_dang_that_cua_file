﻿#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QDebug"
#include "QMessageBox"
#include "QDesktopServices"
#include "QUrl"
#include "file_detail_window.h"
#include "QMouseEvent"
QMap<QString, QString> DICT;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resetGUI();
    this->readDict();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readDict(){
    QFile dic("dic.dll");
    if(!dic.open(QFile::Text|QFile::ReadOnly)) return;
    QTextStream reader(&dic);
    reader.setCodec("UTF-8");
    while(!reader.atEnd()){
        DICT.insert(reader.readLine(),reader.readLine());
    }
    dic.close();
}

void MainWindow::resetGUI(){
    this->ui->stackedWidget->setCurrentIndex(1);
    this->setupTable();
    this->setStatus("new");
    this->totalWrongFile= 0;
}

void MainWindow::showInfoToScreen(QString text){
    this->ui->label->setText(text);
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
        this->ui->label->setText(QString::fromUtf8("Chọn thư mục để phân tích"));
        this->ui->progressBar->setValue(0);
        this->ui->change_tab_btn->setEnabled(false);
        this->ui->chose_folder_btn->setEnabled(true);
        this->ui->export_csv_btn->setEnabled(false);
    }
    else if(status=="running"){
        this->ui->stop_btn->setEnabled(true);
        this->ui->change_tab_btn->setEnabled(true);
        this->ui->chose_folder_btn->setEnabled(false);
        }
    else if(status=="finished"){
        this->ui->label->setText(QString::fromUtf8("Đã hoàn thành quá trình phân tích"));
        this->ui->stop_btn->setEnabled(false);
        this->ui->change_tab_btn->setEnabled(true);
        this->ui->chose_folder_btn->setEnabled(true);
        }
    else return;
}

void MainWindow::setupTable(){
    this->model = new QStandardItemModel(0,4,this);
    model->setHorizontalHeaderItem(0,new QStandardItem(QString::fromUtf8("Tên tệp tin")));
    model->setHorizontalHeaderItem(1,new QStandardItem(QString::fromUtf8("Kích thước")));
    model->setHorizontalHeaderItem(2,new QStandardItem(QString::fromUtf8("Đuôi mở rộng đúng")));
    model->setHorizontalHeaderItem(3,new QStandardItem(QString::fromUtf8("Đường dẫn")));
    this->ui->tableView->setModel(model);
    this->ui->tableView->setAlternatingRowColors(true);
    this->ui->tableView->setColumnWidth(0,230);
    this->ui->tableView->setColumnWidth(1,130);
    this->ui->tableView->setColumnWidth(2,130);
    this->ui->tableView->setColumnWidth(3,700);
    this->csvString.clear();
    //debug right click menu qtableview
    connect(this,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(create_submenu(QPoint)));
    //
    this->ui->tableView->show();

    this->model_2 = new QStandardItemModel(0,4,this);
    model_2->setHorizontalHeaderItem(0,new QStandardItem(QString::fromUtf8("Tên tệp tin")));
    model_2->setHorizontalHeaderItem(1,new QStandardItem(QString::fromUtf8("Kích thước")));
    model_2->setHorizontalHeaderItem(2,new QStandardItem(QString::fromUtf8("Đuôi mở rộng đúng")));
    model_2->setHorizontalHeaderItem(3,new QStandardItem(QString::fromUtf8("Đường dẫn")));
    this->ui->tableView_2->setModel(model_2);
    this->ui->tableView_2->setAlternatingRowColors(true);
    this->ui->tableView_2->setColumnWidth(1,230);
    this->ui->tableView_2->setColumnWidth(1,130);
    this->ui->tableView_2->setColumnWidth(2,130);
    this->ui->tableView_2->setColumnWidth(3,700);
    this->csvString_2.clear();
    this->ui->tableView_2->show();
}

void MainWindow::showResultToTable(QString string){
//    qDebug() << "chuyen den table" << string;
    QStringList list = string.split(";");
    QList<QStandardItem *> a;
    foreach(QString b, list){
        qDebug() << b;
        a.append(new QStandardItem(b));
        this->csvString.append(b+",");
    }
    this->csvString.append("\n");
    this->model->appendRow(a);
    this->totalWrongFile ++;
}
void MainWindow::showResultToTable_2(QString string){
    QStringList list = string.split(";");
    QList<QStandardItem *> a;
    foreach(QString b, list){
        qDebug() << b;
        a.append(new QStandardItem(b));
        this->csvString_2.append(b+",");
    }
    this->csvString_2.append("\n");
    this->model_2->appendRow(a);
}

void MainWindow::changeProcessBar(int value){
    this->ui->progressBar->setValue(value);
}

void MainWindow::setProgressRange(int maxValue){
    this->ui->progressBar->setRange(0,maxValue);
}

void MainWindow::chose_folder(){
    QString folder = QFileDialog::getExistingDirectory(this, QString::fromUtf8("Chọn thư mục quét"),
                                                     "/home",
                                                     QFileDialog::ShowDirsOnly
                                                     | QFileDialog::DontResolveSymlinks);
    this->ui->label->setText(QString::fromUtf8("Ðang quét các tệp tin trong thư mục ")+folder+" .....");
    this->ui->label->setText(folder);
    emit renewBackend();
    emit resetBackend();
    emit callBackend(folder);
    this->resetGUI();
    this->setStatus("running");
}

void MainWindow::chose_file(){
    QString file = QFileDialog::getOpenFileName(this, QString::fromUtf8("Chọn thư mục quét"),
                                                "/home");
    this->ui->label->setText(QString::fromUtf8("Phân tích tệp tin :")+file);
    File_Detail_Window *f = new File_Detail_Window();
    f->setFilePath(file);
    f->show();
}

void MainWindow::on_chose_folder_btn_clicked()
{
    this->chose_folder();
}

void MainWindow::on_change_tab_btn_clicked()
{
    switch(this->ui->stackedWidget->currentIndex()){
        case 1:{this->ui->stackedWidget->setCurrentIndex(0);
        this->ui->change_tab_btn->setText(QString::fromUtf8("Hiển thị chi tiết quá trình phân tích"));
        this->ui->export_csv_btn->setEnabled(true);
        break;}
    default:{this->ui->stackedWidget->setCurrentIndex(1);
        this->ui->change_tab_btn->setText(QString::fromUtf8("Hiện thị các tệp tin đã bị đổi đuôi mở rộng"));
        this->ui->export_csv_btn->setEnabled(false);
    };
    }
}

void MainWindow::on_stop_btn_clicked()
{
    qDebug() << "Click to stop";
    emit stopProcess();
    this->setStatus("finished");
}

void MainWindow::on_export_csv_btn_clicked()
{

//    qDebug() << "Export csv file";
//    qDebug() << this->csvString;
    QString filename = QFileDialog::getSaveFileName(this,"save file","Ket_qua_phan_tich_",".csv");
    qDebug() << filename;
    QFile file(filename);
    if(file.open(QIODevice::WriteOnly)){
        QTextStream writer(&file);
        writer.setCodec("UTF-8");
        writer<<QString::fromUtf8("Ten tep tin,Kich thuoc,Duoi mo rong dung,Duong dan,")<<endl << this->csvString;
        QMessageBox::information(this,QString::fromUtf8("Hoàn tất"),QString::fromUtf8("Đã xuất thành công kết quả phân tích ra tệp tin csv"));
        file.close();
    }else{QMessageBox::warning(this,QString::fromUtf8("Hoàn tất"), QString::fromUtf8("Đã có lỗi xảy ra, vui lòng thử lại sau!"));}
}


void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    this->index_triggered = index;
    this->viewDetail();
}

void MainWindow::on_actionChonTepTin_triggered()
{
    this->chose_file();
}

void MainWindow::on_actionChonThuMuc_triggered()
{
    this->chose_folder();
}

void MainWindow::reviewFile(){
    int row = this->index_triggered.row();
    QString realExtension = this->index_triggered.sibling(row,2).data().toString();
    if(realExtension == ""){
        QMessageBox::warning(this,QString::fromUtf8("Lỗi"),
                             QString::fromUtf8("Chưa xác định được định dạng đúng của tệp tin này, hãy mở tập tin bằng cách thông thường!"));
        return;
    }
    QString file = this->index_triggered.sibling(row,3).data().toString();// file path
    QString fileName = this->index_triggered.sibling(row,0).data().toString();
    QString fileToCoppy = QFileDialog::getSaveFileName(this,QString::fromUtf8("Tệp tin sẽ được sao chép vào ...")
                                                       ,fileName+"review."+realExtension,"."+realExtension);
    qDebug()<< fileToCoppy;
//    QMessageBox::information(this,"",QString::fromUtf8("Đang sao chép tệp tin"),NULL,NULL);
    if(QFile::copy(file,fileToCoppy)){
        QDesktopServices::openUrl(QUrl(fileToCoppy));
    }else{
        QMessageBox::warning(this,QString::fromUtf8("Lỗi"), QString::fromUtf8("Đã có lỗi xảy ra trong quá trình sao chép tệp tin, vui lòng thử lại sau!"));
    }
}
void MainWindow::qickOpenFile(){
    int row = this->index_triggered.row();
    QString file = this->index_triggered.sibling(row,3).data().toString();
    QFile path(file);
    if(path.exists()){
        if(!QDesktopServices::openUrl(QUrl::fromLocalFile(file))){
            QMessageBox::warning(this,QString::fromUtf8("Lỗi"), QString::fromUtf8("Không thể mở tệp tin bằng cách thông thường"));
        }
    }else{
        QMessageBox::warning(this,QString::fromUtf8("Lỗi"), QString::fromUtf8("Tệp tin không còn tồn tại"));
    }
}
void MainWindow::viewDetail(){
    int row = this->index_triggered.row();
    QString realExtension = this->index_triggered.sibling(row,2).data().toString();
    QString file = this->index_triggered.sibling(row,3).data().toString();
    File_Detail_Window *f = new File_Detail_Window();
    f->setFilePath(file);
    f->show();
}

void MainWindow::create_submenu(QPoint pos){
    qDebug()<<"submenu created!";
    if(!this->index_triggered.isValid()) return;
    QMenu *menu = new QMenu(this->ui->tableView);
    QAction *QickOpen = new QAction(QString::fromUtf8("Mở tệp tin này bằng cách thông thường"),menu);
    menu->addAction(QickOpen);
    QAction *Open = new QAction(QString::fromUtf8("Mở tệp tin này với định dạng đúng"),menu);
    menu->addAction(Open);
    QAction *ViewDetail = new QAction(QString::fromUtf8("Xem chi tiết phân tích tệp tin này"),menu);
    menu->addAction(ViewDetail);
    QPoint newPoint = this->ui->tableView->mapToGlobal(pos);
    menu->mapToParent(newPoint);
    menu->move(newPoint);
    menu->show();
    connect(Open,SIGNAL(triggered()),this,SLOT(reviewFile()));
    connect(ViewDetail,SIGNAL(triggered()),this,SLOT(viewDetail()));
    connect(QickOpen,SIGNAL(triggered()),this, SLOT(qickOpenFile()));
}

void MainWindow::on_tableView_customContextMenuRequested(const QPoint &pos)
{
    this->index_triggered = this->ui->tableView->indexAt(pos);
    this->create_submenu(pos);

}

void MainWindow::on_tableView_2_customContextMenuRequested(const QPoint &pos)
{
    this->index_triggered = this->ui->tableView_2->indexAt(pos);
    this->create_submenu(pos);
}
