#include "backend.h"
#include "QProcess"
#include "QDebug"
#include "QDir"
#include "QThread"
#include "workerthread.h"
Backend::Backend(QObject *parent) :
    QObject(parent)
{
}

void Backend::resetAll(){
    this->totalFolders =0;
    this->files.clear();
    emit
    this->isTotalFileEqualZero=false;
}

void Backend::getAllFile(QString folder_path){
    if(((WorkerThread *) QThread::currentThread())->isTer()){
        return;}
    QDir folder(folder_path);
    this->totalFolders+= (folder.count() -2); // dem so thu muc + tep tin trong folder nay

    QStringList files = folder.entryList(QDir::Files|QDir::NoDotAndDotDot);
    foreach(QString b, files){
        this->totalFolders -= 1;
        this->files.append(folder_path+"/"+b);
        emit sendStringToGui(folder_path+"/"+b);
    }
    QStringList dirs = folder.entryList(QDir::Dirs| QDir::NoDotAndDotDot);
    foreach(QString b, dirs){
        this->totalFolders -= 1;
        this->getAllFile(folder_path+"/"+ b);
    }
    if(this->totalFolders ==0 && !(this->isTotalFileEqualZero) && !((WorkerThread *) QThread::currentThread())->isTer()){
        this->isTotalFileEqualZero = true;
        qDebug()<< "Tong so file: "<< this->files.size();
        emit setProgressRange(this->files.size());
        this-> readInfo();
    }
}
void Backend::readInfo(){
    int current = 0;
    emit sendStringToGui(QString::fromUtf8("Ðang phân tích các tệp tin ...."));
    foreach(QString str, this->files){
        if(((WorkerThread *) QThread::currentThread())->isTer()) {this->resetAll();break;}
//        qDebug() << ((WorkerThread *) QThread::currentThread())->isTer();
        current++;
        this->run(str);
        emit changeProcessBar(current);
    }
    emit showFinishDialog();
    emit setStatus("finished");
//    qDebug() << ((WorkerThread *) QThread::currentThread())->isTer();

}

void Backend::run(QString filePath){
    QProcess process;
//    ui->showInfoToScreen("Dang doc file " + filePath);
    process.start("exif.exe -r \""+filePath+"\"");
    process.waitForFinished();
    QString file_information(process.readAllStandardOutput());
    QRegExp file_name_matcher("(File Name                       : )([^\\n]*)");
    QRegExp file_size_matcher("(File Size                       : )([a-zA-Z0-9 \.]*)");
    QRegExp file_extension_matcher("(File Type Extension             : )([a-zA-Z0-9]*)");
    file_name_matcher.indexIn(file_information);
    file_size_matcher.indexIn(file_information);
    file_extension_matcher.indexIn(file_information);
    QString fileName1 = file_name_matcher.cap(2);
    QString fileName = fileName1.left(fileName1.length()-1);//bo ki tu /n
    QString fileType = file_size_matcher.cap(2);
    QString fileExtension = file_extension_matcher.cap(2);
//    QString output;
//    output = " file path: " + filePath + " real type: "+file_size_matcher.cap(2) + " real extension: "+file_extension_matcher.cap(2);
    emit sendResultToTable_2(fileName+";"+fileType+";"+fileExtension+";"+filePath);
    //Kiem tra duoi file co bi thay doi khong
    if(fileExtension.length() > 0 &&
            QString::compare(fileExtension,filePath.right(fileExtension.length()),Qt::CaseInsensitive)
      ){
        emit sendResultToTable(fileName+";"+fileType+";"+fileExtension+";"+filePath);
    }
    this->addToDict(file_information);
}

void Backend::addToDict(QString ifo){
    QFile file("dict.txt");
    file.open(QFile::Text|QFile::WriteOnly| QFile::Append);
    QTextStream writer(&file);
    writer << ifo;
    file.close();
}
