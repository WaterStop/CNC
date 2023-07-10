/****************************************************************************
** Meta object code from reading C++ file 'navlistview.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../project/navlistview.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'navlistview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NavDelegate_t {
    QByteArrayData data[1];
    char stringdata0[12];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NavDelegate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NavDelegate_t qt_meta_stringdata_NavDelegate = {
    {
QT_MOC_LITERAL(0, 0, 11) // "NavDelegate"

    },
    "NavDelegate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NavDelegate[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void NavDelegate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject NavDelegate::staticMetaObject = { {
    QMetaObject::SuperData::link<QStyledItemDelegate::staticMetaObject>(),
    qt_meta_stringdata_NavDelegate.data,
    qt_meta_data_NavDelegate,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NavDelegate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NavDelegate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NavDelegate.stringdata0))
        return static_cast<void*>(this);
    return QStyledItemDelegate::qt_metacast(_clname);
}

int NavDelegate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStyledItemDelegate::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_NavModel_t {
    QByteArrayData data[7];
    char stringdata0[50];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NavModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NavModel_t qt_meta_stringdata_NavModel = {
    {
QT_MOC_LITERAL(0, 0, 8), // "NavModel"
QT_MOC_LITERAL(1, 9, 8), // "setItems"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 5), // "items"
QT_MOC_LITERAL(4, 25, 6), // "expand"
QT_MOC_LITERAL(5, 32, 11), // "QModelIndex"
QT_MOC_LITERAL(6, 44, 5) // "index"

    },
    "NavModel\0setItems\0\0items\0expand\0"
    "QModelIndex\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NavModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x0a /* Public */,
       4,    1,   27,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList,    3,
    QMetaType::Void, 0x80000000 | 5,    6,

       0        // eod
};

void NavModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NavModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setItems((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 1: _t->expand((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject NavModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_NavModel.data,
    qt_meta_data_NavModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NavModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NavModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NavModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int NavModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
struct qt_meta_stringdata_NavListView_t {
    QByteArrayData data[90];
    char stringdata0[1421];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NavListView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NavListView_t qt_meta_stringdata_NavListView = {
    {
QT_MOC_LITERAL(0, 0, 11), // "NavListView"
QT_MOC_LITERAL(1, 12, 7), // "pressed"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 4), // "text"
QT_MOC_LITERAL(4, 26, 10), // "parentText"
QT_MOC_LITERAL(5, 37, 5), // "index"
QT_MOC_LITERAL(6, 43, 11), // "parentIndex"
QT_MOC_LITERAL(7, 55, 10), // "childIndex"
QT_MOC_LITERAL(8, 66, 11), // "QModelIndex"
QT_MOC_LITERAL(9, 78, 4), // "data"
QT_MOC_LITERAL(10, 83, 7), // "setData"
QT_MOC_LITERAL(11, 91, 9), // "listItems"
QT_MOC_LITERAL(12, 101, 8), // "setItems"
QT_MOC_LITERAL(13, 110, 5), // "items"
QT_MOC_LITERAL(14, 116, 13), // "setCurrentRow"
QT_MOC_LITERAL(15, 130, 3), // "row"
QT_MOC_LITERAL(16, 134, 19), // "setRightIconVisible"
QT_MOC_LITERAL(17, 154, 16), // "rightIconVisible"
QT_MOC_LITERAL(18, 171, 13), // "setTipVisible"
QT_MOC_LITERAL(19, 185, 10), // "tipVisible"
QT_MOC_LITERAL(20, 196, 11), // "setTipWidth"
QT_MOC_LITERAL(21, 208, 8), // "tipWidth"
QT_MOC_LITERAL(22, 217, 18), // "setSeparateVisible"
QT_MOC_LITERAL(23, 236, 15), // "separateVisible"
QT_MOC_LITERAL(24, 252, 17), // "setSeparateHeight"
QT_MOC_LITERAL(25, 270, 14), // "separateHeight"
QT_MOC_LITERAL(26, 285, 16), // "setSeparateColor"
QT_MOC_LITERAL(27, 302, 13), // "separateColor"
QT_MOC_LITERAL(28, 316, 11), // "setLineLeft"
QT_MOC_LITERAL(29, 328, 8), // "lineLeft"
QT_MOC_LITERAL(30, 337, 14), // "setLineVisible"
QT_MOC_LITERAL(31, 352, 11), // "lineVisible"
QT_MOC_LITERAL(32, 364, 12), // "setLineWidth"
QT_MOC_LITERAL(33, 377, 9), // "lineWidth"
QT_MOC_LITERAL(34, 387, 12), // "setLineColor"
QT_MOC_LITERAL(35, 400, 9), // "lineColor"
QT_MOC_LITERAL(36, 410, 15), // "setTriangleLeft"
QT_MOC_LITERAL(37, 426, 12), // "triangleLeft"
QT_MOC_LITERAL(38, 439, 18), // "setTriangleVisible"
QT_MOC_LITERAL(39, 458, 15), // "triangleVisible"
QT_MOC_LITERAL(40, 474, 16), // "setTriangleWidth"
QT_MOC_LITERAL(41, 491, 13), // "triangleWidth"
QT_MOC_LITERAL(42, 505, 16), // "setTriangleColor"
QT_MOC_LITERAL(43, 522, 13), // "triangleColor"
QT_MOC_LITERAL(44, 536, 19), // "setParentIconMargin"
QT_MOC_LITERAL(45, 556, 16), // "parentIconMargin"
QT_MOC_LITERAL(46, 573, 15), // "setParentMargin"
QT_MOC_LITERAL(47, 589, 12), // "parentMargin"
QT_MOC_LITERAL(48, 602, 17), // "setParentFontSize"
QT_MOC_LITERAL(49, 620, 14), // "parentFontSize"
QT_MOC_LITERAL(50, 635, 15), // "setParentHeight"
QT_MOC_LITERAL(51, 651, 12), // "parentHeight"
QT_MOC_LITERAL(52, 664, 22), // "setParentBgNormalColor"
QT_MOC_LITERAL(53, 687, 19), // "parentBgNormalColor"
QT_MOC_LITERAL(54, 707, 24), // "setParentBgSelectedColor"
QT_MOC_LITERAL(55, 732, 21), // "parentBgSelectedColor"
QT_MOC_LITERAL(56, 754, 21), // "setParentBgHoverColor"
QT_MOC_LITERAL(57, 776, 18), // "parentBgHoverColor"
QT_MOC_LITERAL(58, 795, 24), // "setParentTextNormalColor"
QT_MOC_LITERAL(59, 820, 21), // "parentTextNormalColor"
QT_MOC_LITERAL(60, 842, 26), // "setParentTextSelectedColor"
QT_MOC_LITERAL(61, 869, 23), // "parentTextSelectedColor"
QT_MOC_LITERAL(62, 893, 23), // "setParentTextHoverColor"
QT_MOC_LITERAL(63, 917, 20), // "parentTextHoverColor"
QT_MOC_LITERAL(64, 938, 18), // "setChildIconMargin"
QT_MOC_LITERAL(65, 957, 15), // "childIconMargin"
QT_MOC_LITERAL(66, 973, 14), // "setChildMargin"
QT_MOC_LITERAL(67, 988, 11), // "childMargin"
QT_MOC_LITERAL(68, 1000, 16), // "setChildFontSize"
QT_MOC_LITERAL(69, 1017, 13), // "childFontSize"
QT_MOC_LITERAL(70, 1031, 14), // "setChildHeight"
QT_MOC_LITERAL(71, 1046, 11), // "childHeight"
QT_MOC_LITERAL(72, 1058, 21), // "setChildBgNormalColor"
QT_MOC_LITERAL(73, 1080, 18), // "childBgNormalColor"
QT_MOC_LITERAL(74, 1099, 23), // "setChildBgSelectedColor"
QT_MOC_LITERAL(75, 1123, 20), // "childBgSelectedColor"
QT_MOC_LITERAL(76, 1144, 20), // "setChildBgHoverColor"
QT_MOC_LITERAL(77, 1165, 17), // "childBgHoverColor"
QT_MOC_LITERAL(78, 1183, 23), // "setChildTextNormalColor"
QT_MOC_LITERAL(79, 1207, 20), // "childTextNormalColor"
QT_MOC_LITERAL(80, 1228, 25), // "setChildTextSelectedColor"
QT_MOC_LITERAL(81, 1254, 22), // "childTextSelectedColor"
QT_MOC_LITERAL(82, 1277, 22), // "setChildTextHoverColor"
QT_MOC_LITERAL(83, 1300, 19), // "childTextHoverColor"
QT_MOC_LITERAL(84, 1320, 13), // "setExpendMode"
QT_MOC_LITERAL(85, 1334, 10), // "ExpendMode"
QT_MOC_LITERAL(86, 1345, 10), // "expendMode"
QT_MOC_LITERAL(87, 1356, 22), // "ExpendMode_SingleClick"
QT_MOC_LITERAL(88, 1379, 22), // "ExpendMode_DoubleClick"
QT_MOC_LITERAL(89, 1402, 18) // "ExpendMode_NoClick"

    },
    "NavListView\0pressed\0\0text\0parentText\0"
    "index\0parentIndex\0childIndex\0QModelIndex\0"
    "data\0setData\0listItems\0setItems\0items\0"
    "setCurrentRow\0row\0setRightIconVisible\0"
    "rightIconVisible\0setTipVisible\0"
    "tipVisible\0setTipWidth\0tipWidth\0"
    "setSeparateVisible\0separateVisible\0"
    "setSeparateHeight\0separateHeight\0"
    "setSeparateColor\0separateColor\0"
    "setLineLeft\0lineLeft\0setLineVisible\0"
    "lineVisible\0setLineWidth\0lineWidth\0"
    "setLineColor\0lineColor\0setTriangleLeft\0"
    "triangleLeft\0setTriangleVisible\0"
    "triangleVisible\0setTriangleWidth\0"
    "triangleWidth\0setTriangleColor\0"
    "triangleColor\0setParentIconMargin\0"
    "parentIconMargin\0setParentMargin\0"
    "parentMargin\0setParentFontSize\0"
    "parentFontSize\0setParentHeight\0"
    "parentHeight\0setParentBgNormalColor\0"
    "parentBgNormalColor\0setParentBgSelectedColor\0"
    "parentBgSelectedColor\0setParentBgHoverColor\0"
    "parentBgHoverColor\0setParentTextNormalColor\0"
    "parentTextNormalColor\0setParentTextSelectedColor\0"
    "parentTextSelectedColor\0setParentTextHoverColor\0"
    "parentTextHoverColor\0setChildIconMargin\0"
    "childIconMargin\0setChildMargin\0"
    "childMargin\0setChildFontSize\0childFontSize\0"
    "setChildHeight\0childHeight\0"
    "setChildBgNormalColor\0childBgNormalColor\0"
    "setChildBgSelectedColor\0childBgSelectedColor\0"
    "setChildBgHoverColor\0childBgHoverColor\0"
    "setChildTextNormalColor\0childTextNormalColor\0"
    "setChildTextSelectedColor\0"
    "childTextSelectedColor\0setChildTextHoverColor\0"
    "childTextHoverColor\0setExpendMode\0"
    "ExpendMode\0expendMode\0ExpendMode_SingleClick\0"
    "ExpendMode_DoubleClick\0ExpendMode_NoClick"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NavListView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      42,   14, // methods
      36,  354, // properties
       1,  462, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,  224,    2, 0x06 /* Public */,
       1,    2,  229,    2, 0x06 /* Public */,
       1,    1,  234,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       1,    1,  237,    2, 0x08 /* Private */,
      10,    1,  240,    2, 0x08 /* Private */,
      12,    1,  243,    2, 0x0a /* Public */,
      14,    1,  246,    2, 0x0a /* Public */,
      16,    1,  249,    2, 0x0a /* Public */,
      18,    1,  252,    2, 0x0a /* Public */,
      20,    1,  255,    2, 0x0a /* Public */,
      22,    1,  258,    2, 0x0a /* Public */,
      24,    1,  261,    2, 0x0a /* Public */,
      26,    1,  264,    2, 0x0a /* Public */,
      28,    1,  267,    2, 0x0a /* Public */,
      30,    1,  270,    2, 0x0a /* Public */,
      32,    1,  273,    2, 0x0a /* Public */,
      34,    1,  276,    2, 0x0a /* Public */,
      36,    1,  279,    2, 0x0a /* Public */,
      38,    1,  282,    2, 0x0a /* Public */,
      40,    1,  285,    2, 0x0a /* Public */,
      42,    1,  288,    2, 0x0a /* Public */,
      44,    1,  291,    2, 0x0a /* Public */,
      46,    1,  294,    2, 0x0a /* Public */,
      48,    1,  297,    2, 0x0a /* Public */,
      50,    1,  300,    2, 0x0a /* Public */,
      52,    1,  303,    2, 0x0a /* Public */,
      54,    1,  306,    2, 0x0a /* Public */,
      56,    1,  309,    2, 0x0a /* Public */,
      58,    1,  312,    2, 0x0a /* Public */,
      60,    1,  315,    2, 0x0a /* Public */,
      62,    1,  318,    2, 0x0a /* Public */,
      64,    1,  321,    2, 0x0a /* Public */,
      66,    1,  324,    2, 0x0a /* Public */,
      68,    1,  327,    2, 0x0a /* Public */,
      70,    1,  330,    2, 0x0a /* Public */,
      72,    1,  333,    2, 0x0a /* Public */,
      74,    1,  336,    2, 0x0a /* Public */,
      76,    1,  339,    2, 0x0a /* Public */,
      78,    1,  342,    2, 0x0a /* Public */,
      80,    1,  345,    2, 0x0a /* Public */,
      82,    1,  348,    2, 0x0a /* Public */,
      84,    1,  351,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void, QMetaType::Int,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QStringList,   11,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Bool,   17,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void, QMetaType::Bool,   23,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void, QMetaType::QColor,   27,
    QMetaType::Void, QMetaType::Bool,   29,
    QMetaType::Void, QMetaType::Bool,   31,
    QMetaType::Void, QMetaType::Int,   33,
    QMetaType::Void, QMetaType::QColor,   35,
    QMetaType::Void, QMetaType::Bool,   37,
    QMetaType::Void, QMetaType::Bool,   39,
    QMetaType::Void, QMetaType::Int,   41,
    QMetaType::Void, QMetaType::QColor,   43,
    QMetaType::Void, QMetaType::Int,   45,
    QMetaType::Void, QMetaType::Int,   47,
    QMetaType::Void, QMetaType::Int,   49,
    QMetaType::Void, QMetaType::Int,   51,
    QMetaType::Void, QMetaType::QColor,   53,
    QMetaType::Void, QMetaType::QColor,   55,
    QMetaType::Void, QMetaType::QColor,   57,
    QMetaType::Void, QMetaType::QColor,   59,
    QMetaType::Void, QMetaType::QColor,   61,
    QMetaType::Void, QMetaType::QColor,   63,
    QMetaType::Void, QMetaType::Int,   65,
    QMetaType::Void, QMetaType::Int,   67,
    QMetaType::Void, QMetaType::Int,   69,
    QMetaType::Void, QMetaType::Int,   71,
    QMetaType::Void, QMetaType::QColor,   73,
    QMetaType::Void, QMetaType::QColor,   75,
    QMetaType::Void, QMetaType::QColor,   77,
    QMetaType::Void, QMetaType::QColor,   79,
    QMetaType::Void, QMetaType::QColor,   81,
    QMetaType::Void, QMetaType::QColor,   83,
    QMetaType::Void, 0x80000000 | 85,   86,

 // properties: name, type, flags
      13, QMetaType::QString, 0x00095103,
      17, QMetaType::Bool, 0x00095103,
      19, QMetaType::Bool, 0x00095103,
      21, QMetaType::Int, 0x00095103,
      23, QMetaType::Bool, 0x00095103,
      25, QMetaType::Int, 0x00095103,
      27, QMetaType::QColor, 0x00095103,
      29, QMetaType::Bool, 0x00095103,
      31, QMetaType::Bool, 0x00095103,
      33, QMetaType::Int, 0x00095103,
      35, QMetaType::QColor, 0x00095103,
      37, QMetaType::Bool, 0x00095103,
      39, QMetaType::Bool, 0x00095103,
      41, QMetaType::Int, 0x00095103,
      43, QMetaType::QColor, 0x00095103,
      45, QMetaType::Int, 0x00095103,
      47, QMetaType::Int, 0x00095103,
      49, QMetaType::Int, 0x00095103,
      51, QMetaType::Int, 0x00095103,
      53, QMetaType::QColor, 0x00095103,
      55, QMetaType::QColor, 0x00095103,
      57, QMetaType::QColor, 0x00095103,
      59, QMetaType::QColor, 0x00095103,
      61, QMetaType::QColor, 0x00095103,
      63, QMetaType::QColor, 0x00095103,
      65, QMetaType::Int, 0x00095103,
      67, QMetaType::Int, 0x00095103,
      69, QMetaType::Int, 0x00095103,
      71, QMetaType::Int, 0x00095103,
      73, QMetaType::QColor, 0x00095103,
      75, QMetaType::QColor, 0x00095103,
      77, QMetaType::QColor, 0x00095103,
      79, QMetaType::QColor, 0x00095103,
      81, QMetaType::QColor, 0x00095103,
      83, QMetaType::QColor, 0x00095103,
      86, 0x80000000 | 85, 0x0009510b,

 // enums: name, alias, flags, count, data
      85,   85, 0x0,    3,  467,

 // enum data: key, value
      87, uint(NavListView::ExpendMode_SingleClick),
      88, uint(NavListView::ExpendMode_DoubleClick),
      89, uint(NavListView::ExpendMode_NoClick),

       0        // eod
};

void NavListView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NavListView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->pressed((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->pressed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->pressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->pressed((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 4: _t->setData((*reinterpret_cast< const QStringList(*)>(_a[1]))); break;
        case 5: _t->setItems((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->setCurrentRow((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setRightIconVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->setTipVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->setTipWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->setSeparateVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->setSeparateHeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->setSeparateColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 13: _t->setLineLeft((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->setLineVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->setLineWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->setLineColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 17: _t->setTriangleLeft((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->setTriangleVisible((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: _t->setTriangleWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->setTriangleColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 21: _t->setParentIconMargin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->setParentMargin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->setParentFontSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->setParentHeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->setParentBgNormalColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 26: _t->setParentBgSelectedColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 27: _t->setParentBgHoverColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 28: _t->setParentTextNormalColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 29: _t->setParentTextSelectedColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 30: _t->setParentTextHoverColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 31: _t->setChildIconMargin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->setChildMargin((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: _t->setChildFontSize((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->setChildHeight((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 35: _t->setChildBgNormalColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 36: _t->setChildBgSelectedColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 37: _t->setChildBgHoverColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 38: _t->setChildTextNormalColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 39: _t->setChildTextSelectedColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 40: _t->setChildTextHoverColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 41: _t->setExpendMode((*reinterpret_cast< const ExpendMode(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (NavListView::*)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavListView::pressed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (NavListView::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavListView::pressed)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (NavListView::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&NavListView::pressed)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<NavListView *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->getItems(); break;
        case 1: *reinterpret_cast< bool*>(_v) = _t->getRightIconVisible(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->getTipVisible(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->getTipWidth(); break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->getSeparateVisible(); break;
        case 5: *reinterpret_cast< int*>(_v) = _t->getSeparateHeight(); break;
        case 6: *reinterpret_cast< QColor*>(_v) = _t->getSeparateColor(); break;
        case 7: *reinterpret_cast< bool*>(_v) = _t->getLineLeft(); break;
        case 8: *reinterpret_cast< bool*>(_v) = _t->getLineVisible(); break;
        case 9: *reinterpret_cast< int*>(_v) = _t->getLineWidth(); break;
        case 10: *reinterpret_cast< QColor*>(_v) = _t->getLineColor(); break;
        case 11: *reinterpret_cast< bool*>(_v) = _t->getTriangleLeft(); break;
        case 12: *reinterpret_cast< bool*>(_v) = _t->getTriangleVisible(); break;
        case 13: *reinterpret_cast< int*>(_v) = _t->getTriangleWidth(); break;
        case 14: *reinterpret_cast< QColor*>(_v) = _t->getTriangleColor(); break;
        case 15: *reinterpret_cast< int*>(_v) = _t->getParentIconMargin(); break;
        case 16: *reinterpret_cast< int*>(_v) = _t->getParentMargin(); break;
        case 17: *reinterpret_cast< int*>(_v) = _t->getParentFontSize(); break;
        case 18: *reinterpret_cast< int*>(_v) = _t->getParentHeight(); break;
        case 19: *reinterpret_cast< QColor*>(_v) = _t->getParentBgNormalColor(); break;
        case 20: *reinterpret_cast< QColor*>(_v) = _t->getParentBgSelectedColor(); break;
        case 21: *reinterpret_cast< QColor*>(_v) = _t->getParentBgHoverColor(); break;
        case 22: *reinterpret_cast< QColor*>(_v) = _t->getParentTextNormalColor(); break;
        case 23: *reinterpret_cast< QColor*>(_v) = _t->getParentTextSelectedColor(); break;
        case 24: *reinterpret_cast< QColor*>(_v) = _t->getParentTextHoverColor(); break;
        case 25: *reinterpret_cast< int*>(_v) = _t->getChildIconMargin(); break;
        case 26: *reinterpret_cast< int*>(_v) = _t->getChildMargin(); break;
        case 27: *reinterpret_cast< int*>(_v) = _t->getChildFontSize(); break;
        case 28: *reinterpret_cast< int*>(_v) = _t->getChildHeight(); break;
        case 29: *reinterpret_cast< QColor*>(_v) = _t->getChildBgNormalColor(); break;
        case 30: *reinterpret_cast< QColor*>(_v) = _t->getChildBgSelectedColor(); break;
        case 31: *reinterpret_cast< QColor*>(_v) = _t->getChildBgHoverColor(); break;
        case 32: *reinterpret_cast< QColor*>(_v) = _t->getChildTextNormalColor(); break;
        case 33: *reinterpret_cast< QColor*>(_v) = _t->getChildTextSelectedColor(); break;
        case 34: *reinterpret_cast< QColor*>(_v) = _t->getChildTextHoverColor(); break;
        case 35: *reinterpret_cast< ExpendMode*>(_v) = _t->getExpendMode(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<NavListView *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setItems(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setRightIconVisible(*reinterpret_cast< bool*>(_v)); break;
        case 2: _t->setTipVisible(*reinterpret_cast< bool*>(_v)); break;
        case 3: _t->setTipWidth(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->setSeparateVisible(*reinterpret_cast< bool*>(_v)); break;
        case 5: _t->setSeparateHeight(*reinterpret_cast< int*>(_v)); break;
        case 6: _t->setSeparateColor(*reinterpret_cast< QColor*>(_v)); break;
        case 7: _t->setLineLeft(*reinterpret_cast< bool*>(_v)); break;
        case 8: _t->setLineVisible(*reinterpret_cast< bool*>(_v)); break;
        case 9: _t->setLineWidth(*reinterpret_cast< int*>(_v)); break;
        case 10: _t->setLineColor(*reinterpret_cast< QColor*>(_v)); break;
        case 11: _t->setTriangleLeft(*reinterpret_cast< bool*>(_v)); break;
        case 12: _t->setTriangleVisible(*reinterpret_cast< bool*>(_v)); break;
        case 13: _t->setTriangleWidth(*reinterpret_cast< int*>(_v)); break;
        case 14: _t->setTriangleColor(*reinterpret_cast< QColor*>(_v)); break;
        case 15: _t->setParentIconMargin(*reinterpret_cast< int*>(_v)); break;
        case 16: _t->setParentMargin(*reinterpret_cast< int*>(_v)); break;
        case 17: _t->setParentFontSize(*reinterpret_cast< int*>(_v)); break;
        case 18: _t->setParentHeight(*reinterpret_cast< int*>(_v)); break;
        case 19: _t->setParentBgNormalColor(*reinterpret_cast< QColor*>(_v)); break;
        case 20: _t->setParentBgSelectedColor(*reinterpret_cast< QColor*>(_v)); break;
        case 21: _t->setParentBgHoverColor(*reinterpret_cast< QColor*>(_v)); break;
        case 22: _t->setParentTextNormalColor(*reinterpret_cast< QColor*>(_v)); break;
        case 23: _t->setParentTextSelectedColor(*reinterpret_cast< QColor*>(_v)); break;
        case 24: _t->setParentTextHoverColor(*reinterpret_cast< QColor*>(_v)); break;
        case 25: _t->setChildIconMargin(*reinterpret_cast< int*>(_v)); break;
        case 26: _t->setChildMargin(*reinterpret_cast< int*>(_v)); break;
        case 27: _t->setChildFontSize(*reinterpret_cast< int*>(_v)); break;
        case 28: _t->setChildHeight(*reinterpret_cast< int*>(_v)); break;
        case 29: _t->setChildBgNormalColor(*reinterpret_cast< QColor*>(_v)); break;
        case 30: _t->setChildBgSelectedColor(*reinterpret_cast< QColor*>(_v)); break;
        case 31: _t->setChildBgHoverColor(*reinterpret_cast< QColor*>(_v)); break;
        case 32: _t->setChildTextNormalColor(*reinterpret_cast< QColor*>(_v)); break;
        case 33: _t->setChildTextSelectedColor(*reinterpret_cast< QColor*>(_v)); break;
        case 34: _t->setChildTextHoverColor(*reinterpret_cast< QColor*>(_v)); break;
        case 35: _t->setExpendMode(*reinterpret_cast< ExpendMode*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject NavListView::staticMetaObject = { {
    QMetaObject::SuperData::link<QListView::staticMetaObject>(),
    qt_meta_stringdata_NavListView.data,
    qt_meta_data_NavListView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NavListView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NavListView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NavListView.stringdata0))
        return static_cast<void*>(this);
    return QListView::qt_metacast(_clname);
}

int NavListView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 42)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 42;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 42)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 42;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 36;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 36;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 36;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 36;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 36;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 36;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void NavListView::pressed(const QString & _t1, const QString & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void NavListView::pressed(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void NavListView::pressed(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
