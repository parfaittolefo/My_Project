#ifndef CAREHISTORY_H
#define CAREHISTORY_H
#include "A_ll_H.h"
#include <QMainWindow>

class careHistory : public QMainWindow
{
    Q_OBJECT
public:
    explicit careHistory(QWidget *parent = nullptr);
    QLabel* LbFname;
    QLabel* LbLname;
    QLabel* LbhireDate;
    QLabel* LbbackDate;
    QString Fname,Lname,hireDate,backDate;
    QGridLayout* oneHistory;


signals:

};

#endif // CAREHISTORY_H
