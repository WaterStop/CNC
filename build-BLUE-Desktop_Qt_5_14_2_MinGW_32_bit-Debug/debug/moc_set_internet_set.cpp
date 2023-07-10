/****************************************************************************
** Meta object code from reading C++ file 'set_internet_set.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../project/set_internet_set.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'set_internet_set.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_set_internet_set_t {
    QByteArrayData data[6];
    char stringdata0[76];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_set_internet_set_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_set_internet_set_t qt_meta_stringdata_set_internet_set = {
    {
QT_MOC_LITERAL(0, 0, 16), // "set_internet_set"
QT_MOC_LITERAL(1, 17, 13), // "Timer_on_slot"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 18), // "keyboard_show_slot"
QT_MOC_LITERAL(4, 51, 14), // "val_input_slot"
QT_MOC_LITERAL(5, 66, 9) // "save_slot"

    },
    "set_internet_set\0Timer_on_slot\0\0"
    "keyboard_show_slot\0val_input_slot\0"
    "save_slot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_set_internet_set[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x0a /* Public */,
       3,    0,   35,    2, 0x08 /* Private */,
       4,    1,   36,    2, 0x08 /* Private */,
       5,    0,   39,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

       0        // eod
};

void set_internet_set::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<set_internet_set *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Timer_on_slot(); break;
        case 1: _t->keyboard_show_slot(); break;
        case 2: _t->val_input_slot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->save_slot(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject set_internet_set::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_set_internet_set.data,
    qt_meta_data_set_internet_set,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *set_internet_set::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *set_internet_set::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_set_internet_set.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int set_internet_set::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
