#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QDebug"
#include "QMessageBox"
#include "QDesktopServices"
#include "QUrl"

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
    model->setHorizontalHeaderItem(1,new QStandardItem(QString::fromUtf8("Định dạng tệp tin")));
    model->setHorizontalHeaderItem(2,new QStandardItem(QString::fromUtf8("Đuôi mở rộng đúng")));
    model->setHorizontalHeaderItem(3,new QStandardItem(QString::fromUtf8("Đường dẫn")));
    this->ui->tableView->setModel(model);
    this->ui->tableView->setAlternatingRowColors(true);
    this->ui->tableView->setColumnWidth(1,130);
    this->ui->tableView->setColumnWidth(2,130);
    this->ui->tableView->setColumnWidth(3,700);
    this->csvString.clear();
    this->ui->tableView->show();

    this->model_2 = new QStandardItemModel(0,4,this);
    model_2->setHorizontalHeaderItem(0,new QStandardItem(QString::fromUtf8("Tên tệp tin")));
    model_2->setHorizontalHeaderItem(1,new QStandardItem(QString::fromUtf8("Định dạng tệp tin")));
    model_2->setHorizontalHeaderItem(2,new QStandardItem(QString::fromUtf8("Đuôi mở rộng đúng")));
    model_2->setHorizontalHeaderItem(3,new QStandardItem(QString::fromUtf8("Đường dẫn")));
    this->ui->tableView_2->setModel(model_2);
    this->ui->tableView_2->setAlternatingRowColors(true);
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

void MainWindow::on_chose_folder_btn_clicked()
{
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
        writer<<QString::fromUtf8("Ten tep tin,Dinh dang tep tin,Duoi mo rong dung,Duong dan,")<<endl << this->csvString;
        QMessageBox::information(this,QString::fromUtf8("Hoàn tất"),QString::fromUtf8("Đã xuất thành công kết quả phân tích ra tệp tin csv"));
        file.close();
    }else{QMessageBox::warning(this,QString::fromUtf8("Hoàn tất"), QString::fromUtf8("Đã có lỗi xảy ra, vui lòng thử lại sau!"));}
}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    int row = index.row();
    QString realExtension = index.sibling(row,2).data().toString();
    QString file = index.sibling(row,3).data().toString();
    if(!QFile::copy(file,"review_file."+realExtension)){
        QDesktopServices::openUrl(QUrl("review_file."+realExtension));
    }
}
