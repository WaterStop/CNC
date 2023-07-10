/****************************************************************************
** Meta object code from reading C++ file 'widget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../project/widget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Widget_t {
    QByteArrayData data[27];
    char stringdata0[427];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Widget_t qt_meta_stringdata_Widget = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Widget"
QT_MOC_LITERAL(1, 7, 17), // "edit_input_signal"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 5), // "index"
QT_MOC_LITERAL(4, 32, 3), // "str"
QT_MOC_LITERAL(5, 36, 14), // "set_scr_change"
QT_MOC_LITERAL(6, 51, 7), // "scr_num"
QT_MOC_LITERAL(7, 59, 19), // "show_wg_popwin_slot"
QT_MOC_LITERAL(8, 79, 20), // "show_dis_screen_slot"
QT_MOC_LITERAL(9, 100, 13), // "Timer_on_slot"
QT_MOC_LITERAL(10, 114, 16), // "main_update_slot"
QT_MOC_LITERAL(11, 131, 19), // "goto_LuowenSet_slot"
QT_MOC_LITERAL(12, 151, 21), // "gouback_lastpage_slot"
QT_MOC_LITERAL(13, 173, 16), // "hide_fixval_slot"
QT_MOC_LITERAL(14, 190, 16), // "show_fixval_slot"
QT_MOC_LITERAL(15, 207, 16), // "addWorkInfo_slot"
QT_MOC_LITERAL(16, 224, 18), // "deal_pro_modi_slot"
QT_MOC_LITERAL(17, 243, 18), // "show_pro_modi_slot"
QT_MOC_LITERAL(18, 262, 19), // "goto_setcsreen_slot"
QT_MOC_LITERAL(19, 282, 17), // "show_keybord_slot"
QT_MOC_LITERAL(20, 300, 19), // "close_keyboard_slot"
QT_MOC_LITERAL(21, 320, 15), // "edit_input_slot"
QT_MOC_LITERAL(22, 336, 21), // "change_warn_text_slot"
QT_MOC_LITERAL(23, 358, 17), // "set_win_back_slot"
QT_MOC_LITERAL(24, 376, 14), // "page_jump_slot"
QT_MOC_LITERAL(25, 391, 21), // "jump_to_alm_info_slot"
QT_MOC_LITERAL(26, 413, 13) // "screen_change"

    },
    "Widget\0edit_input_signal\0\0index\0str\0"
    "set_scr_change\0scr_num\0show_wg_popwin_slot\0"
    "show_dis_screen_slot\0Timer_on_slot\0"
    "main_update_slot\0goto_LuowenSet_slot\0"
    "gouback_lastpage_slot\0hide_fixval_slot\0"
    "show_fixval_slot\0addWorkInfo_slot\0"
    "deal_pro_modi_slot\0show_pro_modi_slot\0"
    "goto_setcsreen_slot\0show_keybord_slot\0"
    "close_keyboard_slot\0edit_input_slot\0"
    "change_warn_text_slot\0set_win_back_slot\0"
    "page_jump_slot\0jump_to_alm_info_slot\0"
    "screen_change"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Widget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  124,    2, 0x06 /* Public */,
       5,    1,  129,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,  132,    2, 0x0a /* Public */,
       8,    0,  133,    2, 0x0a /* Public */,
       9,    0,  134,    2, 0x0a /* Public */,
      10,    0,  135,    2, 0x08 /* Private */,
      11,    0,  136,    2, 0x08 /* Private */,
      12,    0,  137,    2, 0x08 /* Private */,
      13,    0,  138,    2, 0x08 /* Private */,
      14,    0,  139,    2, 0x08 /* Private */,
      15,    1,  140,    2, 0x08 /* Private */,
      16,    1,  143,    2, 0x08 /* Private */,
      17,    1,  146,    2, 0x08 /* Private */,
      18,    0,  149,    2, 0x08 /* Private */,
      19,    1,  150,    2, 0x08 /* Private */,
      20,    0,  153,    2, 0x08 /* Private */,
      21,    2,  154,    2, 0x08 /* Private */,
      22,    0,  159,    2, 0x08 /* Private */,
      23,    0,  160,    2, 0x08 /* Private */,
      24,    1,  161,    2, 0x08 /* Private */,
      25,    0,  164,    2, 0x08 /* Private */,
      26,    1,  165,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::Int,    6,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

void Widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->edit_input_signal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->set_scr_change((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->show_wg_popwin_slot(); break;
        case 3: _t->show_dis_screen_slot(); break;
        case 4: _t->Timer_on_slot(); break;
        case 5: _t->main_update_slot(); break;
        case 6: _t->goto_LuowenSet_slot(); break;
        case 7: _t->gouback_lastpage_slot(); break;
        case 8: _t->hide_fixval_slot(); break;
        case 9: _t->show_fixval_slot(); break;
        case 10: _t->addWorkInfo_slot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->deal_pro_modi_slot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->show_pro_modi_slot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->goto_setcsreen_slot(); break;
        case 14: _t->show_keybord_slot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->close_keyboard_slot(); break;
        case 16: _t->edit_input_slot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 17: _t->change_warn_text_slot(); break;
        case 18: _t->set_win_back_slot(); break;
        case 19: _t->page_jump_slot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->jump_to_alm_info_slot(); break;
        case 21: _t->screen_change((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Widget::*)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Widget::edit_input_signal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Widget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Widget::set_scr_change)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Widget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Widget.data,
    qt_meta_data_Widget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 22;
    }
    return _id;
}

// SIGNAL 0
void Widget::edit_input_signal(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Widget::set_scr_change(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
