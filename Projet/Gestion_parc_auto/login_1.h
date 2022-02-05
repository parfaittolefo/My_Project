#ifndef LOGIN_1_H
#define LOGIN_1_H
#include<QHBoxLayout>
#include <QMainWindow>
#include <QLineEdit>
#include "image.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Login_1; }
QT_END_NAMESPACE

class Login_1 : public QMainWindow
{
    Q_OBJECT

public:
    Login_1(QWidget *parent = nullptr);
    QLineEdit* LeNom = new QLineEdit(this);
    QLineEdit* LePassword = new QLineEdit(this);
    QWidget* Mywidget = new QWidget(this);
    Image* MyImage;
    QWidget* Full;

//    ~Login_1();

public slots:
    void Manage_User_Connexion();

private:
    Ui::Login_1 *ui;
};

#endif // LOGIN_1_H
