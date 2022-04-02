#ifndef MULTIPLICATION_CLASS_H
#define MULTIPLICATION_CLASS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Multiplication_class; }
QT_END_NAMESPACE

class Multiplication_class : public QMainWindow
{
    Q_OBJECT

public:
    Multiplication_class(QWidget *parent = nullptr);
    ~Multiplication_class();

private slots:
    void on_calcul_clicked();

private:
    Ui::Multiplication_class *ui;
};
#endif // MULTIPLICATION_CLASS_H
