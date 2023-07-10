/****************************************************************************
** Meta object code from reading C++ file 'plc_plc_pic.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../project/plc_plc_pic.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'plc_plc_pic.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PLC_plc_pic_t {
    QByteArrayData data[9];
    char stringdata0[94];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PLC_plc_pic_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PLC_plc_pic_t qt_meta_stringdata_PLC_plc_pic = {
    {
QT_MOC_LITERAL(0, 0, 11), // "PLC_plc_pic"
QT_MOC_LITERAL(1, 12, 13), // "Timer_on_slot"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 12), // "page_up_slot"
QT_MOC_LITERAL(4, 40, 14), // "page_down_slot"
QT_MOC_LITERAL(5, 55, 7), // "up_slot"
QT_MOC_LITERAL(6, 63, 9), // "down_slot"
QT_MOC_LITERAL(7, 73, 9), // "left_slot"
QT_MOC_LITERAL(8, 83, 10) // "right_slot"

    },
    "PLC_plc_pic\0Timer_on_slot\0\0page_up_slot\0"
    "page_down_slot\0up_slot\0down_slot\0"
    "left_slot\0right_slot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PLC_plc_pic[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x08 /* Private */,
       3,    0,   50,    2, 0x08 /* Private */,
       4,    0,   51,    2, 0x08 /* Private */,
       5,    0,   52,    2, 0x08 /* Private */,
       6,    0,   53,    2, 0x08 /* Private */,
       7,    0,   54,    2, 0x08 /* Private */,
       8,    0,   55,    2, 0x08 /* Private */,

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

void PLC_plc_pic::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<PLC_plc_pic *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Timer_on_slot(); break;
        case 1: _t->page_up_slot(); break;
        case 2: _t->page_down_slot(); break;
        case 3: _t->up_slot(); break;
        case 4: _t->down_slot(); break;
        case 5: _t->left_slot(); break;
        case 6: _t->right_slot(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject PLC_plc_pic::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_PLC_plc_pic.data,
    qt_meta_data_PLC_plc_pic,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *PLC_plc_pic::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PLC_plc_pic::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PLC_plc_pic.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int PLC_plc_pic::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
