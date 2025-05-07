/****************************************************************************
** Meta object code from reading C++ file 'mainloclac.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../mainloclac.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCharts/qlineseries.h>
#include <QtCharts/qabstractbarseries.h>
#include <QtCharts/qvbarmodelmapper.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCharts/qcandlestickseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainloclac.h' doesn't include <QObject>."
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
struct qt_meta_stringdata_CLASSMainLoclacENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSMainLoclacENDCLASS = QtMocHelpers::stringData(
    "MainLoclac",
    "setCenter",
    "",
    "lat",
    "lng",
    "setCenterWithZoom",
    "zoom",
    "addMarker",
    "on_pushButton_ajouter_clicked",
    "afficherLocataires",
    "on_pushButton_ok_clicked",
    "on_pushButton_modifier_clicked",
    "on_pushButton_supprimer_clicked",
    "on_pushButton_triedate_clicked",
    "on_pushButton_trieid_clicked",
    "on_pushButton_6_clicked",
    "on_pushButton_mailing_clicked",
    "on_pushButton_telecharger_2_clicked",
    "envoyerEmail",
    "destinataire",
    "idLocataire",
    "on_pushButton_afficherStats_clicked",
    "on_pushButton_13_clicked",
    "handleChatResponse",
    "response",
    "handleChatError",
    "error",
    "on_sendChatMessage_clicked",
    "detecterIncendie",
    "idLocal",
    "incendieEmail",
    "on_readyRead",
    "on_pushButton_Ajouter_clicked",
    "on_pushButton_Annuler_clicked",
    "on_pushButton_Supprimer_clicked",
    "on_pushButton_Modifier_clicked",
    "mettreAJourAffichage",
    "on_pushButton_18_clicked",
    "rechercherLocaux",
    "on_pushButton_telecharger_clicked",
    "on_pushButton_statistique_clicked",
    "on_pushButton_envoyer_clicked",
    "on_pushButton_clear_clicked",
    "on_pushButton_11_clicked",
    "jeuDevineNombre",
    "verifierCaptchaEtLancerJeu",
    "pushButton_26_clicked",
    "on_connecter_clicked",
    "handleSerialData",
    "rfid"
);
#else  // !QT_MOC_HAS_STRINGDATA
#error "qtmochelpers.h not found or too old."
#endif // !QT_MOC_HAS_STRINGDATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainLoclacENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      39,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,  248,    2, 0x06,    1 /* Public */,
       5,    3,  253,    2, 0x06,    4 /* Public */,
       7,    2,  260,    2, 0x06,    8 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    0,  265,    2, 0x08,   11 /* Private */,
       9,    0,  266,    2, 0x08,   12 /* Private */,
      10,    0,  267,    2, 0x08,   13 /* Private */,
      11,    0,  268,    2, 0x08,   14 /* Private */,
      12,    0,  269,    2, 0x08,   15 /* Private */,
      13,    0,  270,    2, 0x08,   16 /* Private */,
      14,    0,  271,    2, 0x08,   17 /* Private */,
      15,    0,  272,    2, 0x08,   18 /* Private */,
      16,    0,  273,    2, 0x08,   19 /* Private */,
      17,    0,  274,    2, 0x08,   20 /* Private */,
      18,    2,  275,    2, 0x08,   21 /* Private */,
      21,    0,  280,    2, 0x08,   24 /* Private */,
      22,    0,  281,    2, 0x08,   25 /* Private */,
      23,    1,  282,    2, 0x08,   26 /* Private */,
      25,    1,  285,    2, 0x08,   28 /* Private */,
      27,    0,  288,    2, 0x08,   30 /* Private */,
      28,    1,  289,    2, 0x08,   31 /* Private */,
      30,    2,  292,    2, 0x08,   33 /* Private */,
      31,    0,  297,    2, 0x08,   36 /* Private */,
      32,    0,  298,    2, 0x08,   37 /* Private */,
      33,    0,  299,    2, 0x08,   38 /* Private */,
      34,    0,  300,    2, 0x08,   39 /* Private */,
      35,    0,  301,    2, 0x08,   40 /* Private */,
      36,    0,  302,    2, 0x08,   41 /* Private */,
      37,    0,  303,    2, 0x08,   42 /* Private */,
      38,    0,  304,    2, 0x08,   43 /* Private */,
      39,    0,  305,    2, 0x08,   44 /* Private */,
      40,    0,  306,    2, 0x08,   45 /* Private */,
      41,    0,  307,    2, 0x08,   46 /* Private */,
      42,    0,  308,    2, 0x08,   47 /* Private */,
      43,    0,  309,    2, 0x08,   48 /* Private */,
      44,    0,  310,    2, 0x08,   49 /* Private */,
      45,    0,  311,    2, 0x08,   50 /* Private */,
      46,    0,  312,    2, 0x08,   51 /* Private */,
      47,    0,  313,    2, 0x08,   52 /* Private */,
      48,    1,  314,    2, 0x08,   53 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariant, QMetaType::QVariant,    3,    4,
    QMetaType::Void, QMetaType::QVariant, QMetaType::QVariant, QMetaType::QVariant,    3,    4,    6,
    QMetaType::Void, QMetaType::QVariant, QMetaType::QVariant,    3,    4,

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
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   19,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   24,
    QMetaType::Void, QMetaType::QString,   26,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   29,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   19,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   49,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainLoclac::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainLoclacENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainLoclacENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainLoclacENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainLoclac, std::true_type>,
        // method 'setCenter'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVariant, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVariant, std::false_type>,
        // method 'setCenterWithZoom'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVariant, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVariant, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVariant, std::false_type>,
        // method 'addMarker'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVariant, std::false_type>,
        QtPrivate::TypeAndForceComplete<QVariant, std::false_type>,
        // method 'on_pushButton_ajouter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'afficherLocataires'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_ok_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_modifier_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_supprimer_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_triedate_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_trieid_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_6_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_mailing_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_telecharger_2_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'envoyerEmail'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'on_pushButton_afficherStats_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_13_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleChatResponse'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'handleChatError'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QString &, std::false_type>,
        // method 'on_sendChatMessage_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'detecterIncendie'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'incendieEmail'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>,
        // method 'on_readyRead'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_Ajouter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_Annuler_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_Supprimer_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_Modifier_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'mettreAJourAffichage'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_18_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'rechercherLocaux'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_telecharger_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_statistique_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_envoyer_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_clear_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_pushButton_11_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'jeuDevineNombre'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'verifierCaptchaEtLancerJeu'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'pushButton_26_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'on_connecter_clicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'handleSerialData'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QString, std::false_type>
    >,
    nullptr
} };

