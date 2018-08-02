/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Thu Aug 2 16:20:13 2018
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QStackedWidget>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QTextBrowser>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionChonTepTin;
    QAction *actionChonThuMuc;
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *pushButton;
    QProgressBar *progressBar;
    QPushButton *pushButton_3;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout_4;
    QTableView *tableView;
    QWidget *page_2;
    QGridLayout *gridLayout_3;
    QTextBrowser *textBrowser;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QMenu *menuTepTin;
    QMenu *menuCaiDat;
    QMenu *menuHienThi;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(802, 489);
    actionChonTepTin = new QAction(MainWindow);
    actionChonTepTin->setObjectName(QString::fromUtf8("actionChonTepTin"));
    actionChonThuMuc = new QAction(MainWindow);
    actionChonThuMuc->setObjectName(QString::fromUtf8("actionChonThuMuc"));
    centralWidget = new QWidget(MainWindow);
    centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
    gridLayout_2 = new QGridLayout(centralWidget);
    gridLayout_2->setSpacing(6);
    gridLayout_2->setMargin(11);
    gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
    gridLayout = new QGridLayout();
    gridLayout->setSpacing(6);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    label = new QLabel(centralWidget);
    label->setObjectName(QString::fromUtf8("label"));
    label->setWordWrap(true);

    gridLayout->addWidget(label, 0, 0, 1, 1);

    pushButton = new QPushButton(centralWidget);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));

    gridLayout->addWidget(pushButton, 0, 1, 1, 1);

    progressBar = new QProgressBar(centralWidget);
    progressBar->setObjectName(QString::fromUtf8("progressBar"));
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
    progressBar->setSizePolicy(sizePolicy);
    progressBar->setMaximum(0);
    progressBar->setValue(0);
    progressBar->setTextVisible(true);
    progressBar->setInvertedAppearance(false);
    progressBar->setTextDirection(QProgressBar::BottomToTop);
    progressBar->setFormat(QString::fromUtf8("%v/%m"));

    gridLayout->addWidget(progressBar, 1, 0, 1, 1);

    pushButton_3 = new QPushButton(centralWidget);
    pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

    gridLayout->addWidget(pushButton_3, 1, 1, 1, 1);

    stackedWidget = new QStackedWidget(centralWidget);
    stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
    page = new QWidget();
    page->setObjectName(QString::fromUtf8("page"));
    gridLayout_4 = new QGridLayout(page);
    gridLayout_4->setSpacing(6);
    gridLayout_4->setMargin(11);
    gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
    tableView = new QTableView(page);
    tableView->setObjectName(QString::fromUtf8("tableView"));
    tableView->setAutoFillBackground(true);
    tableView->setStyleSheet(QString::fromUtf8(""));
    tableView->setGridStyle(Qt::SolidLine);

    gridLayout_4->addWidget(tableView, 0, 0, 1, 1);

    stackedWidget->addWidget(page);
    page_2 = new QWidget();
    page_2->setObjectName(QString::fromUtf8("page_2"));
    gridLayout_3 = new QGridLayout(page_2);
    gridLayout_3->setSpacing(6);
    gridLayout_3->setMargin(11);
    gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
    textBrowser = new QTextBrowser(page_2);
    textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
    QFont font;
    font.setPointSize(12);
    textBrowser->setFont(font);
    textBrowser->setFrameShape(QFrame::NoFrame);
    textBrowser->setFrameShadow(QFrame::Sunken);

    gridLayout_3->addWidget(textBrowser, 0, 0, 2, 1);

    stackedWidget->addWidget(page_2);

    gridLayout->addWidget(stackedWidget, 2, 0, 1, 2);

    pushButton_2 = new QPushButton(centralWidget);
    pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

    gridLayout->addWidget(pushButton_2, 3, 0, 1, 2);


    gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

    MainWindow->setCentralWidget(centralWidget);
    menuBar = new QMenuBar(MainWindow);
    menuBar->setObjectName(QString::fromUtf8("menuBar"));
    menuBar->setGeometry(QRect(0, 0, 802, 25));
    menuTepTin = new QMenu(menuBar);
    menuTepTin->setObjectName(QString::fromUtf8("menuTepTin"));
    menuCaiDat = new QMenu(menuBar);
    menuCaiDat->setObjectName(QString::fromUtf8("menuCaiDat"));
    menuHienThi = new QMenu(menuBar);
    menuHienThi->setObjectName(QString::fromUtf8("menuHienThi"));
    MainWindow->setMenuBar(menuBar);
    mainToolBar = new QToolBar(MainWindow);
    mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
    MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
    statusBar = new QStatusBar(MainWindow);
    statusBar->setObjectName(QString::fromUtf8("statusBar"));
    MainWindow->setStatusBar(statusBar);

    menuBar->addAction(menuTepTin->menuAction());
    menuBar->addAction(menuCaiDat->menuAction());
    menuBar->addAction(menuHienThi->menuAction());
    menuTepTin->addAction(actionChonTepTin);
    menuTepTin->addAction(actionChonThuMuc);

    retranslateUi(MainWindow);

    stackedWidget->setCurrentIndex(0);


    QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
    actionChonTepTin->setText(QApplication::translate("MainWindow", "Ch\341\273\215n t\341\273\207p tin ph\303\242n t\303\255ch", 0, QApplication::UnicodeUTF8));
    actionChonThuMuc->setText(QApplication::translate("MainWindow", "Ch\341\273\215n th\306\260 m\341\273\245c ph\303\242n t\303\255ch", 0, QApplication::UnicodeUTF8));
    label->setText(QString());
    pushButton->setText(QApplication::translate("MainWindow", "Ch\341\273\215n folder", 0, QApplication::UnicodeUTF8));
    pushButton_3->setText(QApplication::translate("MainWindow", "D\341\273\253ng", 0, QApplication::UnicodeUTF8));
    pushButton_2->setText(QApplication::translate("MainWindow", "Hi\341\273\207n c\303\241c file \304\221\303\243 b\341\273\213 \304\221\341\273\225i \304\221u\303\264i", 0, QApplication::UnicodeUTF8));
    menuTepTin->setTitle(QApplication::translate("MainWindow", "T\341\273\207p tin", 0, QApplication::UnicodeUTF8));
    menuCaiDat->setTitle(QApplication::translate("MainWindow", "C\303\240i \304\221\341\272\267t", 0, QApplication::UnicodeUTF8));
    menuHienThi->setTitle(QApplication::translate("MainWindow", "Hi\341\273\203n th\341\273\213", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
