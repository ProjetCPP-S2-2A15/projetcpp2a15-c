/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_8;
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
    QPushButton *pushButton_15;
    QPushButton *pushButton_14;
    QFrame *frame_11;
    QVBoxLayout *verticalLayout_11;
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
    QPushButton *pushButton_6;
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
    QFrame *frame_12;
    QLabel *label_nomApp;
    QPushButton *pushButton_noti;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_nom;
    QLabel *label_description;
    QLabel *label_type;
    QLabel *label_lieu;
    QLineEdit *lineEdit_telephone;
    QLineEdit *lineEdit_adresse;
    QLineEdit *lineEdit_nom;
    QPushButton *pushButton_ajouter;
    QLabel *label_heure;
    QLabel *label_dateC;
    QDateEdit *dateEdit_C_2;
    QDateEdit *dateEdit_C_3;
    QLineEdit *lineEdit_email;
    QWidget *tab_2;
    QPushButton *pushButton_ok;
    QLineEdit *lineEdit_idU;
    QPushButton *pushButton_modifier;
    QLabel *label_id_2;
    QLabel *label_nom_2;
    QLabel *label_description_2;
    QLabel *label_type_2;
    QLabel *label_lieu_2;
    QLabel *label_date;
    QLabel *label_time;
    QLineEdit *lineEdit_nom2;
    QLineEdit *lineEdit_adresse2;
    QLineEdit *lineEdit_telephone2;
    QDateEdit *dateEdit_debutcontrat2;
    QDateEdit *dateEdit_fincontrat2;
    QLineEdit *lineEdit_Email2;
    QWidget *tab_3;
    QPushButton *pushButton_supprimer;
    QLabel *label_id_3;
    QLineEdit *lineEdit_id3;
    QWidget *tab_4;
    QPushButton *pushButton_telecharger_2;
    QLineEdit *lineEdit_id4;
    QPushButton *pushButton_mailing;
    QLabel *label_5;
    QPushButton *pushButton_triedate;
    QPushButton *pushButton_trieid;
    QTableView *tableView;
    QPushButton *pushButton_afficherStats;
    QTextEdit *chatDisplay;
    QPushButton *sendChatMessage;
    QLineEdit *chatInput;
    QFrame *footer;
    QHBoxLayout *horizontalLayout_3;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_7;
    QFrame *size_grip;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1338, 825);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(86, 1, 38);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout_8 = new QHBoxLayout(centralwidget);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        slide_menu_container = new QFrame(centralwidget);
        slide_menu_container->setObjectName("slide_menu_container");
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
        label_3->setPixmap(QPixmap(QString::fromUtf8("Capture_d_\303\251cran_2025-02-13_135510-removebg-preview (1).png")));
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
        page->setGeometry(QRect(0, 0, 209, 583));
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
        pushButton_10->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #8B0000;  /* Rouge bordeaux */\n"
"    color: #F5F5DC;              /* Beige pour le texte */\n"
"    border-radius: 10px;         /* Coins arrondis */\n"
"    padding: 8px 15px;           /* Espacement int\303\251rieur */\n"
"    font-size: 14px;             /* Taille de police */\n"
"    font-weight: bold;           /* Police en gras */\n"
"    border: 2px solid #600000;   /* Bordure plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A52A2A;   /* Rouge bordeaux plus clair */\n"
"    border: 2px solid #8B0000;   \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #600000;   /* Rouge bordeaux tr\303\250s fonc\303\251 */\n"
"    border: 2px solid #400000;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #D3B8AE;   /* Beige fonc\303\251 pour d\303\251sactiv\303\251 */\n"
"    color: #8B0000;\n"
"    border: 2px solid #A52A2A;\n"
"}"));

        verticalLayout_9->addWidget(pushButton_10);

        pushButton_13 = new QPushButton(frame_10);
        pushButton_13->setObjectName("pushButton_13");
        pushButton_13->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #8B0000;  /* Rouge bordeaux */\n"
"    color: #F5F5DC;              /* Beige pour le texte */\n"
"    border-radius: 10px;         /* Coins arrondis */\n"
"    padding: 8px 15px;           /* Espacement int\303\251rieur */\n"
"    font-size: 14px;             /* Taille de police */\n"
"    font-weight: bold;           /* Police en gras */\n"
"    border: 2px solid #600000;   /* Bordure plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A52A2A;   /* Rouge bordeaux plus clair */\n"
"    border: 2px solid #8B0000;   \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #600000;   /* Rouge bordeaux tr\303\250s fonc\303\251 */\n"
"    border: 2px solid #400000;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #D3B8AE;   /* Beige fonc\303\251 pour d\303\251sactiv\303\251 */\n"
"    color: #8B0000;\n"
"    border: 2px solid #A52A2A;\n"
"}"));

        verticalLayout_9->addWidget(pushButton_13);

        pushButton_11 = new QPushButton(frame_10);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #8B0000;  /* Rouge bordeaux */\n"
"    color: #F5F5DC;              /* Beige pour le texte */\n"
"    border-radius: 10px;         /* Coins arrondis */\n"
"    padding: 8px 15px;           /* Espacement int\303\251rieur */\n"
"    font-size: 14px;             /* Taille de police */\n"
"    font-weight: bold;           /* Police en gras */\n"
"    border: 2px solid #600000;   /* Bordure plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A52A2A;   /* Rouge bordeaux plus clair */\n"
"    border: 2px solid #8B0000;   \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #600000;   /* Rouge bordeaux tr\303\250s fonc\303\251 */\n"
"    border: 2px solid #400000;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #D3B8AE;   /* Beige fonc\303\251 pour d\303\251sactiv\303\251 */\n"
"    color: #8B0000;\n"
"    border: 2px solid #A52A2A;\n"
"}"));

        verticalLayout_9->addWidget(pushButton_11);

        pushButton_17 = new QPushButton(frame_10);
        pushButton_17->setObjectName("pushButton_17");
        pushButton_17->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #8B0000;  /* Rouge bordeaux */\n"
"    color: #F5F5DC;              /* Beige pour le texte */\n"
"    border-radius: 10px;         /* Coins arrondis */\n"
"    padding: 8px 15px;           /* Espacement int\303\251rieur */\n"
"    font-size: 14px;             /* Taille de police */\n"
"    font-weight: bold;           /* Police en gras */\n"
"    border: 2px solid #600000;   /* Bordure plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A52A2A;   /* Rouge bordeaux plus clair */\n"
"    border: 2px solid #8B0000;   \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #600000;   /* Rouge bordeaux tr\303\250s fonc\303\251 */\n"
"    border: 2px solid #400000;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #D3B8AE;   /* Beige fonc\303\251 pour d\303\251sactiv\303\251 */\n"
"    color: #8B0000;\n"
"    border: 2px solid #A52A2A;\n"
"}"));

        verticalLayout_9->addWidget(pushButton_17);

        pushButton_12 = new QPushButton(frame_10);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #8B0000;  /* Rouge bordeaux */\n"
"    color: #F5F5DC;              /* Beige pour le texte */\n"
"    border-radius: 10px;         /* Coins arrondis */\n"
"    padding: 8px 15px;           /* Espacement int\303\251rieur */\n"
"    font-size: 14px;             /* Taille de police */\n"
"    font-weight: bold;           /* Police en gras */\n"
"    border: 2px solid #600000;   /* Bordure plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A52A2A;   /* Rouge bordeaux plus clair */\n"
"    border: 2px solid #8B0000;   \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #600000;   /* Rouge bordeaux tr\303\250s fonc\303\251 */\n"
"    border: 2px solid #400000;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #D3B8AE;   /* Beige fonc\303\251 pour d\303\251sactiv\303\251 */\n"
"    color: #8B0000;\n"
"    border: 2px solid #A52A2A;\n"
"}"));

        verticalLayout_9->addWidget(pushButton_12);

        pushButton_16 = new QPushButton(frame_10);
        pushButton_16->setObjectName("pushButton_16");
        pushButton_16->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #8B0000;  /* Rouge bordeaux */\n"
