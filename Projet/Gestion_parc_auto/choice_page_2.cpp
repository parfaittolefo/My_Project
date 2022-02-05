#include "A_ll_H.h"
#include "choice_page_2.h"
#include "login_1.h"
#include <QDate>
#include <QDateEdit>
#include <QSqlQuery>
#include <QSqlError>
#include <QScrollArea>


/*  ____________________________________________________________________________________________*/
//Seach care in table

bool choice_page_2::SearchCare(QString id)
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


/*-------------------------------------------------------------------------------------------------------*/

//Care_state careHistory

void choice_page_2::On_clicked_searchBtn()
{
    // care state
    BoxNum->setHidden(1);
    CareState = new Care_state();
    QString id = LeId->text();
    MyQuery = new QSqlQuery();
    if(!id.isEmpty())
    {

         if(SearchCare(id))
          {

             // CareState part one

             MyQuery = new QSqlQuery();
             MyQuery->prepare("SELECT * FROM VOITURE WHERE immatriculation ='"+id+"'");

            if(MyQuery->exec())
            {
                if(MyQuery->first())
                {   CareState->LbMileage->setFont(QFont("C059",17,(font().bold())));
                    CareState->LbMileage->setText("N° matricule: "+MyQuery->value(1).toString());
                    CareState->Lbmodel->setText("Modèle: "+MyQuery->value(2).toString());
                    CareState->Lbmarque->setText("Marque: "+MyQuery->value(3).toString());
                    CareState->Lbmarque->setFont(QFont("C059",17,(font().bold())));
                    CareState->Lbstate->setText(MyQuery->value(5).toString());
                    CareState->Lbmodel->setFont(QFont("C059",17,(font().bold())));
                    if(MyQuery->value(5).toString()=="Non disponible")
                    {CareState->Lbstate->setStyleSheet(QString::fromUtf8("color:rgb(255, 12, 40);"));}

                }

                else{QMessageBox::warning(this,"Attention !","Cette voiture n'existe pas, id: "+id );}


                }
               // CareState->show();
                // hISTORY

                MyCareHistory = new careHistory ();
                MyQuery = new QSqlQuery();
                MyQuery->prepare("SELECT nom,prenom,dateLouer,dateRetour FROM (LOUER INNER JOIN CLIENT ON CLIENT.idClient=LOUER.idClient) INNER JOIN VOITURE ON VOITURE.immatriculation=LOUER.idVoiture WHERE VOITURE.immatriculation='"+id+"'");


                    /*---------------------------*/

                oneHistory = new QGridLayout();
                LbFname = new QLabel;
                LbFname->setMaximumHeight(100);
                LbLname = new QLabel;
                LbLname->setMaximumHeight(100);
                LbhireDate = new QLabel;
                LbhireDate->setMaximumHeight(100);
                LbbackDate = new QLabel;
                LbbackDate->setMaximumHeight(100);
                oneHistory= new QGridLayout();
                QLabel* Prepo = new QLabel("au");

                oneHistory->addWidget(LbLname,0,0,1,2);
                oneHistory->addWidget(LbFname,0,3,1,2);
                oneHistory->addWidget(LbhireDate,1,0,1,2);
                oneHistory->addWidget(Prepo,1,3,1,1);
                oneHistory->addWidget(LbbackDate,1,4,1,2);


                /*-----------------------------------*/


                int i=0;

                QGridLayout* MyGridLayout = new QGridLayout();
                QTextBrowser* MyTextBroswer = new QTextBrowser();
                MyGridLayout->addWidget(MyTextBroswer);
                MyTextBroswer->setAlignment(Qt::AlignCenter);
                MyTextBroswer->setStyleSheet(QString::fromUtf8("background-color: rgb(189,249,245);"));
                   MyTextBroswer->append("\n\n L'HISTORIQUES DE LA VOITURE S'AFFICHE ICI\n\n");
                if(MyQuery->exec())
                {
                    MyTextBroswer->setFont(QFont("C059",17,(font().bold())));
                    MyTextBroswer->setMaximumWidth(800);


                    if(MyQuery->first())
                    {

                      MyTextBroswer->append(MyQuery->value(0).toString()+"  "+MyQuery->value(1).toString()+"\n");
                      MyTextBroswer->append("Du  "+MyQuery->value(2).toString()+"   au    "+MyQuery->value(3).toString()+"\n\n");
                        ++i;
                    }



                    while (MyQuery->next()) {


                        MyTextBroswer->append(MyQuery->value(0).toString()+"  "+MyQuery->value(1).toString()+"\n");
                        MyTextBroswer->append("Du  "+MyQuery->value(2).toString()+"   au    "+MyQuery->value(3).toString()+"\n\n");
                          ++i;
                    }

                   QWidget* MyMainWidget = new QWidget();
                    QHBoxLayout* MyLayout = new QHBoxLayout(MyMainWidget);
                   MyLayout->addWidget(CareState);
                   MyLayout->addWidget(MyTextBroswer);
                   MyMainWidget->showMaximized();

            }
            else{QMessageBox::warning(this,"Attention !","NON EXECUTE"+MyQuery->lastError().text());}

        }

       else{QMessageBox::warning(this,"Attention !","Cette voiture n'existe pas, id: "+id );}

    }
      else{QMessageBox::warning(this,"Attention !","Veuillez entrer le numéro d'immatriculation ");}

}

