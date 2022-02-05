#include "A_ll_H.h"
#include "database.h"
#include "QFormLayout"
#include "choice_page_2.h"
//Requestte to the database

  void Login_1::Manage_User_Connexion()
{

      QString UserName = LeNom->text();
      LeNom->clear();
      QString Password = LePassword->text();
      LePassword->clear();
   QSqlQuery MyQuery;
   MyQuery.prepare("SELECT * FROM Gestionnaire;");
   if(MyQuery.exec())
  {
       //QMessageBox::information(0,"Information","Requette de selection execter ");


       bool Ans = MyQuery.last();
       if(Ans) // User is in table, we are going to connect user
      {

           if(MyQuery.value(0).toString()==UserName && MyQuery.value(1).toString()==Password)
            {
                //QMessageBox::information(0,"Information"," Soyez les bienvenus !");

                //this->hide();
                Full= new QWidget();
                choice_page_2* A = new choice_page_2();
               Image* B = new Image();
                QHBoxLayout* FixedLayout = new QHBoxLayout(Full);
                FixedLayout->addWidget(A);
               FixedLayout->addWidget(B);
                Full->showMaximized();
                setCentralWidget(Full);

            }


           else if(!(UserName.isEmpty() | Password.isEmpty()))
           {QMessageBox::warning(this,"Attention","Informations incorrectes");}

     }

       // No user in table, we are going to enregistre him
        else if(!(UserName.isEmpty() | Password.isEmpty()))
        {
               MyQuery.prepare("INSERT INTO Gestionnaire (UserName, Password)" "VALUES (?, ?)");
               MyQuery.addBindValue(UserName);
               MyQuery.addBindValue(Password);

                   if(MyQuery.exec())
                   {
                       QMessageBox::information(this,"Information","Le compte est enrégistré ");
                   }
          }


     // No input information

        if(UserName.isEmpty() | Password.isEmpty())
       {QMessageBox::warning(this,"Attention","Veuillez remplir tous les champs !!! ");}

   }

}


Login_1::Login_1(QWidget *parent)
    : QMainWindow(parent)

{

    //The main windows contain the follows lines
     QGridLayout* MainLayout = new QGridLayout(Mywidget);

    //welcome Text
    QLabel* Text = new QLabel("Connectez vous ici ");
    Text->setFont(QFont("arial",20,(font().bold())));
    Text->setFixedHeight(20);
    Text->setMargin(0);

    //Avatar
    QHBoxLayout* profil = new QHBoxLayout();
    QWidget *frame = new QWidget();

    frame->setMaximumHeight(200);
    frame->setStyleSheet("background-image: url(avatar.jpeg);background-repeat: no-repeat;");
    profil->addWidget(frame);





    //frame->setMaximumWidth(200);


    //The first ligne (username, line 0)
    QLabel* LbNom = new QLabel("Pseudo",this);
    LbNom->setFont((QFont("arial",17,(font().bold()))));
    LeNom->setMaximumWidth(200);
    LbNom->setMargin(10);


    LbNom->setMaximumWidth(140);


    //The second line (password, line 1)
    QLabel* LbPassword = new QLabel("Mot de passe",this);
    LePassword->setMaximumWidth(200);
    LbPassword->setMaximumWidth(140);
    LbPassword->setFont(QFont("arial",17,(font().bold())));
    //Login Button(line 2)
    QPushButton* PbLogin = new QPushButton();
    PbLogin->setText("Se connecter");

    //Mainlayout
    MainLayout->addLayout(profil,0,1,1,2);
    MainLayout->addWidget(Text,1,1,1,2);
    MainLayout->addWidget(LbNom,2,0,1,2);
    MainLayout->addWidget(LeNom,2,2,1,2);
    MainLayout->addWidget(LbPassword,3,0,1,2);
    MainLayout->addWidget(LePassword,3,2,1,2);
    MainLayout->addWidget(PbLogin,4,1,1,2);



    //PbLogin->setMaximumWidth();
    PbLogin->setStyleSheet(QString::fromUtf8("background-color: rgb(7,245,102);"));
    Mywidget->setStyleSheet(QString::fromUtf8("background-color: rgb(210,255,255);opacity: 0.3;"));
    PbLogin->setFont((QFont("arial",17,(font().bold()))));

    // Image Object

    MyImage = new Image();
    Mywidget->setMinimumWidth(700);
    Mywidget->setMinimumHeight(500);


    // Image Object
    MyImage = new Image();
    Image* MyImage2 = new Image();

    //Split screen
    QWidget* Full;
    Full = new QWidget();
    QHBoxLayout* FixedLayout = new QHBoxLayout(Full);
    FixedLayout->addWidget(MyImage);
    FixedLayout->addWidget(Mywidget);
    FixedLayout->addWidget(MyImage2);

    setCentralWidget(Full);
    setEnabled(Full);
    Full->setWindowTitle(" Parc automobile");



   //Connexion slots

   QObject::connect(PbLogin,SIGNAL(clicked()),this,SLOT(Manage_User_Connexion()));

}