"    color: #F5F5DC;              /* Beige pour le texte */\n"
"    border-radius: 10px;         /* Coins arrondis */\n"
"    padding: 8px 15px;           /* Espacement int\303\251rieur */\n"
"    font-size: 14px;             /* Taille de police */\n"
"    font-weight: bold;           /* Police en gras */\n"
"    border: 2px solid #600000;   /* Bordure plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A52A2A;   /* Rouge bordeaux plus clair */\n"
"    border: 2px solid #8B0000;   \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #600000;   /* Rouge bordeaux tr\303\250s fonc\303\251 */\n"
"    border: 2px solid #400000;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #D3B8AE;   /* Beige fonc\303\251 pour d\303\251sactiv\303\251 */\n"
"    color: #8B0000;\n"
"    border: 2px solid #A52A2A;\n"
"}"));

        verticalLayout_9->addWidget(pushButton_16);


        verticalLayout_8->addWidget(frame_10);

        QIcon icon;
        icon.addFile(QString::fromUtf8("icons/chevron-down.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        toolBox->addItem(page, icon, QString::fromUtf8("Menu 1"));
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        page_2->setGeometry(QRect(0, 0, 176, 597));
        verticalLayout_10 = new QVBoxLayout(page_2);
        verticalLayout_10->setObjectName("verticalLayout_10");
        pushButton_15 = new QPushButton(page_2);
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

        verticalLayout_10->addWidget(pushButton_15);

        pushButton_14 = new QPushButton(page_2);
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

        verticalLayout_10->addWidget(pushButton_14);

        frame_11 = new QFrame(page_2);
        frame_11->setObjectName("frame_11");
        frame_11->setFrameShape(QFrame::Shape::StyledPanel);
        frame_11->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_11 = new QVBoxLayout(frame_11);
        verticalLayout_11->setSpacing(0);
        verticalLayout_11->setObjectName("verticalLayout_11");
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);

        verticalLayout_10->addWidget(frame_11, 0, Qt::AlignmentFlag::AlignTop);

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


        horizontalLayout_8->addWidget(slide_menu_container);

        main_body = new QFrame(centralwidget);
        main_body->setObjectName("main_body");
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
        icon2.addFile(QString::fromUtf8(":/new/prefix1/icons/align-left.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
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
        lineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: #8B0000;             /* Texte en rouge bordeaux */\n"
"    background-color: #F5F5DC;  /* Fond beige */\n"
"    padding: 5px;               /* Espacement int\303\251rieur */\n"
"    border: 2px solid #600000;  /* Bordure bordeaux fonc\303\251 */\n"
"    border-radius: 8px;         /* Coins arrondis */\n"
"    font-size: 14px;            /* Taille de police */\n"
"    font-family: \"Palatino Linotype\"; /* Police \303\251l\303\251gante */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #A52A2A;  /* Bordure plus claire lorsqu'on clique */\n"
"    background-color: #FFFFFF;   /* Fond blanc subtil pour bien montrer le focus */\n"
"}\n"
"\n"
"QLineEdit:disabled {\n"
"    background-color: #D3B8AE;   /* Beige fonc\303\251 pour d\303\251sactiv\303\251 */\n"
"    color: #8B0000;              /* Texte en bordeaux */\n"
"    border: 2px solid #A52A2A;\n"
"}"));

        horizontalLayout_5->addWidget(lineEdit);

        pushButton_6 = new QPushButton(frame_2);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 242, 219);"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/icons/search.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_6->setIcon(icon3);

        horizontalLayout_5->addWidget(pushButton_6);

        pushButton_4 = new QPushButton(frame_2);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 242, 219);"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/icons/bell.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_4->setIcon(icon4);

        horizontalLayout_5->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(frame_2);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 242, 219);"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/icons/user.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_5->setIcon(icon5);

        horizontalLayout_5->addWidget(pushButton_5);

        pushButton = new QPushButton(frame_2);
        pushButton->setObjectName("pushButton");
        pushButton->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 242, 219);"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/icons/maximize-2.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton->setIcon(icon6);

        horizontalLayout_5->addWidget(pushButton);

        pushButton_2 = new QPushButton(frame_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setStyleSheet(QString::fromUtf8("background-color: rgb(245, 242, 219);"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/prefix1/icons/arrow-down-left.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton_2->setIcon(icon7);

        horizontalLayout_5->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(frame_2);
        pushButton_3->setObjectName("pushButton_3");
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
        frame_12 = new QFrame(main_body_contents);
        frame_12->setObjectName("frame_12");
        frame_12->setGeometry(QRect(30, 40, 421, 521));
        frame_12->setStyleSheet(QString::fromUtf8("background-color: #FAF0E6; /* Beige clair */\n"
"color: #600000;            /* Texte bordeaux */\n"
"border-radius: 40px;        /* Coins arrondis */\n"
"font: 900 italic 8pt \"Segoe UI\";\n"
"border: 2px solid #8B0000;  /* Bordure bordeaux */\n"
"padding: 8px 16px;          /* Espacement interne pour \303\251quilibrer le contenu */\n"
""));
        frame_12->setFrameShape(QFrame::Shape::StyledPanel);
        frame_12->setFrameShadow(QFrame::Shadow::Raised);
        label_nomApp = new QLabel(frame_12);
        label_nomApp->setObjectName("label_nomApp");
        label_nomApp->setGeometry(QRect(60, 20, 231, 41));
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
        tabWidget->setGeometry(QRect(20, 90, 391, 391));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget::pane { \n"
"    border: 2px solid #8B0000; /* Bordure bordeaux */\n"
"    background-color: #F5F5DC; /* Fond beige */\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QTabBar::tab { \n"
"    background: #FAF0E6;  /* Beige clair pour les onglets */\n"
"    color: #600000;        /* Texte bordeaux */\n"
"    padding: 10px 20px;\n"
"    font-size: 14px;\n"
"    font-family: \"Palatino Linotype\";\n"
"    border: 2px solid #8B0000;\n"
"    border-bottom: none;\n"
"    border-top-left-radius: 8px;\n"
"    border-top-right-radius: 8px;\n"
"}\n"
"\n"
"QTabBar::tab:selected { \n"
"    background: #EDE0D4; /* Beige plus fonc\303\251 pour l\342\200\231onglet s\303\251lectionn\303\251 */\n"
"    color: #600000;       /* Texte bordeaux */\n"
"    font-weight: bold;\n"
"    border-bottom: 2px solid #8B0000;\n"
"}\n"
"\n"
"QTabBar::tab:hover {\n"
"    background: #D2B48C;  /* Beige dor\303\251 pour le survol */\n"
"    color: #600000;\n"
"}\n"
"\n"
"QTabWidget {\n"
"    background-color: #FAF0E6; /* Fond global beige "
                        "*/\n"
"    border: 2px solid #8B0000;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
""));
        tab = new QWidget();
        tab->setObjectName("tab");
        label_nom = new QLabel(tab);
        label_nom->setObjectName("label_nom");
        label_nom->setGeometry(QRect(20, 20, 91, 21));
        label_nom->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #EEE4CC; /* Beige doux */\n"
"    color: #600000;            /* Texte bordeaux */\n"
"    font: 900 italic 8pt \"Segoe UI\"; /* Police en italique et gras */\n"
"    border-radius: 8px;         /* Coins arrondis */\n"
"    padding: 4px 8px;           /* Un peu de marge interne */\n"
"    border: 1px solid #8B0000;  /* Fine bordure bordeaux pour les d\303\251marquer */\n"
"}\n"
""));
        label_description = new QLabel(tab);
        label_description->setObjectName("label_description");
        label_description->setGeometry(QRect(20, 60, 91, 21));
        label_description->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #EEE4CC; /* Beige doux */\n"
