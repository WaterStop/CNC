/****************************************************************************
** Meta object code from reading C++ file 'fixedval_widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../project/fixedval_widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'fixedval_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FixedVal_widget_t {
    QByteArrayData data[11];
    char stringdata0[136];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FixedVal_widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FixedVal_widget_t qt_meta_stringdata_FixedVal_widget = {
    {
QT_MOC_LITERAL(0, 0, 15), // "FixedVal_widget"
QT_MOC_LITERAL(1, 16, 10), // "bt0_signal"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 10), // "bt1_signal"
QT_MOC_LITERAL(4, 39, 10), // "bt2_signal"
QT_MOC_LITERAL(5, 50, 12), // "bt0_val_slot"
QT_MOC_LITERAL(6, 63, 12), // "bt1_val_slot"
QT_MOC_LITERAL(7, 76, 12), // "bt2_val_slot"
QT_MOC_LITERAL(8, 89, 14), // "bt_lastpg_slot"
QT_MOC_LITERAL(9, 104, 14), // "bt_nextpg_slot"
QT_MOC_LITERAL(10, 119, 16) // "Deal_bt_val_slot"

    },
    "FixedVal_widget\0bt0_signal\0\0bt1_signal\0"
    "bt2_signal\0bt0_val_slot\0bt1_val_slot\0"
    "bt2_val_slot\0bt_lastpg_slot\0bt_nextpg_slot\0"
    "Deal_bt_val_slot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FixedVal_widget[] = {

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

void FixedVal_widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FixedVal_widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->bt0_signal(); break;
        case 1: _t->bt1_signal(); break;
        case 2: _t->bt2_signal(); break;
        case 3: _t->bt0_val_slot(); break;
        case 4: _t->bt1_val_slot(); break;
        case 5: _t->bt2_val_slot(); break;
        case 6: _t->bt_lastpg_slot(); break;
        case 7: _t->bt_nextpg_slot(); break;
        case 8: _t->Deal_bt_val_slot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FixedVal_widget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FixedVal_widget::bt0_signal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FixedVal_widget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FixedVal_widget::bt1_signal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FixedVal_widget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FixedVal_widget::bt2_signal)) {
                *result = 2;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject FixedVal_widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_FixedVal_widget.data,
    qt_meta_data_FixedVal_widget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FixedVal_widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FixedVal_widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FixedVal_widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FixedVal_widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void FixedVal_widget::bt0_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void FixedVal_widget::bt1_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void FixedVal_widget::bt2_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
