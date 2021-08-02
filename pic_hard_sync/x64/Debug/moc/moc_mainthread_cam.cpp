/****************************************************************************
** Meta object code from reading C++ file 'mainthread_cam.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../mainthread_cam.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainthread_cam.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_mainthread_cam_t {
    QByteArrayData data[5];
    char stringdata0[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mainthread_cam_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mainthread_cam_t qt_meta_stringdata_mainthread_cam = {
    {
QT_MOC_LITERAL(0, 0, 14), // "mainthread_cam"
QT_MOC_LITERAL(1, 15, 16), // "processed_QImage"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 14), // "recordProgress"
QT_MOC_LITERAL(4, 48, 21) // "signal_check_compelet"

    },
    "mainthread_cam\0processed_QImage\0\0"
    "recordProgress\0signal_check_compelet"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mainthread_cam[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,
       3,    1,   34,    2, 0x06 /* Public */,
       4,    1,   37,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage, QMetaType::QImage,    2,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void mainthread_cam::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<mainthread_cam *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->processed_QImage((*reinterpret_cast< QImage(*)>(_a[1])),(*reinterpret_cast< QImage(*)>(_a[2]))); break;
        case 1: _t->recordProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->signal_check_compelet((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (mainthread_cam::*)(QImage , QImage );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mainthread_cam::processed_QImage)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (mainthread_cam::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mainthread_cam::recordProgress)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (mainthread_cam::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mainthread_cam::signal_check_compelet)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject mainthread_cam::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_mainthread_cam.data,
    qt_meta_data_mainthread_cam,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *mainthread_cam::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mainthread_cam::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_mainthread_cam.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int mainthread_cam::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void mainthread_cam::processed_QImage(QImage _t1, QImage _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void mainthread_cam::recordProgress(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void mainthread_cam::signal_check_compelet(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
