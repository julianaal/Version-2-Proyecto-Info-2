#include "principal.h"
#include "widget.h"

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
{
    menu = new Menu();
    registro = new Registro();

    time = new QTimer(this);
    timer = new QTimer(this);
    time2 = new QTimer(this);
    timer2 = new QTimer(this);
    time3 = new QTimer(this);
    timer3 = new QTimer(this);
    time4 = new QTimer(this);
    timer4 = new QTimer(this);

    connect(time,SIGNAL(timeout()),this,SLOT(Login()));
    connect(timer,SIGNAL(timeout()),this,SLOT(Menus()));
    connect(time2,SIGNAL(timeout()),this,SLOT(Single()));
    connect(timer2,SIGNAL(timeout()),this,SLOT(SingleBMenu()));
    connect(time3,SIGNAL(timeout()),this,SLOT(Multi()));
    connect(timer3,SIGNAL(timeout()),this,SLOT(MultiBMenu()));
    connect(time4,SIGNAL(timeout()),this,SLOT(Record()));
    connect(timer4,SIGNAL(timeout()),this,SLOT(RecordBMenu()));

    timer->start(10);
    time2->start(10);
    time3->start(10);
    time4->start(10);
}

Principal::~Principal()
{

}

void Principal::Login(){
    if (registro->logins==true){
        menu->show();
        time->stop();
        timer->start(10);
        menu->logout=false;
        registro->hide();
    }
}
void Principal::Menus(){
    if(menu->logout==true){
        menu->hide();
        registro->show();
        registro->logins=false;
        timer->stop();
        time->start(10);
    }
}
void Principal::Single(){
    if (menu->single==true){
        //GalagaS=new Widget(registro->user);
        //GalagaS->show();
        menu->hide();
        time2->stop();
        timer2->start(10);
    }
}
void Principal::SingleBMenu(void){
    /*
    if (GalagaS->Jugando==false){
        GalagaS->close();
        menu=new Menu();
        menu->show();
        timer2->stop();
        time2->start(10);
    }
    */
}
void Principal::Multi(){
    if (menu->multi==true){
        GalagaM=new MultiWidget();
        GalagaM->show();
        menu->hide();
        time3->stop();
        timer3->start(10);
    }

}
void Principal::MultiBMenu(void){
    if (GalagaM->Jugando==false){
        GalagaM->hide();
        menu=new Menu();
        menu->show();
        timer3->stop();
        time3->start(10);
    }

}
void Principal::Record(void){}
void Principal::RecordBMenu(void){}
