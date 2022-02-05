#include "A_ll_H.h"



Image::Image()
{

    QWidget* M_Widget = new QWidget();

    M_Widget->setStyleSheet("background: url(images.jpeg)");
    setCentralWidget(M_Widget);
    setEnabled(M_Widget);

}
