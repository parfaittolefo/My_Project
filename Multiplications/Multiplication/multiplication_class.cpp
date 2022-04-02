#include "multiplication_class.h"
#include "ui_multiplication_class.h"
#include <string.h>

Multiplication_class::Multiplication_class(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Multiplication_class)
{
    ui->setupUi(this);
}

Multiplication_class::~Multiplication_class()
{
    delete ui;
}


void Multiplication_class::on_calcul_clicked()
{
    ui->affichage->clear();
    QString Chaine = ui->lineEdit->text();
    int Nombre = Chaine.toInt();
    for(int i=0; i<=12;++i)
    {
        int res = Nombre*i;

       QString s = QString::number(res);
       QString x = QString::number(i);
       QString Sortie = x + " x "+ Chaine + " = "+s+"\n";
       ui->affichage->append(Sortie);

    }

}

