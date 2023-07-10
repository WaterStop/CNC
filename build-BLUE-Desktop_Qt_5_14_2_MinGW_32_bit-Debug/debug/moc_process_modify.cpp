/****************************************************************************
** Meta object code from reading C++ file 'process_modify.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../project/process_modify.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'process_modify.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Process_modify_t {
    QByteArrayData data[11];
    char stringdata0[151];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Process_modify_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Process_modify_t qt_meta_stringdata_Process_modify = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Process_modify"
QT_MOC_LITERAL(1, 15, 10), // "bt_pressed"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 5), // "index"
QT_MOC_LITERAL(4, 33, 15), // "bt_pressed_slot"
QT_MOC_LITERAL(5, 49, 16), // "bt_pressed_slot1"
QT_MOC_LITERAL(6, 66, 16), // "bt_pressed_slot2"
QT_MOC_LITERAL(7, 83, 16), // "bt_pressed_slot3"
QT_MOC_LITERAL(8, 100, 16), // "bt_pressed_slot4"
QT_MOC_LITERAL(9, 117, 16), // "bt_pressed_slot5"
QT_MOC_LITERAL(10, 134, 16) // "bt_pressed_slot6"

    },
    "Process_modify\0bt_pressed\0\0index\0"
    "bt_pressed_slot\0bt_pressed_slot1\0"
    "bt_pressed_slot2\0bt_pressed_slot3\0"
    "bt_pressed_slot4\0bt_pressed_slot5\0"
    "bt_pressed_slot6"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Process_modify[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   57,    2, 0x08 /* Private */,
       5,    0,   58,    2, 0x08 /* Private */,
       6,    0,   59,    2, 0x08 /* Private */,
       7,    0,   60,    2, 0x08 /* Private */,
       8,    0,   61,    2, 0x08 /* Private */,
       9,    0,   62,    2, 0x08 /* Private */,
      10,    0,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Process_modify::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Process_modify *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->bt_pressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->bt_pressed_slot(); break;
        case 2: _t->bt_pressed_slot1(); break;
        case 3: _t->bt_pressed_slot2(); break;
        case 4: _t->bt_pressed_slot3(); break;
        case 5: _t->bt_pressed_slot4(); break;
        case 6: _t->bt_pressed_slot5(); break;
        case 7: _t->bt_pressed_slot6(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Process_modify::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Process_modify::bt_pressed)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Process_modify::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Process_modify.data,
    qt_meta_data_Process_modify,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Process_modify::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Process_modify::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Process_modify.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Process_modify::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Process_modify::bt_pressed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