"    color: #600000;            /* Texte bordeaux */\n"
"    font: 900 italic 8pt \"Segoe UI\"; /* Police en italique et gras */\n"
"    border-radius: 8px;         /* Coins arrondis */\n"
"    padding: 4px 8px;           /* Un peu de marge interne */\n"
"    border: 1px solid #8B0000;  /* Fine bordure bordeaux pour les d\303\251marquer */\n"
"}\n"
""));
        label_type = new QLabel(tab);
        label_type->setObjectName("label_type");
        label_type->setGeometry(QRect(20, 95, 91, 21));
        label_type->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #EEE4CC; /* Beige doux */\n"
"    color: #600000;            /* Texte bordeaux */\n"
"    font: 900 italic 8pt \"Segoe UI\"; /* Police en italique et gras */\n"
"    border-radius: 8px;         /* Coins arrondis */\n"
"    padding: 4px 8px;           /* Un peu de marge interne */\n"
"    border: 1px solid #8B0000;  /* Fine bordure bordeaux pour les d\303\251marquer */\n"
"}\n"
""));
        label_lieu = new QLabel(tab);
        label_lieu->setObjectName("label_lieu");
        label_lieu->setGeometry(QRect(10, 130, 101, 21));
        label_lieu->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #EEE4CC; /* Beige doux */\n"
"    color: #600000;            /* Texte bordeaux */\n"
"    font: 900 italic 8pt \"Segoe UI\"; /* Police en italique et gras */\n"
"    border-radius: 8px;         /* Coins arrondis */\n"
"    padding: 4px 8px;           /* Un peu de marge interne */\n"
"    border: 1px solid #8B0000;  /* Fine bordure bordeaux pour les d\303\251marquer */\n"
"}\n"
""));
        lineEdit_telephone = new QLineEdit(tab);
        lineEdit_telephone->setObjectName("lineEdit_telephone");
        lineEdit_telephone->setGeometry(QRect(140, 130, 131, 31));
        lineEdit_telephone->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: #8B0000;             /* Texte en rouge bordeaux */\n"
"    background-color: #F5F5DC;  /* Fond beige */\n"
"    padding: 5px;               /* Espacement int\303\251rieur */\n"
"    border: 2px solid #600000;  /* Bordure bordeaux fonc\303\251 */\n"
"    border-radius: 8px;         /* Coins arrondis */\n"
"    font-size: 14px;            /* Taille de police */\n"
"    font-family: \"Palatino Linotype\"; /* Police \303\251l\303\251gante */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #A52A2A;  /* Bordure plus claire lorsqu'on clique */\n"
"    background-color: #FFFFFF;   /* Fond blanc subtil pour bien montrer le focus */\n"
"}\n"
"\n"
"QLineEdit:disabled {\n"
"    background-color: #D3B8AE;   /* Beige fonc\303\251 pour d\303\251sactiv\303\251 */\n"
"    color: #8B0000;              /* Texte en bordeaux */\n"
"    border: 2px solid #A52A2A;\n"
"}"));
        lineEdit_adresse = new QLineEdit(tab);
        lineEdit_adresse->setObjectName("lineEdit_adresse");
        lineEdit_adresse->setGeometry(QRect(140, 50, 121, 31));
        lineEdit_adresse->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: #8B0000;             /* Texte en rouge bordeaux */\n"
"    background-color: #F5F5DC;  /* Fond beige */\n"
"    padding: 5px;               /* Espacement int\303\251rieur */\n"
"    border: 2px solid #600000;  /* Bordure bordeaux fonc\303\251 */\n"
"    border-radius: 8px;         /* Coins arrondis */\n"
"    font-size: 14px;            /* Taille de police */\n"
"    font-family: \"Palatino Linotype\"; /* Police \303\251l\303\251gante */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #A52A2A;  /* Bordure plus claire lorsqu'on clique */\n"
"    background-color: #FFFFFF;   /* Fond blanc subtil pour bien montrer le focus */\n"
"}\n"
"\n"
"QLineEdit:disabled {\n"
"    background-color: #D3B8AE;   /* Beige fonc\303\251 pour d\303\251sactiv\303\251 */\n"
"    color: #8B0000;              /* Texte en bordeaux */\n"
"    border: 2px solid #A52A2A;\n"
"}"));
        lineEdit_nom = new QLineEdit(tab);
        lineEdit_nom->setObjectName("lineEdit_nom");
        lineEdit_nom->setGeometry(QRect(140, 10, 121, 31));
        lineEdit_nom->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: #8B0000;             /* Texte en rouge bordeaux */\n"
"    background-color: #F5F5DC;  /* Fond beige */\n"
"    padding: 5px;               /* Espacement int\303\251rieur */\n"
"    border: 2px solid #600000;  /* Bordure bordeaux fonc\303\251 */\n"
"    border-radius: 8px;         /* Coins arrondis */\n"
"    font-size: 14px;            /* Taille de police */\n"
"    font-family: \"Palatino Linotype\"; /* Police \303\251l\303\251gante */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #A52A2A;  /* Bordure plus claire lorsqu'on clique */\n"
"    background-color: #FFFFFF;   /* Fond blanc subtil pour bien montrer le focus */\n"
"}\n"
"\n"
"QLineEdit:disabled {\n"
"    background-color: #D3B8AE;   /* Beige fonc\303\251 pour d\303\251sactiv\303\251 */\n"
"    color: #8B0000;              /* Texte en bordeaux */\n"
"    border: 2px solid #A52A2A;\n"
"}"));
        pushButton_ajouter = new QPushButton(tab);
        pushButton_ajouter->setObjectName("pushButton_ajouter");
        pushButton_ajouter->setGeometry(QRect(120, 270, 101, 31));
        pushButton_ajouter->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #8B0000;  /* Rouge bordeaux */\n"
"    color: #F5F5DC;              /* Beige pour le texte */\n"
"    border-radius: 10px;         /* Coins arrondis */\n"
"    padding: 8px 15px;           /* Espacement int\303\251rieur */\n"
"    font-size: 14px;             /* Taille de police */\n"
"    font-weight: bold;           /* Police en gras */\n"
"    border: 2px solid #600000;   /* Bordure plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A52A2A;   /* Rouge bordeaux plus clair */\n"
"    border: 2px solid #8B0000;   \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #600000;   /* Rouge bordeaux tr\303\250s fonc\303\251 */\n"
"    border: 2px solid #400000;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #D3B8AE;   /* Beige fonc\303\251 pour d\303\251sactiv\303\251 */\n"
"    color: #8B0000;\n"
"    border: 2px solid #A52A2A;\n"
"}"));
        label_heure = new QLabel(tab);
        label_heure->setObjectName("label_heure");
        label_heure->setGeometry(QRect(10, 220, 101, 21));
        label_heure->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #EEE4CC; /* Beige doux */\n"
"    color: #600000;            /* Texte bordeaux */\n"
"    font: 900 italic 8pt \"Segoe UI\"; /* Police en italique et gras */\n"
"    border-radius: 8px;         /* Coins arrondis */\n"
"    padding: 4px 8px;           /* Un peu de marge interne */\n"
"    border: 1px solid #8B0000;  /* Fine bordure bordeaux pour les d\303\251marquer */\n"
"}\n"
""));
        label_dateC = new QLabel(tab);
        label_dateC->setObjectName("label_dateC");
        label_dateC->setGeometry(QRect(10, 180, 121, 21));
        label_dateC->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #EEE4CC; /* Beige doux */\n"
