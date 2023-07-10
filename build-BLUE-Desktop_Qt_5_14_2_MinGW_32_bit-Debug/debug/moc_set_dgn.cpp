/****************************************************************************
** Meta object code from reading C++ file 'set_dgn.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../project/set_dgn.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'set_dgn.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_set_dgn_t {
    QByteArrayData data[12];
    char stringdata0[142];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_set_dgn_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_set_dgn_t qt_meta_stringdata_set_dgn = {
    {
QT_MOC_LITERAL(0, 0, 7), // "set_dgn"
QT_MOC_LITERAL(1, 8, 11), // "back_signal"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 13), // "Timer_on_slot"
QT_MOC_LITERAL(4, 35, 9), // "back_slot"
QT_MOC_LITERAL(5, 45, 11), // "uppage_slot"
QT_MOC_LITERAL(6, 57, 13), // "downpage_slot"
QT_MOC_LITERAL(7, 71, 12), // "uppage_slot1"
QT_MOC_LITERAL(8, 84, 14), // "downpage_slot1"
QT_MOC_LITERAL(9, 99, 13), // "keyboard_show"
QT_MOC_LITERAL(10, 113, 14), // "val_input_slot"
QT_MOC_LITERAL(11, 128, 13) // "change_g98g99"

    },
    "set_dgn\0back_signal\0\0Timer_on_slot\0"
    "back_slot\0uppage_slot\0downpage_slot\0"
    "uppage_slot1\0downpage_slot1\0keyboard_show\0"
    "val_input_slot\0change_g98g99"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_set_dgn[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   65,    2, 0x0a /* Public */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    1,   72,    2, 0x08 /* Private */,
      11,    0,   75,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,

       0        // eod
};

void set_dgn::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<set_dgn *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->back_signal(); break;
        case 1: _t->Timer_on_slot(); break;
        case 2: _t->back_slot(); break;
        case 3: _t->uppage_slot(); break;
        case 4: _t->downpage_slot(); break;
        case 5: _t->uppage_slot1(); break;
        case 6: _t->downpage_slot1(); break;
        case 7: _t->keyboard_show(); break;
        case 8: _t->val_input_slot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->change_g98g99(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (set_dgn::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&set_dgn::back_signal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject set_dgn::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_set_dgn.data,
    qt_meta_data_set_dgn,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *set_dgn::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *set_dgn::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_set_dgn.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int set_dgn::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void set_dgn::back_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
