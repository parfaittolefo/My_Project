/****************************************************************************
** Meta object code from reading C++ file 'choice_page_2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Groupe23Projet5/Projet/Gestion_parc_auto/choice_page_2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'choice_page_2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_choice_page_2_t {
    QByteArrayData data[11];
    char stringdata0[187];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_choice_page_2_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_choice_page_2_t qt_meta_stringdata_choice_page_2 = {
    {
QT_MOC_LITERAL(0, 0, 13), // "choice_page_2"
QT_MOC_LITERAL(1, 14, 17), // "On_clicked_HirBtn"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 20), // "On_clicked_CareState"
QT_MOC_LITERAL(4, 54, 21), // "On_clicked_parc_State"
QT_MOC_LITERAL(5, 76, 19), // "On_clicked_backCare"
QT_MOC_LITERAL(6, 96, 17), // "On_clicked_SumBtn"
QT_MOC_LITERAL(7, 114, 18), // "On_clicked_delCare"
QT_MOC_LITERAL(8, 133, 14), // "On_clicked_sup"
QT_MOC_LITERAL(9, 148, 17), // "Onclicked_addCare"
QT_MOC_LITERAL(10, 166, 20) // "On_clicked_searchBtn"

    },
    "choice_page_2\0On_clicked_HirBtn\0\0"
    "On_clicked_CareState\0On_clicked_parc_State\0"
    "On_clicked_backCare\0On_clicked_SumBtn\0"
    "On_clicked_delCare\0On_clicked_sup\0"
    "Onclicked_addCare\0On_clicked_searchBtn"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_choice_page_2[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a /* Public */,
       3,    0,   60,    2, 0x0a /* Public */,
       4,    0,   61,    2, 0x0a /* Public */,
       5,    0,   62,    2, 0x0a /* Public */,
       6,    0,   63,    2, 0x0a /* Public */,
       7,    0,   64,    2, 0x0a /* Public */,
       8,    0,   65,    2, 0x0a /* Public */,
       9,    0,   66,    2, 0x0a /* Public */,
      10,    0,   67,    2, 0x0a /* Public */,

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

       0        // eod
};

void choice_page_2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<choice_page_2 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->On_clicked_HirBtn(); break;
        case 1: _t->On_clicked_CareState(); break;
        case 2: _t->On_clicked_parc_State(); break;
        case 3: _t->On_clicked_backCare(); break;
        case 4: _t->On_clicked_SumBtn(); break;
        case 5: _t->On_clicked_delCare(); break;
        case 6: _t->On_clicked_sup(); break;
        case 7: _t->Onclicked_addCare(); break;
        case 8: _t->On_clicked_searchBtn(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject choice_page_2::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_choice_page_2.data,
    qt_meta_data_choice_page_2,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *choice_page_2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *choice_page_2::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_choice_page_2.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int choice_page_2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