"    color: #600000;            /* Texte bordeaux */\n"
"    font: 900 italic 8pt \"Segoe UI\"; /* Police en italique et gras */\n"
"    border-radius: 8px;         /* Coins arrondis */\n"
"    padding: 4px 8px;           /* Un peu de marge interne */\n"
"    border: 1px solid #8B0000;  /* Fine bordure bordeaux pour les d\303\251marquer */\n"
"}\n"
""));
        dateEdit_C_2 = new QDateEdit(tab);
        dateEdit_C_2->setObjectName("dateEdit_C_2");
        dateEdit_C_2->setGeometry(QRect(150, 170, 131, 31));
        dateEdit_C_2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: #8B0000;             /* Texte en rouge bordeaux */\n"
"    background-color: #F5F5DC;  /* Fond beige */\n"
"    padding: 5px;               /* Espacement int\303\251rieur */\n"
"    border: 2px solid #600000;  /* Bordure bordeaux fonc\303\251 */\n"
"    border-radius: 8px;         /* Coins arrondis */\n"
"    font-size: 14px;            /* Taille de police */\n"
"    font-family: \"Palatino Linotype\"; /* Police \303\251l\303\251gante */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #A52A2A;  /* Bordure plus claire lorsqu'on clique */\n"
"    background-color: #FFFFFF;   /* Fond blanc subtil pour bien montrer le focus */\n"
"}\n"
"\n"
"QLineEdit:disabled {\n"
"    background-color: #D3B8AE;   /* Beige fonc\303\251 pour d\303\251sactiv\303\251 */\n"
"    color: #8B0000;              /* Texte en bordeaux */\n"
"    border: 2px solid #A52A2A;\n"
"}"));
        dateEdit_C_3 = new QDateEdit(tab);
        dateEdit_C_3->setObjectName("dateEdit_C_3");
        dateEdit_C_3->setGeometry(QRect(150, 210, 131, 31));
        dateEdit_C_3->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: #8B0000;             /* Texte en rouge bordeaux */\n"
"    background-color: #F5F5DC;  /* Fond beige */\n"
"    padding: 5px;               /* Espacement int\303\251rieur */\n"
"    border: 2px solid #600000;  /* Bordure bordeaux fonc\303\251 */\n"
"    border-radius: 8px;         /* Coins arrondis */\n"
"    font-size: 14px;            /* Taille de police */\n"
"    font-family: \"Palatino Linotype\"; /* Police \303\251l\303\251gante */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #A52A2A;  /* Bordure plus claire lorsqu'on clique */\n"
"    background-color: #FFFFFF;   /* Fond blanc subtil pour bien montrer le focus */\n"
"}\n"
"\n"
"QLineEdit:disabled {\n"
"    background-color: #D3B8AE;   /* Beige fonc\303\251 pour d\303\251sactiv\303\251 */\n"
"    color: #8B0000;              /* Texte en bordeaux */\n"
"    border: 2px solid #A52A2A;\n"
"}"));
        lineEdit_email = new QLineEdit(tab);
        lineEdit_email->setObjectName("lineEdit_email");
        lineEdit_email->setGeometry(QRect(140, 90, 121, 31));
        lineEdit_email->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: #8B0000;             /* Texte en rouge bordeaux */\n"
"    background-color: #F5F5DC;  /* Fond beige */\n"
"    padding: 5px;               /* Espacement int\303\251rieur */\n"
"    border: 2px solid #600000;  /* Bordure bordeaux fonc\303\251 */\n"
"    border-radius: 8px;         /* Coins arrondis */\n"
"    font-size: 14px;            /* Taille de police */\n"
"    font-family: \"Palatino Linotype\"; /* Police \303\251l\303\251gante */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #A52A2A;  /* Bordure plus claire lorsqu'on clique */\n"
"    background-color: #FFFFFF;   /* Fond blanc subtil pour bien montrer le focus */\n"
"}\n"
"\n"
"QLineEdit:disabled {\n"
"    background-color: #D3B8AE;   /* Beige fonc\303\251 pour d\303\251sactiv\303\251 */\n"
"    color: #8B0000;              /* Texte en bordeaux */\n"
"    border: 2px solid #A52A2A;\n"
"}"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        pushButton_ok = new QPushButton(tab_2);
        pushButton_ok->setObjectName("pushButton_ok");
        pushButton_ok->setGeometry(QRect(250, 10, 61, 31));
        pushButton_ok->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #8B0000;  /* Rouge bordeaux */\n"
"    color: #F5F5DC;              /* Beige pour le texte */\n"
"    border-radius: 10px;         /* Coins arrondis */\n"
"    padding: 8px 15px;           /* Espacement int\303\251rieur */\n"
"    font-size: 8px;             /* Taille de police */\n"
"    font-weight: bold;           /* Police en gras */\n"
"    border: 2px solid #600000;   /* Bordure plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A52A2A;   /* Rouge bordeaux plus clair */\n"
"    border: 2px solid #8B0000;   \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #600000;   /* Rouge bordeaux tr\303\250s fonc\303\251 */\n"
"    border: 2px solid #400000;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #D3B8AE;   /* Beige fonc\303\251 pour d\303\251sactiv\303\251 */\n"
"    color: #8B0000;\n"
"    border: 2px solid #A52A2A;\n"
"}"));
        lineEdit_idU = new QLineEdit(tab_2);
        lineEdit_idU->setObjectName("lineEdit_idU");
        lineEdit_idU->setGeometry(QRect(110, 10, 111, 31));
        lineEdit_idU->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: #8B0000;             /* Texte en rouge bordeaux */\n"
"    background-color: #F5F5DC;  /* Fond beige */\n"
"    padding: 5px;               /* Espacement int\303\251rieur */\n"
"    border: 2px solid #600000;  /* Bordure bordeaux fonc\303\251 */\n"
"    border-radius: 8px;         /* Coins arrondis */\n"
"    font-size: 14px;            /* Taille de police */\n"
"    font-family: \"Palatino Linotype\"; /* Police \303\251l\303\251gante */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #A52A2A;  /* Bordure plus claire lorsqu'on clique */\n"
"    background-color: #FFFFFF;   /* Fond blanc subtil pour bien montrer le focus */\n"
"}\n"
"\n"
"QLineEdit:disabled {\n"
"    background-color: #D3B8AE;   /* Beige fonc\303\251 pour d\303\251sactiv\303\251 */\n"
"    color: #8B0000;              /* Texte en bordeaux */\n"
"    border: 2px solid #A52A2A;\n"
"}"));
        pushButton_modifier = new QPushButton(tab_2);
        pushButton_modifier->setObjectName("pushButton_modifier");
        pushButton_modifier->setGeometry(QRect(110, 270, 131, 41));
        pushButton_modifier->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #8B0000;  /* Rouge bordeaux */\n"
"    color: #F5F5DC;              /* Beige pour le texte */\n"
"    border-radius: 10px;         /* Coins arrondis */\n"
"    padding: 8px 15px;           /* Espacement int\303\251rieur */\n"
"    font-size: 14px;             /* Taille de police */\n"
"    font-weight: bold;           /* Police en gras */\n"
"    border: 2px solid #600000;   /* Bordure plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A52A2A;   /* Rouge bordeaux plus clair */\n"
"    border: 2px solid #8B0000;   \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #600000;   /* Rouge bordeaux tr\303\250s fonc\303\251 */\n"
"    border: 2px solid #400000;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #D3B8AE;   /* Beige fonc\303\251 pour d\303\251sactiv\303\251 */\n"
"    color: #8B0000;\n"
"    border: 2px solid #A52A2A;\n"
"}"));
        label_id_2 = new QLabel(tab_2);
        label_id_2->setObjectName("label_id_2");
        label_id_2->setGeometry(QRect(20, 20, 61, 20));
        label_id_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #EEE4CC; /* Beige doux */\n"
