/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *ButtonShuffle;
    QLabel *label;
    QWidget *layoutWidget;
    QGridLayout *TypesLink;
    QPushButton *Button4_Bubble;
    QPushButton *Button7_Heap;
    QPushButton *Button9_Radix;
    QPushButton *Button5_Quick;
    QPushButton *Button1_Insert;
    QPushButton *Button3_Shell;
    QPushButton *Button8_Merge;
    QPushButton *Button2_Binary;
    QPushButton *Button6_Selection;
    QLineEdit *DelayEdit;
    QLineEdit *SizeEdit;
    QPushButton *SetSizeButton;
    QPushButton *SetDelayButton;
    QLabel *label_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1200, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        ButtonShuffle = new QPushButton(centralwidget);
        ButtonShuffle->setObjectName("ButtonShuffle");
        ButtonShuffle->setGeometry(QRect(300, 470, 81, 71));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 470, 91, 31));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(720, 450, 441, 111));
        TypesLink = new QGridLayout(layoutWidget);
        TypesLink->setObjectName("TypesLink");
        TypesLink->setContentsMargins(0, 0, 0, 0);
        Button4_Bubble = new QPushButton(layoutWidget);
        Button4_Bubble->setObjectName("Button4_Bubble");
        Button4_Bubble->setMinimumSize(QSize(81, 41));
        Button4_Bubble->setMaximumSize(QSize(81, 41));
        QFont font1;
        font1.setPointSize(9);
        Button4_Bubble->setFont(font1);

        TypesLink->addWidget(Button4_Bubble, 0, 3, 1, 1);

        Button7_Heap = new QPushButton(layoutWidget);
        Button7_Heap->setObjectName("Button7_Heap");
        Button7_Heap->setMinimumSize(QSize(81, 41));
        Button7_Heap->setMaximumSize(QSize(81, 41));
        Button7_Heap->setFont(font1);

        TypesLink->addWidget(Button7_Heap, 1, 1, 1, 1);

        Button9_Radix = new QPushButton(layoutWidget);
        Button9_Radix->setObjectName("Button9_Radix");
        Button9_Radix->setMinimumSize(QSize(81, 41));
        Button9_Radix->setMaximumSize(QSize(81, 41));
        Button9_Radix->setFont(font1);

        TypesLink->addWidget(Button9_Radix, 1, 3, 1, 1);

        Button5_Quick = new QPushButton(layoutWidget);
        Button5_Quick->setObjectName("Button5_Quick");
        Button5_Quick->setMinimumSize(QSize(81, 41));
        Button5_Quick->setMaximumSize(QSize(81, 41));
        Button5_Quick->setFont(font1);

        TypesLink->addWidget(Button5_Quick, 0, 4, 1, 1);

        Button1_Insert = new QPushButton(layoutWidget);
        Button1_Insert->setObjectName("Button1_Insert");
        Button1_Insert->setMinimumSize(QSize(81, 41));
        Button1_Insert->setMaximumSize(QSize(81, 41));
        Button1_Insert->setFont(font1);

        TypesLink->addWidget(Button1_Insert, 0, 0, 1, 1);

        Button3_Shell = new QPushButton(layoutWidget);
        Button3_Shell->setObjectName("Button3_Shell");
        Button3_Shell->setMinimumSize(QSize(81, 41));
        Button3_Shell->setMaximumSize(QSize(81, 41));
        Button3_Shell->setFont(font1);

        TypesLink->addWidget(Button3_Shell, 0, 2, 1, 1);

        Button8_Merge = new QPushButton(layoutWidget);
        Button8_Merge->setObjectName("Button8_Merge");
        Button8_Merge->setMinimumSize(QSize(81, 41));
        Button8_Merge->setMaximumSize(QSize(81, 41));
        Button8_Merge->setFont(font1);

        TypesLink->addWidget(Button8_Merge, 1, 2, 1, 1);

        Button2_Binary = new QPushButton(layoutWidget);
        Button2_Binary->setObjectName("Button2_Binary");
        Button2_Binary->setMinimumSize(QSize(81, 41));
        Button2_Binary->setMaximumSize(QSize(81, 41));
        Button2_Binary->setFont(font1);

        TypesLink->addWidget(Button2_Binary, 0, 1, 1, 1);

        Button6_Selection = new QPushButton(layoutWidget);
        Button6_Selection->setObjectName("Button6_Selection");
        Button6_Selection->setMinimumSize(QSize(81, 41));
        Button6_Selection->setMaximumSize(QSize(81, 41));
        Button6_Selection->setFont(font1);

        TypesLink->addWidget(Button6_Selection, 1, 0, 1, 1);

        DelayEdit = new QLineEdit(centralwidget);
        DelayEdit->setObjectName("DelayEdit");
        DelayEdit->setGeometry(QRect(140, 510, 61, 31));
        SizeEdit = new QLineEdit(centralwidget);
        SizeEdit->setObjectName("SizeEdit");
        SizeEdit->setGeometry(QRect(140, 470, 61, 31));
        SetSizeButton = new QPushButton(centralwidget);
        SetSizeButton->setObjectName("SetSizeButton");
        SetSizeButton->setGeometry(QRect(210, 470, 81, 31));
        SetDelayButton = new QPushButton(centralwidget);
        SetDelayButton->setObjectName("SetDelayButton");
        SetDelayButton->setGeometry(QRect(210, 510, 81, 31));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 510, 91, 31));
        label_2->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1200, 17));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        ButtonShuffle->setText(QCoreApplication::translate("MainWindow", "\346\211\223\344\271\261\346\225\260\347\273\204", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\346\225\260\346\215\256\351\207\217\345\244\247\345\260\217", nullptr));
        Button4_Bubble->setText(QCoreApplication::translate("MainWindow", "\345\206\222\346\263\241\346\216\222\345\272\217", nullptr));
        Button7_Heap->setText(QCoreApplication::translate("MainWindow", "\345\240\206\346\216\222\345\272\217", nullptr));
        Button9_Radix->setText(QCoreApplication::translate("MainWindow", "\345\237\272\346\225\260\346\216\222\345\272\217", nullptr));
        Button5_Quick->setText(QCoreApplication::translate("MainWindow", "\345\277\253\351\200\237\346\216\222\345\272\217", nullptr));
        Button1_Insert->setText(QCoreApplication::translate("MainWindow", "\346\217\222\345\205\245\346\216\222\345\272\217", nullptr));
        Button3_Shell->setText(QCoreApplication::translate("MainWindow", "\345\270\214\345\260\224\346\216\222\345\272\217", nullptr));
        Button8_Merge->setText(QCoreApplication::translate("MainWindow", "\344\272\214\350\267\257\345\275\222\345\271\266\346\216\222\345\272\217", nullptr));
        Button2_Binary->setText(QCoreApplication::translate("MainWindow", "\344\272\214\345\210\206\346\217\222\345\205\245\346\216\222\345\272\217", nullptr));
        Button6_Selection->setText(QCoreApplication::translate("MainWindow", "\351\200\211\346\213\251\346\216\222\345\272\217", nullptr));
        DelayEdit->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        SizeEdit->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        SetSizeButton->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\345\244\247\345\260\217", nullptr));
        SetDelayButton->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\345\273\266\350\277\237", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\350\256\276\347\275\256\345\273\266\350\277\237\357\274\210ms\357\274\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
