/****************************************************************************
** Meta object code from reading C++ file 'pic_hard_sync.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../pic_hard_sync.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'pic_hard_sync.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_pic_hard_sync_t {
    QByteArrayData data[7];
    char stringdata0[85];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_pic_hard_sync_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_pic_hard_sync_t qt_meta_stringdata_pic_hard_sync = {
    {
QT_MOC_LITERAL(0, 0, 13), // "pic_hard_sync"
QT_MOC_LITERAL(1, 14, 16), // "show_realsense_1"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 21), // "update_recordProgress"
QT_MOC_LITERAL(4, 54, 14), // "check_compelet"
QT_MOC_LITERAL(5, 69, 6), // "regist"
QT_MOC_LITERAL(6, 76, 8) // "del_user"

    },
    "pic_hard_sync\0show_realsense_1\0\0"
    "update_recordProgress\0check_compelet\0"
    "regist\0del_user"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_pic_hard_sync[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x08 /* Private */,
       3,    1,   44,    2, 0x08 /* Private */,
       4,    0,   47,    2, 0x08 /* Private */,
       5,    0,   48,    2, 0x08 /* Private */,
       6,    0,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QImage, QMetaType::QImage,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void pic_hard_sync::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<pic_hard_sync *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->show_realsense_1((*reinterpret_cast< QImage(*)>(_a[1])),(*reinterpret_cast< QImage(*)>(_a[2]))); break;
        case 1: _t->update_recordProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->check_compelet(); break;
        case 3: _t->regist(); break;
        case 4: _t->del_user(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject pic_hard_sync::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_pic_hard_sync.data,
    qt_meta_data_pic_hard_sync,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *pic_hard_sync::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *pic_hard_sync::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_pic_hard_sync.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int pic_hard_sync::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