"    color: #600000;            /* Texte bordeaux */\n"
"    font: 900 italic 8pt \"Segoe UI\"; /* Police en italique et gras */\n"
"    border-radius: 8px;         /* Coins arrondis */\n"
"    padding: 4px 8px;           /* Un peu de marge interne */\n"
"    border: 1px solid #8B0000;  /* Fine bordure bordeaux pour les d\303\251marquer */\n"
"}\n"
""));
        label_nom_2 = new QLabel(tab_2);
        label_nom_2->setObjectName("label_nom_2");
        label_nom_2->setGeometry(QRect(20, 50, 91, 21));
        label_nom_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #EEE4CC; /* Beige doux */\n"
"    color: #600000;            /* Texte bordeaux */\n"
"    font: 900 italic 8pt \"Segoe UI\"; /* Police en italique et gras */\n"
"    border-radius: 8px;         /* Coins arrondis */\n"
"    padding: 4px 8px;           /* Un peu de marge interne */\n"
"    border: 1px solid #8B0000;  /* Fine bordure bordeaux pour les d\303\251marquer */\n"
"}\n"
""));
        label_description_2 = new QLabel(tab_2);
        label_description_2->setObjectName("label_description_2");
        label_description_2->setGeometry(QRect(20, 80, 91, 20));
        label_description_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #EEE4CC; /* Beige doux */\n"
"    color: #600000;            /* Texte bordeaux */\n"
"    font: 900 italic 8pt \"Segoe UI\"; /* Police en italique et gras */\n"
"    border-radius: 8px;         /* Coins arrondis */\n"
"    padding: 4px 8px;           /* Un peu de marge interne */\n"
"    border: 1px solid #8B0000;  /* Fine bordure bordeaux pour les d\303\251marquer */\n"
"}\n"
""));
        label_type_2 = new QLabel(tab_2);
        label_type_2->setObjectName("label_type_2");
        label_type_2->setGeometry(QRect(20, 110, 91, 21));
        label_type_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #EEE4CC; /* Beige doux */\n"
"    color: #600000;            /* Texte bordeaux */\n"
"    font: 900 italic 8pt \"Segoe UI\"; /* Police en italique et gras */\n"
"    border-radius: 8px;         /* Coins arrondis */\n"
"    padding: 4px 8px;           /* Un peu de marge interne */\n"
"    border: 1px solid #8B0000;  /* Fine bordure bordeaux pour les d\303\251marquer */\n"
"}\n"
""));
        label_lieu_2 = new QLabel(tab_2);
        label_lieu_2->setObjectName("label_lieu_2");
        label_lieu_2->setGeometry(QRect(20, 140, 101, 21));
        label_lieu_2->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #EEE4CC; /* Beige doux */\n"
"    color: #600000;            /* Texte bordeaux */\n"
"    font: 900 italic 8pt \"Segoe UI\"; /* Police en italique et gras */\n"
"    border-radius: 8px;         /* Coins arrondis */\n"
"    padding: 4px 8px;           /* Un peu de marge interne */\n"
"    border: 1px solid #8B0000;  /* Fine bordure bordeaux pour les d\303\251marquer */\n"
"}\n"
""));
        label_date = new QLabel(tab_2);
        label_date->setObjectName("label_date");
        label_date->setGeometry(QRect(10, 190, 111, 21));
        label_date->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #EEE4CC; /* Beige doux */\n"
"    color: #600000;            /* Texte bordeaux */\n"
"    font: 900 italic 8pt \"Segoe UI\"; /* Police en italique et gras */\n"
"    border-radius: 8px;         /* Coins arrondis */\n"
"    padding: 4px 8px;           /* Un peu de marge interne */\n"
"    border: 1px solid #8B0000;  /* Fine bordure bordeaux pour les d\303\251marquer */\n"
"}\n"
""));
        label_time = new QLabel(tab_2);
        label_time->setObjectName("label_time");
        label_time->setGeometry(QRect(10, 230, 121, 21));
        label_time->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #EEE4CC; /* Beige doux */\n"
"    color: #600000;            /* Texte bordeaux */\n"
"    font: 900 italic 8pt \"Segoe UI\"; /* Police en italique et gras */\n"
"    border-radius: 8px;         /* Coins arrondis */\n"
"    padding: 4px 8px;           /* Un peu de marge interne */\n"
"    border: 1px solid #8B0000;  /* Fine bordure bordeaux pour les d\303\251marquer */\n"
"}\n"
""));
        lineEdit_nom2 = new QLineEdit(tab_2);
        lineEdit_nom2->setObjectName("lineEdit_nom2");
        lineEdit_nom2->setGeometry(QRect(180, 40, 141, 31));
        lineEdit_nom2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: #8B0000;             /* Texte en rouge bordeaux */\n"
"    background-color: #F5F5DC;  /* Fond beige */\n"
"    padding: 5px;               /* Espacement int\303\251rieur */\n"
"    border: 2px solid #600000;  /* Bordure bordeaux fonc\303\251 */\n"
"    border-radius: 8px;         /* Coins arrondis */\n"
"    font-size: 14px;            /* Taille de police */\n"
"    font-family: \"Palatino Linotype\"; /* Police \303\251l\303\251gante */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #A52A2A;  /* Bordure plus claire lorsqu'on clique */\n"
"    background-color: #FFFFFF;   /* Fond blanc subtil pour bien montrer le focus */\n"
"}\n"
"\n"
"QLineEdit:disabled {\n"
"    background-color: #D3B8AE;   /* Beige fonc\303\251 pour d\303\251sactiv\303\251 */\n"
"    color: #8B0000;              /* Texte en bordeaux */\n"
"    border: 2px solid #A52A2A;\n"
"}"));
        lineEdit_adresse2 = new QLineEdit(tab_2);
        lineEdit_adresse2->setObjectName("lineEdit_adresse2");
        lineEdit_adresse2->setGeometry(QRect(180, 70, 141, 31));
        lineEdit_adresse2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: #8B0000;             /* Texte en rouge bordeaux */\n"
"    background-color: #F5F5DC;  /* Fond beige */\n"
"    padding: 5px;               /* Espacement int\303\251rieur */\n"
"    border: 2px solid #600000;  /* Bordure bordeaux fonc\303\251 */\n"
"    border-radius: 8px;         /* Coins arrondis */\n"
"    font-size: 14px;            /* Taille de police */\n"
"    font-family: \"Palatino Linotype\"; /* Police \303\251l\303\251gante */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #A52A2A;  /* Bordure plus claire lorsqu'on clique */\n"
"    background-color: #FFFFFF;   /* Fond blanc subtil pour bien montrer le focus */\n"
"}\n"
"\n"
"QLineEdit:disabled {\n"
"    background-color: #D3B8AE;   /* Beige fonc\303\251 pour d\303\251sactiv\303\251 */\n"
"    color: #8B0000;              /* Texte en bordeaux */\n"
"    border: 2px solid #A52A2A;\n"
"}"));
        lineEdit_telephone2 = new QLineEdit(tab_2);
        lineEdit_telephone2->setObjectName("lineEdit_telephone2");
        lineEdit_telephone2->setGeometry(QRect(180, 140, 141, 31));
        lineEdit_telephone2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: #8B0000;             /* Texte en rouge bordeaux */\n"
