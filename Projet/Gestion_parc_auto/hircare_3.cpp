#include "A_ll_H.h"
#include <QFont>
#include "choice_page_2.h"
#include <QSqlError>

/*  ____________________________________________________________________________________________*/


//Seach care in table

bool HirCare_3::SearchCare(QString id)
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

/*-----------------------------------------------------------------------------------------*/
HirCare_3::HirCare_3()

{

    QScreen *screen        = QGuiApplication::primaryScreen();
    const int screenWidth  = screen->size().width()/2-10;


    //Containner and sumit button
    QHBoxLayout* HLayout = new QHBoxLayout(Mywidget); // Contain the two Glayout1 and 2
    QGridLayout* GLayout1 = new QGridLayout(Mywidget);
    QGridLayout* GLayout2 = new QGridLayout();
    QPushButton* Btn = new QPushButton("Enrégistrer");
    Btn->setStyleSheet(QString::fromUtf8("background-color: rgb(7,245,102);"));
    Btn->setMinimumHeight(20);
    Btn->setMinimumWidth(250);
    Btn->setMaximumHeight(35);
    Btn->setMaximumWidth(200);
    Btn->setFont(QFont("arial",17,(font().bold())));


    HLayout->addLayout(GLayout1);
    HLayout->addLayout(GLayout2);
    HLayout->setSpacing(40);
//    GLayout1->setMargin(30);
//    GLayout2->setMargin(30);


    //About care

        QLabel* LbCarInfo = new QLabel("Informations sur la voiture");

        //Immatriculation

        QLabel* LbImmaticulation = new QLabel("Immatriculation");

        LbImmaticulation->setFont(QFont("arial",17,(font().bold())));
        LeImmatriculation = new QLineEdit();
        LeImmatriculation->setMinimumWidth(200);
        LeImmatriculation->setMaximumHeight(35);
        LeImmatriculation->setMaximumWidth(250);

        //Marque
        QLabel* LbMarque = new QLabel("Marque");
        LbMarque->setFont(QFont("arial",17,(font().bold())));
        LeMarque = new QLineEdit();
        LeMarque->setMinimumHeight(20);
        LeMarque->setMinimumWidth(200);
        LeMarque->setMaximumHeight(35);
        LeMarque->setMaximumWidth(250);


        //HireDate
        LbHDate = new QLabel("Date de location");
        LbHDate->setFont(QFont("arial",17,(font().bold())));
        DeHDate = new QDateEdit(QDate::currentDate());
        DeHDate->setMinimumHeight(20);
        DeHDate->setMinimumWidth(200);
        DeHDate->setMaximumHeight(35);
        DeHDate->setMaximumWidth(250);


    // About customers

            QLabel* LbCusInfo = new QLabel("Informations sur le client");

            //Last Name
            QLabel* LbLName = new QLabel("Prénoms");
            LbLName->setFont(QFont("arial",17,(font().bold())));
            LeLName = new QLineEdit();
            LeLName->setMinimumWidth(200);
            LeLName->setMaximumHeight(35);
            LeLName->setMaximumWidth(250);

            //first Name
            QLabel* LbFName = new QLabel("Nom");
            LbFName->setFont(QFont("arial",17,(font().bold())));
            LeFName = new QLineEdit();
            LeFName->setMinimumHeight(20);
            LeFName->setMinimumWidth(200);
            LeFName->setMaximumHeight(35);
            LeFName->setMaximumWidth(250);


            //Tel
            QLabel* LbTel = new QLabel("Tel");
            LbTel->setFont(QFont("arial",17,(font().bold())));
            LeTel = new QLineEdit();
            LeTel->setMinimumHeight(20);
            LeTel->setMinimumWidth(200);
            LeTel->setMaximumHeight(35);
            LeTel->setMaximumWidth(250);


            //Type of pièce

            MyBox = new QComboBox();
            QLabel* LbMyBox = new QLabel ("Type de pièce");
            LbMyBox->setFont(QFont("arial",17,(font().bold())));
            MyBox->addItem("CIN");
            MyBox->addItem("LEPI");
            MyBox->addItem("RAVIP");
            MyBox->setMinimumHeight(20);
            MyBox->setMinimumWidth(200);
            MyBox->setMaximumHeight(35);
            MyBox->setMaximumWidth(250);



            //Piece number
            QLabel* LbNumP = new QLabel("Numéro de la pièce");
            LbNumP->setFont(QFont("arial",17,(font().bold())));
            LeNumP = new QLineEdit();
            LeNumP->setMinimumHeight(20);
            LeNumP->setMinimumWidth(200);
            LeNumP->setMaximumHeight(35);
            LeNumP->setMaximumWidth(250);

            //Exp Date
            QLabel* LbExpDate = new QLabel("Date de location");
            LbExpDate->setFont(QFont("arial",17,(font().bold())));
            DeExpDate = new QDateEdit(QDate::currentDate());
            DeExpDate->setMinimumHeight(20);
            DeExpDate->setMinimumWidth(200);
            DeExpDate->setMaximumHeight(35);
            DeExpDate->setMaximumWidth(250);


            // Address
            QLabel* LbAddr = new QLabel("Adresse");
            LbAddr->setFont(QFont("arial",17,(font().bold())));
            LeAddr = new QLineEdit();
            LeAddr->setMinimumHeight(20);
            LeAddr->setMinimumWidth(200);
            LeAddr->setMaximumHeight(35);
            LeAddr->setMaximumWidth(250);




    //Add elements to GLayout1 ( care grid )

    //GLayout1->addWidget(LbCarInfo,0,0,0,2);
    GLayout1->addWidget(LbImmaticulation,1,0);
    GLayout1->addWidget(LeImmatriculation,1,1);
    GLayout1->addWidget(LbMarque,2,0);
    GLayout1->addWidget(LeMarque,2,1);
    GLayout1->addWidget(LbHDate,3,0);
    GLayout1->addWidget(DeHDate,3,1);
    GLayout1->addWidget(Btn,4,1);

    //Add elements to GLayout2 ( customer)
    //GLayout2->addWidget(LbCusInfo,0,0,1,2);
    GLayout2->addWidget(LbFName,1,0);
    GLayout2->addWidget(LeFName,1,1);
    GLayout2->addWidget(LbLName,2,0);
    GLayout2->addWidget(LeLName,2,1);
    GLayout2->addWidget(LbMyBox,3,0);
    GLayout2->addWidget(MyBox,3,1);
    GLayout2->addWidget(LbNumP,4,0);
    GLayout2->addWidget(LeNumP,4,1);
    GLayout2->addWidget(LbExpDate,5,0);
    GLayout2->addWidget(DeExpDate,5,1);
    GLayout2->addWidget(LbTel,6,0);
    GLayout2->addWidget(LeTel,6,1);
    GLayout2->addWidget(LbAddr,7,0);
    GLayout2->addWidget(LeAddr,7,1);

    setCentralWidget(Mywidget);
    Mywidget->setMaximumWidth(screenWidth);
    Mywidget->setStyleSheet(QString::fromUtf8("background-color: rgba(200, 242, 235, 0.46);"));
    setEnabled(Mywidget);

    QObject::connect(Btn,SIGNAL(clicked()),this,SLOT(On_clicked_Btn()));


}

