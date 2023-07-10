/****************************************************************************
** Meta object code from reading C++ file 'widget3_10.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../project/widget3_10.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget3_10.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_widget3_10_t {
    QByteArrayData data[19];
    char stringdata0[307];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_widget3_10_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_widget3_10_t qt_meta_stringdata_widget3_10 = {
    {
QT_MOC_LITERAL(0, 0, 10), // "widget3_10"
QT_MOC_LITERAL(1, 11, 17), // "edit_press_signal"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 15), // "input_ok_signal"
QT_MOC_LITERAL(4, 46, 18), // "feed_fixval_signal"
QT_MOC_LITERAL(5, 65, 17), // "edit_input_signal"
QT_MOC_LITERAL(6, 83, 5), // "index"
QT_MOC_LITERAL(7, 89, 3), // "str"
QT_MOC_LITERAL(8, 93, 26), // "widget3_10_editDataToGCode"
QT_MOC_LITERAL(9, 120, 18), // "show_keyboard_slot"
QT_MOC_LITERAL(10, 139, 13), // "input_ok_slot"
QT_MOC_LITERAL(11, 153, 17), // "Focus_switch_slot"
QT_MOC_LITERAL(12, 171, 20), // "change_axisdir1_slot"
QT_MOC_LITERAL(13, 192, 20), // "change_axisdir2_slot"
QT_MOC_LITERAL(14, 213, 25), // "change_anticlockwise_slot"
QT_MOC_LITERAL(15, 239, 21), // "change_clockwise_slot"
QT_MOC_LITERAL(16, 261, 16), // "feed_fixval_slot"
QT_MOC_LITERAL(17, 278, 15), // "edit_input_slot"
QT_MOC_LITERAL(18, 294, 12) // "updateTrCnCr"

    },
    "widget3_10\0edit_press_signal\0\0"
    "input_ok_signal\0feed_fixval_signal\0"
    "edit_input_signal\0index\0str\0"
    "widget3_10_editDataToGCode\0"
    "show_keyboard_slot\0input_ok_slot\0"
    "Focus_switch_slot\0change_axisdir1_slot\0"
    "change_axisdir2_slot\0change_anticlockwise_slot\0"
    "change_clockwise_slot\0feed_fixval_slot\0"
    "edit_input_slot\0updateTrCnCr"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_widget3_10[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    0,   90,    2, 0x06 /* Public */,
       4,    0,   91,    2, 0x06 /* Public */,
       5,    2,   92,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   97,    2, 0x0a /* Public */,
       9,    0,   98,    2, 0x08 /* Private */,
      10,    0,   99,    2, 0x08 /* Private */,
      11,    0,  100,    2, 0x08 /* Private */,
      12,    0,  101,    2, 0x08 /* Private */,
      13,    0,  102,    2, 0x08 /* Private */,
      14,    0,  103,    2, 0x08 /* Private */,
      15,    0,  104,    2, 0x08 /* Private */,
      16,    0,  105,    2, 0x08 /* Private */,
      17,    1,  106,    2, 0x08 /* Private */,
      18,    0,  109,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    6,    7,

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
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,

       0        // eod
};

void widget3_10::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<widget3_10 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->edit_press_signal(); break;
        case 1: _t->input_ok_signal(); break;
        case 2: _t->feed_fixval_signal(); break;
        case 3: _t->edit_input_signal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->widget3_10_editDataToGCode(); break;
        case 5: _t->show_keyboard_slot(); break;
        case 6: _t->input_ok_slot(); break;
        case 7: _t->Focus_switch_slot(); break;
        case 8: _t->change_axisdir1_slot(); break;
        case 9: _t->change_axisdir2_slot(); break;
        case 10: _t->change_anticlockwise_slot(); break;
        case 11: _t->change_clockwise_slot(); break;
        case 12: _t->feed_fixval_slot(); break;
        case 13: _t->edit_input_slot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->updateTrCnCr(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (widget3_10::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&widget3_10::edit_press_signal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (widget3_10::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&widget3_10::input_ok_signal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (widget3_10::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&widget3_10::feed_fixval_signal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (widget3_10::*)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&widget3_10::edit_input_signal)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject widget3_10::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_widget3_10.data,
    qt_meta_data_widget3_10,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *widget3_10::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *widget3_10::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_widget3_10.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int widget3_10::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void widget3_10::edit_press_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void widget3_10::input_ok_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void widget3_10::feed_fixval_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void widget3_10::edit_input_signal(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