"    background-color: #F5F5DC;  /* Fond beige */\n"
"    padding: 5px;               /* Espacement int\303\251rieur */\n"
"    border: 2px solid #600000;  /* Bordure bordeaux fonc\303\251 */\n"
"    border-radius: 8px;         /* Coins arrondis */\n"
"    font-size: 14px;            /* Taille de police */\n"
"    font-family: \"Palatino Linotype\"; /* Police \303\251l\303\251gante */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #A52A2A;  /* Bordure plus claire lorsqu'on clique */\n"
"    background-color: #FFFFFF;   /* Fond blanc subtil pour bien montrer le focus */\n"
"}\n"
"\n"
"QLineEdit:disabled {\n"
"    background-color: #D3B8AE;   /* Beige fonc\303\251 pour d\303\251sactiv\303\251 */\n"
"    color: #8B0000;              /* Texte en bordeaux */\n"
"    border: 2px solid #A52A2A;\n"
"}"));
        dateEdit_debutcontrat2 = new QDateEdit(tab_2);
        dateEdit_debutcontrat2->setObjectName("dateEdit_debutcontrat2");
        dateEdit_debutcontrat2->setGeometry(QRect(180, 180, 151, 31));
        dateEdit_debutcontrat2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: #8B0000;             /* Texte en rouge bordeaux */\n"
"    background-color: #F5F5DC;  /* Fond beige */\n"
"    padding: 5px;               /* Espacement int\303\251rieur */\n"
"    border: 2px solid #600000;  /* Bordure bordeaux fonc\303\251 */\n"
"    border-radius: 8px;         /* Coins arrondis */\n"
"    font-size: 14px;            /* Taille de police */\n"
"    font-family: \"Palatino Linotype\"; /* Police \303\251l\303\251gante */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #A52A2A;  /* Bordure plus claire lorsqu'on clique */\n"
"    background-color: #FFFFFF;   /* Fond blanc subtil pour bien montrer le focus */\n"
"}\n"
"\n"
"QLineEdit:disabled {\n"
"    background-color: #D3B8AE;   /* Beige fonc\303\251 pour d\303\251sactiv\303\251 */\n"
"    color: #8B0000;              /* Texte en bordeaux */\n"
"    border: 2px solid #A52A2A;\n"
"}"));
        dateEdit_debutcontrat2->setDateTime(QDateTime(QDate(2025, 3, 13), QTime(20, 0, 0)));
        dateEdit_fincontrat2 = new QDateEdit(tab_2);
        dateEdit_fincontrat2->setObjectName("dateEdit_fincontrat2");
        dateEdit_fincontrat2->setGeometry(QRect(180, 220, 151, 31));
        dateEdit_fincontrat2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: #8B0000;             /* Texte en rouge bordeaux */\n"
"    background-color: #F5F5DC;  /* Fond beige */\n"
"    padding: 5px;               /* Espacement int\303\251rieur */\n"
"    border: 2px solid #600000;  /* Bordure bordeaux fonc\303\251 */\n"
"    border-radius: 8px;         /* Coins arrondis */\n"
"    font-size: 14px;            /* Taille de police */\n"
"    font-family: \"Palatino Linotype\"; /* Police \303\251l\303\251gante */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #A52A2A;  /* Bordure plus claire lorsqu'on clique */\n"
"    background-color: #FFFFFF;   /* Fond blanc subtil pour bien montrer le focus */\n"
"}\n"
"\n"
"QLineEdit:disabled {\n"
"    background-color: #D3B8AE;   /* Beige fonc\303\251 pour d\303\251sactiv\303\251 */\n"
"    color: #8B0000;              /* Texte en bordeaux */\n"
"    border: 2px solid #A52A2A;\n"
"}"));
        dateEdit_fincontrat2->setDateTime(QDateTime(QDate(2025, 3, 13), QTime(20, 0, 0)));
        lineEdit_Email2 = new QLineEdit(tab_2);
        lineEdit_Email2->setObjectName("lineEdit_Email2");
        lineEdit_Email2->setGeometry(QRect(180, 100, 141, 31));
        lineEdit_Email2->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: #8B0000;             /* Texte en rouge bordeaux */\n"
"    background-color: #F5F5DC;  /* Fond beige */\n"
"    padding: 5px;               /* Espacement int\303\251rieur */\n"
"    border: 2px solid #600000;  /* Bordure bordeaux fonc\303\251 */\n"
"    border-radius: 8px;         /* Coins arrondis */\n"
"    font-size: 14px;            /* Taille de police */\n"
"    font-family: \"Palatino Linotype\"; /* Police \303\251l\303\251gante */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #A52A2A;  /* Bordure plus claire lorsqu'on clique */\n"
"    background-color: #FFFFFF;   /* Fond blanc subtil pour bien montrer le focus */\n"
"}\n"
"\n"
"QLineEdit:disabled {\n"
"    background-color: #D3B8AE;   /* Beige fonc\303\251 pour d\303\251sactiv\303\251 */\n"
"    color: #8B0000;              /* Texte en bordeaux */\n"
"    border: 2px solid #A52A2A;\n"
"}"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        pushButton_supprimer = new QPushButton(tab_3);
        pushButton_supprimer->setObjectName("pushButton_supprimer");
        pushButton_supprimer->setGeometry(QRect(100, 110, 101, 41));
        pushButton_supprimer->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #8B0000;  /* Rouge bordeaux */\n"
"    color: #F5F5DC;              /* Beige pour le texte */\n"
"    border-radius: 10px;         /* Coins arrondis */\n"
"    padding: 8px 15px;           /* Espacement int\303\251rieur */\n"
"    font-size: 14px;             /* Taille de police */\n"
"    font-weight: bold;           /* Police en gras */\n"
"    border: 2px solid #600000;   /* Bordure plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A52A2A;   /* Rouge bordeaux plus clair */\n"
"    border: 2px solid #8B0000;   \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #600000;   /* Rouge bordeaux tr\303\250s fonc\303\251 */\n"
"    border: 2px solid #400000;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #D3B8AE;   /* Beige fonc\303\251 pour d\303\251sactiv\303\251 */\n"
"    color: #8B0000;\n"
"    border: 2px solid #A52A2A;\n"
"}"));
        label_id_3 = new QLabel(tab_3);
        label_id_3->setObjectName("label_id_3");
        label_id_3->setGeometry(QRect(30, 70, 91, 21));
        label_id_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    background-color: #EEE4CC; /* Beige doux */\n"
"    color: #600000;            /* Texte bordeaux */\n"
"    font: 900 italic 12pt \"Segoe UI\"; /* Police en italique et gras */\n"
"    border-radius: 8px;         /* Coins arrondis */\n"
"    padding: 4px 8px;           /* Un peu de marge interne */\n"
"    border: 1px solid #8B0000;  /* Fine bordure bordeaux pour les d\303\251marquer */\n"
"}\n"
""));
        lineEdit_id3 = new QLineEdit(tab_3);
        lineEdit_id3->setObjectName("lineEdit_id3");
        lineEdit_id3->setGeometry(QRect(150, 60, 71, 31));
        lineEdit_id3->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: #8B0000;             /* Texte en rouge bordeaux */\n"
"    background-color: #F5F5DC;  /* Fond beige */\n"
"    padding: 5px;               /* Espacement int\303\251rieur */\n"
"    border: 2px solid #600000;  /* Bordure bordeaux fonc\303\251 */\n"
"    border-radius: 8px;         /* Coins arrondis */\n"
"    font-size: 14px;            /* Taille de police */\n"
"    font-family: \"Palatino Linotype\"; /* Police \303\251l\303\251gante */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #A52A2A;  /* Bordure plus claire lorsqu'on clique */\n"
"    background-color: #FFFFFF;   /* Fond blanc subtil pour bien montrer le focus */\n"
"}\n"
"\n"
"QLineEdit:disabled {\n"
"    background-color: #D3B8AE;   /* Beige fonc\303\251 pour d\303\251sactiv\303\251 */\n"
"    color: #8B0000;              /* Texte en bordeaux */\n"
"    border: 2px solid #A52A2A;\n"
"}"));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        pushButton_telecharger_2 = new QPushButton(tab_4);
        pushButton_telecharger_2->setObjectName("pushButton_telecharger_2");
        pushButton_telecharger_2->setGeometry(QRect(200, 60, 121, 51));
        pushButton_telecharger_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #8B0000;  /* Rouge bordeaux */\n"
