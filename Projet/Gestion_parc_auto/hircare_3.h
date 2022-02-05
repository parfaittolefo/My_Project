#ifndef HIRCARE_3_H
#define HIRCARE_3_H
#include <QtWidgets>
#include <QMainWindow>
#include <QSqlQuery>
#include <QDateEdit>
#include <QDate>

QT_BEGIN_NAMESPACE
class HirCare_3: public QMainWindow
{

    Q_OBJECT
public:
    HirCare_3();
    QWidget* Mywidget = new QWidget();
    QLineEdit* LeLName;
    QLineEdit* LeFName;
    QLineEdit* LeTel;
    QComboBox* MyBox;
    QDateEdit * DeExpDate;
    QLineEdit* LeAddr;
    QString LName,FName,Tel,ExpDate,Addr,type,Numpiece,TypePiece;
    QString Marque,Immatriculation;
    QLineEdit* LeImmatriculation;
    QLabel* LbHDate;
    QLineEdit* LeMarque;
    QLabel* LbMatricul2;
    QLabel* LbModele;
    QSqlQuery* MyQuery;
    QDateEdit* DeHDate;
    QLineEdit* LeNumP;
    QDate     HireDate,BackDate;
    QString SearchCustomer(QString FN, QString LN);
    bool SearchCare(QString str);
    bool SearchCareState(QString imma);

public slots:
    void On_clicked_Btn();

};

#endif // HIRCARE_3_H
