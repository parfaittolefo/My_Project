#include "care_state.h"
#include "A_ll_H.h"
Care_state::Care_state(QWidget *parent) : QMainWindow(parent)
{

    QScreen *screen        = QGuiApplication::primaryScreen();
    const int screenWidth  = screen->size().width();
    const int screenHeigth = screen->size().height();
    QWidget* Mywidget = new QWidget();
    QWidget* CareImage = new QWidget();
    CareImage->setStyleSheet("background: url(voiture.jpg)");
   QGridLayout* MyGrid = new QGridLayout(Mywidget);
    Lbmarque = new QLabel("xxxx");
    Lbmarque->setFont(QFont("arial",17,(font().bold())));
    Lbmodel = new QLabel("xxxx");
    Lbmodel->setFont(QFont("arial",17,(font().bold())));
    LbImmatriculation = new QLabel("xxxx");
    LbImmatriculation->setFont(QFont("arial",17,(font().bold())));
    Lbstate = new QLabel("xxxx");
    Lbstate->setFont(QFont("arial",17,(font().bold())));
    Lbstate->setStyleSheet(QString::fromUtf8("color: rgb(27, 255, 4);/*background-color: rgb(25,230,100,90);*/"));
    Lbstate->setFont(QFont("Lato Black",17,(font().bold())));
    LbMileage = new QLabel("xxxxx");
    LbMileage->setFont(QFont("arial",17,(font().bold())));
     QLabel* vide = new QLabel("");
   MyGrid->addWidget(CareImage,0,0,10,4);
   MyGrid->addWidget(Lbmarque,11,1,1,2);
   MyGrid->addWidget(Lbmodel,12,1,1,2);
   MyGrid->addWidget(Lbstate,13,1,1,2);
   MyGrid->addWidget(LbMileage,14,1,1,2);
   MyGrid->addWidget(vide,15,2,1,2);

   // Historyque

//   Mywidget->setMinimumWidth(screenWidth*0.25);
//   Mywidget->setMinimumHeight(screenHeigth*0.30);
   Mywidget ->setStyleSheet(QString::fromUtf8("background-color: #ffffff;opacity: .4;"));//background-color: rgb(100,150,100,110);
   setCentralWidget(Mywidget);
}