"    color: #F5F5DC;              /* Beige pour le texte */\n"
"    border-radius: 10px;         /* Coins arrondis */\n"
"    padding: 8px 15px;           /* Espacement int\303\251rieur */\n"
"    font-size: 14px;             /* Taille de police */\n"
"    font-weight: bold;           /* Police en gras */\n"
"    border: 2px solid #600000;   /* Bordure plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A52A2A;   /* Rouge bordeaux plus clair */\n"
"    border: 2px solid #8B0000;   \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #600000;   /* Rouge bordeaux tr\303\250s fonc\303\251 */\n"
"    border: 2px solid #400000;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #D3B8AE;   /* Beige fonc\303\251 pour d\303\251sactiv\303\251 */\n"
"    color: #8B0000;\n"
"    border: 2px solid #A52A2A;\n"
"}"));
        lineEdit_id4 = new QLineEdit(tab_4);
        lineEdit_id4->setObjectName("lineEdit_id4");
        lineEdit_id4->setGeometry(QRect(20, 70, 161, 31));
        lineEdit_id4->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    color: #8B0000;             /* Texte en rouge bordeaux */\n"
"    background-color: #F5F5DC;  /* Fond beige */\n"
"    padding: 5px;               /* Espacement int\303\251rieur */\n"
"    border: 2px solid #600000;  /* Bordure bordeaux fonc\303\251 */\n"
"    border-radius: 8px;         /* Coins arrondis */\n"
"    font-size: 14px;            /* Taille de police */\n"
"    font-family: \"Palatino Linotype\"; /* Police \303\251l\303\251gante */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #A52A2A;  /* Bordure plus claire lorsqu'on clique */\n"
"    background-color: #FFFFFF;   /* Fond blanc subtil pour bien montrer le focus */\n"
"}\n"
"\n"
"QLineEdit:disabled {\n"
"    background-color: #D3B8AE;   /* Beige fonc\303\251 pour d\303\251sactiv\303\251 */\n"
"    color: #8B0000;              /* Texte en bordeaux */\n"
"    border: 2px solid #A52A2A;\n"
"}"));
        pushButton_mailing = new QPushButton(tab_4);
        pushButton_mailing->setObjectName("pushButton_mailing");
        pushButton_mailing->setGeometry(QRect(60, 170, 161, 41));
        pushButton_mailing->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #8B0000;  /* Rouge bordeaux */\n"
"    color: #F5F5DC;              /* Beige pour le texte */\n"
"    border-radius: 10px;         /* Coins arrondis */\n"
"    padding: 8px 15px;           /* Espacement int\303\251rieur */\n"
"    font-size: 14px;             /* Taille de police */\n"
"    font-weight: bold;           /* Police en gras */\n"
"    border: 2px solid #600000;   /* Bordure plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A52A2A;   /* Rouge bordeaux plus clair */\n"
"    border: 2px solid #8B0000;   \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #600000;   /* Rouge bordeaux tr\303\250s fonc\303\251 */\n"
"    border: 2px solid #400000;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #D3B8AE;   /* Beige fonc\303\251 pour d\303\251sactiv\303\251 */\n"
"    color: #8B0000;\n"
"    border: 2px solid #A52A2A;\n"
"}"));
        tabWidget->addTab(tab_4, QString());
        label_5 = new QLabel(main_body_contents);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(610, 80, 481, 31));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(86, 1, 38);\n"
"font: 900 italic 10pt \"Segoe UI\";"));
        pushButton_triedate = new QPushButton(main_body_contents);
        pushButton_triedate->setObjectName("pushButton_triedate");
        pushButton_triedate->setGeometry(QRect(600, 140, 151, 31));
        pushButton_triedate->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #8B0000;  /* Rouge bordeaux */\n"
"    color: #F5F5DC;              /* Beige pour le texte */\n"
"    border-radius: 10px;         /* Coins arrondis */\n"
"    padding: 8px 15px;           /* Espacement int\303\251rieur */\n"
"    font-size: 14px;             /* Taille de police */\n"
"    font-weight: bold;           /* Police en gras */\n"
"    border: 2px solid #600000;   /* Bordure plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A52A2A;   /* Rouge bordeaux plus clair */\n"
"    border: 2px solid #8B0000;   \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #600000;   /* Rouge bordeaux tr\303\250s fonc\303\251 */\n"
"    border: 2px solid #400000;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #D3B8AE;   /* Beige fonc\303\251 pour d\303\251sactiv\303\251 */\n"
"    color: #8B0000;\n"
"    border: 2px solid #A52A2A;\n"
"}"));
        pushButton_trieid = new QPushButton(main_body_contents);
        pushButton_trieid->setObjectName("pushButton_trieid");
        pushButton_trieid->setGeometry(QRect(840, 140, 141, 31));
        pushButton_trieid->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #8B0000;  /* Rouge bordeaux */\n"
"    color: #F5F5DC;              /* Beige pour le texte */\n"
"    border-radius: 10px;         /* Coins arrondis */\n"
"    padding: 8px 15px;           /* Espacement int\303\251rieur */\n"
"    font-size: 14px;             /* Taille de police */\n"
"    font-weight: bold;           /* Police en gras */\n"
"    border: 2px solid #600000;   /* Bordure plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A52A2A;   /* Rouge bordeaux plus clair */\n"
"    border: 2px solid #8B0000;   \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #600000;   /* Rouge bordeaux tr\303\250s fonc\303\251 */\n"
"    border: 2px solid #400000;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #D3B8AE;   /* Beige fonc\303\251 pour d\303\251sactiv\303\251 */\n"
"    color: #8B0000;\n"
"    border: 2px solid #A52A2A;\n"
"}"));
        tableView = new QTableView(main_body_contents);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(510, 200, 511, 291));
        tableView->setStyleSheet(QString::fromUtf8("QTableView {\n"
"    background-color: #FAF0E6; /* Fond beige */\n"
"    border: 2px solid #8B0000;  /* Bordure bordeaux */\n"
"    border-radius: 8px;\n"
"    font-size: 14px;\n"
"    font-family: \"Palatino Linotype\";\n"
"}\n"
"\n"
"QTableView::item {\n"
"    padding: 5px;\n"
"    border: 1px solid #8B0000;  /* Bordure autour des cellules */\n"
"    border-radius: 5px;\n"
"    color: #600000;  /* Texte bordeaux */\n"
"}\n"
"\n"
"QTableView::item:selected {\n"
"    background-color: #EDE0D4; /* Beige plus fonc\303\251 pour la cellule s\303\251lectionn\303\251e */\n"
"    color: #600000;             /* Texte bordeaux */\n"
"}\n"
"\n"
"QTableView::item:hover {\n"
"    background-color: #D2B48C;  /* Beige dor\303\251 pour l'\303\251l\303\251ment survol\303\251 */\n"
"    color: #600000;              /* Texte bordeaux */\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #F5F5DC;  /* Fond beige clair pour les en-t\303\252tes */\n"
"    color: #600000;              /* Texte bordeaux */\n"
"    paddin"
                        "g: 5px;\n"
"    border: 1px solid #8B0000;   /* Bordure de l\342\200\231en-t\303\252te */\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QHeaderView::section::horizontal {\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QTableView::indicator:checked {\n"
"    background-color: #8B0000;  /* Bordure ou fond de la case \303\240 cocher */\n"
"}"));
        pushButton_afficherStats = new QPushButton(main_body_contents);
        pushButton_afficherStats->setObjectName("pushButton_afficherStats");
        pushButton_afficherStats->setGeometry(QRect(110, 590, 131, 31));
        pushButton_afficherStats->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #8B0000;  /* Rouge bordeaux */\n"
