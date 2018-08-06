/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Mon Aug 6 18:31:45 2018
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
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionChonTepTin;
    QAction *actionChonThuMuc;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *chose_folder_btn;
    QProgressBar *progressBar;
    QPushButton *stop_btn;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout_4;
    QTableView *tableView;
    QWidget *page_2;
    QGridLayout *gridLayout_3;
    QTableView *tableView_2;
    QPushButton *change_tab_btn;
    QPushButton *export_csv_btn;
    QMenuBar *menuBar;
    QMenu *menuTepTin;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(762, 497);
    actionChonTepTin = new QAction(MainWindow);
    actionChonTepTin->setObjectName(QString::fromUtf8("actionChonTepTin"));
    actionChonThuMuc = new QAction(MainWindow);
    actionChonThuMuc->setObjectName(QString::fromUtf8("actionChonThuMuc"));
    centralWidget = new QWidget(MainWindow);
    centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
    gridLayout = new QGridLayout(centralWidget);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(11);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    label = new QLabel(centralWidget);
    label->setObjectName(QString::fromUtf8("label"));
    QFont font;
    font.setPointSize(11);
    label->setFont(font);
    label->setWordWrap(true);

    gridLayout->addWidget(label, 0, 0, 1, 1);

    chose_folder_btn = new QPushButton(centralWidget);
    chose_folder_btn->setObjectName(QString::fromUtf8("chose_folder_btn"));
    QFont font1;
    font1.setPointSize(10);
    chose_folder_btn->setFont(font1);
    chose_folder_btn->setCursor(QCursor(Qt::PointingHandCursor));

    gridLayout->addWidget(chose_folder_btn, 0, 1, 1, 1);

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

    stop_btn = new QPushButton(centralWidget);
    stop_btn->setObjectName(QString::fromUtf8("stop_btn"));
    stop_btn->setFont(font1);
    stop_btn->setCursor(QCursor(Qt::PointingHandCursor));

    gridLayout->addWidget(stop_btn, 1, 1, 1, 1);

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
    tableView->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
    tableView->setAutoFillBackground(true);
    tableView->setStyleSheet(QString::fromUtf8(""));
    tableView->setEditTriggers(QAbstractItemView::EditKeyPressed);
    tableView->setGridStyle(Qt::SolidLine);
    tableView->setSortingEnabled(true);

    gridLayout_4->addWidget(tableView, 0, 0, 1, 3);

    stackedWidget->addWidget(page);
    page_2 = new QWidget();
    page_2->setObjectName(QString::fromUtf8("page_2"));
    gridLayout_3 = new QGridLayout(page_2);
    gridLayout_3->setSpacing(6);
    gridLayout_3->setMargin(11);
    gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
    tableView_2 = new QTableView(page_2);
    tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
    tableView_2->setSortingEnabled(true);

    gridLayout_3->addWidget(tableView_2, 0, 0, 1, 1);

    stackedWidget->addWidget(page_2);

    gridLayout->addWidget(stackedWidget, 2, 0, 1, 2);

    change_tab_btn = new QPushButton(centralWidget);
    change_tab_btn->setObjectName(QString::fromUtf8("change_tab_btn"));
    change_tab_btn->setFont(font1);
    change_tab_btn->setCursor(QCursor(Qt::PointingHandCursor));

    gridLayout->addWidget(change_tab_btn, 3, 0, 1, 1);

    export_csv_btn = new QPushButton(centralWidget);
    export_csv_btn->setObjectName(QString::fromUtf8("export_csv_btn"));
    export_csv_btn->setFont(font1);
    export_csv_btn->setCursor(QCursor(Qt::PointingHandCursor));

    gridLayout->addWidget(export_csv_btn, 3, 1, 1, 1);

    MainWindow->setCentralWidget(centralWidget);
    menuBar = new QMenuBar(MainWindow);
    menuBar->setObjectName(QString::fromUtf8("menuBar"));
    menuBar->setGeometry(QRect(0, 0, 762, 25));
    menuTepTin = new QMenu(menuBar);
    menuTepTin->setObjectName(QString::fromUtf8("menuTepTin"));
    MainWindow->setMenuBar(menuBar);
    mainToolBar = new QToolBar(MainWindow);
    mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
    MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
    statusBar = new QStatusBar(MainWindow);
    statusBar->setObjectName(QString::fromUtf8("statusBar"));
    MainWindow->setStatusBar(statusBar);

    menuBar->addAction(menuTepTin->menuAction());
    menuTepTin->addAction(actionChonTepTin);
    menuTepTin->addAction(actionChonThuMuc);

    retranslateUi(MainWindow);

    stackedWidget->setCurrentIndex(1);


    QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
    actionChonTepTin->setText(QApplication::translate("MainWindow", "Ch\341\273\215n t\341\273\207p tin ph\303\242n t\303\255ch", 0, QApplication::UnicodeUTF8));
    actionChonThuMuc->setText(QApplication::translate("MainWindow", "Ch\341\273\215n th\306\260 m\341\273\245c ph\303\242n t\303\255ch", 0, QApplication::UnicodeUTF8));
    label->setText(QString());
    chose_folder_btn->setText(QApplication::translate("MainWindow", "Ch\341\273\215n th\306\260 m\341\273\245c", 0, QApplication::UnicodeUTF8));
    stop_btn->setText(QApplication::translate("MainWindow", "D\341\273\253ng", 0, QApplication::UnicodeUTF8));
    change_tab_btn->setText(QApplication::translate("MainWindow", "Hi\341\273\207n th\341\273\213 c\303\241c t\341\273\207p tin \304\221\303\243 b\341\273\213 \304\221\341\273\225i \304\221u\303\264i m\341\273\237 r\341\273\231ng", 0, QApplication::UnicodeUTF8));
    export_csv_btn->setText(QApplication::translate("MainWindow", "Xu\341\272\245t ra t\341\273\207p tin csv", 0, QApplication::UnicodeUTF8));
    menuTepTin->setTitle(QApplication::translate("MainWindow", "T\341\273\207p tin", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