/*________________________________________________________________________________________________*/
// Hire care button

void choice_page_2::On_clicked_HirBtn()
{


    QWidget* MyWidget = new QWidget();
    Hire = new HirCare_3();
    MyHireImg = new HireImg();
    QHBoxLayout* MyHBox = new QHBoxLayout(MyWidget);
    MyHBox->addWidget(MyHireImg);
    MyHBox->addWidget(Hire);
    //setCentralWidget(MyWidget);
     MyWidget->showMaximized();
}

/*_____________________________________________________________________________________________________*/

// Sup button for delete care

void choice_page_2::On_clicked_sup( )
{
    IdVoiture =LeId->text();

    if(SearchCare(IdVoiture))
    {


        if (QMessageBox::Yes == QMessageBox(QMessageBox::Information, "Suppression de voiture !", "Voulez-vous vraiment supprimer la voiture "+IdVoiture+" ?", QMessageBox::Yes|QMessageBox::No).exec())
        {
            MyQuery= new QSqlQuery();
            MyQuery->prepare("DELETE FROM VOITURE\
                             WHERE immatriculation ='"+IdVoiture+"'");
             if(MyQuery->exec())
            {
                QMessageBox::information(this,"Information","Voiture supprimée avec succès");
            }
        }



       /* Conf=QMessageBox::question(this,"Confirmation","Voulez-vous vraiment supprimer cette voiture ?");
        if(QMessageBox::Yes)
        {
            BoxSup->setHidden(1);
            //requete for suppression here with used IdVoiture



        }*/

     }

    else {
        QMessageBox::warning(this,"Attention !","Verifier l'immatricularion");
    }

        BoxSup->setHidden(1);
}

/* ___________________________________________________________________________________________________________*/
// Delete care
    void choice_page_2::On_clicked_delCare()
    {

      BoxSup = new QWidget();
      QGridLayout* BoxLayout = new QGridLayout(BoxSup);
      LeId = new QLineEdit();
      SupBtn= new QPushButton(" Supprimer ");
      QLabel* LbImmatriculation = new QLabel("N° matricule");
      LbImmatriculation->setFont(QFont("arial",14,(font().bold())));
      BoxLayout->addWidget(LbImmatriculation,0,0,1,2);
      BoxLayout->addWidget(LeId,0,2,1,2);
      BoxLayout->addWidget(SupBtn,1,1,1,2);
      BoxSup->setFixedHeight(200);
      BoxSup->setFixedWidth(350);
      SupBtn->setFixedHeight(40);
      SupBtn->setFixedWidth(200);
      SupBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(255,00,00,0);"));
      SupBtn->setFont(QFont("arial",14,(font().bold())));
      BoxSup->show();
      BoxSup->setWindowTitle("Supprimer une voiture");
     // Delete care button
     QObject::connect(SupBtn,SIGNAL(clicked()),this,SLOT(On_clicked_sup()));
    }

 /* ____________________________________________________________________________________________________________*/




/* ____________________________________________________________________________________________________________*/
 // Added care

void choice_page_2::Onclicked_addCare()
{

  //Image* I = new Image();
 choice_page_2* A = new choice_page_2();
  QWidget* MyWidget = new QWidget();
  Add = new addnewcar();
  QHBoxLayout* MyHBox = new QHBoxLayout(MyWidget);
  MyHBox->addWidget(A);
  //MyHBox->addWidget(I);
  MyHBox->addWidget(Add);
  //MyHBox->destroyed(0);
 // setCentralWidget(MyWidget);
  MyWidget->showMaximized();

}

