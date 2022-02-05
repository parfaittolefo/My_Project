#ifndef CHOICE_PAGE_2_H
#define CHOICE_PAGE_2_H
#include <QMainWindow>
#include <QObject>
#include "image.h"
#include "hireimg.h"
#include "AddNewCare.h"
#include "hircare_3.h"
#include "care_state.h"
#include "carehistory.h"
#include "login_1.h"



class choice_page_2 : public QMainWindow
{

  Q_OBJECT
public:
    choice_page_2();
    QWidget* M_Widget;
    QWidget* BoxSup ;
    HireImg* MyHireImg;



public slots:
    //void On_clicked_ManageCare();
    void On_clicked_HirBtn();
    void On_clicked_CareState();
    void On_clicked_parc_State();
    void On_clicked_backCare();
    void On_clicked_SumBtn();
    void On_clicked_delCare();
    void On_clicked_sup();
    void Onclicked_addCare();
    void On_clicked_searchBtn();


public:
    QString IdVoiture;
    QDate DateRetour;
    QString IdConf;
    addnewcar *Add;
    HirCare_3* Hire;
    Care_state* CareState;
    QLineEdit* LeId;
    QSqlQuery* MyQuery;
    QLineEdit* LeIdConf;
    QPushButton* SupBtn;
    QPushButton* SearchBtn;
    QDateEdit* BackDate;
    QWidget* BoxBack;
    QWidget* BoxNum;
     bool SearchCare(QString);
     careHistory* MyCareHistory;
     QLabel* LbFname;
     QLabel* LbLname;
     QLabel* LbhireDate;
     QLabel* LbbackDate;
     QString Fname,Lname,hireDate,backDate;
     QGridLayout* oneHistory;
     QWidget* Full;
     QHBoxLayout* FixedLayout;
     Image* CareImage;
     QGridLayout* MyGrid;




    //Full1* MyFull;

};

#endif // CHOICE_PAGE_2_H
