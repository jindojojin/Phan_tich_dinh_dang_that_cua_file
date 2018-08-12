#include "file_detail_window.h"
#include "ui_file_detail_window.h"
#include "QProcess"

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


//    file_name_matcher.indexIn(file_information);
//    file_type_matcher.indexIn(file_information);
//    file_extension_matcher.indexIn(file_information);
//    QString fileName = file_name_matcher.cap(2).replace("\\n","");
//    QString fileType = file_type_matcher.cap(2);
//    QString fileExtension = file_extension_matcher.cap(2);
//    emit sendResultToTable_2(fileName+";"+fileType+";"+fileExtension+";"+filePath);
//    if(fileExtension.length() > 0 &&
//            QString::compare(fileExtension,filePath.right(fileExtension.length()),Qt::CaseInsensitive)
//      ){
//        emit sendResultToTable(fileName+";"+fileType+";"+fileExtension+";"+filePath);
//    }
}

void File_Detail_Window::setFilePath(QString file_path){
    this->ui->file_path_label->setText(file_path);
    QProcess process;
    process.start("exif.exe -r \""+file_path+"\"");
    process.waitForFinished();
    QString file_information(process.readAllStandardOutput());
    QRegExp file_name_matcher("(File Name                       : )([^\\n]*)");
    QRegExp file_type_matcher("(File Type                       : )([a-zA-Z0-9]*)");
    QRegExp file_extension_matcher("(File Type Extension             : )([a-zA-Z0-9]*)");
    this->setFileInfor(file_information);
}
