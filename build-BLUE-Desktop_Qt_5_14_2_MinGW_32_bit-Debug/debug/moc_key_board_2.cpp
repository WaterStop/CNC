/****************************************************************************
** Meta object code from reading C++ file 'key_board_2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../project/key_board_2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'key_board_2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_key_board_2_t {
    QByteArrayData data[9];
    char stringdata0[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_key_board_2_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_key_board_2_t qt_meta_stringdata_key_board_2 = {
    {
QT_MOC_LITERAL(0, 0, 11), // "key_board_2"
QT_MOC_LITERAL(1, 12, 12), // "enter_signal"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 3), // "str"
QT_MOC_LITERAL(4, 30, 15), // "press_deal_slot"
QT_MOC_LITERAL(5, 46, 5), // "index"
QT_MOC_LITERAL(6, 52, 16), // "press_deal_slot1"
QT_MOC_LITERAL(7, 69, 16), // "KeyOneClick_slot"
QT_MOC_LITERAL(8, 86, 14) // "timer_out_slot"

    },
    "key_board_2\0enter_signal\0\0str\0"
    "press_deal_slot\0index\0press_deal_slot1\0"
    "KeyOneClick_slot\0timer_out_slot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_key_board_2[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       1,    0,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   48,    2, 0x08 /* Private */,
       6,    1,   51,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void key_board_2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<key_board_2 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->enter_signal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->enter_signal(); break;
        case 2: _t->press_deal_slot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->press_deal_slot1((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->KeyOneClick_slot(); break;
        case 5: _t->timer_out_slot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (key_board_2::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&key_board_2::enter_signal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (key_board_2::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&key_board_2::enter_signal)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject key_board_2::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_key_board_2.data,
    qt_meta_data_key_board_2,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *key_board_2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *key_board_2::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_key_board_2.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int key_board_2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void key_board_2::enter_signal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void key_board_2::enter_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
