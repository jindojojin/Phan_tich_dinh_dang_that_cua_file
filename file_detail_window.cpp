#include "file_detail_window.h"
#include "ui_file_detail_window.h"
#include "QProcess"
#include "mainwindow.h"
#include "QMap"
#include "QDebug"
File_Detail_Window::File_Detail_Window(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::File_Detail_Window)
{
    ui->setupUi(this);
}

File_Detail_Window::~File_Detail_Window()
{
    delete ui;
}

void File_Detail_Window::setFileInfor(QString file_info){
    this->ui->file_infor_label->setText(file_info);
}

void File_Detail_Window::setFilePath(QString file_path){
    this->ui->file_path_label->setText(file_path);
    QProcess process;
    process.start("exif.exe -r \""+file_path+"\"");
    process.waitForFinished();
    QString file_information(process.readAllStandardOutput());
    for (QMap<QString,QString>::iterator it = DICT.begin(); it != DICT.end(); ++it) {
//        qDebug()<< it.key()<<it.value();
        file_information.replace(it.value(),it.key());
    }
    this->setFileInfor(file_information);
}