/* --------------------------------------------------------------------------------------------------*/

// Seach customer in table "CLIENT"

QString HirCare_3::SearchCustomer(QString LN, QString FN)
{
    QString id="";
    MyQuery = new QSqlQuery();
    MyQuery->prepare("SELECT idClient FROM CLIENT WHERE nom='"+LN+"' AND prenom='"+FN+"'");

    if(MyQuery->exec())
    {
        if(MyQuery->first())
        {
            id = MyQuery->value(0).toString();
        }
    }

    return id;
}
/*---------------------------------------------------------------------------------------------------*/

bool HirCare_3::SearchCareState(QString imma)
{
        QSqlQuery* q = new QSqlQuery();
        q->prepare("SELECT etat FROM VOITURE WHERE immatriculation='"+imma+"'");
        if(q->exec())
        {
            if(q->first())
            {

                QString stateCare =q->value(0).toString();

                if(stateCare=="Disponible"){return true;}

                else if(stateCare=="Non disponible") {
                    return false;
                }
            }

        }

        return false;
}


/*---------------------------------------------------------------------------------------------------*/

void HirCare_3::On_clicked_Btn()
{
    //About customer
    LName = LeLName->text();
    FName = LeFName->text();
    Tel = LeTel->text();
    type = MyBox->currentText();
    ExpDate = DeExpDate->text();
    Addr = LeAddr->text();
    Numpiece = LeNumP->text();

    //About care

    Marque = LeMarque->text();
    Immatriculation = LeImmatriculation->text();
    HireDate = DeHDate->date();
    QString StrHireDate = HireDate.toString("ddd d MMMM yyyy");
    QSqlQuery* q = new QSqlQuery();

    // if is the first time of customer
    if(!(LName.isEmpty() || FName.isEmpty() || Numpiece.isEmpty() || ExpDate.isEmpty() || Immatriculation.isEmpty()))
    {
        if(SearchCustomer(LName,FName).isEmpty())
        {

            MyQuery = new QSqlQuery();


            // Insertion of new user in table
            MyQuery->prepare("INSERT INTO CLIENT(nom,prenom,adresse,telephone,numPiece,typePiece,dateExpiration)" "VALUES(?,?,?,?,?,?,?)");
            MyQuery->addBindValue(LName);
            MyQuery->addBindValue(FName);
            MyQuery->addBindValue(Addr);
            MyQuery->addBindValue(Tel);
            MyQuery->addBindValue(type);
            MyQuery->addBindValue(Numpiece);
            MyQuery->addBindValue(ExpDate);

            if(MyQuery->exec())
            {
                QMessageBox::information(this,"Information","Le client "+LName+" "+FName+" vient d'être enrégistré.");
            }

        }

        QString id = SearchCustomer(LName,FName);


            MyQuery->prepare("UPDATE VOITURE SET etat='Non disponible' WHERE immatriculation='"+Immatriculation+"'");
            MyQuery->prepare("UPDATE VOITURE SET etat = ? WHERE immatriculation = ?");
            MyQuery->addBindValue("Non disponible");
            MyQuery->addBindValue(Immatriculation);

            q->prepare("INSERT INTO LOUER(dateLouer,idVoiture,idClient)" "VALUES(?,?,?)");
            q->addBindValue(StrHireDate);
            q->addBindValue(Immatriculation);
            q->addBindValue(id);

                if(SearchCareState(Immatriculation))
                {
                    if(MyQuery->exec())
                    {

                        q->prepare("INSERT INTO LOUER(dateLouer,idVoiture,idClient)" "VALUES(?,?,?)");
                        q->addBindValue(StrHireDate);
                        q->addBindValue(Immatriculation);
                        q->addBindValue(id);
                        if(q->exec())
                        {
                            QMessageBox::information(this,"Location","Location enrégistrée");
                        }

                    }
                    else{QMessageBox::warning(0,"error",MyQuery->lastError().text());}
                }
                else {QMessageBox::warning(this,"Location","La voiture "+Immatriculation+" n'est pas disponible !");}

        }

        else {
             QMessageBox::warning(this,"Location","Veuillez renseigner les champs");
            }



    //About customer
    LeLName->clear();
    LeFName->clear();
    LeTel->clear();
    LeAddr->clear();
    LeNumP->clear();

    //About care

    LeMarque->clear();
    LeImmatriculation->clear();


 }



