#include "hireimg.h"
#include <QtWidgets>

HireImg::HireImg(QWidget *parent) : QMainWindow(parent)
{

    QWidget* M_Widget = new QWidget();
    QLabel* HireMessage = new QLabel("Lacation de voiture !!!");
    QGridLayout* Full = new QGridLayout(M_Widget);
    HireMessage->setFont(QFont("Lato Black",40,(font().bold())));
    Full->addWidget(HireMessage);
    HireMessage->setStyleSheet(QString::fromUtf8("color: rgb(17, 92, 234)"));
    HireMessage->setAlignment(Qt::AlignCenter);

    M_Widget->setStyleSheet("background: url(addCare.jpg)");
    setCentralWidget(M_Widget);
    setEnabled(M_Widget);
}
