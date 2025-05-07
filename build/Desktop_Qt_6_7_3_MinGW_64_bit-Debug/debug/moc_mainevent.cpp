/****************************************************************************
** Meta object code from reading C++ file 'mainevent.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainevent.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainevent.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSMainEventENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainEventENDCLASS = QtMocHelpers::stringData(
    "MainEvent",
    "onDateClicked",
    "",
    "date",
    "on_pushButton_Ajouter_clicked",
    "on_pushButton_Supprimer_clicked",
    "on_pushButton_Modifier_clicked",
    "on_pushButton_Afficher_clicked",
    "createConnection",
    "on_pushButton_afficherstatistiques_clicked",
    "afficherStatistiques",
    "exporterStatistiquesEnPDF",
    "rechercherEvenements",
    "trierEvenementsParID",
    "revenirAffichageNormal",
    "confirmerFermeture",
    "envoyerSMS",
    "numero",
    "message",
    "afficherEvenementsDansCalendrier",
    "on_pushButton_Afficher_2_clicked",
    "on_pushButton_7_clicked",
    "on_pushButton_10_clicked",
    "readArduinoData"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainEventENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  128,    2, 0x0a,    1 /* Public */,
       4,    0,  131,    2, 0x08,    3 /* Private */,
       5,    0,  132,    2, 0x08,    4 /* Private */,
       6,    0,  133,    2, 0x08,    5 /* Private */,
       7,    0,  134,    2, 0x08,    6 /* Private */,
       8,    0,  135,    2, 0x08,    7 /* Private */,
       9,    0,  136,    2, 0x08,    8 /* Private */,
      10,    0,  137,    2, 0x08,    9 /* Private */,
      11,    0,  138,    2, 0x08,   10 /* Private */,
      12,    0,  139,    2, 0x08,   11 /* Private */,
      13,    0,  140,    2, 0x08,   12 /* Private */,
      14,    0,  141,    2, 0x08,   13 /* Private */,
      15,    0,  142,    2, 0x08,   14 /* Private */,
      16,    2,  143,    2, 0x08,   15 /* Private */,
      19,    0,  148,    2, 0x08,   18 /* Private */,
      20,    0,  149,    2, 0x08,   19 /* Private */,
      21,    0,  150,    2, 0x08,   20 /* Private */,
      22,    0,  151,    2, 0x08,   21 /* Private */,
      23,    0,  152,    2, 0x08,   22 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QDate,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   17,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainEvent::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainEventENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainEventENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainEventENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainEvent, std::true_type>,
        // method 'onDateClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QDate &, std::false_type>,
        // method 'on_pushButton_Ajouter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_Supprimer_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_Modifier_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_Afficher_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'createConnection'
        QtPrivate::TypeAndForceComplete<bool, std::false_type>,
        // method 'on_pushButton_afficherstatistiques_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'afficherStatistiques'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'exporterStatistiquesEnPDF'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'rechercherEvenements'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'trierEvenementsParID'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'revenirAffichageNormal'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'confirmerFermeture'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'envoyerSMS'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'afficherEvenementsDansCalendrier'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_Afficher_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_7_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_10_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'readArduinoData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MainEvent::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainEvent *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onDateClicked((*reinterpret_cast< std::add_pointer_t<QDate>>(_a[1]))); break;
        case 1: _t->on_pushButton_Ajouter_clicked(); break;
        case 2: _t->on_pushButton_Supprimer_clicked(); break;
        case 3: _t->on_pushButton_Modifier_clicked(); break;
        case 4: _t->on_pushButton_Afficher_clicked(); break;
        case 5: { bool _r = _t->createConnection();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: _t->on_pushButton_afficherstatistiques_clicked(); break;
        case 7: _t->afficherStatistiques(); break;
        case 8: _t->exporterStatistiquesEnPDF(); break;
        case 9: _t->rechercherEvenements(); break;
        case 10: _t->trierEvenementsParID(); break;
        case 11: _t->revenirAffichageNormal(); break;
        case 12: _t->confirmerFermeture(); break;
        case 13: _t->envoyerSMS((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 14: _t->afficherEvenementsDansCalendrier(); break;
        case 15: _t->on_pushButton_Afficher_2_clicked(); break;
        case 16: _t->on_pushButton_7_clicked(); break;
        case 17: _t->on_pushButton_10_clicked(); break;
        case 18: _t->readArduinoData(); break;
        default: ;
        }
    }
}

const QMetaObject *MainEvent::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainEvent::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainEventENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainEvent::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 19;
    }
    return _id;
}
QT_WARNING_POP
