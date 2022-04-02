/********************************************************************************
** Form generated from reading UI file 'multiplication_class.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTIPLICATION_CLASS_H
#define UI_MULTIPLICATION_CLASS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Multiplication_class
{
public:
    QWidget *centralwidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *calcul;
    QTextBrowser *affichage;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Multiplication_class)
    {
        if (Multiplication_class->objectName().isEmpty())
            Multiplication_class->setObjectName(QString::fromUtf8("Multiplication_class"));
        Multiplication_class->resize(1133, 592);
        centralwidget = new QWidget(Multiplication_class);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(30, 10, 1021, 501));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 20));
        label->setStyleSheet(QString::fromUtf8(""));
        label->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(0, QFormLayout::SpanningRole, label);

        lineEdit = new QLineEdit(horizontalLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit);

        calcul = new QPushButton(horizontalLayoutWidget);
        calcul->setObjectName(QString::fromUtf8("calcul"));
        calcul->setStyleSheet(QString::fromUtf8("background-color: rgb(143, 240, 164);\n"
"font: 75 11pt \"DejaVu Math TeX Gyre\";\n"
"color: rgb(0, 0, 0);"));

        formLayout->setWidget(2, QFormLayout::FieldRole, calcul);


        horizontalLayout->addLayout(formLayout);

        affichage = new QTextBrowser(horizontalLayoutWidget);
        affichage->setObjectName(QString::fromUtf8("affichage"));
        affichage->setStyleSheet(QString::fromUtf8("background-color: rgb(153, 193, 241);\n"
"font: 75 oblique 23pt \"DejaVu Sans\";\n"
"color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(affichage);

        Multiplication_class->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Multiplication_class);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1133, 24));
        Multiplication_class->setMenuBar(menubar);
        statusbar = new QStatusBar(Multiplication_class);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Multiplication_class->setStatusBar(statusbar);

        retranslateUi(Multiplication_class);

        QMetaObject::connectSlotsByName(Multiplication_class);
    } // setupUi

    void retranslateUi(QMainWindow *Multiplication_class)
    {
        Multiplication_class->setWindowTitle(QApplication::translate("Multiplication_class", "Multiplication_class", nullptr));
        label->setText(QApplication::translate("Multiplication_class", "Entrer un nombre pour avoir une table de multiplication ", nullptr));
        calcul->setText(QApplication::translate("Multiplication_class", "Calculer", nullptr));
        affichage->setHtml(QApplication::translate("Multiplication_class", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'DejaVu Sans'; font-size:23pt; font-weight:72; font-style:italic;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-family:'Cantarell'; font-size:11pt; font-weight:400; font-style:normal;\"><br /></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Multiplication_class: public Ui_Multiplication_class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTIPLICATION_CLASS_H
