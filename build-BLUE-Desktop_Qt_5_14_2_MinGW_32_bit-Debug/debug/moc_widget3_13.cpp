/****************************************************************************
** Meta object code from reading C++ file 'widget3_13.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../project/widget3_13.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget3_13.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_widget3_13_t {
    QByteArrayData data[11];
    char stringdata0[175];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_widget3_13_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_widget3_13_t qt_meta_stringdata_widget3_13 = {
    {
QT_MOC_LITERAL(0, 0, 10), // "widget3_13"
QT_MOC_LITERAL(1, 11, 17), // "edit_press_signal"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 15), // "input_ok_signal"
QT_MOC_LITERAL(4, 46, 18), // "feed_fixval_signal"
QT_MOC_LITERAL(5, 65, 18), // "show_keyboard_slot"
QT_MOC_LITERAL(6, 84, 13), // "input_ok_slot"
QT_MOC_LITERAL(7, 98, 17), // "Focus_switch_slot"
QT_MOC_LITERAL(8, 116, 20), // "change_axisdir1_slot"
QT_MOC_LITERAL(9, 137, 20), // "change_axisdir2_slot"
QT_MOC_LITERAL(10, 158, 16) // "feed_fixval_slot"

    },
    "widget3_13\0edit_press_signal\0\0"
    "input_ok_signal\0feed_fixval_signal\0"
    "show_keyboard_slot\0input_ok_slot\0"
    "Focus_switch_slot\0change_axisdir1_slot\0"
    "change_axisdir2_slot\0feed_fixval_slot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_widget3_13[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void widget3_13::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<widget3_13 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->edit_press_signal(); break;
        case 1: _t->input_ok_signal(); break;
        case 2: _t->feed_fixval_signal(); break;
        case 3: _t->show_keyboard_slot(); break;
        case 4: _t->input_ok_slot(); break;
        case 5: _t->Focus_switch_slot(); break;
        case 6: _t->change_axisdir1_slot(); break;
        case 7: _t->change_axisdir2_slot(); break;
        case 8: _t->feed_fixval_slot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (widget3_13::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&widget3_13::edit_press_signal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (widget3_13::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&widget3_13::input_ok_signal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (widget3_13::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&widget3_13::feed_fixval_signal)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject widget3_13::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_widget3_13.data,
    qt_meta_data_widget3_13,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *widget3_13::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *widget3_13::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_widget3_13.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int widget3_13::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void widget3_13::edit_press_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void widget3_13::input_ok_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void widget3_13::feed_fixval_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
