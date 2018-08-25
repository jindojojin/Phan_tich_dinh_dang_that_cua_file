/********************************************************************************
** Form generated from reading ui file 'file_detail_window.ui'
**
** Created: Sat Aug 25 15:54:06 2018
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_FILE_DETAIL_WINDOW_H
#define UI_FILE_DETAIL_WINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QLabel>
#include <QtGui/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_File_Detail_Window
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QTextBrowser *file_infor_label;
    QLabel *file_path_label;

    void setupUi(QFrame *File_Detail_Window)
    {
    if (File_Detail_Window->objectName().isEmpty())
        File_Detail_Window->setObjectName(QString::fromUtf8("File_Detail_Window"));
    File_Detail_Window->resize(690, 517);
    File_Detail_Window->setFrameShape(QFrame::StyledPanel);
    File_Detail_Window->setFrameShadow(QFrame::Raised);
    gridLayout = new QGridLayout(File_Detail_Window);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    label = new QLabel(File_Detail_Window);
    label->setObjectName(QString::fromUtf8("label"));
    QFont font;
    font.setPointSize(9);
    label->setFont(font);

    gridLayout->addWidget(label, 0, 0, 1, 1);

    file_infor_label = new QTextBrowser(File_Detail_Window);
    file_infor_label->setObjectName(QString::fromUtf8("file_infor_label"));
    QFont font1;
    font1.setFamily(QString::fromUtf8("Courier New"));
    font1.setPointSize(16);
    file_infor_label->setFont(font1);

    gridLayout->addWidget(file_infor_label, 2, 0, 1, 2);

    file_path_label = new QLabel(File_Detail_Window);
    file_path_label->setObjectName(QString::fromUtf8("file_path_label"));
    QFont font2;
    font2.setPointSize(10);
    file_path_label->setFont(font2);

    gridLayout->addWidget(file_path_label, 1, 0, 1, 1);


    retranslateUi(File_Detail_Window);

    QMetaObject::connectSlotsByName(File_Detail_Window);
    } // setupUi

    void retranslateUi(QFrame *File_Detail_Window)
    {
    File_Detail_Window->setWindowTitle(QApplication::translate("File_Detail_Window", "Xem chi ti\341\272\277t t\341\273\207p tin", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("File_Detail_Window", "Th\303\264ng tin t\341\273\207p tin :", 0, QApplication::UnicodeUTF8));
    file_path_label->setText(QString());
    Q_UNUSED(File_Detail_Window);
    } // retranslateUi

};

namespace Ui {
    class File_Detail_Window: public Ui_File_Detail_Window {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILE_DETAIL_WINDOW_H
