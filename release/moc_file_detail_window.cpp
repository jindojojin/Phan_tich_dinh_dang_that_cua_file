/****************************************************************************
** Meta object code from reading C++ file 'file_detail_window.h'
**
** Created: Mon Aug 13 11:12:59 2018
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../file_detail_window.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'file_detail_window.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_File_Detail_Window[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets

       0        // eod
};

static const char qt_meta_stringdata_File_Detail_Window[] = {
    "File_Detail_Window\0"
};

const QMetaObject File_Detail_Window::staticMetaObject = {
    { &QFrame::staticMetaObject, qt_meta_stringdata_File_Detail_Window,
      qt_meta_data_File_Detail_Window, 0 }
};

const QMetaObject *File_Detail_Window::metaObject() const
{
    return &staticMetaObject;
}

void *File_Detail_Window::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_File_Detail_Window))
	return static_cast<void*>(const_cast< File_Detail_Window*>(this));
    return QFrame::qt_metacast(_clname);
}

int File_Detail_Window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFrame::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
QT_END_MOC_NAMESPACE
