#include "carehistory.h"
#include "A_ll_H.h"
careHistory::careHistory(QWidget *parent) : QMainWindow(parent)
{

   // QWidget* HistoryWdget = new QWidget();
    oneHistory = new QGridLayout(this);
    LbFname = new QLabel;
    LbFname->setMaximumHeight(100);
    LbLname = new QLabel;
    LbLname->setMaximumHeight(100);
    LbhireDate = new QLabel;
    LbhireDate->setMaximumHeight(100);
    LbbackDate = new QLabel;
    LbbackDate->setMaximumHeight(100);
    oneHistory= new QGridLayout(this);
    QLabel* Prepo = new QLabel("à");
    oneHistory->addWidget(LbLname,0,0,1,2);
    oneHistory->addWidget(LbFname,0,3,1,2);
    oneHistory->addWidget(LbhireDate,1,0,1,2);
    oneHistory->addWidget(Prepo,1,3,1,1);
    oneHistory->addWidget(LbbackDate,1,4,1,2);
 //   setCentralWidget(this);
//   this->showMinimized();
   //HistoryWdget->setMinimumWidth(700);
   //HistoryWdget->setMinimumHeight(500);
    //setEnabled(HistoryWdget);



}
