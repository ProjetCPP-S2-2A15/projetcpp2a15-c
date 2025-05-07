/********************************************************************************
** Form generated from reading UI file 'mainservice.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSERVICE_H
#define UI_MAINSERVICE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainService
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page_3;
    QFrame *main_body;
    QVBoxLayout *verticalLayout;
    QFrame *header_frame;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_8;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_3;
    QPushButton *pushButton_6;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_4;
    QFrame *main_body_contents;
    QFrame *frame_12;
    QLabel *label_nomApp;
    QTabWidget *arduino;
    QWidget *tab;
    QLabel *label_id;
    QLabel *label_nom;
    QLabel *label_description;
    QLabel *label_type;
    QLabel *label_lieu;
    QLineEdit *le_id_ser;
    QLineEdit *le_prix;
    QLineEdit *le_nom;
    QPushButton *pushButton_ajouter;
    QPushButton *pushButton_annuler;
    QLabel *label_heure;
    QLabel *label_dateC;
    QDateEdit *le_dated_date;
    QLineEdit *le_descrip;
    QDateEdit *le_datef_date;
    QLabel *label_heure_2;
    QComboBox *le_type;
    QComboBox *le_statut;
    QWidget *tab_2;
    QPushButton *pushButton_annuler_2;
    QPushButton *pushButton_ok;
    QLineEdit *le_modif_id_ser;
    QPushButton *pushButton_modifier;
    QLabel *label_id_2;
    QLabel *label_nom_2;
    QLabel *label_description_2;
    QLabel *label_type_2;
    QLabel *label_lieu_2;
    QLabel *label_date;
    QLabel *label_time;
    QLineEdit *le_modif_nom;
    QLineEdit *le_modif_prix;
    QDateEdit *le_modif_dated_date;
    QDateEdit *le_modif_datef_date;
    QLineEdit *le_modif_descrip;
    QLabel *label_lieu_3;
    QComboBox *le_modif_type;
    QComboBox *le_modif_statut;
    QWidget *tab_3;
    QPushButton *pushButton_supprimer;
    QPushButton *pushButton_annuler_3;
    QLabel *label_id_3;
    QLineEdit *id_supp;
    QWidget *tab_10;
    QLineEdit *event1;
    QLabel *label_nom_7;
    QPushButton *rechercher;
    QPushButton *pushButton_telecharger_pdf;
    QLabel *notificationLibel;
    QPushButton *pushButton_crud;
    QLabel *label_11;
    QPushButton *pushButton_noti;
    QLabel *label_12;
    QPushButton *pushButton_annuler_search;
    QTableView *tab_Services;
    QPushButton *pb_rechercher;
    QLineEdit *le_recherche;
    QComboBox *le_trier;
    QPushButton *pb_tier;
    QPushButton *pushButton_fonctionnalites_2;
    QPushButton *aff_statistique;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *layout_statistique;
    QFrame *footer;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_7;
    QFrame *size_grip;
    QWidget *page_4;
    QPushButton *pushButton_crud_2;
    QPushButton *pushButton_fonctionnalites_3;
    QListWidget *listWidgetHistorique;
    QPushButton *pushButton_delete;
    QPushButton *pushButton_exp;
    QPushButton *pushButton_add;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_12;
    QPushButton *actualiser;
    QFrame *slide_menu_container;
    QVBoxLayout *verticalLayout_2;
    QFrame *slide_menu;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame_7;
    QHBoxLayout *verticalLayout_13;
    QLabel *label_2;
    QLabel *label_3;
    QFrame *frame_8;
    QVBoxLayout *verticalLayout_7;
    QToolBox *toolBox;
    QWidget *page;
    QVBoxLayout *verticalLayout_8;
    QFrame *frame_10;
    QVBoxLayout *verticalLayout_9;
    QPushButton *gestionemployeebtn;
    QPushButton *gestionlocatairesbtn;
    QPushButton *gestionmaintenancebtn;
    QPushButton *gestionlocauxbtn;
    QPushButton *gestioneventbtn;
    QPushButton *pushButton_16;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_10;
    QFrame *frame_11;
    QVBoxLayout *verticalLayout_11;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QLabel *label_4;
    QFrame *frame_9;
    QVBoxLayout *verticalLayout_6;
    QPushButton *pushButton_9;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainService)
    {
        if (MainService->objectName().isEmpty())
            MainService->setObjectName("MainService");
        MainService->resize(1320, 704);
        centralwidget = new QWidget(MainService);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(217, 10, 1097, 631));
        stackedWidget->setStyleSheet(QString::fromUtf8("    QTabWidget::pane { \n"
"        border: 0px solid #eae2b7; \n"
"    }\n"
"    QTabBar::tab { \n"
"        background:#eae2b7; \n"
"        color: black; \n"
"        padding: 8px; \n"
"		border-radius: 0px; \n"
"    }\n"
"    QTabBar::tab:selected { \n"
"        background:#a48f66  ; \n"
"        color:white; \n"
"        font-weight: bold; \n"
"    }\n"
"    QTabBar::tab:hover {\n"
"        background: #c0b49a ; \n"
"    }\n"
";\n"
"background-color: #f5f2db;"));
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        main_body = new QFrame(page_3);
        main_body->setObjectName("main_body");
        main_body->setGeometry(QRect(10, 20, 1097, 631));
        main_body->setFrameShape(QFrame::Shape::StyledPanel);
        main_body->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout = new QVBoxLayout(main_body);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        header_frame = new QFrame(main_body);
        header_frame->setObjectName("header_frame");
        header_frame->setFrameShape(QFrame::Shape::StyledPanel);
        header_frame->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_2 = new QHBoxLayout(header_frame);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        frame_6 = new QFrame(header_frame);
        frame_6->setObjectName("frame_6");
        frame_6->setFrameShape(QFrame::Shape::StyledPanel);
        frame_6->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_6 = new QHBoxLayout(frame_6);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        pushButton_8 = new QPushButton(frame_6);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 242, 219);"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../Atelier_Connexio/Atelier_Connexion/Atelier_Connexion/icons/align-left.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        pushButton_8->setIcon(icon);
        pushButton_8->setIconSize(QSize(32, 32));

        horizontalLayout_6->addWidget(pushButton_8);


        horizontalLayout_2->addWidget(frame_6, 0, Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);

        frame_2 = new QFrame(header_frame);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame_2);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(frame_2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 242, 219);\n"
""));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../../Atelier_Connexio/Atelier_Connexion/Atelier_Connexion/icons/x.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        pushButton_3->setIcon(icon1);

        horizontalLayout_5->addWidget(pushButton_3);

        pushButton_6 = new QPushButton(frame_2);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 242, 219);"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../../../Atelier_Connexio/Atelier_Connexion/Atelier_Connexion/icons/search.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        pushButton_6->setIcon(icon2);

        horizontalLayout_5->addWidget(pushButton_6);

        pushButton_4 = new QPushButton(frame_2);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 242, 219);"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../../../Atelier_Connexio/Atelier_Connexion/Atelier_Connexion/icons/bell.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        pushButton_4->setIcon(icon3);

        horizontalLayout_5->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(frame_2);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 242, 219);"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../../../Atelier_Connexio/Atelier_Connexion/Atelier_Connexion/icons/user.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        pushButton_5->setIcon(icon4);

        horizontalLayout_5->addWidget(pushButton_5);

        pushButton_2 = new QPushButton(frame_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 242, 219);"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("../../../Atelier_Connexio/Atelier_Connexion/Atelier_Connexion/icons/arrow-down-left.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        pushButton_2->setIcon(icon5);

        horizontalLayout_5->addWidget(pushButton_2);


        horizontalLayout_2->addWidget(frame_2);

        lineEdit = new QLineEdit(header_frame);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 242, 219);"));

        horizontalLayout_2->addWidget(lineEdit);

        frame_3 = new QFrame(header_frame);
        frame_3->setObjectName("frame_3");
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout = new QHBoxLayout(frame_3);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);

        horizontalLayout_2->addWidget(frame_3, 0, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignTop);

        frame = new QFrame(header_frame);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);

        horizontalLayout_2->addWidget(frame, 0, Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTop);


        verticalLayout->addWidget(header_frame);

        main_body_contents = new QFrame(main_body);
        main_body_contents->setObjectName("main_body_contents");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(main_body_contents->sizePolicy().hasHeightForWidth());
        main_body_contents->setSizePolicy(sizePolicy);
        main_body_contents->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 242, 219);"));
        main_body_contents->setFrameShape(QFrame::Shape::StyledPanel);
        main_body_contents->setFrameShadow(QFrame::Shadow::Raised);
        frame_12 = new QFrame(main_body_contents);
        frame_12->setObjectName("frame_12");
        frame_12->setGeometry(QRect(40, 120, 301, 431));
        frame_12->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"background-color: rgb(86, 1, 38);\n"
"color: rgb(86, 1, 38);\n"
"border-radius: 40px;\n"
"font: 900 italic 8pt \"Segoe UI\";"));
        frame_12->setFrameShape(QFrame::Shape::StyledPanel);
        frame_12->setFrameShadow(QFrame::Shadow::Raised);
        label_nomApp = new QLabel(frame_12);
        label_nomApp->setObjectName("label_nomApp");
        label_nomApp->setGeometry(QRect(30, 20, 221, 31));
        label_nomApp->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 700 italic 12pt \"Segoe UI\";\n"
"background-color: rgb(238, 228, 204);\n"
"border-radius: 8px;\n"
"\n"
"\n"
"font: 900 italic 11pt \"Segoe UI\";\n"
"\n"
"\n"
""));
        arduino = new QTabWidget(frame_12);
        arduino->setObjectName("arduino");
        arduino->setGeometry(QRect(10, 70, 281, 311));
        arduino->setStyleSheet(QString::fromUtf8("    QTabWidget::pane { \n"
"        border: 0px solid #eae2b7; \n"
"    }\n"
"    QTabBar::tab { \n"
"        background:#eae2b7; \n"
"        color: black; \n"
"        padding: 8px; \n"
"		border-radius: 0px; \n"
"    }\n"
"    QTabBar::tab:selected { \n"
"        background:#a48f66  ; \n"
"        color:white; \n"
"        font-weight: bold; \n"
"    }\n"
"    QTabBar::tab:hover {\n"
"        background: #c0b49a ; \n"
"    }\n"
";\n"
"background-color: #f5f2db;"));
        tab = new QWidget();
        tab->setObjectName("tab");
        label_id = new QLabel(tab);
        label_id->setObjectName("label_id");
        label_id->setGeometry(QRect(20, 30, 91, 16));
        label_id->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        label_nom = new QLabel(tab);
        label_nom->setObjectName("label_nom");
        label_nom->setGeometry(QRect(20, 50, 91, 16));
        label_nom->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        label_description = new QLabel(tab);
        label_description->setObjectName("label_description");
        label_description->setGeometry(QRect(20, 70, 91, 16));
        label_description->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        label_type = new QLabel(tab);
        label_type->setObjectName("label_type");
        label_type->setGeometry(QRect(20, 90, 91, 16));
        label_type->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        label_lieu = new QLabel(tab);
        label_lieu->setObjectName("label_lieu");
        label_lieu->setGeometry(QRect(20, 110, 91, 16));
        label_lieu->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        le_id_ser = new QLineEdit(tab);
        le_id_ser->setObjectName("le_id_ser");
        le_id_ser->setGeometry(QRect(140, 30, 121, 16));
        le_id_ser->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"color: rgb(86, 1, 38);"));
        le_prix = new QLineEdit(tab);
        le_prix->setObjectName("le_prix");
        le_prix->setGeometry(QRect(140, 70, 121, 16));
        le_prix->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid  #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"color: rgb(86, 1, 38);"));
        le_nom = new QLineEdit(tab);
        le_nom->setObjectName("le_nom");
        le_nom->setGeometry(QRect(140, 50, 121, 16));
        le_nom->setStyleSheet(QString::fromUtf8("color: rgb(86, 1, 38);\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid  #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        pushButton_ajouter = new QPushButton(tab);
        pushButton_ajouter->setObjectName("pushButton_ajouter");
        pushButton_ajouter->setGeometry(QRect(60, 220, 75, 24));
        pushButton_ajouter->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid #f77f00;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        pushButton_annuler = new QPushButton(tab);
        pushButton_annuler->setObjectName("pushButton_annuler");
        pushButton_annuler->setGeometry(QRect(150, 220, 75, 24));
        pushButton_annuler->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid #f77f00;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        label_heure = new QLabel(tab);
        label_heure->setObjectName("label_heure");
        label_heure->setGeometry(QRect(20, 150, 101, 16));
        label_heure->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        label_dateC = new QLabel(tab);
        label_dateC->setObjectName("label_dateC");
        label_dateC->setGeometry(QRect(20, 130, 91, 16));
        label_dateC->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        le_dated_date = new QDateEdit(tab);
        le_dated_date->setObjectName("le_dated_date");
        le_dated_date->setGeometry(QRect(140, 150, 121, 21));
        le_dated_date->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"color: rgb(86, 1, 38);\n"
"border-style: solid;\n"
"border: 2px solid  #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        le_descrip = new QLineEdit(tab);
        le_descrip->setObjectName("le_descrip");
        le_descrip->setGeometry(QRect(140, 90, 121, 16));
        le_descrip->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid  #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"color: rgb(86, 1, 38);"));
        le_datef_date = new QDateEdit(tab);
        le_datef_date->setObjectName("le_datef_date");
        le_datef_date->setGeometry(QRect(140, 170, 121, 21));
        le_datef_date->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"color: rgb(86, 1, 38);\n"
"border-style: solid;\n"
"border: 2px solid  #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        label_heure_2 = new QLabel(tab);
        label_heure_2->setObjectName("label_heure_2");
        label_heure_2->setGeometry(QRect(20, 170, 101, 21));
        label_heure_2->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        le_type = new QComboBox(tab);
        le_type->addItem(QString());
        le_type->addItem(QString());
        le_type->setObjectName("le_type");
        le_type->setGeometry(QRect(140, 130, 121, 21));
        le_type->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"color: rgb(86, 1, 38);"));
        le_statut = new QComboBox(tab);
        le_statut->addItem(QString());
        le_statut->addItem(QString());
        le_statut->addItem(QString());
        le_statut->setObjectName("le_statut");
        le_statut->setGeometry(QRect(140, 110, 121, 21));
        le_statut->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"color: rgb(86, 1, 38);"));
        arduino->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        pushButton_annuler_2 = new QPushButton(tab_2);
        pushButton_annuler_2->setObjectName("pushButton_annuler_2");
        pushButton_annuler_2->setGeometry(QRect(150, 230, 75, 24));
        pushButton_annuler_2->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid #f77f00;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        pushButton_ok = new QPushButton(tab_2);
        pushButton_ok->setObjectName("pushButton_ok");
        pushButton_ok->setGeometry(QRect(170, 20, 75, 16));
        pushButton_ok->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"border:none;"));
        le_modif_id_ser = new QLineEdit(tab_2);
        le_modif_id_ser->setObjectName("le_modif_id_ser");
        le_modif_id_ser->setGeometry(QRect(110, 20, 51, 16));
        le_modif_id_ser->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(86, 1, 38);\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        pushButton_modifier = new QPushButton(tab_2);
        pushButton_modifier->setObjectName("pushButton_modifier");
        pushButton_modifier->setGeometry(QRect(50, 230, 75, 24));
        pushButton_modifier->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid #f77f00;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
""));
        label_id_2 = new QLabel(tab_2);
        label_id_2->setObjectName("label_id_2");
        label_id_2->setGeometry(QRect(10, 20, 91, 16));
        label_id_2->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        label_nom_2 = new QLabel(tab_2);
        label_nom_2->setObjectName("label_nom_2");
        label_nom_2->setGeometry(QRect(10, 50, 91, 16));
        label_nom_2->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        label_description_2 = new QLabel(tab_2);
        label_description_2->setObjectName("label_description_2");
        label_description_2->setGeometry(QRect(10, 70, 91, 16));
        label_description_2->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        label_type_2 = new QLabel(tab_2);
        label_type_2->setObjectName("label_type_2");
        label_type_2->setGeometry(QRect(10, 90, 91, 16));
        label_type_2->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        label_lieu_2 = new QLabel(tab_2);
        label_lieu_2->setObjectName("label_lieu_2");
        label_lieu_2->setGeometry(QRect(10, 110, 91, 16));
        label_lieu_2->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        label_date = new QLabel(tab_2);
        label_date->setObjectName("label_date");
        label_date->setGeometry(QRect(10, 160, 91, 16));
        label_date->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        label_time = new QLabel(tab_2);
        label_time->setObjectName("label_time");
        label_time->setGeometry(QRect(10, 190, 101, 16));
        label_time->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        le_modif_nom = new QLineEdit(tab_2);
        le_modif_nom->setObjectName("le_modif_nom");
        le_modif_nom->setGeometry(QRect(140, 50, 121, 16));
        le_modif_nom->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"color: rgb(86, 1, 38);"));
        le_modif_prix = new QLineEdit(tab_2);
        le_modif_prix->setObjectName("le_modif_prix");
        le_modif_prix->setGeometry(QRect(140, 70, 121, 16));
        le_modif_prix->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"color: rgb(86, 1, 38);"));
        le_modif_dated_date = new QDateEdit(tab_2);
        le_modif_dated_date->setObjectName("le_modif_dated_date");
        le_modif_dated_date->setGeometry(QRect(140, 160, 121, 16));
        le_modif_dated_date->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"color: rgb(86, 1, 38);\n"
"border-style: solid;\n"
"border: 2px solid  #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        le_modif_datef_date = new QDateEdit(tab_2);
        le_modif_datef_date->setObjectName("le_modif_datef_date");
        le_modif_datef_date->setGeometry(QRect(140, 190, 121, 16));
        le_modif_datef_date->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"color: rgb(86, 1, 38);\n"
"border-style: solid;\n"
"border: 2px solid  #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        le_modif_descrip = new QLineEdit(tab_2);
        le_modif_descrip->setObjectName("le_modif_descrip");
        le_modif_descrip->setGeometry(QRect(140, 90, 121, 16));
        le_modif_descrip->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid  #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"color: rgb(86, 1, 38);"));
        label_lieu_3 = new QLabel(tab_2);
        label_lieu_3->setObjectName("label_lieu_3");
        label_lieu_3->setGeometry(QRect(10, 130, 91, 16));
        label_lieu_3->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        le_modif_type = new QComboBox(tab_2);
        le_modif_type->addItem(QString());
        le_modif_type->addItem(QString());
        le_modif_type->setObjectName("le_modif_type");
        le_modif_type->setGeometry(QRect(140, 130, 121, 21));
        le_modif_type->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"color: rgb(86, 1, 38);"));
        le_modif_statut = new QComboBox(tab_2);
        le_modif_statut->addItem(QString());
        le_modif_statut->addItem(QString());
        le_modif_statut->addItem(QString());
        le_modif_statut->setObjectName("le_modif_statut");
        le_modif_statut->setGeometry(QRect(140, 110, 121, 21));
        le_modif_statut->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"color: rgb(86, 1, 38);"));
        arduino->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        pushButton_supprimer = new QPushButton(tab_3);
        pushButton_supprimer->setObjectName("pushButton_supprimer");
        pushButton_supprimer->setGeometry(QRect(100, 110, 81, 24));
        pushButton_supprimer->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid #f77f00;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        pushButton_annuler_3 = new QPushButton(tab_3);
        pushButton_annuler_3->setObjectName("pushButton_annuler_3");
        pushButton_annuler_3->setGeometry(QRect(100, 150, 81, 24));
        pushButton_annuler_3->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid #f77f00;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        label_id_3 = new QLabel(tab_3);
        label_id_3->setObjectName("label_id_3");
        label_id_3->setGeometry(QRect(20, 60, 91, 16));
        label_id_3->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        id_supp = new QLineEdit(tab_3);
        id_supp->setObjectName("id_supp");
        id_supp->setGeometry(QRect(140, 60, 51, 16));
        id_supp->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"color: rgb(86, 1, 38);"));
        arduino->addTab(tab_3, QString());
        tab_10 = new QWidget();
        tab_10->setObjectName("tab_10");
        event1 = new QLineEdit(tab_10);
        event1->setObjectName("event1");
        event1->setGeometry(QRect(60, 90, 141, 20));
        event1->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"color: rgb(86, 1, 38);"));
        label_nom_7 = new QLabel(tab_10);
        label_nom_7->setObjectName("label_nom_7");
        label_nom_7->setGeometry(QRect(90, 50, 91, 16));
        label_nom_7->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        rechercher = new QPushButton(tab_10);
        rechercher->setObjectName("rechercher");
        rechercher->setGeometry(QRect(90, 140, 81, 24));
        rechercher->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid #f77f00;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        arduino->addTab(tab_10, QString());
        pushButton_telecharger_pdf = new QPushButton(main_body_contents);
        pushButton_telecharger_pdf->setObjectName("pushButton_telecharger_pdf");
        pushButton_telecharger_pdf->setGeometry(QRect(450, 520, 131, 31));
        pushButton_telecharger_pdf->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid #eae2b7;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"background-color: #ffffff;\n"
"color: rgb(86, 1, 38);"));
        notificationLibel = new QLabel(main_body_contents);
        notificationLibel->setObjectName("notificationLibel");
        notificationLibel->setGeometry(QRect(490, 280, 20, 20));
        notificationLibel->setStyleSheet(QString::fromUtf8("background:transparent;"));
        pushButton_crud = new QPushButton(main_body_contents);
        pushButton_crud->setObjectName("pushButton_crud");
        pushButton_crud->setGeometry(QRect(10, 20, 121, 31));
        pushButton_crud->setStyleSheet(QString::fromUtf8("font: 900 italic 10pt \"Segoe UI\";"));
        label_11 = new QLabel(main_body_contents);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(860, 210, 51, 21));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        label_11->setFont(font);
        pushButton_noti = new QPushButton(main_body_contents);
        pushButton_noti->setObjectName("pushButton_noti");
        pushButton_noti->setGeometry(QRect(440, 400, 51, 41));
        pushButton_noti->setStyleSheet(QString::fromUtf8("border: none;\n"
"image: url(:/resources/notification.png);\n"
"background: transparent;"));
        label_12 = new QLabel(main_body_contents);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(430, 210, 111, 21));
        label_12->setFont(font);
        pushButton_annuler_search = new QPushButton(main_body_contents);
        pushButton_annuler_search->setObjectName("pushButton_annuler_search");
        pushButton_annuler_search->setGeometry(QRect(740, 210, 71, 21));
        pushButton_annuler_search->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid #eae2b7;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"background-color: #ffffff;\n"
"color: rgb(86, 1, 38);"));
        tab_Services = new QTableView(main_body_contents);
        tab_Services->setObjectName("tab_Services");
        tab_Services->setGeometry(QRect(420, 250, 651, 251));
        tab_Services->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    background-color:#A3A3A3;\n"
"}"));
        pb_rechercher = new QPushButton(main_body_contents);
        pb_rechercher->setObjectName("pb_rechercher");
        pb_rechercher->setGeometry(QRect(700, 210, 31, 31));
        pb_rechercher->setStyleSheet(QString::fromUtf8("background-color: rgb(113, 113, 113);"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("../../../../../../../Downloads/feather/search.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pb_rechercher->setIcon(icon6);
        pb_rechercher->setIconSize(QSize(24, 24));
        le_recherche = new QLineEdit(main_body_contents);
        le_recherche->setObjectName("le_recherche");
        le_recherche->setGeometry(QRect(550, 210, 171, 21));
        le_recherche->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(255, 255, 255);"));
        le_trier = new QComboBox(main_body_contents);
        le_trier->addItem(QString());
        le_trier->addItem(QString());
        le_trier->addItem(QString());
        le_trier->setObjectName("le_trier");
        le_trier->setGeometry(QRect(920, 210, 71, 31));
        le_trier->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"color: rgb(86, 1, 38);"));
        pb_tier = new QPushButton(main_body_contents);
        pb_tier->setObjectName("pb_tier");
        pb_tier->setGeometry(QRect(1000, 210, 31, 31));
        pb_tier->setStyleSheet(QString::fromUtf8("background-color: rgb(113, 113, 113);"));
        pb_tier->setIcon(icon6);
        pb_tier->setIconSize(QSize(24, 24));
        pushButton_fonctionnalites_2 = new QPushButton(main_body_contents);
        pushButton_fonctionnalites_2->setObjectName("pushButton_fonctionnalites_2");
        pushButton_fonctionnalites_2->setGeometry(QRect(140, 20, 162, 31));
        pushButton_fonctionnalites_2->setStyleSheet(QString::fromUtf8("font: 900 italic 10pt \"Segoe UI\";"));
        aff_statistique = new QPushButton(main_body_contents);
        aff_statistique->setObjectName("aff_statistique");
        aff_statistique->setGeometry(QRect(350, 80, 45, 29));
        aff_statistique->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 242, 219);"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("../../../../equipe slim/service/icons/maximize-2.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        aff_statistique->setIcon(icon7);
        verticalLayoutWidget_2 = new QWidget(main_body_contents);
        verticalLayoutWidget_2->setObjectName("verticalLayoutWidget_2");
        verticalLayoutWidget_2->setGeometry(QRect(480, 10, 491, 181));
        layout_statistique = new QVBoxLayout(verticalLayoutWidget_2);
        layout_statistique->setObjectName("layout_statistique");
        layout_statistique->setContentsMargins(0, 0, 0, 0);
        frame_12->raise();
        pushButton_telecharger_pdf->raise();
        notificationLibel->raise();
        pushButton_crud->raise();
        label_11->raise();
        pushButton_noti->raise();
        label_12->raise();
        pushButton_annuler_search->raise();
        tab_Services->raise();
        le_recherche->raise();
        pb_rechercher->raise();
        le_trier->raise();
        pb_tier->raise();
        pushButton_fonctionnalites_2->raise();
        aff_statistique->raise();
        verticalLayoutWidget_2->raise();

        verticalLayout->addWidget(main_body_contents);

        footer = new QFrame(main_body);
        footer->setObjectName("footer");
        footer->setFrameShape(QFrame::Shape::StyledPanel);
        footer->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_3 = new QHBoxLayout(footer);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        frame_4 = new QFrame(footer);
        frame_4->setObjectName("frame_4");
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_4);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, -1);
        label = new QLabel(frame_4);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 242, 219);\n"
"color: rgb(86, 1, 38);"));

        verticalLayout_4->addWidget(label);


        horizontalLayout_3->addWidget(frame_4);

        frame_5 = new QFrame(footer);
        frame_5->setObjectName("frame_5");
        frame_5->setFrameShape(QFrame::Shape::StyledPanel);
        frame_5->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_5);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_7 = new QPushButton(frame_5);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 242, 219);"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("../../../Atelier_Connexio/Atelier_Connexion/Atelier_Connexion/icons/box.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        pushButton_7->setIcon(icon8);

        verticalLayout_3->addWidget(pushButton_7);


        horizontalLayout_3->addWidget(frame_5);

        size_grip = new QFrame(footer);
        size_grip->setObjectName("size_grip");
        size_grip->setMinimumSize(QSize(10, 10));
        size_grip->setMaximumSize(QSize(10, 10));
        size_grip->setFrameShape(QFrame::Shape::StyledPanel);
        size_grip->setFrameShadow(QFrame::Shadow::Raised);

        horizontalLayout_3->addWidget(size_grip);


        verticalLayout->addWidget(footer, 0, Qt::AlignmentFlag::AlignBottom);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName("page_4");
        pushButton_crud_2 = new QPushButton(page_4);
        pushButton_crud_2->setObjectName("pushButton_crud_2");
        pushButton_crud_2->setGeometry(QRect(60, 40, 121, 31));
        pushButton_crud_2->setStyleSheet(QString::fromUtf8("font: 900 italic 10pt \"Segoe UI\";"));
        pushButton_fonctionnalites_3 = new QPushButton(page_4);
        pushButton_fonctionnalites_3->setObjectName("pushButton_fonctionnalites_3");
        pushButton_fonctionnalites_3->setGeometry(QRect(190, 40, 162, 31));
        pushButton_fonctionnalites_3->setStyleSheet(QString::fromUtf8("font: 900 italic 10pt \"Segoe UI\";"));
        listWidgetHistorique = new QListWidget(page_4);
        listWidgetHistorique->setObjectName("listWidgetHistorique");
        listWidgetHistorique->setGeometry(QRect(80, 140, 351, 391));
        pushButton_delete = new QPushButton(page_4);
        pushButton_delete->setObjectName("pushButton_delete");
        pushButton_delete->setGeometry(QRect(340, 550, 45, 29));
        pushButton_delete->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 242, 219);"));
        pushButton_delete->setIcon(icon7);
        pushButton_exp = new QPushButton(page_4);
        pushButton_exp->setObjectName("pushButton_exp");
        pushButton_exp->setGeometry(QRect(200, 550, 91, 31));
        pushButton_exp->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 242, 219);"));
        pushButton_exp->setIcon(icon7);
        pushButton_add = new QPushButton(page_4);
        pushButton_add->setObjectName("pushButton_add");
        pushButton_add->setGeometry(QRect(90, 550, 45, 29));
        pushButton_add->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 242, 219);"));
        pushButton_add->setIcon(icon7);
        verticalLayoutWidget = new QWidget(page_4);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(470, 200, 591, 221));
        verticalLayout_12 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_12->setObjectName("verticalLayout_12");
        verticalLayout_12->setContentsMargins(0, 0, 0, 0);
        actualiser = new QPushButton(page_4);
        actualiser->setObjectName("actualiser");
        actualiser->setGeometry(QRect(760, 460, 45, 29));
        actualiser->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 242, 219);\n"
""));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8("../../../../equipe slim/service/icons/x.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        actualiser->setIcon(icon9);
        stackedWidget->addWidget(page_4);
        slide_menu_container = new QFrame(centralwidget);
        slide_menu_container->setObjectName("slide_menu_container");
        slide_menu_container->setGeometry(QRect(10, 10, 200, 631));
        slide_menu_container->setMaximumSize(QSize(200, 16777215));
        slide_menu_container->setFrameShape(QFrame::Shape::StyledPanel);
        slide_menu_container->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_2 = new QVBoxLayout(slide_menu_container);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        slide_menu = new QFrame(slide_menu_container);
        slide_menu->setObjectName("slide_menu");
        slide_menu->setMinimumSize(QSize(198, 0));
        slide_menu->setFrameShape(QFrame::Shape::StyledPanel);
        slide_menu->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_5 = new QVBoxLayout(slide_menu);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        frame_7 = new QFrame(slide_menu);
        frame_7->setObjectName("frame_7");
        frame_7->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 242, 219);"));
        frame_7->setFrameShape(QFrame::Shape::StyledPanel);
        frame_7->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_13 = new QHBoxLayout(frame_7);
        verticalLayout_13->setObjectName("verticalLayout_13");
        label_2 = new QLabel(frame_7);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(86, 1, 38);\n"
"font: 700 italic 10pt \"Segoe UI\";\n"
"font: 900 italic 10pt \"Segoe UI\";\n"
"font: 900 italic 10pt \"Segoe UI\";"));

        verticalLayout_13->addWidget(label_2);

        label_3 = new QLabel(frame_7);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(64, 64));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../../../Atelier_Connexio/Atelier_Connexion/Atelier_Connexion/images/Capture_2025.png")));
        label_3->setScaledContents(true);

        verticalLayout_13->addWidget(label_3);


        verticalLayout_5->addWidget(frame_7, 0, Qt::AlignmentFlag::AlignTop);

        frame_8 = new QFrame(slide_menu);
        frame_8->setObjectName("frame_8");
        sizePolicy.setHeightForWidth(frame_8->sizePolicy().hasHeightForWidth());
        frame_8->setSizePolicy(sizePolicy);
        frame_8->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 242, 219);"));
        frame_8->setFrameShape(QFrame::Shape::StyledPanel);
        frame_8->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_7 = new QVBoxLayout(frame_8);
        verticalLayout_7->setObjectName("verticalLayout_7");
        toolBox = new QToolBox(frame_8);
        toolBox->setObjectName("toolBox");
        toolBox->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 242, 219);\n"
"color: rgb(86, 1, 38);\n"
"font: 900 italic 10pt \"Segoe UI\";"));
        page = new QWidget();
        page->setObjectName("page");
        page->setGeometry(QRect(0, 0, 208, 383));
        verticalLayout_8 = new QVBoxLayout(page);
        verticalLayout_8->setObjectName("verticalLayout_8");
        frame_10 = new QFrame(page);
        frame_10->setObjectName("frame_10");
        frame_10->setFrameShape(QFrame::Shape::StyledPanel);
        frame_10->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_9 = new QVBoxLayout(frame_10);
        verticalLayout_9->setObjectName("verticalLayout_9");
        gestionemployeebtn = new QPushButton(frame_10);
        gestionemployeebtn->setObjectName("gestionemployeebtn");
        gestionemployeebtn->setStyleSheet(QString::fromUtf8("font: 900 italic 10pt \"Segoe UI\";"));

        verticalLayout_9->addWidget(gestionemployeebtn);

        gestionlocatairesbtn = new QPushButton(frame_10);
        gestionlocatairesbtn->setObjectName("gestionlocatairesbtn");
        gestionlocatairesbtn->setStyleSheet(QString::fromUtf8("font: 900 italic 10pt \"Segoe UI\";"));

        verticalLayout_9->addWidget(gestionlocatairesbtn);

        gestionmaintenancebtn = new QPushButton(frame_10);
        gestionmaintenancebtn->setObjectName("gestionmaintenancebtn");
        gestionmaintenancebtn->setStyleSheet(QString::fromUtf8("font: 900 italic 10pt \"Segoe UI\";"));

        verticalLayout_9->addWidget(gestionmaintenancebtn);

        gestionlocauxbtn = new QPushButton(frame_10);
        gestionlocauxbtn->setObjectName("gestionlocauxbtn");
        gestionlocauxbtn->setStyleSheet(QString::fromUtf8("font: 900 italic 9pt \"Segoe UI\";"));

        verticalLayout_9->addWidget(gestionlocauxbtn);

        gestioneventbtn = new QPushButton(frame_10);
        gestioneventbtn->setObjectName("gestioneventbtn");
        gestioneventbtn->setStyleSheet(QString::fromUtf8("font: 900 italic 10pt \"Segoe UI\";"));

        verticalLayout_9->addWidget(gestioneventbtn);

        pushButton_16 = new QPushButton(frame_10);
        pushButton_16->setObjectName("pushButton_16");
        pushButton_16->setStyleSheet(QString::fromUtf8("font: 900 italic 10pt \"Segoe UI\";"));

        verticalLayout_9->addWidget(pushButton_16);


        verticalLayout_8->addWidget(frame_10);

        QIcon icon10;
        icon10.addFile(QString::fromUtf8("../../../../equipe slim/service/icons/chevron-down.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        toolBox->addItem(page, icon10, QString::fromUtf8("Menu 1"));
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        page_2->setGeometry(QRect(0, 0, 172, 400));
        verticalLayout_10 = new QVBoxLayout(page_2);
        verticalLayout_10->setObjectName("verticalLayout_10");
        frame_11 = new QFrame(page_2);
        frame_11->setObjectName("frame_11");
        frame_11->setFrameShape(QFrame::Shape::StyledPanel);
        frame_11->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_11 = new QVBoxLayout(frame_11);
        verticalLayout_11->setSpacing(0);
        verticalLayout_11->setObjectName("verticalLayout_11");
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        pushButton_14 = new QPushButton(frame_11);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setStyleSheet(QString::fromUtf8("    QTabWidget::pane { \n"
"        border: 0px solid #eae2b7; \n"
"    }\n"
"    QTabBar::tab { \n"
"        background:#eae2b7; \n"
"        color: black; \n"
"        padding: 8px; \n"
"		border-radius: 0px; \n"
"    }\n"
"    QTabBar::tab:selected { \n"
"        background:#a48f66  ; \n"
"        color:white; \n"
"        font-weight: bold; \n"
"    }\n"
"    QTabBar::tab:hover {\n"
"        background: #c0b49a ; \n"
"    }\n"
";\n"
"background-color: #f5f2db;\n"
"font: 900 italic 10pt \"Segoe UI\";"));

        verticalLayout_11->addWidget(pushButton_14);

        pushButton_15 = new QPushButton(frame_11);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setStyleSheet(QString::fromUtf8("    QTabWidget::pane { \n"
"        border: 0px solid #eae2b7; \n"
"    }\n"
"    QTabBar::tab { \n"
"        background:#eae2b7; \n"
"        color: black; \n"
"        padding: 8px; \n"
"		border-radius: 0px; \n"
"    }\n"
"    QTabBar::tab:selected { \n"
"        background:#a48f66  ; \n"
"        color:white; \n"
"        font-weight: bold; \n"
"    }\n"
"    QTabBar::tab:hover {\n"
"        background: #c0b49a ; \n"
"    }\n"
";\n"
"background-color: #f5f2db;\n"
"font: 900 italic 10pt \"Segoe UI\";"));

        verticalLayout_11->addWidget(pushButton_15);


        verticalLayout_10->addWidget(frame_11, 0, Qt::AlignmentFlag::AlignTop);

        label_4 = new QLabel(page_2);
        label_4->setObjectName("label_4");
        label_4->setWordWrap(true);

        verticalLayout_10->addWidget(label_4, 0, Qt::AlignmentFlag::AlignTop);

        toolBox->addItem(page_2, icon10, QString::fromUtf8("Menu 2"));

        verticalLayout_7->addWidget(toolBox);


        verticalLayout_5->addWidget(frame_8);

        frame_9 = new QFrame(slide_menu);
        frame_9->setObjectName("frame_9");
        frame_9->setFrameShape(QFrame::Shape::StyledPanel);
        frame_9->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_6 = new QVBoxLayout(frame_9);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        pushButton_9 = new QPushButton(frame_9);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setStyleSheet(QString::fromUtf8("    QTabWidget::pane { \n"
"	color: rgb(86, 1, 38);\n"
"	color: rgb(86, 1, 38);\n"
"        border: 0px solid #eae2b7; \n"
"    }\n"
"    QTabBar::tab { \n"
"        background:#eae2b7; \n"
"        color: black; \n"
"        padding: 8px; \n"
"		border-radius: 0px; \n"
"    }\n"
"    QTabBar::tab:selected { \n"
"        background:#a48f66  ; \n"
"        color:white; \n"
"        font-weight: bold; \n"
"    }\n"
"    QTabBar::tab:hover {\n"
"        background: #c0b49a ; \n"
"color: rgb(86, 1, 38);\n"
"    }\n"
";\n"
"background-color: #f5f2db;\n"
"color: rgb(86, 1, 38);\n"
"font: 900 italic 10pt \"Segoe UI\";"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8("../../../Atelier_Connexio/Atelier_Connexion/Atelier_Connexion/icons/external-link.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        pushButton_9->setIcon(icon11);
        pushButton_9->setIconSize(QSize(32, 32));

        verticalLayout_6->addWidget(pushButton_9, 0, Qt::AlignmentFlag::AlignBottom);


        verticalLayout_5->addWidget(frame_9, 0, Qt::AlignmentFlag::AlignBottom);


        verticalLayout_2->addWidget(slide_menu);

        MainService->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainService);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1320, 25));
        MainService->setMenuBar(menubar);
        statusbar = new QStatusBar(MainService);
        statusbar->setObjectName("statusbar");
        MainService->setStatusBar(statusbar);

        retranslateUi(MainService);

        stackedWidget->setCurrentIndex(0);
        arduino->setCurrentIndex(3);
        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainService);
    } // setupUi

    void retranslateUi(QMainWindow *MainService)
    {
        MainService->setWindowTitle(QCoreApplication::translate("MainService", "MainWindow", nullptr));
        pushButton_8->setText(QString());
        pushButton_3->setText(QString());
        pushButton_6->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        pushButton_2->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainService", "search", nullptr));
        label_nomApp->setText(QCoreApplication::translate("MainService", "Gestion des Services", nullptr));
#if QT_CONFIG(tooltip)
        arduino->setToolTip(QCoreApplication::translate("MainService", "<html><head/><body><p>arduino </p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        label_id->setText(QCoreApplication::translate("MainService", "  ID_Service", nullptr));
        label_nom->setText(QCoreApplication::translate("MainService", "  Nom", nullptr));
        label_description->setText(QCoreApplication::translate("MainService", "Prix", nullptr));
        label_type->setText(QCoreApplication::translate("MainService", "Description", nullptr));
        label_lieu->setText(QCoreApplication::translate("MainService", "Statut", nullptr));
        le_id_ser->setText(QString());
        le_prix->setText(QString());
        le_nom->setText(QString());
        pushButton_ajouter->setText(QCoreApplication::translate("MainService", "Ajouter", nullptr));
        pushButton_annuler->setText(QCoreApplication::translate("MainService", "Annuler", nullptr));
        label_heure->setText(QCoreApplication::translate("MainService", "DateDebut", nullptr));
        label_dateC->setText(QCoreApplication::translate("MainService", "Type", nullptr));
        le_descrip->setText(QString());
        label_heure_2->setText(QCoreApplication::translate("MainService", "DateFin", nullptr));
        le_type->setItemText(0, QCoreApplication::translate("MainService", "externe", nullptr));
        le_type->setItemText(1, QCoreApplication::translate("MainService", "interne", nullptr));

        le_statut->setItemText(0, QCoreApplication::translate("MainService", "pas realiser", nullptr));
        le_statut->setItemText(1, QCoreApplication::translate("MainService", "en cours", nullptr));
        le_statut->setItemText(2, QCoreApplication::translate("MainService", "realis\303\251", nullptr));

        arduino->setTabText(arduino->indexOf(tab), QCoreApplication::translate("MainService", "Ajouter", nullptr));
        pushButton_annuler_2->setText(QCoreApplication::translate("MainService", "Annuler", nullptr));
        pushButton_ok->setText(QCoreApplication::translate("MainService", "OK", nullptr));
        le_modif_id_ser->setText(QString());
        pushButton_modifier->setText(QCoreApplication::translate("MainService", "Modifier", nullptr));
        label_id_2->setText(QCoreApplication::translate("MainService", "  ID_Service", nullptr));
        label_nom_2->setText(QCoreApplication::translate("MainService", "  Nom", nullptr));
        label_description_2->setText(QCoreApplication::translate("MainService", "Prix", nullptr));
        label_type_2->setText(QCoreApplication::translate("MainService", "Description", nullptr));
        label_lieu_2->setText(QCoreApplication::translate("MainService", "Statut", nullptr));
        label_date->setText(QCoreApplication::translate("MainService", "DateDebut", nullptr));
        label_time->setText(QCoreApplication::translate("MainService", "DateFin", nullptr));
        le_modif_nom->setText(QString());
        le_modif_prix->setText(QString());
        le_modif_descrip->setText(QString());
        label_lieu_3->setText(QCoreApplication::translate("MainService", "Type", nullptr));
        le_modif_type->setItemText(0, QCoreApplication::translate("MainService", "externe", nullptr));
        le_modif_type->setItemText(1, QCoreApplication::translate("MainService", "interne", nullptr));

        le_modif_statut->setItemText(0, QCoreApplication::translate("MainService", "pas realiser", nullptr));
        le_modif_statut->setItemText(1, QCoreApplication::translate("MainService", "en cours", nullptr));
        le_modif_statut->setItemText(2, QCoreApplication::translate("MainService", "realis\303\251", nullptr));

        arduino->setTabText(arduino->indexOf(tab_2), QCoreApplication::translate("MainService", "Mise a Jour", nullptr));
        pushButton_supprimer->setText(QCoreApplication::translate("MainService", "supprimer", nullptr));
        pushButton_annuler_3->setText(QCoreApplication::translate("MainService", "Annuler", nullptr));
        label_id_3->setText(QCoreApplication::translate("MainService", "  ID", nullptr));
        id_supp->setText(QString());
        arduino->setTabText(arduino->indexOf(tab_3), QCoreApplication::translate("MainService", "Supprimer", nullptr));
        event1->setText(QString());
        label_nom_7->setText(QCoreApplication::translate("MainService", "Evenement", nullptr));
        rechercher->setText(QCoreApplication::translate("MainService", "rechercher", nullptr));
        arduino->setTabText(arduino->indexOf(tab_10), QCoreApplication::translate("MainService", "Page", nullptr));
        pushButton_telecharger_pdf->setText(QCoreApplication::translate("MainService", "Exportation PDF", nullptr));
        notificationLibel->setText(QString());
        pushButton_crud->setText(QCoreApplication::translate("MainService", "Crud", nullptr));
        label_11->setText(QCoreApplication::translate("MainService", "Trier :", nullptr));
        pushButton_noti->setText(QString());
        label_12->setText(QCoreApplication::translate("MainService", "Rechercher :", nullptr));
        pushButton_annuler_search->setText(QCoreApplication::translate("MainService", "Annuler ", nullptr));
        pb_rechercher->setText(QString());
        le_recherche->setPlaceholderText(QString());
        le_trier->setItemText(0, QCoreApplication::translate("MainService", "par", nullptr));
        le_trier->setItemText(1, QCoreApplication::translate("MainService", "prix", nullptr));
        le_trier->setItemText(2, QCoreApplication::translate("MainService", "type", nullptr));

        pb_tier->setText(QCoreApplication::translate("MainService", "ok", nullptr));
        pushButton_fonctionnalites_2->setText(QCoreApplication::translate("MainService", "Fonctionnalit\303\251s", nullptr));
        aff_statistique->setText(QString());
        label->setText(QCoreApplication::translate("MainService", "Modern UI v 7.7.7", nullptr));
        pushButton_7->setText(QString());
        pushButton_crud_2->setText(QCoreApplication::translate("MainService", "Crud", nullptr));
        pushButton_fonctionnalites_3->setText(QCoreApplication::translate("MainService", "Fonctionnalit\303\251s", nullptr));
        pushButton_delete->setText(QCoreApplication::translate("MainService", "supprimer", nullptr));
        pushButton_exp->setText(QCoreApplication::translate("MainService", "exp", nullptr));
        pushButton_add->setText(QCoreApplication::translate("MainService", "Ajouter", nullptr));
        actualiser->setText(QString());
        label_2->setText(QCoreApplication::translate("MainService", "LUXBRAND", nullptr));
        label_3->setText(QString());
        gestionemployeebtn->setText(QCoreApplication::translate("MainService", "Employes", nullptr));
        gestionlocatairesbtn->setText(QCoreApplication::translate("MainService", "Locataires", nullptr));
        gestionmaintenancebtn->setText(QCoreApplication::translate("MainService", "maintenance", nullptr));
        gestionlocauxbtn->setText(QCoreApplication::translate("MainService", "Locaux commerciaux", nullptr));
        gestioneventbtn->setText(QCoreApplication::translate("MainService", "Evenements", nullptr));
        pushButton_16->setText(QCoreApplication::translate("MainService", "Services", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("MainService", "Menu 1", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainService", "besoin d'aide ", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainService", "Log out", nullptr));
        label_4->setText(QCoreApplication::translate("MainService", "text a ajouter plus tard ", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("MainService", "Menu 2", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainService", "EXIT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainService: public Ui_MainService {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSERVICE_H
