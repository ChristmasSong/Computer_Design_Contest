/********************************************************************************
** Form generated from reading UI file 'professional.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROFESSIONAL_H
#define UI_PROFESSIONAL_H

#include <Clickedlabel.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_Professional
{
public:
    QAction *restart;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab_professional;
    QLabel *prompt;
    QPushButton *add;
    QLabel *pic_show;
    QLabel *r_label;
    QLineEdit *c_value;
    QLineEdit *cal_rgb;
    QLabel *c_label;
    QCustomPlot *show;
    QLabel *v1;
    QLabel *RGB_Parameter;
    QLabel *v6;
    QLabel *mol_unknown;
    QLabel *v3;
    QLabel *mol2;
    QLabel *rgb_value;
    QLabel *mol5;
    QPushButton *fit;
    QLabel *rgb_label;
    QScrollArea *img_pre_area;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    ClickedLabel *pic6;
    ClickedLabel *pic1;
    ClickedLabel *pic7;
    ClickedLabel *pic3;
    ClickedLabel *pic5;
    ClickedLabel *pic4;
    ClickedLabel *pic2;
    QLabel *pic1_mol;
    QLabel *pic2_mol;
    QLabel *pic3_mol;
    QLabel *pic4_mol;
    QLabel *pic5_mol;
    QLabel *pic6_mol;
    QLabel *pic7_mol;
    QLabel *cal_show;
    QLabel *r_value;
    QLabel *v2;
    QLabel *mol3;
    QLabel *g_value;
    QLabel *b_value;
    QLabel *v4;
    QLabel *mol_Parameter;
    QLabel *mol4;
    QLabel *mol1;
    QLabel *v5;
    QLabel *rgb_unknown;
    QLabel *p1;
    QLabel *g_label;
    QLabel *mol6;
    QLabel *b_label;
    QLabel *p2;
    QLabel *cal_mol;
    QTextBrowser *formula;
    QWidget *tab_fast;
    ClickedLabel *pic;
    QWidget *widget_solutions_RGB;
    QGridLayout *gridLayout_4;
    QLabel *r_value_fast;
    QLabel *b_value_fast;
    QLabel *g_value_fast;
    QLabel *r_label_fast;
    QLabel *g_label_fast;
    QLabel *b_label_fast;
    QGroupBox *groupBox_solutions_type;
    QWidget *layoutWidget;
    QGridLayout *gridLayout_2;
    QRadioButton *radioButton_CoSO4;
    QRadioButton *radioButton_CuSO4;
    QRadioButton *radioButton_NiSO4;
    QLabel *rgb_value_fast;
    QLabel *rgb_label_fast;
    QPushButton *pushButton_compute;
    QCustomPlot *show_fast;
    QLabel *label_fast;
    QLabel *label_mol_fast;
    QLabel *label_fast_2;
    QLabel *formula_fast;
    QMenuBar *menuBar;
    QMenu *menu;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Professional)
    {
        if (Professional->objectName().isEmpty())
            Professional->setObjectName(QString::fromUtf8("Professional"));
        Professional->resize(1178, 850);
        Professional->setMaximumSize(QSize(1200, 850));
        restart = new QAction(Professional);
        restart->setObjectName(QString::fromUtf8("restart"));
        restart->setCheckable(true);
        centralWidget = new QWidget(Professional);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1191, 831));
        tab_professional = new QWidget();
        tab_professional->setObjectName(QString::fromUtf8("tab_professional"));
        prompt = new QLabel(tab_professional);
        prompt->setObjectName(QString::fromUtf8("prompt"));
        prompt->setGeometry(QRect(900, 370, 101, 16));
        prompt->setStyleSheet(QString::fromUtf8("font: 10pt \"\345\256\213\344\275\223\";\n"
"color:rgb(255, 0, 0)"));
        add = new QPushButton(tab_professional);
        add->setObjectName(QString::fromUtf8("add"));
        add->setGeometry(QRect(1060, 331, 80, 30));
        add->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\256\213\344\275\223\";"));
        pic_show = new QLabel(tab_professional);
        pic_show->setObjectName(QString::fromUtf8("pic_show"));
        pic_show->setGeometry(QRect(20, 10, 471, 251));
        pic_show->setStyleSheet(QString::fromUtf8("border:1px solid;\n"
"border-color: rgb(200, 200, 197);\n"
"background-color: rgb(247, 247, 247);\n"
"font: 72pt \"Arial\";"));
        r_label = new QLabel(tab_professional);
        r_label->setObjectName(QString::fromUtf8("r_label"));
        r_label->setGeometry(QRect(590, 100, 41, 20));
        r_label->setStyleSheet(QString::fromUtf8("font: 12pt \"Times New Roman\";\n"
"color:rgb(232, 0, 0);"));
        c_value = new QLineEdit(tab_professional);
        c_value->setObjectName(QString::fromUtf8("c_value"));
        c_value->setGeometry(QRect(900, 330, 111, 31));
        cal_rgb = new QLineEdit(tab_professional);
        cal_rgb->setObjectName(QString::fromUtf8("cal_rgb"));
        cal_rgb->setGeometry(QRect(900, 400, 111, 31));
        c_label = new QLabel(tab_professional);
        c_label->setObjectName(QString::fromUtf8("c_label"));
        c_label->setGeometry(QRect(790, 330, 101, 31));
        c_label->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\256\213\344\275\223\";"));
        show = new QCustomPlot(tab_professional);
        show->setObjectName(QString::fromUtf8("show"));
        show->setGeometry(QRect(10, 390, 481, 381));
        show->setStyleSheet(QString::fromUtf8("border:1px solid;\n"
"border-color: rgb(200, 200, 197);\n"
"background-color: rgb(230, 230, 230);\n"
"font: 72pt \"\345\256\213\344\275\223\";"));
        v1 = new QLabel(tab_professional);
        v1->setObjectName(QString::fromUtf8("v1"));
        v1->setGeometry(QRect(710, 500, 121, 20));
        RGB_Parameter = new QLabel(tab_professional);
        RGB_Parameter->setObjectName(QString::fromUtf8("RGB_Parameter"));
        RGB_Parameter->setGeometry(QRect(710, 450, 161, 31));
        RGB_Parameter->setStyleSheet(QString::fromUtf8("font: 12pt \"Times New Roman\";\n"
""));
        v6 = new QLabel(tab_professional);
        v6->setObjectName(QString::fromUtf8("v6"));
        v6->setGeometry(QRect(710, 650, 121, 20));
        mol_unknown = new QLabel(tab_professional);
        mol_unknown->setObjectName(QString::fromUtf8("mol_unknown"));
        mol_unknown->setGeometry(QRect(800, 690, 101, 31));
        mol_unknown->setStyleSheet(QString::fromUtf8("font: 12pt \"Times New Roman\";\n"
""));
        v3 = new QLabel(tab_professional);
        v3->setObjectName(QString::fromUtf8("v3"));
        v3->setGeometry(QRect(710, 560, 121, 20));
        mol2 = new QLabel(tab_professional);
        mol2->setObjectName(QString::fromUtf8("mol2"));
        mol2->setGeometry(QRect(930, 530, 121, 20));
        rgb_value = new QLabel(tab_professional);
        rgb_value->setObjectName(QString::fromUtf8("rgb_value"));
        rgb_value->setGeometry(QRect(650, 331, 91, 30));
        rgb_value->setStyleSheet(QString::fromUtf8("border:1px solid;\n"
"border-color: rgb(0, 0, 0);"));
        mol5 = new QLabel(tab_professional);
        mol5->setObjectName(QString::fromUtf8("mol5"));
        mol5->setGeometry(QRect(930, 620, 121, 20));
        fit = new QPushButton(tab_professional);
        fit->setObjectName(QString::fromUtf8("fit"));
        fit->setEnabled(false);
        fit->setGeometry(QRect(550, 550, 101, 41));
        fit->setStyleSheet(QString::fromUtf8("font: 12pt \"Times New Roman\";\n"
""));
        rgb_label = new QLabel(tab_professional);
        rgb_label->setObjectName(QString::fromUtf8("rgb_label"));
        rgb_label->setGeometry(QRect(570, 331, 60, 31));
        rgb_label->setStyleSheet(QString::fromUtf8("font: 12pt \"Times New Roman\";"));
        img_pre_area = new QScrollArea(tab_professional);
        img_pre_area->setObjectName(QString::fromUtf8("img_pre_area"));
        img_pre_area->setGeometry(QRect(20, 270, 471, 111));
        img_pre_area->setStyleSheet(QString::fromUtf8("background-color: rgb(247, 247, 247);\n"
""));
        img_pre_area->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        img_pre_area->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        img_pre_area->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 469, 109));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pic6 = new ClickedLabel(scrollAreaWidgetContents);
        pic6->setObjectName(QString::fromUtf8("pic6"));
        pic6->setCursor(QCursor(Qt::PointingHandCursor));
        pic6->setStyleSheet(QString::fromUtf8("border:1px solid;\n"
"border-color: rgb(200, 200, 197);"));

        gridLayout->addWidget(pic6, 0, 5, 1, 1);

        pic1 = new ClickedLabel(scrollAreaWidgetContents);
        pic1->setObjectName(QString::fromUtf8("pic1"));
        pic1->setCursor(QCursor(Qt::PointingHandCursor));
        pic1->setStyleSheet(QString::fromUtf8("border:1px solid;\n"
"border-color: rgb(200, 200, 197);"));

        gridLayout->addWidget(pic1, 0, 0, 1, 1);

        pic7 = new ClickedLabel(scrollAreaWidgetContents);
        pic7->setObjectName(QString::fromUtf8("pic7"));
        pic7->setCursor(QCursor(Qt::PointingHandCursor));
        pic7->setStyleSheet(QString::fromUtf8("border:1px solid;\n"
"border-color: rgb(200, 200, 197);"));

        gridLayout->addWidget(pic7, 0, 6, 1, 1);

        pic3 = new ClickedLabel(scrollAreaWidgetContents);
        pic3->setObjectName(QString::fromUtf8("pic3"));
        pic3->setCursor(QCursor(Qt::PointingHandCursor));
        pic3->setStyleSheet(QString::fromUtf8("border:1px solid;\n"
"border-color: rgb(200, 200, 197);"));

        gridLayout->addWidget(pic3, 0, 2, 1, 1);

        pic5 = new ClickedLabel(scrollAreaWidgetContents);
        pic5->setObjectName(QString::fromUtf8("pic5"));
        pic5->setCursor(QCursor(Qt::PointingHandCursor));
        pic5->setStyleSheet(QString::fromUtf8("border:1px solid;\n"
"border-color: rgb(200, 200, 197);"));

        gridLayout->addWidget(pic5, 0, 4, 1, 1);

        pic4 = new ClickedLabel(scrollAreaWidgetContents);
        pic4->setObjectName(QString::fromUtf8("pic4"));
        pic4->setCursor(QCursor(Qt::PointingHandCursor));
        pic4->setStyleSheet(QString::fromUtf8("border:1px solid;\n"
"border-color: rgb(200, 200, 197);"));

        gridLayout->addWidget(pic4, 0, 3, 1, 1);

        pic2 = new ClickedLabel(scrollAreaWidgetContents);
        pic2->setObjectName(QString::fromUtf8("pic2"));
        pic2->setCursor(QCursor(Qt::PointingHandCursor));
        pic2->setStyleSheet(QString::fromUtf8("border:1px solid;\n"
"border-color: rgb(200, 200, 197);"));

        gridLayout->addWidget(pic2, 0, 1, 1, 1);

        pic1_mol = new QLabel(scrollAreaWidgetContents);
        pic1_mol->setObjectName(QString::fromUtf8("pic1_mol"));

        gridLayout->addWidget(pic1_mol, 1, 0, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        pic2_mol = new QLabel(scrollAreaWidgetContents);
        pic2_mol->setObjectName(QString::fromUtf8("pic2_mol"));

        gridLayout->addWidget(pic2_mol, 1, 1, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        pic3_mol = new QLabel(scrollAreaWidgetContents);
        pic3_mol->setObjectName(QString::fromUtf8("pic3_mol"));

        gridLayout->addWidget(pic3_mol, 1, 2, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        pic4_mol = new QLabel(scrollAreaWidgetContents);
        pic4_mol->setObjectName(QString::fromUtf8("pic4_mol"));

        gridLayout->addWidget(pic4_mol, 1, 3, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        pic5_mol = new QLabel(scrollAreaWidgetContents);
        pic5_mol->setObjectName(QString::fromUtf8("pic5_mol"));

        gridLayout->addWidget(pic5_mol, 1, 4, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        pic6_mol = new QLabel(scrollAreaWidgetContents);
        pic6_mol->setObjectName(QString::fromUtf8("pic6_mol"));

        gridLayout->addWidget(pic6_mol, 1, 5, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        pic7_mol = new QLabel(scrollAreaWidgetContents);
        pic7_mol->setObjectName(QString::fromUtf8("pic7_mol"));

        gridLayout->addWidget(pic7_mol, 1, 6, 1, 1, Qt::AlignHCenter|Qt::AlignVCenter);

        img_pre_area->setWidget(scrollAreaWidgetContents);
        cal_show = new QLabel(tab_professional);
        cal_show->setObjectName(QString::fromUtf8("cal_show"));
        cal_show->setGeometry(QRect(820, 20, 291, 291));
        cal_show->setStyleSheet(QString::fromUtf8("border:1px solid;\n"
"border-color: rgb(200, 200, 197);\n"
"background-color: rgb(247, 247, 247);\n"
""));
        r_value = new QLabel(tab_professional);
        r_value->setObjectName(QString::fromUtf8("r_value"));
        r_value->setGeometry(QRect(630, 90, 91, 31));
        r_value->setStyleSheet(QString::fromUtf8("border:1px solid;\n"
"border-color:rgb(232, 0, 0);"));
        r_value->setMargin(0);
        v2 = new QLabel(tab_professional);
        v2->setObjectName(QString::fromUtf8("v2"));
        v2->setGeometry(QRect(710, 530, 121, 20));
        mol3 = new QLabel(tab_professional);
        mol3->setObjectName(QString::fromUtf8("mol3"));
        mol3->setGeometry(QRect(930, 560, 121, 20));
        g_value = new QLabel(tab_professional);
        g_value->setObjectName(QString::fromUtf8("g_value"));
        g_value->setGeometry(QRect(630, 210, 91, 31));
        g_value->setStyleSheet(QString::fromUtf8("border:1px solid;\n"
"border-color: rgb(0, 223, 0);"));
        b_value = new QLabel(tab_professional);
        b_value->setObjectName(QString::fromUtf8("b_value"));
        b_value->setGeometry(QRect(630, 149, 91, 31));
        b_value->setStyleSheet(QString::fromUtf8("border:1px solid;\n"
"border-color: rgb(0, 0, 241);"));
        v4 = new QLabel(tab_professional);
        v4->setObjectName(QString::fromUtf8("v4"));
        v4->setGeometry(QRect(710, 590, 121, 20));
        mol_Parameter = new QLabel(tab_professional);
        mol_Parameter->setObjectName(QString::fromUtf8("mol_Parameter"));
        mol_Parameter->setGeometry(QRect(930, 450, 161, 31));
        mol_Parameter->setStyleSheet(QString::fromUtf8("font: 12pt \"Times New Roman\";\n"
""));
        mol4 = new QLabel(tab_professional);
        mol4->setObjectName(QString::fromUtf8("mol4"));
        mol4->setGeometry(QRect(930, 590, 121, 20));
        mol1 = new QLabel(tab_professional);
        mol1->setObjectName(QString::fromUtf8("mol1"));
        mol1->setGeometry(QRect(930, 500, 121, 20));
        v5 = new QLabel(tab_professional);
        v5->setObjectName(QString::fromUtf8("v5"));
        v5->setGeometry(QRect(710, 620, 121, 20));
        rgb_unknown = new QLabel(tab_professional);
        rgb_unknown->setObjectName(QString::fromUtf8("rgb_unknown"));
        rgb_unknown->setGeometry(QRect(740, 400, 171, 31));
        rgb_unknown->setStyleSheet(QString::fromUtf8("font: 12pt \"Times New Roman\";\n"
""));
        p1 = new QLabel(tab_professional);
        p1->setObjectName(QString::fromUtf8("p1"));
        p1->setGeometry(QRect(700, 490, 141, 181));
        p1->setStyleSheet(QString::fromUtf8("border:1px solid;\n"
"border-color: rgb(200, 200, 197);\n"
"background-color: rgb(247, 247, 247);\n"
""));
        g_label = new QLabel(tab_professional);
        g_label->setObjectName(QString::fromUtf8("g_label"));
        g_label->setGeometry(QRect(590, 220, 41, 20));
        g_label->setStyleSheet(QString::fromUtf8("font: 12pt \"Times New Roman\";\n"
"color: rgb(0, 223, 0);"));
        mol6 = new QLabel(tab_professional);
        mol6->setObjectName(QString::fromUtf8("mol6"));
        mol6->setGeometry(QRect(930, 650, 121, 20));
        b_label = new QLabel(tab_professional);
        b_label->setObjectName(QString::fromUtf8("b_label"));
        b_label->setGeometry(QRect(590, 160, 41, 20));
        b_label->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Times New Roman\";\n"
"color:rgb(0, 0, 241);\n"
""));
        p2 = new QLabel(tab_professional);
        p2->setObjectName(QString::fromUtf8("p2"));
        p2->setGeometry(QRect(920, 490, 141, 181));
        p2->setStyleSheet(QString::fromUtf8("border:1px solid;\n"
"border-color: rgb(200, 200, 197);\n"
"background-color: rgb(247, 247, 247);\n"
""));
        cal_mol = new QLabel(tab_professional);
        cal_mol->setObjectName(QString::fromUtf8("cal_mol"));
        cal_mol->setGeometry(QRect(930, 690, 91, 31));
        cal_mol->setStyleSheet(QString::fromUtf8("border:1px solid;\n"
"border-color: rgb(0, 0, 0);\n"
"background-color: rgb(247, 247, 247);\n"
""));
        formula = new QTextBrowser(tab_professional);
        formula->setObjectName(QString::fromUtf8("formula"));
        formula->setGeometry(QRect(520, 690, 231, 31));
        formula->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 230, 230);"));
        tabWidget->addTab(tab_professional, QString());
        p2->raise();
        prompt->raise();
        add->raise();
        pic_show->raise();
        r_label->raise();
        c_value->raise();
        cal_rgb->raise();
        c_label->raise();
        show->raise();
        RGB_Parameter->raise();
        mol_unknown->raise();
        mol2->raise();
        rgb_value->raise();
        mol5->raise();
        fit->raise();
        rgb_label->raise();
        img_pre_area->raise();
        cal_show->raise();
        r_value->raise();
        mol3->raise();
        g_value->raise();
        b_value->raise();
        mol_Parameter->raise();
        mol4->raise();
        mol1->raise();
        rgb_unknown->raise();
        p1->raise();
        g_label->raise();
        mol6->raise();
        b_label->raise();
        cal_mol->raise();
        formula->raise();
        v1->raise();
        v6->raise();
        v5->raise();
        v4->raise();
        v2->raise();
        v3->raise();
        tab_fast = new QWidget();
        tab_fast->setObjectName(QString::fromUtf8("tab_fast"));
        pic = new ClickedLabel(tab_fast);
        pic->setObjectName(QString::fromUtf8("pic"));
        pic->setGeometry(QRect(20, 10, 481, 351));
        pic->setCursor(QCursor(Qt::PointingHandCursor));
        pic->setStyleSheet(QString::fromUtf8("border:1px solid;\n"
"border-color: rgb(239, 239, 239);\n"
"background-color: rgb(247, 247, 247);\n"
"font: 72pt \"Arial\";"));
        widget_solutions_RGB = new QWidget(tab_fast);
        widget_solutions_RGB->setObjectName(QString::fromUtf8("widget_solutions_RGB"));
        widget_solutions_RGB->setGeometry(QRect(560, 250, 571, 111));
        widget_solutions_RGB->setStyleSheet(QString::fromUtf8("border-color: rgb(239, 239, 239);\n"
"background-color: rgb(244, 244, 244);"));
        gridLayout_4 = new QGridLayout(widget_solutions_RGB);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        r_value_fast = new QLabel(widget_solutions_RGB);
        r_value_fast->setObjectName(QString::fromUtf8("r_value_fast"));
        r_value_fast->setStyleSheet(QString::fromUtf8("border:1px solid;\n"
"border-color:rgb(232, 0, 0);"));
        r_value_fast->setMargin(0);

        gridLayout_4->addWidget(r_value_fast, 2, 0, 1, 1);

        b_value_fast = new QLabel(widget_solutions_RGB);
        b_value_fast->setObjectName(QString::fromUtf8("b_value_fast"));
        b_value_fast->setStyleSheet(QString::fromUtf8("border:1px solid;\n"
"border-color: rgb(0, 0, 241);"));

        gridLayout_4->addWidget(b_value_fast, 2, 2, 1, 1);

        g_value_fast = new QLabel(widget_solutions_RGB);
        g_value_fast->setObjectName(QString::fromUtf8("g_value_fast"));
        g_value_fast->setStyleSheet(QString::fromUtf8("border:1px solid;\n"
"border-color: rgb(0, 223, 0);"));

        gridLayout_4->addWidget(g_value_fast, 2, 1, 1, 1);

        r_label_fast = new QLabel(widget_solutions_RGB);
        r_label_fast->setObjectName(QString::fromUtf8("r_label_fast"));
        r_label_fast->setStyleSheet(QString::fromUtf8("font: 12pt \"Times New Roman\";\n"
"color:rgb(232, 0, 0);"));

        gridLayout_4->addWidget(r_label_fast, 0, 0, 1, 1);

        g_label_fast = new QLabel(widget_solutions_RGB);
        g_label_fast->setObjectName(QString::fromUtf8("g_label_fast"));
        g_label_fast->setStyleSheet(QString::fromUtf8("font: 12pt \"Times New Roman\";\n"
"color: rgb(0, 223, 0);"));

        gridLayout_4->addWidget(g_label_fast, 0, 1, 1, 1);

        b_label_fast = new QLabel(widget_solutions_RGB);
        b_label_fast->setObjectName(QString::fromUtf8("b_label_fast"));
        b_label_fast->setStyleSheet(QString::fromUtf8("font: 75 12pt \"Times New Roman\";\n"
"color:rgb(0, 0, 241);\n"
""));

        gridLayout_4->addWidget(b_label_fast, 0, 2, 1, 1);

        groupBox_solutions_type = new QGroupBox(tab_fast);
        groupBox_solutions_type->setObjectName(QString::fromUtf8("groupBox_solutions_type"));
        groupBox_solutions_type->setGeometry(QRect(560, 20, 571, 141));
        groupBox_solutions_type->setStyleSheet(QString::fromUtf8("border-color: rgb(239, 239, 239);\n"
"background-color: rgb(244, 244, 244);"));
        layoutWidget = new QWidget(groupBox_solutions_type);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 40, 531, 81));
        gridLayout_2 = new QGridLayout(layoutWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        radioButton_CoSO4 = new QRadioButton(layoutWidget);
        radioButton_CoSO4->setObjectName(QString::fromUtf8("radioButton_CoSO4"));
        radioButton_CoSO4->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\256\213\344\275\223\";"));
        radioButton_CoSO4->setCheckable(true);
        radioButton_CoSO4->setChecked(false);

        gridLayout_2->addWidget(radioButton_CoSO4, 0, 0, 1, 1);

        radioButton_CuSO4 = new QRadioButton(layoutWidget);
        radioButton_CuSO4->setObjectName(QString::fromUtf8("radioButton_CuSO4"));
        radioButton_CuSO4->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\256\213\344\275\223\";"));

        gridLayout_2->addWidget(radioButton_CuSO4, 0, 1, 1, 1);

        radioButton_NiSO4 = new QRadioButton(layoutWidget);
        radioButton_NiSO4->setObjectName(QString::fromUtf8("radioButton_NiSO4"));
        radioButton_NiSO4->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\256\213\344\275\223\";"));

        gridLayout_2->addWidget(radioButton_NiSO4, 0, 2, 1, 1);

        rgb_value_fast = new QLabel(tab_fast);
        rgb_value_fast->setObjectName(QString::fromUtf8("rgb_value_fast"));
        rgb_value_fast->setGeometry(QRect(850, 390, 91, 30));
        rgb_value_fast->setStyleSheet(QString::fromUtf8("border:1px solid;\n"
"border-color: rgb(0, 0, 0);"));
        rgb_label_fast = new QLabel(tab_fast);
        rgb_label_fast->setObjectName(QString::fromUtf8("rgb_label_fast"));
        rgb_label_fast->setGeometry(QRect(719, 390, 111, 31));
        rgb_label_fast->setStyleSheet(QString::fromUtf8("font: 12pt \"Times New Roman\";"));
        pushButton_compute = new QPushButton(tab_fast);
        pushButton_compute->setObjectName(QString::fromUtf8("pushButton_compute"));
        pushButton_compute->setGeometry(QRect(730, 520, 181, 41));
        pushButton_compute->setStyleSheet(QString::fromUtf8("font: 12pt \"\345\256\213\344\275\223\";"));
        show_fast = new QCustomPlot(tab_fast);
        show_fast->setObjectName(QString::fromUtf8("show_fast"));
        show_fast->setGeometry(QRect(20, 380, 481, 381));
        show_fast->setStyleSheet(QString::fromUtf8("border:1px solid;\n"
"border-color: rgb(200, 200, 197);\n"
"font: 72pt \"Arial\";\n"
"background-color: rgb(230, 230, 230);"));
        label_fast = new QLabel(tab_fast);
        label_fast->setObjectName(QString::fromUtf8("label_fast"));
        label_fast->setGeometry(QRect(620, 670, 201, 31));
        label_fast->setStyleSheet(QString::fromUtf8("font: 16pt \"\345\256\213\344\275\223\";"));
        label_mol_fast = new QLabel(tab_fast);
        label_mol_fast->setObjectName(QString::fromUtf8("label_mol_fast"));
        label_mol_fast->setGeometry(QRect(830, 670, 91, 30));
        label_mol_fast->setStyleSheet(QString::fromUtf8("border:1px solid;\n"
"border-color: rgb(0, 0, 0);"));
        label_fast_2 = new QLabel(tab_fast);
        label_fast_2->setObjectName(QString::fromUtf8("label_fast_2"));
        label_fast_2->setGeometry(QRect(930, 670, 51, 31));
        label_fast_2->setStyleSheet(QString::fromUtf8("font: 12pt \"Times New Roman\";"));
        formula_fast = new QLabel(tab_fast);
        formula_fast->setObjectName(QString::fromUtf8("formula_fast"));
        formula_fast->setGeometry(QRect(710, 600, 221, 31));
        formula_fast->setStyleSheet(QString::fromUtf8("background-color: rgb(230, 230, 230);\n"
"border:1px solid;\n"
""));
        tabWidget->addTab(tab_fast, QString());
        formula_fast->raise();
        widget_solutions_RGB->raise();
        pic->raise();
        groupBox_solutions_type->raise();
        rgb_value_fast->raise();
        rgb_label_fast->raise();
        pushButton_compute->raise();
        show_fast->raise();
        label_fast->raise();
        label_mol_fast->raise();
        label_fast_2->raise();
        Professional->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Professional);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1178, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        Professional->setMenuBar(menuBar);
        statusBar = new QStatusBar(Professional);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Professional->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(restart);

        retranslateUi(Professional);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Professional);
    } // setupUi

    void retranslateUi(QMainWindow *Professional)
    {
        Professional->setWindowTitle(QApplication::translate("Professional", "So-Me,\346\265\213\351\207\217\344\275\240\347\232\204\346\272\266\346\266\262", nullptr));
        restart->setText(QApplication::translate("Professional", "\346\201\242\345\244\215\345\210\235\345\247\213\345\200\274", nullptr));
        prompt->setText(QApplication::translate("Professional", "\350\257\267\350\276\223\345\205\245\346\265\223\345\272\246\357\274\201", nullptr));
        add->setText(QApplication::translate("Professional", "\346\267\273\345\212\240", nullptr));
        pic_show->setText(QString());
        r_label->setText(QApplication::translate("Professional", "R", nullptr));
        c_label->setText(QApplication::translate("Professional", "<html><head/><body><p><span style=\" font-size:14pt;\">\346\272\266\346\266\262\346\265\223\345\272\246</span></p></body></html>", nullptr));
        v1->setText(QString());
        RGB_Parameter->setText(QApplication::translate("Professional", "RGB Parameter", nullptr));
        v6->setText(QString());
        mol_unknown->setText(QApplication::translate("Professional", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">mol</span><span style=\" font-size:14pt; vertical-align:sub;\">Unknown</span></p></body></html>", nullptr));
        v3->setText(QString());
        mol2->setText(QString());
        rgb_value->setText(QString());
        mol5->setText(QString());
        fit->setText(QApplication::translate("Professional", "\346\213\237\345\220\210", nullptr));
        rgb_label->setText(QApplication::translate("Professional", "RGB", nullptr));
        pic6->setText(QApplication::translate("Professional", "<center>+<center/>", nullptr));
        pic1->setText(QApplication::translate("Professional", "<center>+<center/>", nullptr));
        pic7->setText(QApplication::translate("Professional", "<center>+<center/>", nullptr));
        pic3->setText(QApplication::translate("Professional", "<center>+<center/>", nullptr));
        pic5->setText(QApplication::translate("Professional", "<center>+<center/>", nullptr));
        pic4->setText(QApplication::translate("Professional", "<center>+<center/>", nullptr));
        pic2->setText(QApplication::translate("Professional", "<center>+<center/>", nullptr));
        pic1_mol->setText(QString());
        pic2_mol->setText(QString());
        pic3_mol->setText(QString());
        pic4_mol->setText(QString());
        pic5_mol->setText(QString());
        pic6_mol->setText(QString());
        pic7_mol->setText(QString());
        cal_show->setText(QString());
        r_value->setText(QString());
        v2->setText(QString());
        mol3->setText(QString());
        g_value->setText(QString());
        b_value->setText(QString());
        v4->setText(QString());
        mol_Parameter->setText(QApplication::translate("Professional", "mol Parameter", nullptr));
        mol4->setText(QString());
        mol1->setText(QString());
        v5->setText(QString());
        rgb_unknown->setText(QApplication::translate("Professional", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt;\">RGB</span><span style=\" font-size:14pt; vertical-align:sub;\">Unknown</span></p></body></html>", nullptr));
        p1->setText(QString());
        g_label->setText(QApplication::translate("Professional", "G", nullptr));
        mol6->setText(QString());
        b_label->setText(QApplication::translate("Professional", "B", nullptr));
        p2->setText(QString());
        cal_mol->setText(QString());
        formula->setHtml(QApplication::translate("Professional", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_professional), QApplication::translate("Professional", "\344\270\223\344\270\232\346\250\241\345\274\217", nullptr));
        pic->setText(QApplication::translate("Professional", "<html><head/><body><p><br/></p></body></html>", nullptr));
        r_value_fast->setText(QString());
        b_value_fast->setText(QString());
        g_value_fast->setText(QString());
        r_label_fast->setText(QApplication::translate("Professional", "<html><head/><body><p align=\"center\">R</p></body></html>", nullptr));
        g_label_fast->setText(QApplication::translate("Professional", "<html><head/><body><p align=\"center\">G</p></body></html>", nullptr));
        b_label_fast->setText(QApplication::translate("Professional", "<html><head/><body><p align=\"center\">B</p></body></html>", nullptr));
        groupBox_solutions_type->setTitle(QApplication::translate("Professional", "\351\200\211\346\213\251\346\272\266\346\266\262\347\261\273\345\236\213", nullptr));
        radioButton_CoSO4->setText(QApplication::translate("Professional", "\347\241\253\351\205\270\351\222\264\346\272\266\346\266\262", nullptr));
        radioButton_CuSO4->setText(QApplication::translate("Professional", "\347\241\253\351\205\270\351\223\234\346\272\266\346\266\262", nullptr));
        radioButton_NiSO4->setText(QApplication::translate("Professional", "\347\241\253\351\205\270\351\225\215\346\272\266\346\266\262", nullptr));
        rgb_value_fast->setText(QString());
        rgb_label_fast->setText(QApplication::translate("Professional", "<html><head/><body><p align=\"center\">RGB<span style=\" vertical-align:sub;\">unknown</span></p></body></html>", nullptr));
        pushButton_compute->setText(QApplication::translate("Professional", "\350\256\241\347\256\227", nullptr));
        label_fast->setText(QApplication::translate("Professional", "<html><head/><body><p align=\"center\">\346\234\252\347\237\245\346\272\266\346\266\262\347\232\204\346\265\223\345\272\246</p></body></html>", nullptr));
        label_mol_fast->setText(QString());
        label_fast_2->setText(QApplication::translate("Professional", "<html><head/><body><p align=\"center\">mol</p></body></html>", nullptr));
        formula_fast->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_fast), QApplication::translate("Professional", "\345\277\253\346\215\267\346\250\241\345\274\217", nullptr));
        menu->setTitle(QApplication::translate("Professional", "\344\270\273\350\217\234\345\215\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Professional: public Ui_Professional {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROFESSIONAL_H
