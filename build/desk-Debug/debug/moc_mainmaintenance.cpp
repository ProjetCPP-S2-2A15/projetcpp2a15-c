/****************************************************************************
** Meta object code from reading C++ file 'mainmaintenance.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainmaintenance.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainmaintenance.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainMaintenanceENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainMaintenanceENDCLASS = QtMocHelpers::stringData(
    "MainMaintenance",
    "on_pushButton_ajouter_clicked",
    "",
    "on_tableView_clicked",
    "QModelIndex",
    "index",
    "on_pushButton_modifier_clicked",
    "on_pushButton_supprimer_clicked",
    "on_pushButton_telecharger_clicked",
    "on_pushButton_stat_clicked",
    "on_pushButton_tri_clicked",
    "on_pushButton_search_clicked",
    "onSearchTextChanged",
    "text",
    "on_pushButton_sms_clicked",
    "isAppActuallyRunning",
    "processName",
    "on_pushButton_email_clicked"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainMaintenanceENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x08,    1 /* Private */,
       3,    1,   87,    2, 0x08,    2 /* Private */,
       6,    0,   90,    2, 0x08,    4 /* Private */,
       7,    0,   91,    2, 0x08,    5 /* Private */,
       8,    0,   92,    2, 0x08,    6 /* Private */,
       9,    0,   93,    2, 0x08,    7 /* Private */,
      10,    0,   94,    2, 0x08,    8 /* Private */,
      11,    0,   95,    2, 0x08,    9 /* Private */,
      12,    1,   96,    2, 0x08,   10 /* Private */,
      14,    0,   99,    2, 0x08,   12 /* Private */,
      15,    1,  100,    2, 0x08,   13 /* Private */,
      17,    0,  103,    2, 0x08,   15 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,   16,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainMaintenance::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainMaintenanceENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainMaintenanceENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainMaintenanceENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainMaintenance, std::true_type>,
        // method 'on_pushButton_ajouter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_tableView_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'on_pushButton_modifier_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_supprimer_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_telecharger_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_stat_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_tri_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_search_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSearchTextChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_pushButton_sms_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'isAppActuallyRunning'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_pushButton_email_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainMaintenance::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainMaintenance *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_pushButton_ajouter_clicked(); break;
        case 1: _t->on_tableView_clicked((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 2: _t->on_pushButton_modifier_clicked(); break;
        case 3: _t->on_pushButton_supprimer_clicked(); break;
        case 4: _t->on_pushButton_telecharger_clicked(); break;
        case 5: _t->on_pushButton_stat_clicked(); break;
        case 6: _t->on_pushButton_tri_clicked(); break;
        case 7: _t->on_pushButton_search_clicked(); break;
        case 8: _t->onSearchTextChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 9: _t->on_pushButton_sms_clicked(); break;
        //case 10: { bool _r = _t->isAppActuallyRunning((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])));
            //if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->on_pushButton_email_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject *MainMaintenance::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainMaintenance::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainMaintenanceENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainMaintenance::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
