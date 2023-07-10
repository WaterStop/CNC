/****************************************************************************
** Meta object code from reading C++ file 'set_widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../project/set_widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'set_widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_set_widget_t {
    QByteArrayData data[13];
    char stringdata0[174];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_set_widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_set_widget_t qt_meta_stringdata_set_widget = {
    {
QT_MOC_LITERAL(0, 0, 10), // "set_widget"
QT_MOC_LITERAL(1, 11, 11), // "back_signal"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 13), // "Timer_on_slot"
QT_MOC_LITERAL(4, 38, 18), // "goto_work_scr_slot"
QT_MOC_LITERAL(5, 57, 13), // "goto_dgn_slot"
QT_MOC_LITERAL(6, 71, 18), // "goto_alm_info_slot"
QT_MOC_LITERAL(7, 90, 18), // "goto_alm_note_slot"
QT_MOC_LITERAL(8, 109, 19), // "goto_data_para_slot"
QT_MOC_LITERAL(9, 129, 9), // "back_slot"
QT_MOC_LITERAL(10, 139, 16), // "screen_jump_slot"
QT_MOC_LITERAL(11, 156, 5), // "index"
QT_MOC_LITERAL(12, 162, 11) // "parentIndex"

    },
    "set_widget\0back_signal\0\0Timer_on_slot\0"
    "goto_work_scr_slot\0goto_dgn_slot\0"
    "goto_alm_info_slot\0goto_alm_note_slot\0"
    "goto_data_para_slot\0back_slot\0"
    "screen_jump_slot\0index\0parentIndex"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_set_widget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   60,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x08 /* Private */,
       5,    0,   62,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    2,   67,    2, 0x08 /* Private */,

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
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   11,   12,

       0        // eod
};

void set_widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<set_widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->back_signal(); break;
        case 1: _t->Timer_on_slot(); break;
        case 2: _t->goto_work_scr_slot(); break;
        case 3: _t->goto_dgn_slot(); break;
        case 4: _t->goto_alm_info_slot(); break;
        case 5: _t->goto_alm_note_slot(); break;
        case 6: _t->goto_data_para_slot(); break;
        case 7: _t->back_slot(); break;
        case 8: _t->screen_jump_slot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (set_widget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&set_widget::back_signal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject set_widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_set_widget.data,
    qt_meta_data_set_widget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *set_widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *set_widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_set_widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int set_widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void set_widget::back_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