/* _____________________________________________________________________________________________________*/

// Care state

void choice_page_2::On_clicked_CareState()
{
    BoxNum = new QWidget();
    QGridLayout* BoxLayout = new QGridLayout(BoxNum);
     LeId = new QLineEdit();
    SearchBtn= new QPushButton(" Rechercher ");
    QLabel* LbImmatriculation = new QLabel("N° matricule");
    SearchBtn->setFont(QFont("arial",14,(font().bold())));
    LbImmatriculation->setFont(QFont("arial",14,(font().bold())));
    BoxLayout->addWidget(LbImmatriculation,0,0,1,1);
    BoxLayout->addWidget(LeId,0,1,1,2);
    BoxLayout->addWidget(SearchBtn,1,1,1,2);
    BoxNum->setFixedHeight(200);
    BoxNum->setFixedWidth(400);
    BoxNum->show();
    LeId->setFixedWidth(200);
    SearchBtn->setFixedHeight(30);
    SearchBtn->setFixedWidth(200);
    SearchBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(25,230,100,90);"));
    QObject::connect(SearchBtn,SIGNAL(clicked()),this,SLOT(On_clicked_searchBtn()));

  }
/*------------------------------------------------------------------------------------------------------*/
void choice_page_2::On_clicked_SumBtn()
{
    BoxBack->hide();
    IdConf= LeIdConf->text();
    IdVoiture= LeId->text();
    MyQuery = new QSqlQuery();
    DateRetour=BackDate->date();
    MyQuery->prepare("SELECT etat FROM VOITURE WHERE immatriculation ='"+IdConf+"'");
    MyQuery->exec();
    MyQuery->first();
    QString etat = MyQuery->value(0).toString();

    if(SearchCare(IdConf) && !(IdVoiture.isEmpty() || IdConf.isEmpty()) && IdConf == IdVoiture)
    {

        if(etat=="Non disponible")
        {
            MyQuery = new QSqlQuery();
            QSqlQuery* q =new QSqlQuery();
            QString date = DateRetour.toString("ddd d MMMM yyyy");

            MyQuery->prepare("UPDATE VOITURE SET etat = 'Disponible' WHERE immatriculation ='"+IdConf+"';");

            q->prepare("UPDATE LOUER SET dateRetour =:dateR WHERE idVoiture =:idC AND id = (SELECT id FROM LOUER WHERE idVoiture =:idC ORDER BY id DESC LIMIT 0,1);");
            q->bindValue(":dateR",date);
            q->bindValue(":idC",IdConf);
            q->bindValue(":idC",IdConf);


            if(MyQuery->exec())
            {
                if(q->exec())
                {QMessageBox::information(this,"Information","La voiture est désormais disponible ");}
                else{QMessageBox::warning(this,"Error","Error: "+q->lastError().text()+" "+IdConf);}
            }

            else{QMessageBox::warning(this,"Erreur","Mise à jour échouée !"+MyQuery->lastError().text());}

        }
        else{QMessageBox::warning(this,"Attention !!!","Cette voiture n'était pas louée");}
    }

    else{QMessageBox::information(this,"Attention !!!","Cette voiture n'éxiste pas");}
}

/* -----------------------------------------------------------------------------------------------*/

// Manage a care back

