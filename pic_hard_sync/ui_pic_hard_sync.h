/********************************************************************************
** Form generated from reading UI file 'pic_hard_syncuOHCES.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef PIC_HARD_SYNCUOHCES_H
#define PIC_HARD_SYNCUOHCES_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pic_hard_syncClass
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QGroupBox *groupBox;
    QGroupBox *groupBox_2;
    QLabel *label_gray_fisheye_1;
    QGroupBox *groupBox_3;
    QLabel *label_gray_fisheye_2;
    QGroupBox *groupBox_4;
    QGroupBox *groupBox_5;
    QLabel *label_RGB_fisheye_1;
    QGroupBox *groupBox_6;
    QLabel *label_RGB_fisheye_2;
    QGroupBox *groupBox_7;
    QGroupBox *groupBox_8;
    QLabel *label_RGB_1;
    QGroupBox *groupBox_9;
    QLabel *label_RGB_2;
    QGroupBox *groupBox_10;
    QLabel *label_RGB_3;
    QGroupBox *groupBox_11;
    QLabel *label_RGB_4;
    QGroupBox *groupBox_12;
    QLabel *label_RGB_5;
    QGroupBox *groupBox_13;
    QLabel *label_RGB_6;
    QGroupBox *groupBox_14;
    QLabel *label_RGB_7;
    QGroupBox *groupBox_15;
    QLabel *label_RGB_8;
    QGroupBox *groupBox_16;
    QLabel *label_RGB_9;
    QGroupBox *groupBox_17;
    QLabel *label_RGB_10;
    QGroupBox *groupBox_18;
    QLabel *label_RGB_11;
    QGroupBox *groupBox_19;
    QLabel *label_RGB_12;
    QGroupBox *groupBox_20;
    QLabel *label_ID;
    QLineEdit *lineEdit_ID;
    QLineEdit *lineEdit_gestureID;
    QLabel *label_gestureID;
    QLabel *label_gestureNO;
    QPushButton *pushButton_regist;
    QPushButton *pushButton_del;
    QProgressBar *progressBar;
    QLabel *label_status;
    QLineEdit *lineEdit_gestureNO;
    QWidget *tab;
    QLineEdit *lineEdit_sample_frame;
    QLabel *label_sample_frame;
    QLabel *label_save_path;
    QPushButton *pushButton_select_path;
    QLabel *label_root_path;
    QSpinBox *spinBox;
    QLabel *label_iAeTarget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *pic_hard_syncClass)
    {
        if (pic_hard_syncClass->objectName().isEmpty())
            pic_hard_syncClass->setObjectName(QString::fromUtf8("pic_hard_syncClass"));
        pic_hard_syncClass->resize(1429, 879);
        centralWidget = new QWidget(pic_hard_syncClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 1421, 901));
        QFont font;
        font.setFamily(QString::fromUtf8("Arial"));
        font.setPointSize(20);
        font.setBold(false);
        font.setWeight(50);
        tabWidget->setFont(font);
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        groupBox = new QGroupBox(tab_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 461, 271));
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setWeight(50);
        groupBox->setFont(font1);
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox {     \n"
"border: 1px solid gray;     \n"
"border-radius: 9px;     \n"
"margin-top: 0.5em;\n"
"}\n"
"\n"
"QGroupBox::title {     \n"
"subcontrol-origin: margin;     \n"
"left: 10px;     \n"
"padding: 0 3px 0 3px;\n"
" }"));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 30, 201, 221));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Arial"));
        groupBox_2->setFont(font2);
        label_gray_fisheye_1 = new QLabel(groupBox_2);
        label_gray_fisheye_1->setObjectName(QString::fromUtf8("label_gray_fisheye_1"));
        label_gray_fisheye_1->setGeometry(QRect(20, 60, 160, 120));
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(240, 30, 201, 221));
        groupBox_3->setFont(font2);
        label_gray_fisheye_2 = new QLabel(groupBox_3);
        label_gray_fisheye_2->setObjectName(QString::fromUtf8("label_gray_fisheye_2"));
        label_gray_fisheye_2->setGeometry(QRect(20, 60, 160, 120));
        groupBox_4 = new QGroupBox(tab_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(500, 10, 461, 271));
        groupBox_4->setFont(font1);
        groupBox_4->setStyleSheet(QString::fromUtf8("QGroupBox {     \n"
"border: 1px solid gray;     \n"
"border-radius: 9px;     \n"
"margin-top: 0.5em;\n"
"}\n"
"\n"
"QGroupBox::title {     \n"
"subcontrol-origin: margin;     \n"
"left: 10px;     \n"
"padding: 0 3px 0 3px;\n"
" }"));
        groupBox_5 = new QGroupBox(groupBox_4);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(20, 30, 201, 221));
        groupBox_5->setFont(font2);
        label_RGB_fisheye_1 = new QLabel(groupBox_5);
        label_RGB_fisheye_1->setObjectName(QString::fromUtf8("label_RGB_fisheye_1"));
        label_RGB_fisheye_1->setGeometry(QRect(20, 60, 160, 120));
        groupBox_6 = new QGroupBox(groupBox_4);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(240, 30, 201, 221));
        groupBox_6->setFont(font2);
        label_RGB_fisheye_2 = new QLabel(groupBox_6);
        label_RGB_fisheye_2->setObjectName(QString::fromUtf8("label_RGB_fisheye_2"));
        label_RGB_fisheye_2->setGeometry(QRect(20, 60, 160, 120));
        groupBox_7 = new QGroupBox(tab_2);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 300, 1381, 481));
        groupBox_7->setFont(font1);
        groupBox_7->setStyleSheet(QString::fromUtf8("QGroupBox {     \n"
"border: 1px solid gray;     \n"
"border-radius: 9px;     \n"
"margin-top: 0.5em;\n"
"}\n"
"\n"
"QGroupBox::title {     \n"
"subcontrol-origin: margin;     \n"
"left: 10px;     \n"
"padding: 0 3px 0 3px;\n"
" }"));
        groupBox_8 = new QGroupBox(groupBox_7);
        groupBox_8->setObjectName(QString::fromUtf8("groupBox_8"));
        groupBox_8->setGeometry(QRect(40, 30, 201, 211));
        groupBox_8->setFont(font2);
        label_RGB_1 = new QLabel(groupBox_8);
        label_RGB_1->setObjectName(QString::fromUtf8("label_RGB_1"));
        label_RGB_1->setGeometry(QRect(20, 50, 160, 120));
        groupBox_9 = new QGroupBox(groupBox_7);
        groupBox_9->setObjectName(QString::fromUtf8("groupBox_9"));
        groupBox_9->setGeometry(QRect(260, 30, 201, 211));
        groupBox_9->setFont(font2);
        label_RGB_2 = new QLabel(groupBox_9);
        label_RGB_2->setObjectName(QString::fromUtf8("label_RGB_2"));
        label_RGB_2->setGeometry(QRect(20, 50, 160, 120));
        groupBox_10 = new QGroupBox(groupBox_7);
        groupBox_10->setObjectName(QString::fromUtf8("groupBox_10"));
        groupBox_10->setGeometry(QRect(480, 30, 201, 211));
        groupBox_10->setFont(font2);
        label_RGB_3 = new QLabel(groupBox_10);
        label_RGB_3->setObjectName(QString::fromUtf8("label_RGB_3"));
        label_RGB_3->setGeometry(QRect(20, 50, 160, 120));
        groupBox_11 = new QGroupBox(groupBox_7);
        groupBox_11->setObjectName(QString::fromUtf8("groupBox_11"));
        groupBox_11->setGeometry(QRect(700, 30, 201, 211));
        groupBox_11->setFont(font2);
        label_RGB_4 = new QLabel(groupBox_11);
        label_RGB_4->setObjectName(QString::fromUtf8("label_RGB_4"));
        label_RGB_4->setGeometry(QRect(20, 50, 160, 120));
        groupBox_12 = new QGroupBox(groupBox_7);
        groupBox_12->setObjectName(QString::fromUtf8("groupBox_12"));
        groupBox_12->setGeometry(QRect(920, 30, 201, 211));
        groupBox_12->setFont(font2);
        label_RGB_5 = new QLabel(groupBox_12);
        label_RGB_5->setObjectName(QString::fromUtf8("label_RGB_5"));
        label_RGB_5->setGeometry(QRect(20, 50, 160, 120));
        groupBox_13 = new QGroupBox(groupBox_7);
        groupBox_13->setObjectName(QString::fromUtf8("groupBox_13"));
        groupBox_13->setGeometry(QRect(1140, 30, 201, 211));
        groupBox_13->setFont(font2);
        label_RGB_6 = new QLabel(groupBox_13);
        label_RGB_6->setObjectName(QString::fromUtf8("label_RGB_6"));
        label_RGB_6->setGeometry(QRect(20, 50, 160, 120));
        groupBox_14 = new QGroupBox(groupBox_7);
        groupBox_14->setObjectName(QString::fromUtf8("groupBox_14"));
        groupBox_14->setGeometry(QRect(40, 250, 201, 211));
        groupBox_14->setFont(font2);
        label_RGB_7 = new QLabel(groupBox_14);
        label_RGB_7->setObjectName(QString::fromUtf8("label_RGB_7"));
        label_RGB_7->setGeometry(QRect(20, 50, 160, 120));
        groupBox_15 = new QGroupBox(groupBox_7);
        groupBox_15->setObjectName(QString::fromUtf8("groupBox_15"));
        groupBox_15->setGeometry(QRect(260, 250, 201, 211));
        groupBox_15->setFont(font2);
        label_RGB_8 = new QLabel(groupBox_15);
        label_RGB_8->setObjectName(QString::fromUtf8("label_RGB_8"));
        label_RGB_8->setGeometry(QRect(20, 50, 160, 120));
        groupBox_16 = new QGroupBox(groupBox_7);
        groupBox_16->setObjectName(QString::fromUtf8("groupBox_16"));
        groupBox_16->setGeometry(QRect(480, 250, 201, 211));
        groupBox_16->setFont(font2);
        label_RGB_9 = new QLabel(groupBox_16);
        label_RGB_9->setObjectName(QString::fromUtf8("label_RGB_9"));
        label_RGB_9->setGeometry(QRect(20, 50, 160, 120));
        groupBox_17 = new QGroupBox(groupBox_7);
        groupBox_17->setObjectName(QString::fromUtf8("groupBox_17"));
        groupBox_17->setGeometry(QRect(700, 250, 201, 211));
        groupBox_17->setFont(font2);
        label_RGB_10 = new QLabel(groupBox_17);
        label_RGB_10->setObjectName(QString::fromUtf8("label_RGB_10"));
        label_RGB_10->setGeometry(QRect(20, 50, 160, 120));
        groupBox_18 = new QGroupBox(groupBox_7);
        groupBox_18->setObjectName(QString::fromUtf8("groupBox_18"));
        groupBox_18->setGeometry(QRect(920, 250, 201, 211));
        groupBox_18->setFont(font2);
        label_RGB_11 = new QLabel(groupBox_18);
        label_RGB_11->setObjectName(QString::fromUtf8("label_RGB_11"));
        label_RGB_11->setGeometry(QRect(20, 50, 160, 120));
        groupBox_19 = new QGroupBox(groupBox_7);
        groupBox_19->setObjectName(QString::fromUtf8("groupBox_19"));
        groupBox_19->setGeometry(QRect(1140, 250, 201, 211));
        groupBox_19->setFont(font2);
        label_RGB_12 = new QLabel(groupBox_19);
        label_RGB_12->setObjectName(QString::fromUtf8("label_RGB_12"));
        label_RGB_12->setGeometry(QRect(20, 50, 160, 120));
        groupBox_20 = new QGroupBox(tab_2);
        groupBox_20->setObjectName(QString::fromUtf8("groupBox_20"));
        groupBox_20->setGeometry(QRect(990, 10, 401, 271));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Arial"));
        font3.setPointSize(12);
        groupBox_20->setFont(font3);
        groupBox_20->setStyleSheet(QString::fromUtf8("QGroupBox {     \n"
"border: 1px solid gray;     \n"
"border-radius: 9px;     \n"
"margin-top: 0.5em;\n"
"}\n"
"\n"
"QGroupBox::title {     \n"
"subcontrol-origin: margin;     \n"
"left: 10px;     \n"
"padding: 0 3px 0 3px;\n"
" }"));
        label_ID = new QLabel(groupBox_20);
        label_ID->setObjectName(QString::fromUtf8("label_ID"));
        label_ID->setGeometry(QRect(120, 40, 91, 31));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Arial"));
        font4.setPointSize(13);
        label_ID->setFont(font4);
        label_ID->setAlignment(Qt::AlignCenter);
        lineEdit_ID = new QLineEdit(groupBox_20);
        lineEdit_ID->setObjectName(QString::fromUtf8("lineEdit_ID"));
        lineEdit_ID->setGeometry(QRect(220, 40, 113, 31));
        lineEdit_ID->setFont(font4);
        lineEdit_gestureID = new QLineEdit(groupBox_20);
        lineEdit_gestureID->setObjectName(QString::fromUtf8("lineEdit_gestureID"));
        lineEdit_gestureID->setGeometry(QRect(220, 90, 113, 31));
        lineEdit_gestureID->setFont(font4);
        label_gestureID = new QLabel(groupBox_20);
        label_gestureID->setObjectName(QString::fromUtf8("label_gestureID"));
        label_gestureID->setGeometry(QRect(120, 90, 91, 31));
        label_gestureID->setFont(font4);
        label_gestureID->setAlignment(Qt::AlignCenter);
        label_gestureNO = new QLabel(groupBox_20);
        label_gestureNO->setObjectName(QString::fromUtf8("label_gestureNO"));
        label_gestureNO->setGeometry(QRect(120, 140, 91, 31));
        label_gestureNO->setFont(font4);
        label_gestureNO->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton_regist = new QPushButton(groupBox_20);
        pushButton_regist->setObjectName(QString::fromUtf8("pushButton_regist"));
        pushButton_regist->setGeometry(QRect(110, 190, 91, 31));
        pushButton_regist->setFont(font4);
        pushButton_del = new QPushButton(groupBox_20);
        pushButton_del->setObjectName(QString::fromUtf8("pushButton_del"));
        pushButton_del->setGeometry(QRect(290, 190, 91, 31));
        pushButton_del->setFont(font4);
        progressBar = new QProgressBar(groupBox_20);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(30, 230, 131, 23));
        progressBar->setValue(0);
        label_status = new QLabel(groupBox_20);
        label_status->setObjectName(QString::fromUtf8("label_status"));
        label_status->setGeometry(QRect(170, 230, 221, 21));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Arial"));
        font5.setPointSize(9);
        label_status->setFont(font5);
        label_status->setLayoutDirection(Qt::LeftToRight);
        label_status->setAlignment(Qt::AlignCenter);
        lineEdit_gestureNO = new QLineEdit(groupBox_20);
        lineEdit_gestureNO->setObjectName(QString::fromUtf8("lineEdit_gestureNO"));
        lineEdit_gestureNO->setGeometry(QRect(220, 140, 113, 31));
        lineEdit_gestureNO->setFont(font4);
        tabWidget->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        lineEdit_sample_frame = new QLineEdit(tab);
        lineEdit_sample_frame->setObjectName(QString::fromUtf8("lineEdit_sample_frame"));
        lineEdit_sample_frame->setGeometry(QRect(590, 120, 91, 41));
        QFont font6;
        font6.setFamily(QString::fromUtf8("Arial"));
        font6.setPointSize(20);
        lineEdit_sample_frame->setFont(font6);
        label_sample_frame = new QLabel(tab);
        label_sample_frame->setObjectName(QString::fromUtf8("label_sample_frame"));
        label_sample_frame->setGeometry(QRect(350, 120, 211, 41));
        label_sample_frame->setFont(font);
        label_sample_frame->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_save_path = new QLabel(tab);
        label_save_path->setObjectName(QString::fromUtf8("label_save_path"));
        label_save_path->setGeometry(QRect(390, 190, 171, 41));
        label_save_path->setFont(font);
        label_save_path->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        pushButton_select_path = new QPushButton(tab);
        pushButton_select_path->setObjectName(QString::fromUtf8("pushButton_select_path"));
        pushButton_select_path->setGeometry(QRect(590, 250, 91, 41));
        label_root_path = new QLabel(tab);
        label_root_path->setObjectName(QString::fromUtf8("label_root_path"));
        label_root_path->setGeometry(QRect(590, 200, 811, 31));
        spinBox = new QSpinBox(tab);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(590, 320, 91, 41));
        spinBox->setMinimum(40);
        spinBox->setMaximum(160);
        label_iAeTarget = new QLabel(tab);
        label_iAeTarget->setObjectName(QString::fromUtf8("label_iAeTarget"));
        label_iAeTarget->setGeometry(QRect(300, 320, 261, 41));
        label_iAeTarget->setFont(font);
        label_iAeTarget->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        tabWidget->addTab(tab, QString());
        pic_hard_syncClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(pic_hard_syncClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1429, 23));
        pic_hard_syncClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(pic_hard_syncClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        pic_hard_syncClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(pic_hard_syncClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        pic_hard_syncClass->setStatusBar(statusBar);

        retranslateUi(pic_hard_syncClass);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(pic_hard_syncClass);
    } // setupUi

    void retranslateUi(QMainWindow *pic_hard_syncClass)
    {
        pic_hard_syncClass->setWindowTitle(QCoreApplication::translate("pic_hard_syncClass", "pic_hard_sync", nullptr));
        groupBox->setTitle(QCoreApplication::translate("pic_hard_syncClass", "\346\267\261\345\272\246\351\261\274\347\234\274\347\233\270\346\234\272", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("pic_hard_syncClass", "1\343\200\201\347\201\260\345\272\246\351\261\274\347\234\274\347\233\270\346\234\272_1", nullptr));
        label_gray_fisheye_1->setText(QString());
        groupBox_3->setTitle(QCoreApplication::translate("pic_hard_syncClass", "2\343\200\201\347\201\260\345\272\246\351\261\274\347\234\274\347\233\270\346\234\272_2", nullptr));
        label_gray_fisheye_2->setText(QString());
        groupBox_4->setTitle(QCoreApplication::translate("pic_hard_syncClass", "RGB\351\261\274\347\234\274\347\233\270\346\234\272", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("pic_hard_syncClass", "3\343\200\201RGB\351\261\274\347\234\274\347\233\270\346\234\272_1", nullptr));
        label_RGB_fisheye_1->setText(QString());
        groupBox_6->setTitle(QCoreApplication::translate("pic_hard_syncClass", "4\343\200\201RGB\351\261\274\347\234\274\347\233\270\346\234\272_2", nullptr));
        label_RGB_fisheye_2->setText(QString());
        groupBox_7->setTitle(QCoreApplication::translate("pic_hard_syncClass", "RGB\347\233\270\346\234\272", nullptr));
        groupBox_8->setTitle(QCoreApplication::translate("pic_hard_syncClass", "5\343\200\201RGB_1", nullptr));
        label_RGB_1->setText(QString());
        groupBox_9->setTitle(QCoreApplication::translate("pic_hard_syncClass", "6\343\200\201RGB_2", nullptr));
        label_RGB_2->setText(QString());
        groupBox_10->setTitle(QCoreApplication::translate("pic_hard_syncClass", "7\343\200\201RGB_3", nullptr));
        label_RGB_3->setText(QString());
        groupBox_11->setTitle(QCoreApplication::translate("pic_hard_syncClass", "8\343\200\201RGB_4", nullptr));
        label_RGB_4->setText(QString());
        groupBox_12->setTitle(QCoreApplication::translate("pic_hard_syncClass", "9\343\200\201RGB_5", nullptr));
        label_RGB_5->setText(QString());
        groupBox_13->setTitle(QCoreApplication::translate("pic_hard_syncClass", "10\343\200\201RGB_6", nullptr));
        label_RGB_6->setText(QString());
        groupBox_14->setTitle(QCoreApplication::translate("pic_hard_syncClass", "11\343\200\201\346\267\261\345\272\246_1", nullptr));
        label_RGB_7->setText(QString());
        groupBox_15->setTitle(QCoreApplication::translate("pic_hard_syncClass", "12\343\200\201\346\267\261\345\272\246_2", nullptr));
        label_RGB_8->setText(QString());
        groupBox_16->setTitle(QCoreApplication::translate("pic_hard_syncClass", "13\343\200\201\346\267\261\345\272\246_3", nullptr));
        label_RGB_9->setText(QString());
        groupBox_17->setTitle(QCoreApplication::translate("pic_hard_syncClass", "14\343\200\201\346\267\261\345\272\246_4", nullptr));
        label_RGB_10->setText(QString());
        groupBox_18->setTitle(QCoreApplication::translate("pic_hard_syncClass", "15\343\200\201RGB_7", nullptr));
        label_RGB_11->setText(QString());
        groupBox_19->setTitle(QCoreApplication::translate("pic_hard_syncClass", "16\343\200\201RGB_8", nullptr));
        label_RGB_12->setText(QString());
        groupBox_20->setTitle(QCoreApplication::translate("pic_hard_syncClass", "\346\263\250\345\206\214\344\277\241\346\201\257", nullptr));
        label_ID->setText(QCoreApplication::translate("pic_hard_syncClass", "\347\224\250\346\210\267ID\357\274\232", nullptr));
        lineEdit_gestureID->setText(QString());
        label_gestureID->setText(QCoreApplication::translate("pic_hard_syncClass", "\346\211\213\345\212\277\347\261\273\345\210\253\357\274\232", nullptr));
        label_gestureNO->setText(QCoreApplication::translate("pic_hard_syncClass", "\346\211\213\345\212\277\345\272\217\345\217\267\357\274\232", nullptr));
        pushButton_regist->setText(QCoreApplication::translate("pic_hard_syncClass", "\346\263\250\345\206\214\347\224\250\346\210\267", nullptr));
        pushButton_del->setText(QCoreApplication::translate("pic_hard_syncClass", "\345\210\240\351\231\244\347\224\250\346\210\267", nullptr));
        label_status->setText(QString());
        lineEdit_gestureNO->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("pic_hard_syncClass", "  RGB  \345\233\276  \345\203\217  \346\230\276  \347\244\272  ", nullptr));
        lineEdit_sample_frame->setText(QCoreApplication::translate("pic_hard_syncClass", "125", nullptr));
        label_sample_frame->setText(QCoreApplication::translate("pic_hard_syncClass", "\345\215\225\346\254\241\351\207\207\346\240\267\345\270\247\346\225\260\357\274\232", nullptr));
        label_save_path->setText(QCoreApplication::translate("pic_hard_syncClass", "\345\255\230\345\202\250\350\267\257\345\276\204\357\274\232", nullptr));
        pushButton_select_path->setText(QCoreApplication::translate("pic_hard_syncClass", "\351\200\211\346\213\251", nullptr));
        label_root_path->setText(QCoreApplication::translate("pic_hard_syncClass", "../data", nullptr));
        label_iAeTarget->setText(QCoreApplication::translate("pic_hard_syncClass", "\345\267\245\344\270\232\347\233\270\346\234\272\346\233\235\345\205\211\344\272\256\345\272\246\357\274\232", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("pic_hard_syncClass", "  \350\256\276  \347\275\256  ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pic_hard_syncClass: public Ui_pic_hard_syncClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // PIC_HARD_SYNCUOHCES_H