void MainLoclac::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainLoclac *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setCenter((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[2]))); break;
        case 1: _t->setCenterWithZoom((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[2])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[3]))); break;
        case 2: _t->addMarker((*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QVariant>>(_a[2]))); break;
        case 3: _t->on_pushButton_ajouter_clicked(); break;
        case 4: _t->afficherLocataires(); break;
        case 5: _t->on_pushButton_ok_clicked(); break;
        case 6: _t->on_pushButton_modifier_clicked(); break;
        case 7: _t->on_pushButton_supprimer_clicked(); break;
        case 8: _t->on_pushButton_triedate_clicked(); break;
        case 9: _t->on_pushButton_trieid_clicked(); break;
        case 10: _t->on_pushButton_6_clicked(); break;
        case 11: _t->on_pushButton_mailing_clicked(); break;
        case 12: _t->on_pushButton_telecharger_2_clicked(); break;
        case 13: _t->envoyerEmail((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 14: _t->on_pushButton_afficherStats_clicked(); break;
        case 15: _t->on_pushButton_13_clicked(); break;
        case 16: _t->handleChatResponse((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 17: _t->handleChatError((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 18: _t->on_sendChatMessage_clicked(); break;
        case 19: _t->detecterIncendie((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 20: _t->incendieEmail((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 21: _t->on_readyRead(); break;
        case 22: _t->on_pushButton_Ajouter_clicked(); break;
        case 23: _t->on_pushButton_Annuler_clicked(); break;
        case 24: _t->on_pushButton_Supprimer_clicked(); break;
        case 25: _t->on_pushButton_Modifier_clicked(); break;
        case 26: _t->mettreAJourAffichage(); break;
        case 27: _t->on_pushButton_18_clicked(); break;
        case 28: _t->rechercherLocaux(); break;
        case 29: _t->on_pushButton_telecharger_clicked(); break;
        case 30: _t->on_pushButton_statistique_clicked(); break;
        case 31: _t->on_pushButton_envoyer_clicked(); break;
        case 32: _t->on_pushButton_clear_clicked(); break;
        case 33: _t->on_pushButton_11_clicked(); break;
        case 34: _t->jeuDevineNombre(); break;
        case 35: _t->verifierCaptchaEtLancerJeu(); break;
        case 36: _t->pushButton_26_clicked(); break;
        //case 37: _t->on_connecter_clicked(); break;
        //case 38: _t->handleSerialData((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MainLoclac::*)(QVariant , QVariant );
            if (_t _q_method = &MainLoclac::setCenter; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MainLoclac::*)(QVariant , QVariant , QVariant );
            if (_t _q_method = &MainLoclac::setCenterWithZoom; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MainLoclac::*)(QVariant , QVariant );
            if (_t _q_method = &MainLoclac::addMarker; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject *MainLoclac::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainLoclac::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainLoclacENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainLoclac::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 39)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 39;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 39)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 39;
    }
    return _id;
}

// SIGNAL 0
void MainLoclac::setCenter(QVariant _t1, QVariant _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainLoclac::setCenterWithZoom(QVariant _t1, QVariant _t2, QVariant _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MainLoclac::addMarker(QVariant _t1, QVariant _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
