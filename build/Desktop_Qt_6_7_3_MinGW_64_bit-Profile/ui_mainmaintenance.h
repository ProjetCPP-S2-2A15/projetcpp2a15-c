/********************************************************************************
** Form generated from reading UI file 'mainmaintenance.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINMAINTENANCE_H
#define UI_MAINMAINTENANCE_H

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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainMaintenance
{
public:
    QWidget *centralwidget;
    QFrame *slide_menu_container;
    QVBoxLayout *verticalLayout_2;
    QFrame *slide_menu;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame_7;
    QHBoxLayout *horizontalLayout_7;
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
    QPushButton *pushButton_13;
    QPushButton *gestionlocauxbtn;
    QPushButton *gestioeventbtn;
    QPushButton *pushButton_12;
    QPushButton *gestionservicebtn;
    QSlider *horizontalSlider;
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
    QFrame *main_body;
    QVBoxLayout *verticalLayout;
    QFrame *header_frame;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton_8;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *lineEdit;
    QPushButton *pushButton_search;
    QPushButton *pushButton_supprimer;
    QPushButton *pushButton_stat;
    QPushButton *pushButton_tri;
    QPushButton *pushButton_sms;
    QPushButton *pushButton_email;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_4;
    QFrame *main_body_contents;
    QFrame *frame_12;
    QLabel *label_nomApp;
    QPushButton *pushButton_noti;
    QPushButton *pushButton_telecharger;
    QLabel *notificationLibel;
    QLabel *label_5;
    QPushButton *pushButton_modifier;
    QLineEdit *lineEdit_categorie;
    QLabel *label_heure_4;
    QLineEdit *lineEdit_idservice;
    QLineEdit *lineEdit_idmaintenance;
    QLabel *label_type;
    QLineEdit *lineEdit_emailtech;
    QDateEdit *dateEdit_datem;
    QLabel *label_id;
    QLabel *label_heure_3;
    QLabel *label_description;
    QPushButton *pushButton_ajouter;
    QComboBox *comboBox;
    QLabel *label_nom;
    QLineEdit *lineEdit_numtelephone;
    QLineEdit *lineEdit_type;
    QLineEdit *lineEdit_id_tech;
    QLabel *label_lieu;
    QLabel *label_dateC;
    QLabel *label_heure_2;
    QLabel *label_heure;
    QLineEdit *lineEdit_description;
    QTableView *tableView;
    QFrame *footer;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_7;
    QFrame *size_grip;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainMaintenance)
    {
        if (MainMaintenance->objectName().isEmpty())
            MainMaintenance->setObjectName("MainMaintenance");
        MainMaintenance->resize(978, 656);
        centralwidget = new QWidget(MainMaintenance);
        centralwidget->setObjectName("centralwidget");
        slide_menu_container = new QFrame(centralwidget);
        slide_menu_container->setObjectName("slide_menu_container");
        slide_menu_container->setGeometry(QRect(3, 10, 200, 566));
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
        horizontalLayout_7 = new QHBoxLayout(frame_7);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label_2 = new QLabel(frame_7);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(86, 1, 38);\n"
"font: italic 9pt \"Segoe UI\";"));

        horizontalLayout_7->addWidget(label_2);

        label_3 = new QLabel(frame_7);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(64, 64));
        label_3->setPixmap(QPixmap(QString::fromUtf8("../../../../equipe slim/maintenance/Capture_d_\303\251cran_2025-02-13_135510-removebg-preview (1).png")));
        label_3->setScaledContents(true);

        horizontalLayout_7->addWidget(label_3);


        verticalLayout_5->addWidget(frame_7, 0, Qt::AlignmentFlag::AlignTop);

        frame_8 = new QFrame(slide_menu);
        frame_8->setObjectName("frame_8");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
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
"color: rgb(86, 1, 38);"));
        page = new QWidget();
        page->setObjectName("page");
        page->setGeometry(QRect(0, 0, 191, 376));
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

        verticalLayout_9->addWidget(gestionemployeebtn);

        pushButton_13 = new QPushButton(frame_10);
        pushButton_13->setObjectName("pushButton_13");

        verticalLayout_9->addWidget(pushButton_13);

        gestionlocauxbtn = new QPushButton(frame_10);
        gestionlocauxbtn->setObjectName("gestionlocauxbtn");

        verticalLayout_9->addWidget(gestionlocauxbtn);

        gestioeventbtn = new QPushButton(frame_10);
        gestioeventbtn->setObjectName("gestioeventbtn");

        verticalLayout_9->addWidget(gestioeventbtn);

        pushButton_12 = new QPushButton(frame_10);
        pushButton_12->setObjectName("pushButton_12");

        verticalLayout_9->addWidget(pushButton_12);

        gestionservicebtn = new QPushButton(frame_10);
        gestionservicebtn->setObjectName("gestionservicebtn");

        verticalLayout_9->addWidget(gestionservicebtn);


        verticalLayout_8->addWidget(frame_10, 0, Qt::AlignmentFlag::AlignTop);

        horizontalSlider = new QSlider(page);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);

        verticalLayout_8->addWidget(horizontalSlider);

        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../equipe slim/maintenance/icons/chevron-down.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        toolBox->addItem(page, icon, QString::fromUtf8("Menu 1"));
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        page_2->setGeometry(QRect(0, 0, 172, 393));
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
"background-color: #f5f2db;"));

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
"background-color: #f5f2db;"));

        verticalLayout_11->addWidget(pushButton_15);


        verticalLayout_10->addWidget(frame_11, 0, Qt::AlignmentFlag::AlignTop);

        label_4 = new QLabel(page_2);
        label_4->setObjectName("label_4");
        label_4->setWordWrap(true);

        verticalLayout_10->addWidget(label_4, 0, Qt::AlignmentFlag::AlignTop);

        toolBox->addItem(page_2, icon, QString::fromUtf8("Menu 2"));

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
"color: rgb(86, 1, 38);"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../../../equipe slim/maintenance/icons/external-link.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        pushButton_9->setIcon(icon1);
        pushButton_9->setIconSize(QSize(32, 32));

        verticalLayout_6->addWidget(pushButton_9, 0, Qt::AlignmentFlag::AlignBottom);


        verticalLayout_5->addWidget(frame_9, 0, Qt::AlignmentFlag::AlignBottom);


        verticalLayout_2->addWidget(slide_menu);

        main_body = new QFrame(centralwidget);
        main_body->setObjectName("main_body");
        main_body->setGeometry(QRect(210, 10, 758, 566));
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
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../../../../equipe slim/maintenance/icons/align-left.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        pushButton_8->setIcon(icon2);
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
        lineEdit = new QLineEdit(frame_2);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 242, 219);"));

        horizontalLayout_5->addWidget(lineEdit);

        pushButton_search = new QPushButton(frame_2);
        pushButton_search->setObjectName("pushButton_search");
        pushButton_search->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 242, 219);"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8("../../../../equipe slim/maintenance/icons/search.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        pushButton_search->setIcon(icon3);

        horizontalLayout_5->addWidget(pushButton_search);

        pushButton_supprimer = new QPushButton(frame_2);
        pushButton_supprimer->setObjectName("pushButton_supprimer");
        pushButton_supprimer->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 242, 219);"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8("../../../../equipe slim/maintenance/icons/bell.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        pushButton_supprimer->setIcon(icon4);

        horizontalLayout_5->addWidget(pushButton_supprimer);

        pushButton_stat = new QPushButton(frame_2);
        pushButton_stat->setObjectName("pushButton_stat");
        pushButton_stat->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 242, 219);"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8("../../../../equipe slim/maintenance/icons/user.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        pushButton_stat->setIcon(icon5);

        horizontalLayout_5->addWidget(pushButton_stat);

        pushButton_tri = new QPushButton(frame_2);
        pushButton_tri->setObjectName("pushButton_tri");
        pushButton_tri->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 242, 219);"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8("../../../../equipe slim/maintenance/icons/maximize-2.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        pushButton_tri->setIcon(icon6);

        horizontalLayout_5->addWidget(pushButton_tri);

        pushButton_sms = new QPushButton(frame_2);
        pushButton_sms->setObjectName("pushButton_sms");
        pushButton_sms->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 242, 219);"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8("../../../../equipe slim/maintenance/icons/arrow-down-left.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        pushButton_sms->setIcon(icon7);

        horizontalLayout_5->addWidget(pushButton_sms);

        pushButton_email = new QPushButton(frame_2);
        pushButton_email->setObjectName("pushButton_email");
        pushButton_email->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 242, 219);\n"
""));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8("../../../../equipe slim/maintenance/icons/x.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        pushButton_email->setIcon(icon8);

        horizontalLayout_5->addWidget(pushButton_email);


        horizontalLayout_2->addWidget(frame_2);

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
        sizePolicy.setHeightForWidth(main_body_contents->sizePolicy().hasHeightForWidth());
        main_body_contents->setSizePolicy(sizePolicy);
        main_body_contents->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 242, 219);"));
        main_body_contents->setFrameShape(QFrame::Shape::StyledPanel);
        main_body_contents->setFrameShadow(QFrame::Shadow::Raised);
        frame_12 = new QFrame(main_body_contents);
        frame_12->setObjectName("frame_12");
        frame_12->setGeometry(QRect(450, 30, 311, 451));
        frame_12->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"background-color: rgb(86, 1, 38);\n"
"color: rgb(86, 1, 38);\n"
"border-radius: 40px;"));
        frame_12->setFrameShape(QFrame::Shape::StyledPanel);
        frame_12->setFrameShadow(QFrame::Shadow::Raised);
        label_nomApp = new QLabel(frame_12);
        label_nomApp->setObjectName("label_nomApp");
        label_nomApp->setGeometry(QRect(50, 30, 221, 31));
        label_nomApp->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"background-color: rgb(238, 228, 204);\n"
"border-radius: 8px;\n"
"\n"
"font: italic 12pt \"Pacifico\"\n"
"\n"
"\n"
""));
        pushButton_noti = new QPushButton(frame_12);
        pushButton_noti->setObjectName("pushButton_noti");
        pushButton_noti->setGeometry(QRect(240, 20, 51, 41));
        pushButton_noti->setStyleSheet(QString::fromUtf8("border: none;\n"
"image: url(:/resources/notification.png);\n"
"background: transparent;"));
        pushButton_telecharger = new QPushButton(frame_12);
        pushButton_telecharger->setObjectName("pushButton_telecharger");
        pushButton_telecharger->setGeometry(QRect(60, 410, 191, 21));
        pushButton_telecharger->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid #eae2b7;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"background-color: #ffffff;\n"
"color: rgb(86, 1, 38);"));
        notificationLibel = new QLabel(frame_12);
        notificationLibel->setObjectName("notificationLibel");
        notificationLibel->setGeometry(QRect(266, 50, 20, 20));
        notificationLibel->setStyleSheet(QString::fromUtf8("background:transparent;"));
        label_5 = new QLabel(frame_12);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 80, 271, 321));
        label_5->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 242, 219);"));
        pushButton_modifier = new QPushButton(frame_12);
        pushButton_modifier->setObjectName("pushButton_modifier");
        pushButton_modifier->setGeometry(QRect(170, 330, 75, 24));
        pushButton_modifier->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid #f77f00;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        lineEdit_categorie = new QLineEdit(frame_12);
        lineEdit_categorie->setObjectName("lineEdit_categorie");
        lineEdit_categorie->setGeometry(QRect(160, 170, 121, 16));
        lineEdit_categorie->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid  #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"color: rgb(86, 1, 38);\n"
"background: transparent;"));
        label_heure_4 = new QLabel(frame_12);
        label_heure_4->setObjectName("label_heure_4");
        label_heure_4->setGeometry(QRect(40, 300, 101, 16));
        label_heure_4->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        lineEdit_idservice = new QLineEdit(frame_12);
        lineEdit_idservice->setObjectName("lineEdit_idservice");
        lineEdit_idservice->setGeometry(QRect(160, 300, 121, 16));
        lineEdit_idservice->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid  #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"color: rgb(86, 1, 38);\n"
"background: transparent;"));
        lineEdit_idmaintenance = new QLineEdit(frame_12);
        lineEdit_idmaintenance->setObjectName("lineEdit_idmaintenance");
        lineEdit_idmaintenance->setGeometry(QRect(160, 110, 121, 16));
        lineEdit_idmaintenance->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"color: rgb(86, 1, 38);\n"
"background: transparent;"));
        label_type = new QLabel(frame_12);
        label_type->setObjectName("label_type");
        label_type->setGeometry(QRect(40, 170, 91, 16));
        label_type->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        lineEdit_emailtech = new QLineEdit(frame_12);
        lineEdit_emailtech->setObjectName("lineEdit_emailtech");
        lineEdit_emailtech->setGeometry(QRect(160, 250, 121, 16));
        lineEdit_emailtech->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid  #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"color: rgb(86, 1, 38);\n"
"background: transparent;"));
        dateEdit_datem = new QDateEdit(frame_12);
        dateEdit_datem->setObjectName("dateEdit_datem");
        dateEdit_datem->setGeometry(QRect(160, 210, 121, 16));
        dateEdit_datem->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"color: rgb(86, 1, 38);\n"
"border-style: solid;\n"
"border: 2px solid  #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"background: transparent;"));
        label_id = new QLabel(frame_12);
        label_id->setObjectName("label_id");
        label_id->setGeometry(QRect(40, 110, 91, 16));
        label_id->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        label_heure_3 = new QLabel(frame_12);
        label_heure_3->setObjectName("label_heure_3");
        label_heure_3->setGeometry(QRect(40, 270, 101, 16));
        label_heure_3->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        label_description = new QLabel(frame_12);
        label_description->setObjectName("label_description");
        label_description->setGeometry(QRect(40, 146, 91, 20));
        label_description->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        pushButton_ajouter = new QPushButton(frame_12);
        pushButton_ajouter->setObjectName("pushButton_ajouter");
        pushButton_ajouter->setGeometry(QRect(60, 330, 75, 24));
        pushButton_ajouter->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid #f77f00;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        comboBox = new QComboBox(frame_12);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(160, 190, 121, 16));
        comboBox->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"color: rgb(86, 1, 38);\n"
"border-style: solid;\n"
"border: 2px solid  #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"background: transparent;"));
        label_nom = new QLabel(frame_12);
        label_nom->setObjectName("label_nom");
        label_nom->setGeometry(QRect(40, 130, 91, 16));
        label_nom->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        lineEdit_numtelephone = new QLineEdit(frame_12);
        lineEdit_numtelephone->setObjectName("lineEdit_numtelephone");
        lineEdit_numtelephone->setGeometry(QRect(160, 270, 121, 16));
        lineEdit_numtelephone->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid  #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"color: rgb(86, 1, 38);\n"
"background: transparent;"));
        lineEdit_type = new QLineEdit(frame_12);
        lineEdit_type->setObjectName("lineEdit_type");
        lineEdit_type->setGeometry(QRect(160, 150, 121, 16));
        lineEdit_type->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid  #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"color: rgb(86, 1, 38);\n"
"background: transparent;"));
        lineEdit_id_tech = new QLineEdit(frame_12);
        lineEdit_id_tech->setObjectName("lineEdit_id_tech");
        lineEdit_id_tech->setGeometry(QRect(160, 230, 121, 16));
        lineEdit_id_tech->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid  #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"color: rgb(86, 1, 38);\n"
"background: transparent;"));
        label_lieu = new QLabel(frame_12);
        label_lieu->setObjectName("label_lieu");
        label_lieu->setGeometry(QRect(40, 190, 91, 16));
        label_lieu->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        label_dateC = new QLabel(frame_12);
        label_dateC->setObjectName("label_dateC");
        label_dateC->setGeometry(QRect(40, 210, 91, 16));
        label_dateC->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        label_heure_2 = new QLabel(frame_12);
        label_heure_2->setObjectName("label_heure_2");
        label_heure_2->setGeometry(QRect(40, 250, 101, 16));
        label_heure_2->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        label_heure = new QLabel(frame_12);
        label_heure->setObjectName("label_heure");
        label_heure->setGeometry(QRect(40, 230, 101, 16));
        label_heure->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        lineEdit_description = new QLineEdit(frame_12);
        lineEdit_description->setObjectName("lineEdit_description");
        lineEdit_description->setGeometry(QRect(160, 130, 121, 16));
        lineEdit_description->setStyleSheet(QString::fromUtf8("color: rgb(86, 1, 38);\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid  #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"background: transparent;"));
        tableView = new QTableView(main_body_contents);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(30, 100, 411, 331));

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

        verticalLayout_4->addWidget(label, 0, Qt::AlignmentFlag::AlignBottom);


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
        QIcon icon9;
        icon9.addFile(QString::fromUtf8("../../../../equipe slim/maintenance/icons/box.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        pushButton_7->setIcon(icon9);

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

        MainMaintenance->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainMaintenance);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 978, 26));
        MainMaintenance->setMenuBar(menubar);
        statusbar = new QStatusBar(MainMaintenance);
        statusbar->setObjectName("statusbar");
        MainMaintenance->setStatusBar(statusbar);

        retranslateUi(MainMaintenance);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainMaintenance);
    } // setupUi

    void retranslateUi(QMainWindow *MainMaintenance)
    {
        MainMaintenance->setWindowTitle(QCoreApplication::translate("MainMaintenance", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainMaintenance", "LUXBRAND", nullptr));
        label_3->setText(QString());
        gestionemployeebtn->setText(QCoreApplication::translate("MainMaintenance", "Employes", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainMaintenance", "Locataires", nullptr));
        gestionlocauxbtn->setText(QCoreApplication::translate("MainMaintenance", "locaux commerciaux", nullptr));
        gestioeventbtn->setText(QCoreApplication::translate("MainMaintenance", "Evenements", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainMaintenance", "maintenance", nullptr));
        gestionservicebtn->setText(QCoreApplication::translate("MainMaintenance", "Services", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("MainMaintenance", "Menu 1", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainMaintenance", "besoin d'aide ", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainMaintenance", "Log out", nullptr));
        label_4->setText(QCoreApplication::translate("MainMaintenance", "text a ajouter plus tard ", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("MainMaintenance", "Menu 2", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainMaintenance", "EXIT", nullptr));
        pushButton_8->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainMaintenance", "search", nullptr));
        pushButton_search->setText(QCoreApplication::translate("MainMaintenance", "search", nullptr));
        pushButton_supprimer->setText(QCoreApplication::translate("MainMaintenance", "delete", nullptr));
        pushButton_stat->setText(QCoreApplication::translate("MainMaintenance", "stat", nullptr));
        pushButton_tri->setText(QCoreApplication::translate("MainMaintenance", "tri", nullptr));
        pushButton_sms->setText(QCoreApplication::translate("MainMaintenance", "sms", nullptr));
        pushButton_email->setText(QCoreApplication::translate("MainMaintenance", "email", nullptr));
        label_nomApp->setText(QCoreApplication::translate("MainMaintenance", "Gestion de maintenance ", nullptr));
        pushButton_noti->setText(QString());
        pushButton_telecharger->setText(QCoreApplication::translate("MainMaintenance", "T\303\251l\303\251charger le Contrat", nullptr));
        notificationLibel->setText(QString());
        label_5->setText(QString());
        pushButton_modifier->setText(QCoreApplication::translate("MainMaintenance", "modifier", nullptr));
        lineEdit_categorie->setText(QString());
        label_heure_4->setText(QCoreApplication::translate("MainMaintenance", "id service ", nullptr));
        lineEdit_idservice->setText(QString());
        lineEdit_idmaintenance->setText(QString());
        label_type->setText(QCoreApplication::translate("MainMaintenance", "categorie", nullptr));
        lineEdit_emailtech->setText(QString());
        label_id->setText(QCoreApplication::translate("MainMaintenance", "  ID", nullptr));
        label_heure_3->setText(QCoreApplication::translate("MainMaintenance", "numero telephone", nullptr));
        label_description->setText(QCoreApplication::translate("MainMaintenance", "type", nullptr));
        pushButton_ajouter->setText(QCoreApplication::translate("MainMaintenance", "Ajouter", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainMaintenance", "en cours ", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainMaintenance", "en attente ", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainMaintenance", "termin\303\251", nullptr));

        label_nom->setText(QCoreApplication::translate("MainMaintenance", "  description", nullptr));
        lineEdit_numtelephone->setText(QString());
        lineEdit_type->setText(QString());
        lineEdit_id_tech->setText(QString());
        label_lieu->setText(QCoreApplication::translate("MainMaintenance", "statut", nullptr));
        label_dateC->setText(QCoreApplication::translate("MainMaintenance", "date ", nullptr));
        label_heure_2->setText(QCoreApplication::translate("MainMaintenance", "email technicien ", nullptr));
        label_heure->setText(QCoreApplication::translate("MainMaintenance", "id technicien", nullptr));
        lineEdit_description->setText(QString());
        label->setText(QCoreApplication::translate("MainMaintenance", "Modern UI v 7.7.7", nullptr));
        pushButton_7->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainMaintenance: public Ui_MainMaintenance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINMAINTENANCE_H
