/****************************************************************************
** Meta object code from reading C++ file 'set_data_para.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../project/set_data_para.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'set_data_para.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_set_data_para_t {
    QByteArrayData data[17];
    char stringdata0[194];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_set_data_para_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_set_data_para_t qt_meta_stringdata_set_data_para = {
    {
QT_MOC_LITERAL(0, 0, 13), // "set_data_para"
QT_MOC_LITERAL(1, 14, 13), // "Timer_on_slot"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 18), // "get_item_info_slot"
QT_MOC_LITERAL(4, 48, 3), // "row"
QT_MOC_LITERAL(5, 52, 3), // "col"
QT_MOC_LITERAL(6, 56, 14), // "val_input_slot"
QT_MOC_LITERAL(7, 71, 3), // "str"
QT_MOC_LITERAL(8, 75, 12), // "seacher_slot"
QT_MOC_LITERAL(9, 88, 11), // "uppage_slot"
QT_MOC_LITERAL(10, 100, 13), // "downpage_slot"
QT_MOC_LITERAL(11, 114, 14), // "clear_tip_slot"
QT_MOC_LITERAL(12, 129, 12), // "bt_fun_slot1"
QT_MOC_LITERAL(13, 142, 12), // "bt_fun_slot2"
QT_MOC_LITERAL(14, 155, 12), // "bt_fun_slot3"
QT_MOC_LITERAL(15, 168, 12), // "bt_fun_slot4"
QT_MOC_LITERAL(16, 181, 12) // "bt_fun_slot5"

    },
    "set_data_para\0Timer_on_slot\0\0"
    "get_item_info_slot\0row\0col\0val_input_slot\0"
    "str\0seacher_slot\0uppage_slot\0downpage_slot\0"
    "clear_tip_slot\0bt_fun_slot1\0bt_fun_slot2\0"
    "bt_fun_slot3\0bt_fun_slot4\0bt_fun_slot5"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_set_data_para[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x0a /* Public */,
       3,    2,   75,    2, 0x08 /* Private */,
       6,    1,   80,    2, 0x08 /* Private */,
       8,    0,   83,    2, 0x08 /* Private */,
       9,    0,   84,    2, 0x08 /* Private */,
      10,    0,   85,    2, 0x08 /* Private */,
      11,    0,   86,    2, 0x08 /* Private */,
      12,    0,   87,    2, 0x08 /* Private */,
      13,    0,   88,    2, 0x08 /* Private */,
      14,    0,   89,    2, 0x08 /* Private */,
      15,    0,   90,    2, 0x08 /* Private */,
      16,    0,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void, QMetaType::QString,    7,
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

void set_data_para::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<set_data_para *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Timer_on_slot(); break;
        case 1: _t->get_item_info_slot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->val_input_slot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->seacher_slot(); break;
        case 4: _t->uppage_slot(); break;
        case 5: _t->downpage_slot(); break;
        case 6: _t->clear_tip_slot(); break;
        case 7: _t->bt_fun_slot1(); break;
        case 8: _t->bt_fun_slot2(); break;
        case 9: _t->bt_fun_slot3(); break;
        case 10: _t->bt_fun_slot4(); break;
        case 11: _t->bt_fun_slot5(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject set_data_para::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_set_data_para.data,
    qt_meta_data_set_data_para,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *set_data_para::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *set_data_para::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_set_data_para.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int set_data_para::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