"    color: #F5F5DC;              /* Beige pour le texte */\n"
"    border-radius: 10px;         /* Coins arrondis */\n"
"    padding: 8px 15px;           /* Espacement int\303\251rieur */\n"
"    font-size: 14px;             /* Taille de police */\n"
"    font-weight: bold;           /* Police en gras */\n"
"    border: 2px solid #600000;   /* Bordure plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A52A2A;   /* Rouge bordeaux plus clair */\n"
"    border: 2px solid #8B0000;   \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #600000;   /* Rouge bordeaux tr\303\250s fonc\303\251 */\n"
"    border: 2px solid #400000;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #D3B8AE;   /* Beige fonc\303\251 pour d\303\251sactiv\303\251 */\n"
"    color: #8B0000;\n"
"    border: 2px solid #A52A2A;\n"
"}"));
        chatDisplay = new QTextEdit(main_body_contents);
        chatDisplay->setObjectName("chatDisplay");
        chatDisplay->setGeometry(QRect(510, 500, 511, 161));
        chatDisplay->setStyleSheet(QString::fromUtf8("\n"
"QTextEdit {\n"
"    background-color: #FAF0E6; /* Fond beige */\n"
"    border: 2px solid #8B0000; /* Bordure bordeaux */\n"
"    border-radius: 8px;\n"
"    font-size: 14px;\n"
"    font-family: \"Palatino Linotype\";\n"
"    padding: 5px;\n"
"    color: #600000; /* Texte bordeaux */\n"
"}\n"
"\n"
"QTextEdit:hover {\n"
"    background-color: #D2B48C; /* Beige dor\303\251 au survol */\n"
"}\n"
"\n"
"QTextEdit:focus {\n"
"    background-color: #EDE0D4; /* Beige plus fonc\303\251 lorsqu'il est actif */\n"
"    border: 2px solid #600000; /* Bordure accentu\303\251e */\n"
"}\n"
"\n"
"\n"
""));
        sendChatMessage = new QPushButton(main_body_contents);
        sendChatMessage->setObjectName("sendChatMessage");
        sendChatMessage->setGeometry(QRect(870, 680, 158, 41));
        sendChatMessage->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background-color: #8B0000;  /* Rouge bordeaux */\n"
"    color: #F5F5DC;              /* Beige pour le texte */\n"
"    border-radius: 10px;         /* Coins arrondis */\n"
"    padding: 8px 15px;           /* Espacement int\303\251rieur */\n"
"    font-size: 14px;             /* Taille de police */\n"
"    font-weight: bold;           /* Police en gras */\n"
"    border: 2px solid #600000;   /* Bordure plus fonc\303\251e */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #A52A2A;   /* Rouge bordeaux plus clair */\n"
"    border: 2px solid #8B0000;   \n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #600000;   /* Rouge bordeaux tr\303\250s fonc\303\251 */\n"
"    border: 2px solid #400000;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #D3B8AE;   /* Beige fonc\303\251 pour d\303\251sactiv\303\251 */\n"
"    color: #8B0000;\n"
"    border: 2px solid #A52A2A;\n"
"}"));
        chatInput = new QLineEdit(main_body_contents);
        chatInput->setObjectName("chatInput");
        chatInput->setGeometry(QRect(550, 680, 311, 41));
        chatInput->setStyleSheet(QString::fromUtf8("\n"
"QLineEdit {\n"
"    background-color: #F5F5DC; /* Fond beige clair */\n"
"    border: 2px solid #8B0000; /* Bordure bordeaux */\n"
"    border-radius: 6px;\n"
"    font-size: 14px;\n"
"    font-family: \"Palatino Linotype\";\n"
"    padding: 3px;\n"
"    color: #600000; /* Texte bordeaux */\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    background-color: #D2B48C; /* Beige dor\303\251 au survol */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    background-color: #EDE0D4; /* Beige plus fonc\303\251 lorsqu'il est actif */\n"
"    border: 2px solid #600000; /* Bordure accentu\303\251e */\n"
"}\n"
"\n"
""));

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


        horizontalLayout_8->addWidget(main_body);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        toolBox->setCurrentIndex(1);
        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "LUXBRAND", nullptr));
        label_3->setText(QString());
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "Employes", nullptr));
        pushButton_13->setText(QCoreApplication::translate("MainWindow", "Locataires", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "Locaux commerciaux", nullptr));
        pushButton_17->setText(QCoreApplication::translate("MainWindow", "Evenements", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "Maintenance", nullptr));
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "Services", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("MainWindow", "Menu 1", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "Log out", nullptr));
        pushButton_14->setText(QCoreApplication::translate("MainWindow", "besoin d'aide ", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("MainWindow", "Menu 2", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "EXIT", nullptr));
        pushButton_8->setText(QString());
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "search", nullptr));
        pushButton_6->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        pushButton_3->setText(QString());
        label_nomApp->setText(QCoreApplication::translate("MainWindow", "Gestion des Locataires", nullptr));
        pushButton_noti->setText(QString());
        label_nom->setText(QCoreApplication::translate("MainWindow", "  Nom", nullptr));
        label_description->setText(QCoreApplication::translate("MainWindow", "Adresse", nullptr));
        label_type->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        label_lieu->setText(QCoreApplication::translate("MainWindow", "Telephone", nullptr));
        lineEdit_telephone->setText(QString());
        lineEdit_adresse->setText(QString());
        lineEdit_nom->setText(QString());
        pushButton_ajouter->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        label_heure->setText(QCoreApplication::translate("MainWindow", "fin contrat", nullptr));
        label_dateC->setText(QCoreApplication::translate("MainWindow", "debut contrat ", nullptr));
        lineEdit_email->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        pushButton_ok->setText(QCoreApplication::translate("MainWindow", "OK", nullptr));
        lineEdit_idU->setText(QString());
        pushButton_modifier->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        label_id_2->setText(QCoreApplication::translate("MainWindow", "  ID", nullptr));
        label_nom_2->setText(QCoreApplication::translate("MainWindow", "  Nom", nullptr));
        label_description_2->setText(QCoreApplication::translate("MainWindow", "Adresse", nullptr));
        label_type_2->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        label_lieu_2->setText(QCoreApplication::translate("MainWindow", "Telephone", nullptr));
        label_date->setText(QCoreApplication::translate("MainWindow", "  Debut Contrat", nullptr));
        label_time->setText(QCoreApplication::translate("MainWindow", "Fin Contrat", nullptr));
        lineEdit_nom2->setText(QString());
        lineEdit_adresse2->setText(QString());
        lineEdit_telephone2->setText(QString());
        lineEdit_Email2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Mise a Jour", nullptr));
        pushButton_supprimer->setText(QCoreApplication::translate("MainWindow", "supprimer", nullptr));
        label_id_3->setText(QCoreApplication::translate("MainWindow", "  ID", nullptr));
        lineEdit_id3->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        pushButton_telecharger_2->setText(QCoreApplication::translate("MainWindow", "telecharger", nullptr));
        pushButton_mailing->setText(QCoreApplication::translate("MainWindow", "contrat par mail", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "Telecharger contrat", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Tableau de locataires nouvellement ajout\303\251s :", nullptr));
        pushButton_triedate->setText(QCoreApplication::translate("MainWindow", "debut de contrat ", nullptr));
        pushButton_trieid->setText(QCoreApplication::translate("MainWindow", "ID locataire", nullptr));
        pushButton_afficherStats->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        sendChatMessage->setText(QCoreApplication::translate("MainWindow", "envoyer", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Modern UI v 7.7.7", nullptr));
        pushButton_7->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
