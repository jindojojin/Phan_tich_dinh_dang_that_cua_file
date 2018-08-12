/********************************************************************************
** Form generated from reading ui file 'file_detail_window.ui'
**
** Created: Sun Aug 12 21:34:40 2018
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
#include <QtGui/QLabel>
#include <QtGui/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_File_Detail_Window
{
public:
    QTextBrowser *file_infor_label;
    QLabel *label;
    QLabel *file_path_label;

    void setupUi(QFrame *File_Detail_Window)
    {
    if (File_Detail_Window->objectName().isEmpty())
        File_Detail_Window->setObjectName(QString::fromUtf8("File_Detail_Window"));
    File_Detail_Window->resize(690, 517);
    File_Detail_Window->setFrameShape(QFrame::StyledPanel);
    File_Detail_Window->setFrameShadow(QFrame::Raised);
    file_infor_label = new QTextBrowser(File_Detail_Window);
    file_infor_label->setObjectName(QString::fromUtf8("file_infor_label"));
    file_infor_label->setGeometry(QRect(20, 50, 651, 451));
    QFont font;
    font.setPointSize(9);
    file_infor_label->setFont(font);
    label = new QLabel(File_Detail_Window);
    label->setObjectName(QString::fromUtf8("label"));
    label->setGeometry(QRect(20, 20, 111, 16));
    label->setFont(font);
    file_path_label = new QLabel(File_Detail_Window);
    file_path_label->setObjectName(QString::fromUtf8("file_path_label"));
    file_path_label->setGeometry(QRect(140, 20, 531, 16));
    file_path_label->setFont(font);

    retranslateUi(File_Detail_Window);

    QMetaObject::connectSlotsByName(File_Detail_Window);
    } // setupUi

    void retranslateUi(QFrame *File_Detail_Window)
    {
    File_Detail_Window->setWindowTitle(QApplication::translate("File_Detail_Window", "Frame", 0, QApplication::UnicodeUTF8));
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
