/****************************************************************************
** Meta object code from reading C++ file 'backend.h'
**
** Created: Mon Aug 13 12:16:42 2018
**      by: The Qt Meta Object Compiler version 59 (Qt 4.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../backend.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'backend.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 59
#error "This file was generated using the moc from 4.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Backend[] = {

 // content:
       1,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   10, // methods
       0,    0, // properties
       0,    0, // enums/sets

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,
      34,    8,    8,    8, 0x05,
      61,    8,    8,    8, 0x05,
      90,    8,    8,    8, 0x05,
     112,    8,    8,    8, 0x05,
     134,    8,    8,    8, 0x05,
     153,    8,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
     172,    8,    8,    8, 0x0a,
     185,    8,    8,    8, 0x0a,
     205,    8,    8,    8, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Backend[] = {
    "Backend\0\0sendStringToGui(QString)\0"
    "sendResultToTable(QString)\0"
    "sendResultToTable_2(QString)\0"
    "changeProcessBar(int)\0setProgressRange(int)\0"
    "showFinishDialog()\0setStatus(QString)\0"
    "run(QString)\0getAllFile(QString)\0"
    "resetAll()\0"
};

const QMetaObject Backend::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Backend,
      qt_meta_data_Backend, 0 }
};

const QMetaObject *Backend::metaObject() const
{
    return &staticMetaObject;
}

void *Backend::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Backend))
	return static_cast<void*>(const_cast< Backend*>(this));
    return QObject::qt_metacast(_clname);
}

int Backend::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: sendStringToGui((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: sendResultToTable((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: sendResultToTable_2((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: changeProcessBar((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: setProgressRange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: showFinishDialog(); break;
        case 6: setStatus((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: run((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: getAllFile((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: resetAll(); break;
        }
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Backend::sendStringToGui(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Backend::sendResultToTable(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Backend::sendResultToTable_2(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Backend::changeProcessBar(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Backend::setProgressRange(int _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Backend::showFinishDialog()
{
    QMetaObject::activate(this, &staticMetaObject, 5, 0);
}

// SIGNAL 6
void Backend::setStatus(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
