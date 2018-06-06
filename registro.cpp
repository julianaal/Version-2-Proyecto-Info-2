#include "registro.h"
#include "ui_registro.h"
#include <QFile>
#include <qDebug>
#include <QGraphicsView>

Registro::Registro(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Registro)
{
    ui->setupUi(this);
    logins=false;
    msg=new QMessageBox();
    this->setMaximumSize(265,170);
    this->setMinimumSize(265,170);
    this->resize(265,170);

   // QGraphicsView *view =new QGraphicsView(this);
    //view->setBackgroundBrush(QPixmap(":/Image/giphy.gif"));

}

Registro::~Registro()
{
    delete ui;
}

void Registro::on_registro_clicked()
{
    this->setMaximumSize(530,170);
    this->setMinimumSize(530,170);
    this->resize(530,170);
}

void Registro::on_password_returnPressed()
{
    on_login_clicked();
}

void Registro::on_login_clicked()
{
    QFile file("Users.txt");
        if(!file.open(QIODevice::ReadWrite|QIODevice::Text)){
            qDebug()<<"Error";
        }
        else{
            QTextStream in(&file);
            for (int i=0;i<200;i++){
                QString x(ui->username->text()+"--"+ui->password->text());
                if (logins==false&&(in.readLine()==x)){
                    qDebug()<<"Login";
                    logins=true;
                }
                user=new QString(ui->username->text());
            }
        }
        if (logins==false){
            msg->setWindowTitle("******ERROR******");
            msg->setText("\nError en Username y Password");
            msg->show();
        }
}

void Registro::on_registro2_clicked()
{
    QFile cuenta("Users.txt");
        if(ui->username2->text()=="" || ui->password2->text()==""){
            qDebug() << "Error";
        }
        else{
            if(!cuenta.open(QIODevice::ReadWrite|QIODevice::Append)){
                qDebug()<<"Error";
                return;
            }
            QTextStream out (&cuenta);
            out << ui->username2->text() +"--"+ ui->password2->text()<<"\n";
            cuenta.close();
        }
    this->setMaximumSize(265,170);
    this->setMinimumSize(265,170);
    this->resize(265,170);
}

void Registro::on_password2_returnPressed()
{
    on_registro2_clicked();
}
