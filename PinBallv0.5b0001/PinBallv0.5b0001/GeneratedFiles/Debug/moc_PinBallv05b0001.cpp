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
    QByteArrayData data[16];
    char stringdata0[203];
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
QT_MOC_LITERAL(10, 114, 22), // "destroyMenuChildLabels"
QT_MOC_LITERAL(11, 137, 12), // "setBGMVolume"
QT_MOC_LITERAL(12, 150, 6), // "volume"
QT_MOC_LITERAL(13, 157, 9), // "toggleBGM"
QT_MOC_LITERAL(14, 167, 18), // "playReturnButtonSE"
QT_MOC_LITERAL(15, 186, 16) // "playStepButtonSE"

    },
    "PinBallv05b0001\0returnMenu\0\0about\0"
    "gallery\0setting\0toggleDebugMode\0"
    "initGameMenu\0createMenu\0destroyMenuChildButtons\0"
    "destroyMenuChildLabels\0setBGMVolume\0"
    "volume\0toggleBGM\0playReturnButtonSE\0"
    "playStepButtonSE"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PinBallv05b0001[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       9,    0,   91,    2, 0x08 /* Private */,
      10,    0,   92,    2, 0x08 /* Private */,
      11,    1,   93,    2, 0x08 /* Private */,
      11,    0,   96,    2, 0x28 /* Private | MethodCloned */,
      13,    0,   97,    2, 0x08 /* Private */,
      14,    0,   98,    2, 0x08 /* Private */,
      15,    0,   99,    2, 0x08 /* Private */,

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
    QMetaType::Void, QMetaType::Int,   12,
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
        case 9: _t->setBGMVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->setBGMVolume(); break;
        case 11: _t->toggleBGM(); break;
        case 12: _t->playReturnButtonSE(); break;
        case 13: _t->playStepButtonSE(); break;
        default: ;
        }
    }
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
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
