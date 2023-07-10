/****************************************************************************
** Meta object code from reading C++ file 'widget3.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../project/widget3.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget3.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_widget3_t {
    QByteArrayData data[22];
    char stringdata0[335];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_widget3_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_widget3_t qt_meta_stringdata_widget3 = {
    {
QT_MOC_LITERAL(0, 0, 7), // "widget3"
QT_MOC_LITERAL(1, 8, 17), // "edit_press_signal"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 5), // "index"
QT_MOC_LITERAL(4, 33, 21), // "close_keyboard_signal"
QT_MOC_LITERAL(5, 55, 19), // "barstock_set_signal"
QT_MOC_LITERAL(6, 75, 17), // "edit_input_signal"
QT_MOC_LITERAL(7, 93, 3), // "str"
QT_MOC_LITERAL(8, 97, 13), // "Timer_on_slot"
QT_MOC_LITERAL(9, 111, 8), // "setpoint"
QT_MOC_LITERAL(10, 120, 5), // "value"
QT_MOC_LITERAL(11, 126, 18), // "show_keyboard_slot"
QT_MOC_LITERAL(12, 145, 19), // "show_keyboard_slot1"
QT_MOC_LITERAL(13, 165, 19), // "show_keyboard_slot2"
QT_MOC_LITERAL(14, 185, 19), // "show_keyboard_slot3"
QT_MOC_LITERAL(15, 205, 19), // "show_keyboard_slot4"
QT_MOC_LITERAL(16, 225, 19), // "show_keyboard_slot5"
QT_MOC_LITERAL(17, 245, 15), // "deal_enter_slot"
QT_MOC_LITERAL(18, 261, 15), // "edit_input_slot"
QT_MOC_LITERAL(19, 277, 19), // "set_edit_style_slot"
QT_MOC_LITERAL(20, 297, 18), // "return_zero_slot_X"
QT_MOC_LITERAL(21, 316, 18) // "return_zero_slot_Z"

    },
    "widget3\0edit_press_signal\0\0index\0"
    "close_keyboard_signal\0barstock_set_signal\0"
    "edit_input_signal\0str\0Timer_on_slot\0"
    "setpoint\0value\0show_keyboard_slot\0"
    "show_keyboard_slot1\0show_keyboard_slot2\0"
    "show_keyboard_slot3\0show_keyboard_slot4\0"
    "show_keyboard_slot5\0deal_enter_slot\0"
    "edit_input_slot\0set_edit_style_slot\0"
    "return_zero_slot_X\0return_zero_slot_Z"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_widget3[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06 /* Public */,
       4,    0,  102,    2, 0x06 /* Public */,
       5,    0,  103,    2, 0x06 /* Public */,
       6,    2,  104,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,  109,    2, 0x0a /* Public */,
       9,    1,  110,    2, 0x08 /* Private */,
      11,    0,  113,    2, 0x08 /* Private */,
      12,    0,  114,    2, 0x08 /* Private */,
      13,    0,  115,    2, 0x08 /* Private */,
      14,    0,  116,    2, 0x08 /* Private */,
      15,    0,  117,    2, 0x08 /* Private */,
      16,    0,  118,    2, 0x08 /* Private */,
      17,    0,  119,    2, 0x08 /* Private */,
      18,    1,  120,    2, 0x08 /* Private */,
      19,    0,  123,    2, 0x08 /* Private */,
      20,    0,  124,    2, 0x08 /* Private */,
      21,    0,  125,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void widget3::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<widget3 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->edit_press_signal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->close_keyboard_signal(); break;
        case 2: _t->barstock_set_signal(); break;
        case 3: _t->edit_input_signal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->Timer_on_slot(); break;
        case 5: _t->setpoint((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->show_keyboard_slot(); break;
        case 7: _t->show_keyboard_slot1(); break;
        case 8: _t->show_keyboard_slot2(); break;
        case 9: _t->show_keyboard_slot3(); break;
        case 10: _t->show_keyboard_slot4(); break;
        case 11: _t->show_keyboard_slot5(); break;
        case 12: _t->deal_enter_slot(); break;
        case 13: _t->edit_input_slot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->set_edit_style_slot(); break;
        case 15: _t->return_zero_slot_X(); break;
        case 16: _t->return_zero_slot_Z(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (widget3::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&widget3::edit_press_signal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (widget3::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&widget3::close_keyboard_signal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (widget3::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&widget3::barstock_set_signal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (widget3::*)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&widget3::edit_input_signal)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject widget3::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_widget3.data,
    qt_meta_data_widget3,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *widget3::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *widget3::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_widget3.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int widget3::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void widget3::edit_press_signal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void widget3::close_keyboard_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void widget3::barstock_set_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void widget3::edit_input_signal(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
