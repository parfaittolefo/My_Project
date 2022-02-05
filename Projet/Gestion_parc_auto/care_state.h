#ifndef CARE_STATE_H
#define CARE_STATE_H
#include <QtWidgets>
#include <QMainWindow>
#include <QSqlQuery>

class Care_state : public QMainWindow
{
    Q_OBJECT
public:
    explicit Care_state(QWidget *parent = nullptr);
    QLabel* Lbmarque;
    QLabel* Lbmodel;
    QLabel* LbImmatriculation;
    QLabel* Lbstate;
    QHBoxLayout * Lstate;
    QSqlQuery* MyQuery;
    QLabel* LbMileage;

};

#endif // CARE_STATE_H
