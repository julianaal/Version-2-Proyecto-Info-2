#include "menu.h"
#include "ui_menu.h"
#include <qdebug.h>


Menu::Menu(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    msg= new QMessageBox();
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_exit_clicked()
{
    this->close();
}

void Menu::on_help_clicked()
{
    msg->setWindowTitle("****Bienvenido A Galaga****");
    msg->setText("\nDestruye naves espaciales.\n");
    msg->show();
}

void Menu::on_logout_clicked()
{
    logout=true;
}

void Menu::on_one_clicked()
{

    single=true;
}

void Menu::on_multi_clicked()
{
    multi=true;
}
