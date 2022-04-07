#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    QPushButton* okbtn;
    QString input;
    QString Code_file_name,cmd;
    QPlainTextEdit* Standart_input;
    QWidget* Input_widget;
    void ErrorPrinter(int sts);

private slots:
    void on_FILE_BTN_clicked();

    void on_INPUT_FILE_BTN_clicked();

    void on_INPUT_BTN_clicked();

    void okbtn_clicked();

    void on_RUN_BTN_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
