/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sat Aug 25 16:59:53 2018
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      33,   11,   11,   11, 0x05,
      48,   11,   11,   11, 0x05,
      62,   11,   11,   11, 0x05,
      77,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      89,   11,   11,   11, 0x08,
     119,   11,   11,   11, 0x08,
     147,   11,   11,   11, 0x08,
     169,   11,   11,   11, 0x08,
     203,  197,   11,   11, 0x08,
     243,   11,   11,   11, 0x08,
     275,   11,   11,   11, 0x08,
     307,   11,   11,   11, 0x08,
     320,   11,   11,   11, 0x08,
     347,  343,   11,   11, 0x08,
     395,  343,   11,   11, 0x08,
     445,   11,   11,   11, 0x0a,
     471,   11,   11,   11, 0x0a,
     498,   11,   11,   11, 0x0a,
     527,   11,   11,   11, 0x0a,
     549,   11,   11,   11, 0x0a,
     571,   11,   11,   11, 0x0a,
     590,   11,   11,   11, 0x0a,
     603,   11,   11,   11, 0x0a,
     618,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0callBackend(QString)\0"
    "resetBackend()\0stopProcess()\0"
    "renewBackend()\0itemClick()\0"
    "on_chose_folder_btn_clicked()\0"
    "on_change_tab_btn_clicked()\0"
    "on_stop_btn_clicked()\0on_export_csv_btn_clicked()\0"
    "index\0on_tableView_doubleClicked(QModelIndex)\0"
    "on_actionChonTepTin_triggered()\0"
    "on_actionChonThuMuc_triggered()\0"
    "viewDetail()\0create_submenu(QPoint)\0"
    "pos\0on_tableView_customContextMenuRequested(QPoint)\0"
    "on_tableView_2_customContextMenuRequested(QPoint)\0"
    "showInfoToScreen(QString)\0"
    "showResultToTable(QString)\0"
    "showResultToTable_2(QString)\0"
    "changeProcessBar(int)\0setProgressRange(int)\0"
    "showFinishDialog()\0reviewFile()\0"
    "qickOpenFile()\0setStatus(QString)\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

const QMetaObject *MainWindow::metaObject() const
{
    return &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
	return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: callBackend((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: resetBackend(); break;
        case 2: stopProcess(); break;
        case 3: renewBackend(); break;
        case 4: itemClick(); break;
        case 5: on_chose_folder_btn_clicked(); break;
        case 6: on_change_tab_btn_clicked(); break;
        case 7: on_stop_btn_clicked(); break;
        case 8: on_export_csv_btn_clicked(); break;
        case 9: on_tableView_doubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 10: on_actionChonTepTin_triggered(); break;
        case 11: on_actionChonThuMuc_triggered(); break;
        case 12: viewDetail(); break;
        case 13: create_submenu((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 14: on_tableView_customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 15: on_tableView_2_customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 16: showInfoToScreen((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 17: showResultToTable((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 18: showResultToTable_2((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 19: changeProcessBar((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: setProgressRange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: showFinishDialog(); break;
        case 22: reviewFile(); break;
        case 23: qickOpenFile(); break;
        case 24: setStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        }
        _id -= 25;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::callBackend(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::resetBackend()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void MainWindow::stopProcess()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}

// SIGNAL 3
void MainWindow::renewBackend()
{
    QMetaObject::activate(this, &staticMetaObject, 3, 0);
}

// SIGNAL 4
void MainWindow::itemClick()
{
    QMetaObject::activate(this, &staticMetaObject, 4, 0);
}
QT_END_MOC_NAMESPACE
