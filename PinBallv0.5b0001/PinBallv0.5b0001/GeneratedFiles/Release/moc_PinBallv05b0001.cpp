/****************************************************************************
** Meta object code from reading C++ file 'PinBallv05b0001.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PinBallv05b0001.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'PinBallv05b0001.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PinBallv05b0001_t {
    QByteArrayData data[11];
    char stringdata0[137];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PinBallv05b0001_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PinBallv05b0001_t qt_meta_stringdata_PinBallv05b0001 = {
    {
QT_MOC_LITERAL(0, 0, 15), // "PinBallv05b0001"
QT_MOC_LITERAL(1, 16, 10), // "returnMenu"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 5), // "about"
QT_MOC_LITERAL(4, 34, 7), // "gallery"
QT_MOC_LITERAL(5, 42, 7), // "setting"
QT_MOC_LITERAL(6, 50, 15), // "toggleDebugMode"
QT_MOC_LITERAL(7, 66, 12), // "initGameMenu"
QT_MOC_LITERAL(8, 79, 10), // "createMenu"
QT_MOC_LITERAL(9, 90, 23), // "destroyMenuChildButtons"
QT_MOC_LITERAL(10, 114, 22) // "destroyMenuChildLabels"

    },
    "PinBallv05b0001\0returnMenu\0\0about\0"
    "gallery\0setting\0toggleDebugMode\0"
    "initGameMenu\0createMenu\0destroyMenuChildButtons\0"
    "destroyMenuChildLabels"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PinBallv05b0001[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    0,   60,    2, 0x08 /* Private */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void PinBallv05b0001::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PinBallv05b0001 *_t = static_cast<PinBallv05b0001 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->returnMenu(); break;
        case 1: _t->about(); break;
        case 2: _t->gallery(); break;
        case 3: _t->setting(); break;
        case 4: _t->toggleDebugMode(); break;
        case 5: _t->initGameMenu(); break;
        case 6: _t->createMenu(); break;
        case 7: _t->destroyMenuChildButtons(); break;
        case 8: _t->destroyMenuChildLabels(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject PinBallv05b0001::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_PinBallv05b0001.data,
      qt_meta_data_PinBallv05b0001,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PinBallv05b0001::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PinBallv05b0001::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PinBallv05b0001.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int PinBallv05b0001::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
