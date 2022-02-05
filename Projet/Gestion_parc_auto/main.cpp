#include "A_ll_H.h"
#include "database.h"
#include "choice_page_2.h"


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
   //conexion database
    Connexion_to_DB();
    Login_1 A;
    A.showMaximized();


    return a.exec();
}
