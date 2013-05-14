/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created: Sun May 12 11:20:26 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *pushButton;
    QLineEdit *ipText;
    QLineEdit *portText;
    QLabel *messageLabel;
    QGroupBox *groupBox;
    QRadioButton *clientRB;
    QRadioButton *serverRB;
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(400, 300);
        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(250, 50, 51, 23));
        ipText = new QLineEdit(Widget);
        ipText->setObjectName(QString::fromUtf8("ipText"));
        ipText->setGeometry(QRect(190, 20, 113, 20));
        portText = new QLineEdit(Widget);
        portText->setObjectName(QString::fromUtf8("portText"));
        portText->setGeometry(QRect(190, 50, 51, 20));
        messageLabel = new QLabel(Widget);
        messageLabel->setObjectName(QString::fromUtf8("messageLabel"));
        messageLabel->setGeometry(QRect(20, 110, 171, 91));
        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 120, 71));
        clientRB = new QRadioButton(groupBox);
        clientRB->setObjectName(QString::fromUtf8("clientRB"));
        clientRB->setGeometry(QRect(10, 40, 89, 16));
        serverRB = new QRadioButton(groupBox);
        serverRB->setObjectName(QString::fromUtf8("serverRB"));
        serverRB->setGeometry(QRect(10, 20, 89, 16));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(140, 20, 41, 16));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(140, 50, 41, 16));
        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(320, 50, 51, 23));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Widget", "\350\277\236\346\216\245", 0, QApplication::UnicodeUTF8));
        ipText->setText(QApplication::translate("Widget", "localhost", 0, QApplication::UnicodeUTF8));
        portText->setText(QApplication::translate("Widget", "6666", 0, QApplication::UnicodeUTF8));
        messageLabel->setText(QString());
        groupBox->setTitle(QApplication::translate("Widget", "\346\250\241\345\274\217", 0, QApplication::UnicodeUTF8));
        clientRB->setText(QApplication::translate("Widget", "\346\234\215\345\212\241\347\253\257", 0, QApplication::UnicodeUTF8));
        serverRB->setText(QApplication::translate("Widget", "\345\256\242\346\210\267\347\253\257", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Widget", "IP\345\234\260\345\235\200", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Widget", "\347\253\257\345\217\243\345\217\267", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Widget", "\346\226\255\345\274\200", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