void choice_page_2::On_clicked_backCare()
{
    BoxBack = new QWidget();
    QGridLayout* BoxLayout = new QGridLayout(BoxBack);
    BackDate =new QDateEdit(QDate::currentDate());

    QLabel* LbId = new QLabel("N° matricule");
    LbId->setFont(QFont("arial",15,(font().bold())));
    LeId = new QLineEdit();
    LeId->setFont(QFont("arial",15,(font().bold())));
    LbId->setFont(QFont("arial",15,(font().bold())));

    QLabel* LbDate = new QLabel("Date");
    LbDate->setFont(QFont("arial",15,(font().bold())));
    LbDate->setFixedHeight(100);
    LbDate->setMidLineWidth(70);

    QLabel* LbIconf = new QLabel("Confirmer n°");
    LbIconf->setFont(QFont("arial",15,(font().bold())));
    LeIdConf = new QLineEdit();
    LeIdConf->setFont(QFont("arial",15,(font().bold())));

    QPushButton* SumBtn= new QPushButton(" Enrégistrer ");
    SumBtn->setFont(QFont("arial",15,(font().bold())));

    BoxLayout->addWidget(LbId,0,0);
    BoxLayout->addWidget(LeId,0,1,1,3);
    BoxLayout->addWidget(LbIconf,1,0);
    BoxLayout->addWidget(LeIdConf,1,1,1,3);
    BoxLayout->addWidget(LbDate,2,0,1,2);
    BoxLayout->addWidget(BackDate,2,1,1,2);
    BoxLayout->addWidget(SumBtn,3,1,1,2);
    SumBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(7,245,102);"));
    SumBtn->setFont(QFont("arial",15,(font().bold())));

    BoxBack->setFixedHeight(200);
    BoxBack->setFixedWidth(400);
    BoxBack->setWindowTitle("Retour d'une voiture ");
    // Back care
    QObject::connect(SumBtn,SIGNAL(clicked()),this,SLOT(On_clicked_SumBtn()));
    BoxBack->show();

}


/*-------------------------------------------------------------------------------------------*/

//On_clicked_parc_State()


void choice_page_2::On_clicked_parc_State()

{
    CareState = new Care_state();
    MyQuery = new QSqlQuery();
    MyQuery->prepare("SELECT * FROM VOITURE");

    if(1)
    {

        if(1)
          {

             // CareState part one

             //MyQuery = new QSqlQuery();
             MyQuery->prepare("SELECT * FROM VOITURE");

            if(MyQuery->exec())
            {
               // QWidget* MyWidget = new QWidget();
                QWidget *MyWidget = new QWidget();
                QGridLayout* MyGrid = new QGridLayout(MyWidget);
                MyGrid->setSpacing(20);

      /*---------------------------------------------------------------------------------*/


//                QWidget *container = new QWidget;
//                scroll->setWidget(container);
//                QVBoxLayout *lay = new QVBoxLayout(container);

//                for(size_t i=0;i <tempList.size(); i++){
//                    ProductWidget *p = new ProductWidget(...);
//                    lay->addWidget(p);
//                }

                //QScrollArea *scroll = new QScrollArea(MyWidget);





     /*-------------------------------------------------------------------------------------------*/


                int col=1, lig=0;
                if(MyQuery->first())
                {
                    CareState->LbMileage->setText("N° matricule: "+MyQuery->value(1).toString());
                    CareState->LbMileage->setFont(QFont("Lato Black",17,(font().bold())));
                    CareState->Lbmodel->setText("Modèle: "+MyQuery->value(2).toString());
                    CareState->Lbmarque->setFont(QFont("Lato Black",17,(font().bold())));
                    CareState->Lbmodel->setFont(QFont("Lato Black",17,(font().bold())));
                    CareState->Lbmarque->setText("Marque: "+MyQuery->value(3).toString());
                    CareState->Lbstate->setText("N° matricule: "+MyQuery->value(1).toString());
                    CareState->Lbstate->setText(MyQuery->value(5).toString());
                    if(MyQuery->value(5).toString()=="Non disponible")
                    {CareState->Lbstate->setStyleSheet(QString::fromUtf8("color:rgb(255, 12, 40);"));}
                }
                MyGrid->addWidget(CareState,lig,col);

                while (MyQuery->next())
                {
                     col++;
                    CareState = new Care_state();

                    CareState->LbMileage->setText("N° matricule: "+MyQuery->value(1).toString());
                    CareState->LbMileage->setFont(QFont("C059",17,(font().bold())));
                    CareState->LbMileage->setFont(QFont("Lato Black",17,(font().bold())));
                    CareState->Lbmodel->setText("Modèle: "+MyQuery->value(2).toString());
                    CareState->Lbmodel->setFont(QFont("Lato Black",17,(font().bold())));
                    CareState->Lbmarque->setText("Marque: "+MyQuery->value(3).toString());
                    CareState->Lbmarque->setFont(QFont("Lato Black",17,(font().bold())));
                    CareState->Lbstate->setText(MyQuery->value(5).toString());
                    CareState->Lbstate->setFont(QFont("Lato Black",17,(font().bold())));
                    if(MyQuery->value(5).toString()=="Non disponible")
                    {CareState->Lbstate->setStyleSheet(QString::fromUtf8("color: rgb(255, 12, 40)"));}

                    MyGrid->addWidget(CareState,lig,col);

                    if(col==3){col=0;lig=lig+1;}

                }

                   // setCentralWidget(MyWidget);
                    MyWidget->showMaximized();

                }

            }
         }

    }


