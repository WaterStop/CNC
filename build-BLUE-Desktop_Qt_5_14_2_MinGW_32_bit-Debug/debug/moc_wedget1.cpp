/****************************************************************************
** Meta object code from reading C++ file 'wedget1.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../project/wedget1.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wedget1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_wedget1_t {
    QByteArrayData data[18];
    char stringdata0[197];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_wedget1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_wedget1_t qt_meta_stringdata_wedget1 = {
    {
QT_MOC_LITERAL(0, 0, 7), // "wedget1"
QT_MOC_LITERAL(1, 8, 9), // "bt_signal"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 5), // "index"
QT_MOC_LITERAL(4, 25, 17), // "long_press_signal"
QT_MOC_LITERAL(5, 43, 21), // "set_proBar_value_solt"
QT_MOC_LITERAL(6, 65, 5), // "value"
QT_MOC_LITERAL(7, 71, 9), // "bt_0_slot"
QT_MOC_LITERAL(8, 81, 9), // "bt_1_slot"
QT_MOC_LITERAL(9, 91, 9), // "bt_2_slot"
QT_MOC_LITERAL(10, 101, 9), // "bt_3_slot"
QT_MOC_LITERAL(11, 111, 9), // "bt_4_slot"
QT_MOC_LITERAL(12, 121, 11), // "bt_0_slot_l"
QT_MOC_LITERAL(13, 133, 11), // "bt_1_slot_l"
QT_MOC_LITERAL(14, 145, 11), // "bt_2_slot_l"
QT_MOC_LITERAL(15, 157, 11), // "bt_3_slot_l"
QT_MOC_LITERAL(16, 169, 11), // "bt_4_slot_l"
QT_MOC_LITERAL(17, 181, 15) // "long_press_slot"

    },
    "wedget1\0bt_signal\0\0index\0long_press_signal\0"
    "set_proBar_value_solt\0value\0bt_0_slot\0"
    "bt_1_slot\0bt_2_slot\0bt_3_slot\0bt_4_slot\0"
    "bt_0_slot_l\0bt_1_slot_l\0bt_2_slot_l\0"
    "bt_3_slot_l\0bt_4_slot_l\0long_press_slot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_wedget1[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       4,    1,   87,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   90,    2, 0x0a /* Public */,
       7,    0,   93,    2, 0x08 /* Private */,
       8,    0,   94,    2, 0x08 /* Private */,
       9,    0,   95,    2, 0x08 /* Private */,
      10,    0,   96,    2, 0x08 /* Private */,
      11,    0,   97,    2, 0x08 /* Private */,
      12,    0,   98,    2, 0x08 /* Private */,
      13,    0,   99,    2, 0x08 /* Private */,
      14,    0,  100,    2, 0x08 /* Private */,
      15,    0,  101,    2, 0x08 /* Private */,
      16,    0,  102,    2, 0x08 /* Private */,
      17,    0,  103,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
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

void wedget1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<wedget1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->bt_signal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->long_press_signal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->set_proBar_value_solt((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->bt_0_slot(); break;
        case 4: _t->bt_1_slot(); break;
        case 5: _t->bt_2_slot(); break;
        case 6: _t->bt_3_slot(); break;
        case 7: _t->bt_4_slot(); break;
        case 8: _t->bt_0_slot_l(); break;
        case 9: _t->bt_1_slot_l(); break;
        case 10: _t->bt_2_slot_l(); break;
        case 11: _t->bt_3_slot_l(); break;
        case 12: _t->bt_4_slot_l(); break;
        case 13: _t->long_press_slot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (wedget1::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&wedget1::bt_signal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (wedget1::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&wedget1::long_press_signal)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject wedget1::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_wedget1.data,
    qt_meta_data_wedget1,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *wedget1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *wedget1::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_wedget1.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int wedget1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void wedget1::bt_signal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void wedget1::long_press_signal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
