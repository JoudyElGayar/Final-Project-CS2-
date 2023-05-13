#include "window.h"
#include "ui_window.h"

Window::Window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);
}

Window::~Window()
{
    delete ui;
}

void Window::on_pushButton_clicked()
{
    win=new StartingWindow;
    win->show();
//    this->hide();
}


void Window::on_pushButton_2_clicked()
{
    path=new Path;
    path->show();
//    this->hide();
}

