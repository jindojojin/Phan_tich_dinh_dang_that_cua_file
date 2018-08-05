/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Sun Aug 5 10:52:31 2018
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
      13,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,
      33,   11,   11,   11, 0x05,
      48,   11,   11,   11, 0x05,
      62,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      77,   11,   11,   11, 0x08,
     107,   11,   11,   11, 0x08,
     135,   11,   11,   11, 0x08,
     157,   11,   11,   11, 0x0a,
     183,   11,   11,   11, 0x0a,
     210,   11,   11,   11, 0x0a,
     232,   11,   11,   11, 0x0a,
     254,   11,   11,   11, 0x0a,
     273,   11,   11,   11, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0callBackend(QString)\0"
    "resetBackend()\0stopProcess()\0"
    "renewBackend()\0on_chose_folder_btn_clicked()\0"
    "on_change_tab_btn_clicked()\0"
    "on_stop_btn_clicked()\0showInfoToScreen(QString)\0"
    "showResultToTable(QString)\0"
    "changeProcessBar(int)\0setProgressRange(int)\0"
    "showFinishDialog()\0setStatus(QString)\0"
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
        case 4: on_chose_folder_btn_clicked(); break;
        case 5: on_change_tab_btn_clicked(); break;
        case 6: on_stop_btn_clicked(); break;
        case 7: showInfoToScreen((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: showResultToTable((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: changeProcessBar((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: setProgressRange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: showFinishDialog(); break;
        case 12: setStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        }
        _id -= 13;
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
QT_END_MOC_NAMESPACE
