/********************************************************************************
** Form generated from reading UI file 'mainevent.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINEVENT_H
#define UI_MAINEVENT_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
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
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainEvent
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
    QPushButton *pushButton_10;
    QPushButton *pushButton_13;
    QPushButton *pushButton_11;
    QPushButton *pushButton_17;
    QPushButton *pushButton_12;
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
    QPushButton *searchButton;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_4;
    QFrame *main_body_contents;
    QLabel *label_6;
    QFrame *frame_12;
    QLabel *label_nomApp;
    QPushButton *pushButton_noti;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_id;
    QLabel *label_nom;
    QLabel *label_description;
    QLabel *label_type;
    QLabel *label_lieu;
    QLineEdit *lineEdit_id;
    QLineEdit *lineEdit_telephone;
    QLineEdit *lineEdit_description;
    QLineEdit *lineEdit_nom;
    QPushButton *button_ajouter;
    QPushButton *pushButton_annuler;
    QLabel *label_heure;
    QLabel *label_dateC;
    QDateEdit *dateEdit_date_ev;
    QLabel *label_lieu_3;
    QLineEdit *lineEdit_lieu;
    QTimeEdit *timeEdit_heure;
    QComboBox *lineEdit_type;
    QWidget *tab_2;
    QPushButton *pushButton_annuler_2;
    QPushButton *pushButton_ok;
    QLineEdit *lineEdit_id_2;
    QPushButton *button_modifier;
    QLabel *label_id_2;
    QLabel *label_nom_2;
    QLabel *label_description_2;
    QLabel *label_type_2;
    QLabel *label_lieu_2;
    QLabel *label_date;
    QLabel *label_time;
    QLineEdit *lineEdit_nom_2;
    QLineEdit *lineEdit_description_2;
    QLineEdit *lineEdit_telephone_2;
    QDateEdit *dateEdit_date_ev_2;
    QTimeEdit *timeEdit_heure_2;
    QLabel *label_lieu_4;
    QLineEdit *lineEdit_lieu_2;
    QComboBox *lineEdit_type_2;
    QWidget *tab_3;
    QPushButton *button_supprimer;
    QPushButton *pushbutton_annuler_3;
    QLabel *label_id_3;
    QLineEdit *lineEdit_id_3;
    QLabel *notificationLibel;
    QTabWidget *tabWidget_2;
    QWidget *tabWidget_2Page2;
    QLabel *label_8;
    QPushButton *pushButton_afficher2;
    QTableView *tableView_3;
    QCalendarWidget *calendarWidget_events;
    QWidget *tabWidget_2Page1;
    QTableView *tableView_2;
    QLabel *label_5;
    QComboBox *comboBox_tri;
    QLabel *label_7;
    QPushButton *pushButton_trier_id;
    QWidget *tab_4;
    QTableWidget *tableWidget_statistique;
    QLabel *label_9;
    QComboBox *comboBox_tri_2;
    QPushButton *button_afficherstatistique;
    QPushButton *pushButton_telecharger;
    QLabel *label_lieu_5;
    QLineEdit *lineEdit_tel;
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

    void setupUi(QMainWindow *MainEvent)
    {
        if (MainEvent->objectName().isEmpty())
            MainEvent->setObjectName("MainEvent");
        MainEvent->resize(971, 632);
        centralwidget = new QWidget(MainEvent);
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
"font: 700 italic 10pt \"Segoe UI\";\n"
"font: 900 italic 10pt \"Segoe UI\";\n"
"font: 900 italic 10pt \"Segoe UI\";"));

        horizontalLayout_7->addWidget(label_2);

        label_3 = new QLabel(frame_7);
        label_3->setObjectName("label_3");
        label_3->setMaximumSize(QSize(64, 64));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/logo.png")));
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
"color: rgb(86, 1, 38);\n"
"font: 900 italic 10pt \"Segoe UI\";"));
        page = new QWidget();
        page->setObjectName("page");
        page->setGeometry(QRect(0, 0, 208, 318));
        verticalLayout_8 = new QVBoxLayout(page);
        verticalLayout_8->setObjectName("verticalLayout_8");
        frame_10 = new QFrame(page);
        frame_10->setObjectName("frame_10");
        frame_10->setFrameShape(QFrame::Shape::StyledPanel);
        frame_10->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_9 = new QVBoxLayout(frame_10);
        verticalLayout_9->setObjectName("verticalLayout_9");
        pushButton_10 = new QPushButton(frame_10);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setStyleSheet(QString::fromUtf8("font: 900 italic 10pt \"Segoe UI\";"));

        verticalLayout_9->addWidget(pushButton_10);

        pushButton_13 = new QPushButton(frame_10);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setStyleSheet(QString::fromUtf8("font: 900 italic 10pt \"Segoe UI\";"));

        verticalLayout_9->addWidget(pushButton_13);

        pushButton_11 = new QPushButton(frame_10);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setStyleSheet(QString::fromUtf8("font: 900 italic 9pt \"Segoe UI\";"));

        verticalLayout_9->addWidget(pushButton_11);

        pushButton_17 = new QPushButton(frame_10);
        pushButton_17->setObjectName("pushButton_17");
        pushButton_17->setStyleSheet(QString::fromUtf8("font: 900 italic 10pt \"Segoe UI\";"));

        verticalLayout_9->addWidget(pushButton_17);

        pushButton_12 = new QPushButton(frame_10);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setStyleSheet(QString::fromUtf8("font: 900 italic 10pt \"Segoe UI\";"));

        verticalLayout_9->addWidget(pushButton_12);

        pushButton_16 = new QPushButton(frame_10);
        pushButton_16->setObjectName("pushButton_16");
        pushButton_16->setStyleSheet(QString::fromUtf8("font: 900 italic 10pt \"Segoe UI\";"));

        verticalLayout_9->addWidget(pushButton_16);


        verticalLayout_8->addWidget(frame_10);

        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../equipe slim/Atelier_Connexion/Atelier_Connexion/icons/chevron-down.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        toolBox->addItem(page, icon, QString::fromUtf8("Menu 1"));
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        page_2->setGeometry(QRect(0, 0, 172, 335));
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
"color: rgb(86, 1, 38);\n"
"font: 900 italic 10pt \"Segoe UI\";"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("icons/external-link.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
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
        icon2.addFile(QString::fromUtf8(":/new/prefix1/icons/align-left.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
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
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 242, 219);\n"
"color: rgb(86, 1, 38);"));

        horizontalLayout_5->addWidget(lineEdit);

        searchButton = new QPushButton(frame_2);
        searchButton->setObjectName("searchButton");
        searchButton->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 242, 219);"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/icons/search.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        searchButton->setIcon(icon3);

        horizontalLayout_5->addWidget(searchButton);

        pushButton_4 = new QPushButton(frame_2);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 242, 219);"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/icons/bell.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        pushButton_4->setIcon(icon4);

        horizontalLayout_5->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(frame_2);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 242, 219);"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/icons/user.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        pushButton_5->setIcon(icon5);

        horizontalLayout_5->addWidget(pushButton_5);

        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName("pushButton");
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 242, 219);"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/icons/maximize-2.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        pushButton->setIcon(icon6);

        horizontalLayout_5->addWidget(pushButton);

        pushButton_2 = new QPushButton(frame_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 242, 219);"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/prefix1/icons/arrow-down-left.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        pushButton_2->setIcon(icon7);

        horizontalLayout_5->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(frame_2);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        pushButton_3->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 242, 219);\n"
""));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/new/prefix1/icons/x.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        pushButton_3->setIcon(icon8);

        horizontalLayout_5->addWidget(pushButton_3);


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
        label_6 = new QLabel(main_body_contents);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(382, 10, 351, 151));
        label_6->setPixmap(QPixmap(QString::fromUtf8("../../../Atelier_Connexio/Atelier_Connexion/Atelier_Connexion/icons/shop.jpg")));
        label_6->setScaledContents(true);
        label_6->setTextInteractionFlags(Qt::TextInteractionFlag::LinksAccessibleByKeyboard|Qt::TextInteractionFlag::LinksAccessibleByMouse|Qt::TextInteractionFlag::TextBrowserInteraction|Qt::TextInteractionFlag::TextEditable|Qt::TextInteractionFlag::TextEditorInteraction|Qt::TextInteractionFlag::TextSelectableByKeyboard|Qt::TextInteractionFlag::TextSelectableByMouse);
        frame_12 = new QFrame(main_body_contents);
        frame_12->setObjectName("frame_12");
        frame_12->setGeometry(QRect(20, 0, 321, 441));
        frame_12->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"background-color: rgb(86, 1, 38);\n"
"color: rgb(86, 1, 38);\n"
"border-radius: 40px;\n"
"font: 900 italic 8pt \"Segoe UI\";"));
        frame_12->setFrameShape(QFrame::Shape::StyledPanel);
        frame_12->setFrameShadow(QFrame::Shadow::Raised);
        label_nomApp = new QLabel(frame_12);
        label_nomApp->setObjectName("label_nomApp");
        label_nomApp->setGeometry(QRect(50, 30, 231, 31));
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
        pushButton_noti = new QPushButton(frame_12);
        pushButton_noti->setObjectName("pushButton_noti");
        pushButton_noti->setGeometry(QRect(240, 20, 51, 41));
        pushButton_noti->setStyleSheet(QString::fromUtf8("border: none;\n"
"image: url(:/resources/notification.png);\n"
"background: transparent;"));
        tabWidget = new QTabWidget(frame_12);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(20, 80, 281, 301));
        tabWidget->setStyleSheet(QString::fromUtf8("    QTabWidget::pane { \n"
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
        lineEdit_id = new QLineEdit(tab);
        lineEdit_id->setObjectName("lineEdit_id");
        lineEdit_id->setGeometry(QRect(140, 30, 121, 16));
        lineEdit_id->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"color: rgb(86, 1, 38);"));
        lineEdit_telephone = new QLineEdit(tab);
        lineEdit_telephone->setObjectName("lineEdit_telephone");
        lineEdit_telephone->setGeometry(QRect(140, 110, 121, 16));
        lineEdit_telephone->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid  #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"color: rgb(86, 1, 38);"));
        lineEdit_description = new QLineEdit(tab);
        lineEdit_description->setObjectName("lineEdit_description");
        lineEdit_description->setGeometry(QRect(140, 70, 121, 16));
        lineEdit_description->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid  #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"color: rgb(86, 1, 38);"));
        lineEdit_nom = new QLineEdit(tab);
        lineEdit_nom->setObjectName("lineEdit_nom");
        lineEdit_nom->setGeometry(QRect(140, 50, 121, 16));
        lineEdit_nom->setStyleSheet(QString::fromUtf8("color: rgb(86, 1, 38);\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid  #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        button_ajouter = new QPushButton(tab);
        button_ajouter->setObjectName("button_ajouter");
        button_ajouter->setGeometry(QRect(60, 220, 75, 24));
        button_ajouter->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
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
        dateEdit_date_ev = new QDateEdit(tab);
        dateEdit_date_ev->setObjectName("dateEdit_date_ev");
        dateEdit_date_ev->setGeometry(QRect(140, 130, 121, 16));
        dateEdit_date_ev->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"color: rgb(86, 1, 38);\n"
"border-style: solid;\n"
"border: 2px solid  #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        label_lieu_3 = new QLabel(tab);
        label_lieu_3->setObjectName("label_lieu_3");
        label_lieu_3->setGeometry(QRect(20, 170, 91, 16));
        label_lieu_3->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        lineEdit_lieu = new QLineEdit(tab);
        lineEdit_lieu->setObjectName("lineEdit_lieu");
        lineEdit_lieu->setGeometry(QRect(140, 170, 121, 16));
        lineEdit_lieu->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid  #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"color: rgb(86, 1, 38);"));
        timeEdit_heure = new QTimeEdit(tab);
        timeEdit_heure->setObjectName("timeEdit_heure");
        timeEdit_heure->setGeometry(QRect(140, 149, 118, 20));
        timeEdit_heure->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"color: rgb(86, 1, 38);\n"
"border-style: solid;\n"
"border: 2px solid  #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        lineEdit_type = new QComboBox(tab);
        lineEdit_type->addItem(QString());
        lineEdit_type->addItem(QString());
        lineEdit_type->addItem(QString());
        lineEdit_type->setObjectName("lineEdit_type");
        lineEdit_type->setGeometry(QRect(140, 90, 121, 16));
        lineEdit_type->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid  #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"color: rgb(86, 1, 38);"));
        tabWidget->addTab(tab, QString());
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
        lineEdit_id_2 = new QLineEdit(tab_2);
        lineEdit_id_2->setObjectName("lineEdit_id_2");
        lineEdit_id_2->setGeometry(QRect(110, 20, 51, 16));
        lineEdit_id_2->setStyleSheet(QString::fromUtf8("\n"
"color: rgb(86, 1, 38);\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        button_modifier = new QPushButton(tab_2);
        button_modifier->setObjectName("button_modifier");
        button_modifier->setGeometry(QRect(50, 230, 75, 24));
        button_modifier->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
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
        label_date->setGeometry(QRect(10, 130, 91, 16));
        label_date->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        label_time = new QLabel(tab_2);
        label_time->setObjectName("label_time");
        label_time->setGeometry(QRect(10, 150, 101, 16));
        label_time->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        lineEdit_nom_2 = new QLineEdit(tab_2);
        lineEdit_nom_2->setObjectName("lineEdit_nom_2");
        lineEdit_nom_2->setGeometry(QRect(140, 50, 121, 16));
        lineEdit_nom_2->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"color: rgb(86, 1, 38);"));
        lineEdit_description_2 = new QLineEdit(tab_2);
        lineEdit_description_2->setObjectName("lineEdit_description_2");
        lineEdit_description_2->setGeometry(QRect(140, 70, 121, 16));
        lineEdit_description_2->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"color: rgb(86, 1, 38);"));
        lineEdit_telephone_2 = new QLineEdit(tab_2);
        lineEdit_telephone_2->setObjectName("lineEdit_telephone_2");
        lineEdit_telephone_2->setGeometry(QRect(140, 110, 121, 16));
        lineEdit_telephone_2->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid  #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"color: rgb(86, 1, 38);"));
        dateEdit_date_ev_2 = new QDateEdit(tab_2);
        dateEdit_date_ev_2->setObjectName("dateEdit_date_ev_2");
        dateEdit_date_ev_2->setGeometry(QRect(140, 130, 121, 16));
        dateEdit_date_ev_2->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"color: rgb(86, 1, 38);\n"
"border-style: solid;\n"
"border: 2px solid  #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        timeEdit_heure_2 = new QTimeEdit(tab_2);
        timeEdit_heure_2->setObjectName("timeEdit_heure_2");
        timeEdit_heure_2->setGeometry(QRect(140, 150, 118, 20));
        timeEdit_heure_2->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"color: rgb(86, 1, 38);\n"
"border-style: solid;\n"
"border: 2px solid  #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        label_lieu_4 = new QLabel(tab_2);
        label_lieu_4->setObjectName("label_lieu_4");
        label_lieu_4->setGeometry(QRect(10, 170, 91, 16));
        label_lieu_4->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        lineEdit_lieu_2 = new QLineEdit(tab_2);
        lineEdit_lieu_2->setObjectName("lineEdit_lieu_2");
        lineEdit_lieu_2->setGeometry(QRect(140, 170, 121, 16));
        lineEdit_lieu_2->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid  #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"color: rgb(86, 1, 38);"));
        lineEdit_type_2 = new QComboBox(tab_2);
        lineEdit_type_2->addItem(QString());
        lineEdit_type_2->addItem(QString());
        lineEdit_type_2->addItem(QString());
        lineEdit_type_2->setObjectName("lineEdit_type_2");
        lineEdit_type_2->setGeometry(QRect(140, 90, 121, 16));
        lineEdit_type_2->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid  #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"color: rgb(86, 1, 38);"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        button_supprimer = new QPushButton(tab_3);
        button_supprimer->setObjectName("button_supprimer");
        button_supprimer->setGeometry(QRect(100, 110, 81, 24));
        button_supprimer->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid #f77f00;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        pushbutton_annuler_3 = new QPushButton(tab_3);
        pushbutton_annuler_3->setObjectName("pushbutton_annuler_3");
        pushbutton_annuler_3->setGeometry(QRect(100, 150, 81, 24));
        pushbutton_annuler_3->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
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
        lineEdit_id_3 = new QLineEdit(tab_3);
        lineEdit_id_3->setObjectName("lineEdit_id_3");
        lineEdit_id_3->setGeometry(QRect(150, 60, 51, 16));
        lineEdit_id_3->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"color: rgb(86, 1, 38);"));
        tabWidget->addTab(tab_3, QString());
        notificationLibel = new QLabel(frame_12);
        notificationLibel->setObjectName("notificationLibel");
        notificationLibel->setGeometry(QRect(266, 50, 20, 20));
        notificationLibel->setStyleSheet(QString::fromUtf8("background:transparent;"));
        tabWidget_2 = new QTabWidget(main_body_contents);
        tabWidget_2->setObjectName("tabWidget_2");
        tabWidget_2->setGeometry(QRect(370, 170, 381, 301));
        tabWidget_2->setStyleSheet(QString::fromUtf8("    QTabWidget::pane { \n"
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
        tabWidget_2Page2 = new QWidget();
        tabWidget_2Page2->setObjectName("tabWidget_2Page2");
        label_8 = new QLabel(tabWidget_2Page2);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(30, 0, 291, 31));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(86, 1, 38);\n"
"font: 900 italic 10pt \"Segoe UI\";"));
        pushButton_afficher2 = new QPushButton(tabWidget_2Page2);
        pushButton_afficher2->setObjectName("pushButton_afficher2");
        pushButton_afficher2->setGeometry(QRect(290, 220, 81, 41));
        pushButton_afficher2->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid #f77f00;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        tableView_3 = new QTableView(tabWidget_2Page2);
        tableView_3->setObjectName("tableView_3");
        tableView_3->setGeometry(QRect(180, 30, 191, 181));
        tableView_3->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);"));
        calendarWidget_events = new QCalendarWidget(tabWidget_2Page2);
        calendarWidget_events->setObjectName("calendarWidget_events");
        calendarWidget_events->setGeometry(QRect(0, 30, 171, 171));
        calendarWidget_events->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"background-color: rgb(86, 1, 38);\n"
"background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"border-radius: 40px;\n"
"font: 900 italic 8pt \"Segoe UI\";"));
        tabWidget_2->addTab(tabWidget_2Page2, QString());
        tabWidget_2Page1 = new QWidget();
        tabWidget_2Page1->setObjectName("tabWidget_2Page1");
        tableView_2 = new QTableView(tabWidget_2Page1);
        tableView_2->setObjectName("tableView_2");
        tableView_2->setGeometry(QRect(-10, 60, 381, 191));
        tableView_2->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);"));
        label_5 = new QLabel(tabWidget_2Page1);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(0, 0, 481, 31));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(86, 1, 38);\n"
"font: 900 italic 10pt \"Segoe UI\";"));
        comboBox_tri = new QComboBox(tabWidget_2Page1);
        comboBox_tri->addItem(QString());
        comboBox_tri->setObjectName("comboBox_tri");
        comboBox_tri->setGeometry(QRect(240, 30, 71, 31));
        comboBox_tri->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid #858fb4;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"color: rgb(86, 1, 38);\n"
"background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);"));
        label_7 = new QLabel(tabWidget_2Page1);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(110, 30, 131, 31));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(86, 1, 38);\n"
"font: 900 italic 10pt \"Segoe UI\";"));
        pushButton_trier_id = new QPushButton(tabWidget_2Page1);
        pushButton_trier_id->setObjectName("pushButton_trier_id");
        pushButton_trier_id->setGeometry(QRect(10, 30, 75, 24));
        pushButton_trier_id->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid #f77f00;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        tabWidget_2->addTab(tabWidget_2Page1, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        tableWidget_statistique = new QTableWidget(tab_4);
        tableWidget_statistique->setObjectName("tableWidget_statistique");
        tableWidget_statistique->setGeometry(QRect(20, 60, 331, 181));
        tableWidget_statistique->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);"));
        label_9 = new QLabel(tab_4);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(20, 0, 301, 31));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(86, 1, 38);\n"
"font: 900 italic 10pt \"Segoe UI\";"));
        comboBox_tri_2 = new QComboBox(tab_4);
        comboBox_tri_2->addItem(QString());
        comboBox_tri_2->setObjectName("comboBox_tri_2");
        comboBox_tri_2->setGeometry(QRect(280, 30, 71, 31));
        comboBox_tri_2->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid #858fb4;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"color: rgb(86, 1, 38);\n"
"background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);"));
        button_afficherstatistique = new QPushButton(tab_4);
        button_afficherstatistique->setObjectName("button_afficherstatistique");
        button_afficherstatistique->setGeometry(QRect(64, 30, 191, 24));
        button_afficherstatistique->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid #f77f00;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        pushButton_telecharger = new QPushButton(tab_4);
        pushButton_telecharger->setObjectName("pushButton_telecharger");
        pushButton_telecharger->setGeometry(QRect(90, 240, 191, 21));
        pushButton_telecharger->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid #eae2b7;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"background-color: #ffffff;\n"
"color: rgb(86, 1, 38);"));
        tabWidget_2->addTab(tab_4, QString());
        label_lieu_5 = new QLabel(main_body_contents);
        label_lieu_5->setObjectName("label_lieu_5");
        label_lieu_5->setGeometry(QRect(160, 460, 91, 16));
        label_lieu_5->setStyleSheet(QString::fromUtf8("background-color:#A3A3A3;\n"
"color: rgb(86, 1, 38);\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;"));
        lineEdit_tel = new QLineEdit(main_body_contents);
        lineEdit_tel->setObjectName("lineEdit_tel");
        lineEdit_tel->setGeometry(QRect(260, 460, 121, 16));
        lineEdit_tel->setStyleSheet(QString::fromUtf8("padding: 1px;\n"
"border-style: solid;\n"
"border: 2px solid  #8ed2ff;\n"
"border-radius: 8px;\n"
"font-size: 12px;\n"
"font-family: Palatino Linotype;\n"
"color: rgb(86, 1, 38);"));

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
        icon9.addFile(QString::fromUtf8("icons/box.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
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

        MainEvent->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainEvent);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 971, 25));
        MainEvent->setMenuBar(menubar);
        statusbar = new QStatusBar(MainEvent);
        statusbar->setObjectName("statusbar");
        MainEvent->setStatusBar(statusbar);

        retranslateUi(MainEvent);

        toolBox->setCurrentIndex(0);
        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainEvent);
    } // setupUi

    void retranslateUi(QMainWindow *MainEvent)
    {
        MainEvent->setWindowTitle(QCoreApplication::translate("MainEvent", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainEvent", "LUXBRAND", nullptr));
        label_3->setText(QString());
        pushButton_10->setText(QCoreApplication::translate("MainEvent", "Employes", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainEvent", "Locataires", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainEvent", "Locaux commerciaux", nullptr));
        pushButton_17->setText(QCoreApplication::translate("MainEvent", "Evenements", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainEvent", "Maintenance", nullptr));
        pushButton_16->setText(QCoreApplication::translate("MainEvent", "Services", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("MainEvent", "Menu 1", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainEvent", "besoin d'aide ", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainEvent", "Log out", nullptr));
        label_4->setText(QCoreApplication::translate("MainEvent", "text a ajouter plus tard ", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("MainEvent", "Menu 2", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainEvent", "EXIT", nullptr));
        pushButton_8->setText(QString());
        lineEdit->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainEvent", "search", nullptr));
        searchButton->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        label_6->setText(QString());
        label_nomApp->setText(QCoreApplication::translate("MainEvent", "Gestion des \303\251venements :", nullptr));
        pushButton_noti->setText(QString());
        label_id->setText(QCoreApplication::translate("MainEvent", "  ID", nullptr));
        label_nom->setText(QCoreApplication::translate("MainEvent", "  Nom", nullptr));
        label_description->setText(QCoreApplication::translate("MainEvent", "Description", nullptr));
        label_type->setText(QCoreApplication::translate("MainEvent", "Type", nullptr));
        label_lieu->setText(QCoreApplication::translate("MainEvent", "Telephone", nullptr));
        lineEdit_id->setText(QString());
        lineEdit_telephone->setText(QString());
        lineEdit_description->setText(QString());
        lineEdit_nom->setText(QString());
        button_ajouter->setText(QCoreApplication::translate("MainEvent", "Ajouter", nullptr));
        pushButton_annuler->setText(QCoreApplication::translate("MainEvent", "Annuler", nullptr));
        label_heure->setText(QCoreApplication::translate("MainEvent", "HEURE", nullptr));
        label_dateC->setText(QCoreApplication::translate("MainEvent", "Date_ev", nullptr));
        label_lieu_3->setText(QCoreApplication::translate("MainEvent", "Lieu", nullptr));
        lineEdit_lieu->setText(QString());
        lineEdit_type->setItemText(0, QCoreApplication::translate("MainEvent", "sportif", nullptr));
        lineEdit_type->setItemText(1, QCoreApplication::translate("MainEvent", "promotion", nullptr));
        lineEdit_type->setItemText(2, QCoreApplication::translate("MainEvent", "musique", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainEvent", "Ajouter", nullptr));
        pushButton_annuler_2->setText(QCoreApplication::translate("MainEvent", "Annuler", nullptr));
        pushButton_ok->setText(QCoreApplication::translate("MainEvent", "OK", nullptr));
        lineEdit_id_2->setText(QString());
        button_modifier->setText(QCoreApplication::translate("MainEvent", "Modifier", nullptr));
        label_id_2->setText(QCoreApplication::translate("MainEvent", "  ID", nullptr));
        label_nom_2->setText(QCoreApplication::translate("MainEvent", "  Nom", nullptr));
        label_description_2->setText(QCoreApplication::translate("MainEvent", "Description", nullptr));
        label_type_2->setText(QCoreApplication::translate("MainEvent", "Type", nullptr));
        label_lieu_2->setText(QCoreApplication::translate("MainEvent", "Telephone", nullptr));
        label_date->setText(QCoreApplication::translate("MainEvent", "Date_ev", nullptr));
        label_time->setText(QCoreApplication::translate("MainEvent", "HEURE", nullptr));
        lineEdit_nom_2->setText(QString());
        lineEdit_description_2->setText(QString());
        lineEdit_telephone_2->setText(QString());
        label_lieu_4->setText(QCoreApplication::translate("MainEvent", "Lieu", nullptr));
        lineEdit_lieu_2->setText(QString());
        lineEdit_type_2->setItemText(0, QCoreApplication::translate("MainEvent", "sportif", nullptr));
        lineEdit_type_2->setItemText(1, QCoreApplication::translate("MainEvent", "promotion", nullptr));
        lineEdit_type_2->setItemText(2, QCoreApplication::translate("MainEvent", "musique", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainEvent", "Mise a Jour", nullptr));
        button_supprimer->setText(QCoreApplication::translate("MainEvent", "supprimer", nullptr));
        pushbutton_annuler_3->setText(QCoreApplication::translate("MainEvent", "Annuler", nullptr));
        label_id_3->setText(QCoreApplication::translate("MainEvent", "  ID", nullptr));
        lineEdit_id_3->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainEvent", "Supprimer", nullptr));
        notificationLibel->setText(QString());
        label_8->setText(QCoreApplication::translate("MainEvent", "Plannification de les \303\251venement :", nullptr));
        pushButton_afficher2->setText(QCoreApplication::translate("MainEvent", "Afficher", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tabWidget_2Page2), QCoreApplication::translate("MainEvent", "1", nullptr));
        label_5->setText(QCoreApplication::translate("MainEvent", "Tableau d'\303\251venement nouvellement ajout\303\251s :", nullptr));
        comboBox_tri->setItemText(0, QCoreApplication::translate("MainEvent", "ID", nullptr));

        label_7->setText(QCoreApplication::translate("MainEvent", "Classification :", nullptr));
        pushButton_trier_id->setText(QCoreApplication::translate("MainEvent", "Trier", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tabWidget_2Page1), QCoreApplication::translate("MainEvent", "2", nullptr));
        label_9->setText(QCoreApplication::translate("MainEvent", "Affichage de statistiqes selon type :", nullptr));
        comboBox_tri_2->setItemText(0, QCoreApplication::translate("MainEvent", "Type", nullptr));

        button_afficherstatistique->setText(QCoreApplication::translate("MainEvent", "Afficher les statistiques", nullptr));
        pushButton_telecharger->setText(QCoreApplication::translate("MainEvent", "Exporter l'\303\251venement en PDF", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QCoreApplication::translate("MainEvent", "3", nullptr));
        label_lieu_5->setText(QCoreApplication::translate("MainEvent", "Telephone", nullptr));
        lineEdit_tel->setText(QString());
        label->setText(QCoreApplication::translate("MainEvent", "Modern UI v 7.7.7", nullptr));
        pushButton_7->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainEvent: public Ui_MainEvent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINEVENT_H