/*----------------------------------------------------------------------------------------------*/


// Class constructor


choice_page_2::choice_page_2()
{
    QPushButton *ManageBtn = new QPushButton(("Gérer une voiture"));
       QMenu *menu = new QMenu(this); CareImage = new Image();
       QAction* AddCare = new QAction(("Ajouter une voiture"), this);
       QAction* DelCare = new QAction(("Supprimer une voiture"), this);
       menu->addAction(AddCare);
       menu->addAction(DelCare);
       ManageBtn->setMenu(menu);
       ManageBtn->setFont((QFont("arial",17,(font().bold()))));
       ManageBtn->setStyleSheet(QString::fromUtf8("background-color: rgba(255, 191, 224, 0.8);"));
       ManageBtn->setMinimumHeight(70);
       ManageBtn->setMinimumWidth(150);

    QPushButton* HireBtn = new QPushButton("Louer une voiture à un client");
    HireBtn->setFont((QFont("arial",17,(font().bold()))));
    HireBtn->setStyleSheet(QString::fromUtf8("background-color: rgb(7,245,102);"));
    HireBtn->setMinimumHeight(70);
    HireBtn->setMinimumWidth(150);
    QPushButton* BackBtn = new QPushButton("Gérer le retour d'une voiture");
    BackBtn->setFont((QFont("arial",17,(font().bold()))));
    BackBtn->setMinimumHeight(70);
    BackBtn->setMinimumWidth(150);
    BackBtn->setStyleSheet(QString::fromUtf8("background-color: rgba(201, 234, 27, 0.58);"));
    QPushButton* CarStateBtn = new QPushButton("Avoir l'état d'une voiture");
    CarStateBtn->setFont((QFont("arial",17,(font().bold()))));
    CarStateBtn->setStyleSheet(QString::fromUtf8("background-color: rgba(90, 222, 201, 0.46);"));
    CarStateBtn->setMinimumHeight(70);
    CarStateBtn->setMinimumWidth(150);
    QPushButton* ParcState = new QPushButton("Avoir l'état du parc ");

    QObject::connect(ParcState,SIGNAL(clicked()),SLOT(On_clicked_parc_State()));

    ParcState->setFont((QFont("arial",17,(font().bold()))));
    ParcState->setStyleSheet(QString::fromUtf8("background-color: rgba(27, 171, 234, 0.58);"));
    ParcState->setMinimumHeight(70);
    ParcState->setMinimumWidth(150);
    //Join putting button in gridLayout  // This grid Layout contain the different choices
    QWidget* M_Widget = new QWidget();
    QGridLayout* MyGrid = new QGridLayout(M_Widget);
    MyGrid->addWidget(ManageBtn,1,0);
    MyGrid->addWidget(HireBtn,1,1);
    MyGrid->addWidget(BackBtn,2,0);
    MyGrid->addWidget(CarStateBtn,2,1);
    MyGrid->addWidget(ParcState,3,0,1,2);
  //  MyGrid->addWidget(CareImage,0,2,5,2);
    MyGrid->setVerticalSpacing(200);

    // Clicked on hireBtn
    QObject::connect(HireBtn,SIGNAL(clicked()),this,SLOT(On_clicked_HirBtn()));

    // Choose delet care
    QObject::connect(DelCare,SIGNAL(triggered()), this, SLOT(On_clicked_delCare()));

        // add new care
    QObject::connect(AddCare,SIGNAL(triggered()), this, SLOT(Onclicked_addCare()));

    //view a care state
    QObject::connect(CarStateBtn,SIGNAL(clicked()),this,SLOT(On_clicked_CareState()));

    // Manage come back of care
    QObject::connect(BackBtn,SIGNAL(clicked()),this,SLOT(On_clicked_backCare()));

    M_Widget->setStyleSheet(QString::fromUtf8("background-color: rgba(200, 242, 235, 0.46);"));

     setEnabled(M_Widget);
    setCentralWidget(M_Widget);

}
