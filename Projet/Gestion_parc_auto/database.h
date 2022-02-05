#ifndef DATABASE_H
#define DATABASE_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include"login_1.h"

void inline Connexion_to_DB()
{
    QSqlDatabase Connexion = QSqlDatabase::addDatabase("QSQLITE");
    Connexion.setDatabaseName("Parc.db");

    if(Connexion.open())
    {
        //QMessageBox::information(0,"Information","Ouverture réussie !!!");

        QSqlQuery MyQuery;
        MyQuery.prepare("CREATE TABLE IF NOT EXISTS Gestionnaire(UserName TEXT NOT NULL, Password TEXT NOT NULL );");

        bool Ans=MyQuery.exec();
        if(Ans)
        {
           // QMessageBox::information(0,"Information","Connexion à la base de donnée réussie ");
        }

        QString createTableVoiture("CREATE TABLE IF NOT EXISTS VOITURE( \
                                       idVoiture INTEGER PRIMARY KEY AUTOINCREMENT, \
                                       immatriculation TEXT NOT NULL,\
                                       modele TEXT, \
                                       marque TEXT NOT NULL, \
                                        kilometrage INTEGER NOT NULL, \
                                       etat TEXT NOT NULL DEFAULT 'Disponible' \
                                   )");

        QString createTableClient("CREATE TABLE IF NOT EXISTS CLIENT( \
                                      idClient INTEGER  PRIMARY KEY AUTOINCREMENT, \
                                      nom TEXT NOT NULL, \
                                      prenom TEXT NOT NULL, \
                                      adresse TEXT NOT NULL, \
                                      telephone TEXT NOT NULL UNIQUE, \
                                      numPiece TEXT NOT NULL, \
                                      typePiece TEXT, \
                                      dateExpiration TEXT)");



             QString createAssociationLouer("CREATE TABLE IF NOT EXISTS \
                                            LOUER(id INTEGER  PRIMARY KEY AUTOINCREMENT, \
                                            dateLouer TEXT NOT NULL, \
                                            dateRetour TEXT DEFAULT '..\\..\\....', \
                                            idVoiture TEXT, \
                                            idClient TEXT)");

             QSqlQuery q;
             q.prepare(createTableVoiture);
             if(!q.exec())
              {QMessageBox::critical(0,"Création table Voiture", "Table non créée");}

             q.prepare(createTableClient);
             if(!q.exec())
               {QMessageBox::critical(0,"Création table client", "Table non créée");}
             q.prepare(createAssociationLouer);

            if(!q.exec())
            {
                QMessageBox::critical(0,"Création table Louer", "Table non créée");

            }


    }

}


#endif // DATABASE_H
