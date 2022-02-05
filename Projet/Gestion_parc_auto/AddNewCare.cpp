#include "AddNewCare.h"
#include "A_ll_H.h"
#include <QSqlQuery>

addnewcar::addnewcar(QWidget *parent) : QMainWindow(parent)
{

    //screen

        QScreen *screen        = QGuiApplication::primaryScreen();
        const int screenWidth  = screen->size().width()/2-10;
        const int screenHeight = screen->size().height()-5;

        QLabel* Title = new QLabel("Informations sur la voiture");
        Title->setFixedHeight(55);
        Title->setFixedWidth(500);
        Title->setFont(QFont("arial",18,(font().bold())));


        //Form container
        Mywidget = new QWidget();
        QGridLayout* MyForm = new QGridLayout(Mywidget);
        setCentralWidget(Mywidget);
        setEnabled(Mywidget);
        Mywidget->setMaximumHeight(screenHeight);
        Mywidget->setMaximumWidth(screenWidth);
        Mywidget->setMinimumWidth(screenWidth*0.27);


        //Marque

        QLabel* LbMarque = new QLabel("Marque");
        LbMarque->setFont(QFont("arial",17,(font().bold())));
        LeMarque = new QLineEdit();
        LeMarque->setMinimumHeight(20);
        LeMarque->setMinimumWidth(250);
        LeMarque->setMaximumHeight(35);
        LeMarque->setMaximumWidth(350);
        //Model

        QLabel* LbModel = new QLabel("Modèle");
        LbModel->setFont(QFont("arial",17,(font().bold())));
        LeModel = new QLineEdit();
        LeModel->setMinimumHeight(20);
        LeModel->setMinimumWidth(250);
        LeModel->setMaximumHeight(35);
        LeModel->setMaximumWidth(350);


        //Immatriculation

        QLabel* LbImmaticulation = new QLabel("Immatriculation");
        LbImmaticulation->setFont(QFont("arial",17,(font().bold())));
       LeImmatriculation = new QLineEdit();
        LeImmatriculation ->setMinimumHeight(20);
        LeImmatriculation ->setMinimumWidth(250);
        LeImmatriculation ->setMaximumHeight(35);
        LeImmatriculation ->setMaximumWidth(350);

        //Mileage

        QLabel* LbMileage= new QLabel("Kilométrage");
        LbMileage->setFont(QFont("arial",17,(font().bold())));
        LeMileage = new QLineEdit();
        LeMileage->setMinimumHeight(20);
        LeMileage->setMinimumWidth(250);
        LeMileage->setMaximumHeight(35);
        LeMileage->setMaximumWidth(350);

        //Summiot btn

        QPushButton* Btn = new QPushButton("Enrégistrer");
        Btn->setMinimumHeight(20);
        Btn->setMinimumWidth(250);
        Btn->setMaximumHeight(35);
        Btn->setMaximumWidth(350);
        Btn->setFont(QFont("arial",17,(font().bold())));
        Btn->setStyleSheet(QString::fromUtf8("background-color: rgb(7,245,102);"));


        //Added label and lineEdit into form
        MyForm->addWidget(Title,0,1,1,2);
        MyForm->addWidget(LbMarque,1,0);
        MyForm->addWidget(LeMarque,1,1);
        MyForm->addWidget(LbModel,2,0);
        MyForm->addWidget(LeModel,2,1);
        MyForm->addWidget(LbImmaticulation,3,0);
        MyForm->addWidget(LeImmatriculation,3,1);
        MyForm->addWidget(LbMileage,4,0);
        MyForm->addWidget(LeMileage,4,1);
        MyForm->addWidget(Btn,5,1,1,2);

        //Column and rows carateres
        //MyForm->columnMinimumWidth(500);
        //MyForm->rowMinimumHeight(90);
        MyForm->setHorizontalSpacing(10);
        MyForm->setHorizontalSpacing(5);
        MyForm->setVerticalSpacing(0);
        MyForm->setRowStretch(1,0);
        MyForm->setColumnStretch(1,0);
        MyForm->setMargin(90);
        Mywidget->setStyleSheet(QString::fromUtf8("background-color: rgba(200, 242, 235, 0.46);"));
        Mywidget->setWindowTitle("Ajouter une voiture");
        Mywidget->setMinimumWidth(500);


        // Care attributs



         QObject::connect(Btn,SIGNAL(clicked()),this,SLOT(On_clicked_Btn()));


}
/*-------------------------------------------------------------------------------------------------------------------*/


bool addnewcar::SearchCare(QString id)
{
    // Do select to check care id in care table
   if(!id.isEmpty())
   {
       MyQuery = new QSqlQuery();
       MyQuery->prepare("SELECT immatriculation FROM VOITURE WHERE immatriculation ='"+id+"'");

       if(MyQuery->exec())
       {
           if( MyQuery->last()){

               QString Id = MyQuery->value(0).toString();

               if(id==Id)
               {return  true;}
               else{return false;}
           }

       }

    }
   return false;
}



/*--------------------------------------------------------------------------------------------------------------*/


void addnewcar::On_clicked_Btn()
{


    Marque = LeMarque->text();
    LeMarque->clear();
    Model = LeModel->text();
    LeModel->clear();
    Immatriculation= LeImmatriculation->text();
    LeImmatriculation->clear();
    Mileage  = LeMileage->text();
    LeMileage->clear();

    if(!SearchCare(Immatriculation))

    {
        if(!(Marque.isEmpty() || Immatriculation.isEmpty() || Mileage.isEmpty()))
        {
            MyQuery->prepare("INSERT INTO VOITURE(marque,modele,immatriculation,kilometrage)" "VALUES(?,?,?,?)");
            MyQuery->addBindValue(Marque);
            MyQuery->addBindValue(Model);
            MyQuery->addBindValue(Immatriculation);
            MyQuery->addBindValue(Mileage);

            if(MyQuery->exec())
            {
                QMessageBox::information(nullptr,"Ajout Voiture",Marque+" "+Model+" "+Immatriculation+" est bien enrégistrée. ");
            }
            else
            {
                QMessageBox::critical(nullptr,"Ajout Voiture","Ajout échoué");
            }
        }

        else
        {
            QMessageBox::critical(nullptr,"Ajout Voiture","Ajout échoué, veuillez remplir les champs");
        }
    }
    else{QMessageBox::critical(nullptr,"Ajout Voiture","Ce numéro d'immatriculation existe déja !");}
}

