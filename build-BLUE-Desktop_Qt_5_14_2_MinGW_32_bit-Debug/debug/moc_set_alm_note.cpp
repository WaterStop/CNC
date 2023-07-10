/****************************************************************************
** Meta object code from reading C++ file 'set_alm_note.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../project/set_alm_note.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'set_alm_note.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_set_alm_note_t {
    QByteArrayData data[10];
    char stringdata0[113];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_set_alm_note_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_set_alm_note_t qt_meta_stringdata_set_alm_note = {
    {
QT_MOC_LITERAL(0, 0, 12), // "set_alm_note"
QT_MOC_LITERAL(1, 13, 13), // "Timer_on_slot"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 14), // "save_func_slot"
QT_MOC_LITERAL(4, 43, 16), // "del_almnote_slot"
QT_MOC_LITERAL(5, 60, 11), // "pageup_slot"
QT_MOC_LITERAL(6, 72, 13), // "pagedown_slot"
QT_MOC_LITERAL(7, 86, 18), // "get_item_info_slot"
QT_MOC_LITERAL(8, 105, 3), // "row"
QT_MOC_LITERAL(9, 109, 3) // "col"

    },
    "set_alm_note\0Timer_on_slot\0\0save_func_slot\0"
    "del_almnote_slot\0pageup_slot\0pagedown_slot\0"
    "get_item_info_slot\0row\0col"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_set_alm_note[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x0a /* Public */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    0,   48,    2, 0x08 /* Private */,
       7,    2,   49,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,

       0        // eod
};

void set_alm_note::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<set_alm_note *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Timer_on_slot(); break;
        case 1: _t->save_func_slot(); break;
        case 2: _t->del_almnote_slot(); break;
        case 3: _t->pageup_slot(); break;
        case 4: _t->pagedown_slot(); break;
        case 5: _t->get_item_info_slot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject set_alm_note::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_set_alm_note.data,
    qt_meta_data_set_alm_note,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *set_alm_note::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *set_alm_note::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_set_alm_note.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int set_alm_note::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
