#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QtWidgets>
#include "qfile.h"
#include <stdio.h>
#include <stdlib.h>
int status=0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->RUN_BTN->setEnabled(false);
    ui->CODE_BRS->setReadOnly(false);
}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::ErrorPrinter(int sts)

{

    if(!sts){
        ui->OUTPUT_BRS->clear();
         ui->OUTPUT_BRS->append("You have compilation error or code source error !!!");
    }

}

//Reading of programme data

void MainWindow::on_FILE_BTN_clicked()
{
    QString file =  QFileDialog::getOpenFileName(this,QDir::currentPath());

    if (!file.isEmpty())
    {
        ui->RUN_BTN->setEnabled(true);

         QFile Myfile(file);
        if(Myfile.open(QIODevice::ReadOnly | QIODevice::Text))

        {
            Code_file_name=Myfile.fileName();

            ui->CODE_BRS->clear();
             while (!Myfile.atEnd())
             {

                 ui->CODE_BRS->append(Myfile.readLine());

             }
        }

    }


    else
    {QMessageBox::warning(0,"Error","The file is empty !");}

 }

//Reading of input file

void MainWindow::on_INPUT_FILE_BTN_clicked()
{
    QString file =  QFileDialog::getOpenFileName(this,QDir::currentPath());



    if (!file.isEmpty())
    {
         QFile Myfile(file);
        if(Myfile.open(QIODevice::ReadOnly | QIODevice::Text))

        {
               ui->INPUT_BRS->clear();
             while (!Myfile.atEnd())
             {

                 ui->INPUT_BRS->append(Myfile.readLine());

             }

        }


    }

    else
    {QMessageBox::warning(0,"Error","The file is empty !");}

}

//Reading of standar input
void MainWindow::on_INPUT_BTN_clicked()
{
    ui->INPUT_BRS->clear();
    //QString input;
    Input_widget = new QWidget();
    okbtn = new QPushButton();
    okbtn->setText("Ok");
    Standart_input= new QPlainTextEdit();
    Standart_input->setFixedHeight(300);
    Standart_input->setFixedWidth(600);
    QGridLayout* Input_Grid = new QGridLayout(Input_widget);
    Input_Grid->addWidget(Standart_input,0,0,2,5);
    Input_Grid->addWidget(okbtn,2,2,1,1);
    Input_widget->setFixedHeight(350);
    Input_widget->setFixedWidth(650);
    Input_widget->show();
   connect(okbtn,SIGNAL(clicked()),this,SLOT(okbtn_clicked()));

}

void MainWindow::okbtn_clicked()
{
    input=Standart_input->toPlainText();
    Input_widget->hide();
    ui->INPUT_BRS->setText(input);
}



void MainWindow::on_RUN_BTN_clicked()
{
    ui->OUTPUT_BRS->clear();
    QString langage, code_source;
    langage= ui->LANGAGE_CMX->currentText();

    QMessageBox::information(0,"Langage choice","You are going to run your code in "+langage);

    //Recuperation of code_brs content

    if(langage=="C")
    {
        //Program compilation
            QProcess::execute("gcc "+Code_file_name+" -o compile_code");

        //chmod +x compile_code
            system("chmod +x compile_code");

            // start time
            QTime myTimer;
            myTimer.start();

            //Program execution
           system("./compile_code > result.txt");

           // time of running
          int time = myTimer.elapsed();

       //Delete binary file
           system("rm -r compile_code");

       QFile Myfile("result.txt");
       if(Myfile.open(QIODevice::ReadOnly | QIODevice::Text))

       {
            ui->INPUT_BRS->clear();
            while (!Myfile.atEnd())
            {
                ui->OUTPUT_BRS->clear();
                ui->OUTPUT_BRS->append(Myfile.readLine());
                status=1;

            }

            QString s = QString::number(time);
            ui->TIM_Lb->setAlignment(Qt::AlignCenter);
            ui->TIM_Lb->setText(s+" ms");

            //Delete result.txt
                system("rm -r result.txt");

       }

        ErrorPrinter(status);
        status=0;

    }

    if(langage=="C++")
    {
        //Program compilation
            QProcess::execute("g++ "+Code_file_name+" -o compile_code");

        //chmod +x compile_code
            system("chmod +x compile_code");

            // start time
            QTime myTimer;
            myTimer.start();


        //Program execution
           system("./compile_code > result.txt");

           // time of running
          int time = myTimer.elapsed();

       //Delete binary file
           system("rm -r compile_code");

       QFile Myfile("result.txt");
       if(Myfile.open(QIODevice::ReadOnly | QIODevice::Text))

       {
            ui->INPUT_BRS->clear();
            while (!Myfile.atEnd())
            {
                ui->OUTPUT_BRS->append(Myfile.readLine());
                status=1;

            }

            //Delete result.txt
                system("rm -r result.txt");
                QString s = QString::number(time);
                ui->TIM_Lb->setAlignment(Qt::AlignCenter);
                ui->TIM_Lb->setText(s+" ms");

       }

        ErrorPrinter(status);
        status=0;

    }

    if(langage=="python2")
    {
        QProcess p;
        QStringList params;
        params << Code_file_name ;

        // start time
        QTime myTimer;
        myTimer.start();

        p.start("/usr/bin/python2",params);

        // time of running
       int time = myTimer.elapsed();
        p.waitForFinished(-1);



        QString p_stdout = p.readAll();
        ui->OUTPUT_BRS->clear();

        ui->OUTPUT_BRS->append(p_stdout);

        QString s = QString::number(time);
        ui->TIM_Lb->setAlignment(Qt::AlignCenter);
        ui->TIM_Lb->setText(s+" ms");

    }
    if(langage=="python3")
    {

        QProcess p;
        QStringList params;
        params << Code_file_name ;

        // start time
        QTime myTimer;
        myTimer.start();

        p.start("/usr/bin/python3",params);
        // time of running
       int time = myTimer.elapsed();
        p.waitForFinished(-1);



        QString p_stdout = p.readAll();
        ui->OUTPUT_BRS->clear();
        ui->OUTPUT_BRS->append(p_stdout);

        QString s = QString::number(time);
        ui->TIM_Lb->setAlignment(Qt::AlignCenter);
        ui->TIM_Lb->setText(s+" ms");



    }
}

