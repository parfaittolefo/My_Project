#ifndef ADDNEWCARE_H
#define ADDNEWCARE_H
#include <QMainWindow>
#include "A_ll_H.h"

class addnewcar : public QMainWindow
{
    Q_OBJECT
public:
     explicit addnewcar(QWidget *parent = nullptr);
     QWidget* Mywidget;
     QString Marque ;
     QString Model;
     QString Immatriculation;
     QString Mileage;
     QSqlQuery* MyQuery;
     QLineEdit* LeMarque;
     QLineEdit* LeModel;
     QLineEdit* LeImmatriculation;
     QLineEdit* LeMileage;
     bool SearchCare(QString id);

public slots:
    void On_clicked_Btn();

};

#endif // ADDNEWCARE_H
